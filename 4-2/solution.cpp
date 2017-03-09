#include<iostream>

using namespace std;


struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;	
	TreeNode(int x=0): data(x), left(NULL), right(NULL){}
};



void print_inorder(TreeNode* root);

void add_element(TreeNode *node, int *A, int i, int j)
{
	if(i>j)
		return;
	if(i==j){
		node->data=A[i];
		print_inorder(node);
		cout << "change " << i << j << endl;
		return;
	}
	
	int mid=(i+j)/2;
	node->data = A[mid];
	print_inorder(node);
	cout << "change " << i << mid << j << endl;
	TreeNode* tmp = new TreeNode;
	node->left = tmp;
	tmp = new TreeNode;
	node->right = tmp;
	add_element((node->left),A,i,mid-1);
	add_element((node->right),A,mid+1,j);
	return;
}

void print_preorder(TreeNode* root){
	if(root==NULL)
		return;
	cout << root->data << " ";
	print_preorder(root->left);
	print_preorder(root->right);
	return;
}

void print_inorder(TreeNode* root){
	if(root==NULL)
		return;
	print_inorder(root->left);
	cout << root->data << " ";
	print_inorder(root->right);
	return;
}



int main()
{
	
	int A[]={1,2,4,7,8,11,14};
	int size=sizeof(A)/sizeof(A[0]);
	TreeNode* root = new TreeNode;
	add_element(root,A,0,size-1);
	print_preorder(root);
	cout <<endl;
	print_inorder(root);
	cout<< endl;
	return 0;
}
