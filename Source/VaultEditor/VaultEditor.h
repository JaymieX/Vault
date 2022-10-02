#pragma once

#include "IAssetTypeActions.h"
#include "IVaultEditorModuleInterface.h"

class FVaultEditor : public IVaultEditorModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual void AddModuleListeners() override;

	static FVaultEditor& Get()
	{
		return FModuleManager::LoadModuleChecked<FVaultEditor>("VaultEditor");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("VaultEditor");
	}

private:
	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};
