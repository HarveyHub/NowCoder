#coding:utf-8
import sys
sys.stdin = open(__file__.split(".")[0] + ".txt")
while(True):
	try:
		n = int(raw_input());
		print(n);
		nums = [];
		while(n):
			nums.append(int(raw_input()));
			n = n - 1;
		print(nums);
		nums.sort();
		print(nums);
	except EOFError:
		break;


        
        
            