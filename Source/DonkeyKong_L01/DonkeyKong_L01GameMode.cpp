// Copyright Epic Games, Inc. All Rights Reserved.

#include "DonkeyKong_L01GameMode.h"
#include "DonkeyKong_L01Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Obstaculo.h"
#include "DonkeyKong_L01Character.h"
#include "ComponentePlataforma.h"

ADonkeyKong_L01GameMode::ADonkeyKong_L01GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	obstaculo01 = nullptr;
	player01 = nullptr;
	
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		player01 = Cast<ADonkeyKong_L01Character>(PlayerPawnBPClass.Class);
     
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
	obstaculo01 = GetWorld()->SpawnActor<AObstaculo>(AObstaculo::StaticClass(), SpawnLocation);
	if (player01 != nullptr)
	{
		player01->SetObstaculo(obstaculo01);
	}

	FVector posicionInicial = FVector(1160.0f, -1100.0f, 400.f);
	FRotator rotacionInicial = FRotator(0.0f, 0.0f, 10.0f);
	FTransform SpawnLocationCP;
	float anchoComponentePlataforma = 600.0f;
	float incrementoAltoComponentePlataforma = -105.0f;
	float incrementoAltoEntrePisos = 800.0f;
	float incrementoInicioPiso = 100.0f;

	for (int npp = 0; npp < 5; npp++) {
		rotacionInicial.Roll = rotacionInicial.Roll * -1;
		incrementoInicioPiso = incrementoInicioPiso * -1;
		incrementoAltoComponentePlataforma = incrementoAltoComponentePlataforma * -1;
		SpawnLocationCP.SetRotation(FQuat(rotacionInicial));

		for (int ncp = 0; ncp < 5; ncp++) {
			SpawnLocationCP.SetLocation(FVector(posicionInicial.X, posicionInicial.Y + anchoComponentePlataforma * ncp, posicionInicial.Z));
			componentesPlataforma.Add(GetWorld()->SpawnActor<AComponentePlataforma>(AComponentePlataforma::StaticClass(), SpawnLocationCP));
			if (ncp < 4) {
				posicionInicial.Z = posicionInicial.Z + incrementoAltoComponentePlataforma;
			}
		}

		posicionInicial.Z = posicionInicial.Z + incrementoAltoEntrePisos;
		posicionInicial.Y = posicionInicial.Y + incrementoInicioPiso;
	}

}
