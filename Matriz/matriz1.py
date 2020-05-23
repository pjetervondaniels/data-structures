matriz = [
    [10, 20, 30, 40],
    [50, 60, 70, 80],
    [90, 100, 110, 120]
]

print('Printando a Matriz!')
for i in range(0, 3, 1):
    for j in range(0, 3, 1):
        print('Matriz [{}][{}] = {}'.format(i, j, matriz[i][j]))