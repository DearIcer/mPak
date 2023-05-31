// Copyright Epic Games, Inc. All Rights Reserved.

#include "mPak.h"
#include "mPakStyle.h"
#include "mPakCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"
#include "SMakeFileEd.h"

static const FName mPakTabName("mPak");

#define LOCTEXT_NAMESPACE "FmPakModule"

void FmPakModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FmPakStyle::Initialize();
	FmPakStyle::ReloadTextures();

	FmPakCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FmPakCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FmPakModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FmPakModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(mPakTabName, FOnSpawnTab::CreateRaw(this, &FmPakModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FmPakTabTitle", "mPak"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FmPakModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FmPakStyle::Shutdown();

	FmPakCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(mPakTabName);
}

TSharedRef<SDockTab> FmPakModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	//FText WidgetText = FText::Format(
	//	LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
	//	FText::FromString(TEXT("FmPakModule::OnSpawnPluginTab")),
	//	FText::FromString(TEXT("mPak.cpp"))
	//	);

	//return SNew(SDockTab)
	//	.TabRole(ETabRole::NomadTab)
	//	[
	//		// Put your tab content here!
	//		SNew(SBox)
	//		.HAlign(HAlign_Center)
	//		.VAlign(VAlign_Center)
	//		[
	//			SNew(STextBlock)
	//			.Text(WidgetText)
	//		]
	//	];





	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SMakeFileEd)
		];


}

void FmPakModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(mPakTabName);
}

void FmPakModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	// 不需要显示在列表里
	//{
	//	UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
	//	{
	//		FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
	//		Section.AddMenuEntryWithCommandList(FmPakCommands::Get().OpenPluginWindow, PluginCommands);
	//	}
	//}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FmPakCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FmPakModule, mPak)