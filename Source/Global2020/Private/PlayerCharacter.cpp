// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArmComp);
	
	PhysicsHandleComponent = CreateDefaultSubobject<UPhysicsHandleComponent>("Physics Handle");

	GrabHoldLocation = CreateDefaultSubobject<USceneComponent>("Held Object Location");
	GrabHoldLocation->SetupAttachment(Camera);

		
}

#pragma region Begin Play/Tick

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PhysicsHandleComponent->SetTargetLocation(GrabHoldLocation->GetComponentLocation());

	

}

#pragma endregion

#pragma region PlayerInput

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Grab", IE_Pressed, this, &APlayerCharacter::GrabObject);
	PlayerInputComponent->BindAction("Grab", IE_Released, this, &APlayerCharacter::ReleaseObject);

	
}

#pragma endregion

#pragma region Grab Object/Release Object

void APlayerCharacter::GrabObject()
{
	//TODO: Add functionality to grab objects by raycasting out from the camera forward vector
	//trace from pawn eyes to crosshair
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	
	GetController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);


	FVector TraceEnd = PlayerViewPointLocation + (PlayerViewPointRotation.Vector() * GrabRange);

	
	//DrawDebugLine(
	//	GetWorld(),
	//	PlayerViewPointLocation,
	//	TraceEnd,
	//	FColor(255, 0, 0),
	//	false,
	//	1.f,
	//	0.f,
	//	10.f
	//);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.bTraceComplex = true;

	FHitResult Hit;

	//check against only the visible channel
	if (GetWorld()->LineTraceSingleByChannel(Hit, PlayerViewPointLocation, TraceEnd, ECollisionChannel::ECC_Visibility, QueryParams))
	{
		

		//get actor hit
		AActor* HitActor = Hit.GetActor();

		if (HitActor)
		{
			//get mesh
			UStaticMeshComponent* MeshHit = Cast<UStaticMeshComponent>(HitActor->GetComponentByClass(UStaticMeshComponent::StaticClass()));

			

			if (MeshHit)
			{

				//make sure its simulating physics
				if (MeshHit->IsSimulatingPhysics())
				{
					PhysicsHandleComponent->GrabComponentAtLocation(MeshHit, NAME_None, Hit.Location);

					bObjectInHand = true;


					MeshHit->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

					MeshHit->SetAngularDamping(AngularDampWhenObjectHeld);

					HeldObject = MeshHit;
				}
			}

		}
	}
}

void APlayerCharacter::ReleaseObject()
{
	if (bObjectInHand)
	{
		PhysicsHandleComponent->ReleaseComponent();

		bObjectInHand = false;

		HeldObject->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	
		HeldObject->SetAngularDamping(0);

		HeldObject = nullptr;
	}

}

#pragma endregion

