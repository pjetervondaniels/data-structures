class Node:

    def __init__(self, label):
        self.label = label
        self.left = None
        self.right = None

    def getLabel(self):
        return self.label

    def setLabel(self, label):
        self.label = label

    def getLeft(self):
        return self.left

    def setLeft(self, left):
        self.left = left

    def getRight(self):
        return self.right

    def setRight(self, right):
        self.right = right


class BinarySearchTree:

    def __init__(self):
        self.root = None

    def insert(self, label):

        # cria um novo nó
        node = Node(label)

        # verifica se a árvore está vazia
        if self.empty():
            self.root = node
        else:

            # árvore não vazia, insere recursivamente

            dad_node = None
            curr_node = self.root

            while True:

                if curr_node != None:

                    dad_node = curr_node

                    # verifica se vai para esquerda ou direita
                    if node.getLabel() < curr_node.getLabel():
                        # vai para esquerda
                        curr_node = curr_node.getLeft()
                    else:
                        # vai para direita
                        curr_node = curr_node.getRight()
                else:

                    # se curr_node é None, então encontrou onde inserir

                    if node.getLabel() < dad_node.getLabel():
                        dad_node.setLeft(node)
                    else:
                        dad_node.setRight(node)

                    break  # sai do loop

    def empty(self):
        if self.root == None:
            return True
        return False

    # mostra em pré-ordem (raiz-esq-dir)
    def show(self, curr_node):

        if curr_node != None:
            print('%d' % curr_node.getLabel(), end=' ')
            self.show(curr_node.getLeft())
            self.show(curr_node.getRight())

    def getRoot(self):
        return self.root


t = BinarySearchTree()
t.insert(8)
t.insert(3)
t.insert(1)
t.insert(6)
t.insert(4)
t.insert(7)
t.insert(10)
t.insert(14)
t.insert(13)

t.show(t.getRoot())
