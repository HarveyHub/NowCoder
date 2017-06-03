#coding:utf-8

import sys
sys.stdin = open("fibonacci.txt");
for line in sys.stdin:
	n = int(line);
	result = [1, 1];
	for i in range(2, n+1):
		result.append(result[i-1] + result[i-2]);
	print result[n]