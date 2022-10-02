#include "Vlt2DGraphFactory.h"

#include "CustomDataType/Graph/Vlt2DBaseGraph.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"

UVlt2DAnimInstanceFactory::UVlt2DAnimInstanceFactory(const FObjectInitializer& ObjectInitializer) :
Super(ObjectInitializer)
{
	SupportedClass = UVlt2DBaseGraph::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UVlt2DAnimInstanceFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
                                                     EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UVlt2DBaseGraph* NewObjectAsset = NewObject<UVlt2DBaseGraph>(InParent, InClass, InName, Flags | RF_Transactional);
	return NewObjectAsset;
}
