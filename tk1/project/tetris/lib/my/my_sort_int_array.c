/*
** EPITECH PROJECT, 2021
** my_sort_int_array
** File description:
** clean your room you fucktard
*/

void my_swap(int *a, int *b);

int *maybe_swap(int *array, int n)
{
    if (array[n - 1] > array[n])
        my_swap(&array[n - 1], &array[n]);
    return array;
}

void my_sort_int_array(int *array, int size)
{
    for (int i = 0; i != size; i++) {
        for (int n = 1; n != size - i; n++) {
            array = maybe_swap(array, n);
        }
    }
}
