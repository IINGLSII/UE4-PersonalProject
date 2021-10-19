// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectPlayerController.h"

void AMyProjectPlayerController::BeginPlay()
{
	Super:: BeginPlay();

	playerPawn = Cast<AMyProjectCharacter>(GetPawn());
}

void AMyProjectPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Dash", IE_Pressed, this, &AMyProjectPlayerController::Dash);
	InputComponent->BindAction("LockOn", IE_Pressed, this, &AMyProjectPlayerController::LockOn);
	InputComponent->BindAction("Attack", IE_Pressed, this, &AMyProjectPlayerController::Attack);
}

void AMyProjectPlayerController::Dash()
{
	playerPawn->Dash();
}

void AMyProjectPlayerController::LockOn()
{
	playerPawn->LockOn();
}

void AMyProjectPlayerController::Attack()
{
	playerPawn->Attack();
}