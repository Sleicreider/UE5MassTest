// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VertexAnimToolset/Public/VertexAnimProfile.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVertexAnimProfile() {}
// Cross Module References
	VERTEXANIMTOOLSET_API UScriptStruct* Z_Construct_UScriptStruct_FVASequenceData();
	UPackage* Z_Construct_UPackage__Script_VertexAnimToolset();
	ENGINE_API UClass* Z_Construct_UClass_UAnimationAsset_NoRegister();
	VERTEXANIMTOOLSET_API UClass* Z_Construct_UClass_UVertexAnimProfile_NoRegister();
	VERTEXANIMTOOLSET_API UClass* Z_Construct_UClass_UVertexAnimProfile();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VASequenceData;
class UScriptStruct* FVASequenceData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VASequenceData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VASequenceData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVASequenceData, Z_Construct_UPackage__Script_VertexAnimToolset(), TEXT("VASequenceData"));
	}
	return Z_Registration_Info_UScriptStruct_VASequenceData.OuterSingleton;
}
template<> VERTEXANIMTOOLSET_API UScriptStruct* StaticStruct<FVASequenceData>()
{
	return FVASequenceData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVASequenceData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SequenceRef_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SequenceRef;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumFrames_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumFrames;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnimStart_Generated_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_AnimStart_Generated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Speed_Generated_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Speed_Generated;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVASequenceData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Struct Holding helper data specific to an Animation Sequence needed for the baking process\n" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
		{ "ToolTip", "Struct Holding helper data specific to an Animation Sequence needed for the baking process" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVASequenceData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVASequenceData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_SequenceRef_MetaData[] = {
		{ "Category", "BakeSequence" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_SequenceRef = { "SequenceRef", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVASequenceData, SequenceRef), Z_Construct_UClass_UAnimationAsset_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_SequenceRef_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_SequenceRef_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_NumFrames_MetaData[] = {
		{ "Category", "BakeSequence" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_NumFrames = { "NumFrames", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVASequenceData, NumFrames), METADATA_PARAMS(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_NumFrames_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_NumFrames_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_AnimStart_Generated_MetaData[] = {
		{ "Category", "BakeSequenceGenerated" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_AnimStart_Generated = { "AnimStart_Generated", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVASequenceData, AnimStart_Generated), METADATA_PARAMS(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_AnimStart_Generated_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_AnimStart_Generated_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_Speed_Generated_MetaData[] = {
		{ "Category", "BakeSequenceGenerated" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_Speed_Generated = { "Speed_Generated", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FVASequenceData, Speed_Generated), METADATA_PARAMS(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_Speed_Generated_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_Speed_Generated_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVASequenceData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_SequenceRef,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_NumFrames,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_AnimStart_Generated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVASequenceData_Statics::NewProp_Speed_Generated,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVASequenceData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VertexAnimToolset,
		nullptr,
		&NewStructOps,
		"VASequenceData",
		sizeof(FVASequenceData),
		alignof(FVASequenceData),
		Z_Construct_UScriptStruct_FVASequenceData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVASequenceData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FVASequenceData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVASequenceData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FVASequenceData()
	{
		if (!Z_Registration_Info_UScriptStruct_VASequenceData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VASequenceData.InnerSingleton, Z_Construct_UScriptStruct_FVASequenceData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VASequenceData.InnerSingleton;
	}
	void UVertexAnimProfile::StaticRegisterNativesUVertexAnimProfile()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVertexAnimProfile);
	UClass* Z_Construct_UClass_UVertexAnimProfile_NoRegister()
	{
		return UVertexAnimProfile::StaticClass();
	}
	struct Z_Construct_UClass_UVertexAnimProfile_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoSize_MetaData[];
#endif
		static void NewProp_AutoSize_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxWidth_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UVMergeDuplicateVerts_MetaData[];
#endif
		static void NewProp_UVMergeDuplicateVerts_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_UVMergeDuplicateVerts;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverrideSize_Vert_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OverrideSize_Vert;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Anims_Vert_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anims_Vert_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Anims_Vert;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FullBoneSkinning_MetaData[];
#endif
		static void NewProp_FullBoneSkinning_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_FullBoneSkinning;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverrideSize_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OverrideSize_Bone;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Anims_Bone_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Anims_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Anims_Bone;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UVChannel_VertAnim_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_UVChannel_VertAnim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OffsetsTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OffsetsTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NormalsTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NormalsTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RowsPerFrame_Vert_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_RowsPerFrame_Vert;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxValueOffset_Vert_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValueOffset_Vert;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UVChannel_BoneAnim_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_UVChannel_BoneAnim;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UVChannel_BoneAnim_Full_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_UVChannel_BoneAnim_Full;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BonePosTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BonePosTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BoneRotTexture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BoneRotTexture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxValuePosition_Bone_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxValuePosition_Bone;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVertexAnimProfile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_VertexAnimToolset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Data asset holding all the helper data needed for the baking process\n" },
		{ "IncludePath", "VertexAnimProfile.h" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
		{ "ToolTip", "Data asset holding all the helper data needed for the baking process" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize_MetaData[] = {
		{ "Category", "AnimProfile" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	void Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize_SetBit(void* Obj)
	{
		((UVertexAnimProfile*)Obj)->AutoSize = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize = { "AutoSize", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UVertexAnimProfile), &Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxWidth_MetaData[] = {
		{ "Category", "AnimProfile" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxWidth = { "MaxWidth", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, MaxWidth), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxWidth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxWidth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts_MetaData[] = {
		{ "Category", "VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	void Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts_SetBit(void* Obj)
	{
		((UVertexAnimProfile*)Obj)->UVMergeDuplicateVerts = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts = { "UVMergeDuplicateVerts", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UVertexAnimProfile), &Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Vert_MetaData[] = {
		{ "Category", "VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Vert = { "OverrideSize_Vert", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, OverrideSize_Vert), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Vert_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Vert_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert_Inner = { "Anims_Vert", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVASequenceData, METADATA_PARAMS(nullptr, 0) }; // 636530986
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert_MetaData[] = {
		{ "Category", "VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert = { "Anims_Vert", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, Anims_Vert), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert_MetaData)) }; // 636530986
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning_MetaData[] = {
		{ "Category", "BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	void Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning_SetBit(void* Obj)
	{
		((UVertexAnimProfile*)Obj)->FullBoneSkinning = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning = { "FullBoneSkinning", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(UVertexAnimProfile), &Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning_SetBit, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Bone_MetaData[] = {
		{ "Category", "BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Bone = { "OverrideSize_Bone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, OverrideSize_Bone), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Bone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Bone_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone_Inner = { "Anims_Bone", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVASequenceData, METADATA_PARAMS(nullptr, 0) }; // 636530986
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone_MetaData[] = {
		{ "Category", "BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone = { "Anims_Bone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, Anims_Bone), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone_MetaData)) }; // 636530986
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "AnimProfileGenerated" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, StaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_StaticMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_StaticMesh_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_VertAnim_MetaData[] = {
		{ "Category", "Generated_VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_VertAnim = { "UVChannel_VertAnim", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, UVChannel_VertAnim), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_VertAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_VertAnim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OffsetsTexture_MetaData[] = {
		{ "Category", "Generated_VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OffsetsTexture = { "OffsetsTexture", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, OffsetsTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OffsetsTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OffsetsTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_NormalsTexture_MetaData[] = {
		{ "Category", "Generated_VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_NormalsTexture = { "NormalsTexture", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, NormalsTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_NormalsTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_NormalsTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_RowsPerFrame_Vert_MetaData[] = {
		{ "Category", "Generated_VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_RowsPerFrame_Vert = { "RowsPerFrame_Vert", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, RowsPerFrame_Vert), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_RowsPerFrame_Vert_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_RowsPerFrame_Vert_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValueOffset_Vert_MetaData[] = {
		{ "Category", "Generated_VertAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValueOffset_Vert = { "MaxValueOffset_Vert", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, MaxValueOffset_Vert), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValueOffset_Vert_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValueOffset_Vert_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_MetaData[] = {
		{ "Category", "Generated_BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim = { "UVChannel_BoneAnim", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, UVChannel_BoneAnim), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_Full_MetaData[] = {
		{ "Category", "Generated_BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_Full = { "UVChannel_BoneAnim_Full", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, UVChannel_BoneAnim_Full), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_Full_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_Full_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BonePosTexture_MetaData[] = {
		{ "Category", "Generated_BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BonePosTexture = { "BonePosTexture", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, BonePosTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BonePosTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BonePosTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BoneRotTexture_MetaData[] = {
		{ "Category", "Generated_BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BoneRotTexture = { "BoneRotTexture", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, BoneRotTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BoneRotTexture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BoneRotTexture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValuePosition_Bone_MetaData[] = {
		{ "Category", "Generated_BoneAnim" },
		{ "ModuleRelativePath", "Public/VertexAnimProfile.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValuePosition_Bone = { "MaxValuePosition_Bone", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UVertexAnimProfile, MaxValuePosition_Bone), METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValuePosition_Bone_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValuePosition_Bone_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVertexAnimProfile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_AutoSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVMergeDuplicateVerts,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Vert,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Vert,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_FullBoneSkinning,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OverrideSize_Bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_Anims_Bone,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_StaticMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_VertAnim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_OffsetsTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_NormalsTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_RowsPerFrame_Vert,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValueOffset_Vert,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_UVChannel_BoneAnim_Full,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BonePosTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_BoneRotTexture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVertexAnimProfile_Statics::NewProp_MaxValuePosition_Bone,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVertexAnimProfile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVertexAnimProfile>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVertexAnimProfile_Statics::ClassParams = {
		&UVertexAnimProfile::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UVertexAnimProfile_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UVertexAnimProfile_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UVertexAnimProfile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UVertexAnimProfile()
	{
		if (!Z_Registration_Info_UClass_UVertexAnimProfile.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVertexAnimProfile.OuterSingleton, Z_Construct_UClass_UVertexAnimProfile_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVertexAnimProfile.OuterSingleton;
	}
	template<> VERTEXANIMTOOLSET_API UClass* StaticClass<UVertexAnimProfile>()
	{
		return UVertexAnimProfile::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVertexAnimProfile);
	struct Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics::ScriptStructInfo[] = {
		{ FVASequenceData::StaticStruct, Z_Construct_UScriptStruct_FVASequenceData_Statics::NewStructOps, TEXT("VASequenceData"), &Z_Registration_Info_UScriptStruct_VASequenceData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVASequenceData), 636530986U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVertexAnimProfile, UVertexAnimProfile::StaticClass, TEXT("UVertexAnimProfile"), &Z_Registration_Info_UClass_UVertexAnimProfile, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVertexAnimProfile), 2317723460U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_3599631510(TEXT("/Script/VertexAnimToolset"),
		Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MassTest_Plugins_VertexAnimToolset_Source_VertexAnimToolset_Public_VertexAnimProfile_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
