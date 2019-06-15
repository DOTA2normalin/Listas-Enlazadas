//https://ronnyml.wordpress.com/2009/07/04/listas-enlazadas-clase-lista-en-c/

#include <iostream>
using namespace std;

template<typename T>
class Nodo
{
public:
	T dato;
	Nodo<T> * next;
public:
	Nodo(T x) {
        dato=x;
        next=NULL;
    }
    void imprimir(){
        cout<<dato<<"-->";
    }
};


template<typename T>
class LinkedList{
private:
	Nodo<T>* head;
public: 
	LinkedList();
	void add(T);
    void insertar(T);
	void remove(T);
	void print();
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

template<typename T>
void LinkedList<T>::remove(T data_)
{
    Nodo<T> *temp = head;
    Nodo<T> *temp1 = head->next;
    
    if (head->dato == data_) {
        head = temp->next;
    }else {
        while (temp1) {
            if (temp1->dato == data_) {
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

int main()
{
    LinkedList<int> lst;
    lst.add(1);
    lst.add(2);
    lst.add(3);
    lst.add(4);
    lst.print();
    lst.insertar(-9);
    lst.print();
    lst.remove(-9);
    lst.print();
	return 0;
}
