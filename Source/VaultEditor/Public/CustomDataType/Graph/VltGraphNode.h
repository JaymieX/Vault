// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "VltGraphNode.generated.h"

class UVlt2DBaseGraph;

UCLASS(Blueprintable)
class VAULTEDITOR_API UVltGraphNode : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "General")
	FText NodeTitle;

	UPROPERTY(VisibleDefaultsOnly, Category = "General")
	UVlt2DBaseGraph* OwningGraph;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	TArray<UVltGraphNode*> ParentNodes;

	UPROPERTY(BlueprintReadOnly, Category = "General")
	TArray<UVltGraphNode*> ChildrenNodes;
};