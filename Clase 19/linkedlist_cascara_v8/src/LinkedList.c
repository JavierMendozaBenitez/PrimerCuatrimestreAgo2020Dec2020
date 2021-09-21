#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);//obtiene un vagon, devuelve la direccion de memoria de un vagon que adentro tiene dos direcciones de memoria
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado, deberia limpiar los campos, inicializar en size el 0 y pFirstNode en NULL
 */
LinkedList* ll_newLinkedList(void)//reserva espacio en memoria
{
    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->size = 0;//falta test que verifique estos dos
        this->pFirstNode = NULL;
    }

    return this;//si no consigue espacio en memoria devolvera NULL
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)//devuelve la cantidad de elementos, cantidad de vagones, devuele el size
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
{ //cargar o leer su carga. Tambien para obtener la direccion del vagon que viene atras
    Node* pNodo = NULL;
    int contador = 0;

    /*if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode;//inicializas pNode, que es la locomotora, con la direccion del primer vagon, del vagon 0.
        //El linkedlist this que apunta al primer vagon es igual a pNode, ambos apuntan al mismo lugar
        //la direccion de memoria que esta guardada en el linkedlist ahora esta guardada en pNode

        while(nodeIndex > 0) //si no se cumple devuelve 0, la direccion del primer vagon/elemento/nodo
        {
            pNodo = pNodo->pNextNode;//ahora pNode apunta al vagon que viene atras
            nodeIndex--;      //achicas el nodeIndex para que corte cuando encontro el elemento requerido, si no disminuye nuca para de buscar
        }
    }*/
    /*if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode;
        while(contador < nodeIndex)
        {
            pNodo = pNodo->pNextNode;
            contador++;
        }
    }*/

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        for(pNodo = this->pFirstNode; contador < nodeIndex; contador++)
        {
            pNodo = pNodo->pNextNode;
        }
    }

    return pNodo;
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)//agrega un vagon, coloca un nodo entre dos nodos
{
    int returnAux = -1;
    Node* nuevoNode = NULL;//creas un nuevo vagon
    Node* nodoAux = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        nuevoNode = (Node*) malloc(sizeof(Node));//asignas memoria al vagon
        if(nuevoNode != NULL)
        {
            nuevoNode->pElement = pElement; // el pElement que nos pasaron por parametro se lo asignas al pElement del nuevo nodo
            //nuevoNode->pNextNode = NULL;
            if(nodeIndex == 0)//si es 0, tenes que engancharlo de la locomotora, sino de algun vagon
            {
                nuevoNode->pNextNode = this->pFirstNode;//primero haces que el nuevo nodo apunte al vagon 0, la direccion de ese vagon esta en la locomotora
                this->pFirstNode = nuevoNode;// segundo, la locomotora ya no apunta al viejo nodo, apunta al nuevo nodo
            }
            else//ahora enganchamos a cualquier vagon y no a la locomotora, debes engancharlo entre medio de dos nodos
            {
                nodoAux = getNode(this, nodeIndex-1);//Guardas en nodoAux la direccion del nodo anterior al que queres agregar, porque ahí esta la direccion de pNextNode que es el lugar donde queres agregar el nuevo nodo
                nuevoNode->pNextNode = nodoAux->pNextNode;//copias en nuevoNode la direccion del lugar que le sigue al lugar donde queres agregarlo
                nodoAux->pNextNode = nuevoNode;//Copias en nodeAux pNextNode la  direccion del nuevo nodo, con esto lo colocaste entre los dos
            }
            this->size++;//aumento la cantidad de nodos
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
    return addNode(this, ll_len(this), pElement);
    // el indice es ll_len(this) porque len devuelve el tamanio de la lista mediante el size, entonces le decis que agrege el pElement
    // en la ubicacion que coincide con el tamanio de la lista, es al final de la Linkedlist
}

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la
verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
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
    Node* nodeAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))//es menor a len porque si es igual no existe ese index
    {
        nodeAux = getNode(this, index);//guardas el puntero al nodo que se encuentra en ese indice para poder leer el pElement

        if(nodeAux != NULL)
        {
            returnAux = nodeAux->pElement;//guardas en el retorno el pElement del nodeAux
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

    if(this != NULL && index >= 0 && index < ll_len(this))//es menor a len porque si es igual no existe ese index
    {
        Node* auxNode = getNode(this, index);//guardas el puntero al nodo que se encuentra en ese indice para poder leer el pElement

        if(auxNode != NULL)
        {
            auxNode->pElement = pElement;//copias en el auxNode pElement el pElement que nos pasaron por parametro
            returnAux = 0;//devuelve 0 porque se hizo bien
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
//se desea eliminar el elemento de indice 0, debemos escribir en el campo pFirstNode de la LinkedList la direccion del elemento del indice 1.
//si es otro nodo, escribir en el campo de pNextNode de el elemento que viene antes la direccion de memoria del elemento que viene despues.
    int returnAux = -1;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
       // Node* nodoAnterior = getNode(this, index -1);
        Node* nodoARemover = getNode(this, index);

        if(index == 0)
        {
            this->pFirstNode = nodoARemover->pNextNode;//Si es el primer nodo, la Linkedlist apunta al nodo de indice 1
        }
        else
        {
            /*Node* nodoAnterior = getNode(this, index - 1);
            nodoAnterior->pNextNode = (nodoAnterior->pNextNode)->pNextNode;*/
            //de esta forma haces que nodoAnterior->pNextNode sea igual al valor que hay en (nodoAnterior->pNextNode)->pNextNode,
            //vas accediendo de vagon a vagon, un nodo llama al otro y asi

            getNode(this, index - 1)->pNextNode = nodoARemover->pNextNode;
            //Llamo al nodo anterior al nodo que quiero eliminar y le cargo la direccion del nodo que le sigue al que quiero eliminar
        }
        free(nodoARemover);//libero la memoria de ese nodo
        this->size--;//una vez que lo elimine disminuyo el tamanio
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

    if(this != NULL)
    {
        int tam = ll_len(this);//declaras el tamanio de la LinkedList

        for(int i= tam-1; i >= 0; i--)//recorres desde el final al principio si  usas un for
        {
            ll_remove(this, i);//vas removiendo nodo a nodo.
        }
        returnAux = 0;
    }
    /*
    if(this != NULL)
    {
        while(ll_len(this) != 0)//vas eliminando el vagon 0, esto si usas un while, vas de 0 al final
        {
            ll_remove(this, 0);
        }
        returnAux = 0;
    }
*/
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
        if(!ll_clear(this))//vacias todo el LinkedList y usas el retorno para entrar al if y haces free de la lista
        {
            free(this);
            this = NULL;//apunta a NULL para que ese espacio de memoria no quede apuntando a algun lugar que no deberia.
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
    if(this != NULL)
    {
        int tam = ll_len(this);//asi llamas una sola vez a ll_len, si lo metes en el for lo calculo cada vez

        for(int i=0; i<tam; i++)
        {
            if(ll_get(this, i) == pElement)//aca devuelve el pElement en la posicion i
            {
                returnAux = i;//la posicion del vagon
                break;//con este devuelve 1 posicion
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
        returnAux = ll_len(this) == 0? 1 : 0 ;//reemplazas el if else. Se llama ternario. Si es == 0 devolve 1, sino devolve 0
    }

    /*if(this != NULL)
    {
        if(ll_len(this))//si la cantidad de elementos es diferente de 0 es que esta cargada la lista
        {
            returnAux = 0;
        }
        else// si da 0 es que la lista esta vacia
        {
            returnAux = 1;
        }
    }*/

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
//uass addNode para insertar un elemento en una ubicacion en particular
//no usar ll_add porque agrega si o si un elemento al final de la lista
{
    return addNode(this, index, pElement);
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
        returnAux = ll_get(this, index);//guardas el pElement en returnAux para devolverlo

        if(ll_remove(this, index))//si falla el ll_remove devuelve -1, entra y returnAux vale NULL
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
        returnAux = ll_indexOf(this, pElement) == -1 ? 0 : 1;
    }

    /*if(this != NULL)
    {
        returnAux = 1;//ya lo declaras como bien

        if(ll_indexOf(this, pElement) == -1)//si ll_indexOf devuelve -1 es porque el elemento no esta en la lista entonces devolves 0
        {
            returnAux = 0;
        }
    }*/

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
    int len;
    void* aux;// creas este aux para guardar los elementos que te devuelva ll_get

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        len = ll_len(this2);//conseguis el tamanio de la lista 2

        for(int i = 0; i < len; i++)
        {
            aux = ll_get(this2, i);//guardas cada elemento de la lista 2 en un auxiliar
            if(!ll_contains(this, aux))//con ll_contains recorres toda la lista 1 comparando cada elemento de la lista 2
            {
                returnAux = 0;
                break;//con que haya un elemento que no este, corta la busqueda.
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

    if(this != NULL && from >= 0 && from < ll_len(this) && to <= ll_len(this) && from < to)
        //from debe ser menor al to, iguales no porque el to no esta incluido
    {
        cloneArray = ll_newLinkedList();

        if(cloneArray != NULL)
        {
            for(int i = from; i < to; i++)//recorres la lista 1 original desde el elemento de indice from hasta el elemento de indice to
                //para cargar en el cloneArray los elementos de la lista 1
            {
                ll_add(cloneArray, ll_get(this, i));//los cargas en el nuevo LinkedList
            }
        }
    }

    return cloneArray;
}
//[from, to)
/*
[18, 65] // intervalo cerrado porque esta entre corchetes, va de 18 a 65 inclusive
(18, 65) //abierto, tiene parenyesis, el 18 y 65 no estan incluidos
(17, 66) //con esto incluis al 18 y 65
(17, 65] //intervalo abierto por izquierda, el 17 no esta incluido pero el 65 si lo esta
[18, 65) // cerrado por izquierda abierta por derecha, 18 incluido, 65 no */


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)//devuelve una copia fiel de la lista original, crea una nueva lista que apunta a los elementos de otra
{
    /*LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
        cloneArray = ll_subList(this, 0, ll_len(this));//clonas desde el 0 al ultimo elemento
    }

    return cloneArray;*/

    return ll_subList(this, 0, ll_len(this));//ll_subList devuelve una lista donde se cargaron los elementos desde el from al to
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
    void* pAux = NULL;//creas una variable auxiliar para el swap ya que voy a swapear las cargas


    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        int comparacion;//Ya que la funcion que recibo devuelve 1 si es mayor el primer parametro con respecto al segundo
        //devuelve 0 si son iguales, -1 si el primero es mas chico que el segundo, creo una variable para guardar ese valor devuelto

        int len = ll_len(this);//esto lo haces aca para no llamar simepre a ll_len
        for(int i = 0; i < ll_len(this) - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                comparacion = pFunc(ll_get(this, i), ll_get(this, j));// 1: A > B
                //asignas en cada vuelta, en comparacion, el valor devuelto por la funcion que chequea si el elemento 1 es mayor o no del elemento 2
                //comparacion: 1 si A > B
                //comparacion: 0 si A = B
                //comparacion: -1 si A < B, ya están ordenados
                if((comparacion == 1 && order) || (comparacion == -1 && !order))//depende del numero devuelto y el orden elegido swapeo
                {//swapeas los elementos con set, con get conseguis los punteros a los elementos
                    pAux = ll_get(this, i);//guardas en pAux el puntero al primer elemento
                    ll_set(this, i, ll_get(this, j));//con set pisas en el indice i de this el elemento que esta en this en el indice j
                    ll_set(this, j, pAux);// en el indice j de this guardas el puntero al elemento de indice i de this
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
     void* auxElement = NULL;

     if(this != NULL && pFunc != NULL)
     {
         listaFiltrada = ll_newLinkedList();
         if( listaFiltrada != NULL)
         {
             int tam = ll_len(this);

             for( int i = 0; i < tam; i++)
             {
                 auxElement = ll_get(this, i);

                 if( pFunc(auxElement) )
                 {
                     ll_add(listaFiltrada, auxElement);//agrega cada elemento que pase el filtro
                 }
             }
         }
     }
     return listaFiltrada;
}
