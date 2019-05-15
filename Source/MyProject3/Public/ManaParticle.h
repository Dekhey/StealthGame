// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ManaParticle.generated.h"
class UParticleSystemComponent;
class UFloatingPawnMovement;

UCLASS()
class MYPROJECT3_API AManaParticle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AManaParticle();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UParticleSystemComponent* Particle;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UFloatingPawnMovement* MovementComponent;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
