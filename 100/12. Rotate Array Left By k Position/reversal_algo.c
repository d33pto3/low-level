void reverse(int *arr, int start, int end)
{
    while (start < end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[start] ^ arr[end];
        arr[start] = arr[start] ^ arr[end];
        start++;
        end--;
    }
}