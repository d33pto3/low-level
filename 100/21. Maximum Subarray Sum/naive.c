int nmaxSubArraySum(int arr[], int size)
{
    int maxSum = 0;

    for (int i = 0; i < size; i++)
    {
        int curSum = 0;
        for (int j = i; j < size; j++)
        {
            curSum += arr[j];
            if (curSum > maxSum)
            {
                maxSum = curSum;
            }
        }
    }

    return maxSum;
}