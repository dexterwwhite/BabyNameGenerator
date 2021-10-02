#include <iostream>
#include <random>
#include "BabyNames.h"

using std::cout, std::endl, std::string;

string getConsonant(int rand)
{
	if(rand == 0)
		return "b";
	else if(rand == 1)
		return "c";
	else if(rand == 2)
		return "d";
	else if(rand == 3)
		return "f";
	else if(rand == 4)
		return "g";
	else if(rand == 5)
		return "h";
	else if(rand == 6)
		return "j";
	else if(rand == 7)
		return "k";
	else if(rand == 8)
		return "l";
	else if(rand == 9)
		return "m";
	else if(rand == 10)
		return "n";
	else if(rand == 11)
		return "p";
	else if(rand == 12)
		return "q";
	else if(rand == 13)
		return "r";
	else if(rand == 14)
		return "s";
	else if(rand == 15)
		return "t";
	else if(rand == 16)
		return "v";
	else if(rand == 17)
		return "w";
	else if(rand == 18)
		return "x";
	else if(rand == 19)
		return "y";
	else if(rand == 20)
		return "z";
	return "";
}

string getVowel(int rand)
{
	if(rand == 0)
		return "a";
	else if(rand == 1)
		return "e";
	else if(rand == 2)
		return "i";
	else if(rand == 3)
		return "o";
	else if(rand == 4)
		return "u";
	else if(rand == 5)
		return "y";
}

unsigned int getLength(int rand)
{
	if(rand == 0)
		return 3;
	else if(rand == 1 || rand == 2)
		return 4;
	else if(rand == 3 || rand == 4 || rand == 5)
		return 5;
	else if(rand == 6 || rand == 7 || rand == 8)
		return 6;
	else if(rand == 9 || rand == 10)
		return 7;
	else if(rand == 11 || rand == 12)
		return 8;
	else if(rand == 13)
		return 9;
	else if(rand == 14)
		return 10;
	return 6;
}

string generateName()
{
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> length(0, 14);
	std::uniform_int_distribution<std::mt19937::result_type> cons(0, 20);
	std::uniform_int_distribution<std::mt19937::result_type> vowels(0, 5);
	std::uniform_int_distribution<std::mt19937::result_type> position(0, 7);
	
	unsigned int vowelStart = position(rng);
	unsigned int nameSize = getLength(length(rng));
	string name = "";
	if(vowelStart == 0 || vowelStart == 1 || vowelStart == 2 || vowelStart == 3)
	{
		for(unsigned int i = 0; i < nameSize; i++)
		{
			if(i % 2 == 0)
				name = name + getVowel(vowels(rng));
			else
				name = name + getConsonant(cons(rng));
		}
	}
	else
	{
		for(unsigned int i = 0; i < nameSize; i++)
		{
			if(i % 2 == 1)
				name = name + getVowel(vowels(rng));
			else
				name = name + getConsonant(cons(rng));
		}
	}
	string caps = "";
	caps = toupper(name.at(0));
	name.replace(0, 1, caps);
	return name;
}