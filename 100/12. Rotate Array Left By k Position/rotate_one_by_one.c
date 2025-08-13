// fn definition
void rotate_one_by_one(int arr[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        int first = arr[0];

        for (int j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }

        arr[n - 1] = first;
    }
}