// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"
#include <Kismet/KismetSystemLibrary.h>


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SMakeFileEd"
void SMakeFileEd::Construct(const FArguments& InArgs)
{

	

	ChildSlot
		[
			SNew(SBox)
	.HAlign(HAlign_Center)
	.VAlign(VAlign_Center)
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		.AutoHeight()
		[

			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.AutoWidth()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("a", "要打包的路径 "))
		]
	+ SHorizontalBox::Slot()
		[
			SNew(SBox)
			.WidthOverride(300.f)
		[

			//SNew(SEditableTextBox)
			SAssignNew(MakeEditableTextBox,SEditableTextBox)
			.Text(LOCTEXT("b", "C:/Users/hotPC/Desktop/editP/Content/makePak"))

		]
		]


		]

		+SVerticalBox::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.AutoHeight()
			[
				SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					.AutoWidth()
					[
					SNew(STextBlock)
					.Text(LOCTEXT("c", "要保存的路径 "))
					]
					+ SHorizontalBox::Slot()
					[
						SNew(SBox)
						.WidthOverride(300.f)
						[
							//SNew(SEditableTextBox)
							SAssignNew(SaveEditableTextBox, SEditableTextBox)
							.Text(LOCTEXT("b", "C:/projectname/content/makmpak/"))
						]
					]
			]


		+SVerticalBox::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			.AutoHeight()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
							[
								//SNew(SCheckBox)
								SAssignNew(WindowsEditorCheckBox,SCheckBox)
								.IsChecked(true)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("WindowsEditor", "WindowsEditor"))
								]
							]
						
						+ SVerticalBox::Slot()
							[
								//SNew(SCheckBox)
								SAssignNew(WindowsCheckBox, SCheckBox)
								.IsChecked(true)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Windows", "Windows"))
								]
							]
							
							
						+ SVerticalBox::Slot()
							[
								//SNew(SCheckBox)
								SAssignNew(HololensCheckBox, SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Hololens", "Hololens"))
								]
							]

						+ SVerticalBox::Slot()
							[
								//SNew(SCheckBox)
								SAssignNew(AndroidCheckBox, SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Android", "Android"))
								]
							]
							
						+ SVerticalBox::Slot()
							[
								//SNew(SCheckBox)
								SAssignNew(LinuxCheckBox, SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Linux", "Linux"))
								]
							]
					
						+ SVerticalBox::Slot()
							[
								//SNew(SCheckBox)
								SAssignNew(IOSCheckBox, SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("IOS", "IOS"))
								]
							]
					]

					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Right)
					.VAlign(VAlign_Bottom)
					[
						SNew(SBox)
						.WidthOverride(270.f)
						[
						
							SAssignNew(PackButton,SButton)
							.Text(LOCTEXT("打包", "打包"))	
							.OnClicked_Raw(this, &SMakeFileEd::OnClickFun)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
						]
					]
		   		]
			]
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

bool SMakeFileEd::MakePathAndCommand()
{

	//UEAccessPath
	UEAccessPath = MakeEditableTextBox->GetText().ToString() + "*";


	//ProjectRoot
	int32 ContentIndex = MakeEditableTextBox->GetText().ToString().Find(TEXT("Content"));
	ProjectRoot = MakeEditableTextBox->GetText().ToString().Left(ContentIndex - 1);


	//ProjectName
	ProjectName = UKismetSystemLibrary::GetGameName();

	//Project_uproject
	Project_uproject = ProjectRoot + "/" + ProjectName + ".uproject";

	//CookRight
	CookRight = MakeEditableTextBox->GetText().ToString().Right(MakeEditableTextBox->GetText().ToString().Len() - ProjectRoot.Len());


	//打包编辑器命令
	PackPieCmd = "UnrealPak " + pakTempDir + "/pie.pak " + UEAccessPath;

	//打包Windows包命令
	PackWindowsCmd = "UnrealPak " + pakTempDir + "/run.pak " + ProjectRoot + "/Saved/Cooked/Windows/" + ProjectName + CookRight + "/*";



	return true;

}



void SMakeFileEd::DoPackFun()
{




	//FText cookWindowsCmd = FText::Format(
	//	LOCTEXT("cookWindowsCmd", "UnrealEditor-Cmd.exe {0} -run=Cook -TargetPlatform=Windows -CookAll"),
	//	Project_uproject
	//	);


	FString  str1 = "UnrealEditor-Cmd.exe ";
	FString  str2 = Project_uproject;
	FString  str3 = " -run=Cook -TargetPlatform=Windows -CookAll";

	FString cookWindowsCmd = str1 + str2 + str3;



	char* cookCommand = TCHAR_TO_ANSI(*cookWindowsCmd);
	char* packPieCommand = TCHAR_TO_ANSI(*PackPieCmd);
	char* PackWinCommand = TCHAR_TO_ANSI(*PackWindowsCmd);
	system(cookCommand);
	system(packPieCommand);
	system(PackWinCommand);



}

FReply SMakeFileEd::OnClickFun()
{


	if (MakePathAndCommand())
	{
		DoPackFun();
	}
	



  	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE