// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSProjectile.h"
#include "FireBall.generated.h"

class UParticleSystem;
class USoundBase;
/**
 * 
 */
UCLASS()
class MYPROJECT3_API AFireBall : public AFPSProjectile
{
	GENERATED_BODY()
public:
	AFireBall();
	void Explode();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		UParticleSystem* ExplosionParticles;
	UPROPERTY(EditDefaultsOnly, Category = "Explosion")
		USoundBase* ExplosionSound;

	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	void BeginPlay() override;

};
