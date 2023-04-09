EventScript_StepStart::
	setflag FLAG_TEST_STEP @start counting
	setflag FLAG_SYS_B_DASH
	setvar VAR_TEST_STEP, 0
	setvar VAR_HOW_MANY_STEPS, 25
	msgbox gText_StepStart, MSGBOX_DEFAULT
	release
	end

EventScript_StepStop::
	clearflag FLAG_TEST_STEP
	setflag FLAG_TOO_HUNGRY
	@buffernumberstring STR_VAR_1, VAR_TEST_STEP
	@msgbox gText_StepStop, MSGBOX_DEFAULT
	msgbox gText_Too_Hungry, MSGBOX_AUTOCLOSE
	release
	end

gText_Too_Hungry::
	.string "Too hungry to run...$"

gText_StepStart::
	.string "10k a day keeps the doctor away!$"

gText_StepStop::
	.string "Was that 10k or {STR_VAR_1}?$"
