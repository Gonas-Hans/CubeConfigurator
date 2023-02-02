// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "JsonObjectConverter.h"

void UMyUserWidget::ExportToJson(TArray<FCubeMaterial> CubeMaterials)
{
	//TODO: Do something with array
	/*
	TArray<TSharedPtr<FJsonValue>> JsonCubeMaterials;

	for (auto Material : CubeMaterials)
	{
		FString CubeMaterialString;
		FJsonObjectConverter::UStructToJsonObjectString(Material, CubeMaterialString);
		
		JsonCubeMaterials.Add(MakeShareable(new FJsonValueString(CubeMaterialString)));
	}
	
	TSharedPtr<FJsonObject> JsonRootObject = MakeShareable(new FJsonObject);
	JsonRootObject->SetArrayField("Cube materials", JsonCubeMaterials);
	
	FString FileContent;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&FileContent);
	FJsonSerializer::Serialize(JsonRootObject.ToSharedRef(), Writer);
	
	FFileHelper::SaveStringToFile(FileContent, *(FPaths::ProjectDir() + TEXT("/CubeMaterials.json")));
	*/
	
	TSharedPtr<FJsonObject> JsonRootObject = MakeShareable(new FJsonObject);

	for (auto Material : CubeMaterials)
	{
		JsonRootObject->SetStringField(Material.Name, Material.Material);
	}
	
	FString FileContent;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&FileContent);
	FJsonSerializer::Serialize(JsonRootObject.ToSharedRef(), Writer);

	FFileHelper::SaveStringToFile(FileContent, *(FPaths::ProjectDir() + TEXT("/CubeMaterials.json")));
}
