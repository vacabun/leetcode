#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = nullptr;
  newNode->right = nullptr;
  return newNode;
}

class Solution
{
public:
    void solve(Node* node)
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