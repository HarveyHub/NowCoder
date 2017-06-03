#coding:utf-8
import sys

sys.stdin = open("find_min_pair.txt");

while(True):
	try:
		n = int(raw_input());
		pairs = [];
		for i in range(n):
			pair = map(int, raw_input().strip().split(" "));
			pairs.append(pair);
			
		min_pair = min(pairs, key = lambda x:(x[0], x[1]));
		print(" ".join(map(str, min_pair)));
	except EOFError:
		break;
		
			