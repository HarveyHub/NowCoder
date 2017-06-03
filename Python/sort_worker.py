#coding:utf-8
import sys

sys.stdin = open("sort_worker.txt");
while(True):
	try:
		n = int(raw_input());
		workers = [];
		for i in range(n):
			workers.append(tuple(raw_input().split()));
		workers.sort(key = lambda x:(int(x[2]),int(x[0]),x[1]));
		k = 3 if n>3 else n;
	
		for i in range(k):
			print " ".join(workers[i])
		# for w in workers:
			# print(w);
	except EOFError:
		break;
		