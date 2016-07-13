#include <iostream>
#include <cassert>
#include <algorithm>
#include <iterator>

using namespace std;

int array[] = {1, 2, 10, 8, 9, 7, 5};
const int size = sizeof array / sizeof *array;

int partition(int *array, int left, int right)
{
	if (array == NULL)
		return -1;

	int pos = right;
	right--;
	while (left <= right)
	{
		while (left < pos && array[left] <= array[pos])
			left++;

		while (right >= 0 && array[right] > array[pos])
			right--;

		if (left >= right)
			break;

		swap(array[left], array[right]);
	}
	swap(array[left], array[pos]);

	return left;
}

int getMidIndex(int *array, int size)
{
	if (array == NULL || size <= 0)
		return -1;

	int left = 0;
	int right = size - 1;
	int midPos = right >> 1;
	int index = -1;

	while (index != midPos)
	{
		index = partition(array, left, right);

		if (index < midPos)
		{
			left = index + 1;
		}
		else if (index > midPos)
		{
			right = index - 1;
		} 
		else
		{
			break;
		}
	}

	assert(index == midPos);
	return array[index];
}

void main()
{
	int value = getMidIndex(array, size);

	cout << "value: " << value << endl;
}