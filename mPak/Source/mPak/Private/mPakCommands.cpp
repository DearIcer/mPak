// Copyright Epic Games, Inc. All Rights Reserved.

#include "mPakCommands.h"

#define LOCTEXT_NAMESPACE "FmPakModule"

void FmPakCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "mPak", "Bring up mPak window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
