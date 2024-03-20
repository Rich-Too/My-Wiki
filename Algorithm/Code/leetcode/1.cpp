#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hashmap.find(target - nums[i]);
            if (it != hashmap.end())
            {
                return {i, it->second};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};