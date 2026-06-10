/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <print>

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        // inorder traversal + DFS: 1,2,#,#,3,4,#,#,5,#,#,
        std::string sStr;
        dfsSerialize(root, sStr);
        // std::print("sStr: {}\n", sStr);
        return sStr;
    }

    void dfsSerialize(TreeNode* root, std::string& str) {
        if (!root) {
            str += "#,";
            return;
        }
        str += std::to_string(root->val) + ",";
        dfsSerialize(root->left, str);
        dfsSerialize(root->right, str);
    } 

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        int idx = 0;
        return dfsDeserialize(data, idx);
    }

    TreeNode* dfsDeserialize(const std::string& data, int& idx) {
        if (idx >= data.size())
            return nullptr;
        
        // parse 1,2,#,#,3,4,#,#,5,#,#,
        size_t i = data.find(',', idx);
        std::string token = data.substr(idx, i - idx);
        // std::print("token: {}\n", token);
        idx = i + 1;    // the idx right after ','
        if (token == "#") {
            return nullptr;
        }
        TreeNode* cur = new TreeNode(std::stoi(token));
        cur->left = dfsDeserialize(data, idx);
        cur->right = dfsDeserialize(data, idx);
        return cur;
    }
};
