#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <random>


using namespace std;


#include "QuickSort.h"

vector<int> numList;


void genNums(int amount) {

	
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


void bubbleSort(vector<int>&numList, int n)
{
	
	for (int i = 0; i < n - 1; i++) {

		
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


}



int main() {



	srand(time(NULL));

	int dataSize;

	cout << "Enter the size of the array: ";
	cin >> dataSize;


	genNums(dataSize);
	cout << "Unsorted array: ";
	for (int i = 0; i < numList.size(); i++) {
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