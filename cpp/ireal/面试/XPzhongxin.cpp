#include<iostream>

using namespace std;  

class List{
public:
    
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void addAtTail(ListNode* head, int val) {
    ListNode* p = head;
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = new ListNode(val);
}

int main(){
    ListNode* head = new ListNode(0);
    addAtTail(head, 1);
    addAtTail(head, 2);
    addAtTail(head, 3);
    addAtTail(head, 4);
    ListNode* p = head;
    while(p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
}