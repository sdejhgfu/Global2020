// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(RootComponent);

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
}

void APlayerCharacter::ReleaseObject()
{
	//TODO: if an object is being held drop the object
	if (bObjectInHand)
	{


		bObjectInHand = false;
	}

}

#pragma endregion


void APlayerCharacter::TracingFromCamera()
{
	//trace from pawn eyes to crosshair
	FVector EyeLocation;
	FRotator EyeRotation;
	FVector ShotDirection;

	FVector TraceEnd = EyeLocation + GrabRange;


	GetActorEyesViewPoint(EyeLocation, EyeRotation);
	ShotDirection = EyeRotation.Vector();


	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.bTraceComplex = true;

	FHitResult Hit;

	//check against only the visible channel
	if (GetWorld()->LineTraceSingleByChannel(Hit, EyeLocation, TraceEnd, ECollisionChannel::ECC_Visibility, QueryParams))
	{
		AActor* HitActor = Hit.GetActor();
		
	}
}