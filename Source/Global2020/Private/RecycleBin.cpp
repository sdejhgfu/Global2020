// Fill out your copyright notice in the Description page of Project Settings.


#include "RecycleBin.h"
#include "Components/SphereComponent.h"
#include "TrashActor.h"
#include "PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "TrashPlayerState.h"

// Sets default values
ARecycleBin::ARecycleBin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComp->SetSphereRadius(32);
	SphereComp->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ARecycleBin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARecycleBin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//check overlapping actors
void ARecycleBin::NotifyActorBeginOverlap(AActor* OtherActor)
{
	

	Super::NotifyActorBeginOverlap(OtherActor);

	
	ATrashActor* TrashObject = Cast<ATrashActor>(OtherActor);

	APlayerCharacter* ThePlayer = nullptr;


	//get the player
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		

		ThePlayer = Cast<APlayerCharacter>(It->Get()->GetCharacter());
		if (ThePlayer)
		{
			continue;
		}
		else
		{
		}
	}

	//check if its a trash object
	if (TrashObject)
	{
		//check if the recycle bin is the correct bin the garbage should be going in
		if (RecycleGarbageType == TrashObject->GetGarbageType())
		{
			//take negative dmg val to heal the player
			if (ThePlayer)
			ThePlayer->HurtThePlayer(-TrashObject->GetDamageValue());
			
			ATrashPlayerState* TPS = Cast<ATrashPlayerState>(ThePlayer->GetPlayerState());
			//add score for the player upon getting one correct
			if (TPS)
			{
				TPS->AddScore(TrashObject->GetScoreValue());
				UE_LOG(LogTemp, Warning, TEXT("Score Value now: %i"), TPS->GetTotalScore());
			}


			UE_LOG(LogTemp, Warning, TEXT("Healed Player"));
		}
		else
		{
			//add normal damage to player to hurt them.
			if (ThePlayer)
			ThePlayer->HurtThePlayer(TrashObject->GetDamageValue());
			UE_LOG(LogTemp, Warning, TEXT("Damaged Player"));
		}
	}
	TrashObject->Destroy();
}
