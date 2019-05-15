// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageTrap.generated.h"
class UBoxComponent;

UCLASS()
class MYPROJECT3_API ADamageTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageTrap();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void ActivateTrap();

protected:


	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* Collision;
	UPROPERTY(EditDefaultsOnly, Category = "Trap")
		float damage = 1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Trap")
		bool bActive;
	UFUNCTION()
	virtual void OverlapManage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	

};
