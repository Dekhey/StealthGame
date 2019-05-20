// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageTrap.h"
#include "DoorTrap.generated.h"
class uStaticMeshComponent;
class UCurveFloat;
class ADamageTrapButton;
UCLASS()
class MYPROJECT3_API ADoorTrap : public ADamageTrap
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorTrap();

protected:
	// Called when the game starts or when spawned
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* Mesh;

	// Timeline variables
	UPROPERTY(EditDefaultsOnly, Category = "Timeline")
		UCurveFloat* Curve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		ADamageTrapButton* Button;


	UFUNCTION(BlueprintCallable)
		void ActivateButton();	
	
	virtual void OverlapManage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
