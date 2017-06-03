#coding:utf-8

prices = {
'ACME': 45.23,
'AAPL': 612.78,
'IBM': 205.55,
'HPQ': 37.20,
'FB': 10.75
}

a = zip(prices.values(), prices.keys());
print min(a)
print max(a)

b = max(prices, key = lambda x:prices[x])
print b