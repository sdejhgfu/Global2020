// Fill out your copyright notice in the Description page of Project Settings.


#include "TrashFurnance.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ATrashFurnance::ATrashFurnance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Comp"));
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Comp"));
	SphereComp->SetupAttachment(MeshComp);

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

