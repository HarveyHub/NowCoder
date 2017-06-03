#coding:utf-8
import sys
sys.stdin = open("str_cat.txt")
for line in sys.stdin:
	# result = "";
	# for w in line:
		# if(w != " "):
			# result += w;
	# print result,;
	twostr = line.split(" ");
	print (twostr[0] + twostr[1]),;