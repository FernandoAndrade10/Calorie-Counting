//Fernando Andrade
//Advant of Code 2021
//Day 1: Calorie Counting

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getTopThreeSums(int calorieCount[], int size, int max) {
	int max2 = 0;
	int max3 = 0;
	int maxTotal = 0;

	//Finding elf with 2nd highest total count
	for (int i = 0; i < size; i++)
	{
		if (calorieCount[i] > max2 && calorieCount[i] < max)
		{
			max2 = calorieCount[i];
		}
	}

	//Finding elf with 3rd highest total count
	for (int i = 0; i < size; i++)
	{
		if (calorieCount[i] > max3 && calorieCount[i] < max2)
		{
			max3 = calorieCount[i];
		}
	}

	maxTotal = max + max2 + max3;

	return maxTotal;
}

int getHighestSum(int calorieCount[], int size) {
	int max = 0;

	//Finding elf with highest total count
	for (int i = 0; i < size; i++)
	{
		if (calorieCount[i] > max)
		{
			max = calorieCount[i];
		}
	}
	
	return max;
}

int main() {
	ifstream in;
	in.open("calories.txt");

	int arr[1000] = {};
	int element = 0;
	int size = 0;
	string line;

	int calories[1000] = {};
	int sum = 0;
	int resultSize = 0;
	int k = 0;
	int max = 0;

	if (in.is_open())
	{
		int i = 0;
		

		while (getline(in, line))
		{
			//Store a set of calorie counts from the text file
			if (!line.empty())
			{
				arr[i++] = stoi(line);
				size++;
			}
			//Store the sum of the previous calorie count into a new array
			else
			{
				for (int j = 0; j < size; j++)
				{
					sum += arr[j];
				}

				calories[k] = sum;
				k++;
				sum = 0;
				size = 0;
				i = 0;
				resultSize++;
			}

			
		}
	}

	//At the eof the last data set does not get stored
	//So it gets stored here instead
	for (int j = 0; j < size; j++)
	{
		sum += arr[j];
	}

	calories[k] = sum;
	resultSize++;

	max = getHighestSum(calories, resultSize);

	cout << "Elf with the highest calorie count has a total of " << max << " calories" << endl;
	cout << "Top 3 elves with the combined highest calorie count is " << getTopThreeSums(calories,resultSize,max) << " calories" << endl;

	return 0;
}