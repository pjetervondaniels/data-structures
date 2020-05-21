d = {} # criando um dicionário vazio

# inserindo os elementos
d['joao'] = 20
d['maria'] = 30
d['pedro'] = 25

# mostrando os valores
for k in d.keys():
	print(d[k])

chave_procurada = 'joao'

# procurando uma chave
if chave_procurada in d.keys():
	print('chave encontrada')
else:
	print('chave NAO encontrada')

# deletando uma chave
del d['joao']