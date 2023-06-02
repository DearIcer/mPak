// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "mPakFileHandle.generated.h"

/**
 * 
 */

 USTRUCT(BlueprintType)
struct FBlueprintFileInfo
{
	 GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 fileSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Plantform;
};



UCLASS()
class MPAKIMPORTER_API UmPakFileHandle : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	
	struct FileInfo
	{
		int32 fileSize;
		char fileName[20] = {};
	};


	static int32 getFileSize(FString inPath) { return FPlatformFileManager::Get().GetPlatformFile().FileSize(*inPath); };
	static FString getFileName(FString inPath) { FString FileName = FPaths::GetCleanFilename(inPath); return  FileName; };
	static bool WriteByte2File(TArray<uint8> byte, FString outPath);
	static TArray<uint8> ReadFile2Byte(FString inPath);




public:

	UFUNCTION(BlueprintCallable, Category = "mPakHandle", meta = (DisplayName = "mPakUnpackage"))
		static bool mPakUnpackage(FString exportPath , FString mPakFile);

	UFUNCTION(BlueprintCallable, Category = "mPakHandle", meta = (DisplayName = "mPakPackage"))
		static TArray<uint8> mPakPackage(TArray<FString> inFilePtahs, FString outFile,bool& Success);

	UFUNCTION(BlueprintCallable, Category = "mPakHandle", meta = (DisplayName = "GetmPakFileInfo"))
		static TArray<FBlueprintFileInfo> GetmPakFileInfo(FString inFile);





};
