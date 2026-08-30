// Problem: Sort a Linked List (Merge Sort)
// Pattern: divide and conquer — split at midpoint, recurse, merge two sorted lists
// Time: O(N log N)  Space: O(log N) recursion stack
//
// Sort a singly linked list in O(N log N) using merge sort. Return the new head.
//
// Constraints: 0 ≤ N ≤ 1e5, 0 ≤ node value ≤ 1e9.
//
// Example:
//     [2]           -> [2]
//         [1,3,6,1,7]   -> [1,1,3,6,7]

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

// Recall Trail
// - Array merge sort needs random-access splitting; a linked list doesn't
//   have that, so find the midpoint with slow/fast pointers (as in
//   02_reorder_list), recurse on both halves, then merge.
// - findMid here starts fast = head->next (not head, unlike the
//   reorder-list variant) — this lands on the *first* middle and, critically,
//   guarantees progress: with fast = head a 2-node list would return
//   slow = head unchanged, and calling mergesort again on the same head
//   recurses forever. Base case (!head || !head->next) is what actually
//   prevents that for 0/1-node lists, but the fast = head->next offset is
//   what keeps a 2-node split from degenerating.
// - Merge step is a comparison merge, not the reorder problem's
//   alternating merge: left->val < right->val decides which node gets
//   appended next, since the two halves are independently sorted, not just
//   split halves of one list.
// - Once one side runs out, the entire remaining side can be spliced on
//   wholesale, unsorted-comparison-free — every node left in the exhausted
//   side's sibling is already ≥ everything merged so far, since it survived
//   every earlier comparison.
// - Base case must handle both head == nullptr and head->next == nullptr:
//   skipping it either null-derefs in findMid (head->next on null) or
//   infinite-recurses on a single node.
