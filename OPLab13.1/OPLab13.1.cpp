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

	for (int j = 0; j < number; j++) {
		for (int index = 0; index < number - j - 1; index++) {
			if (array[index] > array[index + 1]) {
				int temp = array[index];
				array[index] = array[index + 1];
				array[index + 1] = temp;
			}
		}
	}

	finish = clock();

	printf("\n");
	finish = clock();

	for (int index = 0; index < number; index++) { printf("%d ", array[index]); }

	timetaken = (float)(finish - start) / CLOCKS_PER_SEC;
	printf("\nЧас сортування (в секундах): %f", timetaken);
	return 0;
}