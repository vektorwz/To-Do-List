/**
 * Name: Agustin Silvero Castillo aka vektor
 * App: To-Do List / Lista de quehaceres
 * Date: 16/12/21
 * Purpose: A To-Do list. ATM: You can add tasks and display the lis. Working on modifying and changing the state (done/in progress)
**/

#include <iostream>
#include <string>
#include <ios>
#include <limits>   

using namespace std;

struct datos {
    int id;
    char titulo[28];
    char desc[256];
    bool estado;
};

struct Nodo{
    datos info;
    Nodo* sig;
};

void agregar(Nodo* &lista, int &id);
void mostrar(Nodo*lista);
void eliminar(Nodo*&lista, int &id);
Nodo* buscar(Nodo*lista, int val);
void modificar(Nodo*&lista);

int main(){
    char input;
    int id = 1;
    Nodo* lista = NULL;
    cout << "Welcome" << endl << "The list's functions are the following:" << endl;
    cout << "a: add | d: delete " << endl << "m: modify a task | q: change state" << endl;
    cout << "s: show the list" << endl;
    cout << "Please enter a key with your desired option, then press enter. To quit enter 'x' " << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // limpia el buffer y el \n en el buffer
    
    while (input!='x'){
        switch(input){
            case 'a':
            cout << "Option a" << endl;
            agregar(lista, id);
            break;
            
            case 'd':
            cout << "Option d" << endl;
            eliminar(lista, id);
            break;
            
            case 'm':
            cout << "Option m" << endl;
            modificar(lista);
            break;
            
            case 'q':
            cout << "Option q" << endl;
            break;
            
            case 's':
            cout << "Option s" << endl;
            mostrar(lista);
            break;
        }//fin switch
        cout << "Enter an option to continue" << endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    
    return 0;
}

void agregar(Nodo* &lista, int &id){
    // Creo y cargo el nuevo nodo
    Nodo* nuevo = new Nodo();
    nuevo->info.id = id;
    id++;
    cout << "Enter a title" << endl;
    cin.getline(nuevo->info.titulo, 28);
    
    cout << "Enter a description" << endl;
    cin.getline(nuevo->info.desc, 256);
    
    nuevo->info.estado = false;
    nuevo->sig = NULL;
    
    if (lista == NULL)
        lista = nuevo;
    else{
        Nodo* aux = lista;
        while (aux->sig != NULL)
            aux = aux->sig; //recorro la lista hasta el ultimo nodo
        aux->sig = nuevo; //linkeo el ultimo nodo con el recien creado
    } // fin else
} //fin agregar

void mostrar(Nodo*lista){
    cout << "Showing" << '\n' << "==============" << endl;
    if (lista == NULL)
        cout << "The list is empty" << endl;
        
    Nodo* aux = lista;
    
    while (aux!=NULL){
        cout << "ID: " << aux->info.id << endl;
        cout << "Title: " << aux->info.titulo << endl;
        cout << "Description: " << endl << aux->info.desc << endl;
        cout << "State: " << aux->info.estado << endl;
        aux = aux->sig;
        cout << "-----------------" << endl;
    }
} //fin mostrar


void eliminar(Nodo*&lista, int &id){
    Nodo* aux = lista;
    Nodo* ant;
    int auxId;
    cout << "Enter the task's ID you wish to delete" << endl;
    cin >> auxId;
    while (aux->info.id != auxId && aux != NULL){
        ant = aux;
        aux = aux->sig;
    }
    
    if (aux == NULL) // pregunto si no se encontro el elemento
        cout << "The ID doesn't exist" << endl;
    else {
        if (lista == aux) // pregunto si el nodo es el primero
            lista = NULL;
        else{ //caso contrario se encontro el elemento y procedo normal
            ant->sig = aux->sig; // conecto las estructuras anterior y siguiente
            
            ant = ant->sig; // avanzo el puntero ant
            while (ant != NULL){ // acomodo los ids para que queden ordenados
                ant->info.id--;
                ant = ant->sig;   
            }
            delete aux;
        }
        id--;
    } // fin else
} // fin eliminar

Nodo* buscar(Nodo*lista, int val){
    Nodo* aux = lista;
    
    while (aux->info.id != val)
        aux = aux->sig;
        return aux;   
} // fin buscar

void modificar(Nodo*&lista){
    Nodo* aux = lista;
    char entrada;
    int val;
    
    cout << "Ingrese el ID de la tarea que quiere modificar" << endl;
    cin >> val;
    while (aux->info.id != val && aux!=NULL)
        aux = aux->sig;
    if (aux == NULL)
        cout << "No se encontro el ID ingresado" << endl;
    else{
        cout << "Para modificar titulo ingrese 'a' | descripcion 'b'" << endl;
        cin >> entrada;
            switch (entrada){
            case 'a':
                cin.getline(aux->info.titulo, 28);
            break;
            
            case 'b':
                cin.getline(aux->info.desc, 256);
            break;
         }
    } //fin else
} //fin modificar
