#coding:utf-8
import sys

sys.stdin = open("matrix_max.txt");
while(True):
	try:
		m, n = map(int, raw_input().split());
		matrix = [];
		for i in range(m):
			line = map(int, raw_input().split());
			line[line.index(max(line))] = sum(line);
			print " ".join(map(str, line));
		
	except EOFError:
		break;

		