#coding:utf-8
def my_abs(x):
	try:
		value = float(x);
		
		if(value < 0):
			return value * -1;
		else:
			return x;
			
	except ValueError:
		return value;
		
		
if __name__ == "__main__":
			
	x = -3.5;
	y = my_abs(x);
	print y;