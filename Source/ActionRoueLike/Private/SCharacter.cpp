// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include "Camera/CameraComponent.h"
#include "InteractComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));

	//设置相机跟随旋转
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	GetCharacterMovement()->bOrientRotationToMovement = true;
	interactComponent = CreateDefaultSubobject<UInteractComponent>(TEXT("InteractComponent"));
	
	
	 // 禁用控制器旋转
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
	//水平旋转
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//垂直旋转
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	//
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ASCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &ASCharacter::PrimaryInteract);
}

void ASCharacter::MoveForward(float value)
{
	// 获取控制器的旋转
	FRotator ControlRotation = GetControlRotation();
	// 仅使用 Yaw 旋转
	FRotator YawRotation(0.0f, ControlRotation.Yaw, 0.0f);

	// 获取前向矢量
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void ASCharacter::MoveRight(float value)
{
	
	FRotator rotation = GetControlRotation();
	rotation.Pitch = 0.0f;
	rotation.Roll = 0.0f;
	//获取角色朝向的向量
	FVector rightVector = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);
	AddMovementInput(rightVector, value);
}

void ASCharacter::PrimaryAttack()
{
	FVector handLocation =  GetMesh()->GetSocketLocation("Muzzle_01");
	//变换矩阵
	FTransform spawnTM = FTransform(GetActorRotation(), handLocation);
	FActorSpawnParameters spawnParams;
	//总是生成无视碰撞
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>
	(projectleClass, spawnTM, spawnParams);
}

void ASCharacter::PrimaryInteract()
{
	//交互组件不为空
	if (interactComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("E"));
		interactComponent->PrimaryInteract();
	}
}



