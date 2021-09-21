#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado, deberia limpiar los campos, inicializar el size en 0 y pFirstNode en NULL
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)//obtiene la direccion de un vagon/nodo para escribirle o leerle el campo pElemente,
 //cargar o leer su carga. Tambien para obtener la direccion del vagon que viene atras
{
    Node* pNode = NULL;

    int len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
    {
        pNode = this->pFirstNode;

        while(nodeIndex > 0)
        {
            pNode = pNode->pNextNode;
            nodeIndex--;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo = NULL;
    Node* auxNodo = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));

        if(nuevoNodo != NULL)
        {
            nuevoNodo->pElement = pElement;

            if(nodeIndex == 0)
            {
                nuevoNodo->pNextNode = this->pFirstNode;
                this->pFirstNode = nuevoNodo;
            }
            else
            {
                auxNodo = getNode(this, nodeIndex-1);
                nuevoNodo->pNextNode = auxNodo->pNextNode;
                auxNodo->pNextNode = nuevoNodo;
            }
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)//crear un nuevo nodo/vagon, pElement debe apuntar al elemento que nos pasaron y
//agregar el nodo a la lista, por default lo agrega al final
{
    int returnAux = -1;

    if(this != NULL)
    {
        addNode(this, ll_len(this), pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el �ndice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tama�o del array. Si la
verificaci�n falla la funci�n retorna (NULL) y si tiene �xito retorna el elemento.
 *
 * \param this LinkedList* Puntero a la lista
 * \param Index int Ubicacion del puntero a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)//devuelve la ubicacion de la carga (pElement), un puntero al pElement
{
    void* returnAux = NULL;
    Node* auxNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNodo = getNode(this, index);

        if(auxNodo != NULL)
        {
            returnAux = auxNodo->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)//sirve para cambiar un pElement del nodo, pisas una carga por otra.
{
    int returnAux = -1;
    Node* auxNodo = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNodo = getNode(this, index);

        if(auxNodo != NULL)
        {
            auxNodo->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)//borra el nodo de la lista, desconecta un nodo, conecta el nodo de atras con el nodo de adelante.
{//el nodo de indice-1(adelante) debe apuntar al elemento que este atras indice+1. Si el elemento de adelante es la locomotora/Linkedlist,
//se desea eliminar el elemento de indice 0, debemos escribir en el campo pFirstNode del LinkedList la direccion del elemento del indice 1.
//si es otro nodo, escribir en el campo de pNextNode de el elemento que viene antes la direccion de memoria del elemento que viene despues.
    int returnAux = -1;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        Node* nodoARemover = getNode(this, index);

        if(index == 0)
        {
            this->pFirstNode = nodoARemover->pNextNode;
        }
        else
        {
            getNode(this, index-1)->pNextNode = nodoARemover->pNextNode;
        }
        free(nodoARemover);
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)//Elimina todos los elementos de la lista. Deja el LinkedList como cuando lo creas, sin el primer nodo,
//solo queda la locomotora con un size 0. Hace un free de cada nodo. Recorres la LinkedList mientras que el tamanio sea distinto de 0 y los removes.
//Los removes desde el final al principio porque o sino perdes las direcciones de memoria a borrar
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);

        for(int i = len-1; i >= 0; i--)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)//Elimina todos los elementos de la lista y la lista
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)//es un buscador, como buscar libre o un buscar empleado. Recorre todo el LinkedList buscando
//la primera aparicion de un pElement. Buscar el primer nodo que apunte a pElement, que su campo pElement tenga la misma direccion de memoria
// que me mandaron a buscar. Devolver la ubicacion, el indice de ese vagon.
{
    int returnAux = -1;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);

        for(int i = 0; i < tam; i++)
        {
            if(ll_get(this, i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)//Agregas un nodo en cualquier ubicacion
//usas addNode para insertar un elemento en una ubicacion en particular
//no usar ll_add porque agrega si o si un elemento al final de la lista
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        if(!(addNode(this, index, pElement)))
        {
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)//El elemento que esta en el indice que estoy solicitando se retira de la lista pero lo devolves.
//Devolves el puntero al pElemento de la lista y lo sacas de la lista
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        returnAux = ll_get(this, index);

        if(ll_remove(this, index))
        {
            returnAux = NULL;
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = 1;

        if(ll_indexOf(this, pElement) == -1)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)//Chequea si todos los elementos de la lista 2 estan en la lista 1
{
    int returnAux = -1;
    int tam;
    void* aux;

    if(this != NULL && this2 != NULL)
    {
        tam = ll_len(this2);

        returnAux = 1;

        for(int i = 0; i < tam; i++)
        {
            aux = ll_get(this2, i);

            if(!ll_contains(this, aux))
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)//copia los elementos de una lista en otra
//devolveme una lista nueva donde como integrantes de esa lista esten los elementos del linkedList original this que esten ubicados
//desde el indice from como intervalo cerrado, o sea el que este en el indice from este, hasta el indice to, el indice to no debe figurar.
//El to no debe estar incluido por eso va to <= ll_len(this), podes traer uno mas para que entre el to
{
    LinkedList* cloneArray = NULL;
    void* aux = NULL;
    int tam;

    if(this != NULL && from >= 0 && from < ll_len(this) && from < to && to <= ll_len(this))
    {
        cloneArray = ll_newLinkedList();

        if(cloneArray != NULL)
        {
            for(int i = from; i < to; i++)
            {
                aux = ll_get(this, i);
                ll_add(cloneArray, aux);
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)//devuelve una copia fiel de la lista original, crea una nueva lista que apunta a los elementos de otra
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)//swapeamos la carga porque solo swapeamos un puntero
//Si lo hariamos con los nodos, swapeamos dos punteros, el pElement y el nextNode
{
    int returnAux =-1;
    void* pAux = NULL;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        int comparacion;
        int tam = ll_len(this);

        for(int i = 0; i < tam-1; i++)
        {
            for(int j = i + 1; j < tam; j++)
            {
                comparacion = pFunc(ll_get(this, i), ll_get(this, j));

                if((comparacion == 1 && order) || (comparacion == -1 && !order))
                {
                    pAux = ll_get(this, i);
                    ll_set(this, i, ll_get(this, j));
                    ll_set(this, j, pAux);
                }
            }
        }
        returnAux = 0;
    }


    return returnAux;
}


/** \brief Retorna una nueva lista con los elementos que hacen que pFunc retorne 1
 *
 * \param this Lista a filtrar
 * \param pFunc Funcion que sabe como filtrar la lista
 * \return un nuevo LinkedList con los elementos que pasan el filtro
 *
 */
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    LinkedList* listaFiltrada = NULL;
    void* pAux = NULL;

    if(this != NULL && pFunc != NULL)
    {
        listaFiltrada = ll_newLinkedList();

        if(listaFiltrada != NULL)
        {
            int tam = ll_len(this);

            for(int i = 0; i < tam; i++)
            {
                pAux = ll_get(this, i);

                if(pFunc(pAux))
                {
                    ll_add(listaFiltrada, pAux);
                }
            }
        }

    }
    return listaFiltrada;
}

