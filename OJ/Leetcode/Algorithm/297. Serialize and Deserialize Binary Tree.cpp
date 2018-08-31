/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void toString(TreeNode* root, stringstream& sout)
    {
        if(root==NULL)
            sout<<"#"<<" ";
        else
        {
            sout<<root->val<<" ";
            toString(root->left, sout);
            toString(root->right, sout);
        }
    }

    TreeNode* toTree(stringstream& sin)
    {
        string word;
        sin>>word;
        if(word == "#")
            return NULL;
        else
        {
            TreeNode* root = new TreeNode(atoi(word.c_str()));
            root->left = toTree(sin);
            root->right = toTree(sin);
            return root;
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream sout;
        toString(root, sout);
        return sout.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream sin(data);
        return toTree(sin);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
