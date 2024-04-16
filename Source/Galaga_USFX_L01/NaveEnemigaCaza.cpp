// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaCaza.h"
#include "Galaga_USFX_L01GameMode.h"

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
    TiempoTrascurrido = 0.0f;
	
}
void ANaveEnemigaCaza::Mover(float DeltaTime)
{
    // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();

    // Declara las nuevas posiciones en X e Y
    float NewX;
    float NewY;

    // Calcula las velocidades para el movimiento diagonal
    float VelocidadX = 200.0f; // Velocidad en el eje X
    float VelocidadY = 200.0f; // Velocidad en el eje Y

    // Distancia mínima para considerar que la nave está cerca de un punto de spawn
    float DistanciaMinima = 10.0f;

    // Calcula la distancia a cada punto de spawn
    float DistanciaSpawn1 = FVector::Dist(PosicionActual, FVector(1700.0f, -1600.0f, 250.0f));
    float DistanciaSpawn2 = FVector::Dist(PosicionActual, FVector(1700.0f, 1600.0f, 250.0f));
    float DistanciaSpawn3 = FVector::Dist(PosicionActual, FVector(-1700.0f, 1600.0f, 250.0f));
    float DistanciaSpawn4 = FVector::Dist(PosicionActual, FVector(-1700.0f, -1600.0f, 250.0f));

    // Aplica las velocidades de movimiento diagonal si la nave está cerca de alguno de los puntos de spawn
    if (DistanciaSpawn1 <= DistanciaMinima)
    {
        // Ajusta la velocidad para el punto de spawn 1 (diagonal hacia arriba y hacia la izquierda)
        NewX = PosicionActual.X - VelocidadX * DeltaTime; // Disminuye en X para moverse hacia la izquierda
        NewY = PosicionActual.Y + VelocidadY * DeltaTime; // Aumenta en Y para moverse hacia arriba
    }
    else if (DistanciaSpawn2 <= DistanciaMinima)
    {
        // Ajusta la velocidad para el punto de spawn 2 (diagonal hacia abajo y hacia la izquierda)
        NewX = PosicionActual.X - VelocidadX * DeltaTime; // Disminuye en X para moverse hacia la izquierda
        NewY = PosicionActual.Y - VelocidadY * DeltaTime; // Disminuye en Y para moverse hacia abajo
    }
    else if (DistanciaSpawn3 <= DistanciaMinima)
    {
        // Ajusta la velocidad para el punto de spawn 3 (diagonal hacia abajo y hacia la derecha)
        NewX = PosicionActual.X + VelocidadX * DeltaTime; // Aumenta en X para moverse hacia la derecha
        NewY = PosicionActual.Y - VelocidadY * DeltaTime; // Disminuye en Y para moverse hacia abajo
    }
    else if (DistanciaSpawn4 <= DistanciaMinima)
    {
        // Ajusta la velocidad para el punto de spawn 4 (diagonal hacia arriba y hacia la derecha)
        NewX = PosicionActual.X + VelocidadX * DeltaTime; // Aumenta en X para moverse hacia la derecha
        NewY = PosicionActual.Y + VelocidadY * DeltaTime; // Aumenta en Y para moverse hacia arriba
    }
    else
    {
        // Si la nave no está cerca de ningún punto de spawn, no se mueve
        NewX = PosicionActual.X;
        NewY = PosicionActual.Y;
    }

    // Actualiza la posición del actor
    SetActorLocation(FVector(NewX, NewY, PosicionActual.Z));
}







void ANaveEnemigaCaza::Disparar()
{
}

void ANaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Mover(DeltaTime);
}
