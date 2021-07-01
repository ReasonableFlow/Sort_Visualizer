#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <chrono>
#include <windows.h>


using namespace std;
using namespace std::chrono;



#include "QuickSort.h"


//This code block is referenced from https://stackoverflow.com/questions/5866529/how-do-we-clear-the-console-in-assembly/5866648#5866648 - StackOverflow user - Jerry Coffin
void clear_screen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}//

void genNums(int amount, vector<int>& numList) {

	
	int num;

	for (int i = 0; i < amount; i++) {

		num = 1 + rand() % 50;
		numList.push_back(num);
	}


}

void printLine(vector<int>&numList, int length, int n, int colourSize) {

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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

		printLine(numList, length, n + 1,colourSize);

		for (int i = 0; i < length; i++) {

			int number = numList[i] - n;
			if (number > 0) {

				SetConsoleTextAttribute(hConsole, colourSize);
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


void bubbleSort(vector<int>&numList, int n, int colourSize, int& swaps) {
	
	for (int i = 0; i < n - 1; i++) {

		
		for (int j = 0; j < n - i - 1; j++) {
			if (numList[j] > numList[j + 1]) {
				swap(&numList[j], &numList[j + 1]);
				swaps++;
			}
		}

		printLine(numList, n, 0,colourSize);
		cout << "\n\n";

		if (i != n - 2) {
			
			clear_screen();
		}
	}

}

	
int main() {



	srand(time(NULL));
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	vector<int> numList;
	int dataSize;
	float seconds;
	int colSize;
	char choice;
	int swapNums = 0;


	cout << "Enter the size of the array: ";
	cin >> dataSize;


	for (int k = 10; k < 16; k++)
	{
		
		SetConsoleTextAttribute(hConsole, k);
		cout << k << ": Test" << endl;
	}


	SetConsoleTextAttribute(hConsole, 7);
	cout << "\nChoose which colour you want: ";
	cin >> colSize;


	genNums(dataSize,numList);
	cout << "Unsorted array: ";
	for (int i = 0; i < numList.size(); i++) {
		cout << setw(3) << numList[i];
	}

	cout << "\n";


	int length = numList.size();
	printLine(numList, length, 0, colSize);

	SetConsoleTextAttribute(hConsole, 7);
	cout << "\nThis is the array, do you wish to proceed to sort? (y/n): ";
	cin >> choice;
	


	if (choice == 'y') {

		printLine(numList, length, 0, colSize);


		auto start = high_resolution_clock::now();
		bubbleSort(numList, length, colSize, swapNums);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);



		cout << "\n\n\n";
		seconds = duration.count() / 1e+6;


		SetConsoleTextAttribute(hConsole, 7);

		cout << "Number of swaps made: " << swapNums << "\n";
		cout << "Time taken: " << seconds << " seconds";
	}
	else if (choice == 'n') {

		return 0;
	}
	

	/*QuickSort qs(numList);
	qs.sort(0, numList.size() - 1);
	qs.print();*/
	

	//return 0;
}