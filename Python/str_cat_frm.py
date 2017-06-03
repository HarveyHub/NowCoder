#coding:utf-8

# line = "8";
# n = int(line);
# result = [[1, 1],];
# for i in range(2, n+1):
	# for j in range(i-1):
		# row.append(result[i-1][j] + result[i-1][k+1])
#coding:utf-8
import sys
sys.stdin = open("str_cat_frm.txt")
while(True):
	try:
		s1 = raw_input().strip();
		s2 = raw_input().strip();
		n = len(s1) if len(s1) < len(s2) else len(s2);
		result = "";
		for i in range(n):
			result +=  s1[i];
			result += s2[-i-1];
		if(n == len(s1)):
			result += s2[-n-1::-1];
		else:
			result += s1[-n-1::-1];
		print result;
	except EOFError:
		break;