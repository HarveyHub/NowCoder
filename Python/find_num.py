#coding:utf-8
import sys

sys.stdin = open("find_num.txt");

while(True):
	try:
		n = int(raw_input());
		nums = map(int, raw_input().split(" "));
		m = int(raw_input());
		num_find = map(int, raw_input().split(" "));
		for i in range(m):
			if(num_find[i] in nums):
				print("YES");
			else:
				print("NO");
	except EOFError:
		break;
		
			