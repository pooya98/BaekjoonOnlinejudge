class Stack():
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack.append(data)

    def pop(self):
        pop_object = None

        if self.isEmpty():
            print("Stack is Empty")
        else:
            pop_object = self.stack.pop()

        return pop_object

    def top(self):
        top_object = None
        if self.isEmpty():
            print("Stack is Empty")
        else:
            top_object = self.stack[-1]

        return top_object

    def isEmpty(self):
        is_empty = False

        if len(self.stack) == 0:
            is_empty = True
            return is_empty


if __name__ == '__main__':

    while True:
        string = input()

        if string == '.':
            break

        stack = Stack()
        flag = True

        for i in range(len(string)):
            if string[i] == '(' or string[i] == '[':
                stack.push(string[i])

            elif string[i] == ')':
                if stack.isEmpty():
                    flag = False
                    break
                else:
                    if stack.pop() == '(':
                        continue
                    else:
                        flag = False
                        break

            elif string[i] == ']':
                if stack.isEmpty():
                    flag = False
                    break
                else:
                    if stack.pop() == '[':
                        continue
                    else:
                        flag = False
                        break

            else:
                continue

        if not stack.isEmpty():
            flag = False

        if flag:
            print("yes")
        else:
            print("no")
