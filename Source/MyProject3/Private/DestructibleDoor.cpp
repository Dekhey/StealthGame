// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/DestructibleDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Components/TimelineComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
ADestructibleDoor::ADestructibleDoor()
{
	// Set mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = Mesh;

	// Set dissolve collision
	DissolveRadius = CreateDefaultSubobject<USphereComponent>(TEXT("Dissolve radius"));
	DissolveRadius->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	DissolveRadius->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	DissolveRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DissolveRadius->SetSphereRadius(100.f);
	DissolveRadius->SetupAttachment(Mesh);


}



