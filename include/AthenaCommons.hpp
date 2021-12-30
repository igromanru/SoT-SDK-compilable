#pragma once

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "SoT_Basic.hpp"
#include "SoT_CoreUObject_classes.hpp"
#include "SoT_Athena_enums.hpp"
#include "SoT_ObjectMessaging_structs.hpp"
#include "SoT_Maths_structs.hpp"
#include "SoT_AthenaInputMkII_classes.hpp"

namespace SDK
{

// Class Tales.TaleQuestStep
// 0x0068 (0x0090 - 0x0028)
class UTaleQuestStep : public UObject
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x0028(0x0058) MISSED OFFSET
	class UTaleQuestStepDesc*                          TaleStepDesc;                                             // 0x0080(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x0088(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Tales.TaleQuestStep"));
		return ptr;
	}


	void Signal();
};

// Class Tales.TaleQuestStepDesc
// 0x0058 (0x0080 - 0x0028)
class UTaleQuestStepDesc : public UObject
{
public:
	bool                                               Fork;                                                     // 0x0028(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET
	TMap<struct FName, struct FQuestVariableAny>       PromotedPropertyVariables;                                // 0x0030(0x0050) (Edit, ZeroConstructor, EditConst)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Tales.TaleQuestStepDesc"));
		return ptr;
	}

};

// Class Tales.TaleQuestService
// 0x0038 (0x0060 - 0x0028)
class UTaleQuestService : public UObject
{
public:
	unsigned char                                      UnknownData00[0x38];                                      // 0x0028(0x0038) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Tales.TaleQuestService"));
		return ptr;
	}

};

// Class Tales.TaleQuestServiceDesc
// 0x0000 (0x0028 - 0x0028)
class UTaleQuestServiceDesc : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Tales.TaleQuestServiceDesc"));
		return ptr;
	}

};

// ScriptStruct Athena.ItemLoadoutCapacity
// 0x0010
struct FItemLoadoutCapacity
{
	class UClass*                                      ItemCategory;                                             // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	int                                                Capacity;                                                 // 0x0008(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
};

// ScriptStruct Athena.ItemLoadout
// 0x0020
struct FItemLoadout
{
	TArray<struct FItemLoadoutCapacity>                Capacities;                                               // 0x0000(0x0010) (Edit, ZeroConstructor)
	TArray<class UClass*>                              Items;                                                    // 0x0010(0x0010) (Edit, ZeroConstructor)
};

// ScriptStruct Athena.StartPickupObjectActionRuleParams
// 0x0010
struct FStartPickupObjectActionRuleParams
{
	TArray<TEnumAsByte<EWieldableItemSize>>            WieldableItemSizesDisablePickup;                          // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Athena.DetailAppearenceDesc
// 0x0030
struct FDetailAppearenceDesc
{
	struct FStringAssetReference                       Mesh;                                                     // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<struct FDetailAppearenceMaterialDesc>       Materials;                                                // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	struct FStringAssetReference                       CustomDepthMaterial;                                      // 0x0020(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
};

// ScriptStruct Athena.BaseLightData
// 0x0080
struct FBaseLightData
{
	float                                              Intensity;                                                // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FColor                                      LightColor;                                               // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bAffectsWorld : 1;                                        // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      CastShadows : 1;                                          // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      CastStaticShadows : 1;                                    // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      CastDynamicShadows : 1;                                   // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      bAffectTranslucentLighting : 1;                           // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      bPrecomputedLightingIsValid : 1;                          // 0x0008(0x0001)
	unsigned char                                      RainOcclusion : 1;                                        // 0x0008(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0009(0x0003) MISSED OFFSET
	float                                              IndirectLightingIntensity;                                // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ScaleForTranslucency;                                     // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              CapForTranslucency;                                       // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              Temperature;                                              // 0x0018(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bUseTemperature : 1;                                      // 0x001C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData01[0x3];                                       // 0x001D(0x0003) MISSED OFFSET
	float                                              MinRoughness;                                             // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ShadowBias;                                               // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ShadowSharpen;                                            // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              ShadowResMaxDynamicDegradation;                           // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      CastTranslucentShadows : 1;                               // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      bCastShadowsFromCinematicObjectsOnly : 1;                 // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      bAffectDynamicIndirectLighting : 1;                       // 0x0030(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
	class UMaterialInterface*                          LightFunctionMaterial;                                    // 0x0038(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FVector                                     LightFunctionScale;                                       // 0x0040(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x004C(0x0004) MISSED OFFSET
	class UTextureLightProfile*                        IESTexture;                                               // 0x0050(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bUseIESBrightness : 1;                                    // 0x0058(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData04[0x3];                                       // 0x0059(0x0003) MISSED OFFSET
	float                                              IESBrightnessScale;                                       // 0x005C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              LightFunctionFadeDistance;                                // 0x0060(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              DisabledBrightness;                                       // 0x0064(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bEnableLightShaftBloom : 1;                               // 0x0068(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData05[0x3];                                       // 0x0069(0x0003) MISSED OFFSET
	float                                              BloomScale;                                               // 0x006C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              BloomThreshold;                                           // 0x0070(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FColor                                      BloomTint;                                                // 0x0074(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               bUseRayTracedDistanceFieldShadows;                        // 0x0078(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x3];                                       // 0x0079(0x0003) MISSED OFFSET
	float                                              RayStartOffsetDepthScale;                                 // 0x007C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.PointLightData
// 0x003C
struct FPointLightData
{
	float                                              AttenuationRadius;                                        // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      bUseInverseSquaredFalloff : 1;                            // 0x0004(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0005(0x0003) MISSED OFFSET
	float                                              LightFalloffExponent;                                     // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              IntensityScaleForWater;                                   // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MinDistanceToLightAssumed;                                // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              SourceRadius;                                             // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              SourceLength;                                             // 0x0018(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ESimpleLightFunctionType>              SimpleFunctionType;                                       // 0x001C(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x001D(0x0003) MISSED OFFSET
	float                                              ScaleOffset;                                              // 0x0020(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              PulsePhase;                                               // 0x0024(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              FlickerFrequency;                                         // 0x0028(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	int                                                FlickerPerlinRow;                                         // 0x002C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	struct FLightmassPointLightSettings                LightmassSettings;                                        // 0x0030(0x000C) (Edit, BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct Athena.SpotLightData
// 0x000C
struct FSpotLightData
{
	float                                              InnerConeAngle;                                           // 0x0000(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              OuterConeAngle;                                           // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              KickBackRatio;                                            // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.GenericLightTemplate
// 0x00D0
struct FGenericLightTemplate
{
	TEnumAsByte<ELightTemplateType>                    LightType;                                                // 0x0000(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0001(0x0007) MISSED OFFSET
	struct FBaseLightData                              BaseLightData;                                            // 0x0008(0x0080) (Edit)
	struct FPointLightData                             PointLightData;                                           // 0x0088(0x003C) (Edit)
	struct FSpotLightData                              SpotLightData;                                            // 0x00C4(0x000C) (Edit)
};

// ScriptStruct Athena.ImpactDamageEvent
// 0x0058
struct FImpactDamageEvent
{
	struct FGuid                                       AttackId;                                                 // 0x0000(0x0010) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	class UClass*                                      DamagerType;                                              // 0x0010(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class AActor*                                      DirectInstigator;                                         // 0x0018(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class AActor*                                      RootInstigator;                                           // 0x0020(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     Location;                                                 // 0x0028(0x000C) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     SurfaceNormal;                                            // 0x0034(0x000C) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FVector                                     Velocity;                                                 // 0x0040(0x000C) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DamageAmount;                                             // 0x004C(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	int                                                DamageSpread;                                             // 0x0050(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EHealthChangedReason>                  Reason;                                                   // 0x0054(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               DealFriendlyFireDamage;                                   // 0x0055(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0056(0x0002) MISSED OFFSET
};

// ScriptStruct Athena.EncounterParams
// 0x000C
struct FEncounterParams
{
	TEnumAsByte<EEncounterType>                        EncounterType;                                            // 0x0000(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0001(0x0003) MISSED OFFSET
	float                                              EncounterRadius;                                          // 0x0004(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EEncounterDimensions>                  EncounterDimensions;                                      // 0x0008(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EEncounterMobility>                    EncounterMobility;                                        // 0x0009(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x000A(0x0002) MISSED OFFSET
};

// ScriptStruct Athena.TelemetryFragmentInput
// 0x0001
struct FTelemetryFragmentInput
{
	unsigned char                                      UnknownData00[0x1];                                       // 0x0000(0x0001) MISSED OFFSET
};

// ScriptStruct Athena.WeightedPetAnimationSelector
// 0x00A0
struct FWeightedPetAnimationSelector
{
	TArray<struct FPetAnimationWeighting>              Weightings;                                               // 0x0000(0x0010) (Edit, ZeroConstructor)
	unsigned char                                      UnknownData00[0x90];                                      // 0x0010(0x0090) MISSED OFFSET
};

// ScriptStruct Athena.PlayerStat
// 0x0004
struct FPlayerStat
{
	uint32_t                                           StatId;                                                   // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.PetAnimationDataPreview
// 0x0010
struct FPetAnimationDataPreview
{
	struct FStringAssetReference                       MontageData;                                              // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Athena.RewardId
// 0x0008
struct FRewardId
{
	struct FName                                       RewardId;                                                 // 0x0000(0x0008) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.QuestDesc
// 0x0028
struct FQuestDesc
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	class FString                                      Title;                                                    // 0x0008(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
	bool                                               IsEmergent;                                               // 0x0018(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
	struct FName                                       IslandName;                                               // 0x001C(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Athena.DamageInstance
// 0x0028
struct FDamageInstance
{
	struct FGuid                                       AttackId;                                                 // 0x0000(0x0010) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      DirectInstigator;                                         // 0x0010(0x0008) (ZeroConstructor, IsPlainOldData)
	class AActor*                                      RootInstigator;                                           // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              Amount;                                                   // 0x0020(0x0004) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EHealthChangedReason>                  Reason;                                                   // 0x0024(0x0001) (BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
};

// ScriptStruct Athena.LookAtOffsetParams
// 0x001C
struct FLookAtOffsetParams
{
	bool                                               UseLookAtPosition;                                        // 0x0000(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	bool                                               UseSpring;                                                // 0x0001(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x0002(0x0002) MISSED OFFSET
	float                                              SpringAccel;                                              // 0x0004(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MinYaw;                                                   // 0x0008(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MaxYaw;                                                   // 0x000C(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MinPitch;                                                 // 0x0010(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	float                                              MaxPitch;                                                 // 0x0014(0x0004) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ECameraLookatAnimationType>            CameraLookatAnimationType;                                // 0x0018(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0019(0x0003) MISSED OFFSET
};

// ScriptStruct Athena.ItemMetaBase
// 0x0018
struct FItemMetaBase
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	struct FStringAssetReference                       StoredStructType;                                         // 0x0008(0x0010) (ZeroConstructor)
};

// ScriptStruct Athena.PirateIdentity
// 0x0078
struct FPirateIdentity
{
	struct FUniqueNetIdRepl                            UserId;                                                   // 0x0000(0x0018)
	class FString                                      PirateId;                                                 // 0x0018(0x0010) (ZeroConstructor)
	TMap<class FString, class FString>                 Claims;                                                   // 0x0028(0x0050) (ZeroConstructor, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
};

// ScriptStruct Athena.PlayerBaseTelemetryFragment
// 0x0048
struct FPlayerBaseTelemetryFragment
{
	struct FGuid                                       PlayerGameId;                                             // 0x0000(0x0010) (ZeroConstructor, IsPlainOldData)
	class FString                                      UserId;                                                   // 0x0010(0x0010) (ZeroConstructor)
	class FString                                      PirateId;                                                 // 0x0020(0x0010) (ZeroConstructor)
	unsigned char                                      PlatformId;                                               // 0x0030(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0031(0x0007) MISSED OFFSET
	class FString                                      DeviceID;                                                 // 0x0038(0x0010) (ZeroConstructor)
};

// ScriptStruct Athena.VFXHandlerComponentParams
// 0x0040
struct FVFXHandlerComponentParams
{
	class UParticleSystem*                             ParticleSystem;                                           // 0x0000(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FVector                                     VFXRelativeOffset;                                        // 0x0008(0x000C) (Edit, ZeroConstructor, IsPlainOldData)
	struct FVector                                     VFXScale;                                                 // 0x0014(0x000C) (Edit, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    VFXRotationOffset;                                        // 0x0020(0x000C) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       VFXAttachSocket;                                          // 0x002C(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              VFXDrivingCurveValue;                                     // 0x0034(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EVfxCustomLocalSpaceMode>              VFXCustomLocalSpaceMode;                                  // 0x0038(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0039(0x0007) MISSED OFFSET
};

// ScriptStruct Athena.KnockBackInfo
// 0x0050
struct FKnockBackInfo
{
	struct FName                                       FeatureName;                                              // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              HorizontalVelocity;                                       // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              VerticalVelocity;                                         // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MinHorizontalVelocity;                                    // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              MinVerticalVelocity;                                      // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SwimmingVelocity;                                         // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DockedHorizontalVelocity;                                 // 0x001C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DockedVerticalVelocity;                                   // 0x0020(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               UseDockedVelocitiesWhenDocked;                            // 0x0024(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0025(0x0003) MISSED OFFSET
	struct FName                                       RumbleTag;                                                // 0x0028(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              StunDuration;                                             // 0x0030(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AIKnockbackDistance;                                      // 0x0034(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AIKnockbackSpeed;                                         // 0x0038(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AIKnockbackAcceleration;                                  // 0x003C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EAIKnockbackStrengthType>              AIKnockbackStrengthType;                                  // 0x0040(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               UseOverrideLaunchDirection;                               // 0x0041(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x2];                                       // 0x0042(0x0002) MISSED OFFSET
	struct FVector                                     OverrideLaunchDirectionInWorldSpace;                      // 0x0044(0x000C) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.RandomParticleSystemPicker
// 0x0010
struct FRandomParticleSystemPicker
{
	TArray<struct FRandomParticleSystemPickerEntry>    Effects;                                                  // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Athena.DistanceThrottledRandomParticleSystemPicker
// 0x0010
struct FDistanceThrottledRandomParticleSystemPicker
{
	TArray<struct FDistanceThrottledRandomParticleSystemPickerEntry> Entries;                                                  // 0x0000(0x0010) (Edit, BlueprintVisible, ZeroConstructor)
};

// ScriptStruct Athena.TreasureMapWidget
// 0x0018
struct FTreasureMapWidget
{
	struct FVector2D                                   Position;                                                 // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETreasureMapHorizontalAlignment>       HorizontalAlignment;                                      // 0x0008(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETreasureMapVerticalAlignment>         VerticalAlignment;                                        // 0x0009(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x2];                                       // 0x000A(0x0002) MISSED OFFSET
	float                                              Angle;                                                    // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Width;                                                    // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              Opacity;                                                  // 0x0014(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.TreasureMapWidgetStreamedTexture
// 0x0018 (0x0030 - 0x0018)
struct FTreasureMapWidgetStreamedTexture : public FTreasureMapWidget
{
	struct FStringAssetReference                       TexturePath;                                              // 0x0018(0x0010) (Edit, ZeroConstructor)
	float                                              RelativeHeightModifier;                                   // 0x0028(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               FlipX;                                                    // 0x002C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x002D(0x0003) MISSED OFFSET
};

// ScriptStruct Athena.TreasureMapWidgetText
// 0x0008 (0x0020 - 0x0018)
struct FTreasureMapWidgetText : public FTreasureMapWidget
{
	float                                              Scale;                                                    // 0x0018(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               CutoutTextStyle;                                          // 0x001C(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x001D(0x0003) MISSED OFFSET
};

// ScriptStruct Athena.QuestVariable
// 0x0010
struct FQuestVariable
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	struct FName                                       ParamName;                                                // 0x0008(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.QuestVariableActor
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableActor : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableAsset
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableAsset : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableClass
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableClass : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableGuid
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableGuid : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariablePlayerActor
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariablePlayerActor : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableVector
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableVector : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableNameArray
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableNameArray : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableName
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableName : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableContestIslandArchetype
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableContestIslandArchetype : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableInt
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableInt : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariablePageBundle
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariablePageBundle : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableDataAsset
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableDataAsset : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableText
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableText : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableAssetArray
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableAssetArray : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableAISpawner
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableAISpawner : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableAIDioramaDesc
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableAIDioramaDesc : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableBool
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableBool : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableAISpawnerArray
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableAISpawnerArray : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableUObject
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableUObject : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableVectorArray
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableVectorArray : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableTextArray
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableTextArray : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableFloat
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableFloat : public FQuestVariable
{

};

// ScriptStruct Athena.QuestVariableTransform
// 0x0008 (0x0018 - 0x0010)
struct FQuestVariableTransform : public FQuestVariable
{
	struct FName                                       SocketName;                                               // 0x0010(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct Athena.QuestVariableOrientedPoint
// 0x0000 (0x0010 - 0x0010)
struct FQuestVariableOrientedPoint : public FQuestVariable
{

};

// ScriptStruct AthenaAI.TargetSkillsetProgressionPair
// 0x0020
struct FTargetSkillsetProgressionPair
{
	struct FStringAssetReference                       CrewSkillset;                                             // 0x0000(0x0010) (Edit, ZeroConstructor)
	struct FStringAssetReference                       CaptainSkillset;                                          // 0x0010(0x0010) (Edit, ZeroConstructor)
};

// ScriptStruct AthenaAI.TinySharkParams
// 0x00B8
struct FTinySharkParams
{
	class UClass*                                      TinySharkType;                                            // 0x0000(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TargetRadius;                                             // 0x0008(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FVector                                     SpawnOffset;                                              // 0x000C(0x000C) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TAssetPtr<class UClass>                            TinySharkAIType;                                          // 0x0018(0x0020) (Edit, DisableEditOnInstance)
	TAssetPtr<class UAthenaAIControllerParamsDataAsset> TinySharkSkillset;                                        // 0x0038(0x0020) (Edit, DisableEditOnInstance)
	TAssetPtr<class ULoadoutAsset>                     TinySharkLoadout;                                         // 0x0058(0x0020) (Edit, DisableEditOnInstance)
	class UClass*                                      TinySharkClassID;                                         // 0x0078(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FWeightedProbabilityRangeOfRanges           LifetimeTimeout;                                          // 0x0080(0x0030) (Edit, DisableEditOnInstance)
	float                                              TrackedShipDistanceThreshold;                             // 0x00B0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RepositionTime;                                           // 0x00B4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
};

// Class AthenaAI.TinySharkExperience
// 0x03A0 (0x0770 - 0x03D0)
class ATinySharkExperience : public AActor
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x03D0(0x0008) MISSED OFFSET
	float                                              RelevancyDistance;                                        // 0x03D8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              TrackingMovementCheckInterval;                            // 0x03DC(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UEnvQuery*                                   TrackingMovementValidQuery;                               // 0x03E0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0xA0];                                      // 0x03E8(0x00A0) MISSED OFFSET
	class UAIOnDemandSpawner*                          TinySharkSpawner;                                         // 0x0488(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class ASharkPawn*                                  TinySharkPawn;                                            // 0x0490(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	struct FName                                       HealthRTPC;                                               // 0x0498(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x04A0(0x0008) MISSED OFFSET
	struct FTinySharkParams                            Params;                                                   // 0x04A8(0x00B8) (Transient)
	class UTinySharkTelemetryComponent*                TinySharkTelemetryComponent;                              // 0x0560(0x0008) (Edit, BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class AShip*                                       TrackedShip;                                              // 0x0568(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x80];                                      // 0x0570(0x0080) MISSED OFFSET
	struct FEncounterParams                            SightingEncounterParams;                                  // 0x05F0(0x000C) (Edit, DisableEditOnInstance)
	struct FEncounterParams                            CloseEncounterParams;                                     // 0x05FC(0x000C) (Edit, DisableEditOnInstance)
	unsigned char                                      UnknownData04[0x140];                                     // 0x0608(0x0140) MISSED OFFSET
	TAssetPtr<class UAthenaAIControllerParamsDataAsset> CachedControllerParamsAsset;                              // 0x0748(0x0020)
	unsigned char                                      UnknownData05[0x8];                                       // 0x0768(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class AthenaAI.TinySharkExperience"));
		return ptr;
	}


	void TinySharkPawnDestroyed(class AActor* InDestroyedActor);
	void OnRep_TinySharkPawn(class ASharkPawn* LastTinySharkPawn);
	class AShip* GetTrackedShip();
	TEnumAsByte<ETinySharkState> GetCurrentState();
	TEnumAsByte<ETinySharkActiveState> GetActiveState();
};

// Class AthenaAI.AthenaAIFormComponent
// 0x0070 (0x0138 - 0x00C8)
class UAthenaAIFormComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x00C8(0x0008) MISSED OFFSET
	TArray<struct FAthenaAIFormComponentVfxCustomisation> VfxCustomisations;                                        // 0x00D0(0x0010) (Edit, ZeroConstructor)
	class UAthenaAIFormDataAsset*                      FormData;                                                 // 0x00E0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UCharacterHitReactionDamagerTypeToAnimTypeLayer* HitReactionsLayer;                                        // 0x00E8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x48];                                      // 0x00F0(0x0048) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class AthenaAI.AthenaAIFormComponent"));
		return ptr;
	}


	void OnRep_FormData();
};

// Class Athena.MetalAIFormComponent
// 0x00C0 (0x01F8 - 0x0138)
class UMetalAIFormComponent : public UAthenaAIFormComponent
{
public:
	unsigned char                                      UnknownData00[0x28];                                      // 0x0138(0x0028) MISSED OFFSET
	class UParticleSystem*                             RustyParticlesTemplate;                                   // 0x0160(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletonAudioFootfallControllerParams*      DefaultFootfallParams;                                    // 0x0168(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USkeletonAudioFootfallControllerParams*      RustyFootfallParams;                                      // 0x0170(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TAssetPtr<class UMaterial>                         MetalBaseMaterial;                                        // 0x0178(0x0020) (Edit, DisableEditOnInstance)
	struct FName                                       RustShaderParamName;                                      // 0x0198(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              NotRustyShaderParamValue;                                 // 0x01A0(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RustyShaderParamValue;                                    // 0x01A4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ShaderParamBlendSpeed;                                    // 0x01A8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SeedShaderParamName;                                      // 0x01AC(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxSeedShaderValue;                                       // 0x01B4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               IsWet;                                                    // 0x01B8(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x01B9(0x0007) MISSED OFFSET
	class UParticleSystemComponent*                    RustyParticleSystemComponent;                             // 0x01C0(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x01C8(0x0008) MISSED OFFSET
	class UDamageableVulnerabilityLayer*               DefaultVulnerabilityLayer;                                // 0x01D0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UDamageableVulnerabilityLayer*               RustyVulnerabilityLayer;                                  // 0x01D8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UCharacterHitReactionDamagerTypeToAnimTypeLayer* RustyHitReactionsLayer;                                   // 0x01E0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UMaterialInstanceDynamic*                    MetalDynamicMaterialInstance;                             // 0x01E8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x01F0(0x0008) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.MetalAIFormComponent"));
		return ptr;
	}


	void OnRep_IsWet();
};

// Class Athena.EntitlementDesc
// 0x00B0 (0x00D8 - 0x0028)
class UEntitlementDesc : public UDataAsset
{
public:
	struct FText                                       Title;                                                    // 0x0028(0x0038) (Edit, DisableEditOnInstance)
	struct FText                                       Description;                                              // 0x0060(0x0038) (Edit, DisableEditOnInstance)
	struct FStringAssetReference                       IconPath;                                                 // 0x0098(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FStringAssetReference                       IconInvPath;                                              // 0x00A8(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FStringAssetReference                       IconPrvPath;                                              // 0x00B8(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	class UClass*                                      Category;                                                 // 0x00C8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      Company;                                                  // 0x00D0(0x0008) (Edit, ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.EntitlementDesc"));
		return ptr;
	}

};

// Class Athena.RadialContextBase
// 0x0000 (0x0028 - 0x0028)
class URadialContextBase : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.RadialContextBase"));
		return ptr;
	}

};

// Class Athena.ItemDesc
// 0x0058 (0x0130 - 0x00D8)
class UItemDesc : public UEntitlementDesc
{
public:
	unsigned char                                      CanBeAddedToLoadout : 1;                                  // 0x00D8(0x0001) (Edit, DisableEditOnInstance)
	unsigned char                                      IsTransient : 1;                                          // 0x00D8(0x0001) (Edit, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00D9(0x0007) MISSED OFFSET
	class FString                                      PreviousItem;                                             // 0x00E0(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	class FString                                      NextItem;                                                 // 0x00F0(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FStringAssetReference                       IconRadPath;                                              // 0x0100(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FStringClassReference                       InstanceClassType;                                        // 0x0110(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	TArray<struct FItemInfoTogglePair>                 ItemInfoOverrides;                                        // 0x0120(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemDesc"));
		return ptr;
	}

};

// Class Athena.ItemWithoutIconsDesc
// 0x0000 (0x0130 - 0x0130)
class UItemWithoutIconsDesc : public UItemDesc
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemWithoutIconsDesc"));
		return ptr;
	}

};

// Class Athena.BootyItemDesc
// 0x0000 (0x0130 - 0x0130)
class UBootyItemDesc : public UItemWithoutIconsDesc
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.BootyItemDesc"));
		return ptr;
	}

};

// Class Athena.CategoryBase
// 0x0050 (0x0078 - 0x0028)
class UCategoryBase : public UObject
{
public:
	struct FText                                       Name;                                                     // 0x0028(0x0038) (Edit, DisableEditOnInstance)
	struct FName                                       UniqueTextIdentifier;                                     // 0x0060(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FStringAssetReference                       IconPath;                                                 // 0x0068(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.CategoryBase"));
		return ptr;
	}

};

// Class Athena.ItemCategory
// 0x0008 (0x0080 - 0x0078)
class UItemCategory : public UCategoryBase
{
public:
	class UClass*                                      NotificationInputId;                                      // 0x0078(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemCategory"));
		return ptr;
	}

};

// Class Athena.ItemInfo
// 0x0130 (0x0500 - 0x03D0)
class AItemInfo : public AActor
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x03D0(0x0020) MISSED OFFSET
	bool                                               CanBeStoredInInventory;                                   // 0x03F0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x03F1(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnItemPickedUpDelegate;                                   // 0x03F8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	struct FScriptMulticastDelegate                    OnItemDroppedDeletage;                                    // 0x0408(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UClass*                                      WieldableType;                                            // 0x0418(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      ProxyType;                                                // 0x0420(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UWieldableItemPersistentCooldownComponent*   WieldableItemPersistenceCooldownComponent;                // 0x0428(0x0008) (Edit, ExportObject, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UItemDesc*                                   Desc;                                                     // 0x0430(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EItemRepresentation>                   CurrentRepresentation;                                    // 0x0438(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0439(0x0007) MISSED OFFSET
	class AActor*                                      CurrentRepresentationInstance;                            // 0x0440(0x0008) (Edit, Net, ZeroConstructor, EditConst, IsPlainOldData)
	class AActor*                                      CurrentOwner;                                             // 0x0448(0x0008) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	class AActor*                                      TutorialOwner;                                            // 0x0450(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xA1];                                      // 0x0458(0x00A1) MISSED OFFSET
	bool                                               DoNotConsiderForMigrationGather;                          // 0x04F9(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x6];                                       // 0x04FA(0x0006) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemInfo"));
		return ptr;
	}


	void SwitchNetworkClusterToLevel(class ULevel* Level);
	void SwitchNetworkClusterToGlobal();
	void SwitchNetworkClusterToActorOrItsLevel(class AActor* NewOwner);
	void SwitchNetworkClusterTo(class AActor* NewOwner);
	void OnRep_CurrentRepresentationInstance();
	class UClass* GetItemType();
	class UClass* GetItemCategory();
	class AActor* GetItem();
	class AWieldableItem* GetAsWieldable();
	class AWieldableItem* CreateWieldableItem(class AActor* InNewOwner, const struct FTransform& InTransform);
	class AActor* CreateProxyItem(const struct FTransform& InTransform, TEnumAsByte<EItemLifetimeManagement> LifetimeManagement);
};

// Class Athena.NonStorableItemInfo
// 0x0000 (0x0500 - 0x0500)
class ANonStorableItemInfo : public AItemInfo
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.NonStorableItemInfo"));
		return ptr;
	}

};

// Class Athena.WieldableItem
// 0x03C0 (0x0790 - 0x03D0)
class AWieldableItem : public AActor
{
public:
	unsigned char                                      UnknownData00[0x58];                                      // 0x03D0(0x0058) MISSED OFFSET
	class UPrimitiveComponent*                         FirstPersonMesh;                                          // 0x0428(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UPrimitiveComponent*                         ThirdPersonMesh;                                          // 0x0430(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UActionRulesComponent*                       ActionRulesComponent;                                     // 0x0438(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UClass*                                      AnimationKey;                                             // 0x0440(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FObjectMessagingDispatcher                  MessagingDispatcher;                                      // 0x0448(0x00A0) (BlueprintVisible)
	unsigned char                                      UnknownData01[0x8];                                       // 0x04E8(0x0008) MISSED OFFSET
	struct FTransform                                  AnimationOffset;                                          // 0x04F0(0x0030) (Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData)
	class UWwiseEvent*                                 EquipSfx;                                                 // 0x0520(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 UnequipSfx;                                               // 0x0528(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 WielderLandedJumpSfx;                                     // 0x0530(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 WielderFootstepLayerOneshot;                              // 0x0538(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerWalkSpeedRtpc;                                      // 0x0540(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 FirstTimeEquipSfx;                                        // 0x0548(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               ForceUnequipSfx;                                          // 0x0550(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TEnumAsByte<EWieldableItemSize>                    ItemSize;                                                 // 0x0551(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x6];                                       // 0x0552(0x0006) MISSED OFFSET
	struct FDetailAppearenceDesc                       DetailAppearence;                                         // 0x0558(0x0030) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	bool                                               PropagateVisibilityToChildren;                            // 0x0588(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x3];                                       // 0x0589(0x0003) MISSED OFFSET
	struct FName                                       AINoiseTag;                                               // 0x058C(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x0594(0x0004) MISSED OFFSET
	TArray<struct FName>                               ThirdPersonExtraMeshNames;                                // 0x0598(0x0010) (Edit, ZeroConstructor)
	TArray<struct FName>                               StashedExtraMeshNames;                                    // 0x05A8(0x0010) (Edit, ZeroConstructor)
	class UMeshComponent*                              StashedMeshComponent;                                     // 0x05B8(0x0008) (Edit, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       StashedMeshAttachSocket;                                  // 0x05C0(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       ServerWieldAttachSocket;                                  // 0x05C8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UPhrasesRadialDataAsset*                     Phrases;                                                  // 0x05D0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UObject*                                     CachedFirstPersonProxyMesh;                               // 0x05D8(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	class UObject*                                     CachedThirdPersonProxyMesh;                               // 0x05E0(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData05[0x128];                                     // 0x05E8(0x0128) MISSED OFFSET
	class UClass*                                      ItemCategory;                                             // 0x0710(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class AItemInfo*                                   ItemInfo;                                                 // 0x0718(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class AInterpolatingItem*                          InterpolatingItem;                                        // 0x0720(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData06[0x18];                                      // 0x0728(0x0018) MISSED OFFSET
	TWeakObjectPtr<class AActor>                       LastKnownWielder;                                         // 0x0740(0x0008) (ZeroConstructor, IsPlainOldData)
	class UWieldableItemVfxComponent*                  WieldableItemVfxComponent;                                // 0x0748(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	TArray<class UMeshComponent*>                      ThirdPersonExtraMeshes;                                   // 0x0750(0x0010) (ExportObject, ZeroConstructor, Transient)
	TArray<class UMeshComponent*>                      StashedExtraMeshes;                                       // 0x0760(0x0010) (ExportObject, ZeroConstructor, Transient)
	unsigned char                                      UnknownData07[0x19];                                      // 0x0770(0x0019) MISSED OFFSET
	bool                                               OfferingEnabled;                                          // 0x0789(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x6];                                       // 0x078A(0x0006) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.WieldableItem"));
		return ptr;
	}


	void SetItemWwiseSwitch(const struct FName& SwitchGroup, const struct FName& SwitchOption);
	void SetItemWwiseRTPC(float Value, struct FName* RTPCName);
	void PostItemWwiseEvent(class UWwiseEvent* Event);
	void OnWielderHasLandedFromJumpBPImpl();
	void OnRep_ItemInfo();
	bool IsUnderwater();
	class AActor* GetWielder();
	struct FTransform GetWieldedItemAnimationOffset();
	TEnumAsByte<EWieldableItemSize> GetWieldableItemSize();
	class AActor* GetLastKnownWielder();
	bool GetIsFirstPerson();
};

// Class Athena.SkeletalMeshWieldableItem
// 0x0000 (0x0790 - 0x0790)
class ASkeletalMeshWieldableItem : public AWieldableItem
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.SkeletalMeshWieldableItem"));
		return ptr;
	}

};

// Class Athena.DamagerType
// 0x0000 (0x0028 - 0x0028)
class UDamagerType : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.DamagerType"));
		return ptr;
	}

};

// Class Athena.NameplateComponent
// 0x0030 (0x02E0 - 0x02B0)
class UNameplateComponent : public USceneComponent
{
public:
	float                                              FadeTime;                                                 // 0x02B0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x02B4(0x0004) MISSED OFFSET
	class USkeletalMeshSocket*                         NameplateSocket;                                          // 0x02B8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x20];                                      // 0x02C0(0x0020) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.NameplateComponent"));
		return ptr;
	}


	struct FVector GetWorldPosition();
};

// Class Athena.ItemSpawnData
// 0x0030 (0x0058 - 0x0028)
class UItemSpawnData : public UObject
{
public:
	unsigned char                                      UnknownData00[0x30];                                      // 0x0028(0x0030) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemSpawnData"));
		return ptr;
	}

};

// Class Athena.PoseableMeshWieldableItem
// 0x0000 (0x0790 - 0x0790)
class APoseableMeshWieldableItem : public AWieldableItem
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.PoseableMeshWieldableItem"));
		return ptr;
	}

};

// Class Athena.TaleQuestToolService
// 0x00C0 (0x0120 - 0x0060)
class UTaleQuestToolService : public UTaleQuestService
{
public:
	class UTaleQuestToolServiceDesc*                   ServiceDesc;                                              // 0x0060(0x0008) (ZeroConstructor, IsPlainOldData)
	TArray<class UItemDesc*>                           WieldableDescs;                                           // 0x0068(0x0010) (ZeroConstructor)
	unsigned char                                      UnknownData00[0xA8];                                      // 0x0078(0x00A8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.TaleQuestToolService"));
		return ptr;
	}


	void RemoveToolsFromAllParticipants();
	void GiveToolsToAllParticipants();
};

// Class Athena.Compass
// 0x00E0 (0x0870 - 0x0790)
class ACompass : public APoseableMeshWieldableItem
{
public:
	class UNamedNotificationInputComponent*            NamedNotificationInputComponent;                          // 0x0790(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	class UUsableWieldableComponent*                   UsableWieldableComponent;                                 // 0x0798(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	class UCompassSpinComponent*                       SpinComponent;                                            // 0x07A0(0x0008) (Edit, ExportObject, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	class UNarratedCompassDirectionComponent*          NarratedCompassDirectionComponent;                        // 0x07A8(0x0008) (Edit, ExportObject, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
	class UPoseableMeshComponent*                      MeshToUse;                                                // 0x07B0(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData00[0xB8];                                      // 0x07B8(0x00B8) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.Compass"));
		return ptr;
	}

};

// Class Athena.TaleQuestToolServiceDesc
// 0x0008 (0x0030 - 0x0028)
class UTaleQuestToolServiceDesc : public UTaleQuestServiceDesc
{
public:
	bool                                               GiveToolsOnStart;                                         // 0x0028(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0029(0x0007) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.TaleQuestToolServiceDesc"));
		return ptr;
	}

};

// Class Athena.ConditionalStatsTriggerType
// 0x0008 (0x0030 - 0x0028)
class UConditionalStatsTriggerType : public UObject
{
public:
	struct FName                                       UniqueTextIdentifier;                                     // 0x0028(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ConditionalStatsTriggerType"));
		return ptr;
	}

};

// Class Athena.StatCondition
// 0x0000 (0x0028 - 0x0028)
class UStatCondition : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.StatCondition"));
		return ptr;
	}

};

// Class Athena.TargetedStatCondition
// 0x0008 (0x0030 - 0x0028)
class UTargetedStatCondition : public UStatCondition
{
public:
	class UStatConditionTargetSelector*                TargetSelector;                                           // 0x0028(0x0008) (Edit, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.TargetedStatCondition"));
		return ptr;
	}

};

// Class Athena.ItemSnapshotMetaGenerator
// 0x0008 (0x0030 - 0x0028)
class UItemSnapshotMetaGenerator : public UObject
{
public:
	class UScriptStruct*                               MetaWrapper;                                              // 0x0028(0x0008) (ZeroConstructor, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemSnapshotMetaGenerator"));
		return ptr;
	}

};

// Class Athena.SpawnRequirement
// 0x0028 (0x0050 - 0x0028)
class USpawnRequirement : public UObject
{
public:
	unsigned char                                      UnknownData00[0x18];                                      // 0x0028(0x0018) MISSED OFFSET
	TArray<class USpawnRequirement*>                   OR_Requirements;                                          // 0x0040(0x0010) (Edit, ExportObject, ZeroConstructor)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.SpawnRequirement"));
		return ptr;
	}

};

// Class Athena.LookAtOffsetInputComponent
// 0x0000 (0x0280 - 0x0280)
class ULookAtOffsetInputComponent : public UAthenaCharacterBaseMovementComponentWithInterference
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.LookAtOffsetInputComponent"));
		return ptr;
	}

};

// ScriptStruct Pets.PetTurnToFaceData
// 0x0020
struct FPetTurnToFaceData
{
	struct FQuat                                       EndRotation;                                              // 0x0000(0x0010) (IsPlainOldData)
	float                                              RotationTime;                                             // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0xC];                                       // 0x0014(0x000C) MISSED OFFSET
};

// ScriptStruct SeasonProgressionFramework.PlayerTrackedObjective
// 0x0010
struct FPlayerTrackedObjective
{
	struct FGuid                                       ObjectiveId;                                              // 0x0000(0x0010) (ZeroConstructor, IsPlainOldData)
};

// Class TaleMaps.TaleQuestMapStepDescBase
// 0x0000 (0x0080 - 0x0080)
class UTaleQuestMapStepDescBase : public UTaleQuestStepDesc
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class TaleMaps.TaleQuestMapStepDescBase"));
		return ptr;
	}

};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
