#coding:utf-8
import sys
sys.stdin = open("sort_num.txt")
for line in sys.stdin:
	nums = map(int, line.split());
	if(len(nums) > 1):
		nums.sort();
		# print(nums.pop(-1));
		print(" ".join(map(str, nums))); 
	