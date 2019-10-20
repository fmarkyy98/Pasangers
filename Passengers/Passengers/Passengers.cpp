#include <iostream>
#include <strstream>
using namespace std;

const int MAX_N = 100;
int buses[MAX_N];

string stringJoin(int* array, unsigned int arrayLength, string separator = " ")
{
	strstream result;
	result << "";
	if (arrayLength != 0)
	{
		result << array[0];
		for (int i = 1; i < arrayLength; ++i)
		{
			result << separator << array[i];
		}
	}
	result << '\0';
	string resultStr = result.str();
	return resultStr;
}

int main()
{
	int busesLength;
	int busSize;

	cin >> busesLength >> busSize;
	for (int i = 0; i < busesLength; ++i)
	{
		cin >> buses[i];
	}

	int busesManyPassenger[MAX_N];
	int busesManyPassengerLength = 0;

	int busesFewPassenger[MAX_N];
	int busesFewPassengerLength = 0;

	double manyPassengerValue = 0.8 * busSize;
	double fewPassengerValue = 0.2 * busSize;

	for (int i = 0; i < busesLength; i++)
	{
		if (buses[i] > manyPassengerValue)
		{
			busesManyPassenger[busesManyPassengerLength] = i + 1;
			++busesManyPassengerLength;
		}
		else if (buses[i] < fewPassengerValue)
		{
			busesFewPassenger[busesFewPassengerLength] = i + 1;
			++busesFewPassengerLength;
		}
	}
	cout << busesManyPassengerLength << " " << stringJoin(busesManyPassenger, busesManyPassengerLength) << endl;
	cout << busesFewPassengerLength << " " << stringJoin(busesFewPassenger, busesFewPassengerLength) << endl;
}
