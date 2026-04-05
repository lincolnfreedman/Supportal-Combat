#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EQC_TaggedActors.generated.h"

UCLASS(Abstract)
class SUPPORTALCOMBAT_API UEQC_TaggedActors : public UEnvQueryContext
{
    GENERATED_BODY()

public:
    virtual void ProvideContext(FEnvQueryInstance& QueryInstance,
        FEnvQueryContextData& ContextData) const override;

protected:
    FName ActorTag;
    float MaxSearchRadius = 5000.f;
};

UCLASS(meta = (DisplayName = "Healing Puddles"))
class SUPPORTALCOMBAT_API UEQC_HealingPuddles : public UEQC_TaggedActors
{
    GENERATED_BODY()

public:
    UEQC_HealingPuddles()
    {
        ActorTag = TEXT("HealingPuddle");
        MaxSearchRadius = 5000.f;
    }
};

UCLASS(meta = (DisplayName = "Enemies"))
class SUPPORTALCOMBAT_API UEQC_Enemies : public UEQC_TaggedActors
{
    GENERATED_BODY()

public:
    UEQC_Enemies()
    {
        ActorTag = TEXT("Enemy");
        MaxSearchRadius = 5000.f;
    }
};

UCLASS(meta = (DisplayName = "Allies"))
class SUPPORTALCOMBAT_API UEQC_Allies : public UEQC_TaggedActors
{
    GENERATED_BODY()

public:
    UEQC_Allies()
    {
        ActorTag = TEXT("Ally");
        MaxSearchRadius = 5000.f;
    }
};