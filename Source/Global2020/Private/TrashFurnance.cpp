// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashFurnance.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystem.h"
#include "TrashActor.h"
#include "PlayerCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h" 


// Sets default values
ATrashFurnance::ATrashFurnance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Comp"));
	SphereComp->SetupAttachment(MeshComp);
	SphereComp->SetGenerateOverlapEvents(true);

	ParticleEffect = CreateDefaultSubobject<UParticleSystem>(TEXT("Furnace Effect"));
	
}

// Called when the game starts or when spawned
void ATrashFurnance::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrashFurnance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATrashFurnance::NotifyActorBeginOverlap(AActor* OtherActor)
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
		//add normal damage to player to hurt them.
		if (ThePlayer)
			ThePlayer->HurtThePlayer(TrashObject->GetDamageValue());
		UE_LOG(LogTemp, Warning, TEXT("Damaged Player"));


		

		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleEffect, SphereComp->GetComponentTransform());
		

		TrashObject->Destroy();
	}
}