#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void solve(std::vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
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
    Solution solution;
    solution.solve(nums);

    return 0;
}