// Problem: Reorder List I
// Pattern: split + reverse second half + merge alternately
// Time: O(N)  Space: O(1)
//
// Given the head of a singly linked list, reorder it in place from
// L1 -> L2 -> ... -> Ln to L1 -> Ln -> L2 -> Ln-1 -> L3 -> Ln-2 -> ....
// Node values may not be changed — only links may be rewired.
//
// Constraints: 0 ≤ length ≤ 1e6, 0 ≤ node value ≤ 1e9.
//
// Example:
//     [3]           -> [3]
//         [1,2,3,4]     -> [1,4,2,3]
//         [1,2,3,4,5]   -> [1,5,2,4,3]

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

// Recall Trail
// - Core idea: singly-linked means no prev pointer, so you can't walk
//   backward from the tail repeatedly. Reversing a portion turns "walk
//   backward" into "walk forward" — so split the list in half, reverse the
//   second half, then merge the two halves by alternating nodes.
// - Middle-finder variant used here (slow=fast=head; each iteration
//   fast=fast->next, and only if fast is still non-null does
//   slow=slow->next; fast=fast->next run): lands on the *second* middle for
//   even-length lists, so the first half ends up longer by 2 for even N (and
//   by 1 for odd N, same as the standard fast->next && fast->next->next
//   variant). This is fine here — see next point.
// - Merge loop: while (second) — tmp1=first->next, tmp2=second->next,
//   first->next=second, second->next=tmp1, first=tmp1, second=tmp2.
//   Because the loop condition is only on second, it degrades gracefully:
//   second empty from the start (N≤2) → loop body never runs, list
//   untouched; second shorter than first → last write is
//   second->next=tmp1, which reattaches the untouched remainder of first
//   automatically. No special-casing needed for either the split asymmetry or
//   small N.
