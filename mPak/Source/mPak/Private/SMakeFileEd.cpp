// Fill out your copyright notice in the Description page of Project Settings.


#include "SMakeFileEd.h"
#include "SlateOptMacros.h"
#include <Kismet/KismetSystemLibrary.h>
#include <UATHelper/Public/IUATHelperModule.h>
#include "../Slate/PageFileMaker.h"


// Slate UI框架时优化编译时间和构建时间
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SMakeFileEd"

void SMenuPanel::Construct(const FArguments& InArgs)
{
 

	ChildSlot
		[
			SNew(PageFileMaker)
		];

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE