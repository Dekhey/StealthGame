// Fill out your copyright notice in the Description page of Project Settings.

#include "NoDamageTrapButton.h"
#include "NoDamageTrap.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "FireBall.h"
// Sets default values
ANoDamageTrapButton::ANoDamageTrapButton()
{
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base mesh"));
	BaseMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button mesh"));
	ButtonMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
	Collision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ANoDamageTrapButton::ManageTrapActivation);
	RootComponent = BaseMesh;
	ButtonMesh->SetupAttachment(BaseMesh);
	Collision->SetupAttachment(ButtonMesh);
	bActive = false;
}
void ANoDamageTrapButton::ManageTrapActivation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (Trap)
	{
		if (bActive)
		{
			AFireBall* fireBall = Cast<AFireBall>(OtherActor);
			if (fireBall)
			{
				fireBall->Explode();
			}
			Trap->ActivateTrap();
			ButtonMesh->SetWorldLocation(BaseMesh->GetComponentLocation());
			bActive = false;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The button has not a trap reference"));
	}
}
void ANoDamageTrapButton::ActivateButton()
{
	if (!bActive)
	{
		FVector newLocation = BaseMesh->GetComponentLocation();
		newLocation.Z += 9;
		ButtonMesh->SetWorldLocation(newLocation);
		bActive = false;
	}
}
