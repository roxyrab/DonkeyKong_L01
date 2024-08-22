// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKong_L01GameMode.generated.h"

class AObstaculo;
class ADonkeyKong_L01Character;

UCLASS(minimalapi)
class ADonkeyKong_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKong_L01GameMode();
protected:
	virtual void BeginPlay() override;

	AObstaculo* obstaculo01;
	ADonkeyKong_L01Character* player01;
};



