## Solution of problem 1.6

**Q. compress a string as aabccccaaa to a2b1c4a3. Return the compressed string if it is smaller else return the original string.**

**Sol.**

Create another string which keep the char and frequency. Finally compare the length of the new string with the previous string. 

**NOTE** 

Converting integer to string or char* is critical for this problem. It is easier in python, also easier in C++ if to_string is working. (// to string is working with -std=C++11 option while compiling )

*Implementation in C++ and python*
