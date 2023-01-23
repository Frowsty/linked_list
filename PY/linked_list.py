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
