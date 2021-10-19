// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyProjectCharacter.h"
#include "MyProjectPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyProjectPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void Dash();
	void LockOn();
	void Attack();
	AMyProjectCharacter* playerPawn;

	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;
};

