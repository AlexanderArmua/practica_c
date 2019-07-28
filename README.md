# Es es un proyecto personal para ir aprendiendo C.

## Comandos Utiles (Bash):
- Compilar: ```gcc uddt.c -o uddt.exe```
- Compilar para evaluar Memory Leak con Valgrind: ```gcc PROGRAMA.c -o PROGRAMA_debug.exe -g```
- Correr Valgrind para ver Memory Leak: ```valgrind --leak-check=yes ./PROGRAMA_debug.exe```

## TODO:
### Implementar operaciones Disponibles por definicion para ADT
#### List:
- ```get()```
- ```insert()```
- ```remove()```
- ```removeAt()```
- ```replace()```
- ```size()```
- ```isEmpty()```
- ```isFull()```

#### Stack:
- ```push()```
- ```pop() //LIFO```
- ```peek()``` (Elemento en la cima sin removerlo)
- ```size()```
- ```isEmpty()```
- ```isFull()```

#### Queue
- ```enqueue()``` (Nuevo elemento al final)
- ```dequeue()``` (Remover y retornar primer elemento)
- ```peek()``` (Primer elemento sin removerlo)
- ```size()```
- ```isEmpty()```
- ```isFull()```