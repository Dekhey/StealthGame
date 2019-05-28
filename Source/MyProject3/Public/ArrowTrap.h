// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTrap.h"
#include "ArrowTrap.generated.h"

class UStaticMeshComponent;
//class AArrow;

UCLASS()
class MYPROJECT3_API AArrowTrap : public ADamageTrap
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrowTrap();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* Mesh;
	/*UPROPERTY(EditDefaultsOnly, Category = "Trap")
		AArrow* Arrow;*/

	FTimerHandle TimerHandle_TimeBetweenShots;


	void ActivateTrap();
public:	

};
