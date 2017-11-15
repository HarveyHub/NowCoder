#!/usr/bin/python
#coding:utf-8
import sys
sys.stdin = open("AplusB.txt");

for line in sys.stdin:
	nums = line.split(" ");
	A = "";
	B = "";
	for c in nums[0].split(","):
		A += (c);
	for c in nums[1].split(","):
		B += (c);
	result = int(A) + int(B);
	print(result)
