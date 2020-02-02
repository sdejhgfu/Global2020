// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashConveyerBelt.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "TrashActor.h"

// Sets default values
ATrashConveyerBelt::ATrashConveyerBelt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));

	if (RootComponent)
	SpawnPoint->SetupAttachment(RootComponent);
	//

}

// Called when the game starts or when spawned
void ATrashConveyerBelt::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_SpawnerTimer, this, &ATrashConveyerBelt::SpawnTrash, TimeBetweenSpawning,true,0);
	
}

// Called every frame
void ATrashConveyerBelt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrashConveyerBelt::SpawnTrash()
{
	//rando pick obj to spawn
	FActorSpawnParameters SpawnParams;
	
	FRotator Rotator = FRotator::ZeroRotator;

	FVector SpawnLocation = SpawnPoint->GetComponentLocation();

	int SpawnNum = FMath::RoundToInt(FMath::RandRange(0, SpawnableActors.Num()));

	ATrashActor* TrashToSpawn = GetWorld()->SpawnActor<ATrashActor>(SpawnableActors[SpawnNum], SpawnLocation,Rotator,SpawnParams);

}