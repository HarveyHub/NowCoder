# -*- coding:utf-8 -*-
import sys 
sys.stdin = open("reOrderArray.txt");

class Solution:
	def reOrderArray(self, array):
		# write code here
		odd = [];
		even = [];
		for num in array:
			if(num % 2 == 0):
				odd.append(num);
			else:
				even.append(num);
		for num in even:
			odd.append(num);
		return odd;

if __name__ == '__main__':
	array = map(int, raw_input().split());
	s = Solution();
	res = s.reOrderArray(array);
	print(" ".join(map(str, res)));