c1 = {1, 2, 3}
c2 = {'marcos', 'maria', 'yankee'}
c3 = {1, 'marcos', 3.14}
c4 = set([1,2,2,3,3])

print(len(c2))
if 'marcos' in c2:
	print('encontrado')

c5 = {1, 2, 3, 4}
c6 = {3, 4, 5, 6}

print(c5 | c6) # união
print(c5 & c6) # intersecção
print(c6 - c5) # diferença

# removendo elementos
c = {10, 20, 30, 40}
c.remove(20)
print(c)