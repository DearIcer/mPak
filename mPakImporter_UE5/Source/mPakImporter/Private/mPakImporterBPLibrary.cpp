// Copyright Epic Games, Inc. All Rights Reserved.

#include "mPakImporterBPLibrary.h"
#include "mPakImporter.h"
#include "unMPakLib.h"
#include "mPakCore.h"
#include "IPlatformFilePak.h"

UmPakImporterBPLibrary::UmPakImporterBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}


AActor* UmPakImporterBPLibrary::mpakImport(const FString& mPakFile,  bool bSpawnActor, bool bSpawnAccess, const FTransform& spawnTransform, const UObject* WorldContextObject)
{

	std::string cstr(TCHAR_TO_UTF8(*mPakFile));
	unMPakLibTool temp;
	bool has = temp.unMpak(cstr);


#if WITH_EDITOR
	//const FString& PakPath = "C:\\Users\\hotWin\\Desktop\\ccccccc\\Saved\\Sandboxes\\pie.pak";

	const FString& PakPath = FPaths::ConvertRelativePathToFull(*FPaths::ProjectSavedDir()) + "/pie.pak";
#else
	//const FString& PakPath = "C:\\Users\\hotWin\\Desktop\\ccccccc\\Saved\\Sandboxes\\run.pak";

	const FString& PakPath = FPaths::ConvertRelativePathToFull(*FPaths::ProjectSavedDir()) + "/run.pak";
#endif
	

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


#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 9.0f, FColor::Yellow, FString::Printf(TEXT("PIEMountPath:%s"), *PIEMountPath));	  //打印输出挂载点
	MyPakPlatformFile->Mount(*PakPath, 1, *PIEMountPath);		

#else
	GEngine->AddOnScreenDebugMessage(-1, 9.0f, FColor::Yellow, FString::Printf(TEXT("DebugMountPath:%s"), *DebugMountPath));	  //打印输出挂载点
	MyPakPlatformFile->Mount(*PakPath, 1, *DebugMountPath);

#endif

	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	//UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), TEXT("/Script/Engine.Blueprqint'/Game/MakePak/BP_Main.BP_Main_C'"));


	AActor* spawnActor = nullptr;


	if (bSpawnActor)
	{
		UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), TEXT("/Script/Engine.Blueprqint'/Game/makePak/BP_Main.BP_Main_C'"));
		spawnActor = World->SpawnActor<AActor>(spActor, spawnTransform);
	}


	pak->Release();
	FPlatformFileManager::Get().SetPlatformFile(OldPlatform);

	if (bSpawnAccess)
	{
		FString ContentDir = FPaths::ProjectContentDir().Append(TEXT("makePak"));
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		PlatformFile.CreateDirectory(*ContentDir);
	}


	MyPakPlatformFile->Unmount(*PakPath);

	return spawnActor;
}

FString UmPakImporterBPLibrary::getLibStr(FString inStr)
{
	//std::string cstr(TCHAR_TO_UTF8(*inStr));

	//
	//std::string outStr = std::getFileName(cstr);

	return "";
}

AActor* UmPakImporterBPLibrary::MPakImportFormCore(const FString& mPakFile, bool bSpawnActor, bool bSpawnAccess, const FTransform& spawnTransform, const UObject* WorldContextObject)
{

	FString pakTempDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());



	FString ProjectPluginsDir = FPaths::ConvertRelativePathToFull(FPaths::ProjectPluginsDir());
	FString Batpath = ProjectPluginsDir += "mPakImporter_UE5/ThirdParty/mPakCore2.exe";


	FString batParam;
	batParam += FString::Printf(TEXT(" %s"), *mPakFile);
	batParam += FString::Printf(TEXT(" -o=%s"), *pakTempDir);
	FProcHandle Handle = FPlatformProcess::CreateProc(*Batpath, *batParam, false, true, true, nullptr, 0, NULL, nullptr, nullptr);
	FPlatformProcess::WaitForProc(Handle);



#if WITH_EDITOR
	//const FString& PakPath = "C:\\Users\\hotWin\\Desktop\\ccccccc\\Saved\\Sandboxes\\pie.pak";

	const FString& PakPath = FPaths::ConvertRelativePathToFull(*FPaths::ProjectSavedDir()) + "/pie.pak";
#else
	//const FString& PakPath = "C:\\Users\\hotWin\\Desktop\\ccccccc\\Saved\\Sandboxes\\run.pak";

	const FString& PakPath = FPaths::ConvertRelativePathToFull(*FPaths::ProjectSavedDir()) + "/run.pak";
#endif


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


#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, 9.0f, FColor::Yellow, FString::Printf(TEXT("PIEMountPath:%s"), *PIEMountPath));	  //打印输出挂载点
	MyPakPlatformFile->Mount(*PakPath, 1, *PIEMountPath);

#else
	GEngine->AddOnScreenDebugMessage(-1, 9.0f, FColor::Yellow, FString::Printf(TEXT("DebugMountPath:%s"), *DebugMountPath));	  //打印输出挂载点
	MyPakPlatformFile->Mount(*PakPath, 1, *DebugMountPath);

#endif

	UWorld* const World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);

	//UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), TEXT("/Script/Engine.Blueprqint'/Game/MakePak/BP_Main.BP_Main_C'"));


	AActor* spawnActor = nullptr;


	if (bSpawnActor)
	{
		UClass* spActor = LoadClass<AActor>(AActor::StaticClass(), TEXT("/Script/Engine.Blueprqint'/Game/makePak/BP_Main.BP_Main_C'"));
		spawnActor = World->SpawnActor<AActor>(spActor, spawnTransform);
	}


	pak->Release();
	FPlatformFileManager::Get().SetPlatformFile(OldPlatform);

	if (bSpawnAccess)
	{
		FString ContentDir = FPaths::ProjectContentDir().Append(TEXT("makePak"));
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		PlatformFile.CreateDirectory(*ContentDir);
	}


	MyPakPlatformFile->Unmount(*PakPath);

	return spawnActor;

}



