#pragma once


class QuickSort {
	//int sortData[MAX_ARY_SIZE];
	vector<int> sortData;
	void medianLeft(int left, int right);
public:
	QuickSort( vector<int>ary) {
		for (int i = 0; i < ary.size(); i++)
			//sortData[i] = ary[i];
		sortData.push_back(ary[i]);
	}
	void sort(int left, int right);
	void print() {
		cout << "\nSorted array:   ";
		for (int i = 0; i < sortData.size(); i++)
			cout << setw(3) << sortData[i];
		cout << endl;
	}
};

void QuickSort::sort(int left, int right) {

	int sortLeft;
	int sortRight;
	int pivot;
	int hold;

	{
		medianLeft(left, right);
		pivot = sortData[left];
		sortLeft = left + 1;
		sortRight = right;

		while (sortLeft <= sortRight) {
			// Find key on left that belongs on right
			while (sortData[sortLeft] < pivot)
				sortLeft++;
			// Find key on right that belongs on left
			while (sortData[sortRight] >= pivot)
				sortRight--;
			if (sortLeft <= sortRight) {
				hold = sortData[sortLeft];
				sortData[sortLeft] = sortData[sortRight];
				sortData[sortRight] = hold;
				sortLeft++;
				sortRight--;
			} /* if */
		} // while
		// Prepare for next phase
		sortData[left] = sortData[sortLeft - 1];
		sortData[sortLeft - 1] = pivot;
		if (left < sortRight)
			sort(left, sortRight - 1);
		if (sortLeft < right)
			sort(sortLeft, right);
	}

	return;
}	// end quickSort 

void QuickSort::medianLeft(int left, int right) {
	//	Local Definitions 
	int mid;
	mid = (left + right) / 2;
	if (sortData[left] > sortData[mid]) {
		swap(sortData[left], sortData[mid]);
	} // if
	if (sortData[left] > sortData[right]) {
		swap(sortData[left], sortData[right]);
	} // if
	if (sortData[mid] > sortData[right]) {
		swap(sortData[right], sortData[mid]);
	} // if
	// Median is in middle. Exchange with left.
	swap(sortData[left], sortData[mid]);

	return;
}	// medianLeft 


//int main(void) {
//	//	Local Declarations
//	int i;
//
//	int ary[MAX_ARY_SIZE] = { 89, 72, 3, 15, 21, 57, 61, 44, 19, 98, 5, 77, 39,
//			59, 61 }; // ary
//
////	Statements
//	cout << "Unsorted array: ";
//	for (i = 0; i < MAX_ARY_SIZE; i++)
//		cout << setw(3) << ary[i];
//
//	QuickSort qs(ary);
//	qs.sort(0, MAX_ARY_SIZE - 1);
//	qs.print();
//	return 0;
//}	// main
