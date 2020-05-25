class Stack:

    def __init__(self):
        self.stack = []
        self.len_stack = 0

    def push(self, element):
        self.stack.append(element)
        self.len_stack += 1

    def pop(self):
        if not self.empty():
            self.stack.pop(self.len_stack - 1)
            self.len_stack -= 1

    def top(self):
        if not self.empty():
            return self.stack[-1]
        print('Pilha Vazia!')

    def length(self):
        return self.len_stack

    def empty(self):
        if self.len_stack == 0:
            return True
        return False


stack1 = Stack()

stack1.push(10)
stack1.push(2)
stack1.push(33)
stack1.push(42)
stack1.push(51)

print('==================================================')
print('  Pilha 1 Otimizada')

for i in range(0, 6, 1):
    print('---------------------------')
    print('Último elemento da pilha: {}'.format(stack1.top()))
    print('Tamanho da Pilha: {}'.format(stack1.length()))
    print('Topo Removido!')
    stack1.pop()
    
print('==================================================')
