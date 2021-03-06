// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DamageTrapButton.generated.h"
class ADamageTrap;
class UBoxComponent;

UCLASS()
class MYPROJECT3_API ADamageTrapButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageTrapButton();

protected:
	UPROPERTY(EditAnywhere, Category = "Trap")
		bool bActive; //true to activate and false to deactivate
	UPROPERTY(EditAnywhere, Category = "Trap")
		ADamageTrap* Trap;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* ButtonMesh;
	UPROPERTY(VisibleAnywhere, Category = "Components")
		UBoxComponent* Collision;
	

	UFUNCTION()
		virtual void ManageTrapActivation(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	void ActivateButton();
};
