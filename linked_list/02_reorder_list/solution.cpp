// Problem: Reorder List I
// Pattern: split + reverse second half + merge alternately
// Time: O(N)  Space: O(1)

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next_ = NULL;

    while (cur != NULL) {
        next_ = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_;
    }
    return prev;
}

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* mid = middleNode(head);
    ListNode* second = mid->next;
    mid->next = nullptr;
    second = reverseList(second);

    ListNode* first = head;
    while (second) {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}

ListNode* GetList(vector<int>& num) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (int x : num) {
        ListNode* temp = new ListNode(x);
        if (!cur) { head = cur = temp; }
        else { cur->next = temp; cur = temp; }
    }
    return head;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];

    ListNode* head = GetList(num);
    reorderList(head);

    while (head) { cout << head->val << " "; head = head->next; }
    cout << "\n";
    return 0;
}
