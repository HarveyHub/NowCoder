def zip_str(iniString):
    length = len(iniString)
    i = 0
    result = ""
    repeat_cnt = 1
    while(i < length -1):
        if(iniString[i] == iniString[i+1]):
            repeat_cnt += 1
        else:
            result += iniString[i] + str(repeat_cnt)
            repeat_cnt = 1
        i += 1
    result += iniString[i]+str(repeat_cnt)
    return len(result) < len(iniString)?result

s = "aabcccccaaa"
print(zip_str(s))