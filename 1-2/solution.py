#!/usr/bin/python

def isPermuHash(s1,s2):
	if len(s1)!=len(s2):
		return False
	D={}
	for char in s1:
		D[char]=D.get(char,0)+1;
	for char in s2:
		D[char]=D.get(char,0)-1;
		if D[char]<0:
			return False	
	return True	

def isPermuArray(s1,s2):
	if len(s1)!=len(s2):
		return False						# Assuming ASCII characters
	L=[0]*128;
	for char in s1:
		L[ord(char)]+=1
	for char in s2:
		L[ord(char)]-=1
		if L[ord(char)]<0:
			return False
	return True




s1=raw_input("Enter the first input string")
s2=raw_input("Enter the second input string")
print "are given strings permutation of each other? ", isPermuHash(s1,s2)
print "are given strings permutation of each other? ", isPermuArray(s1,s2)






