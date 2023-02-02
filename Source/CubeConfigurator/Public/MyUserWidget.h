// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

//Secondary struct for comfortable export to json file
USTRUCT(BlueprintType)
struct FCubeMaterial
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cube Material")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cube Material")
	FString Material;
	
};


UCLASS()
class CUBECONFIGURATOR_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable, Category = "Cube Configurator")
	void ExportToJson(TArray<FCubeMaterial> CubeMaterials);
	
};
