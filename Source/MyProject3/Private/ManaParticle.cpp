// Fill out your copyright notice in the Description page of Project Settings.

#include "ManaParticle.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIController.h"

// Sets default values
AManaParticle::AManaParticle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement component"));
}

// Called when the game starts or when spawned
void AManaParticle::BeginPlay()
{
	Super::BeginPlay();
	//SpawnDefaultController();
	/*AAIController* controller = Cast<AAIController>(GetController());
	if (controller)
	{
		FVector vector = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		vector.operator+=(FVector(0, 0, -1000));
		vector = FVector(100);
		
		if (controller->MoveToLocation(vector) == EPathFollowingRequestResult::RequestSuccessful)
		{
			if (GEngine) {//PRINT ON SCREEN
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, vector.ToString());
			}

		}
	}*/
	/*else
	{
		if (GEngine) {//PRINT ON SCREEN
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().ToString());
		}
		controller = AAIController();
		controller = Cast<AAIController>(algo);
		if (controller)
		{
			controller->MoveToLocation(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
			if (GEngine) {//PRINT ON SCREEN
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().ToString());
			}
		}
	}*/
}

// Called every frame
void AManaParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*AAIController* controller = Cast<AAIController>(GetController());
	if (controller)
	{
		FVector vector = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
		vector = FVector(-1000, 0, 100);
		if (controller->MoveToLocation(vector,5.0f) == EPathFollowingRequestResult::Failed)
		{
			if (GEngine) {//PRINT ON SCREEN
				GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, vector.ToString());
			}

		}
	}*/
}


