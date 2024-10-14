# def max_gap(num : list, P: int, Q : int) -> int :
#     if len(num) <= 1: return 0
#     num.sort()
#     while(P > 0):
#         leftsum = num[0] + num[1]
#         rightsum = num[-1] + num[-2]
#         gapleft = num[0] - leftsum
#         gapright = rightsum - num[-1]
#         if(gapleft <=0 and gapright <= 0):
#             break
#         if len(num) <= 2: break

#         P -= 1
#         if(gapleft > 0 and gapright <= 0):
#             num.pop(0)
#             num[0] = leftsum
#         elif(gapleft <= 0 and gapright > 0):
#             num.pop(-1)
#             num[-1] = rightsum
#         else:
#             if(gapleft > gapright):
#                 num.pop(0)
#                 num[0] = leftsum
#             else:
#                 num.pop(-1)
#                 num[-1] = rightsum
    
#     while(Q > 0):
#         if(num[0] >=0):
#             break
#         if(len(num) <= 2):
#             break
#         gap = num[-1] - num[0]
#         num.pop(0)
#         num.pop(-1)
#         # gap插入
#         for i in range(len(num)):
#             if(num[i] >= gap):
#                 num.insert(i, gap)
#                 break
#             elif i == len(num) - 1:
#                 num.append(gap)
#         Q -= 1
#     return num[-1] - num[0]

# T = (int)(input())

# for i in range(T):
#     n, P, Q = map(int, input().split())
#     num = list(map(int, input().split()))
#     print(max_gap(num, P, Q))
# class User:
#     def __init__ (self,username,password):
#         username = username 
#         self.password = password
#     def showInfo(self):
#         print("用户名称:",self.username)
#         print("用户密码:",self.password)
# user = User("zhang","123456")
# user.username="wangwu"
# user.password="123"
# user.showInfo()

# import threading
# def runx(name):
#     for i in range(1, 10):
#         print(name, "执行任务")
# t1 = threading.Thread(target=runx, args=("线程1",))
# t1.start()


