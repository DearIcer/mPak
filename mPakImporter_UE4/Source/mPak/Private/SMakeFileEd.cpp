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
								.IsChecked(false)
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

void SMakeFileEd::MakePath()
{

	UEAccessPath = MakeEditableTextBox->GetText().ToString() + "*";
	ProjectRoot = "";

}

FString SMakeFileEd::GetMakePath()
{
	FString aa = MakeEditableTextBox->GetText().ToString() + "*";
	return 	aa;
}

FReply SMakeFileEd::OnClickFun()
{
	//UEAccessPath
	UEAccessPath = MakeEditableTextBox->GetText().ToString() + "*";
	

	//ProjectRoot
	int32 ContentIndex = MakeEditableTextBox->GetText().ToString().Find(TEXT("Content"));
	ProjectRoot = MakeEditableTextBox->GetText().ToString().Left(ContentIndex - 1);
	

	//ProjectName
	ProjectName = UKismetSystemLibrary::GetGameName();

	//Project_uproject
	Project_uproject = ProjectRoot + "/" + ProjectName  + ".uproject";


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Project_uproject);

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE