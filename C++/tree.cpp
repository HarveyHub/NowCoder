#include<iostream>
using namespace std;

struct TreeNode
{
	TreeNode(int v)
	{
		this->left = NULL;
		this->right = NULL;
		this->value = v;
	}
	TreeNode *left, *right;
	int value;
};

void BSP_insert(TreeNode *&root, int value)
{
	if(root == NULL)
	{
		root = new TreeNode(value);
		return;
	}
	if(value < root->value)
	{
		BSP_insert(root->left, value);
	}
	else
	{
		BSP_insert(root->right, value);
	}
}

void BSP_preOrder(TreeNode* root)
{
	
	if(root == NULL)
		return;
	cout << root->value << " ";
	BSP_preOrder(root->left);
	BSP_preOrder(root->right);
	
}

void BSP_midOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	BSP_preOrder(root->left);
	cout << root->value << " ";
	BSP_preOrder(root->right);
	
}

void BSP_overOrder(TreeNode* root)
{
	if(root == NULL)
		return;
	BSP_preOrder(root->left);
	BSP_preOrder(root->right);
	cout << root->value << " ";
}

int getHeigth(TreeNode* root)
{
	if(root == NULL)
		return 0;
	else
	{
		cout << root->value << endl;
		int left = getHeigth(root->left);
		int right = getHeigth(root->right);
		return max(left, right) + 1;
	}
}
int main()
{
	TreeNode* root = NULL;
	int a[] = {5, 2, 9, 4, 7, 6, 1, 3, 8};
	int len = sizeof(a) / sizeof(int);
	for(int i = 0; i < len; i++)
	{
		BSP_insert(root, a[i]);
	}
	BSP_preOrder(root);
	cout << endl;
	cout << getHeigth(root) << endl;
}