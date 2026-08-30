// Problem: Reverse Nodes in k-Group
// Pattern: group-bounded in-place reversal
// Time: O(N)  Space: O(1)
//
// Given a singly linked list of length N and an integer K, reverse the nodes
// in groups of size K and return the head. K divides N exactly (no partial
// final group to worry about).
//
// Constraints: 1 ≤ N ≤ 1e6, 1 ≤ K ≤ N, 0 ≤ node values ≤ 1e9, N % K == 0.
//
// Example:
//     [1,2,3,4,5,6], K=3 -> [3,2,1,6,5,4]
//         [1,3,2],       K=3 -> [2,3,1]

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

ListNode* reverse(ListNode* head) {
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

ListNode* reverseList(ListNode* head, int K) {
    if (head == nullptr || K == 1) return head;

    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;

    while (head) {
        ListNode* tail = head;
        for (int i = 1; i < K; i++) tail = tail->next;

        ListNode* nextGroup = tail->next;
        tail->next = nullptr;
        ListNode* newHead = reverse(head);

        prev->next = newHead;
        head->next = nextGroup;

        prev = head;
        head = nextGroup;
    }
    return dummy->next;
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
    int K; cin >> K;

    ListNode* head = GetList(num);
    head = reverseList(head, K);

    while (head) { cout << head->val << " "; head = head->next; }
    cout << "\n";
    return 0;
}

// Recall Trail
// - State: head = start of current unprocessed group, prev = last node of
//   the previous (already-reversed) group, dummy node ahead of head avoids
//   special-casing the first group.
// - Reverse helper: p, c = None, h; loop while c: save n = c.next before
//   overwriting c.next = p (must save first — you lose the rest of the list
//   otherwise), then p, c = c, n; return p.
// - Group loop: walk t forward k-1 steps to find the group's tail, save
//   nxtg = t.next, cut with t.next = None, reverse the group, then splice:
//   prev.next = new_head, old_head.next = nxtg, advance
//   prev, head = old_head, nxtg.
// - k == 1 needs no special case — the loop degenerates to a 1-node
//   "reversal" and relinks correctly on its own.
