// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	//设置模拟物理
	meshComp->SetSimulatePhysics(true);
	RootComponent = meshComp;
	forceComp = CreateDefaultSubobject<URadialForceComponent>(TEXT("ForceComp"));
	forceComp->SetupAttachment(meshComp);
	//径向力组件自动激活关闭
	forceComp->SetAutoActivate(false);

	forceComp->Radius = 750.f;
	forceComp->ImpulseStrength = 2500.0f;
	forceComp->bImpulseVelChange = true;

	forceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);


}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASExplosiveBarrel::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//蓝图动态绑定
	meshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}

void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* hitComponent, AActor* otherActor,
	UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
	forceComp->FireImpulse();
}
