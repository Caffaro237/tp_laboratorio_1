#ifndef __LINKEDLIST
#define __LINKEDLIST

//Declaracion de las estructuras del LinkedList
struct
{
    void* pElement;
    struct Node* pNextNode;

}typedef Node;

struct
{
    Node* pFirstNode;
    int size;

}typedef LinkedList;

#endif

//Prototipos de las funciones LinkedList usadas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* empleado);
int ll_add(LinkedList* empleado, void* p_elemento);
void* ll_get(LinkedList* empleado, int index);
int ll_set(LinkedList* empleado, int index,void* p_elemento);
int ll_remove(LinkedList* empleado, int index);
int ll_sort(LinkedList* empleado, int (*p_func)(void* ,void*), int orden);


//Prototipos de las funciones LinkedList no usadas
Node* test_getNode(LinkedList* empleado, int node_index);
int test_addNode(LinkedList* empleado, int node_index,void* p_elemento);
int ll_clear(LinkedList* empleado);
int ll_deleteLinkedList(LinkedList* empleado);
int ll_indexOf(LinkedList* empleado, void* p_elemento);
int ll_isEmpty(LinkedList* empleado);
int ll_push(LinkedList* empleado, int index, void* p_elemento);
void* ll_pop(LinkedList* empleado, int index);
int ll_contains(LinkedList* empleado, void* p_elemento);
int ll_containsAll(LinkedList* empleado, LinkedList* empleado_2);
LinkedList* ll_subList(LinkedList* empleado, int origen, int destino);
LinkedList* ll_clone(LinkedList* empleado);


