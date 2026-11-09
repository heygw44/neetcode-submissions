
class Codec {
public:
    string serialize(TreeNode* root) {
        string res;
        dfsSerialize(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string token;
        stringstream ss(data);

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        int i = 0;
        return dfsDeserialize(tokens, i);
    }

private:
    void dfsSerialize(TreeNode* node, string& res) {
        if (!node) {
            res += "N,";
            return;
        }

        res += to_string(node->val) + ",";

        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    TreeNode* dfsDeserialize(vector<string>& tokens, int& i) {
        if (tokens[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[i]));
        i++;

        node->left = dfsDeserialize(tokens, i);
        node->right = dfsDeserialize(tokens, i);

        return node;
    }
};
