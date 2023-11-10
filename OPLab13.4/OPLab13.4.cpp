#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

int main() {

	srand(time(0));
	float timetaken;
	clock_t finish, start;
	const int number = 10;
	int array[number];
	for (int index = 0; index < number; index++) {
		array[index] = rand() % 20 - 10 + 1;
		printf("%d ", array[index]);
	}
	start = clock();
	for (int j = number / 2; j > 0; j = j / 2) {
		for (int index = j; index < number; index++) {
			int temp = array[index];
			int atom;
			for (atom = index; atom >= j && array[atom - j] > temp; atom = atom - j) {
				array[atom] = array[atom - j];
			}
			array[atom] = temp;
		}
	}
	finish = clock();
	printf("\n");
	for (int index = 0; index < number; index++) { printf("%d ", array[index]); }
	timetaken = (float)(finish - start) / CLOCKS_PER_SEC;
	printf("\nЧас сортування (в секундах): %f", timetaken);

	return 0;
}