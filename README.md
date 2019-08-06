# Personal project for learn "C".

## Utils (Bash):
- Compile: ```gcc PROGRAM_NAME.c -o PROGRAM_NAME.exe```
- Compile including debbuging information for Valgrind: ```gcc PROGRAM_NAME.c -o PROGRAM_NAME_DEBUG.exe -g```
- Run Valgrind for look Memory Leaks: ```valgrind --leak-check=yes ./PROGRAM_NAME_DEBUG.exe```

## TODO:
#### Add "C Unit"
#### Add Travis o Jenkins
#### Add the following
#### 00- Pointers
```
---Ingrese el valor nº 0: 1
---Ingrese el valor nº 1: 2
---Ingrese el valor nº 2: 3
---Ingrese el valor nº 3: 4
---Ingrese el valor nº 4: 5
        | VALUE         |   ID  |   SIGUIENTE   |
        | Valor: 1      | Id: 0 | Sgt: True     |
        | Valor: 2      | Id: 1 | Sgt: True     |
        | Valor: 3      | Id: 2 | Sgt: True     |
        | Valor: 4      | Id: 3 | Sgt: True     |
        | Valor: 5      | Id: 4 | Sgt: False    |
```
__*** stack smashing detected ***: <unknown> terminated__
__Aborted (core dumped)__

#### 01- Queue (Done):
- It can be better :)

#### 02- List:
- ```get()```
- ```insert()```
- ```remove()```
- ```removeAt()```
- ```replace()```
- ```size()```
- ```isEmpty()```
- ```isFull()```

#### 03- Stack:
- ```push()```
- ```pop() //LIFO```
- ```peek()``` (Elemento en la cima sin removerlo)
- ```size()```
- ```isEmpty()```
- ```isFull()```

## Done: 
#### 01- Queue
- ```enqueue()``` 
- ```dequeue()```
- ```peek()```
- ```size()```
- ```isEmpty()```
- ```isFull()```