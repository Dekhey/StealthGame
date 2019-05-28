// Fill out your copyright notice in the Description page of Project Settings.

#include "FireBall.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

AFireBall::AFireBall() {
	CollisionComp->InitSphereRadius(25.0f);
}
void AFireBall::BeginPlay()
{
	Super::BeginPlay();
}
void AFireBall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != GetOwner())
	{
		// Only add impulse and destroy projectile if we hit a physics
		if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		}
		if ((OtherActor != NULL) && (OtherActor != this))
		{
			//make the noise. The instigator is the pawn which spawns this projectile (the noise will still be made in the position of this actor)
			Explode();
		}
	}
}
void AFireBall::Explode()
{
	MakeNoise(1.0f, Instigator);
	if (ExplosionParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticles, GetTransform());
	}
	if (ExplosionSound)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), ExplosionSound);
	}
	Destroy();
}