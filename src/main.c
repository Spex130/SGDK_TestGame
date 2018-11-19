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

	JOY_init();
	JOY_setEventHandler( &myJoyHandler );
	VDP_setTextPalette(0);
    VDP_setPaletteColor(0, 0x0882);
	VDP_drawText("Hello World! - Genesis 2018", 10, 13);

	u16 value;

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


