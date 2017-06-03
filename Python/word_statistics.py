#coding:utf-8

# import sys
# for lines in sys.stdin:
lines = "ygexrr unu xalgcb istydv xmfy bz fpjwt sasz."
data = lines.split(".");
words = data[0].split(" ");
cnt = [];
for word in words:
	cnt.append(len(word));
print " ".join(map(str, cnt));