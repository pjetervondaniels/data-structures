'''
	Implementação da priority queue com lista ordenada
'''

class Person:

	'''
		nome -> nome da pessoa
		prior -> prioridade da pessoa
	'''
	def __init__(self, name, prior):
		self.name = name
		self.prior = prior

	def getName(self):
		return self.name

	def getPrior(self):
		return self.prior

class PriorityQueue:

	def __init__(self):
		self.pq = [] # priority queue
		self.len = 0 # length of priority queue

	# insere decrescentemente pela prioridade
	def push(self, person):

		if self.empty():
			self.pq.append(person)
		else:

			flag_push = False

			# procura-se onde inserir para manter a fila ordenada
			for i in range(self.len):
				if self.pq[i].getPrior() < person.getPrior():
					self.pq.insert(i, person)
					flag_push = True
					break

			if not flag_push:
				# se entrou aqui é porque tem que inserir ao final
				self.pq.insert(self.len, person)

		self.len += 1

	def pop(self):
		if not self.empty():
			self.pq.pop(0)
			self.len -= 1

	def empty(self):
		if self.len == 0:
			return True
		return False

	def show(self):
		for p in self.pq:
			print('Nome: %s' % p.getName())
			print('Prioridade: %d\n' % p.getPrior())

# criando os objetos Person
p1 = Person('Marcos', 28)
p2 = Person('Catarina', 3)
p3 = Person('Pedro', 20)
p4 = Person('João', 35)

# criando a fila de prioridades e inserindo os elementos
pq = PriorityQueue()
pq.push(p1)
pq.push(p2)
pq.push(p3)
pq.push(p4)

print('Exibindo após as inserções:\n')
pq.show() # João, Marcos, Pedro, Catarina

# removendo elementos
pq.pop()
pq.pop()

print('Exibindo após as remoções:\n')
pq.show() # Pedro, Catarina

# inserindo um novo elementos
pq.push(Person('Goku', 30))
print('Exibindo após a inserção:\n')
pq.show() # Goku, Pedro, Catarina