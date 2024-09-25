/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */  
#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverse_List(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next;
        while (cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << slow->val << endl;
        cout << fast->val << endl;
        ListNode *p1 = head;
        ListNode *head1 = reverse_List(slow->next);
        slow->next = nullptr;
        ListNode *p2 = head1;
        // while (p1 != nullptr)
        // {
        //     if (p1->val != p2->val)
        //     {
        //         return false;
        //     }
        //     p1 = p1->next;
        //     p2 = p2->next;
        // }
        while(p1){
            cout << p1->val << " ";
            p1 = p1->next;
        }
        cout << endl;
        while(p2){
            cout << p2->val << " ";
            p2 = p2->next;
        }
        return true;
    }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(1);
    Solution s;
    cout << s.isPalindrome(head) << endl;
    cout << "hello" << endl;
}