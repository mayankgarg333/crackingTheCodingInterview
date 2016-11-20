## Solution of problem 1.2

**Q. Given two strings, check if one is permutation of the other**

**sol.**

**method 1**
Sort both the strings. After sorting both should be identical. 
O(n log n) time, o(1) space , string will be changed after the program. 

**method 2**
Use hash function to check if there is any letter extra in the second string. 
O(n) time , O(n) space... space can be argued to be O(c) where c is different type of characters. So constant space arguably. 
Again the implementation can be hash based or array based in case type of characters are fixed.

*In both cases check string length first, they should be equal*

**Note** 
Here no bit manipulation is possible.
Some code reused from problem 1.1. 


*Hash and array implementation in c++ and python*
