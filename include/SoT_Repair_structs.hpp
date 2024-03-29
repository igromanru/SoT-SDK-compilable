#pragma once

// Sea of Thieves (2) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "SoT_Basic.hpp"
#include "SoT_Repair_enums.hpp"
#include "SoT_CoreUObject_classes.hpp"
#include "SoT_Athena_classes.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct Repair.EventRepairableObjectRepairEndedEvent
// 0x0028
struct FEventRepairableObjectRepairEndedEvent
{
	class UObject*                                     Repairable;                                               // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     Position;                                                 // 0x0008(0x000C) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0014(0x0004) MISSED OFFSET
	class AActor*                                      RepairerActor;                                            // 0x0018(0x0008) (ZeroConstructor, IsPlainOldData)
	float                                              RepairPercentage;                                         // 0x0020(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
};

// ScriptStruct Repair.EventRepairableObjectDestroyed
// 0x0001
struct FEventRepairableObjectDestroyed
{
	unsigned char                                      UnknownData00[0x1];                                       // 0x0000(0x0001) MISSED OFFSET
};

// ScriptStruct Repair.EventPlayerUndoRepairEnd
// 0x0008
struct FEventPlayerUndoRepairEnd
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct Repair.EventPlayerUndoRepairCompleted
// 0x0008
struct FEventPlayerUndoRepairCompleted
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

// ScriptStruct Repair.EventPlayerUndoRepairStart
// 0x0008
struct FEventPlayerUndoRepairStart
{
	unsigned char                                      UnknownData00[0x8];                                       // 0x0000(0x0008) MISSED OFFSET
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
