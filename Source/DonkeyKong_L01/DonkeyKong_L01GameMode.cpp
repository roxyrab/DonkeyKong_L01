// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_L01GameMode.h"
#include "DonkeyKong_L01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Obstaculo.h"

ADonkeyKong_L01GameMode::ADonkeyKong_L01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADonkeyKong_L01GameMode::BeginPlay()
{
		Super::BeginPlay();

		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Actor Spawning"));
		// Spawn an instance of the AMyFirstActor class at the
		//default location.
		FTransform SpawnLocation;
		SpawnLocation.SetLocation(FVector(1160.0f, -210.0f, 140.0f));
		SpawnLocation.SetRotation(FQuat(FRotator(0.0f, 0.0f, 0.0f)));
		GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation);


}
