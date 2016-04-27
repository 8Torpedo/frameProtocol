#include <stdlib.h>
#include <stdio.h>

/*
Data protocol program. Data is modified by parameters putted by user in console.
Firs parameter is command. If command is 1, we turn camera on , if it is 0 we turn camera off .
Second parameter is camera adress. We have 4 cameras witch are adressed : 0 , 1 , 2 , 3.
There are four informations in one frame: command, cameraAdrr, state, checkSum.
Without parameters program is shutting down all cameras.
*/

int main(int argc, char *argv[])
{
	char frame[4];
	char cameraAdrr[4] = { '0' , '1', '2', '3' };
	char checkSum;
	int j = 0; 
	
	int cmd; // It contains a command from console
	int i; // It contains a index witch we using to get the right camera adress
	
	char state;
	char command;

	
	if (argc >= 3)
	{
		cmd = atoi(argv[1]);

		/*
		Checking command. If it is wrong program will ask for correction*/
		while ((cmd != 1) && (cmd != 0))
		{
			puts("Wrong command. Try 1 to ON and 0 to OFF.");
			scanf_s("%d", &cmd);
		}

		/*
		Seting a camera state basesd on command*/
		if (cmd == 1)
		{
			state = '1';
		}
		else
		{
			state = '0';
		}

		i = atoi(argv[2]);

		/*
		Checking index of the table with camera adresses. If it is wrong program 
		will ask for correction*/
		while ((i<0) || (i>3))
		{
			puts("This number is not available. Try numbers between 0-3");
			scanf_s("%d", &i);
		}
		
		command = (char)cmd;
		checkSum = cameraAdrr[i] + command + state -48; // 48 in decimal is 0 in char

		/*
		Putting data to our data frame.*/
		frame[0] = command + 48; 
		frame[1] = cameraAdrr[i];
		frame[2] = state;
		frame[3] = checkSum;

		puts("Char format: ");
		for (j = 0; j <= 3; j++)
		{
			printf("%c ", frame[j]);
		}

		puts("\nHex format: ");
		for (j = 0; j <= 3; j++)
		{
			printf("%#x ", frame[j]);
		}

	}

	/*
	If we don't have parameters from console*/
	else
	{
		/*
		Shutting down all cameras*/
		state = '0';
		command = '0';
		for (i; i <= 3; i++)
		{
			checkSum = cameraAdrr[i] + command + state -96 ;
			frame[0] = command;
			frame[1] = cameraAdrr[i];
			frame[2] = state;
			frame[3] = checkSum;

			puts("Char format: ");
			for (j = 0; j <= 3; j++)
			{
				printf("%c ", frame[j]);
			}

			puts("Hex format: ");
			for (j = 0; j <= 3; j++)
			{
				printf("%#x ", frame[j]);
			}
		}
	}

	return 0;
}