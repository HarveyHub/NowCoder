def checkSame(stringA, stringB):
    if(len(stringA)!= len(stringB)):
        return False
    ma = {}
    mb = {}
    for i in range(len(stringA)):
        if(stringA[i] in ma):
            ma[stringA[i]] += 1
        else:
            ma[stringA[i]] = 1
        if(stringB[i] in mb):
            mb[stringB[i]] += 1
        else:
            mb[stringB[i]] = 1
    return ma == mb
a = "Here you are"
b = "Are you here"
a = "This is nowcoder"
b = "is This nowcoder"
print(checkSame(a, b))