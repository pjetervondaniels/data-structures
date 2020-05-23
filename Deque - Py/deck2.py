from collections import deque

d = deque()
d.append(1) # adiciona do lado direito
d.appendleft(2) # adiciona do lado esquerdo
d.append(3)
d.appendleft(4)

# 4, 2, 1, 3
for i in d:
	print(i, end=' ')

print(' ')
print('==================================================')

d.remove(2)

for i in d:
	print(i, end=' ')