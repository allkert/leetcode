class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# class Solution:
#     def addTwoNumbers(self, l1:ListNode, l2:ListNode):
#         [Q,R] = divmod(l1.val+l2.val, 10)
#         temp = ListNode()
#         temp.val = R
#         if(l1.next != None):
#             l1.next.val = l1.next.val + Q
#             if(l2.next != None):temp.next = self.addTwoNumbers(l1.next,l2.next) if(l2.next != None) else self.addTwoNumbers(l1.next,ListNode())
#         else:
#             if(l2.next != None):
#                 l2.next.val = l2.next.val + Q 
#                 temp.next = self.addTwoNumbers(ListNode(),l2.next)
#             else:
#                 if(Q!=0):
#                     temp.next = ListNode()
#                     temp.next.val = Q
#         return temp
# a1 = ListNode()
# a2 = ListNode()
# b1 = ListNode()
# b2 = ListNode()
# b3 = ListNode()
# a1.val, a2.val = 4, 9
# b1.val,b2.val,b3.val = 6,4,9
# # a1.next = a2
# b1.next = b2
# # b2.next = b3
# c = Solution()
# d = c.addTwoNumbers(a1,b1)
# print(d.next.val)
        
class Solution:
    def addTwoNumbers(self, l1:ListNode, l2:ListNode):
        out = ListNode()
        temp = out
        while True:
            new = ListNode()
            if(l1 == None and l2 == None):break
            elif(l1 == None and l2 != None):new.val = l2.val
            elif(l1 != None and l2 == None):new.val = l1.val
            elif(l1 != None and l2 != None):new.val = l1.val + l2.val
            temp.next = new
            temp = new
        out = out.next
        temp = out
        while True:
            [Q,R] = divmod(temp.val,10)
            temp.val = R
            if(Q == 0):
                if(temp.next == None):break
            else:
                if(temp.next == None):
                    temp.next = ListNode(val=Q)
                    break
                else:
                    temp=temp.next
                    temp.val = temp.val+Q                         


                
            




