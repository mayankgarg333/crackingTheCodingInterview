## Solution of problem 2.2

**Q. Find kth from the last of a singly link list.**

**Sol.**

**method 1**

Go through the link list. get the size of link list. Go through link list again and return (size-k)th node. 


**method 2**

Create two pointers. First pointer will move k steps before second pointer will start moving. Then increase both pointers together. When pointer will reach at the end of link list, second pointer will be at k nodes before end. 

*Both methods are O(n)time and O(1) space. Both methods are doing exactly same number of calculations. Method 2 is just fancier.*

**method 3**

Recursive method. Keep putting the nodes on the stack then will finishing up the recursively call return the kth node from end. We need a variable which is global and start increasing when stack frame start to pop. 

*Implementation of method 2 and method 3 in C++*
