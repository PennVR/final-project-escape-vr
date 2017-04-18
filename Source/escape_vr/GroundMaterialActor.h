// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GroundMaterialActor.generated.h"

UCLASS()
class ESCAPE_VR_API AGroundMaterialActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGroundMaterialActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
	UMaterialInstance* fireMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
	UStaticMeshComponent* fireMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float RunningTime;
	
};
