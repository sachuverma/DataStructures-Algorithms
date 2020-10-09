class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "#";
        
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    
    int i=0;
    TreeNode* des(string data){
        if(i<data.size() && data[i]==',')i++;
        if(i>=data.size() || data[i]=='#'){
            i+=2;
            return nullptr;
        }
        string s="";
        while(i<data.size() && data[i]!=','){
            s+=data[i];
            i++;
        }
        
        TreeNode* node=new TreeNode(stoi(s));
        
        node->left=des(data);
        node->right=des(data);
        cout<<node->val<<" ";
        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        return des(data.substr(0,data.size()-2));
    }
};