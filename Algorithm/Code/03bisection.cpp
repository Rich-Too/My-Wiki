#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, q;
int array[N];

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    while (q--)
    {
        int i = 0, j = n - 1;
        int target;
        scanf("%d", &target);
        while (i < j)
        {
            int mid = i + j >> 1;
            if (array[mid] >= target)
                j = mid;
            else
                i = mid + 1;
        }
        if (array[i] != target)
        {
            cout << "-1 -1" << endl;
            continue;
        }
        cout << i << " ";
        i = 0, j = n - 1;
        while (i < j)
        {
            int mid = i + j + 1 >> 1;
            if (array[mid] <= target)
                i = mid;
            else
                j = mid - 1;
        }
        cout << j << endl;
    }
}