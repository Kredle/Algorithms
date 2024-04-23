#include <iostream>
#include <ctime>
using namespace std;

int main() {
	const unsigned int n = 20;
	int* start_arr = new int[n];
	int* AscendingArr = new int[n];
	int* DescendingArr = new int[n];

	srand(time(0));
	for (int i = 0; i < n; i++) {
		start_arr[i] = rand() % (10 - 1) + 1;
	}
	int max = start_arr[0];
	cout << "Start Array: \n";
	for (int i = 0; i < n; ++i) {
		cout << start_arr[i] << ' ';
		if (start_arr[i] > max) max = start_arr[i];
	}

	int* countArr = new int[max + 1];
	for (int i = 0; i <= max; ++i) countArr[i] = 0;
	for (int i = 0; i < n; ++i) ++countArr[start_arr[i]];
	for (int i = 0; i < max; ++i) countArr[i+1] += countArr[i];

	int* copycountArr = new int[max + 1];
	for (int i = 0; i <= max; ++i) copycountArr[i] = countArr[i];
	for (int i = 0; i < n; ++i) {
		AscendingArr[countArr[start_arr[i]] - 1] = start_arr[i];
		--countArr[start_arr[i]];
	}
	for (int i = 0; i < n; i++) {
		start_arr[i] = AscendingArr[i];
	}
	cout << endl;
	cout << "Ascending Arr: \n";
	for (int i = 0; i < n; ++i) cout << AscendingArr[i] << ' ';

	for (int i = 0; i < n; ++i) {
		DescendingArr[n-copycountArr[start_arr[i]]] = start_arr[i];
		--copycountArr[start_arr[i]];
	}
	cout << endl;
	cout << "Descending Arr: \n";
	for (int i = 0; i < n; ++i) cout << DescendingArr[i] << ' ';

	return 0;
}