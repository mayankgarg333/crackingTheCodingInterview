## Solution of problem 1.3

**Q. Replace space in the string with '%20'. There are suffiient space available in the original string to expend in the end** 

Input: "My name Mayank    " , 14 (length of the relevent string)
Output "My%20name%20Mayank" 

**Sol**

**method 1**
It is possible to create another string which will copy the original string until there is a space. If there is a space it will insert '%20' and then continue to scan. This will be O(n) time and O(n) space solution. 

**method 2** 
A better method will be to shift the string as there are extra space avialble within the given string. This will be O(n) time and O(1) space. 
step of the solution:
1. Calculate the number of spaces in the relevent portion of the string. (for loop 1)
2. start filling the string backward from length of string + 2*number of spaces. (for loop 2)

*method 2 is implemented using C++ and python*

**Python string are immutable**
Python strings are immutable so have to create another string for stoing the characters of the given string and placing '%20' when there is a space. 
