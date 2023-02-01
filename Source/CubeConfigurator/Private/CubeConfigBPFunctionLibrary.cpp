// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeConfigBPFunctionLibrary.h"

#include "JsonObjectConverter.h"

void UCubeConfigBPFunctionLibrary::ExportToJson(FCubeMaterial StructToExport)
{
	/*FString Path = FPaths::ProjectDir();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Path);

	FString FileName = FString("Name.json");

	FFileHelper::SaveStringToFile(Path, *FileName);*/

	FString FileContent;

	FJsonObjectConverter::UStructToJsonObjectString(StructToExport, FileContent);

	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) + TEXT("/MessageLog.json");
	FFileHelper::SaveStringToFile(FileContent, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
	
}
