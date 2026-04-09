// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "EQT_PositionInertia.generated.h"

/**
 * 
 */
UCLASS(meta = (DisplayName = "EQT Position Inertia"))
class SUPPORTALCOMBAT_API UEQT_PositionInertia : public UEnvQueryTest
{
	GENERATED_BODY()
	
public:
    UEQT_PositionInertia();

    UPROPERTY(EditAnywhere, Category = "Inertia")
    FName MoveToLocationKey = TEXT("MoveToLocation");

    UPROPERTY(EditAnywhere, Category = "Inertia")
    float InertiaRadius = 600.f;

    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

private:
    mutable FVector CachedCurrentDest;
    mutable bool bHasValidDest = false;
};
