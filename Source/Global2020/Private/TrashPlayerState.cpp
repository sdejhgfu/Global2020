// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashPlayerState.h"

void ATrashPlayerState::AddScore(int AddedScore)
{
	Score += AddedScore;
}

int ATrashPlayerState::GetTotalScore() const
{
	return Score;
}