// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"
class UCameraComponent;
class USpringArmComponent;
class UInteractComponent;
class UAttributeComponent;

UCLASS()
class ACTIONROUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComponent;
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	UInteractComponent* interactComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "component")
	UAttributeComponent* attributeComp;
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> projectleClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> holeClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* attackAnimMontage;

	FTimerHandle attackTimerHandle;

	
public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float value);
	void MoveRight(float value);
	void PrimaryAttack();

	void PrimaryInteract();
	void AttackTimerElapsed();
	void AttackHole();
};
