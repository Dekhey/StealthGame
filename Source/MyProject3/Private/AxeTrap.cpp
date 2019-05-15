// Fill out your copyright notice in the Description page of Project Settings.

#include "AxeTrap.h"
#include "Components/BoxComponent.h"
#include "Components/TimelineComponent.h"
#include "Components/StaticMeshComponent.h"

AAxeTrap::AAxeTrap()
{

	// Set mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Set collision
	Collision->SetupAttachment(Mesh);

	damage = 1.f;
}