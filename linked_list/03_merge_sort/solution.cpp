// Problem: Sort a Linked List (Merge Sort)
// Pattern: divide and conquer — split at midpoint, recurse, merge two sorted lists
// Time: O(N log N)  Space: O(log N) recursion stack

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

ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {
    if (!left) return right;
    if (!right) return left;

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while (left && right) {
        if (left->val < right->val) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return dummy->next;
}

ListNode* mergesort(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* mid = findMid(head);

    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = nullptr;

    left = mergesort(left);
    right = mergesort(right);

    return merge(left, right);
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
    head = mergesort(head);

    while (head) { cout << head->val << " "; head = head->next; }
    cout << "\n";
    return 0;
}
