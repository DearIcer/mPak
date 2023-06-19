// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "mPakImporter/Public/mPakFileHandle.h"

/**
 * 
 */
class MPAK_API PageFileMaker :public SCompoundWidget
{

public:SLATE_BEGIN_ARGS(PageFileMaker) {}
	  SLATE_END_ARGS()

  void Construct(const FArguments& InArgs);


private:
 	TSharedPtr<SButton> PackButton;
	TSharedPtr<SEditableTextBox> MakeEditableTextBox;
	TSharedPtr<SEditableTextBox> SaveEditableTextBox;
	TSharedPtr<SCheckBox> WindowsEditorCheckBox;
	TSharedPtr<SCheckBox> WindowsCheckBox;
	TSharedPtr<SCheckBox> HololensCheckBox;
	TSharedPtr<SCheckBox> AndroidCheckBox;
	TSharedPtr<SCheckBox> LinuxCheckBox;
	TSharedPtr<SCheckBox> IOSCheckBox;


public:
	void DoCookPlantformTask(FString Plantform);
	void DoPackPlantformTask(FString Plantform);
	TArray<FString> GetAllPakFilesInDirectory(const FString& Directory);
	FText GetSelectDirectory() const;
	FReply OnPackButtonClickFun();



private:
	//获取各种路径
	FString ProjectPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
 	FString FullProjectName = FPaths::ConvertRelativePathToFull(FPaths::GetProjectFilePath());
	FString EngineDir = FPaths::ConvertRelativePathToFull(FPaths::EngineDir());
	FString EditorCmdPath = FPaths::Combine(*EngineDir, TEXT("Binaries"), TEXT("Win64"), TEXT("UnrealEditor-Cmd.exe"));	 \
  	FString ProjectPluginsDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir());
	FString cookBatpath = ProjectPluginsDir += "mPak/ThirdParty/CookContent.bat";


};
