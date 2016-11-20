#include<iostream>
#include<string>


using namespace std;

string URLify(string s, int size)
{
	int space=0;
	for(int i=0;i<size; i++){
		if(s[i]==' ')
			space++;
	}
	
	int target=size+2*space-1;
	
	for(int i=size-1;i>=0;i--){
		if(s[i]!=' ')
		{
			s[target]=s[i];
			target--;
		}
		else
		{
			s[target]='0';
			s[target-1]='2';
			s[target-2]='%';
			target=target-3;
		}
					
	}
	return s;	

}

int main()
{

	string s = "My name Mayank    ";
	int size = 14;
	cout<< "Augmented string is : " << URLify(s, size) << endl;
	return 0;
}


