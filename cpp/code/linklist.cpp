#include<iostream>
#include<limits>
#include<math.h>
#include<vector>

using namespace std;


// // 定义链表节点
// struct ListNode{
//     int val; // 节点的值
//     ListNode *next; // 指向下一个节点
//     /*  节点的构造函数，cpp有一个默认的构造函数，默认是无参数的构造，不能传入参数
//         但是可以像下面一样自定义一个构造函数，但是必需按照构造来传入参数，不然报错    
//     */
//     ListNode(int x): val(x), next(NULL) {}
// };


// *
//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 707 设计链表
class MyLinkedList {
public:

    MyLinkedList() {
        dummyhead = new ListNode();
        _size = 0;
    }
    
    int get(int index) {
        if(index >= _size or index < 0){
            return -1;
        }
        ListNode *res = dummyhead;
        while(index >= 0){
            res = res->next;
            index--;
        }
        return res->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode();
        node->val = val;
        node->next = dummyhead->next;
        dummyhead->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = dummyhead;
        while(cur->next){
            cur = cur->next;
        }
        ListNode* node = new ListNode;
        node->val = val;
        cur->next = node;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index >= 0 and index <= _size){
            ListNode* cur = dummyhead;
            while(index > 0){
                cur = cur->next;
                index--;
            }
            ListNode* node = new ListNode();
            node->val = val;
            node->next = cur->next;
            cur->next = node;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >= 0 and index < _size){
            ListNode* cur = dummyhead;
            while(index > 0){
                cur = cur->next;
                index--;
            }
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            _size--;
        }
    }

private:
    ListNode* dummyhead;
    int _size;
};

class Solution {
public:

    // 203 移除链表元素
    // 我的方法，设置一个dummyhead
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* vhead = new ListNode(0, head);
        return deleteElementss(vhead, val);
    }
    ListNode* deleteElementss(ListNode* head, int val){
        ListNode* res = head;
        while ( head->next != nullptr){
            if (head->next->val == val){
                ListNode *tmp = head->next;
                head->next = head->next->next;
                delete tmp;
            }
            else{
                head = head->next;
            }
        }
        return res->next;
    }

    // 参考
    ListNode* removeElements_ref(ListNode* head, int val) {
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* cur = dummyhead;
        while(cur->next){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else{
                cur = cur->next;
            }
        }
        head = dummyhead->next;
        delete dummyhead;
        return head;
    }

    // 206 反转链表
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head;
        ListNode *nextnode = NULL;
        while(cur){
            nextnode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextnode;
        }
        return prev;
    }

    // 24. 两两交换链表中的节点
    // 自己写的好乱啊,cpp不熟悉,导致逻辑也非常混乱.
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode *dommyhead = new ListNode();
        ListNode *left = head, *right = head->next;
        ListNode *pre = dommyhead;
        while(true){
            pre->next = right;
            left->next = right->next;
            right->next=left;
            pre = left;
            if(left->next and left->next->next){
                left = left->next;
                right = left->next;
            }
            else break;
        }
        return dommyhead->next;
    }

    // 19. 删除链表的倒数第 N 个结点
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyhead = new ListNode();
        ListNode *pre = dummyhead;
        ListNode *cur = dummyhead;
        dummyhead->next = head;
        while(n > 0){
            cur = cur->next;
            n--;
        }
        while (cur->next){
            pre = pre->next;
            cur = cur->next;
        }
        ListNode *tmp = pre->next;
        pre->next = tmp->next;
        delete tmp;
        return dummyhead->next;
    }

    // 面试题 02.07. 链表相交

    int getListLen(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLen(headA), lenB = getListLen(headB);
        if(lenA < lenB){
            swap(lenA, lenB);
            swap(headA, headB);
        }
        int gap = lenA - lenB;
        while(gap){
            headA = headA->next;
            gap--;
        }
        while(headA){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

    // 142 环形链表Ⅱ
    // 注意这个问题的数学推导
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
    // 242. 有效的字母异位词
    bool isAnagram(string s, string t) {
        int table[26];
        for(char ch:s){
            table[ch - 'a']++;
        }
        for(char ch:s){
            table[ch - 'a']--;
        }
        for(int times: table){
            if(times) return false;
        }
        return true;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
    }

};



int main(){
}