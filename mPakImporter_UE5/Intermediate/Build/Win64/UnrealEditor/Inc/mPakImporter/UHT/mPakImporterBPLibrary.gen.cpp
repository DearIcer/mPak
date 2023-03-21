// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "mPakImporter/Public/mPakImporterBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodemPakImporterBPLibrary() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	MPAKIMPORTER_API UClass* Z_Construct_UClass_UmPakImporterBPLibrary();
	MPAKIMPORTER_API UClass* Z_Construct_UClass_UmPakImporterBPLibrary_NoRegister();
	UPackage* Z_Construct_UPackage__Script_mPakImporter();
// End Cross Module References
	DEFINE_FUNCTION(UmPakImporterBPLibrary::execMPakImport)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_mPakFile);
		P_GET_UBOOL(Z_Param_bSpawnActor);
		P_GET_UBOOL(Z_Param_bSpawnAccess);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_spawnTransform);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=UmPakImporterBPLibrary::MPakImport(Z_Param_mPakFile,Z_Param_bSpawnActor,Z_Param_bSpawnAccess,Z_Param_Out_spawnTransform,Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void UmPakImporterBPLibrary::StaticRegisterNativesUmPakImporterBPLibrary()
	{
		UClass* Class = UmPakImporterBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MPakImport", &UmPakImporterBPLibrary::execMPakImport },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics
	{
		struct mPakImporterBPLibrary_eventMPakImport_Parms
		{
			FString mPakFile;
			bool bSpawnActor;
			bool bSpawnAccess;
			FTransform spawnTransform;
			const UObject* WorldContextObject;
			AActor* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_mPakFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_mPakFile;
		static void NewProp_bSpawnActor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawnActor;
		static void NewProp_bSpawnAccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawnAccess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_spawnTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_spawnTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_mPakFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_mPakFile = { "mPakFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(mPakImporterBPLibrary_eventMPakImport_Parms, mPakFile), METADATA_PARAMS(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_mPakFile_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_mPakFile_MetaData)) };
	void Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnActor_SetBit(void* Obj)
	{
		((mPakImporterBPLibrary_eventMPakImport_Parms*)Obj)->bSpawnActor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnActor = { "bSpawnActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(mPakImporterBPLibrary_eventMPakImport_Parms), &Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnActor_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnAccess_SetBit(void* Obj)
	{
		((mPakImporterBPLibrary_eventMPakImport_Parms*)Obj)->bSpawnAccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnAccess = { "bSpawnAccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(mPakImporterBPLibrary_eventMPakImport_Parms), &Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnAccess_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_spawnTransform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_spawnTransform = { "spawnTransform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(mPakImporterBPLibrary_eventMPakImport_Parms, spawnTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_spawnTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_spawnTransform_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(mPakImporterBPLibrary_eventMPakImport_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_WorldContextObject_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(mPakImporterBPLibrary_eventMPakImport_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_mPakFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_bSpawnAccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_spawnTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/mPakImporterBPLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UmPakImporterBPLibrary, nullptr, "MPakImport", nullptr, nullptr, sizeof(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::mPakImporterBPLibrary_eventMPakImport_Parms), Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UmPakImporterBPLibrary);
	UClass* Z_Construct_UClass_UmPakImporterBPLibrary_NoRegister()
	{
		return UmPakImporterBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UmPakImporterBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UmPakImporterBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_mPakImporter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UmPakImporterBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UmPakImporterBPLibrary_MPakImport, "MPakImport" }, // 2079882624
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UmPakImporterBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/* \n*\x09""Function library class.\n*\x09""Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*\x09When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*\x09""BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*\x09""BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*\x09""DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*\x09\x09\x09\x09Its lets you name the node using characters not allowed in C++ function names.\n*\x09""CompactNodeTitle - the word(s) that appear on the node.\n*\x09Keywords -\x09the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. \n*\x09\x09\x09\x09Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*\x09""Category -\x09the category your node will be under in the Blueprint drop-down menu.\n*\n*\x09""For more info on custom blueprint nodes visit documentation:\n*\x09https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation\n*/" },
		{ "IncludePath", "mPakImporterBPLibrary.h" },
		{ "ModuleRelativePath", "Public/mPakImporterBPLibrary.h" },
		{ "ToolTip", "*      Function library class.\n*      Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.\n*\n*      When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.\n*      BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.\n*      BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.\n*      DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.\n*                              Its lets you name the node using characters not allowed in C++ function names.\n*      CompactNodeTitle - the word(s) that appear on the node.\n*      Keywords -      the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.\n*                              Good example is \"Print String\" node which you can find also by using keyword \"log\".\n*      Category -      the category your node will be under in the Blueprint drop-down menu.\n*\n*      For more info on custom blueprint nodes visit documentation:\n*      https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UmPakImporterBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UmPakImporterBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UmPakImporterBPLibrary_Statics::ClassParams = {
		&UmPakImporterBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UmPakImporterBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UmPakImporterBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UmPakImporterBPLibrary()
	{
		if (!Z_Registration_Info_UClass_UmPakImporterBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UmPakImporterBPLibrary.OuterSingleton, Z_Construct_UClass_UmPakImporterBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UmPakImporterBPLibrary.OuterSingleton;
	}
	template<> MPAKIMPORTER_API UClass* StaticClass<UmPakImporterBPLibrary>()
	{
		return UmPakImporterBPLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UmPakImporterBPLibrary);
	UmPakImporterBPLibrary::~UmPakImporterBPLibrary() {}
	struct Z_CompiledInDeferFile_FID_Users_hotWin_Desktop_MyProject_Plugins_mPakImporter_UE5_Source_mPakImporter_Public_mPakImporterBPLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_hotWin_Desktop_MyProject_Plugins_mPakImporter_UE5_Source_mPakImporter_Public_mPakImporterBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UmPakImporterBPLibrary, UmPakImporterBPLibrary::StaticClass, TEXT("UmPakImporterBPLibrary"), &Z_Registration_Info_UClass_UmPakImporterBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UmPakImporterBPLibrary), 2005293163U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_hotWin_Desktop_MyProject_Plugins_mPakImporter_UE5_Source_mPakImporter_Public_mPakImporterBPLibrary_h_4042548165(TEXT("/Script/mPakImporter"),
		Z_CompiledInDeferFile_FID_Users_hotWin_Desktop_MyProject_Plugins_mPakImporter_UE5_Source_mPakImporter_Public_mPakImporterBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_hotWin_Desktop_MyProject_Plugins_mPakImporter_UE5_Source_mPakImporter_Public_mPakImporterBPLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
