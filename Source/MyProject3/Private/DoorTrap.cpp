// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorTrap.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DamageTrapButton.h"

// Sets default values
ADoorTrap::ADoorTrap()
{
	// Set mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Set collision
	Collision->SetupAttachment(Mesh);

	damage = 1.f;

}
void ADoorTrap::ActivateButton()
{
	if (Button)
	{
		Button->ActivateButton();
	}
}
void ADoorTrap::OverlapManage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bActive)
	{
		APawn* pawn = Cast<APawn>(OtherActor);
		if (pawn)
		{
			if (pawn->bCanBeDamaged)
			{
				pawn->ReceiveAnyDamage(damage, NULL, NULL, this);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("This component has overlap with a pawn that can't be damaged, check the pawns. "));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("This component has overlap with an actor that isn't a pawn, check the collision. "));
		}
	}
}

