#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

/*树结点的定义(请不要在代码中定义该结构)
*/
struct TreeNode {
   int val;
   TreeNode *left, *right;
   bool isLeftThread, isRightThread;
   TreeNode (const int& v) 
      : val(v)
      , left(NULL)
      , right(NULL)
      , isLeftThread(false)
      , isRightThread(false)
   {}
};

int str2i(const string& s)
{
   istringstream iss(s);
   int rtn;
   iss >> rtn;
   return rtn;
}

TreeNode* fromArray(const vector<string>& input)
{
   queue<TreeNode *> que;
   int p(0);
   TreeNode *head = new TreeNode(str2i(input[p++]));
   que.push(head);
   while ( !que.empty() && p < input.size() )
   {
      TreeNode *curr = que.front();
      que.pop();
      if ( input[p] != "#" )
      {
         TreeNode *left = new TreeNode(str2i(input[p]));
         curr->left = left;
         que.push(left);
      }
      ++p;
      if ( p < input.size() && input[p] != "#" )
      {
         TreeNode *right = new TreeNode(str2i(input[p]));
         curr->right = right;
         que.push(right);
      }
      ++p;
   }
   return head;
}

std::ostream& operator<<(std::ostream& os, TreeNode *head)
{
   os << "[";
   if ( NULL == head )
   {
      os << "[#]";
      return os;
   }

   std::queue<TreeNode *> que;
   que.push(head);
   while ( que.size() > 0 )
   {
      TreeNode *curr = que.front();
      que.pop();
      cout << "(" << curr->val 
           << "," << (curr->isLeftThread ? curr->left->val : 0)
           << "," << (curr->isRightThread ? curr->right->val : 0)
           << ")" << endl;

      if ( curr->isLeftThread == false 
        && curr->left != NULL )
      {
         que.push(curr->left);
      }

      if ( curr->isRightThread == false
        && curr->right != NULL )
      {
         que.push(curr->right);
      }
   }
   os << "]";
   return os;
}



TreeNode *traverse(TreeNode *root, TreeNode *pre)
{
   if ( root->left )
   {
      TreeNode *last = traverse(root->left, pre);
      last->right = root;
      last->isRightThread = true;
   }
   else if ( pre )
   {
      root->left = pre;
      root->isLeftThread = true;
   }

   TreeNode *last;
   if ( root->right )
   {
      last = traverse(root->right, root);
   }
   else
   {
      last = root;
   }
   return last;
}

void convertToThreadedTree(TreeNode *root) {
   if ( root == NULL ) return;
   traverse(root, NULL);
}

int main()
{
   vector<string> tree;
   string input;
   while ( getline(cin, input) )
   {
      tree.push_back(input);
   }
   TreeNode *head = fromArray(tree);
   cout << head << endl;

   convertToThreadedTree(head);
   cout << head << endl;

   return 0;
}

