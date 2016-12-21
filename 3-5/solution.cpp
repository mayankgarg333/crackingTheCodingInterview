#include<iostream>
#include<string>


using namespace std;

struct Node{
	int number;
	struct 	Node* next;
	
	Node(int x=0): number(x), next(NULL){}
};

class Stack{
	public:
		Node* start;		
		int size;
		Stack(){
			start=NULL;
			size=0;
		}
		
		void push(int data){
			if(size==0){
				start=new Node;
				start->number=data;
				size++;
			}
			else{
				Node* tmp=new Node;
				tmp->next=start;
				tmp->number=data;
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
};



void Stack_sorted(Stack& first){
	int mini;
	if(first.size==0){
		first.show();
		return;}

	Stack tmp;
	while (first.size>0){
		/*
		cout << "Details of the loop: " << endl;
		cout << mini << endl;
		cout << " first " << endl; first.show();
		cout << " tmp " << endl; tmp.show();*/

// Critical code (Only 4 lines)
		mini=first.pop();
		while(tmp.size>0 && tmp.top()>mini)
			first.push(tmp.pop());
		tmp.push(mini);

	}
	int s=tmp.size;
	for(int i=0;i<s;i++)
		first.push(tmp.pop());
}




int main()
{
	int input,data;		
	Stack firstStack;
	while(true){
	
		cout << "Press 1 to push, 2 to pop, 3 to top, 4 to show and 5 to sort the Stack" << endl;	
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
			cout << "Sorted stack is :" << endl;
			Stack_sorted(firstStack);
		}		
	}


	return 0;
}
