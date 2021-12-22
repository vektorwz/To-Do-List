/**
 * Nombre: Agustin Silvero Castillo aka vektor
 * Programa: To-Do List / Lista de quehaceres
 * Fecha: 16/12/21
 * Proposito: Una lista de cosas para hacer, se pueden agregar, eliminar, modificar, marcar, entre otros, las tareas agregadas.
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
    cout << "Bienvenido" << endl << "Las funciones de la lista son las siguentes:" << endl;
    cout << "a: agregar | e: eliminar " << endl << "m: modificar una tarea | q: cambiar estado" << endl;
    cout << "s: mostrar la lista" << endl;
    cout << "Porfavor elija una y presione enter, para salir ingrese x" << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // limpia el buffer y el \n en el buffer
    
    while (input!='x'){
        switch(input){
            case 'a':
            cout << "Opcion a" << endl;
            agregar(lista, id); // crashea en el procedimiento
            break;
            
            case 'e':
            cout << "Opcion e" << endl;
            break;
            
            case 'm':
            cout << "Opcion m" << endl;
            break;
            
            case 'q':
            cout << "Opcion q" << endl;
            break;
            
            case 's':
            cout << "Opcion show" << endl;
            mostrar(lista);
            break;
        }//fin switch
        cout << "Ingrese otra opcion para continuar" << endl;
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
    cout << "Ingrese un titulo" << endl;
    cin.getline(nuevo->info.titulo, 28);
    cout << "Ingrese una descripcion" << endl;
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
        cout << "La lista esta vacia" << endl;
    Nodo* aux = lista;
    while (aux!=NULL){
        cout << "ID: " << aux->info.id << endl;
        cout << "Titulo: " << aux->info.titulo << endl;
        cout << "Descripcion: " << endl << aux->info.desc << endl;
        cout << "Estado: " << aux->info.estado << endl;
        aux = aux->sig;
    }
} //fin mostrar


