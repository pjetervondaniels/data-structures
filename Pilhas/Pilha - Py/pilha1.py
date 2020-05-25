class Stack:
    #  A pilha segue o princípio FILO = ('First in, last out') para o português:
    # ' O primeiro a entrar e o último a sair..'

    def __init__(self):
        # Construtor
        self.stack = []

    def push(self, element):
        # Insere elemento na última posição
        self.stack.append(element)

    def pop(self):
        # Verifica se a Pilha está vazia e Remove elemento na última posição
        if not self.empty():
            self.stack.pop(len(self.stack) - 1)

    def top(self):
        # Retorna o valor do topo
        if not self.empty():
            return self.stack[-1]
        print('Pilha Vazia!')

    def length(self):
        return len(self.stack)


    def empty(self):
        # Verifica se a Pilha está vazia....
        if len(self.stack) == 0:
            return True
        return False


stack1 = Stack()

stack1.push(10)
stack1.push(2)
stack1.push(33)
stack1.push(42)
stack1.push(51)

print('  Pilha 1')

for i in range(0, 5, 1):
    print('==================================================')
    print('Último elemento da pilha: {}'.format(stack1.top()))
    print('Tamanho da Pilha: {}'.format(stack1.length()))
    stack1.pop()

