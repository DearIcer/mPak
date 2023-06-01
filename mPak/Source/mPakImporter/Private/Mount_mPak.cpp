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

	if (!WorldContextObject)
	{	
		UMount_mPak* Ins = nullptr;
		return Ins;
	}


	UMount_mPak* Ins = NewObject<UMount_mPak>();
	Ins->mPakPath = mPakPath;
	Ins->WorldContextObject = WorldContextObject;


	return Ins;
}




void UMount_mPak::Activate()
{

	AActor* tempPtr = nullptr;
	FString ProjectFullSaveDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());


	UmPakFileHandle::mPakUnpackage(ProjectFullSaveDir,mPakPath);

	FString PakPath = "";
#if WITH_EDITOR
	PakPath = FPaths::Combine(ProjectFullSaveDir, TEXT("editor.pak"));
#elif PLATFORM_WINDOWS
	PakPath = FPaths::Combine(ProjectFullSaveDir, TEXT("windows.pak"));
#elif PLATFORM_ANDROID
	PakPath = FPaths::Combine(ProjectFullSaveDir, TEXT("android.pak"));
#else
	// �������
#endif
	 //ҪMount��pak�ļ��Ѿ��㶨��



	IPlatformFile& OldPlatform = FPlatformFileManager::Get().GetPlatformFile();

	FPakPlatformFile* MyPakPlatformFile = new FPakPlatformFile();
	MyPakPlatformFile->Initialize(&OldPlatform, TEXT(""));
	FPlatformFileManager::Get().SetPlatformFile(*MyPakPlatformFile);

	FPakFile* pak = new FPakFile(MyPakPlatformFile, *PakPath, false);
	pak->AddRef();

	FString OldPakMountPoint = pak->GetMountPoint();
	int32 ContentPos = OldPakMountPoint.Find("Content/");

	FString PIEMountPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir() + OldPakMountPoint.RightChop(ContentPos));
 	FString DebugMountPath = FPaths::ProjectDir() + OldPakMountPoint.RightChop(ContentPos);

	FString RightPart = "";

#if WITH_EDITOR
	//GEngine->AddOnScreenDebugMessage(-1, 90.0f, FColor::Yellow, FString::Printf(TEXT("PIEMountPath:%s"), *PIEMountPath));	  //��ӡ������ص�
	MyPakPlatformFile->Mount(*PakPath, 1, *PIEMountPath);	
     	
	FString ContentDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
	RightPart = FPaths::GetPath(PIEMountPath.RightChop(ContentDir.Len()));
	//GEngine->AddOnScreenDebugMessage(-1, 90.0f, FColor::Yellow, FString::Printf(TEXT("PIEMountPath:%s"), *RightPart));	

#else
	//GEngine->AddOnScreenDebugMessage(-1, 90.0f, FColor::Yellow, FString::Printf(TEXT("DebugMountPath:%s"), *DebugMountPath));	  //��ӡ������ص�
	MyPakPlatformFile->Mount(*PakPath, 1, *DebugMountPath);


	FString ContentDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
	RightPart = FPaths::GetPath(DebugMountPath.RightChop(ContentDir.Len()));
	//GEngine->AddOnScreenDebugMessage(-1, 90.0f, FColor::Yellow, FString::Printf(TEXT("DebugMountPath:%s"), *RightPart));	

#endif

	//UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	//UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), TEXT("/Script/Engine.Blueprqint'/Game/%s/BP_Main.BP_Main_C'"),*RightPart);
	UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), *FString::Printf(TEXT("/Script/Engine.Blueprqint'/Game/%s/BP_Main.BP_Main_C'"), *RightPart));

		
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

