from solution import ListNode, reorder_list


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
    head = build([3])
    reorder_list(head)
    assert to_list(head) == [3]


def test_sample_2():
    head = build([1, 2, 3, 4])
    reorder_list(head)
    assert to_list(head) == [1, 4, 2, 3]


def test_sample_3():
    head = build([1, 2, 3, 4, 5])
    reorder_list(head)
    assert to_list(head) == [1, 5, 2, 4, 3]


def test_two_nodes():
    head = build([1, 2])
    reorder_list(head)
    assert to_list(head) == [1, 2]


def test_empty_list():
    head = build([])
    reorder_list(head)
    assert to_list(head) == []


def test_six_nodes_even():
    head = build([1, 2, 3, 4, 5, 6])
    reorder_list(head)
    assert to_list(head) == [1, 6, 2, 5, 3, 4]
