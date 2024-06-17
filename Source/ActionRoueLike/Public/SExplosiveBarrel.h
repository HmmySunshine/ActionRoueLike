// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;

UCLASS()
class ACTIONROUELIKE_API ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere)
	URadialForceComponent* forceComp;

	virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintCallable)
	void OnActorHit(UPrimitiveComponent* hitComponent, AActor* otherActor, 
		UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
