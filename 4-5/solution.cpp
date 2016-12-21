#include<iostream>

using namespace std;


struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;	
	TreeNode(int x=0): data(x), left(NULL), right(NULL){}
};





void add_element(TreeNode **node, int *A, int i, int j)
{
	if(i>j)
		return;
	if(i==j){
		*node=new TreeNode(A[i]);
		return;
	}
	int mid=(i+j)/2;
	*node=new TreeNode(A[mid]);
	add_element(&((*node)->left),A,i,mid-1);
	add_element(&((*node)->right),A,mid+1,j);
	return;
}


bool check_element(TreeNode* root, int min, int max)
{
	if(root==NULL)
		return true;
	if(root->data<max && root->data>min)
		return (check_element(root->left,min,root->data) && check_element(root->right, root->data,max) );
	return false;
}

int main()
{
	
	int A[]={1,2,4,7,8,11,15,14};
	int size=sizeof(A)/sizeof(A[0]);
	TreeNode* root;
	add_element(&root,A,0,size-1);
	cout << check_element(root,-100,100) <<endl;
	
	return 0;
}
