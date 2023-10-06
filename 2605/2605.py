class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.count = 0

    def __len__(self):
        return self.count

    def __str__(self):
        cur_node = self.head
        result = ""

        while cur_node:
            result += (str(cur_node.data) + " ")
            cur_node = cur_node.next

        return result


    def insert(self, index, new_node):
        if index < 0 or index > self.count:
            return False

        if index == 0:
            new_node.next = self.head
            self.head = new_node

        else:
            prev_node = self.head
            cur_index = 0;

            while cur_index != index - 1:
                prev_node = prev_node.next
                cur_index += 1

            new_node.next = prev_node.next
            prev_node.next = new_node

        self.count += 1
        return True

    def remove(self, index):
        if index < 0 or index >= self.count:
            return -1

        cur_node = self.head

        if index == 0:
            self.head = self.head
        else:
            prev_node = self.head
            cur_index = 0;

            while cur_index != index - 1:
                prev_node = prev_node.next
                cur_index += 1

            delete_node = prev_node.next
            prev_node.next = prev_node.next.next

        self.count -= 1
        return delete_node.data

    def search(self, data):
        cur_node = self.head
        index = 0

        while cur_node:
            if cur_node.data == data:
                return index
            else:
                cur_node = cur_node.next
                index += 1

        return -1


if __name__ == '__main__':
    myList = LinkedList()

    N = int(input())

    myList.insert(0, Node(1))

    choice = list(map(int, input().split(" ")))

    for i in range(2, N + 1):

        location = myList.count - choice[i - 1]

        myList.insert(location, Node(i))

    print(myList)