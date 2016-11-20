#include<iostream>
#include<string>
#include<map> 

using namespace std;


bool isUniqueHash(string s);
bool isUniqueArray(string s);
bool isUniqueBit(string s);

int main()
{
	string s;
	cout << "give an input string \n---> " << endl;
	cin >> s;
	cout << "input string is " << s << endl; 
	cout << "given string is " << isUniqueHash(s) << " as per isUniqueHash function" << endl;
	cout << "given string is " << isUniqueArray(s) << " as per isUniqueArray function" << endl;
	cout << "given string is " << isUniqueBit(s) << " as per isUniqueBit function" << endl;
	return 0;
}

bool  isUniqueHash(string s)
{
	map<char,int> mymap;
	for(int i=0; i<s.size();i++){
		if(mymap.find(s[i])!=mymap.end())
			return false;
		else
			mymap[s[i]]=1;
	}
	return true;
}

bool  isUniqueArray(string s)		// assuming ascii characters 
{	
	if (s.size()>128)
		return false;
	int array[128]={};
	for(int i=0; i<s.size();i++){
			array[(int)s[i]]+=1;
			if (array[(int)s[i]]>1)
				return false;
	}
	return true;

}

bool  isUniqueBit(string s)			// Assuming a-z characters 
{
	if (s.size()>26)
		return false;
	int value=0;
	for(int i=0; i<s.size();i++){
		int shift=(int)s[i] - (int)'a';
		int tmp = value & (1<<shift);
		if (tmp>0)
			return false;
		value = value |  (1<<shift);
			
	}
	return true;

}
