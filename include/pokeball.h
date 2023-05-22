#ifndef GUARD_POKEBALL_H
#define GUARD_POKEBALL_H

enum BallGraphics{
    BALL_POKE,
    BALL_GREAT,
    BALL_SAFARI,
    BALL_ULTRA,
    BALL_MASTER,
    BALL_NET,
    BALL_DIVE,
    BALL_NEST,
    BALL_REPEAT,
    BALL_TIMER,
    BALL_LUXURY,
    BALL_PREMIER,
    BALL_LEVEL,
    BALL_LURE,
    BALL_MOON,
    BALL_FRIEND,
    BALL_LOVE,
    BALL_FAST,
    BALL_HEAVY,
    BALL_ZOO,
    POKEBALL_COUNT
};

enum {
    BALL_AFFINE_ANIM_0,
    BALL_ROTATE_RIGHT,
    BALL_ROTATE_LEFT,
    BALL_AFFINE_ANIM_3,
    BALL_AFFINE_ANIM_4
};

//#define IS_ITEM_BALL(x) ((x) <= ITEM_PREMIER_BALL || ((x) >= ITEM_LEVEL_BALL && (x) <= ITEM_ZOO_BALL))
//#define ITEM_ID_TO_BALL_ID(x) (((x) >= ITEM_LEVEL_BALL && (x) <= ITEM_ZOO_BALL) ? (((x) - ITEM_LEVEL_BALL) + BALL_LEVEL) : (x))
#define IS_ITEM_BALL(x) (ItemId_GetPocket(x) == POCKET_POKE_BALLS)
#define ITEM_ID_TO_BALL_ID(x) ((ItemId_GetPocket(x) == POCKET_POKE_BALLS) ? ItemId_GetSecondaryId(x) : (x))

extern const struct CompressedSpriteSheet gBallSpriteSheets[];
extern const struct CompressedSpritePalette gBallSpritePalettes[];
extern const struct SpriteTemplate gBallSpriteTemplates[];

#define POKEBALL_PLAYER_SENDOUT     0xFF
#define POKEBALL_OPPONENT_SENDOUT   0xFE

u8 DoPokeballSendOutAnimation(s16 pan, u8 kindOfThrow);
void CreatePokeballSpriteToReleaseMon(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subpriortiy, u8 delay, u32 fadePalettes, u16 species);
u8 CreateTradePokeballSprite(u8 monSpriteId, u8 monPalNum, u8 x, u8 y, u8 oamPriority, u8 subPriority, u8 delay, u32 fadePalettes);
void StartHealthboxSlideIn(u8 battler);
void DoHitAnimHealthboxEffect(u8 battler);
void LoadBallGfx(u8 ballId);
void FreeBallGfx(u8 ballId);

#endif // GUARD_POKEBALL_H
