#include<iostream>
#include<string>

using namespace std;

bool isPal(string s);
int toggle(int val, int num);
bool isSingle(int val);

int main()
{
	
	string s="asdfeasd";
	if (isPal(s)==true)
		cout << "YES" << endl;
	else
		cout << "FALSE" << endl;
	return 0;
}



bool isPal(string s)
{
	int value=0;	
	for(int i=0;i<s.size();i++){
		int bitnum=(int)s[i]- (int)'a';
		value=toggle(value,bitnum);		
	}
	return isSingle(value);
}



int toggle(int val, int num)
{
	if( (val & 1<<num) >0)   // means the bit at the num position is 1
	{
		val=val & ~(1<<num); // one converted to zero
	}
	else
	{
		val=val | (1<<num); // zero converted to one. 
	}
	return val;
}


bool isSingle(int val)
{
	/*
	// Easy method
	while(1){
		if ((val & 1)==0)
			val=val>>1;
		else if ( (val & 1) == 1 && (val>>1)==0)
				return true;
			else
				return false;
	}
	*/

	// smart method
	
	if(((val-1) & val) == 0)
		return true;
	else
		return false;
}




