// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
class UTrashGrabber;
class UCameraComponent;
class UPhysicsHandleComponent;
class USpringArmComponent;
class USceneComponent;

UCLASS()
class GLOBAL2020_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	float GrabRange = 300;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	UPhysicsHandleComponent* PhysicsHandleComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	USceneComponent* GrabHoldLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components", meta = (ClampMin = 0.f))
	float AngularDampWhenObjectHeld = 10;

	bool bObjectInHand;

	UFUNCTION(BlueprintCallable, Category = "Trash")
	void GrabObject();

	UFUNCTION(BlueprintCallable, Category = "Trash")
	void ReleaseObject();


	UStaticMeshComponent* HeldObject;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void HurtThePlayer(float DamageTakenValue);
};
