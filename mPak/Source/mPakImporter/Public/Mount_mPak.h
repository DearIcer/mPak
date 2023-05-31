// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "mPakFileHandle.h"
#include "Mount_mPak.generated.h"

/**
 * 
 */
UCLASS()
class MPAKIMPORTER_API UMount_mPak : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostResult, UClass*, ActorPtr);

	UPROPERTY(BlueprintAssignable)
		FPostResult OnSuccess;
  	UPROPERTY(BlueprintAssignable)
		FPostResult OnFailed;

	void Event_OnSuccess(UClass* ActorPtr);
  	void Event_OnFailed(UClass* ActorPtr);






	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", Category = "Biz API"))
		static UMount_mPak* Mount_mPak(FString mPakPath,const UObject* WorldContextObject);




	virtual void Activate() override;

private:
	FString mPakPath = "";

	const UObject* WorldContextObject;
	
};
