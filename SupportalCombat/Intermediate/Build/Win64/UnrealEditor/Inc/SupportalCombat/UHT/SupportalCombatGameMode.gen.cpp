// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SupportalCombatGameMode.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSupportalCombatGameMode() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SUPPORTALCOMBAT_API UClass* Z_Construct_UClass_ASupportalCombatGameMode();
SUPPORTALCOMBAT_API UClass* Z_Construct_UClass_ASupportalCombatGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_SupportalCombat();
// ********** End Cross Module References **********************************************************

// ********** Begin Class ASupportalCombatGameMode *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_ASupportalCombatGameMode;
UClass* ASupportalCombatGameMode::GetPrivateStaticClass()
{
	using TClass = ASupportalCombatGameMode;
	if (!Z_Registration_Info_UClass_ASupportalCombatGameMode.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SupportalCombatGameMode"),
			Z_Registration_Info_UClass_ASupportalCombatGameMode.InnerSingleton,
			StaticRegisterNativesASupportalCombatGameMode,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_ASupportalCombatGameMode.InnerSingleton;
}
UClass* Z_Construct_UClass_ASupportalCombatGameMode_NoRegister()
{
	return ASupportalCombatGameMode::GetPrivateStaticClass();
}
struct Z_Construct_UClass_ASupportalCombatGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *  Simple GameMode for a third person game\n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SupportalCombatGameMode.h" },
		{ "ModuleRelativePath", "SupportalCombatGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Simple GameMode for a third person game" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class ASupportalCombatGameMode constinit property declarations *****************
// ********** End Class ASupportalCombatGameMode constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASupportalCombatGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_ASupportalCombatGameMode_Statics
UObject* (*const Z_Construct_UClass_ASupportalCombatGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SupportalCombat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASupportalCombatGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASupportalCombatGameMode_Statics::ClassParams = {
	&ASupportalCombatGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ADu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASupportalCombatGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ASupportalCombatGameMode_Statics::Class_MetaDataParams)
};
void ASupportalCombatGameMode::StaticRegisterNativesASupportalCombatGameMode()
{
}
UClass* Z_Construct_UClass_ASupportalCombatGameMode()
{
	if (!Z_Registration_Info_UClass_ASupportalCombatGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASupportalCombatGameMode.OuterSingleton, Z_Construct_UClass_ASupportalCombatGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASupportalCombatGameMode.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ASupportalCombatGameMode);
ASupportalCombatGameMode::~ASupportalCombatGameMode() {}
// ********** End Class ASupportalCombatGameMode ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_linco_OneDrive_Documents_Unreal_Projects_SupportalCombat_Source_SupportalCombat_SupportalCombatGameMode_h__Script_SupportalCombat_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASupportalCombatGameMode, ASupportalCombatGameMode::StaticClass, TEXT("ASupportalCombatGameMode"), &Z_Registration_Info_UClass_ASupportalCombatGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASupportalCombatGameMode), 915822627U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_linco_OneDrive_Documents_Unreal_Projects_SupportalCombat_Source_SupportalCombat_SupportalCombatGameMode_h__Script_SupportalCombat_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_linco_OneDrive_Documents_Unreal_Projects_SupportalCombat_Source_SupportalCombat_SupportalCombatGameMode_h__Script_SupportalCombat_2332210268{
	TEXT("/Script/SupportalCombat"),
	Z_CompiledInDeferFile_FID_Users_linco_OneDrive_Documents_Unreal_Projects_SupportalCombat_Source_SupportalCombat_SupportalCombatGameMode_h__Script_SupportalCombat_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_linco_OneDrive_Documents_Unreal_Projects_SupportalCombat_Source_SupportalCombat_SupportalCombatGameMode_h__Script_SupportalCombat_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
