#include<iostream>
#include<string>
#include<map> 

using namespace std;


bool isPermuHash(string s, string s2);
bool isPermuArray(string s1, string s2);


int main()
{
	string s1,s2;
	cout << "give an input string s1\n---> " << endl;
	cin >> s1;
	cout << "input string s1 is " << s1 << endl; 
	cout << "give an input string s2\n---> " << endl;
	cin >> s2;
	cout << "input string s2 is " << s2 << endl; 
	cout << "are given strings permutation of each other? " << isPermuHash(s1,s2) <<  endl;
	cout << "are given strings permutation of each other? " << isPermuArray(s1,s2) << endl;

	return 0;
}



bool  isPermuHash(string s1, string s2)
{
	if(s1.size()!=s2.size())
		return false;
	map<char,int> mymap;
	for(int i=0; i<s1.size();i++){
		mymap[s1[i]]+=1;
	}
	for(int i=0; i<s2.size();i++){
		if(mymap.find(s2[i])==mymap.end())			// not needed 
			return false;
		mymap[s2[i]]-=1;
		if (mymap[s2[i]]<0)
			return false;
	}
	return true;
}

bool  isPermuArray(string s1, string s2)		// assuming ascii characters 
{	
	if(s1.size()!=s2.size())
		return false;
	int array[128]={};
	for(int i=0; i<s1.size();i++){
			array[(int)s1[i]]+=1;
	}
	for(int i=0; i<s2.size();i++){
		array[(int)s2[i]]-=1;
		if (array[(int) s2[i]]<0)
			return false;			
	}
	return true;

}

