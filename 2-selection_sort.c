#include "sort.h"

/**
 * swap_ints - Swaptwo9 integes in  array.
 * @a: first integr to swap.
 * @b: second integer  swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * selection_sort - sort an array of integers in ascending
 *              	using the selection sort algo
 * @array:array of integers.
 * @size:size of the array.
 *
 * Description: Prints array after each swap.
 */
void selection_sort(int *array, size_t size)
{
    int *min;
    size_t k, j;

    if (array == NULL || size < 2)
   	 return;

    for (k = 0; k < size - 1; k++)
    {
   	 min = array + k;
   	 for (j = k + 1; j < size; j++)
   		 min = (array[j] < *min) ? (array + j) : min;

   	 if ((array + k) != min)
   	 {
   		 swap_ints(array + k, min);
   		 print_array(array, size);
   	 }
    }
}
/**
 * Shadrack Yego
 */

