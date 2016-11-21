#!/usr/bin/python


def compressed_string(s):
	prev='*'
	mark=0
	s2=''
	for char in s:
		print s2
		if char!=prev:
			if mark!=0:
				s2+=str(count)				# C++ also have + operator for string
			s2+=str(char)
			mark=1
			count=1
			prev=char
		else:
			count+=1
	s2+=str(count)
	print s2
	return s2
		

s="aabccccddde"
s2=compressed_string(s)
if len(s2)<len(s):
	print "compressed string is :", s2
else:
	print "compressed string is :", s
