// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 * 早期的initStudio，迁移到这里
 * 
 */



 //预打包资产的路径 , 项目root , 项目名 , 项目_uproject  ,cook右边的路径
FString UEAccessPath = "";
FString ProjectRoot = "";
FString ProjectName = "";
FString Project_uproject = "";
FString PackPieCmd = "";
FString PackWindowsCmd = "";
FString CookRight = "";			//\Content\makePak
FString mPakOutPath = "";



//将打包文件临时放在save的沙盒里面
FString pakTempDir = FPaths::ConvertRelativePathToFull(FPaths::SandboxesDir());




class MPAK_API SMakeFileEd : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMakeFileEd)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
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


	bool MakePathAndCommand();

	void DoPackFun();


	FReply OnPackButtonClickFun();



};
