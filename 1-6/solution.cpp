#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string compressed_string(string s);
string push_back_int(string s, int num);

int main()
{
	string s="aabccccdde";
	string s_rtn=compressed_string(s);
	
	if (s.size()>=s_rtn.size()) 
	{
		cout << "compressed string is: " << s << endl;
	}
	else
	{
		cout << "compressed string is: " << s_rtn << endl;
	}

	return 0;
}



string compressed_string(string s)
{
		
	string s2;
	int mark=0; // for first iteration
	int count=0;// count the number of repitation of the repitative char
	char prev='*';
	for(int i =0; i<s.size() ; i++){
		if(prev!=s[i])
		{
			if(mark!=0)
				s2=push_back_int(s2,count);
			s2.push_back(s[i]);
			count=1;
			prev=s[i];
			mark=1;
		}
		else
		{
			count++;
		}
		
	}
	s2=push_back_int(s2,count);
	return s2;	
}




string push_back_int(string s, int num)			// coonverting int to char or string (tricky)
{
	stringstream ss;
	ss << num;
	string s2;
	ss >> s2;
	for(int i=0; i<s2.size();i++)
		s.push_back(s2[i]);
	return s;

}
