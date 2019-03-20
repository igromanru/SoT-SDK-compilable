#pragma once

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "SoT_Basic.hpp"
#include "SoT_CoreUObject_classes.hpp"
#include "SoT_Athena_enums.hpp"

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
// ScriptStruct AthenaAI.TargetSkillsetProgressionPair
// 0x0020
struct FTargetSkillsetProgressionPair
{
	struct FStringAssetReference                       CrewSkillset;                                             // 0x0000(0x0010) (Edit, ZeroConstructor)
	struct FStringAssetReference                       CaptainSkillset;                                          // 0x0010(0x0010) (Edit, ZeroConstructor)
};
// Class AthenaAI.AthenaAIFormComponent
// 0x0080 (0x0150 - 0x00D0)
class UAthenaAIFormComponent : public UActorComponent
{
public:
	class UAthenaAIFormDataAsset*                      FormData;                                                 // 0x00D0(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UCharacterHitReactionDamagerTypeToAnimTypeLayer* HitReactionsLayer;                                        // 0x00D8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x70];                                      // 0x00E0(0x0070) MISSED OFFSET

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class AthenaAI.AthenaAIFormComponent"));
		return ptr;
	}


	void OnRep_FormData();
};
// Class Athena.MetalAIFormComponent
// 0x0098 (0x01E8 - 0x0150)
class UMetalAIFormComponent : public UAthenaAIFormComponent
{
public:
	class UParticleSystem*                             RustyParticlesTemplate;                                   // 0x0150(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCharacterAudioFootfallControllerParams*     DefaultFootfallParams;                                    // 0x0158(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UCharacterAudioFootfallControllerParams*     RustyFootfallParams;                                      // 0x0160(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	TAssetPtr<class UMaterial>                         MetalBaseMaterial;                                        // 0x0168(0x0020) (Edit, DisableEditOnInstance)
	struct FName                                       RustShaderParamName;                                      // 0x0188(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              NotRustyShaderParamValue;                                 // 0x0190(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              RustyShaderParamValue;                                    // 0x0194(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ShaderParamBlendSpeed;                                    // 0x0198(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FName                                       SeedShaderParamName;                                      // 0x019C(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                MaxSeedShaderValue;                                       // 0x01A4(0x0004) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               IsWet;                                                    // 0x01A8(0x0001) (Net, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x01A9(0x0007) MISSED OFFSET
	class UParticleSystemComponent*                    RustyParticleSystemComponent;                             // 0x01B0(0x0008) (ExportObject, ZeroConstructor, Transient, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData01[0x8];                                       // 0x01B8(0x0008) MISSED OFFSET
	class UDamageableVulnerabilityLayer*               DefaultVulnerabilityLayer;                                // 0x01C0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UDamageableVulnerabilityLayer*               RustyVulnerabilityLayer;                                  // 0x01C8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UCharacterHitReactionDamagerTypeToAnimTypeLayer* RustyHitReactionsLayer;                                   // 0x01D0(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	class UMaterialInstanceDynamic*                    MetalDynamicMaterialInstance;                             // 0x01D8(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x01E0(0x0008) MISSED OFFSET

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
// 0x0048 (0x0120 - 0x00D8)
class UItemDesc : public UEntitlementDesc
{
public:
	struct FStringClassReference                       InstanceClassType;                                        // 0x00D8(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	unsigned char                                      CanBeAddedToLoadout : 1;                                  // 0x00E8(0x0001) (Edit, DisableEditOnInstance)
	unsigned char                                      IsTransient : 1;                                          // 0x00E8(0x0001) (Edit, DisableEditOnInstance)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00E9(0x0007) MISSED OFFSET
	class FString                                      PreviousItem;                                             // 0x00F0(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	class FString                                      NextItem;                                                 // 0x0100(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)
	struct FStringAssetReference                       IconRadPath;                                              // 0x0110(0x0010) (Edit, ZeroConstructor, DisableEditOnInstance)

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
// 0x0128 (0x05C8 - 0x04A0)
class AItemInfo : public AActor
{
public:
	unsigned char                                      UnknownData00[0x20];                                      // 0x04A0(0x0020) MISSED OFFSET
	bool                                               CanBeStoredInInventory;                                   // 0x04C0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x04C1(0x0007) MISSED OFFSET
	struct FScriptMulticastDelegate                    OnItemPickedUpDelegate;                                   // 0x04C8(0x0010) (ZeroConstructor, InstancedReference, BlueprintAssignable)
	class UClass*                                      WieldableType;                                            // 0x04D8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      ProxyType;                                                // 0x04E0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      ProjectileType;                                           // 0x04E8(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UParticleSystem*                             LoadedItemParticleTemplate;                               // 0x04F0(0x0008) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UItemDesc*                                   Desc;                                                     // 0x04F8(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EItemRepresentation>                   CurrentRepresentation;                                    // 0x0500(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0501(0x0007) MISSED OFFSET
	class AActor*                                      CurrentRepresentationInstance;                            // 0x0508(0x0008) (Edit, Net, ZeroConstructor, EditConst, IsPlainOldData)
	class AActor*                                      CurrentOwner;                                             // 0x0510(0x0008) (Edit, ZeroConstructor, EditConst, IsPlainOldData)
	class AActor*                                      TutorialOwner;                                            // 0x0518(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData03[0xA1];                                      // 0x0520(0x00A1) MISSED OFFSET
	bool                                               DoNotConsiderForMigrationGather;                          // 0x05C1(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData04[0x6];                                       // 0x05C2(0x0006) MISSED OFFSET

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
// 0x0000 (0x05C8 - 0x05C8)
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
// 0x0330 (0x07D0 - 0x04A0)
class AWieldableItem : public AActor
{
public:
	unsigned char                                      UnknownData00[0x40];                                      // 0x04A0(0x0040) MISSED OFFSET
	class UPrimitiveComponent*                         FirstPersonMesh;                                          // 0x04E0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UPrimitiveComponent*                         ThirdPersonMesh;                                          // 0x04E8(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UActionRulesComponent*                       ActionRulesComponent;                                     // 0x04F0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UClass*                                      AnimationKey;                                             // 0x04F8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FObjectMessagingDispatcher                  MessagingDispatcher;                                      // 0x0500(0x00A0) (BlueprintVisible)
	class UWwiseEvent*                                 EquipSfx;                                                 // 0x05A0(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 UnequipSfx;                                               // 0x05A8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 WielderLandedJumpSfx;                                     // 0x05B0(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseEvent*                                 WielderFootstepLayerOneshot;                              // 0x05B8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       PlayerWalkSpeedRtpc;                                      // 0x05C0(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UWwiseObjectPoolWrapper*                     WwiseSfxPool;                                             // 0x05C8(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EWieldableItemSize>                    ItemSize;                                                 // 0x05D0(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x05D1(0x0007) MISSED OFFSET
	struct FDetailAppearenceDesc                       DetailAppearence;                                         // 0x05D8(0x0020) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	bool                                               PropagateVisibilityToChildren;                            // 0x05F8(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x05F9(0x0003) MISSED OFFSET
	struct FName                                       AINoiseTag;                                               // 0x05FC(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x0604(0x0004) MISSED OFFSET
	class UClass*                                      ItemCategory;                                             // 0x0608(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class AItemInfo*                                   ItemInfo;                                                 // 0x0610(0x0008) (Net, ZeroConstructor, IsPlainOldData)
	class UMeshComponent*                              StashedMeshComponent;                                     // 0x0618(0x0008) (Edit, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FName                                       StashedMeshAttachSocket;                                  // 0x0620(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	struct FName                                       ServerWieldAttachSocket;                                  // 0x0628(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	class UPhrasesRadialDataAsset*                     Phrases;                                                  // 0x0630(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class UObject*                                     CachedFirstPersonProxyMesh;                               // 0x0638(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	class UObject*                                     CachedThirdPersonProxyMesh;                               // 0x0640(0x0008) (BlueprintVisible, ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData04[0x128];                                     // 0x0648(0x0128) MISSED OFFSET
	class AInterpolatingItem*                          InterpolatingItem;                                        // 0x0770(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData05[0x30];                                      // 0x0778(0x0030) MISSED OFFSET
	class UWieldableItemVfxComponent*                  WieldableItemVfxComponent;                                // 0x07A8(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData06[0x20];                                      // 0x07B0(0x0020) MISSED OFFSET

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
	TEnumAsByte<EWieldableItemSize> GetWieldableItemSize();
	class AActor* GetLastKnownWielder();
	bool GetIsFirstPerson();
};
// Class Athena.SkeletalMeshWieldableItem
// 0x0000 (0x07D0 - 0x07D0)
class ASkeletalMeshWieldableItem : public AWieldableItem
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Athena.SkeletalMeshWieldableItem"));
		return ptr;
	}

};
// Class Pets.PetCategory
// 0x0000 (0x0080 - 0x0080)
class UPetCategory : public UItemCategory
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindObject<UClass>(_xor_("Class Pets.PetCategory"));
		return ptr;
	}

};

































}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
