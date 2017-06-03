#coding:utf-8
import sys
sys.stdin = open("ip.txt");

for line in sys.stdin:
    flag = True;
    if("." in line):
		
		nums = map(int, line.split("."));
		for num in nums:
			if(num < 0 or num > 255):
				flag = False;
				break;
		if(flag):
			print("Yes!");
		else:
			print("No!");

           