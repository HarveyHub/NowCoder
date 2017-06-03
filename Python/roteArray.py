# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
		length = len(rotateArray);
		if(length < 1):
			return 0;
		
		for i in range(len(rotateArray)-1):
			if(rotateArray[i] > rotateArray[i+1]):
				return rotateArray[i+1];
				
				
arr = [3,4,5,1,2];
arr = []
s = Solution();
s.minNumberInRotateArray(arr);