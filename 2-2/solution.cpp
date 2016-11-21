#include<iostream>
#include<map>

using namespace std;



struct Node
{
	int number;	
	struct Node *next;
	Node(int x=0) : number(x), next(NULL) {}
};

Node* create_link_list(int a[],int size);
void print_link_list(Node *root);
int kthNodeFromEnd_2(Node* root, int k);
int kthNodeFromEnd_3(Node* root, int k);
Node* recursive_func(Node* root,int k, int& i);

int main()
{
	int k=4;	
	int array[]={1,3,7,5,1,2,3,5,4,6,5,2,3,7,8,6,9,0,1,0};
	int size=sizeof(array)/sizeof(array[0]);
	Node* root=create_link_list(array,size);
	print_link_list(root);
	cout << "Kth node from the end : " << kthNodeFromEnd_2(root,k) <<endl; 		//k=1 will give the last node. 
	cout << "Kth node from the end : " << kthNodeFromEnd_3(root,k) << endl; 
	return 0;
}


Node* create_link_list(int a[], int size)
{

	Node* root=new Node;
	Node* root2=root;
	for(int i=0;i<size;i++){
		root->number=a[i];
		
		if(i<size-1)
		{
			root->next=new Node;
			root=root->next;
		}
	}	
	return root2;
}



void print_link_list(Node *root)
{
	int first=1;
	while(root!=NULL)
	{	
		if(first==1)
			cout << root->number;
		else
			cout << "->" << root->number;
		first=0;	
		root=root->next;
	}
	cout << endl;
}



int kthNodeFromEnd_2(Node* root, int k)
{
	Node * second=root;
	for(int i=0;i<k;i++)
	{
		root=root->next;
	}	
	while(root!=NULL)
	{	
		root=root->next;
		second=second->next;
	}	
	return second->number;
}

int kthNodeFromEnd_3(Node* root, int k)
{
	int i=0;
	Node* second=recursive_func(root,k,i);
	return second->number;
}

Node* recursive_func(Node* root,int k, int& i)
{
	if(root==NULL)
		return root;
	Node* to_rtn= recursive_func(root->next,k,i);
	i=i+1;
	if(i==k)
		return root;
	else
		return to_rtn;

}









