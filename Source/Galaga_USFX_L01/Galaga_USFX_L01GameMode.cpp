// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "Galaga_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "TimerManager.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaAerea.h"
#include "NaveEnemigaTerrestre.h"
#include "NaveEnemigaAcuatica.h"
AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	// set default pawn class to our character class
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = AGalaga_USFX_L01Pawn::StaticClass();

	//NaveEnemiga01 = nullptr;
}
void AGalaga_USFX_L01GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Define las posiciones fijas donde aparecerán los enemigos
    //TArray<FVector> FixedSpawnLocations;
    FixedSpawnLocations.Add(FVector(1700.0f, -1600.0f, 250.0f));  // Ejemplo de posición fija 1
    FixedSpawnLocations.Add(FVector(1700.0f, 1600.0f, 250.0f));  // Ejemplo de posición fija 2
    FixedSpawnLocations.Add(FVector(-1700.0f, 1600.0f, 250.0f));  // Ejemplo de posición fija 3
    FixedSpawnLocations.Add(FVector(-1700.0f, -1600.0f, 250.0f));  // Ejemplo de posición fija 4

    // Configura un temporizador para generar enemigos cada 5 segundos
    GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AGalaga_USFX_L01GameMode::SpawnEnemies, 5.0f, true);
    GetWorldTimerManager().SetTimer(SpawnTimerHand, this, &AGalaga_USFX_L01GameMode::SpawnAeTerreAcua, 10.0f, true);
}

void AGalaga_USFX_L01GameMode::SpawnEnemies()
{
    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        // Selecciona aleatoriamente qué tipo de enemigo generar (puedes ajustar esto según tus necesidades)
        TSubclassOf<AActor> EnemyClass;

        int32 RandomEnemyType = FMath::RandRange(0, 1); // Suponiendo que tienes tres tipos de enemigos diferentes
        switch (RandomEnemyType)
        {
        case 0:
            EnemyClass = ANaveEnemigaCaza::StaticClass();
            break;
        case 1:
            EnemyClass = ANaveEnemigaTransporte::StaticClass();
            break;
        case 2:
            EnemyClass = ANaveEnemigaTransporte::StaticClass();
            // Puedes agregar más tipos de enemigos según sea necesario
            break;
        }

        // Itera sobre las posiciones fijas y genera un enemigo en cada una
        for (FVector SpawnLocation : FixedSpawnLocations)
        {
            // Genera el enemigo en la posición fija actual
            AActor* NewEnemy = World->SpawnActor<AActor>(EnemyClass, SpawnLocation, FRotator::ZeroRotator);
            if (NewEnemy)
            {
                // Personaliza el enemigo según sea necesario
            }
        }
    }
}
void AGalaga_USFX_L01GameMode::SpawnAeTerreAcua()
{

    FVector ubicacionE = FVector(-900.0f, 1000.0f, 400.0f);
    FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
    //Para el spauwn de las objetos de inventario
    for (int i = 0; i < 1; i++) {
        FVector Posicion = FVector(ubicacionE.X, ubicacionE.Y + i * 100.0f, ubicacionE.Z);
        //Generar un número aleatorio entre 0 y 1
        float RandomNumber = FMath::FRandRange(0.0f, 1.0f); // Cambiado el rango a 0.0f - 1.0f

        if (RandomNumber <= 0.33f) { // 33% de probabilidad
            ANaveEnemiga* NaveAerea = GetWorld()->SpawnActor<ANaveEnemigaAerea>(ANaveEnemigaAerea::StaticClass(), Posicion, rotacionNave);
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NaveAerea")));


            }
        }
        else if (RandomNumber <= 0.66f) { // 33% de probabilidad
            ANaveEnemiga* NaveTerrestre = GetWorld()->SpawnActor<ANaveEnemigaTerrestre>(ANaveEnemigaTerrestre::StaticClass(), Posicion, rotacionNave);
            if (GEngine)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("NaveTerrestre")));


            }
        }
        else { // El restante 33% de probabilidad
            ANaveEnemiga* NaveAcuatica = GetWorld()->SpawnActor<ANaveEnemigaAcuatica>(ANaveEnemigaAcuatica::StaticClass(), Posicion, rotacionNave);
            if (GEngine)
           	{
        		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("NaveAcuatica")));

                		
            }
        
        
        }

    }
    

}

//
//void AGalaga_USFX_L01GameMode::BeginPlay()
//{
//	Super::BeginPlay();
//	//Set the game state to playing
//	FVector ubicacionInicioNavesEnemigasCaza = FVector(-500.0f, 500.0f, 250.0f);
//	FVector ubicacionInicioNavesEnemigasTransporte = FVector(500.0f, 500.0f, 250.0f);
//
//	//FVector ubicacionNave01 = FVector(-1000.0f, 500.0f, 250.0f);
//	//FVector ubicacionNave02 = FVector(-500.0f, -500.0f, 250.0f);
//
//	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);
//
//	UWorld* const World = GetWorld();
//	if (World != nullptr)
//	{
//		for (int i = 0; i < 5; i++) {
//			FVector PosicionNaveActual = FVector(ubicacionInicioNavesEnemigasCaza.X, ubicacionInicioNavesEnemigasCaza.Y + i * 300, ubicacionInicioNavesEnemigasTransporte.Z);
//			ANaveEnemigaCaza* NaveEnemigaCazaTemporal = World->SpawnActor<ANaveEnemigaCaza>(PosicionNaveActual, rotacionNave);
//
//			//TANavesEnemigasCaza.Push(NaveEnemigaCazaTemporal);
//			TANavesEnemigas.Push(NaveEnemigaCazaTemporal);
//		}
//
//		float nuevaposicionX = ubicacionInicioNavesEnemigasTransporte.X - 300.0f;
//
//		for (int j = 0; j < 5; j++) {
//			FVector PosicionNaveActual = FVector(nuevaposicionX, ubicacionInicioNavesEnemigasTransporte.Y + j * 300, ubicacionInicioNavesEnemigasTransporte.Z);
//			ANaveEnemigaTransporte* NaveEnemigaTransporteTemporal = World->SpawnActor<ANaveEnemigaTransporte>(PosicionNaveActual, rotacionNave);
//
//			//TANavesEnemigasTransporte.Push(NaveEnemigaTransporteTemporal);
//			TANavesEnemigas.Push(NaveEnemigaTransporteTemporal);
//		}
//
//		//NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNave01, rotacionNave);
//		//NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNave02, rotacionNave);
//
//		TiempoTranscurrido = 0;
//	}
//
//	/*NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
//	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));*/
//
//}
//
void AGalaga_USFX_L01GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TiempoTranscurrido++;

	//if (TiempoTranscurrido >= 100)
	//{
	//	int numeroEnemigo = FMath::RandRange(0, 9);
	//	if(GEngine)
	//	{
	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Hola estoy aqui")));


	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Entero: %d"), numeroEnemigo));
	//		
	//	}
	//	//TANavesEnemigas[numeroEnemigo]->PrimaryActorTick.bCanEverTick = false;
	//	TANavesEnemigas[numeroEnemigo]->SetVelocidad(0);
	//}

}
