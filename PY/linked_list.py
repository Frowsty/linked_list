# linked_list by Daniel Barbis

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

    def __str__(self):
        return str(self.data)

class Storage:
    def __init__(self):
        self.head = None
        self.items = 0

    # add item to the front of the list and increment the items counter
    def push(self, data):
        newNode = Node(data)
        if not self.head:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode
        self.items += 1

    # remove the item at the front of the list while returning the data it contained and decrement the items counter
    def pop(self):
        if not self.head:
            return None
        data = self.head.data
        self.head = self.head.next
        self.items -= 1
        return data

    # return the data of the current head of the list
    def peek(self):
        return self.head.data

    # function to check if a linked list is empty or not
    def isempty(self):
        if not self.items:
            return True
        return False

    # function to swap data between nodes at index i and j
    def swap(self, i, j):
        if self.items <= i or self.items <= j and i is not j:
            return False

        node1 = None
        node2 = None

        temp = self.head

        k = 0
        while temp != None: 
            if k == i:
                node1 = temp
            if k == j:
                node2 = temp

            k += 1
            temp = temp.next


        temp = node1.data
        node1.data = node2.data
        node2.data = temp

        print(node1.data + " : " + node2.data)

        return True
