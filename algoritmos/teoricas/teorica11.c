/*
BST - Binary Search Tree
find - O(log n)
insert - O(log n)
delete - O(log n)

Red Black Tree: Son arboles que tienen la garantia de que siempre estan
ordenados.
*/

/*
Skip List
Hace lo mismo que un arbol binario balanceado, sin serlo.

Tengo una lista enlazada
-> [6] -> [8] -> [3] -> [21] -> [2] -> [4] -> [15] -> [9]

La ordeno
-> [2] -> [3] -> [4] -> [6] -> [8] -> [9] -> [15] -> [21]
El ordenarla no nos mejora nada, vamos a buscar una forma de que el orden de la
lista nos ayude.

Creo otra lista enlazada, pero esta vez con saltos.

-> [2] --------> [4] --------> [8] --------> [15] -> [21]
-> [2] -> [3] -> [4] -> [6] -> [8] -> [9] -> [15] -> [21]
Podemos ver que si buscamos un elemento primero lo buscamos en la lista de
arriba, una vez no podemos buscar mas, buscamos en la lista de abajo. pero en el
espacio entre los saltos de la lista de arriba.

Uso mas listas
----------------------> [6] ------------------------------->
----------[3]---------->[6]--- ------>[9] ---------------- >
--------> [3] -> [4]--> [6] -> [8] -> [9] ---------> [21] ->
-> [2] -> [3] -> [4] -> [6] -> [8] -> [9] -> [15] -> [21] ->

y tengo una suerte de arbol binario balanceado, pero sin serlo y con la ventaja
de que es dinámico. La cantidad de listas que tengo es log(n) Uso una lista para
guardar estas listas de manera ordenada
[*] ----------------------> [6] ------------------------------->
[*] ----------[3]---------->[6]--- ------>[9] ---------------- >
[*] --------> [3] -> [4]--> [6] -> [8] -> [9] ---------> [21] ->
[*] -> [2] -> [3] -> [4] -> [6] -> [8] -> [9] -> [15] -> [21] ->

No tengo forma de grantizar O log(n) en los metodos, pero puedo asegurar que hay
una alta probabilidad de que si lo sea.

Para hacerlo nos ayudaremos del azar

SKIP LIST (estructura aleatorizada)

agarro un elemento para empezar, el [80]

[-∞] -----------> [∞]
[-∞] -----------> [∞]
[-∞] -----------> [∞]
[-∞] --> [80] --> [∞]

uso una moneda para ver hasta donde sube el elemento. La moneda me dice que sube

[-∞] -----------> [∞]
[-∞] -----------> [∞]
[-∞] --> [80] --> [∞]
[-∞] --> [80] --> [∞]

Tiro una moneda y me fijo de vuelta. no sube mas. Paso a usar otro elemento el
[7]

[-∞] -------------------> [∞]
[-∞] -------------------> [∞]
[-∞] ----------> [80] --> [∞]
[-∞] --> [7] --> [80] --> [∞]

La moneda me dice que no sube mas. uso el 90

[-∞] ----------------------------> [∞]
[-∞] ----------------------------> [∞]
[-∞] ----------> [80] -----------> [∞]
[-∞] --> [7] --> [80] --> [90] --> [∞]

La moneda dice que no subo. agrego [100]. La moneda dice que sube 2 veces

[-∞] --------------------------------------> [∞]
[-∞] ----------------------------> [100] --> [∞]
[-∞] ----------> [80] -----------> [100] --> [∞]
[-∞] --> [7] --> [80] --> [90] --> [100] --> [∞]

Pruebo con el [244] la moneda dice que subo 2 veces

[-∞] ------------------------------------------------> [∞]
[-∞] ----------------------------> [100] --> [214] --> [∞]
[-∞] ----------> [80] -----------> [100] --> [214] --> [∞]
[-∞] --> [7] --> [80] --> [90] --> [100] --> [214] --> [∞]

Pruebo con [e]. No sube

[-∞] --------------------------------------------------------> [∞]
[-∞] ------------------------------------> [100] --> [214] --> [∞]
[-∞] ------------------> [80] -----------> [100] --> [214] --> [∞]
[-∞] --> [e] --> [7] --> [80] --> [90] --> [100] --> [214] --> [∞]

Pruebo con [120]. Sube 3 veces

[-∞] --------------------------------------------- > [120] ------------> [∞]
[-∞] ------------------------------------> [100] --> [120] --> [214] --> [∞]
[-∞] ------------------> [80] -----------> [100] --> [120] --> [214] --> [∞]
[-∞] --> [e] --> [7] --> [80] --> [90] --> [100] --> [120] --> [214] --> [∞]

Pruebo con [3200]. Subo 1 vez

[-∞] --------------------------------------------- > [120]
-----------------------> [∞]
[-∞] ------------------------------------> [100] --> [120] --> [214]
-------------> [∞]
[-∞] ------------------> [80] -----------> [100] --> [120] --> [214] --> [3200]
--> [∞]
[-∞] --> [e] --> [7] --> [80] --> [90] --> [100] --> [120] --> [214] --> [3200]
--> [∞]

Pruebo con [-25]. Subo 1 vez

[-∞] ------------------------------------------------------- > [120]
-----------------------> [∞]
[-∞] ----------------------------------------------> [100] --> [120] --> [214]
-------------> [∞]
[-∞] --> [-25] ------------------> [80] -----------> [100] --> [120] --> [214]
--> [3200] --> [∞]
[-∞] --> [-25] --> [e] --> [7] --> [80] --> [90] --> [100] --> [120] --> [214]
--> [3200] --> [∞]

La lista queda asi. Los metodos de busqueda en esta lista son
Lista enlazada busqueda
search O (n)
_________________________
SKIP-LIST

search O (log(n)) |-\
insert O (log(n)) |--> with high probability. Funciona siempre que la
probabilidad siga funcionando delete O (log(n)) |-/

*/