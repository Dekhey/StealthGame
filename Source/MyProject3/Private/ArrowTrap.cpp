// Fill out your copyright notice in the Description page of Project Settings.

#include "ArrowTrap.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AArrowTrap::AArrowTrap()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}
void AArrowTrap::ActivateTrap()
{
	//GetWorld()->SpawnActor<AActor>(GetActorLocation(),GetActorRotation());
}

