/* 2017.01.07 21:01
 * P_457
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
	public:
		TreeNode();
		TreeNode(const string &s);
		TreeNode(const TreeNode&);
		TreeNode& operator=(const TreeNode &);
		~TreeNode();
	public:
		void DeleteRecurse(TreeNode *node);
		string value;
		int count;
		TreeNode *left;
		TreeNode *right;
};
TreeNode::TreeNode(): count(1), left(NULL), right(NULL)
{
}
TreeNode::TreeNode(const string &s): value(s), count(1), left(NULL), right(NULL)
{
}
TreeNode::TreeNode(const TreeNode &orig): value(orig.value), count(orig.count)
{
	left = orig.left == NULL ? NULL : new TreeNode(*orig.left);
	right = orig.right == NULL ? NULL : new TreeNode(*orig.right);
}
TreeNode& TreeNode::operator=(const TreeNode &rhs)
{
	value = rhs.value;
	count = rhs.count;
	TreeNode *tmp = new TreeNode(*rhs.left);
	DeleteRecurse(left);
	left = tmp;
	tmp = new TreeNode(*rhs.right);
	DeleteRecurse(right);
	right = tmp;
}
TreeNode::~TreeNode()
{
	DeleteRecurse(left);
	left = NULL;
	DeleteRecurse(right);
	right = NULL;
}
void TreeNode::DeleteRecurse(TreeNode *node)
{
	if (node->left != NULL)
		DeleteRecurse(node->left);
	if (node->right != NULL)
		DeleteRecurse(node->right);
	delete node;
}

class BinStrTree {
	public:
		BinStrTree();
		BinStrTree(const BinStrTree&);
		BinStrTree& operator=(const BinStrTree&);
		~BinStrTree();
	private:
		TreeNode *root;
};
BinStrTree::BinStrTree(): root(new TreeNode)
{
}
BinStrTree::BinStrTree(const BinStrTree &orig): root(new TreeNode(*orig.root))
{
}
BinStrTree& BinStrTree::operator=(const BinStrTree &rhls)
{
	TreeNode *tmp = new TreeNode(*rhls.root);
	delete root;
	root = tmp;
	return *this;
}

int main(int argc, char **argv)
{

	return 0;
}

