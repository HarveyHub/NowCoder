#!/usr/bin/python
#coding:utf-8
import sys
try:
	sys.stdin = open("increased_list.txt");
except IOError,e:
	print e;
	print "please input manaully";
	
while(True):
	try:
		n = int(raw_input());
		nums = map(int, raw_input().split());
		nums.sort();
		print " ".join(map(str, nums));
	except EOFError:
		break;
		