// https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/
// https://www.youtube.com/watch?v=pq3wN8TrdHo

#include <iostream>
using namespace std;
//template<typename T>
//class LinkedList;

//template<typename T>
//class ListIterador;

template<typename T>
class Nodo
{
public:
	T dato;
	Nodo<T> *next;
public:
	Nodo(T x) {
        dato=x;
        next=NULL;
    }
    void imprimir(){
        cout<<dato<<" --> ";
    }
    void delete_all()
    {
        if(next)
            next->delete_all();
        delete this;
    }
  //  friend class ListIterador;
   // friend class LinkedList;
};

template<typename T>
class LinkedList{
public:    
	Nodo<T>* head;
public: 
	LinkedList();
    ~LinkedList();
	void add(T);
    void insertar(T);
	void remove(T);
    void del_all();
	void print();
    //friend class ListIterador;   

};
template <typename T>
LinkedList<T>::LinkedList(){
	head=NULL;
}
template<typename T>
void LinkedList<T>::add(T data_)
{
    Nodo<T> *new_node = new Nodo<T> (data_);
    Nodo<T> *temp = head;
 
    if (!head) {
        head = new_node;
    } else {
        if (head->dato > data_) {
            new_node->next = head;
            head = new_node;
        } else {
            while ((temp->next != NULL) && (temp->next->dato < data_)) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

template<typename T>
void LinkedList<T>::insertar(T data_){
    Nodo<T> *new_node = new Nodo<T> (data_);
    Nodo<T> *temp = head;
 
    if (!head) {
        head = new_node;
    } else {
        if (head->dato > data_) {
            new_node->next = head;
            head = new_node;
        } else {
            
            while ((temp->next != NULL) && (temp->next->dato < data_)) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

/*template<typename T>
void LinkedList<T>::remove(T data_)
{
    Nodo<T> *temp = head;
    Nodo<T> *temp1 = head->next;
    
    if (temp->dato == data_) {
        head = temp->next;
    }
    else 
    {
        while (!temp1) {
            if (temp1->dato == data_) {
                Nodo<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}*/

template<typename T>
void LinkedList<T>::remove(T pos)
{
    Nodo<T> *temp = head;
    Nodo<T> *temp1 = temp->next;
 
    if (pos < 1 ) {
        cout << "Fuera de rango " << endl;
    } else if (pos == 1) {
        head = temp->next;
    } else {
        for (int i = 2; i <= pos; i++) {
            if (i == pos) {
                Nodo<T> *aux_node = temp1;
                temp->next = temp1->next;
                delete aux_node;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
}

template<typename T>
void LinkedList<T>::del_all()
{
    head->delete_all();
    head = 0;
}

template<typename T>
void LinkedList<T>::print()
{
    Nodo<T> *temp = head;
    
    if (!head) {
            cout << "Lista no inicializada " << endl;
        } else {
            while (temp) {
                temp->imprimir();
                if (!temp->next) cout << "NULL";
                    temp = temp->next;
            }
    }
    cout << endl << endl;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
    del_all();
}

template<typename T>
class ListIterador
{
    Nodo<T> *pNodo;
    Nodo<T> *anterior;
public:
    void operator =(Nodo<T> *nodo)
    {
        pNodo=nodo;
        anterior=nodo;
    }
    int operator ++()
    {
        anterior=pNodo;
        pNodo=pNodo->next;
    }
    void operator--()
    {
        pNodo=anterior;
    }
    T operator *()
    {
        return pNodo->dato;
    }
    void operator ==(T nodo)
    {
        if(pNodo->dato==nodo)
            cout<<"se encontro el dato :"<<pNodo->dato;
        else{
            cout<<"no se encontro "<<endl; 
        }
    }
    void operator !=(T nodo)
    {
        if(pNodo->dato!=nodo)
            cout<<"es diferente el dato :"<<pNodo->dato;
        else{
            cout<<"no se encontro "<<endl;
        }
    }
    int datos()
    {
            cout<<pNodo->dato<<" ";
    }
    bool hasMore()
    {
        if(pNodo->next!= NULL)
            return false;
        else
            return true;
    }

    bool found(T n)
    {
        if(pNodo->dato == n)
        {
            return true;
        }

        Nodo<T> *temp = pNodo;
        while(temp->next != NULL)
        {   
            if(temp->next->dato == n)
            {
                return true;
            }
        }
    }
};

int main()
{
    LinkedList<int> lst;
    lst.add(1);
    lst.add(2);
    lst.add(3);
    lst.add(4);
    lst.print();
    lst.insertar(5);
    lst.insertar(50);
    lst.insertar(-9);
    lst.print();
    lst.remove(3);
    lst.remove(1);
    lst.print();

    ListIterador<int> iterador;
    iterador=lst.head;
    iterador.datos();
    while(iterador.hasMore)
    {
        if(iterador.found)
        {
            ++iterador;
        }
    }
    *iterador;
    ++iterador;
    --iterador;
    *iterador;
    iterador==50;
    iterador!=5;
	return 0;
}
