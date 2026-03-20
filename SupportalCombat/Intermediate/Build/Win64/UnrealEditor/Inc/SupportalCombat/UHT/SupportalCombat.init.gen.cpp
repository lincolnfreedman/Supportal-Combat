// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSupportalCombat_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	SUPPORTALCOMBAT_API UFunction* Z_Construct_UDelegateFunction_SupportalCombat_OnEnemyDied__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SupportalCombat;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SupportalCombat()
	{
		if (!Z_Registration_Info_UPackage__Script_SupportalCombat.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_SupportalCombat_OnEnemyDied__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/SupportalCombat",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0x9B42FF01,
			0x6EA0BC65,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SupportalCombat.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_SupportalCombat.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SupportalCombat(Z_Construct_UPackage__Script_SupportalCombat, TEXT("/Script/SupportalCombat"), Z_Registration_Info_UPackage__Script_SupportalCombat, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x9B42FF01, 0x6EA0BC65));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
