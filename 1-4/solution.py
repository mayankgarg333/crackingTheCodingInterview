#!/usr/bin/python

def toggle(val,num):
	if (val & 1<<num) > 0:    # means the bit at the num position is 1
		val=val & ~(1<<num)  # one converted to zero
	else:
		val=val | (1<<num)   # zero converted to one. 
	return val



def isSingle(val):
	if ((val-1) & val) == 0:
		return True
	else:
		return False


def isPal(s):
	value=0
	for char in s:
		value=toggle(value,ord(char)-ord('a'))
	return isSingle(value)


s="asdfassd"
print isPal(s)

