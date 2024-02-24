#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <climits>
using namespace std;

class max_subarray
{
public:
    int A[10000];

public:
    struct Result {
        int low;
        int high;
        int sum;
    };

    Result find_max_cross_subarray(int low, int mid, int high)
    {
        int left_sum = INT_MIN;
        int sum = 0;
        int max_left = mid;

        for (int i = mid; i >= low; i--)
        {
            sum = sum + A[i];
            if (sum > left_sum)
            {
                left_sum = sum;
                max_left = i;
            }
        }

        int right_sum = INT_MIN;
        sum = 0;
        int max_right = mid;

        for (int i = mid + 1; i <= high; i++)
        {
            sum = sum + A[i];
            if (sum > right_sum)
            {
                right_sum = sum;
                max_right = i;
            }
        }

        return {max_left, max_right, left_sum + right_sum};
    }

    Result find_max_subarray(int low, int high)
    {
        if (low == high)
        {
            return {low, high, A[low]};
        }
        else
        {
            int mid = (low + high) / 2;

            Result left = find_max_subarray(low, mid);
            Result right = find_max_subarray(mid + 1, high);
            Result cross = find_max_cross_subarray(low, mid, high);

            if (left.sum >= right.sum && left.sum >= cross.sum)
            {
                return left;
            }
            else if (right.sum >= left.sum && right.sum >= cross.sum)
            {
                return right;
            }
            else
            {
                return cross;
            }
        }
    }
};

int main()
{
    max_subarray obj;

    obj.A[0] = -2;
    obj.A[1] = 1;
    obj.A[2] = -3;
    obj.A[3] = 4;
    obj.A[4] = -1;
    obj.A[5] = 2;
    obj.A[6] = 1;
    obj.A[7] = -5;
    obj.A[8] = 4;

    int low = 0;
    int high = 8;

    max_subarray::Result result = obj.find_max_subarray(low, high);

    cout << "Maximum subarray found: ";
    for (int i = result.low; i <= result.high; i++)
    {
        cout << obj.A[i] << " ";
    }
    cout << endl;
    cout << "Sum of maximum subarray: " << result.sum << endl;

    return 0;
}