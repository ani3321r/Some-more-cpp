#include <iostream>

int main()
{
	// 1d
	int* a1d = new int[50]; // this is initializing a int array of 200 bytes
	
	// 2d
	int** a2d = new int*[50]; // this is initializing a 2d array
	for (int i = 0; i < 50; i++)
		a2d[i] = new int[50]; // inside the int ptrs initializing the int vals

	// 3d
	int*** a3d = new int** [50];
	for (int i = 0; i < 50; i++)
	{
		a3d[i] = new int* [50];
		for (int j = 0; j < 50; j++) {
			//a3d[i][j] = new int[50]; // this is one way of writing

			// another way
			int** ptr = a3d[i];
			ptr[j] = new int[50];
		}
	}

	a1d[0] = 0;
	a2d[0][0] = 0; // the rightmost value is the actual value we are allocating and the left ones are just pointers
	a3d[0][0][0] = 0;

	// we can delete the 2d or the 3d arrays like this 
	// delete[] a2d;
	// we have to manually delete every byte of data by iterating through it
	for (int i = 0; i < 50; i++)
		delete[] a2d[i];
	delete[] a2d; // also delete the 200 bytes of allocated ptr to ptr



	// there is a faster way of accessing memory than the tradition way
	// traditional way
	// this has to jump to a different memory everytime making it slower
	for (int y = 0; y < 50; y++)
	{
		for (int x = 0; x < 50; x++)
		{
			a2d[x][y] = 2;
		}
	}

	// big brain way(actually storing the 2d data in a 1d array)
	// this is a lot faster as it is accessing the memory which is all in a row
	int* array = new int[5 * 5];
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			array[x + y * 5] = 2;
		}
	}

	std::cin.get();
}