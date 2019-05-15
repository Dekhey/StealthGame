// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageTrapButton.h"
#include "DamageTrap.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
// Sets default values
ADamageTrapButton::ADamageTrapButton()
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
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ADamageTrapButton::ManageTrapActivation);
	RootComponent = BaseMesh;
	ButtonMesh->SetupAttachment(BaseMesh);
	Collision->SetupAttachment(ButtonMesh);
	bActive = false;
}
void ADamageTrapButton::ManageTrapActivation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (Trap)
	{
		if (bActive)
		{
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
