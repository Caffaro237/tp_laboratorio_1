#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

//Estructuras del LinkedList
struct nodo
{
    void* p_elemento;// Puntero al elemento
    struct nodo* p_siguiente_nodo;// Puntero al prox nodo

}typedef nodo;

struct LinkedList
{
    nodo* p_primer_nodo;
    int tam;

}typedef LinkedList;


//Prototipos de Funciones del LinkedList
LinkedList* ll_nueva_linkedlist(void);
int ll_len(LinkedList* lista);
int ll_add(LinkedList* lista, void* p_elemento);
void* ll_get(LinkedList* lista, int index);
int ll_set(LinkedList* lista, int index,void* p_elemento);
int ll_remove(LinkedList* lista,int index);
int ll_clear(LinkedList* lista);
int ll_delete_linkedlist(LinkedList* lista);
int ll_index_of(LinkedList* lista, void* p_elemento);
int ll_is_empty(LinkedList* lista);
int ll_push(LinkedList* lista, int index, void* p_elemento);
void* ll_pop(LinkedList* lista,int index);
int ll_contains(LinkedList* lista, void* p_elemento);
int ll_contains_all(LinkedList* lista,LinkedList* lista_2);
LinkedList* ll_sub_list(LinkedList* lista,int origen, int destino);
LinkedList* ll_clone(LinkedList* lista);
int ll_sort(LinkedList* lista, int(*p_func)(void* ,void*), int orden);
LinkedList* ll_filter(LinkedList* lista, int(*p_func)(void*));
LinkedList* ll_map(LinkedList* lista, void*(*p_func)(void* elemento));


#endif // LINKEDLIST_H_INCLUDED
