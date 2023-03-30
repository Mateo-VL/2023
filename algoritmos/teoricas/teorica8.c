/*colas de prioridad/Heaps
 *
 *get_max()----------------O(1)
 *remove()-----------------O(log n)
 *insert(elem, pr)---------O(log n)
 *build(elem[],pri[],n)----O(n)
 *aka heapify
 *
 *pq = meld(pq, pq2)-------O(log n)"destruir todo y armar un heap nuevo"
 *
 *Torunament trees:
 *Siempre es un heap, pero no todo heaps son torunament trees.
 *-El heap es un arbol binario completo.
 *-Los elementos estan en las hojas
 *-Los nodos no-hoja replican elementos
 *-Cumple la prioridad de Heap
 *-La cantidad de elementos en cada nivel es potencia de 2
 *
 *get_max()
 *remove_max()
 *insert(elem, pr)
 *pq = meld(pq, pq2)
 *
 **OBS: Es muy facil hacer el meld de 2 tournament trees con = cantidad de
 *elementos
 *
 *Tournament Heap
 *"Conjunto de torunament trees"
 *"no puede haber 2 torunament trees con la misma cantidad de elementos(misma
 *altura)"
 *
 *insert(elem, pr)---------O(log n)
 *get_max()----------------O(log n)
 *remove_max()-------------O(log n)
 *pq3 = meld(pq1, pq2)-------O(log n)
 *
 *
 *En un sort por comparaciòn no puedo mejorar O(n log n)
 *
 *Teorema:
 *En una cola de prioridad o insert o remove_max tienen que ser al menos O(log
 *n) no puedo mejorar insert y remove_max juntos pero puedo intentar mejorar uno
 *de ellos
 *
 *Intentemos mejorar insert
 *"LAZY TOURNAMENT HEAP"
 *
 *Idea: al insertar no hacer nada
 *Inserto los elementos sin ordenarlos y los ordeno recien cuando alguien lo
 *pida En remove max luego de sacar el maximo hacemos los meld necesarios
 *
 *remove_max()
 *si lo hacemos n veces 1 vez O(n) y las otras O(log n)
 *costo amortizado
 *(1 * O(n) + O(log n)) / n = O(log n)
 *O(log n) amortizado
 */
