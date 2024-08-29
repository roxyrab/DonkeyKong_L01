// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ComponentePlataforma.generated.h"

class UStaticMeshComponent;

UCLASS()
class DONKEYKONG_L01_API AComponentePlataforma : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AComponentePlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//PROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* meshPlataforma;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
