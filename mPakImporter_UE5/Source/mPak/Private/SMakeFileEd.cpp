// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"
#include <Kismet/KismetSystemLibrary.h>
#include "mPakCore.h"
#include <UATHelper/Public/IUATHelperModule.h>
//#include <Windows/LiveCodingServer/Private/External/LC_ImmutableString.h>


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
			.Text(LOCTEXT("makePakDir", "C:/Users/hotWin/Desktop/MyProject/Content/makePak"))

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

bool SMakeFileEd::MakePathAndCommand()
{

	//UEAccessPath
	UEAccess_Path = MakeEditableTextBox->GetText().ToString() + "/*";

	//mpak file out path
	mPakOut_Path = SaveEditableTextBox->GetText().ToString();


	//ProjectRoot
	int32 ContentIndex = MakeEditableTextBox->GetText().ToString().Find(TEXT("Content"));
	ProjectRoot = MakeEditableTextBox->GetText().ToString().Left(ContentIndex - 1);


	//ProjectName
	ProjectName = UKismetSystemLibrary::GetGameName();

	//Project_uproject
	//Project_uproject = ProjectRoot + "/" + ProjectName + ".uproject";
	Project_uproject = FPaths::ConvertRelativePathToFull(FPaths::GetProjectFilePath());

	//CookRight
	CookRight = MakeEditableTextBox->GetText().ToString().Right(MakeEditableTextBox->GetText().ToString().Len() - ProjectRoot.Len());


	//打包编辑器命令
	PackPieCmd = "UnrealPak " + pakTempDir + "/pie.pak " + UEAccess_Path;

	//打包Windows包命令
	PackWindowsCmd = "UnrealPak " + pakTempDir + "/run.pak " + ProjectRoot + "/Saved/Cooked/Windows/" + ProjectName + CookRight + "/*";
	
	
	return true;

}



void SMakeFileEd::DoPackFun()
{



	FString  str1 = "UnrealEditor-Cmd.exe ";
	FString  str2 = Project_uproject;
	FString  str3 = " -run=Cook -TargetPlatform=Windows -unversioned -stdout -CrashForUAT -unattended -NoLogTimes -UTF8Output";
   	FString cookWindowsCmd = str1 + str2 + str3;



	//引擎的转换方法会出问题
	std::string MyStdString1(TCHAR_TO_UTF8(*cookWindowsCmd));
	char cookCommand[] = "";
	MyStdString1.copy(cookCommand, MyStdString1.size(), 0);


	//const char* cookCommand = TCHAR_TO_ANSI(*cookWindowsCmd);		//UnrealEditor-Cmd.exe C:/Users/hotPC/Desktop/editP/editP.uproject -run=Cook -TargetPlatform=Windows -CookAll
	const char* packPieCommand = TCHAR_TO_ANSI(*PackPieCmd);		//UnrealPak C:/Users/hotPC/Desktop/editP/Saved/Sandboxes/pie.pak C:/Users/hotPC/Desktop/editP/Content/makePak/*
	//const char* PackWinCommand = TCHAR_TO_ANSI(*PackWindowsCmd);	//UnrealPak C:/Users/hotPC/Desktop/editP/Saved/Sandboxes/run.pak C:/Users/hotPC/Desktop/editP/Saved/Cooked/Windows/editP/Content/makePak/*
	


	std::string MyStdString(TCHAR_TO_UTF8(*PackWindowsCmd));
	char PackWinCommand[]="";
	MyStdString.copy(PackWinCommand, MyStdString.size(), 0);


	
	FString ProjectPluginsDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir());
	FString Batpath = ProjectPluginsDir += "mPakImporter_UE5/ThirdParty/BuildMPak.bat";
	



	FPaths::NormalizeFilename(Batpath);



	//::ProjectName
	//::TargetPakFile_pie
	//::TargetPakFile_run
	//::PakSourceListFile_pie
	//::PakSourceListFile_run
	//::mPakOutput
  	FString TargetPakFile_pie = FString(pakTempDir + "/pie.pak");
	FString TargetPakFile_run = FString(pakTempDir + "/run.pak");
	FString PakSourceListFile_pie = FString(pakTempDir + "/run.pak");
	FString PakSourceListFile_run = FString(ProjectRoot + "/Saved/Cooked/Windows/" + ProjectName + CookRight + "/*");




	FString batParam;
	batParam += FString::Printf(TEXT(" %s"), *Project_uproject);
	batParam += FString::Printf(TEXT(" %s"), *TargetPakFile_pie);
	batParam += FString::Printf(TEXT(" %s"), *TargetPakFile_run);
	batParam += FString::Printf(TEXT(" %s"), *UEAccess_Path);
	batParam += FString::Printf(TEXT(" %s"), *PakSourceListFile_run);
	batParam += FString::Printf(TEXT(" %s"), *mPakOut_Path);





	//启动器是否隐藏
	//启动器是否真正的隐藏	   3
	//返回创建进程的ID
	//优先级默认0
	//指定工作路径
	//剩下两个参数是管线相关的内容
	FProcHandle Handle = FPlatformProcess::CreateProc(*Batpath, *batParam, false, false, false, nullptr, 0, NULL, nullptr, nullptr);
	FPlatformProcess::WaitForProc(Handle);




}

FReply SMakeFileEd::OnPackButtonClickFun()
{


	if (MakePathAndCommand())
	{
		DoPackFun();
	}

  	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE