#coding:utf-8
import sys
sys.stdin = open("matrix.txt");

while(True):
	try:
		n = int(raw_input());
		matrix = [];
		while(n):
			matrix.append(tuple(raw_input().split()));
			n -= 1;
		print(matrix);
		print(zip(*matrix));
		if(matrix == zip(*matrix)):
			print("Yes!");
		else:
			print("No!");
	except EOFError:
		break;
			
	except IOError:
		pass;