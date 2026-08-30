from solution import ListNode, mergesort


def build(values):
    head = cur = None
    for v in values:
        node = ListNode(v)
        if cur is None:
            head = cur = node
        else:
            cur.next = node
            cur = node
    return head


def to_list(head):
    out = []
    while head:
        out.append(head.val)
        head = head.next
    return out


def test_sample_1():
    head = build([2])
    assert to_list(mergesort(head)) == [2]


def test_sample_2():
    head = build([1, 3, 6, 1, 7])
    assert to_list(mergesort(head)) == [1, 1, 3, 6, 7]


def test_empty_list():
    head = build([])
    assert to_list(mergesort(head)) == []


def test_two_nodes_out_of_order():
    head = build([5, 2])
    assert to_list(mergesort(head)) == [2, 5]


def test_already_sorted():
    head = build([1, 2, 3, 4, 5])
    assert to_list(mergesort(head)) == [1, 2, 3, 4, 5]


def test_reverse_sorted():
    head = build([5, 4, 3, 2, 1])
    assert to_list(mergesort(head)) == [1, 2, 3, 4, 5]


def test_duplicates():
    head = build([4, 4, 4, 1, 1])
    assert to_list(mergesort(head)) == [1, 1, 4, 4, 4]
