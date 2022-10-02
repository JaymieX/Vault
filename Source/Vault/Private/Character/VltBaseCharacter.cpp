// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VltBaseCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"

// Sets default values
AVltBaseCharacter::AVltBaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create CapsuleComponent
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	CapsuleComponent->SetSimulatePhysics(true);
	CapsuleComponent->SetCollisionProfileName(TEXT("Pawn"));
	CapsuleComponent->BodyInstance.bLockRotation = true;
	RootComponent = CapsuleComponent;

	// Create MovementComponent
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	MovementComponent->UpdatedComponent = RootComponent;
	MovementComponent->MaxSpeed = 600.f;

	// Create ArrowComponent
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
	ArrowComponent->SetupAttachment(RootComponent);

	// Create SpriteComponent
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>("FlipbookComponent");
	FlipbookComponent->SetupAttachment(RootComponent);
	FlipbookComponent->SetRelativeRotation({0.f, 90.f, 0.f});
	FlipbookComponent->CastShadow = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetRelativeRotation({-25.f, 0.f, 0.f});
	CameraBoom->TargetArmLength = 800.0f; // The camera follows at this distance behind the character
	CameraBoom->bDoCollisionTest = false;

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	// Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->PostProcessSettings.MotionBlurAmount = 0.f;
}

// Called when the game starts or when spawned
void AVltBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVltBaseCharacter::MoveForward(float Value)
{
	static bool bIsPreviousFrameMoving = false;
	
	if (Value != 0.f)
	{
		bIsPreviousFrameMoving = true;
		AddMovementInput(CapsuleComponent->GetForwardVector(), Value);

		if (Value > 0.f)
		{
			CurrentDirection = EVltCharacterDirection::Up;
			FlipbookComponent->SetFlipbook(RunUpFlipbook);
		}
		else
		{
			CurrentDirection = EVltCharacterDirection::Down;
			FlipbookComponent->SetFlipbook(RunDownFlipbook);
		}
	}
	else
	{
		if (bIsPreviousFrameMoving)
		{
			bIsPreviousFrameMoving = false;

			if (CurrentDirection == EVltCharacterDirection::Up)
				FlipbookComponent->SetFlipbook(IdleUpFlipbook);
			else
				FlipbookComponent->SetFlipbook(IdleDownFlipbook);
		}
	}
}

void AVltBaseCharacter::MoveRight(float Value)
{
	static bool bIsPreviousFrameMoving = false;
	
	if (Value != 0.f)
	{
		bIsPreviousFrameMoving = true;
		AddMovementInput(CapsuleComponent->GetRightVector(), Value);
		
		if (Value > 0.f)
		{
			CurrentDirection = EVltCharacterDirection::Right;
			FlipbookComponent->SetFlipbook(RunRightFlipbook);
		}
		else
		{
			CurrentDirection = EVltCharacterDirection::Left;
			FlipbookComponent->SetFlipbook(RunLeftFlipbook);
		}
	}
	else
	{
		if (bIsPreviousFrameMoving)
		{
			bIsPreviousFrameMoving = false;
			
			if (CurrentDirection == EVltCharacterDirection::Right)
				FlipbookComponent->SetFlipbook(IdleRightFlipbook);
			else
				FlipbookComponent->SetFlipbook(IdleLeftFlipbook);
		}
	}
}

// Called every frame
void AVltBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVltBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AVltBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AVltBaseCharacter::MoveRight);
}

