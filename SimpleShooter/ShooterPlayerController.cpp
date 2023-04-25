// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if (bIsWinner)
	{
		UUserWidget* WinScreenWidget = CreateWidget(this, WinScreenClass, TEXT("Lose Screen"));

		if (WinScreenWidget != nullptr)
		{
			WinScreenWidget->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LoseScreenWidget = CreateWidget(this, LoseScreenClass, TEXT("Lose Screen"));

		if (LoseScreenWidget != nullptr)
		{
			LoseScreenWidget->AddToViewport();
		}
	}

	if(HUDWidget != nullptr)
	{
		HUDWidget->RemoveFromViewport();
	}


	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// HUDWidget = CreateWidget(this, HUDClass, TEXT("HUD"));
	//
	// if (HUDWidget != nullptr)
	// {
	// 	HUDWidget->AddToViewport();
	// }
}

