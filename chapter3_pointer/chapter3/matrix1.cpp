#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3

void matrix_calc(int arr1[][COLS], int arr2[][COLS]);
void matrix_print(int A[ROWS][COLS]);
int** add_matrix(int arr1[][COLS], int arr2[][COLS]);
void free_add_matrix(int** arr);

int main(void) {
	int arr1[ROWS][COLS] = { {2,3,0},
							 {8,9,1},
							 {7,0,5} };
	int arr2[ROWS][COLS];
	matrix_calc(arr1, arr2);
	matrix_print(arr1);
	matrix_print(arr2);
	int** arr3 = add_matrix(arr1, arr2);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
}

void matrix_calc(int arr1[][COLS], int arr2[][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			arr2[j][i] = arr1[i][j];
		}
	}
}

void matrix_print(int A[ROWS][COLS]) {
	printf("---------------------\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}

int** add_matrix(int arr1[][COLS], int arr2[][COLS]) {
	int** arr = (int**)malloc(ROWS * sizeof(int*)); //malloc�� (void*)�� ��ȯ�ϱ� ������ (int**)�� ����� ����ȯ �ʿ�
	if (arr == NULL) { //�޸� �Ҵ� ������ ���� �ʴ°��, malloc�� NULL�� ��ȯ�� �����߻�
		perror("Failed to allocate memory for rows"); 
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < ROWS; i++) {
		arr[i] = (int*)malloc(COLS * sizeof(int));
		if (arr[i] == NULL) {
			perror("Failed to allocate memory for columns");
			for (int j = 0; j < i; j++) {
				free(arr[j]);
			}
			free(arr);
			exit(EXIT_FAILURE);
		}
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	return arr;
}

void free_add_matrix(int** arr) {
	for (int i = 0; i < ROWS; i++) {
		free(arr[i]);
	}
	free(arr);
}