#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "video.h"

/**
 * Defines the background control.
 */

typedef u16 ScreenEntry;

typedef struct {
    u32 data[8];
} Tile;

typedef struct {
    s16 x, y;
} ALIGN(4) BackgroundPoint;

typedef ScreenEntry ScreenBlock[1024];
typedef Tile CharBlock[512];

#define MEMORY_BACKGROUND_PALETTE ((Color*)MEMORY_PALETTE)
#define MEMORY_BACKGROUND_PALETTE_SIZE 0x00200

#define MEMORY_SCREEN_BLOCK       ((ScreenBlock*)MEMORY_VIDEORAM)
#define MEMORY_CHAR_BLOCK         ((CharBlock*)MEMORY_VIDEORAM)

#define REGISTER_BACKGROUND_CONTROL ((vu16*)(REGISTER_BASE+0x0008))
#define REGISTER_BACKGROUND_OFFSET  ((BackgroundPoint*)(REGISTER_BASE+0x0010))

#define FLAG_BACKGROUND_4BPP		  0
#define FLAG_BACKGROUND_8BPP          0x0080
#define FLAG_BACKGROUND_REGULAR_32x32 0
#define FLAG_BACKGROUND_REGULAR_64x32 0x4000
#define FLAG_BACKGROUND_REGULAR_32x64 0x8000
#define FLAG_BACKGROUND_REGULAR_64x64 0xC000

#define MASK_FLAG_BACKGROUND_CHAR_BLOCK	 0x000C
#define SHIFT_FLAG_BACKGROUND_CHAR_BLOCK 2
#define FLAG_BACKGROUND_CHAR_BLOCK(n)	 ((n)<<SHIFT_FLAG_BACKGROUND_CHAR_BLOCK)

#define MASK_FLAG_BACKGROUND_SCREEN_BLOCK_MASK 0x1F00
#define SHIFT_FLAG_BACKGROUND_SCREEN_BLOCK	   8
#define FLAG_BACKGROUND_SCREEN_BLOCK(n)		   ((n)<<SHIFT_FLAG_BACKGROUND_SCREEN_BLOCK)

#define FLAG_BACKGROUND(n) ((0x0100)<<n)
#define FLAG_BACKGROUND_PRIORITY(n) ((n*1) & 0x0003)

#endif // BACKGROUND_H