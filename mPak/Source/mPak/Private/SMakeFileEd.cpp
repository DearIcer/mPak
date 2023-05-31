// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"
#include <Kismet/KismetSystemLibrary.h>
//#include "mPakCore.h"
#include <UATHelper/Public/IUATHelperModule.h>
#include <ContentBrowserModule.h>
#include <IContentBrowserSingleton.h>


// Slate UI框架时优化编译时间和构建时间
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

	if (WindowsEditorCheckBox->IsChecked())
	{
		DoPackPlantformTask(TEXT("Editor"));
	}
	if (WindowsCheckBox->IsChecked())
	{
		DoCookPlantformTask(TEXT("Windows"));
		DoPackPlantformTask(TEXT("Windows"));
	}
	if (AndroidCheckBox->IsChecked())
	{
		DoCookPlantformTask(TEXT("Android_ASTC"));
		DoPackPlantformTask(TEXT("Android_ASTC"));
	}


	//获取打包后的所有pak文件
	FString saveDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
	TArray<FString> allPak = GetAllPakFilesInDirectory(saveDir);

	for (auto pak:allPak)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *pak);
	}

	FString EditorStr = SaveEditableTextBox->GetText().ToString();
	bool MakeState;
	TArray<uint8>mPakByte =  UmPakFileHandle::mPakPackage(allPak, EditorStr, MakeState);



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
	FString CookAndroidParam;
	CookAndroidParam += FString::Printf(TEXT(" \"%s\""), *EditorCmdPath);
	CookAndroidParam += FString::Printf(TEXT(" \"%s\""), *FullProjectName);
	CookAndroidParam += FString::Printf(TEXT(" \"%s\""), TEXT("Android_ASTC"));

	FProcHandle CookAndroidHandle = FPlatformProcess::CreateProc(*cookBatpath, *CookAndroidParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
	FPlatformProcess::WaitForProc(CookAndroidHandle);


}



void SMakeFileEd::DoPackPlantformTask(FString Plantform)
{
	
	FString UnrealPakPath = FPaths::ConvertRelativePathToFull(FPaths::EngineDir() / TEXT("Binaries/Win64/UnrealPak.exe"));    //UnrealPak的相对路径
	


	//C:/Users/hotWin/Desktop/dddd/Content/MakePak
	FString EditorStr = MakeEditableTextBox->GetText().ToString();

	//MakePak
	FString Right = EditorStr.RightChop(EditorStr.Find(TEXT("Content/"), ESearchCase::IgnoreCase, ESearchDir::FromStart) + FString("Content/").Len());


	//Cook之后的资产路径
	FString EditorAssicePath = MakeEditableTextBox->GetText().ToString();
	FString WindowsCookPath = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()), TEXT("Cooked/Windows"), FApp::GetProjectName(), TEXT("Content"), Right);
	FString AndroidCookPath = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()), TEXT("Cooked/Android_ASTC"), FApp::GetProjectName(), TEXT("Content"), Right);



	if (Plantform.Equals("Editor"))
	{

		FString outFile = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("editor.pak"));

		FString   PackWindowsParam;
		//PackWindowsParam += FString::Printf(TEXT(" '"'%s'\*"'"), *EditorAssicePath);
 		PackWindowsParam += FString::Printf(TEXT(" %s"), *FPaths::ConvertRelativePathToFull(*outFile));
		PackWindowsParam += FString::Printf(TEXT(" ""%s""/*"), *EditorAssicePath);

		FProcHandle PackEcitorHandle = FPlatformProcess::CreateProc(*UnrealPakPath, *PackWindowsParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
		FPlatformProcess::WaitForProc(PackEcitorHandle);
	
	}
	else if (Plantform.Equals("Windows"))
	{

		FString outFile = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("windows.pak"));

		FString   PackWindowsParam;
		//PackWindowsParam += FString::Printf(TEXT(" '"'%s'\*"'"), *WindowsCookPath);
		PackWindowsParam += FString::Printf(TEXT(" %s"), *FPaths::ConvertRelativePathToFull(*outFile));
		PackWindowsParam += FString::Printf(TEXT(" ""%s""/*"), *WindowsCookPath);

		FProcHandle PackEcitorHandle = FPlatformProcess::CreateProc(*UnrealPakPath, *PackWindowsParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
		FPlatformProcess::WaitForProc(PackEcitorHandle);



	}
	else if (Plantform.Equals("Android_ASTC"))
	{
		FString outFile = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("android.pak"));

		FString   PackWindowsParam;
		//PackWindowsParam += FString::Printf(TEXT(" '"'%s'\*"'"), *AndroidCookPath);
		PackWindowsParam += FString::Printf(TEXT(" %s"), *FPaths::ConvertRelativePathToFull(*outFile));
		PackWindowsParam += FString::Printf(TEXT(" ""%s""/*"), *AndroidCookPath);

		FProcHandle PackEcitorHandle = FPlatformProcess::CreateProc(*UnrealPakPath, *PackWindowsParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
		FPlatformProcess::WaitForProc(PackEcitorHandle);
	}
	else
	{
		// default case


	}

	
}


TArray<FString> SMakeFileEd::GetAllPakFilesInDirectory(const FString& Directory)
{


	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	TArray<FString> FileNames;

   	PlatformFile.IterateDirectory(*Directory, [&FileNames](const TCHAR* FilenameOrDirectory, bool bIsDirectory) -> bool
		{
			if (!bIsDirectory)
			{
				FString Extension = FPaths::GetExtension(FilenameOrDirectory);
				if (Extension.Equals(TEXT("pak"), ESearchCase::IgnoreCase))
				{
					FileNames.Add(FilenameOrDirectory);
				}
			}
			return true;
		});

	//for (const auto& File : FileNames)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("File: %s"), *File);
	//}

	return FileNames;
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