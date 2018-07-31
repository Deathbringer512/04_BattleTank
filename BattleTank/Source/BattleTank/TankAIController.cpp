// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	// Move Towards Player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim Towards Player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	// Fire if Ready
	ControlledTank->Fire();	// TODO: Limit firing rate
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}



