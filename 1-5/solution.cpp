#include<iostream>
#include<string>


using namespace std;

string isReplace(string s1,string s2);
string isInsert(string s1, string s2);

int main()
{
	string s1 = "pale";
	string s2 = "bake";	
	
	if (s2.size()>s1.size())
	{	
		string tmp=s2;
		s2=s1;
		s1=tmp;
	}
	
	if(s1.size()-s2.size()>1)
	{
		cout << "FALSE" << endl;
		return 0;
	}

	if(s1.size()==s2.size())
	{
		cout << isReplace(s1,s2) <<endl;
		return 0;
	}
	else
	{
		cout << isInsert(s1,s2) << endl;
		return 0;
	}
		
	
	return 0;
}



string isReplace(string s1,string s2)
{
	bool replace=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]==s2[i])
			continue;
		if (replace==0)
			replace=1;
		else
			return "NO";
	}	
	return "YES";
}


string isInsert(string s1, string s2)
{
	bool insert=0;
	int j=0;
	for(int i=0;i<s1.size();i++){
		if (s1[i]==s2[j])
			j++;
		else if (insert==0)
				insert=1;
			else
				return "NO";
	}	
	return "YES"	;
	
}


