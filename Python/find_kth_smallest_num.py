#coding:utf-8
import sys

sys.stdin = open("find_kth_smallest_num.txt");	
while(True):
	try:
		n = int(raw_input());
		nums = map(int, raw_input().split(" "));
		print(nums);
		nums.sort();
		k = int(raw_input());
		print(nums)
		print(nums[k + 1]);
	except EOFError:
		break;