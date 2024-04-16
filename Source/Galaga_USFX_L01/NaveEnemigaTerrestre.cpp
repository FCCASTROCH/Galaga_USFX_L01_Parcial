// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaTerrestre.h"

ANaveEnemigaTerrestre::ANaveEnemigaTerrestre()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}

void ANaveEnemigaTerrestre::Mover(float DeltaTime)
{
    // Se mueve un poco mas rapido en su estado de sigilo
 // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();
    float NewY; //Declara la nueva posición en Y
    float PendienteActual = -100; //Declara la pendiente actual
    float Velocidad = 100.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posición en X  
    float Amplitud = 5.0f;
    float Frecuencia = 4.0f;

    // Si han pasado más de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {


        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y - Amplitud * FMath::Sin(Frecuencia * Timer);//Es negativa para que se mueva hacia abajo;


    }
    else
    {

        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y;
    }
    TiempoTranscurrido += PI / 2 * DeltaTime;
    Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo

    // Calcula las nuevas posiciones en X e Y


    // Actualiza la posición del actor
    SetActorLocation(FVector(NewX, NewY, PosicionActual.Z));

    if (GetActorLocation().X <= -1800.0f)
    {

        SetActorLocation(FVector(1850.0f, NewY, PosicionActual.Z));


    }
    if (GetActorLocation().Y >= 1850)
    {
        SetActorLocation(FVector(NewX, -1850.0f, PosicionActual.Z));
    }

    if (GetActorLocation().Y <= -1850)
    {
        SetActorLocation(FVector(NewX, 1850.0f, PosicionActual.Z));
    }
}

void ANaveEnemigaTerrestre::Tick(float DeltaTime)
{
		Super::Tick(DeltaTime);
        Mover(DeltaTime);
}
