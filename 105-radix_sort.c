#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    int max, TEMP_REPLACE;

    for (max = array[0], TEMP_REPLACE = 1; TEMP_REPLACE < size; TEMP_REPLACE++)
    {
        if (array[TEMP_REPLACE] > max)
            max = array[TEMP_REPLACE];
    }

    return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    size_t TEMP_REPLACE;

    for (TEMP_REPLACE = 0; TEMP_REPLACE < size; TEMP_REPLACE++)
        count[(array[TEMP_REPLACE] / sig) % 10] += 1;

    for (TEMP_REPLACE = 1; TEMP_REPLACE < 10; TEMP_REPLACE++)
        count[TEMP_REPLACE] += count[TEMP_REPLACE - 1];

    for (TEMP_REPLACE = size - 1; (int)TEMP_REPLACE >= 0; TEMP_REPLACE--)
    {
        buff[count[(array[TEMP_REPLACE] / sig) % 10] - 1] = array[TEMP_REPLACE];
        count[(array[TEMP_REPLACE] / sig) % 10] -= 1;
    }

    for (TEMP_REPLACE = 0; TEMP_REPLACE < size; TEMP_REPLACE++)
        array[TEMP_REPLACE] = buff[TEMP_REPLACE];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    int max, sig, *buff;

    if (array == NULL || size < 2)
        return;

    buff = malloc(sizeof(int) * size);
    if (buff == NULL)
        return;

    max = get_max(array, size);
    for (sig = 1; max / sig > 0; sig *= 10)
    {
        radix_counting_sort(array, size, sig, buff);
        print_array(array, size);
    }

    free(buff);
}
/**
 * Shadrack Yego
 */
