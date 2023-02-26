// Copyright Epic Games, Inc. All Rights Reserved.

#include "mPakStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FmPakStyle::StyleInstance = nullptr;

void FmPakStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FmPakStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FmPakStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("mPakStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FmPakStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("mPakStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("mPak")->GetBaseDir() / TEXT("Resources"));

	Style->Set("mPak.OpenPluginWindow", new IMAGE_BRUSH_SVG(TEXT("mPakLogo"), Icon20x20));

	return Style;
}

void FmPakStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FmPakStyle::Get()
{
	return *StyleInstance;
}
