**Solution of problem 2.4**

**Q. Partition the link list in a way that all nodes smaller than X comes before all nodes higher than X. X is given. No need to be sorted**

**Sol.**

Create 4 pointers 
list1h - pointer to the head of list 1.
list1t - pointer to the tail of list 1.
list2h - pointer to the head of list 2.
list2t - pointer to the tail of list 2.

divide the original link list into two link list based on the node values. 

*Implementation in C++*

Book offers more elegant solution using head and tail. I feel my solution more intuitive. 


