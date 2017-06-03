#coding:utf-8
import sys

sys.stdin = open("str_manipulate.txt");

while(True):
	try:
		input = raw_input().strip();
		n = int(raw_input());
		
		for i in range(n):
			cmd = raw_input().strip();
			start = int(cmd[1]);
			end = start + int(cmd[2]);
			if(cmd[0] == "0"):
				tmp = input[start:end];
				input = input[:start] + tmp[::-1] + input[end:];
			elif(cmd[0] == "1"):
				input = input[:start] + cmd[3:] + input[end:];
			print(input);
			
				
	except EOFError:
		break;
		
			