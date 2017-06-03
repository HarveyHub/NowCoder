#coding:utf-8



def zipString(iniString):
		# write code here
		result = [[]];
		for c in iniString:
			for arr in result:
				if(c in arr):
					arr[1] += 1;
					
				else:
					result.append([c, 1]);
		return result;
					
s = "aabcccccaaa";
print zipString(s)			