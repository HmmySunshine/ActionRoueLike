// Fill out your copyright notice in the Description page of Project Settings.


#include "SMagicProjectile.h"

#include "Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "AttributeComponent.h"



// Sets default values
ASMagicProjectile::ASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	//设置碰撞预设
	sphereComp->SetCollisionProfileName("Projectle");
	/*sphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	sphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);*/
	
	RootComponent = sphereComp;
	

	effectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EffectComp"));
	effectComp->SetupAttachment(sphereComp);
	moveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComp"));
	moveComp->InitialSpeed = 1000.0f;
	moveComp->bRotationFollowsVelocity = false;
	moveComp->bInitialVelocityInLocalSpace = true;
	


} 
void ASMagicProjectile::PostInitializeComponents()
{
	//在初始化组件完再使用动态绑定
	Super::PostInitializeComponents();
	sphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASMagicProjectile::OnActorOverlap);
}
void ASMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	UE_LOG(LogTemp, Warning, TEXT("Overlap"));
	if (OtherActor)
	{
		UAttributeComponent* attributeComp = Cast<UAttributeComponent>(OtherActor->GetComponentByClass(UAttributeComponent::StaticClass()));
		if (attributeComp)
		{
			attributeComp->ApplyHealthChange(-20.0f);

			Destroy();
		}
	}


}
// Called when the game starts or when spawned
void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

//


// Called every frame
void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

