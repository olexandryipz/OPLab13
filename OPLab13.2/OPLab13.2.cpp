#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

int main() {

	srand(time(0));
	float timetaken;
	clock_t start, finish;
	const int number = 10;
	int array[number];
	for (int index = 0; index < number; index++) {
		array[index] = rand() % 20 - 10 + 1;
		printf("%d ", array[index]);
	}
	start = clock();
	for (int index = 1; index < number; index++) {
		int key = array[index];
		int j = index - 1;
		while (j >= 0 && array[j] > key) {
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	finish = clock();
	printf("\n");
	for (int index = 0; index < number; index++) { printf("%d ", array[index]); }
	timetaken = (float)(finish - start) / CLOCKS_PER_SEC;
	printf("\nЧас сортування (в секундах): %f", timetaken);

	return 0;
}