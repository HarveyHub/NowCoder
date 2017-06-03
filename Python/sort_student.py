#coding:utf-8
import sys

sys.stdin = open("sort_student.txt");
	
while(True):
	try:
		n = int(raw_input());
		students = [];
		for i in range(n):
			s = tuple(raw_input().split());
			students.append(s);
		students.sort(key = lambda x:(int(x[2]), x[0], int(x[1])));
		for i in range(n):
			print " ".join(students[i]);
	except EOFError:
		break;