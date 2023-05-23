#ifndef GUARD_TIME_EVENTS_H
#define GUARD_TIME_EVENTS_H

void UpdateMirageRnd(u16);
u8 IsMirageIslandPresent(void);
void UpdateBirchState(u16);

bool32 IsMoonPhase(u32 phase);

enum MoonPhase{
    NEW_MOON = 1,
    WAX_CRES,
    FIRST_QTR,
    WAX_GIB,
    FULL_MOON,
    WAN_GIB,
    LAST_QTR,
    WAN_CRES,
};


#endif // GUARD_TIME_EVENTS_H
