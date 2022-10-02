#pragma once

#include "UnrealEd.h"
#include "Vlt2DGraphFactory.generated.h"

UCLASS()
class UVlt2DAnimInstanceFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags,
		UObject* Context, FFeedbackContext* Warn) override;
};
