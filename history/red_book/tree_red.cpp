#include <iostream>
#include <vector>

using namespace std;

// 检查一个数是否为质数
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    int back_tracking(std::vector<int> &nums, std::vector<std::vector<int>> &m, std::vector<int> &nums_is_red, int positon, int num)
    {
        if (positon == nums.size())
        {
            return num;
        }
        int i = positon;

        int can_be_red = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (m[i][j] == 1 && nums_is_red[i] != 1 && nums_is_red[j] != 1 && isPrime(nums[i] + nums[j]))
            {
                can_be_red = 1;
                break;
            }
        }

        if (can_be_red == 1)
        {
            nums_is_red[i] = 1;
            int val1 = back_tracking(nums, m, nums_is_red, i + 1, num + 1);
            nums_is_red[i] = 0;
            int val2 = back_tracking(nums, m, nums_is_red, i + 1, num);
            return max(val1, val2);
        }
        else
        {
            nums_is_red[i] = 0;
            return back_tracking(nums, m, nums_is_red, i + 1, num);
        }
    }
    int solve(std::vector<int> nums, std::vector<std::vector<int>> m)
    {
        std::vector<int> nums_is_red(nums.size(), 0);

        return back_tracking(nums, m, nums_is_red, 0, 0);
    }
};

int main()
{

    int size = 0;
    cin >> size;

    std::vector<int> nums(size, 0);

    for (int i = 0; i < nums.size(); i++)
    {
        int temp;
        cin >> temp;
        nums[i] = temp;
    }
    std::vector<std::vector<int>> m(size, std::vector<int>(size, 0));

    for (int i = 0; i < nums.size() - 1; i++)
    {
        int u;
        cin >> u;
        int v;
        cin >> v;
        int u_index = 0;
        auto it = std::find(nums.begin(), nums.end(), u);
        if (it != nums.end())
        {
            u_index = std::distance(nums.begin(), it);
        }
        int v_index = 0;
        it = std::find(nums.begin(), nums.end(), v);
        if (it != nums.end())
        {
            v_index = std::distance(nums.begin(), it);
        }
        m[u_index][v_index] = 1;
        m[v_index][u_index] = 1;
    }
    // cout << nums.size() << "\n";
    Solution solution;
    cout << solution.solve(nums, m) << "\n";

    return 0;
}