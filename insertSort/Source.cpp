/*
Ellie Chen
CSC 382 - HW #1
*/

#include <iostream>
#include <array>
#include <ctime>
#include <stdlib.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main() {
	int A[10];
	int i, j;
	srand(time(0) + 5);

	cout << "INSERTION SORT" << endl;

	
	//Populate array
	for (int i = 0; i < (sizeof(A) / sizeof(*A)); i++) {
		A[i] = (rand() % (sizeof(A) / sizeof(*A))) + 1;
	}

	//cout array before sort
	cout << "Before sort: ";
	for (int i = 0; i < (sizeof(A) / sizeof(*A)); i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	/*
	* INSERTION SORT
	*/
	auto start = high_resolution_clock::now();
	//Iterate through array
	for (int i = 0; i < (sizeof(A) / sizeof(*A)); i++) {

		//Begin sorting process
		for (int j = i; j > 0; j--) {
			if ((j - 1) > -1 && A[j - 1] > A[j]) {
				swap(A[j], A[j - 1]);
			}
		}
	}
	auto end = high_resolution_clock::now();
	auto diff = duration_cast<microseconds>(end - start);

	//cout array after sort
	cout << "After sort: ";
	for (int i = 0; i < (sizeof(A) / sizeof(*A)); i++) {
		cout << A[i] << " ";
	}
	cout << endl;

	//cout time
	cout << "Time taken: " << diff.count() << endl;

	system("pause");
	return 0;


}