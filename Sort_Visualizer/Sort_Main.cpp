#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <chrono>


using namespace std;
using namespace std::chrono;



#include "QuickSort.h"

vector<int> numList;
int swapNums = 0;


void genNums(int amount) {

	
	int num;

	for (int i = 0; i < amount; i++) {

		num = 1 + rand() % 50;
		numList.push_back(num);
	}


}

void printLine(vector<int>numList, int length, int n) {


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


void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


void bubbleSort(vector<int>&numList, int n) {
	
	for (int i = 0; i < n - 1; i++) {

		
		for (int j = 0; j < n - i - 1; j++) {
			if (numList[j] > numList[j + 1]) {
				swap(&numList[j], &numList[j + 1]);
				swapNums++;
			}
		}

		printLine(numList, n, 0);
		cout << "\n\n";
	}
	}

	






int main() {



	srand(time(NULL));

	int dataSize;
	float seconds;

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


	auto start = high_resolution_clock::now();
	bubbleSort(numList, length);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);



	cout << "\n\n\n";
	seconds = duration.count() / 1e+6;



	cout << "Number of swaps made: " << swapNums<<"\n";
	cout << "Time taken: " << seconds << " seconds";
	

	/*QuickSort qs(numList);
	qs.sort(0, numList.size() - 1);
	qs.print();*/
	

	return 0;
}