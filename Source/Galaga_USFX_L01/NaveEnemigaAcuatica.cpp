// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaAcuatica.h"

ANaveEnemigaAcuatica::ANaveEnemigaAcuatica()
{
		PrimaryActorTick.bCanEverTick = true;
		static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
		mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);

}

void ANaveEnemigaAcuatica::BeginPlay()
{
	Super::BeginPlay();
}
void ANaveEnemigaAcuatica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveEnemigaAcuatica::Mover(float DeltaTime)
{
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
}
