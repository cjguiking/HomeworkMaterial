// Ceejay Guiking
// Assignment 9
// CS 302 - 1003

#include <iostream>
#include <cmath>
#include <time.h>

//	Used to count the number of comparisons between vector elements
int counter = 0;

using namespace std;

void slowsort(int a[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		slowsort(a, left, center);
		slowsort(a, center + 1, right);
		
		if (a[center] > a[right]){
			for(int i=0; i < 10; i++){
				cout << a[i] << "|";
			}
			
			int temp = a[center];
			a[center] = a[right];
			a[right] = temp;
			counter++;
		}
		slowsort(a, left, right-1);
	}
}

//	Prints the array from element 0 till the end
void printArray(int A[], int size)
{
	for (int i=0; i<size; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main()
{
	int n = 20;
	int a[n];
	time_t srand(time(NULL));
		for (int i= 0; i < n; ++i){
			a[i] = 1 + (int)(1000 * (sin(1.2*i) * sin(1.2*i)));
		}
//	Sort the array and print the element exchanges		
		slowsort(a, 0, n - 1);
//	Finally print the sorted array		
		printArray(a, n);
		
		cout << "number of comparisons " << counter << endl;
		
		return 0;
}