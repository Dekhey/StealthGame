// Fill out your copyright notice in the Description page of Project Settings.

#include "LogTrap.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ALogTrap::ALogTrap()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	Collision->SetupAttachment(Mesh);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ALogTrap::OverlapManage);
}

void ALogTrap::OverlapManage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* pawn = Cast<APawn>(OtherActor);
	if (pawn)
	{
		if (Mesh)
		{

			pawn->LaunchPawn(Mesh->GetForwardVector()*Strength*direction, true, true);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("This component has overlap with an actor that isn't a pawn, check the collision. "));
	}
}