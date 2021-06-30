#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <random>


using namespace std;

#define MAX_ARY_SIZE 15

#include "QuickSort.h"

vector<int> numList;
vector<int> sortedList;

void genNums(int amount) {

	//vector<int> numList;
	int num;

	for (int i = 0; i < amount; i++) {

		num = 1 + rand() % 50;
		numList.push_back(num);
	}


}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort 
void bubbleSort(vector<int>&numList, int n)
{
	//int i, j;
	int k;
	for (int i = 0; i < n - 1; i++) {

		// Last i elements are already in place 
		for (int j = 0; j < n - i - 1; j++) {
			if (numList[j] > numList[j + 1]) {
				swap(&numList[j], &numList[j + 1]);
			}
		}
	}
}



void printLine(vector<int>numList,int length,int n) {


	bool finished = true;

	for (int i = 0; i < length; i++) {
		if (numList[i] - n > 0) {

			finished = false;
		}
	}

	if (finished) {

		return;
	}
	else {

		printLine(numList, length, n + 1);

		

		for (int i = 0; i < length; i++) {

			int number = numList[i] - n;
			if (number > 0) {
				
				cout << "| ";
			}
			else {

				cout << "  ";
			}
		}

		
		cout << "\n";
	}
	

	/*for (int i = 0; i < numList.size(); i++) {

		
		for (int j = 0; j < numList[i]; j++) {


			cout << "|";
		}

		cout << "\n";


	}*/


}



int main() {

	
	int i;

	srand(time(NULL));
	//int ary[MAX_ARY_SIZE] = { 89, 72, 3, 15, 21, 57, 61, 44, 19, 98, 5, 77, 39,
	//		59, 61 }; // ary

//	Statements
	int dataSize;

	cout << "Enter the size of the array: ";
	cin >> dataSize;


	genNums(dataSize);
	cout << "Unsorted array: ";
	for (i = 0; i < numList.size(); i++) {
		cout << setw(3) << numList[i];
	}

	cout << "\n";


	int length = numList.size();
	printLine(numList,length,0);
	bubbleSort(numList, length);
	cout << "\n\n\n";
	printLine(numList, length, 0);
	

	/*QuickSort qs(numList);
	qs.sort(0, numList.size() - 1);
	qs.print();*/
	




	return 0;
}