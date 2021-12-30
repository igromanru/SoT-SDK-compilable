#pragma once

// Sea of Thieves (2) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "SoT_Basic.hpp"
#include "SoT_EmotingFramework_enums.hpp"
#include "SoT_Engine_classes.hpp"
#include "SoT_CoreUObject_classes.hpp"
#include "SoT_AthenaInput_classes.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct EmotingFramework.EmoteId
// 0x0008
struct FEmoteId
{
	struct FName                                       EmoteId;                                                  // 0x0000(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
};

// ScriptStruct EmotingFramework.EmoteData
// 0x0098
struct FEmoteData
{
	struct FEmoteId                                    EmoteId;                                                  // 0x0000(0x0008) (Edit, BlueprintVisible, BlueprintReadOnly)
	struct FText                                       EmoteDisplayName;                                         // 0x0008(0x0038) (Edit)
	struct FText                                       AudioDescription;                                         // 0x0040(0x0038) (Edit)
	bool                                               PlayAudioDescriptionForLocalPlayer;                       // 0x0078(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0079(0x0003) MISSED OFFSET
	float                                              DelayBeforeAllowingExit;                                  // 0x007C(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	float                                              VerticalOffsetFactorWhenZoomed;                           // 0x0080(0x0004) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               HideNameplate;                                            // 0x0084(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0085(0x0003) MISSED OFFSET
	class UEmotePropData*                              EmotePropDataAsset;                                       // 0x0088(0x0008) (Edit, ZeroConstructor, IsPlainOldData)
	bool                                               CanPlayInSuccession;                                      // 0x0090(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData02[0x7];                                       // 0x0091(0x0007) MISSED OFFSET
};

// ScriptStruct EmotingFramework.EventEmoteEndRequested
// 0x000C
struct FEventEmoteEndRequested
{
	struct FName                                       EmoteIdentifier;                                          // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               EndForcedEmote;                                           // 0x0008(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0009(0x0003) MISSED OFFSET
};

// ScriptStruct EmotingFramework.EventEndEmoteAnimation
// 0x0001
struct FEventEndEmoteAnimation
{
	unsigned char                                      UnknownData00[0x1];                                       // 0x0000(0x0001) MISSED OFFSET
};

// ScriptStruct EmotingFramework.EventEmoteSwapped
// 0x0098
struct FEventEmoteSwapped
{
	struct FEmoteData                                  EmoteData;                                                // 0x0000(0x0098)
};

// ScriptStruct EmotingFramework.EventEmoteCompleted
// 0x000C
struct FEventEmoteCompleted
{
	struct FName                                       EmoteName;                                                // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	uint32_t                                           EmoteDuration;                                            // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct EmotingFramework.EventEmoteStarted
// 0x0098
struct FEventEmoteStarted
{
	struct FEmoteData                                  EmoteData;                                                // 0x0000(0x0098) (BlueprintVisible, BlueprintReadOnly)
};

// ScriptStruct EmotingFramework.EventEmoteRequested
// 0x00A8
struct FEventEmoteRequested
{
	struct FEmoteData                                  EmoteData;                                                // 0x0000(0x0098)
	struct FName                                       ForcedEmoteIdentifier;                                    // 0x0098(0x0008) (ZeroConstructor, IsPlainOldData)
	bool                                               ForcedEmote;                                              // 0x00A0(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x00A1(0x0007) MISSED OFFSET
};

// ScriptStruct EmotingFramework.EmoteDiceOutcomeTelemetryEvent
// 0x0014
struct FEmoteDiceOutcomeTelemetryEvent
{
	int                                                MaxLimit;                                                 // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                RollNumber;                                               // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     OrientationUsed;                                          // 0x0008(0x000C) (ZeroConstructor, IsPlainOldData)
};

// ScriptStruct EmotingFramework.EventDisableLookAtEmoteCamera
// 0x0001
struct FEventDisableLookAtEmoteCamera
{
	unsigned char                                      UnknownData00[0x1];                                       // 0x0000(0x0001) MISSED OFFSET
};

// ScriptStruct EmotingFramework.EventEnableLookAtEmoteCamera
// 0x0008
struct FEventEnableLookAtEmoteCamera
{
	TWeakObjectPtr<class AActor>                       LookAtTarget;                                             // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
