#coding:utf-8
import sys
sys.stdin = open("sort_num.txt");
while(True):
	try:
		N = int(raw_input());
		nums = map(int, raw_input().split());
		if(N == 1):
			print(nums[0]);
			print("-1");
		else:
			nums.sort();
			print(nums.pop(-1));
			print(" ".join(map(str, nums)));      
	except :
		break;