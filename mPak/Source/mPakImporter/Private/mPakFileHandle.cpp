// Fill out your copyright notice in the Description page of Project Settings.


#include "mPakFileHandle.h"
#include <Containers/StringConv.h>

bool UmPakFileHandle::WriteByte2File(TArray<uint8> byte, FString outPath)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle* FileHandle = PlatformFile.OpenWrite(*outPath);

	if (FileHandle)
	{
		FileHandle->Write(byte.GetData(), byte.Num());
		delete FileHandle;
	}
	return true;
}

TArray<uint8> UmPakFileHandle::ReadFile2Byte(FString inPath)
{
	// ��ȡƽ̨�ļ�ϵͳ
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// ��ȡ�ļ���TArray<uint8>
	TArray<uint8> FileData;
	FFileHelper::LoadFileToArray(FileData, *inPath);

	return FileData;
}

bool UmPakFileHandle::mPakUnpackage(FString exportPath,FString mPakFile)
{

	TArray<uint8> byteArray = ReadFile2Byte(mPakFile);

	uint8* bytePtr = byteArray.GetData();
	// ��TArray<uint8>�ж�ȡint32�ͽṹ������
	bytePtr = byteArray.GetData();
	int32 numFiles;
	FMemory::Memcpy(&numFiles, bytePtr, sizeof(int32));
	bytePtr += sizeof(int32);

	//��ȡ�ṹ������
	TArray<FileInfo> fileInfos;
	fileInfos.SetNum(numFiles);
	for (int i = 0; i < numFiles; i++) {
		FileInfo fileInfo;
		FMemory::Memcpy(&fileInfo, bytePtr, sizeof(FileInfo));
		fileInfos[i] = fileInfo;
		bytePtr += sizeof(FileInfo);
	}

	//��ȡ�ļ����ݿ鲢���ļ����浽SaveFilePath
	for (int i = 0; i < fileInfos.Num(); i++) {
		FString fileName = FString(ANSI_TO_TCHAR(fileInfos[i].fileName));
		int fileSize = fileInfos[i].fileSize;
		TArray<uint8> fileData;
		fileData.SetNum(fileSize);
		FMemory::Memcpy(fileData.GetData(), bytePtr, fileSize);
		bytePtr += fileSize;

		FString filePath = exportPath / fileName;
		if (!FFileHelper::SaveArrayToFile(fileData, *filePath)) {
			UE_LOG(LogTemp, Error, TEXT("Failed to save file %s"), *filePath);
			return false;
		}
	}

	// ��ӡֵ
	UE_LOG(LogTemp, Warning, TEXT("numFiles: %d"), numFiles);
	for (int i = 0; i < fileInfos.Num(); i++) {
		UE_LOG(LogTemp, Display, TEXT("fileName: %s, fileSize: %d"), ANSI_TO_TCHAR(fileInfos[i].fileName), fileInfos[i].fileSize);
	}

	return true;
}

TArray<uint8> UmPakFileHandle::mPakPackage(TArray<FString> inFilePtahs, FString SaveFilePath, bool& Success)
{

	// �洢�ṹ�����TArray<uint8>��
	TArray<uint8> byteArray;
	int32 numStructs = inFilePtahs.Num();
	byteArray.AddUninitialized(sizeof(int32) + sizeof(FileInfo) * numStructs);	
	uint8* bytePtr = byteArray.GetData();

	// �洢int32
	FMemory::Memcpy(bytePtr, &numStructs, sizeof(int32));
	bytePtr += sizeof(int32);

	// �洢�ṹ������
	for (int i = 0; i < numStructs; i++) {
		FileInfo fileInfo;


		FString fileName = getFileName(inFilePtahs[i]);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, *fileName);


		//sprintf(fileInfo.fileName, "%s",TCHAR_TO_ANSI(*fileName));	//�ļ��� ����������
		strcpy_s(fileInfo.fileName, sizeof(fileInfo.fileName), TCHAR_TO_ANSI(*fileName));

		fileInfo.fileSize = getFileSize(inFilePtahs[i]);			//�ļ���С

		FMemory::Memcpy(bytePtr, &fileInfo, sizeof(FileInfo));
		bytePtr += sizeof(FileInfo);
	}

	//�洢���ݿ�
	for (int i = 0; i < numStructs; i++) {
		TArray<uint8> fileData;
		if (FFileHelper::LoadFileToArray(fileData, *inFilePtahs[i])) {    // ��ȡ�ļ���TArray
			byteArray.Append(fileData);      // ���ݿ�
		}
	}

	 if (SaveFilePath !="")
	 {
		WriteByte2File(byteArray, SaveFilePath);
	 }

	 
	 Success = FPaths::FileExists(SaveFilePath);

	// ������õ�����д���ļ�
	/*	int32 bytesWritten = 0;
	 *	FFileHelper::SaveArrayToFile(byteArray, *SaveFilePath, &bytesWritten);
	 */
	return byteArray;
}

