// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 * ���ڵ�initStudio��Ǩ�Ƶ�����
 * 
 */



 //Ԥ����ʲ���·�� , ��Ŀroot , ��Ŀ�� , ��Ŀ_uproject  ,cook�ұߵ�·��
FString UEAccessPath = "";
FString ProjectRoot = "";
FString ProjectName = "";
FString Project_uproject = "";
FString PackPieCmd = "";
FString PackWindowsCmd = "";
FString CookRight = "";			//\Content\makePak
FString mPakOutPath = "";



//������ļ���ʱ����save��ɳ������
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
