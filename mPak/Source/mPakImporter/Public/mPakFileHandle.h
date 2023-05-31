// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "mPakFileHandle.generated.h"

/**
 * 
 */
UCLASS()
class MPAKIMPORTER_API UmPakFileHandle : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()



public:

	UFUNCTION(BlueprintCallable,Category="mPakHandle", meta = (DisplayName = "WriteByte2File"))
	static bool WriteByte2File(TArray<uint8> byte, FString outPath);

	UFUNCTION(BlueprintCallable, Category = "mPakHandle", meta = (DisplayName = "ReadFile2Byte"))
	static TArray<uint8> ReadFile2Byte(FString inPath);

	UFUNCTION(BlueprintCallable, Category = "mPakHandle", meta = (DisplayName = "mPakUnpack"))
	static bool mPakUnpack(TArray<uint8> inByteArr, FString SaveFilePath);

	UFUNCTION(BlueprintCallable, Category = "mPakHandle", meta = (DisplayName = "mPakMaker"))
	static TArray<uint8> mPakMaker(TArray<FString> inFilePtahs, FString outFile);


private:

	struct FileInfo
	{
		int32 fileSize;
		char fileName[20];
	};

	static int32 getFileSize(FString inPath) { return FPlatformFileManager::Get().GetPlatformFile().FileSize(*inPath); };
	static FString getFileName(FString inPath) { FString FileName = FPaths::GetCleanFilename(inPath); return  FileName; };
	
};
