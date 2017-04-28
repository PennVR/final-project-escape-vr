// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include <algorithm>
#include <random>

#include "GameFramework/Actor.h"
#include "GroundMaterialActor.generated.h"

UCLASS()
class ESCAPE_VR_API AGroundMaterialActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	USoundWave* wakeupSound;
	std::vector<USoundWave*> commonSounds;
	int32 commonSoundsIndex = 0;


	int32 CountdownTime = 30;

	FTimerHandle CountdownTimerHandle;

	void AdvanceTimer();

	void CountdownHasFinished();

	// Sets default values for this actor's properties
	AGroundMaterialActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	float RunningTime;
	
	UFUNCTION(BlueprintCallable, Category="groundmaterial")
	void SoundDelayTimer();
};
