#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
class Solution
{
public:
    int longestConsecutive(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int res = 0, count = 0, last = nums[0];
        std::set<int> temp;
        for (auto& it : nums)
        {
            if (it == last || it == ++last)
            {
                temp.insert(it);
            }
            else
            {
                res = res > temp.size() ? res : temp.size();
                temp.clear();
                temp.insert(it);
                last = it;
            }
        }
        return res > temp.size() ? res : temp.size();
    }
};
int main()
{
    Solution solution;
    std::vector<int> num = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    std::cout << solution.longestConsecutive(num) << "\n";
    return 0;
}
