// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "mPakStyle.h"

class FmPakCommands : public TCommands<FmPakCommands>
{
public:

	FmPakCommands()
		: TCommands<FmPakCommands>(TEXT("mPak"), NSLOCTEXT("Contexts", "mPak", "mPak Plugin"), NAME_None, FmPakStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};