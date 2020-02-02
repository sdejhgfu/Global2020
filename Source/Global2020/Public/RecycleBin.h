// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RecycleBin.generated.h"

class USphereComponent;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EGarbageType : uint8
{
	Carboard,
	Plastic,
	Metal,
	Trash
};

UCLASS()
class GLOBAL2020_API ARecycleBin : public AActor
{
	GENERATED_BODY()
	//
public:	
	// Sets default values for this actor's properties
	ARecycleBin();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trash")
	EGarbageType RecycleGarbageType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Trash")
	USphereComponent* SphereComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
