#pragma once

#include "Modules/ModuleManager.h"
#include "Containers/Array.h"
#include "Templates/SharedPointer.h"

class IVaultEditorModuleListenerInterface
{
public:
	virtual ~IVaultEditorModuleListenerInterface() = default;
	virtual void OnStartupModule() {};
	virtual void OnShutdownModule() {};
};

class IVaultEditorModuleInterface : public IModuleInterface
{
protected:
	TArray<TSharedRef<IVaultEditorModuleListenerInterface>> ModuleListeners;
	
public:
	virtual void StartupModule() override
	{
		if (!IsRunningCommandlet())
		{
			AddModuleListeners();
			for (auto Mod : ModuleListeners)
			{
				Mod->OnStartupModule();
			}
		}
	}

	virtual void ShutdownModule() override
	{
		for (auto Mod : ModuleListeners)
		{
			Mod->OnShutdownModule();
		}
	}

	virtual void AddModuleListeners() {};
};
