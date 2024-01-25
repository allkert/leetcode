from collections import deque, defaultdict


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class solution():

    # 二叉树前中后序遍历的统一写法，以中序遍历为例
    def inorderTraversal(self, root):
        if root==None:return[]
        res=[]
        stack=[root]
        while stack:
            node=stack.pop()
            if node==None:
                node = stack.pop()
                res.append(node.val)
            else:
                # 这里改一下顺序即可
                if node.right!=None:
                    stack.append(node.right)
                stack.append(node)
                stack.append(None)
                if node.left != None:
                    stack.append(node.left)
        return res

    # 144. 二叉树的前序遍历
    # 递归
    def preorderTraversal_1(self, root):
        if root == None: return []
        else:return ([root.val]+self.preorderTraversal(root.left)+self.preorderTraversal(root.right))
    
    def preorderTraversal_2(self, root):
        if root == None: return []
        stack=[root]
        res=[]
        while stack:
            node=stack.pop()
            res.append(node.val)
            if node.right != None:stack.append(node.right)
            if node.left != None:stack.append(node.lefg)
        return res

    # 94. 二叉树的中序遍历
    def inorderTraversal_1(self, root):
        if root==None:return []
        else: return self.inorderTraversal(root.left)+[root.val]+self.inorderTraversal(root.right)
    
    def inorderTraversal_2(self, root):
        if root==None:return []
        stack=[]
        res=[]
        cur=root
        while stack or cur:
            if cur != None:
                stack.append(cur)
                cur=cur.left
            else:
                cur=stack.pop()
                res.append(cur.val)
                cur=cur.right
        return res

    
    # 145. 二叉树的后序遍历
    def postorderTraversal_1(self, root):
        if root==None:return[]
        else: return self.postorderTraversal(root.left)+self.postorderTraversal(root.right)+[root.val]
    
    def postorderTraversal_2(self,root):
        if root==None: return[]
        stack=[root]
        res=[]
        while stack:
            node=stack.pop()
            res.append(node.val)
            if node.left: stack.append(node.left)
            if node.right:stack.append(node.right)
        return res[::-1]

    
    # 102. 二叉树的层序遍历
    # 非递归的方法
    def levelOrder1(self, root):
        if root==None: return []
        res=[]
        queen=[root]
        while queen:
            tmp_val = []
            tmp_node= []
            for node in queen:
                tmp_val.append(node.val)
                if node.left: tmp_node.append(node.left)
                if node.right:tmp_node.append(node.right)
            res.append(tmp_val)
            queen=tmp_node
        return res
    
    # 递归法
    def levelOrder2(self, root):
        if root == None: return[]
        
    # 107. 二叉树的层序遍历二
    def levelOrderBottom(self, root):
        if root == None: return[]
        res=[]
        stack=[[root]]
        layer=0
        while True:
            tmp =[]
            for node in stack[layer]:
                if node.left:tmp.append(node.left)
                if node.right:tmp.append(node.right)
            if len(tmp)==0:break
            stack.append(tmp)
            layer+=1
        while stack:
            res.append([node.val for node in stack.pop()])
        return res
    
    #  199. 二叉树的右视图
    def rightSideView(self, root):
        if root == None: return []
        res=[root.val]
        layer=[root]
        while True:
            tmp = []
            for node in layer:
                if node.left: tmp.append(node.left)
                if node.right:tmp.append(node.right)
            if len(tmp)==0:break
            res.append(tmp[-1].val)
            layer=tmp
        return res

    # 637 二叉树的层平均值
    def averageOfLevels(self, root):
        if root == None: return []
        layer=[root]
        average_val=[]
        while True:
            tmp=[]
            total=0
            node_num=0
            for node in layer:
                total+=node.val
                node_num+=1
                if node.left: tmp.append(node.left)
                if node.right:tmp.append(node.right)
            average_val.append(total/node_num)
            print(total,node_num)
            if len(tmp) == 0:return average_val
            else:layer=tmp

    # 429 N叉树的层序遍历
    def levelOrder(self, root):
        if root==None: return
        layer=[root]
        res=[]
        while True:
            tmp_layer=[]
            tmp_val=[]
            for node in layer:
                for child in node.children:
                    tmp_layer.append(child)
                tmp_val.append(node.val)
            res.append(tmp_val)
            if len(tmp_layer)==0: return res
            layer=tmp_layer

    # 515. 在每个树行中找最大值
    def largestValues(self, root):
        if root==None:return []

        node_layer=deque([root])
        res=[]

        while node_layer:
            tmp = float('-inf')
            qlen = len(node_layer)
            for _ in range(qlen):
                node = node_layer.popleft()
                if tmp < node.val: tmp=node.val
                if node.left:node_layer.append(node.left)
                if node.right:node_layer.append(node.right)
            res.append(tmp)
        return res

    # 116. 填充每个节点的下一个右侧节点指针 
    # 117. 填充每个节点的下一个右侧节点指针 II
    def connect(self, root):
        if root==None: return
        layer=deque([root])
        while layer:
            layer_length = len(layer)
            prev=None
            for _ in range(layer_length):
                node=layer.popleft()
                if prev:
                    prev.next=node
                prev = node
                if node.left:
                    layer.append(node.left)
                if node.right:
                    layer.append(node.right)

        return root
    # 104. 二叉树的最大深度
    def maxDepth1(self, root):
        if root == None: return 0
        layer = deque([root])
        depth=0
        while layer:
            depth+=1
            length = len(layer)
            for _ in range(length):
                node = layer.popleft()
                if node.left:layer.append(node.left)
                if node.right:layer.append(node.right)
        return depth
    # 递归
    def maxDepth2(self, root):
        if root==None:return 0
        else: return 1 + max(self.maxDepth2(root.left), self.maxDepth2(root.right))
    
    # 559. N 叉树的最大深度
    # 递归
        # 这里要判断子节点列表不为空的原因是 max的args不能是一个空的列表
    def NmaxDepth(self, root):
        if root == None: return 0
        if len(root.children)==0: return 1
        return 1+max([self.NmaxDepth(child) for child in root.children])
    
    # 迭代
    def NmaxDepth1(self, root):
        if root==None:return 0
        quene = deque([root])
        depth = 0
        while quene:
            depth += 1
            length = len(quene)
            for _ in range(length):
                node=quene.popleft()
                for child in node.children:
                    if child!=None:quene.append(child)
        return depth

    # 111.二叉树的最小深度
    # 递归
    def minDepth(self, root):
        if root==None:return 0
        if root.left and root.right:
            return 1 + min(self.minDepth(root.left), self.minDepth(root.right))
        elif root.left == None and root.right == None: return 1
        elif root.right==None: return 1+self.minDepth(root.left)
        else:return 1+self.minDepth(root.right)
    # 循环
    def minDepth_1(self, root):
        if not root:
            return 0
        depth = 0
        queue = deque([root])
        
        while queue:
            depth += 1 
            for _ in range(len(queue)):
                node = queue.popleft()                
                if not node.left and not node.right:
                    return depth            
                if node.left:
                    queue.append(node.left)     
                if node.right:
                    queue.append(node.right)
        return depth
    
    #  226. 翻转二叉树
    # 递归
    def invertTree(self, root):
        if root==None: return None
        root.left,root.right=root.right,root.left
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root
    # 迭代
    def invertTree1(self, root):
        if root==None: return None
        stack=[root]
        while stack:
            node = stack.pop()
            node.left, node.right = node.right, node.left
            if node.left:stack.append(node.left)
            if node.right:stack.append(node.right)
        return root
    
    # 101.对称二叉树、
    # 递归
    def isSymmetric(self, root):
        def judge(left, right):
            if left == None and right == None: return True
            elif left == None and right != None: return False
            elif left !=None and right==None:return False
            else: return (left.val==right.val) and judge(left.left,right.right) and judge(left.right, right.left)
        if root == None: return True
        return judge(root.left, root.right)
    # 迭代
    def isSymmetric1(self, root):
        if root==None: return True
        quene = deque([root.left,root.right])
        while quene:
            left = quene.popleft()
            right= quene.pop()
            if left == None and right != None: return False
            elif left != None and right == None: return False
            elif left != None and right != None:
                if left.val != right.val: return False
                quene.append(right.right)
                quene.append(right.left)
                quene.appendleft(left.left)
                quene.appendleft(left.right)
        return True
    
    # 222.完全二叉树的节点个数
    # 递归
    def countNodes(self, root):
        if root==None:return 0
        else: return 1 + self.countNodes(root.left) + self.countNodes(root.right)

    # 迭代
    # 来一个前序遍历吧，中序后序层序遍历都可以
    def countNodes1(self, root):
        if root == None: return 0
        stack = [root]
        num=0
        while stack:
            node = stack.pop()
            num+=1
            if node.left: stack.append(node.left)
            if node.left: stack.append(node.right)

    # 110.平衡二叉树
    # 递归
    # 参考：如果直接设返回值为T和F的话，没有办法递归，所以要定义一个可以判断是否为二叉树，如果不是则返回-1，是则返回高度的函数
    def isBalanced(self, root):
        if root == None: return True
        def getheight(node):
            # 结束标志
            if node==None:return 0
            ltree_height = getheight(node.left)
            if ltree_height == -1: return -1
            rtree_height = getheight(node.right)
            if rtree_height == -1: return -1
            return -1 if abs(ltree_height-rtree_height)>1 else 1 + max(ltree_height, rtree_height)
        return False if getheight(root)==-1 else True
    
    # 迭代
    def isBalanced1(self, root):
        if root == None: return True
        # 后序遍历
        stack = [root]
        height = {}
        while stack:
            node = stack.pop()
            if node == None:
                node = stack.pop()
                leftheight = height.get(node.left, 0)
                rightheight = height.get(node.right,0)
                if abs(leftheight-rightheight)>1: return False
                height[node] = max(leftheight,rightheight)+1
            else:
                stack.append(node)
                stack.append(None)
                if node.right: stack.append(node.right)
                if node.left:stack.append(node.left)
        return True

    # 257 二叉树的所有路径
    # 递归＋回溯,第一次见,后面可以用来解决n皇后问题
    # 这是显式的递归回溯写法,每次传进去的是列表地址,递归调用可以改变列表的值
    def binaryTreePaths(self, root):
        def getpath(res, path, node):
            path.append(node.val)
            if node.left == None and node.right==None:
                res.append("->".join(map(str,path)))
                return
            if node.left:
                getpath(res,path,node.left)
                path.pop()
            if node.right:
                getpath(res,path,node.right)
                path.pop()
        if root == None:
            return []
        res=[]
        getpath(res,[],root)
        return res
    
    # 404.左叶子之和
    # 递归
    def sumOfLeftLeaves(self, root):
        if root==None:return 0
        left,right=root.left,root.right
        if left:
            if left.left == None and left.right==None:
                return left.val+self.sumOfLeftLeaves(right)
        return self.sumOfLeftLeaves(left)+self.sumOfLeftLeaves(right)
    
    # 迭代
    def sumOfLeftLeaves1(self,root):
        if root == None:return 0
        res = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if node == None:
                node = stack.pop()
                if node.left == None and node.right==None:
                    res+=node.val
            if node.left: 
                stack.append(node.left)
                stack.append(None)
            if node.right: stack.append(node.right)
        return res

    # 513. 找树左下角的值
    # 递归+回溯
    def findBottomLeftValue(self, root):
        self.maxdepth = -1
        self.res = None
        def getval(node, depth):
            if node.left==None and node.right==None:
                if depth > self.maxdepth: 
                    self.maxdepth = depth
                    self.res = node.val
                return
            if node.left: getval(node.left, depth+1)
            if node.right:getval(node.right,depth+1)
        getval(root,1)
        return self.res
    
    # 迭代：层序遍历
    def findBottomLeftValue1(self,root):
        quene = deque([root])
        res = None
        while quene:
            res = quene[0].val
            length = len(quene)
            for _ in range(length):
                node = quene.popleft()
                if node.left: quene.append(node.left)
                if node.right:quene.append(node.right)
        return res

    # 112. 路径总和
    # 递归
    def hasPathSum(self, root, targetSum):
        if root == None: return False
        def func(node, s):
            if node.left == None and node.right == None:
                return True if node.val == s else False
            elif node.left and not node.right:
                return func(node.left, s-node.val)
            elif node.right and not node.left:
                return func(node.right, s-node.val)
            else: return func(node.left, s - node.val) or func(node.right, s-node.val)
        return func(root, targetSum)
    
    # 迭代
    def hasPathSum1(self, root, targetSum):
        if root == None: return False
        stack = [(root,root.val)]
        while stack:
            node, nowsum = stack.pop()
            if node.left == None and node.right == None and nowsum == targetSum:
                return True
            if node.left: stack.append((node.left,nowsum+node.left.val))
            if node.right: stack.append((node.right, nowsum+node.right.val))
        return False

    # 106.从中序与后序遍历序列构造二叉树
    # 递归
    def buildTree(self, inorder, postorder):
        if len(inorder) == 0: return None
        midval = postorder[-1]
        root = TreeNode(val=midval)
        mid = inorder.index(postorder[-1])
        left = self.buildTree(inorder[:mid], postorder[:mid])
        right = self.buildTree(inorder[mid+1:],postorder[mid:-1])
        if left: root.left = left
        if right:root.right=right
        return root
    # 105. 从前序与中序遍历序列构造二叉树
    def buildTree(self, preorder, inorder):
        # 第一步: 特殊情况讨论: 树为空. 或者说是递归终止条件
        if not preorder:
            return None

        # 第二步: 前序遍历的第一个就是当前的中间节点.
        root_val = preorder[0]
        root = TreeNode(root_val)

        # 第三步: 找切割点.
        separator_idx = inorder.index(root_val)

        # 第四步: 切割inorder数组. 得到inorder数组的左,右半边.
        inorder_left = inorder[:separator_idx]
        inorder_right = inorder[separator_idx + 1:]

        # 第五步: 切割preorder数组. 得到preorder数组的左,右半边.
        preorder_left = preorder[1:1 + len(inorder_left)]
        preorder_right = preorder[1 + len(inorder_left):]

        # 第六步: 递归
        root.left = self.buildTree(preorder_left, inorder_left)
        root.right = self.buildTree(preorder_right, inorder_right)
        # 第七步: 返回答案
        return root

    # 654. 最大二叉树
    def constructMaximumBinaryTree(self, nums):
        if len(nums)==0: return None
        maxval = max(nums)
        pos = nums.index(maxval)
        root = TreeNode(val=maxval)
        root.left = self.constructMaximumBinaryTree(nums[:pos])
        root.right = self.constructMaximumBinaryTree(nums[pos+1:])
        return root

    # 617. 合并二叉树
    def mergeTrees(self, root1, root2):
        if root1==None: return root2
        if root2==None: return root1
        root1.val += root2.val
        root1.left = self.mergeTrees(root1.left, root2.left)
        root1.right = self.mergeTrees(root1.right, root2.right)
        return root1
    
    # 迭代
    def mergeTrees1(self, root1, root2):
        if root1 == None: return root2
        if root2 == None: return root1
        quene = deque([(root1, root2)])
        while quene:
            node1, node2 = quene.popleft()
            node1.val += node2.val
            if node1.left and node2.left:
                quene.append((node1.left,node2.left))
            elif node1.left == None:
                node1.left = node2.left
            if node1.right and node2.right:
                quene.append((node1.right,node2.right))
            elif node1.right == None:
                node1.right = node2.right
        return root1

    # 700. 二叉搜索树中的搜索
    # 递归
    def searchBST(self, root, val):
        if root == None: return None
        if root.val == val: return root
        if root.val > val: return self.searchBST(root.left,val)
        else: return self.searchBST(root.right,val)
    
    # 迭代
    def searchBST1(self, root, val):
        node = root
        while node:
            if node.val == val: return node
            if node.val > val: node = node.left
            else: node = node.right
        return None
    
    # 98. 验证二叉搜索树
    # 递归
    def isValidBST(self, root):
        def func(node, minround, maxround):
            if node == None: return True
            if node.val >minround and node.val <maxround: return func(node.left, minround, min(maxround,node.val)) and func(node.right, max(node.val, minround), maxround)
            else: return False
        return func(root, float('-inf'), float('inf'))
    
    def isValidBST1(self, root):
        stack = []
        cur = root
        pre = None
        while cur or stack:
            if cur: 
                stack.append(cur)
                cur = cur.left
            else:
                cur=stack.pop()
                if pre and cur.val <= pre.val: return False
                pre = cur
                cur = cur.right
        return True


    # 530. 二叉搜索树的最小绝对差
    # 1.这个逻辑的本质其实是中序遍历，迭代
    def getMinimumDifference1(self, root):
        stack = []
        cur = root
        pre = None
        mindif = float('inf')
        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                if pre:
                    mindif = min(mindif, cur.val-pre.val)
                pre = cur
                cur = cur.right
        return mindif

    # 501. 二叉搜索树中的众数
    def findMode(self, root):
        cur = root
        stack = []
        count = defaultdict(int)
        while cur or stack:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                count[cur.val] += 1
                cur = cur.right
        maxnum = 0
        for key in count:
            maxnum = max(maxnum, count[key])
        return [key for key in count if count[key]==maxnum]
    
    # 236. 二叉树的最近公共祖先
    """ 
        如果一个节点，它的左子树包含p，右子树包含q，则它一定是二叉树的最近公共祖先  
    """
    def lowestCommonAncestor1(self, root, p, q):
        # 结束条件
        if root == p or root == q or root == None: return root
        left =self.lowestCommonAncestor1(root.left,p,q)
        right = self.lowestCommonAncestor1(root.right,p,q)
        if left and right: return root
        if left: return left
        else:return right

    # 235. 二叉搜索树的最近公共祖先
    # 这是我的垃圾递归，就是在236的基础上多加了一个终止条件。
    def lowestCommonAncestor2(self, root, p, q):
        if root == p or root == q or root == None: return root
        if (root.val-p.val)*(root.val-q.val) < 0: return root
        left = self.lowestCommonAncestor2(root.left,p,q)
        right = self.lowestCommonAncestor2(root.right,p,q)
        if left and right: return TimeoutError
        if left: return left
        else:return right
    
    # 答案写法1
    def lowestCommonAncestor2_1(self, root, p, q):
        def traversal(cur, p, q):
            if cur.val>p.val and cur.val > q.val:
            # 说明p和q都在cur的左子树里面，并且cur.left一定不是空的
                return traversal(cur.left,p,q)
            if cur.val<p.val and cur.val < q.val:
                return traversal(cur.right, p, q)
    
            return cur
        return traversal(root, p, q)
        
    # 迭代
    def lowestCommonAncestor2_2(self, root, p, q):
        while True:
            if root.val > p.val and root.val > q.val:
                root = root.left
            elif root.val < p.val and root.val < q.val:
                root = root.right
            else: return root
    
    # 701. 二叉搜索树中的插入操作
    # 迭代
    def insertIntoBST1(self, root, val):
        if root == None: return TreeNode(val)
        node = TreeNode(val)
        tmp = root
        pre = None
        while tmp:
            pre = tmp
            if tmp.val > val:
                tmp = tmp.left
            else:
                tmp = tmp.right
        if pre.val > val: pre.left = node
        else: pre.right = node
        return root

    # 递归
    def insertIntoBST(self, root, val):
        if root == None: return TreeNode(val)
        if root.val > val: root.left = self.insertIntoBST(root.left, val)
        if root.val < val: root.right = self.insertIntoBST(root.right, val)
        return root

    # 450. 删除二叉搜索树中的节点
    def deleteNode1(self, root, key):
        def func(node, key, pre):
            if node == None: return None
            if node.val > key:
                node.left = func(node.left, key, node)
            elif node.val < key:
                node.right = func(node.right, key, node)
            else:
                if node.left == None and node.right == None:
                    if pre.left == node: pre.left = None
                    else:pre.right = None
                    return None
                elif node.left and node.right==None:
                    if pre.left == node: pre.left = node.left
                    else:pre.right = node.left
                    return node.left
                elif node.left == None and node.right:
                    if pre.left == node:pre.left = node.right
                    else:pre.right = node.right
                    return node.right
                elif node.left and node.right:
                    if pre.left == node:pre.left = node.right
                    else:pre.right=node.right
                    cur = node.right
                    tmp = None
                    while cur:
                        tmp = cur
                        cur = cur.left
                    tmp.left = node.left
                    return node.right
            return node
        head = TreeNode()
        head.left = root
        return func(head.left, key, head)
    
    # 迭代
    def deleteNode1(self, root, key):
        head = TreeNode()
        head.left = root
        cur = root
        pre = head
        while cur:
            if cur.val == key: break
            pre = cur
            cur = cur.left if cur.val > key else cur.right
        if cur:
            if cur.left and cur.right:
                if pre.left == cur:pre.left = cur.right
                else:pre.right = cur.right
                r = cur.right
                tmp = None
                while r:
                    tmp = r
                    r = r.left
                tmp.left = cur.left
            elif cur.left == None and cur.right:
                if pre.left == cur: pre.left = cur.right
                else:pre.right = cur.right
            elif cur.left and cur.right == None:
                if pre.left == cur: pre.left = cur.left
                else:pre.right = cur.left
            else:
                if pre.left == cur: pre.left = None
                else: pre.right = None
        return head.left

    # 参考答案
    # 虽然看起来很简洁，但是其实很复杂，思路是把要删除的节点通过交换值变为去删除子节点
    def deleteNode(self, root, key):
        if root == None: return root
        if root.val == key:
            # 如果右孩子为空，则直接返回左孩子，如果这里就包含了左右孩子都为空的情况了
            if root.right == None:
                return root.left
            # 现在剩下两种情况：右孩子不空，左孩子空或者不空
            cur = root.right #右孩子
            while cur.left:
                cur = cur.left
            # 交换了两个节点的值，然后接着递归下去，相当于把要删除的节点变成了其右子树的最左（小）子节点
            root.val, cur.val = cur.val, root.val
            root.left = self.deleteNode(root.left, key)  # 在左子树中递归删除目标节点
            root.right = self.deleteNode(root.right, key)  # 在右子树中递归删除目标节点
            return root
        
    # 669. 修剪二叉搜索树
    # 递归：卧槽我真牛逼，和答案写的一毛一样
    def trimBST(self, root, low, high):
        """
        :type root: TreeNode
        :type low: int
        :type high: int
        :rtype: TreeNode
        """
        if root == None: return None
        if root.val > high:
            return self.trimBST(root.left, low, high)
        elif root.val < low:
            return self.trimBST(root.right, low, high)
        else:
            root.left = self.trimBST(root.left, low, high)
            root.right = self.trimBST(root.right, low, high)
            return root
        
    # 迭代
    def trimBST1(self, root, low,  high):
        if root == None: return None
        while root and (root.val < low or root.val > high):
            if root.val < low: root = root.right
            else: root = root.left
        cur = root

        # 找到node，node.val在范围内，其左子树中可能包含小于范围的节点，右子树中可能包含大于范围的节点
        # 处理左子树
        while cur:
            while cur.left and cur.left.val < low:
                # 则节点要被修剪，接着往下找
                cur.left = cur.left.right
            cur = cur.left
        
        cur = root
        
        while cur:
            while cur.right and cur.right.val > high:
                cur.right = cur.right.left
            cur = cur.right
        
        return root

    # 108. 将有序数组转换为二叉搜索树
    # 递归
    def sortedArrayToBST(self, nums):
        length = len(nums)
        if length == 0: return None
        else: 
            node = TreeNode(nums[length//2])
            node.left = self.sortedArrayToBST(nums[:length])
            node.right = self.sortedArrayToBST(nums[length+1:])
        return node
    
    # 迭代
    def sortedArrayToBST1(self, nums):
        if len(nums) == 0: return None

        root = TreeNode(0)
        nodeQue = deque()
        leftQue = deque()
        rightQue = deque()

        nodeQue.append(root)
        leftQue.append(0)
        rightQue.append(len(nums)-1)

        while nodeQue:
            curNode = nodeQue.popleft()
            left = leftQue.popleft()
            right = rightQue.popleft()
            mid = (left+right)//2
            curNode.val = nums[mid]
            if left <= mid - 1:
                curNode.left = TreeNode(0)
                nodeQue.append(curNode.left)
                leftQue.append(left)
                rightQue.append(mid-1)
            if right >= mid + 1:
                curNode.right = TreeNode(0)
                nodeQue.append(curNode.right)
                leftQue.append(mid+1)
                rightQue.append(right)
        return root
    
# 538. 把二叉搜索树转换为累加树
    # 基于中序遍历的改进，为右左中
    def convertBST1(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None: return None
        cur = root
        stack = []
        acc = 0
        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.right
            else:
                cur = stack.pop()
                acc += cur.val
                cur.val = acc
                cur = cur.left
        return root
    # 递归我不会啊
    # 参考答案
    def convertBST(self, root):
        self.acc = 0
        def trav(node):
            if node == None: return
            trav(node.right)
            self.acc += node.val
            node.val = self.acc
            trav(node.left)
        trav(root)
        return root
        






