#include <iostream>

using namespace std;

void findMaxCrossingSubarray(int A[], int low, int mid, int high, int &max_left, int &max_right, int &max_sum, int &count)
{
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        count++;
        sum += A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        count++;
        sum += A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }

    max_sum = left_sum + right_sum;
}

void findMaxSubarray(int A[], int low, int high, int &max_left, int &max_right, int &max_sum, int &count)
{
    if (low == high)
    {
        max_left = low;
        max_right = high;
        max_sum = A[low];
    }
    else
    {
        int mid = (low + high) / 2;
        int left_max_left, left_max_right, left_max_sum;
        int right_max_left, right_max_right, right_max_sum;
        int cross_max_left, cross_max_right, cross_max_sum;

        findMaxSubarray(A, low, mid, left_max_left, left_max_right, left_max_sum, count);
        findMaxSubarray(A, mid + 1, high, right_max_left, right_max_right, right_max_sum, count);
        findMaxCrossingSubarray(A, low, mid, high, cross_max_left, cross_max_right, cross_max_sum, count);

        if (left_max_sum >= right_max_sum && left_max_sum >= cross_max_sum)
        {
            max_left = left_max_left;
            max_right = left_max_right;
            max_sum = left_max_sum;
        }
        else if (right_max_sum >= left_max_sum && right_max_sum >= cross_max_sum)
        {
            max_left = right_max_left;
            max_right = right_max_right;
            max_sum = right_max_sum;
        }
        else
        {
            max_left = cross_max_left;
            max_right = cross_max_right;
            max_sum = cross_max_sum;
        }
    }
}

int main()
{
    int A[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(A) / sizeof(A[0]);
    int count = 0;
    int max_left, max_right, max_sum;

    findMaxSubarray(A, 0, n - 1, max_left, max_right, max_sum, count);

    cout << "Max subarray sum: " << max_sum << endl;
    cout << "Max subarray indices: [" << max_left << ", " << max_right << "]" << endl;
    cout << "Number of operations performed: " << count << endl;

    return 0;
}
