#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

int main()
{
    // 创建 Solution 类的实例
    Solution solution;

    // 准备输入数据
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // 调用 groupAnagrams 函数
    vector<vector<string>> result = solution.groupAnagrams(input);

    // 输出结果
    for (const auto &group : result)
    {
        cout << "[ ";
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
