//Skynet HK-Aerial Software
//Programmer: Jacquelynne Heiman
// January 21st, 2019
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;


int binarySearch(int grid[], int min, int middle, int max, int hostile_position, int ping);

int main()
{
	//generating a psudorandom number
	srand(time(0));

	// this is the array that holds the grid sectors 1 - 64
	int grid[] = {
			1,  2,  3,  4,  5,  6,  7,  8,
			9,  10, 11, 12, 13, 14, 15, 16,
			17, 18, 19, 20, 21, 22, 23, 24,
			25, 26, 27, 28, 29, 30, 31, 32,
			33, 34, 35, 36, 37, 38, 39, 40,
			41, 42, 43, 44, 45, 46, 47, 48,
			49, 50, 51, 52, 53, 54, 55, 56,
			57, 58, 59, 60, 61, 62, 63, 64
	};


	//min is the lowest the number that the program can search for, it is set to 0 since there are no indexes below 0
	int min = 0;
	//max is the highest number the program can search for
	//it is getting the number of elements in the array
	int max = (sizeof(grid) / sizeof(*grid));

	//setting the hostile position to a random position on the grid
		//I do this by taking the modulus of the number of elements in the grid, which max is set to.
	int hostile_position = rand() % max;

	//Since we are doing a binary search we want to check if the number we are looking for is in the center of elements
	//so our guess is the middle to find the middle you add the min and max values and divide by two
	int middle = ((max - min) / 2) + min;
	//This is the number of tries the program used to find the hostile position
	int ping = 1;

	
	
	
}



int binarySearch(int grid, int min, int max, int middle, int hostile_position, int ping)
{
	


	cout << "Generate a random enemy location on a 8x8 grid..." << endl;
	cout << "The enemy is located at grid #" << hostile_position << " on 8x8 grid with 1 - 64 sectors." << endl;
	cout << "Skynet HK-Aerial Initializing software..." << endl;
	cout << "=================================================================================== " << endl;

	//While the min number is less than or equal to the max number do the following:
	while (min <= max)
	{
		if (middle == hostile_position) //if the middle number (the computers guess) is equal to the position our hostile is in
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << ping << endl;
			cout << "Enemy was found hiding in location #" << middle << "." << endl;
			cout << "Target was neutralized at loction #" << middle << "." << endl;
			min = max + 1; // set the min number to one more than the max number to quit the while loop

		}
		else if (middle < hostile_position) // or if the middle (the computers guess) is less than the location of our hostile
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << ping << endl;
			cout << "The target location prediction of " << middle << " was lower than the actual enemy location of " << hostile_position << "." << endl;
			cout << "=================================================================================== " << endl;
			ping++; // increment the ping number because the computer did not guess right so we have to try again
			min = middle + 1; //reset the min to the middle + 1 so view a new section of our grid
			middle = ((max - min) / 2) + min; // reset the middle based off the new min value


		}
		else // otherwise
		{
			cout << "Skynet HK-Aerial Radar sending out ping #" << ping << endl;
			cout << "The target location prediction of " << middle << " was higher than the actual enemy location of " << hostile_position << "." << endl;
			cout << "=================================================================================== " << endl;
			ping++; // increase the ping number by 1 because the computer did not guess right so we have to try again
			max = middle - 1; // set the new max value to the middle minus one to view a new part of the grid
			middle = ((max - min) / 2) + min; //reset the middle based off the new max value
		}
	}

	cout << "Skynet HK-Aerial Software took " << ping << " predictions to find the enemy location on a grid size of 8x8 (64)." << endl;

	

	system("pause"); //pause the program so the user can read the output, to continue the user will provide any input on the keyboard

	return 0;


}

