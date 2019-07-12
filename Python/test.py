#utf-8
import sys
import re

# sys.stdin = open("test.txt");
# for input in sys.stdin:
	# input = input.strip();
	# pattern = re.compile(r"[+|\-|*|/]");
	# a, b = map(int, pattern.split(input));

	# print a,b,;
	# if "*" in input:
		# print a*b;
	# elif "/" in input:
		# print a/b;
	# elif "-" in input:
		# print a-b;
	# else:
		# print a+b;
		
# import re

# line = "Cats are smarter than dogs"

# matchObj = re.match( r'(.*) are (.*?) .*', line, re.M|re.I)

# if matchObj:
	# print "matchObj.group() : ", matchObj.group()
	# print "matchObj.group(1) : ", matchObj.group(1)
	# print "matchObj.group(2) : ", matchObj.group(2)
		
# else:
	# print "No match!!"	
	

cards = [str(x) for x in range(5)]
num = [x for x in range(2,7)]
counter = dict(zip(cards, num))
print(counter)
for k in counter.keys():
	print k, counter[k]
	
d = chr(ord("c")+ 1)
print(type(d))
line = "hello world"

for c in line:
	print(chr(ord(c) + 1)),