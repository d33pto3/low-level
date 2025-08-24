int remove_dups(int *arr, int size)
{
    if (size == 0)
        return 0;
    int j = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }

    return ++j;
}