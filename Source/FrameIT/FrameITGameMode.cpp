// Fill out your copyright notice in the Description page of Project Settings.

#include "FrameIT.h"
#include "FrameITGameMode.h"
#include "FrameITGameState.h"
#include "FP_FirstPerson/FP_FirstPersonHUD.h"
#include "FP_FirstPerson/FP_FirstPersonCharacter.h"

AFrameITGameMode::AFrameITGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	this->DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	this->HUDClass = AFP_FirstPersonHUD::StaticClass();

	// use our custom GameState class
    this->GameStateClass = AFrameITGameState::StaticClass();
}

void AFrameITGameMode::BeginPlay()
{
	Super::BeginPlay();
	this->ChangeMenuWidget(this->FactWidgetClass);
}

void AFrameITGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (this->CurrentWidget != nullptr)
	{
		this->CurrentWidget->RemoveFromViewport();
		this->CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		this->CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (this->CurrentWidget != nullptr)
		{
			this->CurrentWidget->AddToViewport();
		}
	}
}
