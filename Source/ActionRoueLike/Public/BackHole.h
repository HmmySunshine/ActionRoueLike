// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BackHole.generated.h"

class URadialForceComponent;
class USphereComponent;
class UParticleSystemComponent;

UCLASS()
class ACTIONROUELIKE_API ABackHole : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackHole();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URadialForceComponent* radialForeceComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* sphereComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* particleComp;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
