#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 8
int sorted[MAX_SIZE];
//
void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

int main(int argc, const char* argv[]) {
	int arr[8] = { 8, 2, 5, 7, 6, 4, 1, 3 };
	merge_sort(arr, 0, 7);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}

void merge(int list[], int left, int mid, int right) {
	int i = left; int j = mid + 1; int k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}

	if (i > mid) {
		for (int l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (int l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (int l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}