// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrashConveyerBelt.generated.h"

class USceneComponent;
class ATrashActor;

UCLASS()
class GLOBAL2020_API ATrashConveyerBelt : public AActor
{
	GENERATED_BODY()
	//
public:	
	// Sets default values for this actor's properties
	ATrashConveyerBelt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawner")
	USceneComponent* SpawnPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Spawner")
	float TimeBetweenSpawning = .2f;

	FTimerHandle TimerHandle_SpawnerTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spawner")
	TArray<TSubclassOf<ATrashActor>> SpawnableActors;

	void SpawnTrash();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
