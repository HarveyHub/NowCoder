#coding:utf-8

# def myhash(s):
	# hash = 0;
	# for i in range(0, len(s))[::-1]:
		# hash = ((hash << 5) - hash) + ord(s[len(s)-1 - i]);
	# for c in s:
		# hash = ((hash << 5) - hash) + ord(c)
		
	# return hash;

# def myhash1(s):
	# hash = 0;
	# length = len(s);
	# for i in range(0, length):
		# hash += ord(s[i])*31**(length - 1 - i)
	# return hash
# print myhash('cmd')
# print myhash('Ey')
# print myhash1('Ey')
# print myhash('FZ')

# def mybin(s):
	# result = 0;
	# for i in range(0, len(s))[::-1]:
		# result = result * 2 + int(s[len(s) - 1 -i])
		
	# return result;
	
# print mybin("101001")
# print myhash('tt')
# print myhash('uU')
# print myhash('ttuU') == myhash('uUtt')

def myhash_djbx33x(s, target):
	hash  = 5381;
	s_len = len(s);
	for i in range(s_len):
		hash = (hash << 5 + hash) ^ s[i];
	return hash;
	
def myhash_back_djbx33x(suffix, end):
	hash  = end;
	s_len = len(s);
	for i in range(s_len)[::-1]:
		hash = (hash ^ suffix[i]) * 1041204193
	
	return hash;
	
	
	
	
	
	
	
	
	
	
	
