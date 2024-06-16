// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayInterface.h"
#include "ItemActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class ACTIONROUELIKE_API AItemActor : public AActor, public IGameplayInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();
	UPROPERTY(EditAnywhere)
	float pitchAngle;

	void Interact_Implementation(APawn* InstigatorPawn);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* baseMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* lidMesh;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
