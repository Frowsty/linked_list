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

    def push(self, data):
        newNode = Node(data)
        if not self.head:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head = newNode
        self.items += 1

    def pop(self):
        if not self.head:
            return None
        data = self.head.data
        self.head = self.head.next
        self.items -= 1
        return data

    def peek(self):
        return self.head.data

    def isempty(self):
        if not self.items:
            return True
        return False

    def swap(self, i, j):
        if self.items <= i or self.items <= j and i != j:
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
