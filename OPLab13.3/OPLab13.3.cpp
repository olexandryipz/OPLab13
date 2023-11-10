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
	for (int index = 0; index < number; index++) {
		int min = index;
		for (int j = index; j < number; j++) {
			if (array[j] < array[min]) { min = j; }
		}
		int temp = array[index];
		array[index] = array[min];
		array[min] = temp;
	}
	finish = clock();
	printf("\n");
	for (int index = 0; index < number; index++) { printf("%d ", array[index]); }
	timetaken = (float)(finish - start) / CLOCKS_PER_SEC;
	printf("\nЧас сортування (в секундах): %f", timetaken);

	return 0;
}