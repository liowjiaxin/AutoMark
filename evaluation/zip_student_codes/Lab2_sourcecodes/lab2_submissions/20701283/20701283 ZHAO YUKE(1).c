#include<stdio.h>
#include<stdlib.h>

void get_valid_indices(int* index1, int*index2, int size);
int get_valid_size();

int main() {
	int N;
	N = get_valid_size();
	
	int* array = (int*)malloc(N * sizeof(int));
	if (array == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	printf("Enter %d elements of the array:\n", N);
	int i;
	for (i = 0; i < N; i++) {
		printf("Enter element %d: ", i + 1);
		scanf("%d", array + i);
	}
	int index1, index2;
	get_valid_indices(&index1, &index2, N);
	int sum = *(array + index1) + *(array + index2);
	printf("The sum of elements at indices %d and %d is: %d\n", index1,index2, sum);
	free(array);
	
	return 0; 
	
}
int get_valid_size() {
	int size;
	do {
		printf("Enter the size of the array(N >= 5): ");
		scanf("%d", &size);
		if (size < 5){
			printf("Invalid size. PLease enter a size >=5.\n");
		
		}
	} while (size < 5);
	return size;
}

void get_valid_indices(int* index1, int* index2, int size){
	do{printf("Enter the first index (0 to %d): ", size -1);
	scanf("%d", index1);
	printf("Enter the second index (0 to %d): ", size - 1);
	scanf("%d", index2);
	
	  if (*index1 < 0 || *index1 >=size || *index2 < 0 || *index2>= size) {
		printf("Invalid indices. Please enter indices within range.\n");
		
	  }
	}while (*index1 < 0 || *index1 >= size || *index2 < 0 || *index2 >= size);
}


