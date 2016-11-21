#!/usr/bin/python
def isReplace(s1,s2):
	replace=0	
	for i in range(len(s1)):
		if s1[i]==s2[i]:
			continue
		if replace==0:
			replace=1
		else:
			return "NO"
	return "YES"

def isInsert(s1,s2):
	insert=0
	j=0
	for i in range(len(s1)):
		if s1[i]==s2[j]:
			j=j+1
		elif insert==0:
			insert=1
		else:
			return "NO"
	return "YES"




s1="pale"
s2="ple"


if len(s2)>len(s1):
	tmp=s2	
	s2=s1
	s1=tmp

if len(s1)-len(s2)>1:
	print "NO"
	quit()

if len(s1)==len(s2):
	print isReplace(s1,s2)
	quit()

print isInsert(s1,s2)


