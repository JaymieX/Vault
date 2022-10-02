#include "Vlt2DGraphEditor.h"

#include "GraphEditorActions.h"
#include "Framework/Commands/GenericCommands.h"

#define LOCTEXT_NAMESPACE "Vlt2DGraphEditor"

void Vlt2DGraphEditor::Init(const EToolkitMode::Type Mode,
							const TSharedPtr<IToolkitHost>& InitToolkitHost,
                            UVlt2DBaseGraph* Graph)
{
	if(Graph)
	{
		TargetGraph = Graph;
	}
	
	FGenericCommands::Register();
	FGraphEditorCommands::Register();

	// Layout
	const TSharedRef<FTabManager::FLayout> DefaultLayout = FTabManager::NewLayout("Vlt2DGraph_Editor_Default_Layout");
	DefaultLayout->AddArea(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)->Split(
			FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)->SetSizeCoefficient(0.9f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.5f)
					->AddTab(TEXT("Viewport"), ETabState::OpenedTab)->SetHideTabWell(true)
				)
				->Split
				(
					FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.5f)
						->AddTab(TEXT("Property"), ETabState::OpenedTab)->SetHideTabWell(true)
					)
				)
		)
	);

	// init editor
	InitAssetEditor(Mode,
	                InitToolkitHost,
	                TEXT("VaultEditorApp"),
	                DefaultLayout,
	                true,
	                true,
	                TargetGraph,
	                false);

	RegenerateMenusAndToolbars();
}

void Vlt2DGraphEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& RefTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(RefTabManager);
}

void Vlt2DGraphEditor::AddReferencedObjects(FReferenceCollector& Collector)
{
}

FName Vlt2DGraphEditor::GetToolkitFName() const
{
	return TEXT("FVaultEditor");
}

FText Vlt2DGraphEditor::GetBaseToolkitName() const
{
	return LOCTEXT("VaultEditorAppLabel", "Vault Graph Editor");
}

FString Vlt2DGraphEditor::GetWorldCentricTabPrefix() const
{
	return TEXT("VaultEditor");
}

FLinearColor Vlt2DGraphEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor::Red;
}

#undef LOCTEXT_NAMESPACE