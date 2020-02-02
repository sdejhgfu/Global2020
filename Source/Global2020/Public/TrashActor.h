// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecycleBin.h"
#include "TrashActor.generated.h"

class UStaticMeshComponent;
UCLASS()
class GLOBAL2020_API ATrashActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrashActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	/*Doing Dmg is a positve value Healing is a negative value*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trash", meta = (ClampMin = 0.f))
		float DamageAmount;

	UPROPERTY(EditDefaultsOnly,Category = "Trash")
	EGarbageType GarbageType;

	UPROPERTY(EditDefaultsOnly, Category = "Trash")
	float ScoreValue = 5;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	EGarbageType GetGarbageType() const;

	float GetDamageValue() const;

	float GetScoreValue() const;

};
