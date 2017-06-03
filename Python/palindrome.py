#coding:utf-8

import sys
sys.stdin = open("palindrome.txt");
for line in sys.stdin:
	line = line.strip();
	length = len(line);
	if(line == line[::-1]):
		print("Yes!");
	else:
		print("No!");