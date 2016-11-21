## Solution of problem 1.4

**Q. Check if any permutation of the given string will be palindrome.**

**sol.**

A string will be palindrome only when at max one character has even frequency. So the solution is to get the frequency of each letter and if there are more than 1 letter with odd frequency, the answer is no. 

**method 1** 
Use hash table or array to same the frequency of the characters. 

**method 2**
Exact count of the characters is not required, only the even and odd is required. As there are only two possible options, bit manipulation can be used. This will work only if the characters are from a-z. 

1. take a integer.
2. loop though the string 
3. toggle the bit number based on the character.
4. finally only 1 bit should have value 1.

**How to toggle the bit of a int**
Zero to one : place 1 where you want to convert and rest zero and take OR
one to zero : place 1 where you want to convert and rest zero. Negate it and take AND

''' c++
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
'''

**How to check if there is only one bit of value 1**
Easy solution: check the last bit, if last bit is 0, shift right, if last bit is 1, remove that rest of the number should 0. 
Smart solution : removing 1 from the given number will change all the bits if there is only single 1 in the number. Then take and with the original number

//

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



*Method 2 is implemented in c++ and python*
