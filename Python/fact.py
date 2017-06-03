#coding:utf-8
import sys
sys.stdin = open("fact.txt")
for lines in sys.stdin:
	# lines = "4";
	n = int(lines);
	fac = [0,1]
	y1 = 1;
	y2 = 0;
	for i in range(2,n+1):
		fac.append(i*fac[i-1]);
		if(i % 2 != 0):
			y1 += fac[i];
		else:
			y2 += fac[i];
	print y1, y2;
		