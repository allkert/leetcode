class ListNode:

    def __init__(self, val=0):
        self.val = val
        self.next = None


class MyLinkedList(object):
    
    def __init__(self):
        self.size = 0
        self.head = None

    def get(self, index):
        node = self.getnode(index=index)
        return -1 if node == None else node.val
        
    def addAtHead(self, val):
        self.addAtIndex(0,val=val)


    def addAtTail(self, val):
        self.addAtIndex(self.size,val=val)


    def addAtIndex(self, index, val):
        if index<=self.size:
            add = ListNode(val=val)
            if index == 0:
                add.next = self.head
                self.head = add
            else:
                prev = self.getnode(index-1)
                if prev != None:
                    add.next = prev.next
                    prev.next = add
            self.size += 1
        


    def deleteAtIndex(self, index):
        if index < self.size:
            if index == 0:
                self.head = self.head.next
            else:
                prev = self.getnode(index-1)
                node = prev.next
                prev.next = node.next
            self.size -= 1
    
    def getnode(self,index):
        temp = self.head
        while index > 0:
            if temp.next == None:
                return None
            index -= 1
            temp = temp.next
        return temp
    
class Solution():
    def _203(self, head, val):
        if head == None: return
        while True:
            if head.val==val:
                if head.next ==None:
                    return
                head = head.next
            else: break
        a, b = head, head.next
        while b != None:
            if b.val == val:
                b = b.next
                a.next = b
            else:
                a = a.next
                b = b.next
        return head
    
    def _206(head):
        if head == None: return
        a = head.next
        if a == None: return
        head.next = None
        while a != None:
            print(1)
            temp = a.next
            a.next = head
            head = a
            a = temp
        return head

    def _24(self, head):
        if head == None: return None
        a,b = head, head.next
        if b == None:return a
        while True:
            if a == None or b == None:break
            a.val, b.val = b.val, a.val
            if b.next == None:break
            a = b.next
            b = a.next
        return head

    def _19(self, head, n):
        dummyhead = ListNode()
        dummyhead.next = head
        fast = slow = dummyhead
        for i in range(n):
            fast = fast.next
        while fast.next != None:
            slow = slow.next
            fast = fast.next
        tmp = slow.next
        slow.next = tmp.next
        return dummyhead.next

    def getIntersectionNode(self, headA, headB):
        # 链表相交的题目，这个思路很巧妙。！！！
        A, B = headA, headB
        while A != B:
            A = A.next if A else headB
            B = B.next if B else headA
        return A
    
    def _142_1(self, head):
        nodelist = []
        while head != None:
            if head in nodelist: return head
            nodelist.append(head)
            head = head.next
        return None

a = MyLinkedList()
a.addAtTail(val=7)
print(a.get(1))