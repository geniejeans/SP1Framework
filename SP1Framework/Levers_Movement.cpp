#include "Levers_Movement.h"

extern bool  g_abKeyPressed[K_COUNT];


void leversMovement_HS()
{
	
	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;
	
	charColor = 0x0B;
	
	// Updating the location of the character based on the key press
	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)219) // WALL COLLISION
		{
			if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)186) // DOOR COLLISION
			{
				if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != '0') // SWITCH COLLISION
				{
					if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != '1') // SWITCH COLLISION
					{
						// SPIKES
						if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == '+')
						{
							*changeHealth -= 1;
							g_sChar.m_cLocation.Y--;
							charColor = 0x0C;
							bSomethingHappened = true;
						}
	                    // NORMAL WALKING
						else
						{
							g_sChar.m_cLocation.Y--;
							bSomethingHappened = true;
						}
					}
				}
			}
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] != (char)219) // WALL COLLISION
		{
			if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] != (char)186) // DOOR COLLISION
			{
				if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] != '0') // SPIKES COLLISION
				{
					if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] != '1') //SPIKES COLLISION
					{
						// SPIKES
						if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] == '+')
						{
							*changeHealth -= 1;
							g_sChar.m_cLocation.X--;
							charColor = 0x0C;
							bSomethingHappened = true;
						}
						else
						{
							g_sChar.m_cLocation.X--;
							bSomethingHappened = true;
						}
					}
				}
			}
		}
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)219) // WALL COLLISION
		{
			if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)186) // DOOR COLLISION
			{
				if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != '0') // SWITCH COLLISION
				{
					if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != '1') // SWITCH COLLISION
					{
						// SPIKES
						if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == '+')
						{
							*changeHealth -= 1;
							g_sChar.m_cLocation.Y++;
							charColor = 0x0C;
							bSomethingHappened = true;
						}
						// NORMAL WALKING
						else
						{
							g_sChar.m_cLocation.Y++;
							bSomethingHappened = true;
						}
					}
				}
			}
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] != (char)219) // WALL COLLISION
		{
			if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] != (char)186) // DOOR COLLISION
			{
				if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] != '0') //SWITCH COLLISION
				{
					if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] != '1') // SWITCH COLLISION
					{
						// SPIKES
						if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] == '+')
						{
							*changeHealth -= 1;
							g_sChar.m_cLocation.X++;
							charColor = 0x0C;
							bSomethingHappened = true;
						}
						// NORMAL WALKING
						else
						{
							g_sChar.m_cLocation.X++;
							bSomethingHappened = true;
						}
					}
				}
			}
		}
	}
	if (g_abKeyPressed[K_SPACE])
	{
		g_dBounceTime = g_dElapsedTime + 0.280;
		/*--------------------- THIS IS FOR SWITCH. ALL FOUR DIRECTIONS INCLUDED-----------------------------------------------------*/
		if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] == (char)48) //right
		{
			map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] = (char)49;
		}
		else if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] == (char)49) //right
		{
			map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] = (char)48;
		}
		else if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] == (char)48) //left
		{
			map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] = (char)49;
		}
		else if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] == (char)49) //left
		{
			map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] = (char)48;
		}
		else if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)48) //down
		{
			map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = (char)49;
		}
		else if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)49) //down
		{
			map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = (char)48;
		}
		else if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)48) //up
		{
			map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = (char)49;
		}
		else if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)49) //up
		{
			map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = (char)48;
		}

		bSomethingHappened = true;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
	if (*changeHealth == 0)
	{
		resetLevel();
	}
}