#include <iostream>
#include <algorithm>
#include <climits>

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class MaxPath
{

public:
    int maxPathSum(Node *root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(Node *node, int &maxSum)
    {
        if (node == nullptr)
            return 0;

        int leftMax = std::max(dfs(node->left, maxSum), 0);
        int rightMax = std::max(dfs(node->right, maxSum), 0);
        int currentMax = node->val + leftMax + rightMax;
        maxSum = std::max(maxSum, currentMax);

        return node->val + std::max(leftMax, rightMax);
    }
};

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    MaxPath obj;
    std::cout << "Maximum Path Sum = " << obj.maxPathSum(root) << std::endl;
}