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
Node* partition(Node* root,int x);
Node* partition2(Node* root,int x);
Node* partition_failed(Node* root,int x);

int main()
{
	int x=4;	
	int array[]={1,3,7,5,2,3,4,2,6,7,2,3,4,5,21,1,2,3,4,6,7,89,4,3,2};
	int size=sizeof(array)/sizeof(array[0]);
	Node* root=create_link_list(array,size);
	print_link_list(root);
	//Node* new_root=partition(root,x);
	//print_link_list(new_root);
	Node* new_root=partition2(root,x);
	print_link_list(new_root);
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




Node* partition(Node* root, int x)			//Book solution
{
	Node* list1=root;
	Node* list2=root;
	Node* tmp;
	
	while(root!=NULL)
	{	
		tmp=root->next;
		if(root->number <x)
		{
			root->next=list1;
			list1=root;
		}
		else
		{
			list2->next=root;
			list2=root;
		}
		root=tmp;
	}
	list2->next=NULL;
	return list1;

}


Node* partition2(Node* root, int x)							// Easier to understand, bifurcate the list based on the node values
{
	Node* list1t;
	Node* list2t;
	bool first_list1=true;
	bool first_list2=true;
	Node* list1h;
	Node* list2h;
	//cout << " -------------------------------------------- " << endl;
	//print_link_list(root);
	while(root!=NULL)
	{	
		//cout << "root number " << root->number <<endl;
		if(root->number <x && first_list1==true)
		{
			list1t=root;	
			list1h=list1t;	
			first_list1=false;
			//cout << "root number to be added in list 1 (first) " << root->number <<endl;
		}
		else if (root->number >= x && first_list2==true)
		{
			list2t=root;	
			list2h=list2t;
			first_list2=false;		
			//cout << "root number to be added in list 2 (first) " << root->number <<endl;
		}
		else if (root->number <x)
		{
			list1t->next=root;
			list1t=list1t->next;
			//cout << "root number to be added in list 1 " << root->number <<endl;
		}
		else
		{
			list2t->next=root;
			list2t=list2t->next;
			//cout << "root number to be added in list 2 " << root->number <<endl;
		}
		root=root->next;
	}
	list2t->next=NULL;
	print_link_list(list1h);
	print_link_list(list2h);
	list1t->next=list2h;
	return list1h;

}































Node* partition_failed(Node* root, int x)				// This implemetation failed. Very imp to realize why it failed
{
	Node* list1,*next;
	Node* list1P=list1;
	
	cout << "list 1: " << list1  <<endl;
	cout << "list 1p: " << list1P <<endl;
	cout << "root " << root << endl;
	
	while(root!=NULL)
	{	
		cout << "print list " << endl;
		print_link_list(list1P);
		next=root->next;
		if(root->number <x)
		{
			list1=root;
			cout << "list 1 number " << list1->number << endl;
			//root->next=list1;
		}
		root=next;

	}
	cout << " --------------------------------------------- " << endl;
	cout << "list 1p: " << list1P << endl;
	cout << "list 1p: " << list1P->next << endl;
	cout << "list 1p: " << list1P->next->next << endl;
	return list1P;

}




