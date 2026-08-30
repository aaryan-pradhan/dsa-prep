from solution import max_difference


def test_sample():
    assert max_difference([1, 2, 3, 4, 5]) == 4


def test_min_after_max():
    assert max_difference([5, 1]) == -4


def test_strictly_decreasing():
    assert max_difference([5, 4, 3, 2, 1]) == -1


def test_min_in_middle():
    assert max_difference([7, 1, 5, 3, 6, 4]) == 5


def test_two_elements_increasing():
    assert max_difference([1, 5]) == 4


def test_all_equal():
    assert max_difference([3, 3, 3]) == 0
