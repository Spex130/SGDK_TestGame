#include <genesis.h>

void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	if (joy == JOY_1)
	{
		if (state & BUTTON_START)
		{
			//player 1 press START button
		}
		else if (changed & BUTTON_START)
		{
			//player 1 released START button	
		}
	}	
}

int main()
{

	JOY_init();
	JOY_setEventHandler( &myJoyHandler );
	VDP_drawText("Hello World! - Genesis 2018", 10, 13);

	u16 value;

	while(1)
	{
		//read input
		value = JOY_readJoypad(JOY_1);

		if(value & BUTTON_START)
		{
			VDP_drawText("Player Pressed Start", 10, 14);
		}
		//move sprite
		//update score
		//draw current screen (logo, start screen, settings, game, gameover, credits...)

		//wait for screen refresh
		VDP_waitVSync();
	}
	return (0);
}


