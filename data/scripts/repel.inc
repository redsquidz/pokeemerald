EventScript_RepelWoreOff::
	lockall
	checkitem VAR_QUICK_REPEL_TYPE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RepelWoreOff_NoMoreRepels
	msgbox Text_RepelWoreOff_UseAnother, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_RepelWoreOff_ChooseNo
	copyvar VAR_0x8004, VAR_QUICK_REPEL_TYPE
	callnative ItemId_GetHoldEffectParam_Script
	copyvar VAR_REPEL_STEP_COUNT, VAR_RESULT
	bufferitemname 1, VAR_QUICK_REPEL_TYPE
	removeitem VAR_QUICK_REPEL_TYPE, 1
	playse SE_REPEL
	msgbox gText_PlayerUsedVar2, MSGBOX_DEFAULT
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_ChooseNo:
	closemessage
	goto EventScript_RepelWoreOff_End

EventScript_RepelWoreOff_NoMoreRepels:
	msgbox Text_RepelWoreOff, MSGBOX_DEFAULT

EventScript_RepelWoreOff_End:
	releaseall
	end

Text_RepelWoreOff:
	.string "REPEL's effect wore off…$"

Text_RepelWoreOff_UseAnother:
	.string "REPEL's effect wore off…\n"
	.string "Use another?$"
