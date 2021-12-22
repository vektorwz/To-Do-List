/**
 * Name: Agustin Silvero Castillo aka vektor
 * App: To-Do List / Lista de quehaceres
 * Date: 16/12/21
 * Purpose: A To-Do list. ATM: You can add tasks and display the lis. Working on deleting, modifying and changing the state (done/in progress)
 * Notas: Usar strings
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

int main(){
    char input;
    int id = 1;
    Nodo* lista = NULL;
    cout << "Welcome" << endl << "The list's functions are the following:" << endl;
    cout << "a: add | e: delete " << endl << "m: modify a task | q: change state" << endl;
    cout << "s: show the list" << endl;
    cout << "Please enter a key with your desired option, then press enter. To quit enter 'x' " << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // limpia el buffer y el \n en el buffer
    
    while (input!='x'){
        switch(input){
            case 'a':
            cout << "Option a" << endl;
            agregar(lista, id); // crashea en el procedimiento
            break;
            
            case 'e':
            cout << "Option e" << endl;
            break;
            
            case 'm':
            cout << "Option m" << endl;
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
    if (lista == NULL)
        cout << "The list is empty" << endl;
    Nodo* aux = lista;
    while (aux!=NULL){
        cout << "ID: " << aux->info.id << endl;
        cout << "Title: " << aux->info.titulo << endl;
        cout << "Description: " << endl << aux->info.desc << endl;
        cout << "State: " << aux->info.estado << endl;
        aux = aux->sig;
    }
} //fin mostrar
