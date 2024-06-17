// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"
class USphereComponent;
class UParticleSystemComponent;
class UProjectileMovementComponent;

UCLASS()
class ACTIONROUELIKE_API ASMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASMagicProjectile();


protected:
	// Called when the game starts or when spawned
	//�������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USphereComponent* sphereComp;
	//����Ч��
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent* effectComp;
	//�ӵ��ƶ�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* moveComp;

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
