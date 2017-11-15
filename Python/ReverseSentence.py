#coding:utf-8
def ReverseSentence(s):
        # write code here
        if(s == " "):
        	return s;
        strs = s.split();
        strs = strs[::-1];
        return " ".join(strs);
		
s = " ";
print ReverseSentence(s);