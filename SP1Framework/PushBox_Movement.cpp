#include "PushBox_Movement.h"

extern bool  g_abKeyPressed[K_COUNT];

void pushBoxMovement_J()
{

	bool bSomethingHappened = false;
	if (g_dBounceTime > g_dElapsedTime)
		return;

	// Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
	if (g_abKeyPressed[K_UP] && g_sChar.m_cLocation.Y > 0)
	{
		if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)219)
		{
			if (map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)186) //'D'
			{
				if ((map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y - 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)219))
				{
					if (map[(g_sChar.m_cLocation.Y - 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)186)
					{
						g_sChar.m_cLocation.Y = g_sChar.m_cLocation.Y;
						bSomethingHappened = true;
					}
					else
					{
						map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = ' ';
						map[(g_sChar.m_cLocation.Y - 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = (char)254;
						g_sChar.m_cLocation.Y--;
						bSomethingHappened = true;
					}
				}
				else if ((map[(g_sChar.m_cLocation.Y - 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y - 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)219))
				{
					g_sChar.m_cLocation.Y = g_sChar.m_cLocation.Y;
					bSomethingHappened = true;
				}
				else
				{
					g_sChar.m_cLocation.Y--;
					bSomethingHappened = true;
				}
			}

			//Beep(1440, 30);
			//g_sChar.m_cLocation.Y--;
			//bSomethingHappened = true;
		}

	}
	if (g_abKeyPressed[K_LEFT] && g_sChar.m_cLocation.X > 0)
	{
		if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] != (char)219)
		{
			if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] != (char)186)
			{
				if ((map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 2) - (90 - mapSizeWidth)] != (char)219))
				{
					if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 2) - (90 - mapSizeWidth)] == (char)186)
					{
						g_sChar.m_cLocation.X = g_sChar.m_cLocation.X;
						bSomethingHappened = true;
					}
					else
					{
						map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] = ' ';
						map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 2) - (90 - mapSizeWidth)] = (char)254;
						g_sChar.m_cLocation.X--;
						bSomethingHappened = true;
					}

				}
				else if ((map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 1) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X - 2) - (90 - mapSizeWidth)] == (char)219))
				{
					g_sChar.m_cLocation.X = g_sChar.m_cLocation.X;
					bSomethingHappened = true;
				}
				else
				{
					g_sChar.m_cLocation.X--;
					bSomethingHappened = true;
				}
			}

			//Beep(1440, 30);
			//g_sChar.m_cLocation.X--;
			//bSomethingHappened = true;
		}
	}
	if (g_abKeyPressed[K_DOWN] && g_sChar.m_cLocation.Y < g_Console.getConsoleSize().Y - 1)
	{
		if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)219)
		{
			if (map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)186)
			{
				if ((map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y + 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] != (char)219))
				{
					if (map[(g_sChar.m_cLocation.Y + 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)186)
					{
						g_sChar.m_cLocation.Y = g_sChar.m_cLocation.Y;
						bSomethingHappened = true;
					}
					else
					{
						map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = ' ';
						map[(g_sChar.m_cLocation.Y + 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] = (char)254;
						g_sChar.m_cLocation.Y++;
						bSomethingHappened = true;
					}

				}
				else if ((map[(g_sChar.m_cLocation.Y + 1) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y + 2) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X) - (90 - mapSizeWidth)] == (char)219))
				{
					g_sChar.m_cLocation.Y = g_sChar.m_cLocation.Y;
					bSomethingHappened = true;
				}
				else
				{
					g_sChar.m_cLocation.Y++;
					bSomethingHappened = true;
				}
			}

			//Beep(1440, 30);
			//g_sChar.m_cLocation.Y++;
			//bSomethingHappened = true;
		}
	}
	if (g_abKeyPressed[K_RIGHT] && g_sChar.m_cLocation.X < g_Console.getConsoleSize().X - 1)
	{
		if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] != (char)219)
		{
			if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] != (char)186)
			{
				if ((map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 2) - (90 - mapSizeWidth)] != (char)219)) //if there is a block and nothing is blocking it
				{
					if (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 2) - (90 - mapSizeWidth)] == (char)186)
					{
						g_sChar.m_cLocation.X = g_sChar.m_cLocation.X;
						bSomethingHappened = true;
					}
					else
					{
						map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] = ' ';
						map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 2) - (90 - mapSizeWidth)] = (char)254;
						g_sChar.m_cLocation.X++;
						bSomethingHappened = true;
					}
				}
				else if ((map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 1) - (90 - mapSizeWidth)] == (char)254) && (map[(g_sChar.m_cLocation.Y) - (25 - mapSizeHeight)][(g_sChar.m_cLocation.X + 2) - (90 - mapSizeWidth)] == (char)219)) //if something is blocking the block 
				{
					g_sChar.m_cLocation.X = g_sChar.m_cLocation.X;
					bSomethingHappened = true;
				}
				else
				{
					g_sChar.m_cLocation.X++;
					bSomethingHappened = true;
				}
			}
			//Beep(1440, 30);
			//g_sChar.m_cLocation.X++;
			//bSomethingHappened = true;
		}
	}
	if (g_abKeyPressed[K_SPACE])
	{
		g_sChar.m_bActive = !g_sChar.m_bActive;
		bSomethingHappened = true;
	}

	if (bSomethingHappened)
	{
		// set the bounce time to some time in the future to prevent accidental triggers
		g_dBounceTime = g_dElapsedTime + 0.125; // 125ms should be enough
	}
}