#include "MyActor.h"
#include "Kismet/GameplayStatics.h"
#include <random>

AMyActor::AMyActor()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("MyActor가 스폰되었습니다!"));

    CurrentLocation = FVector2D(0, 0); // 시작 위치 (0,0)
    UE_LOG(LogTemp, Warning, TEXT("시작 위치: (%f, %f)"), CurrentLocation.X, CurrentLocation.Y);

    move(); // 이동 시작
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

int32_t AMyActor::step()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1); // 0 또는 1 생성

    return distrib(gen);
}

void AMyActor::move()
{
    for (int i = 0; i < 10; ++i)
    {
        int32_t xStep = step();
        int32_t yStep = step();

        CurrentLocation.X += xStep;
        CurrentLocation.Y += yStep;

        UE_LOG(LogTemp, Warning, TEXT("이동 %d: (%f, %f)"), i + 1, CurrentLocation.X, CurrentLocation.Y);
    }
}
