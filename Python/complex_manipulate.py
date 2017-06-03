#coding:utf-8
import sys

sys.stdin = open("complex_manipulate.txt");



while(True):
	try:
		n = int(raw_input());
		complexs = [];
		for i in range(n):
			cmd = raw_input().strip().split();
			if(cmd[0] == "Pop"):
				if(len(complexs) <= 0):
					print("empty");
				else:
					max_complex = max(complexs, key = lambda x : (x[0]**2 + x[1]**2));
					complexs.remove(max_complex);
					print(str(max_complex[0]) + "+i" + str(max_complex[1]));
					print("SIZE = " + str(len(complexs)));
			elif(cmd[0] == "Insert"):
				complexs.append(map(int, cmd[1].split("+i")));
				print("SIZE = " + str(len(complexs)));
				
				
		
	except EOFError:
		break;
		
			