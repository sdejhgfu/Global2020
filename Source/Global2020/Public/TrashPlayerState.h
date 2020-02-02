// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TrashPlayerState.generated.h"
class APlayerCharacter;
/**
 * 
 */
UCLASS()
class GLOBAL2020_API ATrashPlayerState : public APlayerState
{
	GENERATED_BODY()

	APlayerCharacter* PlayerCharacter;

public:
		UFUNCTION(BlueprintCallable, Category = "Score")
		void AddScore(int AddedScore);
	
		UFUNCTION(BlueprintCallable, Category = "Score")
		int GetTotalScore() const;

		UFUNCTION(BlueprintCallable, Category = "Score")
		APlayerCharacter* GetPlayerCharacter() const;

		UFUNCTION(BlueprintCallable, Category = "Score")
		void SetPlayerCharacter(APlayerCharacter* ThePlayerCharacter);
};
