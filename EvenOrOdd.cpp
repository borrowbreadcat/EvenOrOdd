// EvenOrOdd learncppChap3_2Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>		// `cout <<` and `cin >>`
#include <cmath>		// `pow()` and `sqrt()`

#include "ioProtocol.h"	// this should help include my userYesNo function?

using namespace std;	// allows writing `cout << endl;` instead of `std::cout << std::endl;`

//slash screen on startup. incl version history and quick description
void splash()
{
	cout << "This is part of the borrowbreadcat C++ training effort. \n";
	cout << "This program contains assorted practice funtions, helping me familiarize myself with C++. \n";
	cout << "\n \t VERSION HISTORY \n";
	cout << "\t v20180722.1 \n\n";
	cout << "I'm always happy to share, so thanks for poking around!  Have fun! \n\n";
}

//practicing some new concepts
void testMath()
{
	constexpr int defaultValue{ 2 };		//use constexpr for magic number to ease potential future edits
	int valueArr[10];						//use array for a list of related variables

	for (int x{ 0 }; x<10 ; x++)			//for this variable x, while x is < 10, do the body, then x+1 and repeat
	{
		valueArr[x] = defaultValue;			//applies defaultValue to every element in valueArr
		cout << "Array element # " << x << " = " << valueArr[x] << "\n";  
	}

	cout << "\n pow (9.0,2.0) = " << pow(9.0, 2.0) << "\n"; //checking which is exponent and which is base.
	cout << " pow (2.0,9.0) = " << pow(2.0, 9.0) << "\n";
	
}

bool isEven(int inquiry)
{
	bool itIsEven{ 0 };
	if (inquiry % 2 == 0)
	{
		cout << "When we divide " << inquiry << " by 2, we get a nice, smooth zero. Therefore...\n";
		itIsEven = 1;
	}
	else if (inquiry % 2 != 0)
	{
		cout << "Looks like " << inquiry << " is not cleanly divisible by two, so...\n";
		itIsEven = 0;
	}
	else
	{
		cout << "This is an error message you should mathelogically never see. Congrats on your epic fail.\n";
	}
	return itIsEven;
}

//learncpp.com asked me to write a program that determines if a user-given integer is even or odd.
void learncppCh3_2Quiz()
{
	cout << "\nlearncpp.com asked me to write a program that determines if a user-given integer is even or odd. \n";
	cout << "so this is where you come in.  Yes, YOU...\n";

	bool repeat{ true };
	while ( repeat == true )
	{
		cout << "please type in an integer.\n\n";
		cout << "MY INTEGER IS ... ";
		int usersInt{ 0 };
		cin >> usersInt;
		cout << "\n\nAlright, let's check to see if " << usersInt << " is even or odd.\n\n";
		bool isItEven{ isEven(usersInt) };
		if (isItEven)
		{
			cout << "Yes, " << usersInt << " is an even number.  I win!\n";
		}
		else if (!isItEven)
		{
			cout << "No, " << usersInt << " is not even.  It is an odd number.  That means you lose. boo for you.\n";
		}

		cout << "\nDo you wanna check if another integer is even or odd?\n";
		repeat = userYesNo();
	}
}

int main()
{
	bool fromTheTop{ true };
	while (fromTheTop )
	{
		splash();
		testMath();
		learncppCh3_2Quiz();

		cout << "Would you like to restart the program from the top?\n";
		fromTheTop = userYesNo();
	}
    return 0;
}

