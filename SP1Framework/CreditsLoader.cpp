#include "CreditsLoader.h"

void loadCredits(int SceneNum, char credits[600][150])
{
	string filename = " "; // store file location

	switch (SceneNum) // open file location
	{
		case 1:
			filename = "Maps_Text/Credits/Title.txt";
			break;
	}

	string line = " "; // use for storing
	memset(credits, '\0', sizeof(credits[0][0]) * 500 * 150); // initializing array

	ifstream myfile(filename);
	int row = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			for (unsigned int i = 0; i <= line.length(); i++)
			{
				credits[row][i] = line[i]; //Store to array
			}
			row++;
		}
		myfile.close(); //Close file
	}
	else
	{
		cout << "file cannot be opened" << endl;
	}
}