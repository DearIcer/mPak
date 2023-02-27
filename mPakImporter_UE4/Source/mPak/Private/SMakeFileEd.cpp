// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"


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

			SNew(SEditableTextBox)
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
							SNew(SEditableTextBox)
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
								SNew(SCheckBox)
								.IsChecked(true)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("WindowsEditor", "WindowsEditor"))
								]
							]
						
						+ SVerticalBox::Slot()
							[
								SNew(SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Windows", "Windows"))
								]
							]
							
							
						+ SVerticalBox::Slot()
							[
								SNew(SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Hololens", "Hololens"))
								]
							]
							
						+ SVerticalBox::Slot()
							[
								SNew(SCheckBox)
								.IsChecked(false)
								[
									SNew(STextBlock)
									.Text(LOCTEXT("Linux", "Linux"))
								]
							]
							
						+ SVerticalBox::Slot()
							[
								SNew(SCheckBox)
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
						.WidthOverride(300.f)
						[
							SNew(SButton)
							.Text(LOCTEXT("打包", "打包"))
	 	
							//.OnClicked_Raw(this, &FmPakModule::ExtractClicked)
							

						]
					]
		   		]
	]
		];

}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE