// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaAerea.h"

ANaveEnemigaAerea::ANaveEnemigaAerea()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));
	//// Create the mesh component
	//mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	PrimaryActorTick.bCanEverTick = true;

}
void ANaveEnemigaAerea::BeginPlay()
{
	Super::BeginPlay();
}
void ANaveEnemigaAerea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveEnemigaAerea::Mover(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	NewLocation += GetActorForwardVector() * velocidad * DeltaTime;
	SetActorLocation(NewLocation);
}