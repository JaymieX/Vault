#include "Vlt2DGraphTypeActions.h"

#include "Vlt2DGraphEditor.h"
#include "CustomDataType/Graph/Vlt2DBaseGraph.h"

FVlt2DGraphTypeActions::FVlt2DGraphTypeActions(EAssetTypeCategories::Type InAssetCategory) :
AssetCategory(InAssetCategory)
{
}

FText FVlt2DGraphTypeActions::GetName() const
{
	return FText::FromString("2D Base Graph");
}

UClass* FVlt2DGraphTypeActions::GetSupportedClass() const
{
	return UVlt2DBaseGraph::StaticClass();
}

FColor FVlt2DGraphTypeActions::GetTypeColor() const
{
	return FColor(230, 50, 10);
}

uint32 FVlt2DGraphTypeActions::GetCategories()
{
	return AssetCategory;
}

void FVlt2DGraphTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects,
                                             TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		if (UVlt2DBaseGraph* Graph = Cast<UVlt2DBaseGraph>(*ObjIt))
		{
			TSharedRef<Vlt2DGraphEditor> NewGraphEditor(new Vlt2DGraphEditor());
			NewGraphEditor->Init(Mode, EditWithinLevelEditor, Graph);
		}
	}
}
