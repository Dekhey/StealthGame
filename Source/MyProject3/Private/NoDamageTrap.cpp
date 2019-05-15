// Fill out your copyright notice in the Description page of Project Settings.

#include "NoDamageTrap.h"
#include "Components/BoxComponent.h"
// Sets default values
ANoDamageTrap::ANoDamageTrap()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box collision"));
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Collision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
}



