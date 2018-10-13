#include "background.h"

/**
 * Defines the sprite object control
 */

typedef struct
{
    u16 attribute0;
    u16 attribute1;
    u16 attribute2;
    s16 fill;
} ALIGN(4) SpriteObject;

#define MEMORY_OBJECT_PALETTE ((Color*)(MEMORY_PALETTE + MEMORY_BACKGROUND_PALETTE_SIZE))
#define MEMORY_SPRITE_OBJECTS ((SpriteObject*)MEMORY_OBJECT_ATTRIBUTES)

#define ATTRIBUTE0_HIDE    0x0200
#define ATTRIBUTE0_SQUARE  0
#define ATTRIBUTE0_Y_MASK  0x00FF
#define ATTRIBUTE0_Y_SHIFT 0
#define ATTRIBUTE0_Y(n)	   ((n)<<ATTRIBUTE0_Y_SHIFT)

#define ATTRIBUTE1_SIZE_64 0xC000
#define ATTRIBUTE1_X_MASK  0x01FF
#define ATTRIBUTE1_X_SHIFT 0
#define ATTRIBUTE1_X(n)	   ((n)<<ATTRIBUTE1_X_SHIFT)

#define ATTRIBUTE2_PALETTE_BANK_MASK  0xF000
#define ATTRIBUTE2_PALETTE_BANK_SHIFT 12
#define ATTRIBUTE2_PALETTE_BANK(n)    ((n)<<ATTRIBUTE2_PALETTE_BANK_SHIFT)

#define FLAG_SPRITE_OBJECTS  0x1000
#define FLAG_1D_SPRITE_SHEET 0x0040