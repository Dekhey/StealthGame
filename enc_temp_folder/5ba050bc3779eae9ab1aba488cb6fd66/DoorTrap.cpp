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
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
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

