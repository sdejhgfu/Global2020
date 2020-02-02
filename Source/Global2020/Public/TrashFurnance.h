// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrashFurnance.generated.h"
class USphereComponent;
class UParticleSystem;
class UStaticMeshComponent;
UCLASS()
class GLOBAL2020_API ATrashFurnance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrashFurnance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trash")
	USphereComponent* SphereComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trash")
	UParticleSystem* ParticleEffect;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trash")
		UStaticMeshComponent* MeshComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
