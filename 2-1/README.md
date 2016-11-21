## Solution of problem 2.1

**Q. delete the repetitive nodes from a unsorted link list. Follow up without extra space.**

**Sol.**

**With extra space**
keep a hash table for the data seen so far, if it is seen again, delete the Node. O(n) time, O(n) space.


**Without extra space**
Traverse the whole list for each element to check for repetitiveness. O(n^2) time and O(1) space.

*Both solution implemented in C++*
