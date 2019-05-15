// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NoDamageTrap.h"
#include "LogTrap.generated.h"

class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class MYPROJECT3_API ALogTrap : public ANoDamageTrap
{
	GENERATED_BODY()
	
public:
	ALogTrap();
protected:
	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly, Category = "Trap")
		int direction = 1;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* Mesh;
	UFUNCTION()
		virtual void OverlapManage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
