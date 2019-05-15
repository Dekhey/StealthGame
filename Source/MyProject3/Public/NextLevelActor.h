// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextLevelActor.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class MYPROJECT3_API ANextLevelActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANextLevelActor();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void NextLevel(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
		UBoxComponent* Collision;

	UPROPERTY(EditAnywhere, Category = "NextLevel")
		FName NextLevelString;

public:	

};
