// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing: %s"), *ControlledTank->GetName());
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not finding player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found player tank: %s"), *PlayerTank->GetName());
	}
}

ATank * ATankAIController::GetPlayerTank()
{
	
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


