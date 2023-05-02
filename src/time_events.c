#include "global.h"
#include "time_events.h"
#include "event_data.h"
#include "field_weather.h"
#include "pokemon.h"
#include "random.h"
#include "overworld.h"
#include "rtc.h"
#include "script.h"
#include "task.h"

static u32 GetMirageRnd(void)
{
    u32 hi = VarGet(VAR_MIRAGE_RND_H);
    u32 lo = VarGet(VAR_MIRAGE_RND_L);
    return (hi << 16) | lo;
}

static void SetMirageRnd(u32 rnd)
{
    VarSet(VAR_MIRAGE_RND_H, rnd >> 16);
    VarSet(VAR_MIRAGE_RND_L, rnd);
}

// unused
void InitMirageRnd(void)
{
    SetMirageRnd((Random() << 16) | Random());
}

void UpdateMirageRnd(u16 days)
{
    s32 rnd = GetMirageRnd();
    while (days)
    {
        rnd = ISO_RANDOMIZE2(rnd);
        days--;
    }
    SetMirageRnd(rnd);
}

bool8 IsMirageIslandPresent(void)
{
    u16 rnd = GetMirageRnd() >> 16;
    int i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) && (GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY) & 0xFFFF) == rnd)
            return TRUE;

    return FALSE;
}

void UpdateShoalTideFlag(void)
{
    static const u8 tide[] =
    {
        1, // 00
        1, // 01
        1, // 02
        0, // 03
        0, // 04
        0, // 05
        0, // 06
        0, // 07
        0, // 08
        1, // 09
        1, // 10
        1, // 11
        1, // 12
        1, // 13
        1, // 14
        0, // 15
        0, // 16
        0, // 17
        0, // 18
        0, // 19
        0, // 20
        1, // 21
        1, // 22
        1, // 23
    };

    if (IsMapTypeOutdoors(GetLastUsedWarpMapType()))
    {
        RtcCalcLocalTime();
        if (tide[gLocalTime.hours])
            FlagSet(FLAG_SYS_SHOAL_TIDE);
        else
            FlagClear(FLAG_SYS_SHOAL_TIDE);
    }
}

static void Task_WaitWeather(u8 taskId)
{
    if (IsWeatherChangeComplete())
    {
        ScriptContext_Enable();
        DestroyTask(taskId);
    }
}

void WaitWeather(void)
{
    CreateTask(Task_WaitWeather, 80);
}

void InitBirchState(void)
{
    *GetVarPointer(VAR_BIRCH_STATE) = 0;
}

void UpdateBirchState(u16 days)
{
    u16 *state = GetVarPointer(VAR_BIRCH_STATE);
    *state += days;
    *state %= 7;
}

bool32 IsMoonPhase(enum MoonPhase phase){
    //built using omnicalculator.com/everyday-life/moon-phase "How to calculate the Moon phase?"    
    u32 days;
    u32 lunar_day;
    u32 syn_month = 42524; //average moon cycle period (min; days = 29.53058770576 rounded to 29.530555)
    struct SiiRtcInfo *rtc;

    days = RtcGetDayCount(rtc) - ConvertDateToDayCount(2000,1,6); //Reference day
    days /= 24 / 60;
    lunar_day = (days % syn_month) * syn_month; //this was changed to mins due to gba not liking floats
    if (lunar_day > syn_month)
        lunar_day = syn_month;

    switch (phase){
    case NEW_MOON:
        if (0 < lunar_day && lunar_day <= 1440 || 41084 < lunar_day && lunar_day <= syn_month)
            return TRUE;
        break;
    case WAX_CRES:
        if (1440 < lunar_day && lunar_day <= 9191)
            return TRUE;
        break;
    case FIRST_QTR:
        if (9191 < lunar_day && lunar_day <= 12071)
            return TRUE;    
        break;
    case WAX_GIB:
        if (12071 < lunar_day && lunar_day <= 19822)
            return TRUE;
        break;
    case FULL_MOON:
        if (19822 < lunar_day && lunar_day <= 22702)
            return TRUE;
        break;
    case WAN_GIB:
        if (22702 < lunar_day && lunar_day <= 30453)
            return TRUE;
        break;
    case LAST_QTR:
        if (30453 < lunar_day && lunar_day <= 33333)
            return TRUE;
        break;
    case WAN_CRES:
        if (33333 < lunar_day && lunar_day <= 41084)
            return TRUE;
        break;
    }

    return FALSE;
}
