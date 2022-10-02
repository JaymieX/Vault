#include "VaultEditor.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "CustomDataType/Graph/Vlt2DGraphTypeActions.h"

IMPLEMENT_GAME_MODULE(FVaultEditor, VaultEditor)

void FVaultEditor::StartupModule()
{
	// Register custom data types
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	
	// Add custom category
	EAssetTypeCategories::Type VaultGraphCategory =
		AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("VaultGraphs")), FText::FromString("Vault Graphs"));

	// Register custom asset
	TSharedPtr<IAssetTypeActions> Vlt2DGraphAction = MakeShareable(new FVlt2DGraphTypeActions(VaultGraphCategory));
	AssetTools.RegisterAssetTypeActions(Vlt2DGraphAction.ToSharedRef());
	
	CreatedAssetTypeActions.Add(Vlt2DGraphAction);

	IVaultEditorModuleInterface::StartupModule();
}

void FVaultEditor::ShutdownModule()
{
	// Unregister all custom asset types
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (auto Asset : CreatedAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(Asset.ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();
	
	IVaultEditorModuleInterface::ShutdownModule();
}

void FVaultEditor::AddModuleListeners()
{
	IVaultEditorModuleInterface::AddModuleListeners();
}
