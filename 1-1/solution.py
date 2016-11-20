#!/usr/bin/python

def isUniqueHash(s):
	D={}
	for char in s:
		D[char]=D.get(char,0)+1;
		if D[char]>1:
			return False;
	return True	

def isUniqueArray(s):						# Assuming ASCII characters
	L=[0]*128;
	for char in s:
		L[ord(char)]+=1
		if L[ord(char)]>1:
			return False
	return True

def isUniqueBit(s):							# Assuming a-z characters
	value=0
	for char in s:
		shift=ord(char)-ord('a')
		tmp=value & (1<< shift)
		if tmp>0:
			return False
		value = value | (1<<shift)
	return True



s=raw_input("Enter the input string")
print "input string is Unique ", isUniqueHash(s) , " using hash function"
print "input string is Unique ", isUniqueArray(s) , " using array"
print "input string is Unique ", isUniqueBit(s) , " using bit manuplation"











