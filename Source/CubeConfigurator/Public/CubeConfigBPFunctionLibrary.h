// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CubeConfigBPFunctionLibrary.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCubeMaterial
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cube Material")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Cube Material")
	UMaterialInterface* Material;
	
};

UCLASS()
class CUBECONFIGURATOR_API UCubeConfigBPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Cube Configurator")
	static void ExportToJson(FCubeMaterial StructToExport);
	
};
