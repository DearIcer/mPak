// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"
#include <Kismet/KismetSystemLibrary.h>
//#include "mPakCore.h"
#include <UATHelper/Public/IUATHelperModule.h>
#include <ContentBrowserModule.h>
#include <IContentBrowserSingleton.h>



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
			.Text(this,&SMakeFileEd::GetSelectDirectory)

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
							.Text(LOCTEXT("outFile", "C:/Users/hotWin/Desktop/car.mpak"))
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
								.IsEnabled(false)							
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
								//.IsEnabled(false)
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
								.IsEnabled(false)
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
								.IsEnabled(false)
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
							.OnClicked_Raw(this, &SMakeFileEd::OnPackButtonClickFun)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
						]
					]
		   		]
			]
		];

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION




FReply SMakeFileEd::OnPackButtonClickFun()
{

	//if (WindowsCheckBox->IsChecked())
	//{
	//	DoCookPlantformTask(TEXT("Windows"));
	//}


	
	//if (AndroidCheckBox->IsChecked())
	//{
	//	DoCookPlantformTask(TEXT("Android_ASTC"));
	//}

	DoPackPlantformTask(TEXT("Editor"));




	return FReply::Handled();
}



void SMakeFileEd::DoCookPlantformTask(FString Plantform)
{


	//路径有可能存在空格	 所以转义双引号
   	
	FString CookWindowsParam;
	CookWindowsParam += FString::Printf(TEXT(" \"%s\""), *EditorCmdPath);	  //C:/Program Files/Epic Games/UE_5.2/Engine/Binaries/Win64/UnrealEditor-Cmd.exe
	CookWindowsParam += FString::Printf(TEXT(" \"%s\""), *FullProjectName);		//C:/Users/hotWin/Desktop/dddd/dddd.uproject
	CookWindowsParam += FString::Printf(TEXT(" \"%s\""), *Plantform);			//Windows

	FProcHandle CookWinHandle = FPlatformProcess::CreateProc(*cookBatpath, *CookWindowsParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
	FPlatformProcess::WaitForProc(CookWinHandle);



	//Cook 安卓
   //FString CookAndroidParam;
   //CookAndroidParam += FString::Printf(TEXT(" \"%s\""), *EditorCmdPath);
   //CookAndroidParam += FString::Printf(TEXT(" \"%s\""), *FullProjectName);
   //CookAndroidParam += FString::Printf(TEXT(" \"%s\""), TEXT("Android_ASTC"));

   //FProcHandle CookAndroidHandle = FPlatformProcess::CreateProc(*cookBatpath, *CookAndroidParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
   //FPlatformProcess::WaitForProc(CookAndroidHandle);


}



void SMakeFileEd::DoPackPlantformTask(FString Plantform)
{
	
	FString UnrealPakPath = FPaths::ConvertRelativePathToFull(FPaths::EngineDir() / TEXT("Binaries/Win64/UnrealPak.exe"));    //UnrealPak的相对路径
	FString EditorAssicePath = MakeEditableTextBox->GetText().ToString();
	FString AndroidAssicePath = "";
	FString WindowsAssicePath = "";




	if (Plantform.Equals("Editor"))
	{

		FString outFile = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("editor.pak"));
		FString   PackWindowsParam;
		//PackWindowsParam += FString::Printf(TEXT(" '"'%s'\*"'"), *EditorAssicePath);
 		PackWindowsParam += FString::Printf(TEXT(" %s"), *FPaths::ConvertRelativePathToFull(*outFile));
		PackWindowsParam += FString::Printf(TEXT(" ""%s""/*"), *EditorAssicePath);

	
		UE_LOG(LogTemp, Warning, TEXT("%s"), *UnrealPakPath);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *PackWindowsParam);

		FProcHandle PackEcitorHandle = FPlatformProcess::CreateProc(*UnrealPakPath, *PackWindowsParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
		FPlatformProcess::WaitForProc(PackEcitorHandle);
	
	}
	else if (Plantform.Equals("Windows"))
	{
		// do something else
	}
	else if (Plantform.Equals("Android_ASTC"))
	{
		// do something else
	}
	else
	{
		// default case
	}

		
	
}




FText SMakeFileEd::GetSelectDirectory() const
{


	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	IContentBrowserSingleton& ContentBrowserSingleton = ContentBrowserModule.Get();
	TArray<FString> Folders;
	ContentBrowserSingleton.GetSelectedFolders(Folders);

	
	FString absContentPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()) + "Content";

	if (Folders.Num() > 0)
	{
		FString FullSelectPaht = Folders[0].Replace(TEXT("/All/Game"), *absContentPath);
		
		//暂不支持插件路径
		//FString FullSelectPaht = Folders[0].Replace(TEXT("/All/Plugins"), *absContentPath);

		const FText res = FText::FromString(FullSelectPaht);
		return res;
	}
	else
	{
		const FText res = FText::FromString("Please Select a folder in the Content browser");
		return res;
		
	}

}

#undef LOCTEXT_NAMESPACE