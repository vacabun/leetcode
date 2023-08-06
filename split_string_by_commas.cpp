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
            cout << nums[i] << "\n";
        }

    }
};

#include <vector>
#include <string>
#include <sstream>
std::vector<std::string> split_string_by_commas(std::string input)
{
    int n = input.size();
	for (int i = 0; i < n; ++i){
		if (input[i] == ','){
			input[i] = ' ';
		}
	}
    std::vector<std::string> result;
	std::istringstream out(input);
	std::string str;
	while (out >> str){
		result.push_back(str);
	}
    return result;
}

int main()
{
    std::string str;
    cin >> str;
    std::vector<int> nums;
    for (auto s : split_string_by_commas(str))
    {
        nums.push_back(std::stoi(s));
    }

    Solution solution;
    solution.solve(nums);

    return 0;
}
