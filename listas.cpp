#include <iostream>
using namespace std;

class Nodo
{
private:
	int dato;
	Nodo * next;
public:
	Nodo(int x,Nodo *sig=NULL) {
        this->dato=x;
        this->next=sig;
    }
	void setdato(int a) {
		dato = a;
	}
	void setNodo(Nodo* siguiente) {
		next = siguiente;
	}
	int getdato() {
		return dato;
	}
	Nodo* getNodo() {
		return next;
	}
	~Nodo() {

	}
    friend class LinkedList;
};

class LinkedList:public Nodo{
private:
	Nodo* primero;
	Nodo* actual;
public: 
	LinkedList() {
		this->primero = NULL;
		this->actual = NULL;
	}
    bool ListaVacia() {
		return(this->primero = NULL);
	}
	void insertar(int v) {
		Nodo* nuevo = new Nodo(v);
		if (ListaVacia()) {
			this->next = nuevo;
		}
		else {
			this->actual->next = nuevo;
		}
		this->actual = nuevo;
	}
	void mostrar() {
		Nodo* tmp = this->primero;
		while (tmp) {
			cout << tmp->dato<< "-->";
			tmp = tmp->next;
		}
		cout << "NULL\n";
	}
    Nodo *borrar(Nodo* LinkedList, int elemento){
        if(LinkedList!=NULL){
            Nodo *aux_borrar;
            Nodo *anterior=NULL;

            aux_borrar=LinkedList;

            while((aux_borrar!=NULL)&& (aux_borrar)!=elemento)
            {
                anterior=aux_borrar;
                aux_borrar=aux_borrar->next;
            }

            if(aux_borrar==NULL){
                cout<<"elemento no ha sido encontrado";
            }
            else if(anterior==NULL){
                LinkedList=LinkedList->next;
                delete aux_borrar;
            }
            else{
                anterior->next=aux_borrar->next;
                delete aux_borrar;
            }
        }
    }
};

int main()
{
    LinkedList lst;
    lst.insertar(1);
    lst.insertar(2);
    lst.insertar(3);
    lst.insertar(4);
    lst.borrar(LinkedList,2);
    lst.mostrar();
	return 0;
}