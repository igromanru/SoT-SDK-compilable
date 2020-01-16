#pragma once

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "SoT_Basic.hpp"
#include "SoT_CoreUObject_classes.hpp"
#include "SoT_Athena_enums.hpp"
#include "SoT_ObjectMessaging_structs.hpp"

namespace SDK
{

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
// 0x0020
struct FDetailAppearenceDesc
{
	struct FStringAssetReference                       Mesh;                                                     // 0x0000(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
	TArray<struct FDetailAppearenceMaterialDesc>       Materials;                                                // 0x0010(0x0010) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor)
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
// 0x0010
struct FPlayerStat
{
	struct FName                                       Name;                                                     // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x8];                                       // 0x0008(0x0008) MISSED OFFSET
};

// ScriptStruct AthenaAI.TargetSkillsetProgressionPair
// 0x0020
struct FTargetSkillsetProgressionPair
{
	struct FStringAssetReference                       CrewSkillset;                                             // 0x0000(0x0010) (Edit, ZeroConstructor)
	struct FStringAssetReference                       CaptainSkillset;                                          // 0x0010(0x0010) (Edit, ZeroConstructor)
};

// Class AthenaAI.AthenaAIFormComponent
// 0x0058 (0x0120 - 0x00C8)
class UAthenaAIFormComponent : public UActorComponent
{
public:
	class UAthenaAIFormDataAsset*                      FormData;                                                 // 0x00C8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UCharacterHitReactionDamagerTypeToAnimTypeLayer* HitReactionsLayer;                                        // 0x00D0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x48];                                      // 0x00D8(0x0048) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class AthenaAI.AthenaAIFormComponent"));
		return ptr;
	}


	void OnRep_FormData();
};

// Class Athena.MetalAIFormComponent
// 0x00C0 (0x01E0 - 0x0120)
class UMetalAIFormComponent : public UAthenaAIFormComponent
{
public:
	unsigned char                                      UnknownData00[0x28];                                      // 0x0120(0x0028) MISSED OFFSET
	class UParticleSystem*                             RustyParticlesTemplate;                                   // 0x0148(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCharacterAudioFootfallControllerParams*     DefaultFootfallParams;                                    // 0x0150(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCharacterAudioFootfallControllerParams*     RustyFootfallParams;                                      // 0x0158(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TAssetPtr<class UMaterial>                         MetalBaseMaterial;                                        // 0x0160(0x0020) (Edit, DisableEditOnInstance)
	struct FName                                       RustShaderParamName;                                      // 0x0180(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              NotRustyShaderParamValue;                                 // 0x0188(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RustyShaderParamValue;                                    // 0x018C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ShaderParamBlendSpeed;                                    // 0x0190(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SeedShaderParamName;                                      // 0x0194(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxSeedShaderValue;                                       // 0x019C(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               IsWet;                                                    // 0x01A0(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x01A1(0x0007) MISSED OFFSET
	class UParticleSystemComponent*                    RustyParticleSystemComponent;                             // 0x01A8(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x01B0(0x0008) MISSED OFFSET
	class UDamageableVulnerabilityLayer*               DefaultVulnerabilityLayer;                                // 0x01B8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UDamageableVulnerabilityLayer*               RustyVulnerabilityLayer;                                  // 0x01C0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UCharacterHitReactionDamagerTypeToAnimTypeLayer* RustyHitReactionsLayer;                                   // 0x01C8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UMaterialInstanceDynamic*                    MetalDynamicMaterialInstance;                             // 0x01D0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData03[0x8];                                       // 0x01D8(0x0008) MISSED OFFSET

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
// 0x0140 (0x0550 - 0x0410)
class AItemInfo : public AActor
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x0410(0x0020) MISSED OFFSET
	bool                                               CanBeStoredInInventory;                                   // 0x0430(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0431(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnItemPickedUpDelegate;                                   // 0x0438(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UClass*                                      WieldableType;                                            // 0x0448(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              WieldDuration;                                            // 0x0450(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x4];                                       // 0x0454(0x0004) MISSED OFFSET
	TArray<class UClass*>                              ValidMidWieldInputs;                                      // 0x0458(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	class UClass*                                      ProxyType;                                                // 0x0468(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      ProjectileType;                                           // 0x0470(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UParticleSystem*                             LoadedItemParticleTemplate;                               // 0x0478(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UItemDesc*                                   Desc;                                                     // 0x0480(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EItemRepresentation>                   CurrentRepresentation;                                    // 0x0488(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0x7];                                       // 0x0489(0x0007) MISSED OFFSET
	class AActor*                                      CurrentRepresentationInstance;                            // 0x0490(0x0008) (Edit, Net, ZeroConstructor, EditConst, IsPlainOldData)
	class AActor*                                      CurrentOwner;                                             // 0x0498(0x0008) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	class AActor*                                      TutorialOwner;                                            // 0x04A0(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0xA1];                                      // 0x04A8(0x00A1) MISSED OFFSET
	bool                                               DoNotConsiderForMigrationGather;                          // 0x0549(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x6];                                       // 0x054A(0x0006) MISSED OFFSET

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
// 0x0000 (0x0550 - 0x0550)
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
// 0x03A0 (0x07B0 - 0x0410)
class AWieldableItem : public AActor
{
public:
	unsigned char                                      UnknownData00[0x50];                                      // 0x0410(0x0050) MISSED OFFSET
	class UPrimitiveComponent*                         FirstPersonMesh;                                          // 0x0460(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UPrimitiveComponent*                         ThirdPersonMesh;                                          // 0x0468(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UActionRulesComponent*                       ActionRulesComponent;                                     // 0x0470(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass*                                      AnimationKey;                                             // 0x0478(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FObjectMessagingDispatcher                  MessagingDispatcher;                                      // 0x0480(0x00A0) (BlueprintVisible)
	struct FTransform                                  AnimationOffset;                                          // 0x0520(0x0030) (Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData)
	class UWwiseEvent*                                 EquipSfx;                                                 // 0x0550(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 UnequipSfx;                                               // 0x0558(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 WielderLandedJumpSfx;                                     // 0x0560(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 WielderFootstepLayerOneshot;                              // 0x0568(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerWalkSpeedRtpc;                                      // 0x0570(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EWieldableItemSize>                    ItemSize;                                                 // 0x0578(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0579(0x0007) MISSED OFFSET
	struct FDetailAppearenceDesc                       DetailAppearence;                                         // 0x0580(0x0020) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	bool                                               PropagateVisibilityToChildren;                            // 0x05A0(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x05A1(0x0003) MISSED OFFSET
	struct FName                                       AINoiseTag;                                               // 0x05A4(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x05AC(0x0004) MISSED OFFSET
	class UClass*                                      ItemCategory;                                             // 0x05B0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class AItemInfo*                                   ItemInfo;                                                 // 0x05B8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TArray<struct FName>                               ThirdPersonExtraMeshNames;                                // 0x05C0(0x0010) (Edit, ZeroConstructor)
	TArray<struct FName>                               StashedExtraMeshNames;                                    // 0x05D0(0x0010) (Edit, ZeroConstructor)
	class UMeshComponent*                              StashedMeshComponent;                                     // 0x05E0(0x0008) (Edit, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       StashedMeshAttachSocket;                                  // 0x05E8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       ServerWieldAttachSocket;                                  // 0x05F0(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UPhrasesRadialDataAsset*                     Phrases;                                                  // 0x05F8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UObject*                                     CachedFirstPersonProxyMesh;                               // 0x0600(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	class UObject*                                     CachedThirdPersonProxyMesh;                               // 0x0608(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData04[0x128];                                     // 0x0610(0x0128) MISSED OFFSET
	class AInterpolatingItem*                          InterpolatingItem;                                        // 0x0738(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x18];                                      // 0x0740(0x0018) MISSED OFFSET
	TWeakObjectPtr<class AActor>                       LastKnownWielder;                                         // 0x0758(0x0008) (ZeroConstructor, IsPlainOldData)
	class UWieldableItemVfxComponent*                  WieldableItemVfxComponent;                                // 0x0760(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class UMeshComponent*>                      ThirdPersonExtraMeshes;                                   // 0x0768(0x0010) (ExportObject, ZeroConstructor, Transient)
	TArray<class UMeshComponent*>                      StashedExtraMeshes;                                       // 0x0778(0x0010) (ExportObject, ZeroConstructor, Transient)
	unsigned char                                      UnknownData06[0x19];                                      // 0x0788(0x0019) MISSED OFFSET
	bool                                               OfferingEnabled;                                          // 0x07A1(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData07[0xE];                                       // 0x07A2(0x000E) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.WieldableItem"));
		return ptr;
	}


	void SetItemWwiseSwitch(const struct FName& SwitchGroup, const struct FName& SwitchOption);
	void SetItemWwiseRTPC(float Value, struct FName* RTPCName);
	void PostItemWwiseEvent(class UWwiseEvent* Event);
	void OnWielderHasLandedFromJumpBPImpl();
	bool IsUnderwater();
	class AActor* GetWielder();
	struct FTransform GetWieldedItemAnimationOffset();
	TEnumAsByte<EWieldableItemSize> GetWieldableItemSize();
	class AActor* GetLastKnownWielder();
	bool GetIsFirstPerson();
};

// Class Athena.SkeletalMeshWieldableItem
// 0x0000 (0x07B0 - 0x07B0)
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
// 0x0030 (0x02C0 - 0x0290)
class UNameplateComponent : public USceneComponent
{
public:
	class USkeletalMeshSocket*                         NameplateSocket;                                          // 0x0290(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x28];                                      // 0x0298(0x0028) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.NameplateComponent"));
		return ptr;
	}


	struct FVector GetWorldPosition();
};

// Class Athena.ItemSpawnData
// 0x0000 (0x0028 - 0x0028)
class UItemSpawnData : public UObject
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.ItemSpawnData"));
		return ptr;
	}

};

// ScriptStruct Athena.KnockBackInfo
// 0x0034
struct FKnockBackInfo
{
	float                                              HorizontalVelocity;                                       // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              VerticalVelocity;                                         // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              SwimmingVelocity;                                         // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DockedHorizontalVelocity;                                 // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              DockedVerticalVelocity;                                   // 0x0010(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	bool                                               UseDockedVelocitiesWhenDocked;                            // 0x0014(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0015(0x0003) MISSED OFFSET
	struct FName                                       RumbleTag;                                                // 0x0018(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              StunDuration;                                             // 0x0020(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AIKnockbackDistance;                                      // 0x0024(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AIKnockbackSpeed;                                         // 0x0028(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	float                                              AIKnockbackAcceleration;                                  // 0x002C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EAIKnockbackStrengthType>              AIKnockbackStrengthType;                                  // 0x0030(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0031(0x0003) MISSED OFFSET
};

// Class Athena.DitherComponent
// 0x00A0 (0x0168 - 0x00C8)
class UDitherComponent : public UActorComponent
{
public:
	unsigned char                                      UnknownData00[0x8];                                       // 0x00C8(0x0008) MISSED OFFSET
	bool                                               FindMeshOnOwner;                                          // 0x00D0(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x00D1(0x0007) MISSED OFFSET
	TArray<class UMaterialInstanceDynamic*>            DynamicMaterials;                                         // 0x00D8(0x0010) (ZeroConstructor, Transient)
	float                                              FadeTime;                                                 // 0x00E8(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0xC];                                       // 0x00EC(0x000C) MISSED OFFSET
	class UMeshComponent*                              Mesh;                                                     // 0x00F8(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData03[0x68];                                      // 0x0100(0x0068) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.DitherComponent"));
		return ptr;
	}


	void SetCurrentTransparency(float Val);
	void FadeOut();
	void FadeIn();
};

// Class Athena.LookAtOffsetCompositeInputHandler
// 0x0048 (0x0120 - 0x00D8)
class ULookAtOffsetCompositeInputHandler : public UCompositeInputHandler
{
public:
	class AActor*                                      Controller;                                               // 0x00D8(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x40];                                      // 0x00E0(0x0040) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.LookAtOffsetCompositeInputHandler"));
		return ptr;
	}


	TEnumAsByte<EInputHandlerResult> OnYawRate(float Value);
	TEnumAsByte<EInputHandlerResult> OnYaw(float Value);
	TEnumAsByte<EInputHandlerResult> OnPitchRate(float Value);
	TEnumAsByte<EInputHandlerResult> OnPitch(float Value);
};

// ScriptStruct AthenaEngine.BoxedRpc
// 0x0010
struct FBoxedRpc
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
	class UScriptStruct*                               Type;                                                     // 0x0008(0x0008) (ZeroConstructor, IsPlainOldData, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
};

// ScriptStruct Athena.NetworkEventStruct
// 0x0000 (0x0010 - 0x0010)
struct FNetworkEventStruct : public FBoxedRpc
{

};



}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
