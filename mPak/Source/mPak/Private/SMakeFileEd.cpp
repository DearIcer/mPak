// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"
#include <Kismet/KismetSystemLibrary.h>
#include <UATHelper/Public/IUATHelperModule.h>
#include "../Slate/PageFileMaker.h"
#include <Widgets/Layout/SWidgetSwitcher.h>


// Slate UI框架时优化编译时间和构建时间
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SMakeFileEd"

void SMenuPanel::Construct(const FArguments& InArgs)
{
	
	SAssignNew(MySwitcher, SWidgetSwitcher)
		.WidgetIndex(1)
		+ SWidgetSwitcher::Slot()
		[
			SNew(SButton)
		]
		+ SWidgetSwitcher::Slot()
		[
			SNew(PageFileMaker)
		];

		ChildSlot
		[
				//MySwitcher.ToSharedRef()

			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot().FillWidth(0.05f)
			[
				SNew(SBox)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				.HeightOverride(20.f)
				[
					SAssignNew(CutButton, SButton)
					.Text(LOCTEXT("Change", "Cut"))
					.OnClicked_Raw(this, &SMenuPanel::OnCutButtonClickFun)
				]			

			]
			+ SHorizontalBox::Slot().FillWidth(0.95f)
			[
				MySwitcher.ToSharedRef()
			]
		];

}




FReply SMenuPanel::OnCutButtonClickFun()
{
	//切换0和1
	MySwitcher->GetActiveWidgetIndex() == 0 ? MySwitcher->SetActiveWidgetIndex(1) : MySwitcher->SetActiveWidgetIndex(0);
	return FReply::Handled();
}






END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE