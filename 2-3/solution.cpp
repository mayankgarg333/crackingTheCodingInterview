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
Node* get_pointer_node_k(Node* root,int k);
void remove_node(Node* to_remove);

int main()
{
	int k=4;	
	int array[]={1,3,7,5,1,2,3,5,4,6,5,2,3,7,8,6,9,0,1,0};
	int size=sizeof(array)/sizeof(array[0]);
	Node* root=create_link_list(array,size);
	print_link_list(root);
	Node* to_remove=get_pointer_node_k(root,k);
	remove_node(to_remove);
	print_link_list(root);
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


Node* get_pointer_node_k(Node* root,int k)
{
	for(int i=0;i<k-1;i++)
		root=root->next;
	return root;

}



void remove_node(Node* to_remove)
{
	to_remove->number=to_remove->next->number;
	to_remove->next=to_remove->next->next;
}











