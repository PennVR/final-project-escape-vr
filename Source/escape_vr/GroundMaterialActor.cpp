// Fill out your copyright notice in the Description page of Project Settings.

#include "escape_vr.h"
#include "GroundMaterialActor.h"


// Sets default values
AGroundMaterialActor::AGroundMaterialActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USoundWave> tmp(TEXT("/Game/Audio/Wake_Up.Wake_Up"));
	wakeupSound = tmp.Object;

	ConstructorHelpers::FObjectFinder<USoundWave> tmp1(TEXT("/Game/Audio/Clay.Clay"));
	commonSounds.push_back(tmp1.Object);
	ConstructorHelpers::FObjectFinder<USoundWave> tmp2(TEXT("/Game/Audio/Shovel.Shovel"));
	commonSounds.push_back(tmp2.Object);
	ConstructorHelpers::FObjectFinder<USoundWave> tmp3(TEXT("/Game/Audio/Table.Table"));
	commonSounds.push_back(tmp3.Object);
	ConstructorHelpers::FObjectFinder<USoundWave> tmp4(TEXT("/Game/Audio/Glass_Shards.Glass_Shards"));
	commonSounds.push_back(tmp4.Object);

	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(commonSounds), std::end(commonSounds), engine);

}

// Called when the game starts or when spawned
void AGroundMaterialActor::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::PlaySoundAtLocation(this, wakeupSound, FVector(0.0f, 0.0f, 0.0f));

	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &AGroundMaterialActor::AdvanceTimer, 1.0f, true);
}

// Called every frame
void AGroundMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AGroundMaterialActor::AdvanceTimer()
{
	--CountdownTime;
	if (CountdownTime < 1)
	{
		//We're done counting down, so stop running the timer.
		//GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();
	}
}

void AGroundMaterialActor::CountdownHasFinished()
{
	UGameplayStatics::PlaySoundAtLocation(this, commonSounds[commonSoundsIndex], FVector(0.0f, 0.0f, 0.0f));
	commonSoundsIndex++;
	if (commonSoundsIndex == commonSounds.size())
		commonSoundsIndex = 0;
	CountdownTime = 30;
}

void AGroundMaterialActor::SoundDelayTimer()
{
	CountdownTime = 40;
}

void AGroundMaterialActor::ReallyLongTimer()
{
	CountdownTime = 100000;
}