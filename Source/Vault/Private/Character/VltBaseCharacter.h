// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaperFlipbook.h"
#include "VltBaseCharacter.generated.h"

UCLASS()
class AVltBaseCharacter : public APawn
{
	GENERATED_BODY()

	enum class EVltCharacterDirection
	{
		Up,
		Down,
		Left,
		Right
	};

	enum class EVltCharacterAxis
	{
		UpDown,
		LeftRight
	};

	EVltCharacterDirection CurrentDirection = EVltCharacterDirection::Down;

public:
	// Sets default values for this character's properties
	AVltBaseCharacter();

	/** Base capsule component */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComponent;

	/** Movement Component */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UFloatingPawnMovement* MovementComponent;

	/** Arrow */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UArrowComponent* ArrowComponent;

	/** Sprite */
	UPROPERTY(Category=Character, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* FlipbookComponent;

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(Category=Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(Category=Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Flipbook */
	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* IdleDownFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* IdleUpFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* IdleLeftFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* IdleRightFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* RunDownFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* RunUpFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* RunLeftFlipbook;

	UPROPERTY(Category=Animation, EditAnywhere)
	class UPaperFlipbook* RunRightFlipbook;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
