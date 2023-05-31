// Fill out your copyright notice in the Description page of Project Settings.


#include "Mount_mPak.h"
#include <IPlatformFilePak.h>

void UMount_mPak::Event_OnSuccess(UClass* ActorPtr)
{
	if (OnSuccess.IsBound())
	{
		OnSuccess.Broadcast(ActorPtr);
	}
}

void UMount_mPak::Event_OnFailed(UClass* ActorPtr)
{
	if (OnFailed.IsBound())
	{
		OnFailed.Broadcast(ActorPtr);
	}
}

UMount_mPak* UMount_mPak::Mount_mPak(FString mPakPath,  const UObject* WorldContextObject)
{
	UMount_mPak* Ins = NewObject<UMount_mPak>();
	Ins->mPakPath = mPakPath;
	Ins->WorldContextObject = WorldContextObject;
	return Ins;
}




void UMount_mPak::Activate()
{
	AActor* tempPtr = nullptr;
	FString ProjectFullSaveDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());


	TArray<uint8> mPakByte = UmPakFileHandle::ReadFile2Byte(mPakPath);
	UmPakFileHandle::mPakUnpack(mPakByte, ProjectFullSaveDir);

	FString PakPath = "";
#if WITH_EDITOR
	PakPath = FPaths::Combine(ProjectFullSaveDir, TEXT("editor.pak"));
#elif PLATFORM_WINDOWS
	PakPath = FPaths::Combine(ProjectFullSaveDir, TEXT("windows.pak"));
#elif PLATFORM_ANDROID
	PakPath = FPaths::Combine(ProjectFullSaveDir, TEXT("android.pak"));
#else
	// 其他情况
#endif
	 //要Mount的pak文件已经搞定了



	IPlatformFile& OldPlatform = FPlatformFileManager::Get().GetPlatformFile();

	FPakPlatformFile* MyPakPlatformFile = new FPakPlatformFile();
	MyPakPlatformFile->Initialize(&OldPlatform, TEXT(""));
	FPlatformFileManager::Get().SetPlatformFile(*MyPakPlatformFile);

	FPakFile* pak = new FPakFile(MyPakPlatformFile, *PakPath, false);
	pak->AddRef();

	FString OldPakMountPoint = pak->GetMountPoint();
	int32 ContentPos = OldPakMountPoint.Find("Content/");

	FString PIEMountPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir() + OldPakMountPoint.RightChop(ContentPos));	   //PIE使用绝对路径
 	FString DebugMountPath = FPaths::ProjectDir() + OldPakMountPoint.RightChop(ContentPos);    //打包后使用相对路径


#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 9.0f, FColor::Yellow, FString::Printf(TEXT("PIEMountPath:%s"), *PIEMountPath));	  //打印输出挂载点
	MyPakPlatformFile->Mount(*PakPath, 1, *PIEMountPath);		

#else
	GEngine->AddOnScreenDebugMessage(-1, 9.0f, FColor::Yellow, FString::Printf(TEXT("DebugMountPath:%s"), *DebugMountPath));	  //打印输出挂载点
	MyPakPlatformFile->Mount(*PakPath, 1, *DebugMountPath);

#endif

	//UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);


	UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), TEXT("/Script/Engine.Blueprqint'/Game/MakePak/BP_Main.BP_Main_C'"));

		
	if (spActor)
	{
		this->OnSuccess.Broadcast(spActor);
	}
	else
	{
		this->OnFailed.Broadcast(spActor);
	}


	pak->Release();
	FPlatformFileManager::Get().SetPlatformFile(OldPlatform);

	MyPakPlatformFile->Unmount(*PakPath);

}

