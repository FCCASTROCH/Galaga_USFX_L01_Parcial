// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaAcuatica.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_L01_API ANaveEnemigaAcuatica : public ANaveEnemiga
{
	GENERATED_BODY()
	
	public:
		ANaveEnemigaAcuatica();
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		virtual void Mover(float DeltaTime) ;
		
	
};
