// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashPlayerState.h"
#include "PlayerCharacter.h"

void ATrashPlayerState::AddScore(int AddedScore)
{
	Score += AddedScore;
}

int ATrashPlayerState::GetTotalScore() const
{
	return Score;
}

APlayerCharacter* ATrashPlayerState::GetPlayerCharacter() const
{
	return PlayerCharacter;
}

void ATrashPlayerState::SetPlayerCharacter(APlayerCharacter * ThePlayerCharacter)
{
	PlayerCharacter = ThePlayerCharacter;
}
