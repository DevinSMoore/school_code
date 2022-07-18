/*******************************************************************************************
Programmer: Devin Moore
Date:       2021/03/22
Class:      CptS122 Section 10 Andrew O'Fallon
TA: Muthuu Svs
Assignment: Morse code decoder thing PA6

Description: This program is designed to take in a file with words and such and convert
			 that to it's morse code euivalent. could've added logic to split the tree
			 automagically but a) i don't get points b) i'm still playing catching up 
			 overall and getting this in early will be nice. Got those templates done
			 which is nice.
*******************************************************************************************/

#include "morseDecoder.h"

int main(void)
{
	DecodeMorse newDecoder;
	
	std::cout << "Tree printing in order: " << std::endl;
	newDecoder.getTree().printInOrder();
	std::fstream infile("Convert.txt", std::ios::in);
	if (infile.is_open())
	{
		std::cout << std::endl << "Decoded message:" << std::endl;
		newDecoder.runDecode(infile);
		putchar('\n');
	}
	return 0;
}