#include <climits>
#include <iostream>
using namespace std;

int main() {
    struct ListNode {
        int val;
        ListNode* next{nullptr};
        ListNode(int x) : val(x)  {}
    };
    int opNum;
    int listSize = 0;
    cin >> opNum;
    string op;
    auto dummyHead = new ListNode(INT_MAX);
    for (int i = 0; i < opNum; i++) {
        cin >> op;
        if (op == "insert") {
            auto cur = dummyHead;
            int x, y;
            cin >> x >> y;
            while (cur->next != nullptr && cur->next->val != x) {
                cur = cur->next;
            }
            auto node = new ListNode(y);
            auto temp = cur->next;
            cur->next = node;
            node->next = temp;
            listSize++;
        } else if (op == "delete") {
            int x;
            cin >> x;
            auto cur = dummyHead;
            while (cur->next && cur->next->val != x) {
                cur = cur->next;
            }
            if (cur->next) {
                auto temp = cur->next->next;
                delete (cur->next);
                cur->next = temp;
                listSize--;
            }
        }
    }
    if (listSize) {
        auto cur = dummyHead;
        while (cur->next) {
            cur = cur->next;
            cout << cur->val;
            if (cur->next) cout << ' ';
        }
        cout << endl;
    }
    else cout << "NULL" << endl;
}
// 64 位输出请用 printf("%lld")