// Fill out your copyright notice in the Description page of Project Settings.

#include "escape_vr.h"
#include "GroundMaterialActor.h"


// Sets default values
AGroundMaterialActor::AGroundMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/Content/Object/Shape_Sphere.Shape_Sphere"));
}

// Called when the game starts or when spawned
void AGroundMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FPaths::GameContentDir());


	FVector NewScale = GetActorScale();

	NewScale.X = 0.1f;
	NewScale.Y = 0.1f;
	NewScale.Z = 0.1f;
	
}

// Called every frame
void AGroundMaterialActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation();
	FVector NewScale = GetActorScale();

	DeltaTime *= FMath::RandRange(1.0f, 5.0f);
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	float DeltaWidth = (FMath::Cos(RunningTime + DeltaTime) - FMath::Cos(RunningTime));

	NewLocation.Z += DeltaHeight * 1.0f * FMath::RandRange(1.0, 2.0f);

	float scale = FMath::RandRange(0.025, 0.1f) / 15.0f;
	NewScale.X += DeltaWidth * scale;
	NewScale.Y += DeltaWidth * scale;
	NewScale.Z += DeltaWidth * scale;

	if(NewScale.X < 0.05f)
	{
		NewScale.X = 0.05f;
		NewScale.Y = 0.05f;
		NewScale.Z = 0.05f;

	}

	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
	SetActorScale3D(NewScale);


}

