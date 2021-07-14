/*
Huffman Encoding
================

Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency. Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.
Note: If two elements have same frequency, then the element which occur at first will be taken on the left of Binary Tree and other one to the right.

Example 1:
S = "abcdef"
f[] = {5, 9, 12, 13, 16, 45}
Output: 
0 100 101 1100 1101 111
Explanation:
HuffmanCodes will be:
f : 0
c : 100
d : 101
a : 1100
b : 1101
e : 111
Hence printing them in the PreOrder of Binary Tree.

Your Task:
You don't need to read or print anything. Your task is to complete the function huffmanCodes() which takes the given string S, frequency array f[ ] and number of characters N as input parameters and returns a vector of strings containing all huffman codes in order of preorder traversal of the tree.

Expected Time complexity: O(N * LogN) 
Expected Space complexity: O(N) 

Constraints:
1 ≤ N ≤ 26
*/

struct node
{
  int f;
  char ch;
  node *left, *right;
  node(int y, char x = '\0')
  {
    f = y;
    ch = x;
    left = right = NULL;
  }
};

struct cmp
{
  bool operator()(node *a, node *b) const
  {
    return a->f > b->f;
  }
};

vector<string> huffmanCodes(string S, vector<int> f, int N)
{
  priority_queue<node *, vector<node *>, cmp> q;
  for (int i = 0; i < N; ++i)
  {
    node *temp = new node(f[i], S[i]);
    q.push(temp);
  }

  while (q.size() > 1)
  {
    auto left = q.top();
    q.pop();
    auto right = q.top();
    q.pop();
    node *n = new node(left->f + right->f);
    n->left = left;
    n->right = right;
    q.push(n);
  }

  string str;
  vector<string> ans;
  preorder(q.top(), str, ans);
  return ans;
}

void preorder(node *root, string &str, vector<string> &ans)
{
  if (root == NULL)
    return;
  if (root->ch != '\0')
  {
    ans.push_back(str);
    //cout << str << endl;
  }

  str += '0';
  preorder(root->left, str, ans);
  str.pop_back();

  str += '1';
  preorder(root->right, str, ans);
  str.pop_back();
}