import pytest
from linked_list import Node, Storage


@pytest.mark.parametrize("test_input", [1, 2, 5, 7, 8, "a", "b", 5.5, -1.2])
def test_node_init(test_input):
    n = Node(test_input)
    assert n.data == test_input


@pytest.mark.parametrize("test_input", [1, 2, 5, 7, 8, "a", "b", 5.5, -1.2])
def test_node_str(test_input):
    n = Node(test_input)
    assert str(n) == str(test_input)


def test_storage_init():
    s = Storage()
    assert s.head is None


def test_push():
    s = Storage()
    s.push(1)
    assert s.head.data == 1
    s.push(2)
    assert s.head.data == 2
    assert s.head.next.data == 1
    s.push(3)
    assert s.head.data == 3
    assert s.head.next.data == 2
    assert s.head.next.next.data == 1


def test_pop():
    s = Storage()
    s.push(1)
    s.push(2)
    s.push(3)
    assert s.pop() == 3
    assert s.pop() == 2
    assert s.pop() == 1
    assert s.pop() is None


def test_peek():
    s = Storage()
    s.push(1)
    assert s.peek() == 1
    assert s.peek() == 1
    s.push(2)
    assert s.peek() == 2
    assert s.peek() == 2
    s.push(3)
    assert s.peek() == 3
    assert s.peek() == 3


def test_isempty():
    s = Storage()
    assert s.isempty()
    s.push(1)
    assert not s.isempty()
    s.pop()
    assert s.isempty()

def test_swap():
    if hasattr(Storage, 'swap'):
        s = Storage();
        assert s.swap(0,1) == False

        s.push("f")
        s.push("e")
        s.push("d")
        s.push("c")
        s.push("b")
        s.push("a")
        assert s.swap(1,4) == True
        assert s.head.data == "a"
        assert s.head.next.data == "e"
        assert s.head.next.next.data == "c"
        assert s.head.next.next.next.data == "d"
        assert s.head.next.next.next.next.data == "b"
        assert s.head.next.next.next.next.next.data == "f"
        assert s.swap(4,1) == True
        assert s.swap(4,4) == True
        assert s.head.next.data == "b"
        assert s.head.next.next.next.next.data == "e"
        assert s.swap(1,6) == False
        assert s.swap(0,4) == True
        assert s.head.data == "e"
        assert s.head.next.data == "b"
        assert s.head.next.next.data == "c"
        assert s.head.next.next.next.data == "d"
        assert s.head.next.next.next.next.data == "a"
        assert s.head.next.next.next.next.next.data == "f"
        assert s.swap(5,0) == True
        assert s.head.data == "f"
        assert s.head.next.next.next.next.data == "a"
        assert s.head.next.next.next.next.next.data == "e"


if __name__ == '__main__':
    pytest.main()
