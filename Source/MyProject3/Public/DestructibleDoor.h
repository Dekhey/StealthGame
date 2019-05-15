// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleDoor.generated.h"
class USphereComponent;
class UStaticMeshComponent;
class UMaterialInstanceDynamic;
class UTimelineComponent;
class UCurveFloat;

UCLASS()
class MYPROJECT3_API ADestructibleDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleDoor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite , Category = "Components")
	UStaticMeshComponent* Mesh;

	//Dissolve properties
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* DissolveRadius;



public:	

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UCurveFloat* FloatCurve;
};
