// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ManaSpring.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class MYPROJECT3_API AManaSpring : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManaSpring();

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnyWhere, Category = "Components")
	UBoxComponent* Collision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

};
