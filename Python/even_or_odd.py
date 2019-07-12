# coding:utf-8
import sys

sys.stdin = open("even_or_odd.txt")

while (True):
    try:
        n = int(raw_input())
        nums = map(int, raw_input().split())
        even_cnt = 0
        odd_cnt = 0
        for i in nums:
            if (i % 2 == 0):
                even_cnt += 1
            else:
                odd_cnt += 1
        if (even_cnt > odd_cnt):
            print("NO")
        else:
            print("YES")
    except EOFError:
        break
