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

    CurrentLocation = FVector2D(0, 0); // ���� ��ġ (0,0)
    UE_LOG(LogTemp, Warning, TEXT("���� ��ġ: (%f, %f)"), CurrentLocation.X, CurrentLocation.Y);

    move(); // �̵� ����
}

void AMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

int32_t AMyActor::step()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1); // 0 �Ǵ� 1 ����

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

        UE_LOG(LogTemp, Warning, TEXT("�̵� %d: (%f, %f)"), i + 1, CurrentLocation.X, CurrentLocation.Y);
    }
}