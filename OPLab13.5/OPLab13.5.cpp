#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

void heapify(int array[], int length, int index) {
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left < length && array[left] > array[largest]) { largest = left; }
	if (right < length && array[right] > array[largest]) { largest = right; }
	if (largest != index) {
		int temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		heapify(array, length, largest);
	}
}
void heapsort(int array[], int length) {
	for (int index = length / 2 - 1; index >= 0; index--) { heapify(array, length, index); }
	for (int index = length - 1; index >= 0; index--) {
		int temp = array[0];
		array[0] = array[index];
		array[index] = temp;
		heapify(array, index, 0);
	}
}
int main() {
	int array[] = { 7, 8, 6, -2, 1, 2, -1, -5, 10, 5, 4, -6, -3, 3, -4, 9 };
	int length = 16;
	for (int index = 0; index < length; index++) { printf("%d ", array[index]); }
	for (int index = length / 2 - 1; index >= 0; index--) { heapify(array, length, index); }
	printf("\n");
	for (int index = 0; index < length; index++) { printf("%d ", array[index]); }
	heapsort(array, length);
	printf("\n");
	for (int index = 0; index < length; index++) {
		printf("%d ", array[index]);
		return 0;
}

	}