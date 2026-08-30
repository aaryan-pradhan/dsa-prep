// Problem: Reverse List - hard version (Reverse Nodes in k-Group)
// Pattern: group-bounded in-place reversal
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
