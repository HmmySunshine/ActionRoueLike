// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"
#include "GameplayInterface.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractComponent::PrimaryInteract()
{ 
	FCollisionObjectQueryParams objectQueryParam;
	objectQueryParam.AddObjectTypesToQuery(ECC_WorldDynamic);
	//GetOwner 方法通常用于获取一个组件所属的 Actor。
	AActor* owner = GetOwner();
	if (!owner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner is null"));
		return;
	}
	FVector eyeLocation;
	FRotator eyeRotation;
	owner->GetActorEyesViewPoint(eyeLocation, eyeRotation);
	FVector end = eyeLocation + (eyeRotation.Vector() * 1200);
	// 调试绘制射线
	//DrawDebugLine(GetWorld(), eyeLocation, end, FColor::Red, false, 2.0f, 0, 2.0f);
	//UE_LOG(LogTemp, Log, TEXT("EyeLocation: %s, End: %s"), *eyeLocation.ToString(), *end.ToString());
	
	//FHitResult hitResult;
	TArray<FHitResult> hitResults;
	float raidus = 30.0f;
	FCollisionShape collisionShape;
	collisionShape.SetSphere(raidus);
	//射线检测
	//bool bHit = GetWorld()->LineTraceSingleByObjectType(hitResult, eyeLocation, end, objectQueryParam);
	bool bHit = GetWorld()->SweepMultiByObjectType(hitResults, eyeLocation, end, FQuat::Identity, objectQueryParam, collisionShape);

	FColor lineColor = bHit ? FColor::Green : FColor::Red;
	if (bHit)
	{
		for (const FHitResult& hit : hitResults)
		{
			AActor* hitActor = hit.GetActor();
			if (hitActor)
			{
				UE_LOG(LogTemp, Log, TEXT("Hit Actor: %s"), *hitActor->GetName());
				if (hitActor->Implements<UGameplayInterface>())
				{
					APawn* myPawn = Cast<APawn>(owner);
					if (myPawn)
					{
						UE_LOG(LogTemp, Log, TEXT("MyPawn is valid"));
						// 调用接口

						IGameplayInterface::Execute_Interact(hitActor, myPawn);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("MyPawn is null"));
					}
				}
			}
			DrawDebugSphere(GetWorld(), hit.ImpactPoint, raidus, 32, lineColor, false, 2.0f);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No actor hit"));
	}
	DrawDebugLine(GetWorld(), eyeLocation, end, lineColor, false, 2.0f, 0, 2.0f);
}


// Called when the game starts
void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

