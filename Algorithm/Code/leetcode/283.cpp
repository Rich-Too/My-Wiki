#include <cstddef>
#include <type_traits>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                if (i < j)
                {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                i++;
            }
        }
    }
};