EventScript_Hunger::
    setvar VAR_HUNGER_COUNT, 50
    releaseall
    end






EventScript_StepStart::
	setflag FLAG_SYS_B_DASH
	setvar VAR_HOW_MANY_STEPS, 25
    buffernumberstring STR_VAR_1, VAR_HOW_MANY_STEPS
	msgbox gText_StepStart, MSGBOX_DEFAULT
	release
	end

EventScript_StepStop::
	lockall
	setflag FLAG_TOO_HUNGRY
	msgbox gText_StepStop, MSGBOX_DEFAULT
	@msgbox gText_Too_Hungry, MSGBOX_AUTOCLOSE
	release
	end

gText_Too_Hungry::
	.string "Too hungry to run...$"

gText_StepStart::
	.string "10k a day keeps the doctor away!$"

gText_StepStop::
	.string "Was that 10k or {STR_VAR_1}?$"
