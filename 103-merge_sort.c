#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort subarray
 * @subarr: A subarray of an array integers sort.
 * @buff: A buffer to store
 * @front: The front index.
 * @mid: The middle index.
 * @back: The back index
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t TEMP_REPLACE, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (TEMP_REPLACE = front, j = mid; TEMP_REPLACE < mid && j < back; k++)
		buff[k] = (subarr[TEMP_REPLACE] < subarr[j]) ? subarr[TEMP_REPLACE++] : subarr[j++];
	for (; TEMP_REPLACE < mid; TEMP_REPLACE++)
		buff[k++] = subarr[TEMP_REPLACE];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (TEMP_REPLACE = front, k = 0; TEMP_REPLACE < back; TEMP_REPLACE++)
		subarr[TEMP_REPLACE] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm.
 * @subarr: A subarray of an array of integer
 * @buff: A buffer to store 
 * @front: The front index  subarray.
 * @back: The back index  subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implement the top-down merge sort algo
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}

/**
 * Shadrack Yego 
 */

