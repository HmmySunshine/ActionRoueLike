// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"

#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	//ÉèÖÃÅö×²Ô¤Éè
	sphereComp->SetCollisionProfileName("Projectle");
	/*sphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	sphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);*/
	RootComponent = sphereComp;

	effectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	effectComp->SetupAttachment(sphereComp);
	moveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComp"));
	moveComp->InitialSpeed = 1000.0f;
	moveComp->bRotationFollowsVelocity = true;
	moveComp->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

