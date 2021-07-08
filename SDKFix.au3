#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.14.5
 Author:         Igromanru

 Script Function:
	Fixes SDK after the generation

#ce ----------------------------------------------------------------------------

#include <FileConstants.au3>
#include <MsgBoxConstants.au3>
#include <File.au3>
#include <Array.au3>

;~ Global Const $GENERATED_SDK_DIR = @LocalAppDataDir & "\Packages\Microsoft.SeaofThieves_8wekyb3d8bbwe\AC\Temp\SoT_1.4\SDK\"
Global Const $GENERATED_SDK_DIR = "D:\Git\SDK\SoT\SoT-SDK-private\SoT-SDK\SDK\"
Global Const $SDK_DIR = @ScriptDir & "\include"
Global Const $SDK_SOURCE_DIR = @ScriptDir & "\source"
Global Const $ENGINE_CLASS = $SDK_DIR & "\SoT_Engine_classes.hpp"
Global Const $ATHENA_CLASS = $SDK_DIR & "\SoT_Athena_classes.hpp"
Global Const $SDK_HEADER = $SDK_DIR & "\SDK.hpp"
Global Const $ATHENA_COMMONS = "AthenaCommons.hpp"

Global Const $FILE_BASE_NAMES[] = [ _
						   "SoT_Basic", _
						   "SoT_CoreUObject", _
						   "SoT_Engine", _
						   "SoT_InputCore", _
						   "SoT_SlateCore", _
						   "SoT_Slate", _
						   "SoT_AIModule", _
						   "SoT_AIShips", _
						   "SoT_ActionStateMachine", _
						   "SoT_Animation", _
						   "SoT_AthenaAI", _
						   "SoT_AthenaEngine", _
						   "SoT_AthenaInput", _
						   "SoT_AthenaRigging", _
						   "SoT_AthenaSocketLookup", _
						   "SoT_Athena", _
						   "SoT_CoherentUIGTPlugin", _
						   "SoT_DebugMenu", _
						   "SoT_Engine", _
						   "SoT_GameService", _
						   "SoT_GameplayDebugger", _
						   "SoT_GameplayTags", _
						   "SoT_GameplayTasks", _
						   "SoT_InputCore", _
						   "SoT_Interaction", _
						   "SoT_JsonUtilities", _
						   "SoT_Kraken", _
						   "SoT_Maths", _
						   "SoT_MovieSceneTracks", _
						   "SoT_MovieScene", _
						   "SoT_ObjectLifetime", _
						   "SoT_ObjectMessaging", _
						   "SoT_PirateGenerator", _
						   "SoT_PositionalVoice", _
						   "SoT_RareAudio", _
						   "SoT_RareEngine", _
						   "SoT_StatusEffects", _
						   "SoT_StudiosAutomation", _
						   "SoT_Time", _
						   "SoT_UMG", _
						   "SoT_Water", _
						   "SoT_Watercrafts", _
						   "SoT_Wind", _
						   "SoT_WwiseAudio", _
						   "SoT_NaturalDisasters", _
						   "SoT_Sessions", _
						   "SoT_Pets", _
						   "SoT_ShipDamage", _
						   "SoT_Repair", _
						   "SoT_Tethering", _
						   "SoT_Tales", _
						   "SoT_Retraction", _
						   "SoT_Cooking", _
						   "SoT_BP_MediumShipTemplate", _
						   "SoT_BP_LargeShipTemplate", _
						   "SoT_BP_SmallShipTemplate", _
						   "SoT_Fire", _
						   "SoT_EmotingFramework", _
						   "SoT_DeliverableFramework", _
						   "SoT_PrioritisedPrompts", _
						   "SoT_MerchantContracts", _
						   "SoT_BP_CollectorsChest_Proxy", _
						   "SoT_BP_SkeletonPawnBase", _
						   "SoT_SeasonProgressionFramework", _
						   "SoT_EnchantedCompass", _
						   "SoT_TaleMaps", _
						   "SoT_SpireFramework", _
						   "SoT_ItemQuality", _
						   "SoT_Reviving", _
						   "SoT_AthenaAIAbilities", _
						   "SoT_WaterSlide", _
						   "SoT_ResourceContentionFramework", _
						   "SoT_OnlineSubsystem", _
						   "SoT_LevelSequence" _
						]
Func addAActorsInULevel()
	Local Const $search = @TAB & "unsigned char                                      UnknownData00[0xA0];                                      // 0x0028(0x00A0) MISSED OFFSET"
	Local Const $replace = @TAB & "unsigned char                                      UnknownData00[0x78];                                      // 0x0028(0x0078) MISSED OFFSET" & @CRLF _
						  & @TAB & "TArray<class AActor*>                              AActors;                                                  // 0x00A0(0x0010)" & @CRLF _
						  & @TAB & "unsigned char                                      UnknownData10[0x18];                                      // 0x00B0(0x0018) MISSED OFFSET"
	Local $hFileOpen = FileOpen($ENGINE_CLASS, $FO_READ + $FO_UTF8_NOBOM)
	Local $originalText = FileRead($hFileOpen)
	Local $newText = StringReplace($originalText, $search, $replace)
	If @extended < 1 Then
		MsgBox($MB_ICONWARNING, "SDK Fix", "AActors array couldn't be added to ULevel (extended " & @extended & ")")
	EndIf
	FileClose($hFileOpen)

	$hFileOpen = FileOpen($ENGINE_CLASS, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	FileWrite($hFileOpen, $newText)
	FileClose($hFileOpen)
EndFunc

Func addSpaceBasesArrayInUSkinnedMeshComponent()
	Local Const $search = @TAB & "TWeakObjectPtr<class USkinnedMeshComponent>        MasterPoseComponent;                                      // 0x0588(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)" & @CRLF _
						 & @TAB & "unsigned char                                      UnknownData00[0x40];                                      // 0x0590(0x0040) MISSED OFFSET"
	Local Const $replace =  @TAB & "TWeakObjectPtr<class USkinnedMeshComponent>        MasterPoseComponent;                                      // 0x0588(0x0008) (BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData)" & @CRLF _
						  & @TAB & "TArray<FTransform>                                 SpaceBasesArray[2];                                       // 0x0590(0x0020)" & @CRLF _
						  & @TAB & "int32_t                                            CurrentEditableSpaceBases;                                // 0x05B0(0x0004)" & @CRLF _
						  & @TAB & "int32_t                                            CurrentReadSpaceBases;                                    // 0x05B4(0x0004)" & @CRLF _
						  & @TAB & "unsigned char                                      UnknownData00[0x18];                                      // 0x05B8(0x0018) MISSED OFFSET"
	Local $hFileOpen = FileOpen($ENGINE_CLASS, $FO_READ + $FO_UTF8_NOBOM)
	Local $originalText = FileRead($hFileOpen)
	Local $newText = StringReplace($originalText, $search, $replace)
	If @extended < 1 Then
		MsgBox($MB_ICONWARNING, "SDK Fix", "SpaceBasesArray couldn't be added(extended " & @extended & ")")
	EndIf
	FileClose($hFileOpen)

	$hFileOpen = FileOpen($ENGINE_CLASS, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	FileWrite($hFileOpen, $newText)
	FileClose($hFileOpen)
EndFunc

Func addPitchAndYawToAHarpoonLauncher()
	Local Const $search = @TAB & "unsigned char                                      UnknownData05[0x19];                                      // 0x0B98(0x0019) MISSED OFFSET" & @CRLF _
						 & @TAB & "bool                                               AlwaysRetractAtMaxLength;                                 // 0x0BB1(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)"

	Local Const $replace = @TAB & "unsigned char                                      UnknownData05[0x08];                                      // 0x0B98(0x0008) MISSED OFFSET" & @CRLF _
						 & @TAB & "float                                              Pitch;                                                    // 0x0BA0(0x0004) (Net, ZeroConstructor, IsPlainOldData)" & @CRLF _
						 & @TAB & "float                                              Yaw;                                                      // 0x0BA4(0x0004) (Net, ZeroConstructor, IsPlainOldData)" & @CRLF _
						 & @TAB & "unsigned char                                      UnknownData66[0x09];                                      // 0x0BA8(0x0009) MISSED OFFSET" & @CRLF _
						 & @TAB & "bool                                               AlwaysRetractAtMaxLength;                                 // 0x0BB1(0x0001) (Edit, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)"
	Local $hFileOpen = FileOpen($ATHENA_CLASS, $FO_READ + $FO_UTF8_NOBOM)
	Local $originalText = FileRead($hFileOpen)
	Local $newText = StringReplace($originalText, $search, $replace)
	If @extended < 1 Then
		MsgBox($MB_ICONWARNING, "SDK Fix", "Pitch and Yaw couldn't be added to AHarpoonLauncher (extended " & @extended & ")")
	EndIf
	FileClose($hFileOpen)

	$hFileOpen = FileOpen($ATHENA_CLASS, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	FileWrite($hFileOpen, $newText)
	FileClose($hFileOpen)
EndFunc

; Is not in use, bones is SpaceBasesArray in USkinnedMeshComponent
;~ Func addBoneSpaceTransformsInUSkeletalMeshComponent()
;~ 	Local $hFile = FileOpen($ENGINE_CLASS, $FO_READ + $FO_UTF8_NOBOM)
;~ 	Local $fileAsArray = FileReadToArray($hFile)
;~ 	FileClose($hFile)
;~ 	Local $classSearchMode = True
;~ 	Local $isReplaced = False
;~ 	For $i = 0 To UBound($fileAsArray)-1
;~ 		If $classSearchMode Then
;~ 			If $fileAsArray[$i] = 'class USkeletalMeshComponent : public USkinnedMeshComponent' Then
;~ 				$classSearchMode = False
;~ 			EndIf
;~ 		Else
;~ 			If StringInStr($fileAsArray[$i], 'unsigned char                                      UnknownData02[0x10];                                      // 0x0718(0x0010)') > 0 Then
;~ 				$fileAsArray[$i] = "	TArray<struct FTransform>                          BoneSpaceTransforms;                                      // 0x0718(0x0010) MISSED OFFSET"
;~ 				$isReplaced = True
;~ 			EndIf
;~ 		EndIf
;~ 	Next
;~ 	If $isReplaced Then
;~ 		$hFile = FileOpen($ENGINE_CLASS, $FO_OVERWRITE + $FO_UTF8_NOBOM)
;~ 		_FileWriteFromArray($hFile, $fileAsArray)
;~ 		FileClose($hFile)
;~ 	Else
;~ 		MsgBox($MB_ICONWARNING, "SDK Fix", "BoneSpaceTransforms couldn't be added")
;~ 	EndIf
;~ EndFunc

Func createSDKHeader()
   Local $hFileOpen = FileOpen($SDK_HEADER, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   Local $sdkHeader = "#pragma once" & @CRLF & @CRLF _
	  & "#include ""SoT_Basic.hpp""" & @CRLF _
	  & "#include ""SoT_CoreUObject_classes.hpp""" & @CRLF _
	  & '#include "SoT_Engine_classes.hpp"' & @CRLF _
	  & '#include "SoT_Athena_classes.hpp"'
   Local Const $FILTER[] = [ _
							  "SoT_AIShips_classes.hpp", _
							  "SoT_AthenaAI_classes.hpp", _
							  "SoT_CoreUObject_classes.hpp", _
							  "SoT_Engine_classes.hpp", _
							  "SoT_Athena_classes.hpp" _
							]
   Local $hSearch = FileFindFirstFile($SDK_DIR & "\*_classes.hpp")
   If $hSearch = -1 Then
	  MsgBox($MB_SYSTEMMODAL, "", "Error: No files found to create SDK.hpp")
	  Return False
   EndIf
   Local $sFileName = "", $iResult = 0
   While 1
	  $sFileName = FileFindNextFile($hSearch)
	  If @error Then ExitLoop

	  If _ArraySearch($FILTER, $sFileName) < 0 Then
		 $sdkHeader = $sdkHeader & @CRLF & '#include "' & $sFileName & '"'
	  EndIf
   WEnd
   FileWrite($hFileOpen, $sdkHeader)
   FileClose($hFileOpen)
EndFunc

Func fixCoreUObjectEnums()
   Local Const $CORE_UOBJECT_ENUMS = $SDK_DIR & "\SoT_CoreUObject_enums.hpp"
   Local Const $search = "PF_MAX                         = 63"
   Local Const $replace = "PF_MAX1                        = 63"
   Local $hFileOpen = FileOpen($CORE_UOBJECT_ENUMS, $FO_READ + $FO_UTF8_NOBOM)
   Local $originalText = FileRead($hFileOpen)
   Local $newText = StringReplace($originalText, $search, $replace)
   FileClose($hFileOpen)

   $hFileOpen = FileOpen($CORE_UOBJECT_ENUMS, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   FileWrite($hFileOpen, $newText)
   FileClose($hFileOpen)
EndFunc

Func copyRelevantFiles()
   Local Const $SOURCE_FILES[] = [ _
							  "SoT_Basic.cpp", _
							  "SoT_Athena_functions.cpp", _
							  "SoT_CoreUObject_functions.cpp", _
							  "SoT_Engine_functions.cpp", _
							  "SoT_Maths_functions.cpp", _
							  "SoT_UMG_functions.cpp", _
							  "SoT_DebugMenu_functions.cpp" _
						   ]
   For $fileName In $FILE_BASE_NAMES
	  FileCopy($GENERATED_SDK_DIR & $fileName & ".hpp", $SDK_DIR & "\" & $fileName & ".hpp", $FC_OVERWRITE)
	  FileCopy($GENERATED_SDK_DIR & $fileName & "_enums.hpp", $SDK_DIR & "\" & $fileName & "_enums.hpp", $FC_OVERWRITE)
	  FileCopy($GENERATED_SDK_DIR & $fileName & "_structs.hpp", $SDK_DIR & "\" & $fileName & "_structs.hpp", $FC_OVERWRITE)
	  FileCopy($GENERATED_SDK_DIR & $fileName & "_classes.hpp", $SDK_DIR & "\" & $fileName & "_classes.hpp", $FC_OVERWRITE)
   Next
   For $source In $SOURCE_FILES
	  If FileCopy($GENERATED_SDK_DIR & $source, $SDK_SOURCE_DIR & "\" & $source, $FC_OVERWRITE) = 0 Then
		 MsgBox($MB_ICONWARNING, "SDK Fix", $source & " couldn't be copied")
		 Exit
	  EndIf
   Next
EndFunc

Func fixBasicCpp()
   Local Const $BASIC_CPP = $SDK_SOURCE_DIR & "\SoT_Basic.cpp"
   Local $hBasicCpp = FileOpen($BASIC_CPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $aBasicCpp = FileReadToArray($hBasicCpp)
   FileClose($hBasicCpp)
   For $i = 0 To UBound($aBasicCpp)-1
	  If $aBasicCpp[$i] = '#include "../SDK.hpp"' Then
		 $aBasicCpp[$i] = '#include "SoT_Basic.hpp"'
		 _ArrayInsert($aBasicCpp, $i+1, '#include "SoT_CoreUObject_classes.hpp"')
		 ExitLoop
	  EndIf
   Next
   $hBasicCpp = FileOpen($BASIC_CPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hBasicCpp, $aBasicCpp)
   FileClose($hBasicCpp)
EndFunc

Func fixBasicHpp()
   Local Const $BASIC_HPP = $SDK_DIR & "\SoT_Basic.hpp"
   Local $hBasicHpp = FileOpen($BASIC_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $aBasicHpp = FileReadToArray($hBasicHpp)
   FileClose($hBasicHpp)
   For $i = 0 To UBound($aBasicHpp)-1
	  If $aBasicHpp[$i] = '#include <string>' Then
		 _ArrayInsert($aBasicHpp, $i+1, '#include "XorStrEx/XorStrEx.hpp"')
		 ExitLoop
	  EndIf
   Next
   $hBasicHpp = FileOpen($BASIC_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hBasicHpp, $aBasicHpp)
   FileClose($hBasicHpp)
EndFunc

Func fixAthenaClassesHpp()
   Local $hFile = FileOpen($ATHENA_CLASS, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_structs.hpp"' Then
		 Local $includes = '#include "SoT_AIShips_classes.hpp"' & @CRLF _
						& '#include "SoT_AthenaAI_classes.hpp"' & @CRLF _
						& '#include "SoT_Interaction_classes.hpp"' & @CRLF _
						& '#include "SoT_Kraken_classes.hpp"' & @CRLF _
						& '#include "SoT_Tales_classes.hpp"' & @CRLF _
						& '#include "' & $ATHENA_COMMONS & '"'
		 _ArrayInsert($fileAsArray, $i+1, $includes)
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($ATHENA_CLASS, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixAthenaStructsHppIncludes()
   Local Const $AthenaStructsHpp = $SDK_DIR & "\SoT_Athena_structs.hpp"
   Local $hFile = FileOpen($AthenaStructsHpp, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   Local $markForDelete = ""
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Interaction_classes.hpp"' _
		 Or  $fileAsArray[$i] = '#include "SoT_Kraken_classes.hpp"' _
		 Or  $fileAsArray[$i] = '#include "SoT_AIShips_classes.hpp"' _
		 Or  $fileAsArray[$i] = '#include "SoT_AthenaServerMigration_classes.hpp"' _
		 Or  $fileAsArray[$i] = '#include "SoT_Tales_classes.hpp"' _
		 Or  $fileAsArray[$i] = '#include "SoT_MysteriousNotes_classes.hpp"' _
		 Or  $fileAsArray[$i] = '#include "SoT_ItemQuality_classes.hpp"' _
		 Then
		 If $markForDelete <> "" Then
			 $markForDelete &= ";"
		 EndIf
		 $markForDelete &= $i
	  ElseIf $fileAsArray[$i] = '#include "SoT_AthenaAI_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_AthenaAI_enums.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_Cooking_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_Cooking_enums.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_EmissaryLevel_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_ItemQuality_classes.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_WaterSlide_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_WaterSlide_structs.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_Reviving_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_Reviving_structs.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_AthenaAIAbilities_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_AthenaAIAbilities_structs.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_ResourceContentionFramework_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_ResourceContentionFramework_structs.hpp"'
	  ElseIf $fileAsArray[$i] = '#include "SoT_SeasonProgressionFramework_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_SeasonProgressionFramework_structs.hpp"'
	  EndIf
   Next
   _ArrayDelete($fileAsArray,$markForDelete)
   $hFile = FileOpen($AthenaStructsHpp, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixAthenaAIStructsHppIncludes()
	Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_AthenaAI_structs.hpp"
	Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
	Local $fileAsArray = FileReadToArray($hFile)
	FileClose($hFile)
	For $i = 0 To UBound($fileAsArray)-1
		If $fileAsArray[$i] = '#include "SoT_Animation_classes.hpp"' Then
			_ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
			ExitLoop
		EndIf
	Next
	$hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileAsArray)
	FileClose($hFile)
EndFunc

Func fixPetsStructsHppIncludes()
	Local Const $PETS_STRUCTS_HPP = $SDK_DIR & "\SoT_Pets_structs.hpp"
	Local $hFile = FileOpen($PETS_STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
	Local $fileAsArray = FileReadToArray($hFile)
	FileClose($hFile)
	For $i = 0 To UBound($fileAsArray)-1
		If $fileAsArray[$i] = '#include "SoT_Engine_classes.hpp"' Then
			_ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
			ExitLoop
		EndIf
	Next
	$hFile = FileOpen($PETS_STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileAsArray)
	FileClose($hFile)
EndFunc

Func fixFireStructsHppIncludes()
	Local Const $PETS_STRUCTS_HPP = $SDK_DIR & "\SoT_Fire_structs.hpp"
	Local $hFile = FileOpen($PETS_STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
	Local $fileAsArray = FileReadToArray($hFile)
	FileClose($hFile)
	For $i = 0 To UBound($fileAsArray)-1
		If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
			$fileAsArray[$i] = '#include "AthenaCommons.hpp"'
;~ 			_ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
			ExitLoop
		EndIf
	Next
	$hFile = FileOpen($PETS_STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileAsArray)
	FileClose($hFile)
 EndFunc

Func fixTalesHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_Tales_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   Local $markForDelete = ""
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		$fileAsArray[$i] = '#include "SoT_Athena_structs.hpp"'
		_ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
	  EndIf
	  If $fileAsArray[$i] = '#include "SoT_EmissaryFramework_classes.hpp"' Or _
		 $fileAsArray[$i] = '#include "SoT_TaleMaps_classes.hpp"' _
		 Then
		 If $markForDelete <> "" Then
			 $markForDelete &= ";"
		 EndIf
		 $markForDelete &= $i
	  EndIf
	  If $fileAsArray[$i] = '#include "SoT_PrioritisedPrompts_classes.hpp"' Then
		$fileAsArray[$i] = '#include "SoT_PrioritisedPrompts_enums.hpp"'
		ExitLoop
	  EndIf
   Next
   _ArrayDelete($fileAsArray, $markForDelete)
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixPrioritisedPromptsHppIncludes()
	Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_PrioritisedPrompts_structs.hpp"
	Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
	Local $fileAsArray = FileReadToArray($hFile)
	FileClose($hFile)
	For $i = 0 To UBound($fileAsArray)-1
	   If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_Athena_structs.hpp"'
		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	   EndIf
	Next
	$hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileAsArray)
	FileClose($hFile)
EndFunc

Func fixEnchantedCompassStructsHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_EnchantedCompass_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_Athena_structs.hpp"'
		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixWaterSlideStructsHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_WaterSlide_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "' & $ATHENA_COMMONS & '"'
;~ 		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixRevivingStructsHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_Reviving_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "' & $ATHENA_COMMONS & '"'
;~ 		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixLevelSequenceStructsHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_Reviving_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "' & $ATHENA_COMMONS & '"'
;~ 		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixShipDamageStructsHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_ShipDamage_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
		 $fileAsArray[$i] = '#include "SoT_Athena_structs.hpp"'
		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

Func fixSeasonProgressionFrameworkStructsHppIncludes()
   Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_SeasonProgressionFramework_structs.hpp"
   Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
   Local $fileAsArray = FileReadToArray($hFile)
   FileClose($hFile)
   For $i = 0 To UBound($fileAsArray)-1
	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
;~ 		 $fileAsArray[$i] = '#include "SoT_Athena_structs.hpp"'
		 _ArrayInsert($fileAsArray, $i+1, '#include "' & $ATHENA_COMMONS & '"')
		 ExitLoop
	  EndIf
   Next
   $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
   _FileWriteFromArray($hFile, $fileAsArray)
   FileClose($hFile)
EndFunc

;~ Func fixResourceContentionFrameworkStructsHppIncludes()
;~    Local Const $STRUCTS_HPP = $SDK_DIR & "\SoT_ResourceContentionFramework_structs.hpp"
;~    Local $hFile = FileOpen($STRUCTS_HPP, $FO_READ + $FO_UTF8_NOBOM)
;~    Local $fileAsArray = FileReadToArray($hFile)
;~    FileClose($hFile)
;~    For $i = 0 To UBound($fileAsArray)-1
;~ 	  If $fileAsArray[$i] = '#include "SoT_Athena_classes.hpp"' Then
;~ 		 $fileAsArray[$i] = '#include "' & $ATHENA_COMMONS & '"'
;~ 		 ExitLoop
;~ 	  EndIf
;~    Next
;~    $hFile = FileOpen($STRUCTS_HPP, $FO_OVERWRITE + $FO_UTF8_NOBOM)
;~    _FileWriteFromArray($hFile, $fileAsArray)
;~    FileClose($hFile)
;~ EndFunc

Func removeStructFromFile($fileName, $scriptStructName)
	Local Const $Hpp = $SDK_DIR & "\" & $fileName
	Local $hFile = FileOpen($Hpp, $FO_READ + $FO_UTF8_NOBOM)
	Local $fileAsArray = FileReadToArray($hFile)
	Local $startPos = -1
	Local $endPos = -1
	FileClose($hFile)

	For $i = 0 To UBound($fileAsArray)-1
		If $startPos >= 0 Then
			If $fileAsArray[$i] = "};" Then
				$endPos = $i
				ExitLoop
			EndIf
		ElseIf $fileAsArray[$i] = $scriptStructName Then
			$startPos = $i
		EndIf
	Next
	If $startPos >= 0 And $endPos > 0 And $endPos > $startPos Then
		_ArrayDelete($fileAsArray, $startPos & "-" & $endPos+1)
	EndIf

	$hFile = FileOpen($Hpp, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileAsArray)
	FileClose($hFile)
 EndFunc

Func moveStructToFile($sourceFile, $structName, $targetName, $copy = false)
	Local Const $Hpp = $SDK_DIR & "\" & $sourceFile
	Local Const $TargetHpp = $SDK_DIR & "\" & $targetName
	Local $hFile = FileOpen($Hpp, $FO_READ + $FO_UTF8_NOBOM)
	Local $fileAsArray = FileReadToArray($hFile)
	Local $startPos = -1
	Local $endPos = -1
	FileClose($hFile)

	For $i = 0 To UBound($fileAsArray)-1
		If $startPos >= 0 Then
			If $fileAsArray[$i] = "};" Then
				$endPos = $i
				ExitLoop
			EndIf
		ElseIf $fileAsArray[$i] = $structName Then
			$startPos = $i
		EndIf
	Next
	If $startPos >= 0 And $endPos > 0 And $endPos > $startPos Then
		; Struct to array
		Local $extractedStruct = _ArrayExtract($fileAsArray, $startPos, $endPos)
		If Not @error Then
			If Not $copy Then
			   If StringStripCR($fileAsArray[$startPos-1]) = "" Then
				  $startPos = $startPos - 1
			   EndIf
			   $endPos = $endPos + 1
			   If StringStripCR($fileAsArray[$endPos+1]) = "" Then
				  $endPos = $endPos + 1
			   EndIf
				; Delete target struct from the source
				_ArrayDelete($fileAsArray, $startPos & "-" & $endPos)
			EndIf
			; Open target file and read the file to array
			Local $hTarget = FileOpen($TargetHpp, $FO_READ + $FO_UTF8_NOBOM)
			Local $targetAsArray = FileReadToArray($hTarget)
			FileClose($hTarget)

			; Find the position of the last struct in the SDK namespace
			Local $lastStructPos = -1
			For $i = 0 To UBound($targetAsArray)-1
				If $lastStructPos = -1 And $targetAsArray[$i] = "namespace SDK" Then
					$lastStructPos = $i + 1
				ElseIf $targetAsArray[$i] = "};" Then
					$lastStructPos = $i
				EndIf
			Next
			$lastStructPos += 1
			; insert a new line
			_ArrayInsert($targetAsArray, $lastStructPos, '')
			$lastStructPos += 1
			; insert the struct
			For $i = 0 To UBound($extractedStruct)-1
				_ArrayInsert($targetAsArray, $lastStructPos + $i, $extractedStruct[$i])
			Next
			$hTarget = FileOpen($TargetHpp, $FO_OVERWRITE + $FO_UTF8_NOBOM)
			_FileWriteFromArray($hTarget, $targetAsArray)
			FileClose($hTarget)
		EndIf
	EndIf

	$hFile = FileOpen($Hpp, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileAsArray)
	FileClose($hFile)
EndFunc

Func removeStructsFromAthenaAI()
   ; after 1.4.4
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.EventAILoadoutSelected')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.BountySpawnerAudioChangedNetworkEvent')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.TinySharkSpawnedNetworkEvent')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.TinySharkKilledNetworkEvent')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.EventTinySharkDamaged')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.AIFormDamageResponse')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.AttackableTypeToAnimMapping')
   removeStructFromFile("SoT_AthenaAI_structs.hpp",'// ScriptStruct AthenaAI.PetBaseTelemetryFragmentInput')

   removeStructFromFile("SoT_AthenaAI_classes.hpp",'// Class AthenaAI.AIEncounterGenerationRecipe')
   removeStructFromFile("SoT_AthenaAI_classes.hpp",'// Class AthenaAI.BTTask_SwimAttackTargetShip')
   ; after 1.4.5.7 insider
   removeStructFromFile("SoT_AthenaAI_classes.hpp",'// Class AthenaAI.PetDitherComponent')
   ; after 2.0.19
   removeStructFromFile("SoT_AthenaAI_classes.hpp",'// Class AthenaAI.AppliedStatusToMultipleAIWithFormsStatCondition')
EndFunc

Func removeStructsFromAthena()
   ; after 2.0.1.1 insider
	removeStructFromFile("SoT_Athena_structs.hpp",'// ScriptStruct Athena.EventEmoteStarted')
	; after 2.0.19
	removeStructFromFile("SoT_Athena_structs.hpp",'// ScriptStruct Athena.EventEmissaryFlagMeshChanged')
EndFunc

Func removeStructsShipDamage()
   ; after 1.4.5.4 insider
   removeStructFromFile("SoT_ShipDamage_classes.hpp", "// Class ShipDamage.StrainDamagerType")
   removeStructFromFile("SoT_ShipDamage_classes.hpp", "// Class ShipDamage.ShipDamagerType")
   removeStructFromFile("SoT_ShipDamage_classes.hpp", "// Class ShipDamage.LandscapeDamagerType")
   ; after 2.0.19
;~    removeStructFromFile("SoT_ShipDamage_structs.hpp", "// ScriptStruct ShipDamage.EventShipDamageApplied")
;~    removeStructFromFile("SoT_ShipDamage_structs.hpp", "// ScriptStruct ShipDamage.EventShipDamaged")
EndFunc

Func removeStructsFromWatercrafts()
	removeStructFromFile("SoT_Watercrafts_classes.hpp",'// Class Watercrafts.RowingCompositeInputHandler')
	removeStructFromFile("SoT_Watercrafts_classes.hpp",'// Class Watercrafts.RowboatDescDataAsset')
EndFunc

Func createAthenaCommons()
	Local Const $Hpp = $SDK_DIR & "\AthenaCommons.hpp"
	Local $fileArray[1] = ["#pragma once"]
	_ArrayAdd($fileArray, "")
	_ArrayAdd($fileArray, "#ifdef _MSC_VER")
	_ArrayAdd($fileArray, "	#pragma pack(push, 0x8)")
	_ArrayAdd($fileArray, "#endif")
	_ArrayAdd($fileArray, "")
	_ArrayAdd($fileArray, '#include "SoT_Basic.hpp"')
	_ArrayAdd($fileArray, '#include "SoT_CoreUObject_classes.hpp"')
	_ArrayAdd($fileArray, '#include "SoT_Athena_enums.hpp"')
	_ArrayAdd($fileArray, '#include "SoT_ObjectMessaging_structs.hpp"')
	_ArrayAdd($fileArray, '#include "SoT_Maths_structs.hpp"')
	_ArrayAdd($fileArray, "")
	_ArrayAdd($fileArray, "namespace SDK")
	_ArrayAdd($fileArray, "{")
	_ArrayAdd($fileArray, "")
	_ArrayAdd($fileArray, "}")
	_ArrayAdd($fileArray, "")
	_ArrayAdd($fileArray, "#ifdef _MSC_VER")
	_ArrayAdd($fileArray, "	#pragma pack(pop)")
	_ArrayAdd($fileArray, "#endif")

	Local $hFile = FileOpen($Hpp, $FO_OVERWRITE + $FO_UTF8_NOBOM)
	_FileWriteFromArray($hFile, $fileArray)
	FileClose($hFile)

	moveStructToFile("SoT_Tales_classes.hpp", "// Class Tales.TaleQuestStep", $ATHENA_COMMONS)
	moveStructToFile("SoT_Tales_classes.hpp", "// Class Tales.TaleQuestStepDesc", $ATHENA_COMMONS)
	moveStructToFile("SoT_Tales_classes.hpp", "// Class Tales.TaleQuestService", $ATHENA_COMMONS)
	moveStructToFile("SoT_Tales_classes.hpp", "// Class Tales.TaleQuestServiceDesc", $ATHENA_COMMONS)

	Local $athenaStructHpp = "SoT_Athena_structs.hpp"
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.ItemLoadoutCapacity", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.ItemLoadout", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.StartPickupObjectActionRuleParams", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.DetailAppearenceDesc", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct AthenaAI.AIBountySpawnerParams", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.BaseLightData", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.PointLightData", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.SpotLightData", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.GenericLightTemplate", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.ImpactDamageEvent", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.EncounterParams", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.TelemetryFragmentInput", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.WeightedPetAnimationSelector", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.PlayerStat", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.PetAnimationDataPreview", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.RewardId", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestDesc", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.DamageInstance", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.LookAtOffsetParams", $ATHENA_COMMONS)
	; QuestVariables
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariable", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableActor", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableAsset", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableClass", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableGuid", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariablePlayerActor", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableVector", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableNameArray", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableName", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableContestIslandArchetype", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableInt", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariablePageBundle", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableDataAsset", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableText", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableAssetArray", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableActorHandle", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableVaultHandle", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableAISpawner", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableAIDioramaDesc", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableBool", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableAISpawnerArray", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableUObject", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableVectorArray", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableTextArray", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableFloat", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableTransform", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.QuestVariableOrientedPoint", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.PirateIdentity", $ATHENA_COMMONS)
	moveStructToFile($athenaStructHpp, "// ScriptStruct Athena.PlayerBaseTelemetryFragment", $ATHENA_COMMONS)

	moveStructToFile("SoT_AthenaAI_structs.hpp", "// ScriptStruct AthenaAI.TargetSkillsetProgressionPair", $ATHENA_COMMONS)
	moveStructToFile("SoT_AthenaAI_structs.hpp", "// ScriptStruct AthenaAI.TinySharkParams", $ATHENA_COMMONS)
	moveStructToFile("SoT_AthenaAI_classes.hpp", "// Class AthenaAI.TinySharkExperience", $ATHENA_COMMONS)
	moveStructToFile("SoT_AthenaAI_classes.hpp", "// Class AthenaAI.AthenaAIFormComponent", $ATHENA_COMMONS)

	Local $athenaClassesHpp = "SoT_Athena_classes.hpp"
	moveStructToFile($athenaClassesHpp, "// Class Athena.MetalAIFormComponent", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.EntitlementDesc", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.ItemDesc", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.CategoryBase", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.ItemCategory", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.ItemInfo", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.NonStorableItemInfo", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.WieldableItem", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.SkeletalMeshWieldableItem", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.DamagerType", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.NameplateComponent", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.ItemSpawnData", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.PoseableMeshWieldableItem", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.TaleQuestToolService", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.Compass", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.TaleQuestToolServiceDesc", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.ConditionalStatsTriggerType", $ATHENA_COMMONS)
	moveStructToFile($athenaClassesHpp, "// Class Athena.StatCondition", $ATHENA_COMMONS)

	moveStructToFile("SoT_Pets_classes.hpp", "// Class Pets.PetCategory", $ATHENA_COMMONS)
	moveStructToFile("SoT_Pets_structs.hpp", "// ScriptStruct Pets.PetTurnToFaceData", $ATHENA_COMMONS)

	moveStructToFile("SoT_SeasonProgressionFramework_structs.hpp", "// ScriptStruct SeasonProgressionFramework.PlayerTrackedObjective", $ATHENA_COMMONS)

	moveStructToFile("SoT_TaleMaps_classes.hpp", "// Class TaleMaps.TaleQuestMapStepDescBase", $ATHENA_COMMONS)

	moveStructToFile("SoT_TaleMaps_classes.hpp", "// Class TaleMaps.TaleQuestMapStepDescBase", $ATHENA_COMMONS)
EndFunc

Func removeStructsFromTales()
   removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestEmissaryCompanyActionRewardBoostStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAddCargoRunMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAddMerchantMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAddRiddleMapBaseStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAddXMarksMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAdvanceRiddleMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestRemoveMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestUpdateMerchantMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAddRiddleMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'// Class Tales.TaleQuestAddRiddleMapStepDesc')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'')
;~    removeStructFromFile("SoT_Tales_classes.hpp",'')
EndFunc

copyRelevantFiles()
addAActorsInULevel()
addSpaceBasesArrayInUSkinnedMeshComponent()
addPitchAndYawToAHarpoonLauncher()
;~ ;addBoneSpaceTransformsInUSkeletalMeshComponent()
fixCoreUObjectEnums()
fixBasicCpp()
fixAthenaClassesHpp()
fixAthenaStructsHppIncludes()
fixAthenaAIStructsHppIncludes()
fixPetsStructsHppIncludes()
fixFireStructsHppIncludes()
fixTalesHppIncludes()
removeStructsFromAthenaAI()
removeStructsFromAthena()
createAthenaCommons()
createSDKHeader()
fixBasicHpp()
fixShipDamageStructsHppIncludes()
removeStructsShipDamage()
removeStructsFromWatercrafts()
removeStructsFromTales()
fixPrioritisedPromptsHppIncludes()
fixEnchantedCompassStructsHppIncludes()
fixWaterSlideStructsHppIncludes()
fixRevivingStructsHppIncludes()
fixLevelSequenceStructsHppIncludes()
fixSeasonProgressionFrameworkStructsHppIncludes()

MsgBox(0, @ScriptName, "Done")