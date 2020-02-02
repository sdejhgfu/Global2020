// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecycleBin.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGarbageType : uint8
{
	VE_Carboard 	UMETA(DisplayName = "Cardboard"),
	VE_Plastic 	UMETA(DisplayName = "Plastic"),
	VE_Metal	UMETA(DisplayName = "Metal"),
	VE_Trash	UMETA(DisplayName = "Trash")
};

UCLASS()
class GLOBAL2020_API ARecycleBin : public AActor
{
	GENERATED_BODY()
	//
public:	
	// Sets default values for this actor's properties
	ARecycleBin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trash")
	EGarbageType RecycleGarbageType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
