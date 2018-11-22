#include <genesis.h>

#include "sprite.h"

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		if (state & BUTTON_START)
		{
			//player 1 press START button
			VDP_setTextPalette(1);
			VDP_drawText("Player Pressed Start", 10, 14);
		}
		else if (changed & BUTTON_START)
		{
			//player 1 released START button
			VDP_setTextPalette(0);
			VDP_drawText("Player Pressed Start", 10, 14);
		}
	}	
}

int main()
{
	u16 palette[64];
    u16 ind;

	// disable interrupt when accessing VDP
    SYS_disableInts();
    // initialization
    VDP_setScreenWidth320();

	// init sprites engine
    SPR_init(16, 256, 256);

    // set all palette to black
    VDP_setPaletteColors(0, (u16*) palette_black, 64);

	// VDP process done, we can re enable interrupts
    SYS_enableInts();

	JOY_init();
	JOY_setEventHandler( &myJoyHandler );
	VDP_setTextPalette(0);
    VDP_setPaletteColor(0, 0x0882);
	VDP_drawText("Hello World! - Genesis 2018", 10, 13);

	u16 value;

    sprites[0] = SPR_addSprite(&dungeon_tiles, 10, 10, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));


	while(1)
	{
		//read input
		if(BUTTON_START){VDP_drawText("Player Pressed Start", 10, 14);}
		//move sprite
		//update score
		//draw current screen (logo, start screen, settings, game, gameover, credits...)

		//wait for screen refresh
		VDP_waitVSync();
	}
	return (0);
}


