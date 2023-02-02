// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "JsonObjectConverter.h"

void UMyUserWidget::ExportToJson(TArray<FCubeMaterial> CubeMaterials)
{
	TSharedPtr<FJsonObject> JsonRootObject = MakeShareable(new FJsonObject);

	//Set json objects string fields
	for (auto Material : CubeMaterials)
	{
		JsonRootObject->SetStringField(Material.Name, Material.Material);
	}

	//Serialize json object
	FString FileContent;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&FileContent);
	FJsonSerializer::Serialize(JsonRootObject.ToSharedRef(), Writer);

	//Create file
	FFileHelper::SaveStringToFile(FileContent, *(FPaths::ProjectDir() + TEXT("/CubeMaterials.json")));
}
