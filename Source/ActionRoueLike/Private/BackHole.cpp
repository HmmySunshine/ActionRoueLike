// Fill out your copyright notice in the Description page of Project Settings.


#include "BackHole.h"
#include "Components/SphereComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABackHole::ABackHole()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = sphereComp;
	radialForeceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForceComp"));
	radialForeceComp->SetupAttachment(sphereComp);
	radialForeceComp->SetAutoActivate(false);
	radialForeceComp->bImpulseVelChange = false;
	
	particleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	particleComp->SetupAttachment(sphereComp);
}

// Called when the game starts or when spawned
void ABackHole::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

