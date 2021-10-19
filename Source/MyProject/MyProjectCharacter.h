// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyProjectCharacter.generated.h"

UCLASS(config=Game)
class AMyProjectCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Targeting", meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* TargetingDecal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Targeting", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* TargetingCollision;

public:
	AMyProjectCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/* */

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
	void Dash();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
	void LockOn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
	void Attack();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
	float BaseMovementSpeed = 300;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Default")
	bool canDash = true;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Attacking")
	bool canAttack = true;

	UFUNCTION(BlueprintCallable, Category = "Default")
	void ResetProperties(bool val);

protected:
	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Targeting")
	bool LockedOn = false;

private:
	float TargetingDecalSize = 50;


protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UDecalComponent* GetTargetingDecal() const { return TargetingDecal; }
};

