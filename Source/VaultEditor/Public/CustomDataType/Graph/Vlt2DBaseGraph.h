// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VltGraphNode.h"
#include "UObject/NoExportTypes.h"
#include "Vlt2DBaseGraph.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UVlt2DBaseGraph : public UObject
{
	GENERATED_BODY()

protected:
	TSubclassOf<UVltGraphNode> NodeType;
	
public:
	UVlt2DBaseGraph();
	virtual ~UVlt2DBaseGraph() override = default;
	
	UPROPERTY(EditDefaultsOnly, Category = "General")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	TArray<UVltGraphNode*> RootNodes;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	TArray<UVltGraphNode*> Nodes;
};
