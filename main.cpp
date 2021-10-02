#include <iostream>
#include <random>
#include <string>
#include "BabyNames.h"

using std::cout, std::cin, std::endl, std::string;

int main()
{
	string response;
	string name;
	while(true)
	{
		cout << "Would you like to generate a name? ";
		cin >> response;
		for(char& c: response)
			c = toupper(c);
		
		if(response == "YES" || response == "YE" || response == "Y" || response == "YEAH" || response == "YEA")
		{
			name = generateName();
			cout << name << endl;
		}
		else
		{
			cout << "Alright, have a nice day!" << endl;
			break;
		}
	}
	return 0;
}