#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static nodo* get_node(LinkedList* lista, int nodo_index);
static int add_node(LinkedList* lista, int nodo_index,void* p_elemento);


/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_nueva_linkedlist(void)
{
    LinkedList* nueva_lista;

    nueva_lista = (LinkedList*) malloc(sizeof(LinkedList));

    if(nueva_lista != NULL)
    {
        nueva_lista->tam = 0;
        nueva_lista->p_primer_nodo = NULL;
    }

    return nueva_lista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* lista)
{
    int cantidad = -1;

    if(lista != NULL)
    {
        cantidad = lista->tam;
    }

    return cantidad;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return nodo* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static nodo* get_node(LinkedList* lista, int nodo_index)
{
    nodo* nodo = NULL;

    if(lista != NULL  && nodo_index >= 0 && nodo_index < ll_len(lista))
    {
        nodo = lista->p_primer_nodo;

        while(nodo_index > 0)
        {
            nodo = nodo->p_siguiente_nodo;
            nodo_index = nodo_index - 1;
        }
    }

    return nodo;
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodo_index int Ubicacion donde se agregara el nuevo nodo
 * \param p_elemento void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int add_node(LinkedList* lista, int nodo_index, void* p_elemento)
{
    int retorno = -1;
    nodo* nuevo_nodo = NULL;
    nodo* anterior = NULL;

    if(lista != NULL  && nodo_index >= 0 && nodo_index <= ll_len(lista))
    {
        nuevo_nodo = (nodo*) malloc(sizeof(nodo));

        if(nuevo_nodo != NULL)
        {
            nuevo_nodo->p_elemento = p_elemento;

            nuevo_nodo->p_siguiente_nodo = NULL;

            if(nodo_index == 0)
            {
                nuevo_nodo->p_siguiente_nodo = lista->p_primer_nodo;

                lista->p_primer_nodo = nuevo_nodo;
            }
            else
            {
                anterior = get_node(lista, nodo_index - 1);

                nuevo_nodo->p_siguiente_nodo = anterior->p_siguiente_nodo;

                anterior->p_siguiente_nodo = nuevo_nodo;
            }
        }

        lista->tam++;

        retorno = 0;
    }

    return retorno;
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param p_elemento void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* lista, void* p_elemento)
{
    return add_node(lista, ll_len(lista), p_elemento);
}

/** \brief Permite realizar el test de la funcion add_node la cual es privada
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodo_index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (p_elemento) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* lista, int index)
{
    void* retorno = NULL;
    nodo* aux_node = NULL;

    aux_node = get_node(lista, index);

    if(aux_node != NULL)
    {
        retorno = aux_node->p_elemento;
    }

    return retorno;
}


/** \brief Modifica un elemento de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodo_index int Ubicacion del elemento a modificar
 * \param p_elemento void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* lista, int index, void* p_elemento)
{
    int retorno = -1;

    nodo* aux_node = NULL;

    if(lista != NULL && index >= 0 && index < ll_len(lista))
    {
        aux_node = get_node(lista, index);

        if(aux_node != NULL)
        {
            aux_node->p_elemento = p_elemento;

            retorno = 0;
        }
    }

    return retorno;
}


/** \brief Elimina un elemento de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodo_index int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* lista, int index)
{
    int retorno = -1;
    nodo* actual = NULL;
    nodo* anterior = NULL;

    if(lista != NULL && index >= 0 && index < ll_len(lista))
    {
        actual = get_node(lista, index);

        if(actual != NULL)
        {
            if(index == 0)
            {
                lista->p_primer_nodo = actual->p_siguiente_nodo;

                free(actual);
                lista->tam--;
                retorno = 0;
            }
            else
            {
                anterior = get_node(lista, index - 1);

                if(anterior != NULL)
                {
                    anterior->p_siguiente_nodo = actual->p_siguiente_nodo;

                    free(actual);
                    lista->tam--;
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* lista)
{
    int retorno = -1;

    if(lista != NULL)
    {
        while(ll_len(lista) != 0)
        {
            ll_remove(lista, 0);
        }

        retorno = 0;
    }

    return retorno;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_delete_linkedlist(LinkedList* lista)
{
    int retorno = -1;

    if(lista != NULL)
    {
        if(!ll_clear(lista))
        {
            free(lista);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param lista LinkedList* Puntero a la lista
 * \param p_elemento void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_index_of(LinkedList* lista, void* p_elemento)
{
    int retorno = -1;
    int tam;
    nodo* aux_node = NULL;

    if(lista != NULL)
    {
        tam = ll_len(lista);

        for(int i = 0; i < tam; i++)
        {
            aux_node = get_node(lista, i);

            if(aux_node != NULL)
            {
                if(aux_node->p_elemento == p_elemento)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }

    return retorno;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param lista LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_is_empty(LinkedList* lista)
{
    int retorno = -1;

    if(lista != NULL)
    {
        retorno = 1;

        if(ll_len(lista))
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodo_index int Ubicacion donde se agregara el nuevo elemento
 * \param p_elemento void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* lista, int index, void* p_elemento)
{
    return add_node(lista, index, p_elemento);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param lista LinkedList* Puntero a la lista
 * \param nodo_index int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (p_elemento) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* lista,int index)
{
    void* retorno = NULL;

    if(lista != NULL  && index >= 0 && index <= ll_len(lista))
    {
        retorno = ll_get(lista, index);

        if(ll_remove(lista, index))
        {
            retorno = NULL;
        }
    }

    return retorno;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param lista LinkedList* Puntero a la lista
 * \param p_elemento void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* lista, void* p_elemento)
{
    int retorno = -1;

    if(lista != NULL)
    {
        retorno = 0;

        if(ll_index_of(lista, p_elemento) >= 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}

/** \brief  Determina si todos los elementos de la lista (lista_2)
            estan contenidos en la lista (lista)
 *
 * \param lista LinkedList* Puntero a la lista
 * \param lista_2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (lista_2) estan contenidos en la lista (lista)
                        ( 0) si los elementos de (lista_2) NO estan contenidos en la lista (lista)
*/
int ll_contains_all(LinkedList* lista, LinkedList* lista_2)
{
    int retorno = -1;
    int tam = ll_len(lista_2);
    void* aux_element;

    if(lista != NULL && lista_2 != NULL)
    {
        retorno = 1;

        for(int i = 0; i < tam; i++)
        {
            aux_element = ll_get(lista_2, i);

            if(!ll_contains(lista, aux_element))
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param origen int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice origen es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a origen o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_sub_list(LinkedList* lista, int origen, int destino)
{
    LinkedList* clon_array = NULL;

    if(!(lista == NULL || origen < 0 || origen > ll_len(lista) || destino <= origen || destino > ll_len(lista)))
    {
        clon_array = ll_nueva_linkedlist();

        if(lista != NULL)
        {
            for(int i = origen; i < destino; i++)
            {
                ll_add(clon_array, ll_get(lista, i));
            }
        }
    }

    return clon_array;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* lista)
{
    return ll_sub_list(lista, 0, ll_len(lista));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param p_func (*p_func) Puntero a la funcion criterio
 * \param orden int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* lista, int (*p_func)(void* ,void*), int orden)
{
    int retorno = -1;
    void* aux_elemento;
    int tam;

    if(lista != NULL && (*p_func) != NULL && orden >= 0 && orden <= 1)
    {
        tam = ll_len(lista);

        for(int i = 0; i < tam - 1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                if(p_func(ll_get(lista, i), ll_get(lista, j)) > 0 && orden)
                {
                    aux_elemento = ll_get(lista, i);
                    ll_set(lista, i, ll_get(lista, j));
                    ll_set(lista, j, aux_elemento);
                }
                else if(p_func(ll_get(lista, i), ll_get(lista, j)) < 0 && !orden)
                {
                    aux_elemento = ll_get(lista, i);
                    ll_set(lista, i, ll_get(lista, j));
                    ll_set(lista, j, aux_elemento);
                }
            }
        }

        retorno = 0;
    }

    return retorno;

}

/*
    Filter llama a pFunc y le pasa cada uno de los elementos de la lista
    Y si pFunc devuelve 1, a ese elemento lo carga en la nueva lista
    Devuelve un nuevo linkedlist que tiene
*/
LinkedList* ll_filter(LinkedList* lista, int (*p_func)(void*))
{
    LinkedList* lista_filtrada = NULL;
    int tam;
    void* aux_elemento = NULL;

    if(lista != NULL && (*p_func) != NULL)
    {
        lista_filtrada = ll_nueva_linkedlist();
        tam = ll_len(lista);

        if(lista_filtrada != NULL)
        {
            for(int i = 0; i < tam; i++)
            {
                aux_elemento = ll_get(lista, i);

                if(p_func(aux_elemento))
                {
                    ll_add(lista_filtrada, aux_elemento);
                }
            }
        }
    }

    return lista_filtrada;
}

LinkedList* ll_map(LinkedList* lista, void*(*p_func)(void* elemento))
{
    LinkedList* lista_mapeada = NULL;
    int tam;
    void* aux_elemento = NULL;

    if(lista != NULL && (*p_func) != NULL)
    {
        lista_mapeada = ll_nueva_linkedlist();
        tam = ll_len(lista);

        if(lista_mapeada != NULL)
        {
            for(int i = 0; i < tam; i++)
            {
                aux_elemento = ll_get(lista, i);

                if(p_func(aux_elemento))
                {
                    ll_add(lista_mapeada, aux_elemento);
                }
            }
        }
    }

    return lista_mapeada;
}
