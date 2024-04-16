// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTerrestre.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaTerrestre : public ANaveEnemiga
{
	GENERATED_BODY()
	public:
		ANaveEnemigaTerrestre();
	virtual void Mover(float DeltaTime);
	
	virtual void Tick(float DeltaTime) override;
};
