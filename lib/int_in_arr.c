int int_in_arr(int n, int *arr, int length)
{
    int i;

    for (i = 0; i < length; i++)
        if (arr[i] == n)
            return (i);
    return (-1);
}
