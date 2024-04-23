#include <iostream>
#include <ctime>
using namespace std;
void merge(int arr[], int LeftArr[], int RightArr[], int LeftSize, int RightSize);
void mergeSort(int arr[], int size);

int main() {
	const unsigned int n = 20;
	int* a = new int[n];
	srand(time(0));
	for (int i = 0; i < n; ++i) a[i] = rand() % (100 + 100 + 1) - 100;

	cout << "Start Arr: \n";
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';
	mergeSort(a,n);
	cout << "\nAscending Arr : \n";
	for (int i = 0; i < n; ++i) cout << a[i] << ' ';


}

void mergeSort(int arr[], int size) {
	if (size <= 1) return;
	int midlepos = size / 2;
	int* LeftArr = new int[midlepos];
	int* RightArr = new int[size - midlepos];

	int i = 0;
	int	j = 0;

	for (; i < size; ++i) {
		if (i < midlepos) LeftArr[i] = arr[i];
		else {
			RightArr[j] = arr[i];
			++j;
		}
	}
	mergeSort(LeftArr,midlepos);
	mergeSort(RightArr,size - midlepos);
	merge(arr, LeftArr, RightArr,midlepos,size - midlepos);
}

void merge(int arr[], int LeftArr[], int RightArr[],int LeftSize,int RightSize) {

	int i = 0, j = 0, k = 0;

	while (j < LeftSize && k < RightSize) {
		if (LeftArr[j] < RightArr[k]) {
			arr[i] = LeftArr[j];
			++i;
			++j;
		}
		else {
			arr[i] = RightArr[k];
			++i;
			++k;
		}
	}
	while (j < LeftSize) {
		arr[i] = LeftArr[j];
		++i;
		++j;
	}
	while (k < RightSize) {
		arr[i] = RightArr[k];
		++i;
		++k;
	}
}