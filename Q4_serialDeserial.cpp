#include <iostream>
#include <sstream>
#include <string>
#include <queue>

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

class serialDeserial
{
public:
    std::string serialize(TreeNode *root)
    {
        std::string result;
        serializeTree(root, result);
        return result;
    }

    TreeNode *deserialize(const std::string &data)
    {
        std::queue<std::string> nodes;
        std::stringstream ss(data);
        std::string nodeValue;

        while (getline(ss, nodeValue, ','))
        {
            nodes.push(nodeValue);
        }

        return deserializeTree(nodes);
    }

private:
    void serializeTree(TreeNode *node, std::string &result)
    {
        if (!node)
        {
            result += "#,";
            return;
        }

        result += std::to_string(node->value) + ",";
        serializeTree(node->left, result);
        serializeTree(node->right, result);
    }

    TreeNode *deserializeTree(std::queue<std::string> &nodes)
    {
        std::string nodeValue = nodes.front();
        nodes.pop();
        if (nodeValue == "#")
            return nullptr;
            
        TreeNode *node = new TreeNode(std::stoi(nodeValue));
        node->left = deserializeTree(nodes);
        node->right = deserializeTree(nodes);

        return node;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    serialDeserial serializer, deserializer;

    std::string serializedTree = serializer.serialize(root);
    std::cout << "Serialized Tree: " << serializedTree << std::endl;

    TreeNode *deserializedTree = deserializer.deserialize(serializedTree);

    std::string reserializedTree = serializer.serialize(deserializedTree);
    std::cout << "Reserialized Tree: " << reserializedTree << std::endl;
}