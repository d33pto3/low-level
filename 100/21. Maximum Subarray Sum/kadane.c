int kmaxSubarrarySum(int arr[], int size)
{
    int maxEnding = 0;

    int res = 0;

    for (int i = 0; i < size; i++)
    {
        maxEnding = ((maxEnding + arr[i]) > arr[i]) ? (maxEnding + arr[i]) : arr[i];

        res = (maxEnding > res) ? maxEnding : res;
    }

    return res;
}

// 0: me- 2, res- 2
// 1: me- 2
