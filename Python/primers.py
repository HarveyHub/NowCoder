#coding:utf-8
import sys
try:
	sys.stdin = open("primers.txt");
except IOError, e:
	print e;
	sys.exit(0)

	
def isprimer(x):
	i = 2;
	flag = True;
	while(i*i <= x):
		if(x % i == 0):
			flag = False;
			break;
		i += 1;
	return flag;
	
	
while(True):
	try:
		n = int(raw_input());
		result = [];
		for i in range(2, n):
			if(i % 10 == 1 and isprimer(i)):
				result.append(i);
				
		if(len(result) >= 1):
			print " ".join(map(str, result));
		else:
			print "-1";
				
	except EOFError,e:
		break;