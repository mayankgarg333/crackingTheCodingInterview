#include<iostream>
#include<string>


using namespace std;

struct Node{
	int number;
	int min;
	struct 	Node* next;
	
	Node(int x=0, int m=0): number(x), min(m), next(NULL){}
};

class Stack{
	public:
		Node* start;		
		int size,min;
		Stack(){
			start=NULL;
			size=0;
		}
		
		void push(int data){
			if(size==0){
				start=new Node;
				start->number=data;
				start->min=data;
				min=data;
				size++;
			}
			else{
				Node* tmp=new Node;
				tmp->next=start;
				tmp->number=data;
				if(min<data)
					tmp->min=min;
				else{
					tmp->min=data;
					min=data;
				}
				start=tmp;
				size++;
			}
		}

		int pop(){
			if(size==0)
				return -1;
			else {
				int tmpData=start->number;
				start=start->next;
				size--;
				return tmpData;
			}
		}

		int top(){
			if(size==0)
				return -1;
			else
				return start->number;
		}

		void show(){
			Node *tmp=start;
			for (int i=0; i<size;i++){
				cout<< " -> " << tmp->number ;
				tmp=tmp->next;
			}		
			cout << endl;

		}
		
		int minFunc(){
			if(size>0)
				return start->min;
			return -1;
		}
	

		

};

int main()
{
	int input,data;		
	Stack firstStack;
	while(true){
	
		cout << "Press 1 to push, 2 to pop, 3 to top, 4 to show and 5 to min of the Stack" << endl;	
		cin >> input;
		if(input==1){
			cout << "Enter the number to push" << endl;
			cin >> data;
			firstStack.push(data);
		}
		if(input==2){
			data=firstStack.pop();
			cout << "Poped number is " << data << endl;
		}
		if(input==3){
			data=firstStack.top();
			cout << "Top number is " << data << endl;
		}
		if(input==4){
			cout << "Whole stack is :" << endl;
			firstStack.show();
		}
		if(input==5){
			cout << "Minimum in the stack is :" << firstStack.minFunc() << endl;
			
		}
			
		
	}


	return 0;
}
