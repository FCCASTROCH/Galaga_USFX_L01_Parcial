// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Galaga_USFX_L01GameMode.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    TiempoTrascurrido = 0.0f;
	
}
void ANaveEnemigaCaza::Mover(float DeltaTime)
{
    // Obtiene la posici�n actual del actor
     // Obtiene la posici�n actual del actor
    FVector PosicionActual = GetActorLocation();
    float NewY; //Declara la nueva posici�n en Y
    float PendienteActual = -100; //Declara la pendiente actual
    float Velocidad = 200.0f; //Declara la velocidad de la nave 
    float NewX; //Declara la nueva posici�n en X  
    float Amplitud = 5.0f;
    float Frecuencia = 4.0f;

    // Si han pasado m�s de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {


        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y - Amplitud * FMath::Sin(Frecuencia * Timer);//Es negativa para que se mueva hacia abajo;


    }
    else
    {

        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y + Velocidad * DeltaTime;
    }
    TiempoTranscurrido += PI / 2 * DeltaTime;
    Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo

    // Calcula las nuevas posiciones en X e Y


    // Actualiza la posici�n del actor
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







void ANaveEnemigaCaza::Disparar()
{
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Mover(DeltaTime);
}
