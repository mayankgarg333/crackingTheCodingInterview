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
void delete_duplicate_1(Node *root);
void delete_duplicate_2(Node *root);
void print_link_list(Node *root);


int main()
{
	int array[]={1,3,7,5,1,2,3,5,4,6,5,2,3,7,8,6,9,0,1,0};
	int size=sizeof(array)/sizeof(array[0]);
	Node* root=create_link_list(array,size);
	
	print_link_list(root);
	delete_duplicate_1(root);
	delete_duplicate_2(root);	
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



void delete_duplicate_1(Node *root)    //Using hash table
{
	map<int,int> mymap;
	mymap[root->number]=1;
	Node* prev=root;
	root=root->next;
	while(root!=NULL)
	{
		mymap[root->number]+=1;
		if(mymap[root->number]>1)
		{
			prev->next=root->next;
			root=root->next;
		}
		else
		{
			prev=root;
			root=root->next;
		}
	}

}


void delete_duplicate_2(Node *root) // No extra data structure
{
	while(root!=NULL)
	{
		Node* future=root->next;
		int val=root->number;
		Node* prev=root;
		while(future!=NULL)
		{
			if(future->number==val)
			{
				// delete the node
				prev->next=future->next;
				future=future->next;
			}
			else
			{
				prev=future;
				future=future->next;
			}
		}
			
		root=root->next;	
	}


}










