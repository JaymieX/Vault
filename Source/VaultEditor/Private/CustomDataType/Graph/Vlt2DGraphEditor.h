#pragma once

#include "CoreMinimal.h"
#include "CustomDatatype/Graph/Vlt2DBaseGraph.h"

class Vlt2DGraphEditor : public FAssetEditorToolkit, public FGCObject
{
private:
	UVlt2DBaseGraph* TargetGraph = nullptr;
	
public:
	void Init(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UVlt2DBaseGraph* Graph);
	
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& RefTabManager) override;
	
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
};
