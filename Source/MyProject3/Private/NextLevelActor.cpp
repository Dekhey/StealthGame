// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/NextLevelActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"


// Sets default values
ANextLevelActor::ANextLevelActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	RootComponent = Mesh;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetBoxExtent(FVector(10.f));
	Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ANextLevelActor::NextLevel);
	Collision->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void ANextLevelActor::BeginPlay()
{
	Super::BeginPlay();
	
}
void ANextLevelActor::NextLevel(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* character = Cast<ACharacter>(OtherActor);
	if (character)
	{
		UWorld* TheWorld = GetWorld();
		UGameplayStatics::OpenLevel(TheWorld, NextLevelString);
	}
}



