#include<iostream>
#include<string>


using namespace std;

struct Node{
	int number;
	struct 	Node* next;
	
	Node(int x=0): number(x), next(NULL){}
};

class Stack{   						//same as general implementation
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




class Queue{							// Queue implementation is modified. Now use stack
	public:
		Stack First, Second;
		int size2;
		Queue(){
			size2=0;
		}
		
		void Add(int data){
				First.push(data);
				size2++;
		}

		int Remove(){
			if(size2==0)	
				return -2;
			if(Second.size>0){
				size2--;
				return Second.pop();
			}
			else {
				
				FirstDumpOnSecond();
				size2--;
				return Second.pop();
			}
		}

		int top(){
			if(size2==0)
				return -1;
			if(Second.size>0)
				return Second.top();
			else{
				FirstDumpOnSecond();
				return Second.top();
			}
			
		}

		void show(){
			cout << "First Stack : " << endl;
			First.show();

			cout << "Second Stack : " << endl;
			Second.show();

		}
	
		void FirstDumpOnSecond(){
			for(int i=0; i<size2;i++){
				Second.push(First.pop());
			}
		}
		

};


int main()
{
	int input,data;		
	Queue firstQueue;
	while(true){
	
		cout << "Press 1 to Add, 2 to Remove, 3 to top and 4 to show the Queue " << firstQueue.size2 << endl;	
		cin >> input;
		if(input==1){
			cout << "Enter the number to Add" << endl;
			cin >> data;
			firstQueue.Add(data);
		}
		if(input==2){
			data=firstQueue.Remove();
			cout << "Removeed number is " << data << endl;
		}
		if(input==3){
			data=firstQueue.top();
			cout << "Top number is " << data << endl;
		}
		if(input==4){
			cout << "Whole Queue is :" << endl;
			firstQueue.show();
		}
		
	}


	return 0;
}


