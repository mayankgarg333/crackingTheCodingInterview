#!/usr/bin/python

def URLify(s,size):
	space=0
	for i in range(size):
		if s[i]==' ':
			space=space+1

	target=size+2*space-1
	for i in range(size-1,-1,-1):
		if s[i]==' ':
			s[target-2:target+1]='%20'			# Not working, Python string is immutable
			target=target-3		
		else:
			s[target]=s[i]						# Not working, Python string is immutable
			target=target-1
	return s


def URLify2(s,size):
	st=''
	for i in range(size):
		if s[i]==' ':
			st+='%20'
		else:
			st+=s[i]
	return st



s="my name Mayank    "
size=14

print URLify2(s,size)
