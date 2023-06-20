// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NetTools.generated.h"

/**
 * 
 */


UCLASS()
class NETWORK_API UNetTools	: public UObject
{
	GENERATED_BODY()

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostResult, FString, ReturnMessage);





public:
	UPROPERTY(BlueprintAssignable)
		FPostResult OnSuccess;
													
	UPROPERTY(BlueprintAssignable)
		FPostResult OnFailed;



};



