// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageTrap.h"
#include "Components/BoxComponent.h"

// Sets default values
ADamageTrap::ADamageTrap()
{
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collision"));
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	RootComponent = Collision;
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ADamageTrap::OverlapManage);

}



void ADamageTrap::OverlapManage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
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