#coding:utf-8
import sys

sys.stdin = open("matrix_col_max.txt");
while(True):
	try:
		# n =int(raw_input());
		# matrix = [];
		# order = [];
		# while(n):
			# for i in range(4):
				# row = map(int, raw_input().split());
				# matrix.append(row);
			# matrix_t = zip(*matrix);
			# for i in range(5):
				# order.append(sorted(matrix_t[i])[-1:-3:-1]);
			# order = zip(*order);
			# for line in order:
				# print(" ".join(map(str, line)));
			# n -= 1;
		n = int(raw_input())
		for case in xrange(n):
			a = zip(*[map(int, raw_input().split()) for k in range(4)])
			
			b = map(lambda x:sorted(x)[-2:], a)
			print b
			for i in range(5):
				if a[i].index(b[i][0]) > a[i].index(b[i][1]):
					b[i][0], b[i][1] = b[i][1], b[i][0]
			c = zip(*b)
			for j in c:
				print ' '.join(map(str, j)) + ' '
	except EOFError:
		break;


