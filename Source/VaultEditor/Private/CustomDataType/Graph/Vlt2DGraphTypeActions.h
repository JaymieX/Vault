#pragma once

#include "AssetTypeActions_Base.h"

class FVlt2DGraphTypeActions : public FAssetTypeActions_Base
{
public:
	FVlt2DGraphTypeActions(EAssetTypeCategories::Type InAssetCategory);
	
	virtual FText GetName() const override;
	virtual UClass* GetSupportedClass() const override;
	virtual FColor GetTypeColor() const override;
	virtual uint32 GetCategories() override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects,
		TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;

private:
	EAssetTypeCategories::Type AssetCategory;
};
