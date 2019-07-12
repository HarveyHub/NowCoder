# coding:utf-8

a = [1, 3, 5, 6, 10, 13]
b = [2, 4, 7, 8, 12, 15, 17]


class Node():
    def __init__(self, value, p=0):
        self.value = value
        self.next = p

    @staticmethod
    def list2link(li):
        p = head = Node(0)
        for i in li:
            p.next = Node(i)
            p = p.next
            head.value += 1
        return head

    @staticmethod
    def link2list(li):
        li = li.next
        result = []
        while(li):
            result.append(li.value)
            li = li.next

        return result


def merge(a, b):
    if(not(a.value or b.value)):
        return 0
    if(not b.value):
        return a
    if(not a.value):
        return b
    p = head = Node(0)
    a = a.next
    b = b.next
    while(a and b):
        if(a.value < b.value):
            p.next = Node(a.value)
            a = a.next
        else:
            p.next = Node(b.value)
            b = b.next
        
        p = p.next
        head.value += 1
    while(a):
        p.next = Node(a.value)
        a = a.next
        p = p.next
        head.value += 1
    while(b):
        p.next = Node(b.value)
        b = b.next
        p = p.next
        head.value += 1
    return head


def merge2(a, b):
    head = p = Node(0)
    a = a.next
    b = b.next
    while(a or b):
        if(a and (not b or a.value <= b.value)):
            p.next = Node(a.value)
            a = a.next
        else:
            p.next = Node(b.value)
            b = b.next
        p = p.next
        head.value += 1

    return head

if __name__ == "__main__":
    list_a = Node.list2link(a)   
    list_b = Node.list2link(b)
    tmp = merge2(list_a, list_b)
    result = Node.link2list(tmp)
    print(result)
            

    