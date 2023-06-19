// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Paths.h"
#include "Widgets/SCompoundWidget.h"



class MPAK_API SMenuPanel : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuPanel)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);



private:
	TSharedPtr<SWidgetSwitcher> MySwitcher;
	TSharedPtr<SButton> CutButton;
	FReply OnCutButtonClickFun();


};
