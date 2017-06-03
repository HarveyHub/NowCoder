#coding:utf-8
import sys

try:
	sys.stdin = open("max_range.txt");
except IOError:
		sys.exit(0);
		
while(True):
	try:
		n = int(raw_input());
		nums = map(int, raw_input().split());
		result = [];
		for i in range(1, n-1):
			if(nums[i-1] > nums[i] and nums[i] < nums[i+1]):
				result.append(i);
				
		start = -1;
		end = -1;
		max_range = 0;
		length = len(result);
		if(length < 2):
			print start, end;
			break;
		for i in range(1, length):
			if(result[i] - result[i-1] > max_range):
				start = result[i-1];
				end = result[i];
				max_range = end - start;
				
		print start, end;
		
	except EOFError:
		break;
		
	
		
		
