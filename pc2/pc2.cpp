// pc2.cpp : Defines the entry point for the console application.
// Adam Flammino C++ II, 3/12/17
// Adds a quicksort function to pc1

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

/**
Checks if one value is higher than another, creates virtual sort function
**/
class AbstractSort {
protected:
	int compares = 0;
public:
	/**
	Takes two integers, returns false if the first is smaller, true if the second is smaller
	**/
	bool compareator(int i, int j) {
		compares++;
		return i > j;
	}
	int getCompares() {
		return compares;
	}
	//  virtual int sort(int arr[], int size) = 0;  //USE THIS FOR BUBBLE SORT
	virtual int sort(int arr[], int l, int r) = 0; //USE THIS FOR QUICKSORT (needs l and r for recursive function)
};

/**
Implements a bubble sort
**/
class BubbleSort : public AbstractSort {
	int i;
	int j;
	int temp;
	bool flag = true;
	/**
	Bubble sort
	**/
public:
	int sort(int arr[], int size) {
		for (i = 0; i <= size && flag; i++) {
			flag = false;
			for (j = 0; j < (size - 1); j++) {
				if (compareator(arr[j], arr[(j + 1)])) {
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					flag = true;
				}
			}
		}
		return getCompares();
	}
};




class QuickSort : public AbstractSort {
	/**
	Quick Sort
	**/
public:
	/*
	Implements a quick sort
	*/
	int sort(int arr[], int left, int right) {
		int i = left, j = right;
		int tmp;
		int pivot = arr[(left + right) / 2];

		/* partition */
		while ((i <= j)) {
			while (compareator(pivot, arr[i]))
				i++;
			while (compareator(arr[j], pivot))
				j--;
			if (i <= j) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
				j--;
			}
		};

		/* recursion */
		if (compareator(j, left))
			sort(arr, left, j);
		if (compareator(right, i))
			sort(arr, i, right);
		return getCompares();
	}
	

};
int main()
{
	const int SIZE = 8;
	int numOfCompares = 0;
	int num[] = {6, 2, 1, 3, 5, 9, 0, 4};
	QuickSort sorter;
	numOfCompares = sorter.sort(num, 0, SIZE - 1);
	cout << "This sorting method required " << numOfCompares << " comparisons to sort " << SIZE << " elements.\n";
/* FOR TESTING	
	for (int i = 0; i < SIZE; i++) {
	cout << num[i] << endl;
	}
	*/
	return 0;
}

