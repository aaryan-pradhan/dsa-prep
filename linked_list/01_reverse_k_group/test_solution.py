from solution import ListNode, reverse_k_group


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
    head = build([1, 2, 3, 4, 5, 6])
    assert to_list(reverse_k_group(head, 3)) == [3, 2, 1, 6, 5, 4]


def test_sample_2():
    head = build([1, 3, 2])
    assert to_list(reverse_k_group(head, 3)) == [2, 3, 1]


def test_k_equals_1_is_noop():
    head = build([1, 2, 3, 4])
    assert to_list(reverse_k_group(head, 1)) == [1, 2, 3, 4]


def test_k_equals_n_reverses_whole_list():
    head = build([1, 2, 3, 4, 5])
    assert to_list(reverse_k_group(head, 5)) == [5, 4, 3, 2, 1]


def test_single_node():
    head = build([7])
    assert to_list(reverse_k_group(head, 1)) == [7]


def test_multiple_full_groups_of_two():
    head = build([1, 2, 3, 4, 5, 6, 7, 8])
    assert to_list(reverse_k_group(head, 2)) == [2, 1, 4, 3, 6, 5, 8, 7]
