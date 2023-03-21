// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodemPakImporter_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_mPakImporter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_mPakImporter()
	{
		if (!Z_Registration_Info_UPackage__Script_mPakImporter.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/mPakImporter",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xA8C3F235,
				0x50344F2F,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_mPakImporter.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_mPakImporter.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_mPakImporter(Z_Construct_UPackage__Script_mPakImporter, TEXT("/Script/mPakImporter"), Z_Registration_Info_UPackage__Script_mPakImporter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xA8C3F235, 0x50344F2F));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
