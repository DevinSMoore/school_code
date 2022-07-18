#include "mergeSort.h"
#include <iostream>

int main(void)
{
	MergeSort<int> testArray;
	testArray.getFront()[0] = 5;
	testArray.getFront()[1] = 8;
	testArray.getFront()[2] = 6;
	testArray.getFront()[3] = 5;
	testArray.getFront()[4] = 175;
	testArray.getFront()[5] = 42;
	testArray.getFront()[6] = 57673;
	testArray.getFront()[7] = 34;
	testArray.getFront()[8] = 2;

	testArray.setSize(9);

	for (int index = 0; index < testArray.getSize(); index++)
	{
		std::cout << "Item #" << index << ": " << testArray.getFront()[index] << std::endl;
	}

	std::cout << "List after test sort:" << std::endl;

	testArray.sortArray();

	for (int index = 0; index < testArray.getSize(); index++)
	{
		std::cout << "Item #" << index << ": " << testArray.getFront()[index] << std::endl;
	}

	return 0;
}