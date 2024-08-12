#ifndef GUARD_EVOLUTION_SCENE_H
#define GUARD_EVOLUTION_SCENE_H

void BeginEvolutionScene(struct Pokemon *mon, u16 speciesToEvolve, bool8 canStopEvo, u8 partyID);
void EvolutionScene(struct Pokemon *mon, u16 speciesToEvolve, bool8 canStopEvo, u8 partyID);
void TradeEvolutionScene(struct Pokemon *mon, u16 speciesToEvolve, u8 preEvoSpriteID, u8 partyID);

void FindPartyFuseMons(bool32 *PartyFuseMons, u32 species, u32 monIndex);
#define COMBO_NOT_READY NUM_SPECIES

extern void (*gCB2_AfterEvolution)(void);

#endif // GUARD_EVOLUTION_SCENE_H
