/*
[1, 5, 7, 3, 21, 19, 11, 9, 17, 13, 15]   lineal O(n)
[1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21]   Busqueda binaria O(log(n))

[10, 20, 30, 40, 50, 60, 70, 80, 90]
[1, 7, 28, 53, 73, 89, 100]
[2, 6, 14, 30, 62]

[10, ... , 100]
min 10
max 100
n = 10000
--> (x - min) / (max - min) = n  lugar aproximado del elemento x


Arboles binarios de busqueda.

En estos arboles binarios el nodo de la derecha es mas grande que su padre y que
el hermano izquierdo.

todo el arbol a la izquierda de un nodo debe ser menor que el nodo. y todos los
nodos a la derecha deben ser mayores que su padre.

struct node {
    node * right;
    node * left;
    void * data;
    int key;
}

struct abb{
    node * root;
    size_t size;
}

abb* new();
bool insert(abb * tree, int key, void * data);
bool find(abb * tree, int key); log(n)
void * get(abb * tree, int key); log(n)
void* delete(abb * tree, int key);

node* find_node (node* n, int key){
    if(!n) return NULL;
    if(n->key == key) return n;
    if(n->key > key) return find(n->left, key);
    else{return find(n->right, key);}
}

bool find(abb* tree, int key){
    return find(tree->root, key);
}

bool get(abb* tree, int key){
    node* n = find_node(tree->root, key);
    if(n) return n->data;
    return NULL;
}

node* find_parent(node * n, int key){
    if (!n) return NULL;
    if (key < n->key){
        if(!n->left) return n;
    }
    if(n->left->key == key) return n;
    return find_parent(n->left, key);
}

*/