## Solution of problem 1.5

**Q. Given 2 string return True if there is 1 (or zero) step gap between two strings. A step is insertion a character, deletion a character or replacement of a character**

**Sol.**

**Case 1. Some thing inserted or deleted:**

Insertion and deletion will be same as one can change the string numbering. String 1 can be string 2 and string 2 can be string 1. So only code for extra char. 
If there is a extra char in string 1. Go through the string till it is matching. When char doesn't match - remaining string of the string 1 excluding the non matched char should be equal to the remaining string of the string 2 including the non matched character. 

**Case 2. Some char is replaced:**
Go through the string till it is matching. When char doesn't match - remaining string of the string 1 excluding the non matched char should be equal to the remaining string of the string 2 excluding the non matched character. 


*Implementation in C++ and Python*


