// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/GameState.h"
#include "FrameITGameState.generated.h"

class UFact;
class UScroll;


/**
 * 
 */
UCLASS()
class FRAMEIT_API AFrameITGameState : public AGameState
{
	GENERATED_BODY()

public:
	AFrameITGameState();
	TArray<FText> CreateFactTextList();
	FString GetNextFreeName();

	TMap<FString, UFact*>* GetFactMap();
	TArray<UScroll*>* GetScrollArray();
	UFact* GetFact(int Index);
	void SetRequestInProgress(bool value);
	bool GetRequestInProgress();

protected:
	UPROPERTY()
	TMap<FString, UFact*> FactMap;

	UPROPERTY()
	TArray<UScroll*> ScrollArray;

	UPROPERTY()
	bool RequestInProgress;

};
