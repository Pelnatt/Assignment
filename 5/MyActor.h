#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
    GENERATED_BODY()

public:
    AMyActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    FVector2D CurrentLocation; // 현재 위치
    int32_t step(); // 이동 거리 반환 함수
    void move(); // 이동 및 좌표 출력 함수
};