#coding:utf-8
import sys

sys.stdin = open("play_cards.txt");

while(True):
	try:
		my_cards = raw_input().strip();
		counter = {};
		for c in my_cards:
			if(not c in counter):
				counter[c] = 1;
			else:
				counter[c] += 1;
		# print(counter);		
		cards = raw_input().strip();
		flag = False;
		cards_len = len(cards);
		if(cards_len >= 1 and cards_len < 5):
			for c in my_cards:
				if(c > cards[0] and counter[c] >= cards_len):
					flag = True;
					break;
		elif(cards_len == 5):
			my_cards_len = len(counter);
			j = 0;
			if(my_cards_len < 5):
				flag = False;
				
			else:
				for c in counter.keys():
					if(c > cards[0]):
						# print "line1 " + c;
						flag = True;
						for i in range(5):
							# print "line2 " + chr(ord(c) + i) + " " +str(chr(ord(c) + i) in counter);
							if(not (chr(ord(c) + i) in counter)):
								flag = False;
								break;
								
						if(flag):
							break;	
							
							
						
						
		if(flag):
			print("YES");
		else:
			print("NO");
			
	except EOFError:
		break;
				
				
			