/*
*/
#include <iostream>
#include <assert.h>
using namespace std;

struct BinaryTree
{
	int data;
	BinaryTree* left;
	BinaryTree* right;
};

BinaryTree* newTreeNode(int data)
{
	BinaryTree* newNode = new BinaryTree;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

/*
This getIndex method can be optimized by having a map
Look at http://articles.leetcode.com/2011/04/construct-binary-tree-from-inorder-and-preorder-postorder-traversal.html
*/
int getIndex(int* arr, int val, int size)
{
	for (int i = 0; i<size; i++) {
		if (arr[i] == val)
			return i;
	}
	return -1;
}

const int MAX = 256;
// a fast lookup for inorder's element -> index
// binary tree's element must be in the range of [0, MAX-1]
int mapIndex[MAX];
void mapToIndices(int inorder[], int n) {
	for (int i = 0; i < n; i++) {
		assert(0 <= inorder[i] && inorder[i] <= MAX - 1);
		mapIndex[inorder[i]] = i;
	}
}

// precondition: mapToIndices must be called before entry
BinaryTree* buildInorderPreorder(int in[], int pre[], int n, int offset) {
	//assert(n >= 0);
	if (n == 0) return NULL;
	int rootVal = pre[0];
	int i = mapIndex[rootVal] - offset;  // the divider's index
	BinaryTree* root = newTreeNode(rootVal);
	root->left = buildInorderPreorder(in, pre + 1, i, offset);
	root->right = buildInorderPreorder(in + i + 1, pre + i + 1, n - i - 1, offset + i + 1);
	return root;
}

BinaryTree* buildInorderPostorder(int in[], int post[], int n, int offset) {
	//assert(n >= 0);
	cout << "Input n value is " << n << endl;
	cout << "offset value is " << offset << endl;
	if (n == 0) return NULL;
	int rootVal = post[n - 1];
	cout << "rootVal value is " << rootVal << endl;
	int i = mapIndex[rootVal] - offset;  // the divider's index
	BinaryTree* root = newTreeNode(rootVal);
	root->left = buildInorderPostorder(in, post, i, offset);
	root->right = buildInorderPostorder(in + i + 1, post + i, n - i - 1, offset + i + 1);
	return root;
}
BinaryTree* create_pre_bintree(int* parray, int* iarray, int size)
{
	if (size == 0) return NULL;

	int rootVal = parray[0];
	BinaryTree* root = newTreeNode(rootVal);
	int newIdx = getIndex(iarray, rootVal, size);
	root->left = create_pre_bintree(parray + 1, iarray, newIdx);
	root->right = create_pre_bintree(parray + newIdx + 1, iarray + newIdx + 1, size - newIdx - 1);
	return root;
}

BinaryTree* create_post_bintree(int* postarr, int* inarr, int start, int end, int size){
	if (start > end) return NULL;
	int rootVal = postarr[end-1];
	cout << "root value is " << rootVal << "start value is " << start << ", end value is " << end << endl;
	BinaryTree* root = newTreeNode(rootVal);
	int pos = getIndex(inarr, rootVal, size);
	cout << "pos is " << pos << endl;
	root->left = create_post_bintree(postarr, inarr, start, pos-1,size);
	root->right = create_post_bintree(postarr,inarr,pos+1,end-1,size);
	return root;
}

void printPreOrder(BinaryTree *n1){
	if (n1 == NULL) return;
	std::cout << n1->data << " ";
	printPreOrder(n1->left);
	printPreOrder(n1->right);
}

void printPostOrder(BinaryTree *n1){
	if (n1 == NULL) return;
	printPostOrder(n1->left);
	printPostOrder(n1->right);
	std::cout << n1->data << " ";
}

int main()
{
	int preorder[] = { 7, 10, 4, 3, 1, 2, 8, 11 };
	int inorder[] = { 4, 10, 3, 1, 7, 11, 8, 2 };
	int postorder[] = {4,1,3,10,11,8,2,7};

	BinaryTree* treePre = create_pre_bintree(preorder, inorder, 8);
	std::cout << "The preoder output is: ";
	printPreOrder(treePre);
	cout << endl;

	BinaryTree* treePost = create_post_bintree(postorder, inorder,0,8,8);
	std::cout << "The postorder output is: ";
	printPostOrder(treePost);
	cout << endl;
	/*
	mapToIndices(inorder,8);
	BinaryTree* tree1 = buildInorderPreorder(inorder,preorder,8,0);
	std::cout<<"The preoder output is: ";
	printPreOrder(tree1);
	cout << endl;

	BinaryTree* tree2 = buildInorderPostorder(inorder, postorder, 8, 0);
	std::cout << "The postorder output is: ";
	printPostOrder(tree2);
	cout << endl;
	*/
	getchar();
	return 0;
}