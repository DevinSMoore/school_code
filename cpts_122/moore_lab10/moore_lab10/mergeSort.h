#pragma once
#define MAX_ARRAY_SIZE 50


template <typename T>
class MergeSort
{
public:
	MergeSort();

	T* getFront(void) const;
	int getSize(void) const;

	void setSize(int newSize);
	void sortArray(void);
	

private:
	int mArraySize;
	int mMaxArraySize;
	T* mpFront;

	void sortArray(T* pArray, int frontIndex, int middleIndex, int backIndex);
	void mergeArray(T* pArray, int frontIndex, int backIndex);

};

// Constructor to build our array
template <typename T>
MergeSort<T>::MergeSort()
{
	mArraySize = 0;
	mMaxArraySize = MAX_ARRAY_SIZE;
	mpFront = new T[MAX_ARRAY_SIZE];
}

template <typename T>
T* MergeSort<T>::getFront(void) const
{
	return mpFront;
}

template <typename T>
void MergeSort<T>::sortArray(void)
{
	int midPoint = 0, frontIndex = 0, backIndex = 0;
	
	// front index is just 0, back will be the arraySize variable
	backIndex = this->mArraySize - 1;
	
	// calculate midpoint then pass that to the sort function
	midPoint = backIndex / 2; // b/c front is always 0

	sortArray(this->mpFront, frontIndex, midPoint, backIndex);
	
	
}

// This isn't creating new arrays on demand it will just kind of create an imaginary array using integer representations of the indicies
template <typename T>
void MergeSort<T>::sortArray(T* pArray, int frontIndex, int middleIndex, int backIndex)
{
	int newLeftBackIndex = 0, newRightBackIndex = 0, newLeftFrontIndex = 0, newRightFrontIndex = 0, newLeftMidpoint = 0, newRightMidpoint = 0; // This seems silly

	if (frontIndex < backIndex) // If we have more than one item in our mini array
	{
		// Segmenting new sub arrays
		newLeftMidpoint = (middleIndex - frontIndex) / 2; // Left bias midpoint b/c of integer division
		newRightMidpoint = middleIndex + (backIndex - (middleIndex + 1)) / 2;

		newRightBackIndex = backIndex;
		newLeftBackIndex = middleIndex;
		
		newRightFrontIndex = middleIndex + 1;
		newLeftFrontIndex = frontIndex;

		sortArray(pArray, newLeftFrontIndex, newLeftMidpoint, newLeftBackIndex);
		
		sortArray(pArray, newRightFrontIndex, newRightMidpoint, newRightBackIndex);

		// Ok I think at this point if we immagine playing this out we will eventually reach a single item in each array and we need to merge them
		// So I think if we check the newLeftMidpoint vs the newRightMidpoin values then we can start to slap them in the array in order as we work back through the itterations

		// call mergeArray i guess

		mergeArray(pArray, newLeftFrontIndex, newRightBackIndex);

	}
}

// We pass the front index of the left array and the back index of the right array, the difference (+1) is the size of the array that we're attempting to merge
template <typename T>
void MergeSort<T>::mergeArray(T* pArray, int frontIndex, int backIndex)
{
	T tempData;
	int subArraySize = (frontIndex - backIndex) + 1; // Don't think the is necessary
	if(subArraySize > 1)
	{
		for (int index = frontIndex; index <= backIndex; index++)
		{
			if (pArray[index] > pArray[index + 1])
			{
				tempData = pArray[index];
				pArray[index] = pArray[index + 1];
				pArray[index + 1] = tempData;
			}
		}
	}
}

template <typename T>
int MergeSort<T>::getSize(void) const
{
	return this->mArraySize;
}

template <typename T>
void MergeSort<T>::setSize(int newSize)
{
	this->mArraySize = newSize;
}


// You n

// check if left < right
// don't need to check anythingelse

// allocate new new subarrays

