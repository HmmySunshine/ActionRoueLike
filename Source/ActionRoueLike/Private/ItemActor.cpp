// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActor.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	baseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = baseMesh;
	lidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	lidMesh->SetupAttachment(baseMesh);

	pitchAngle = 110.0f;
	
}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AItemActor::Interact_Implementation(APawn* InstigatorPawn)
{
	lidMesh->SetRelativeRotation(FRotator(pitchAngle, 0, 0));
}

