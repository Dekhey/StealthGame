// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTrap.h"
#include "AxeTrap.generated.h"

class uStaticMeshComponent;
class UCurveFloat;
class UTimelineComponent;
/**
 * 
 */
UCLASS()
class MYPROJECT3_API AAxeTrap : public ADamageTrap
{
	GENERATED_BODY()
	
public:
	AAxeTrap();

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* Mesh;
	
	// Timeline variables
	UPROPERTY(EditDefaultsOnly, Category = "Timeline")
		UCurveFloat* Curve;

};
