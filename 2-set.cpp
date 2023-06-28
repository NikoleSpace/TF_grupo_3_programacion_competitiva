#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    set<string> lista;   
    set<string>::iterator it;
    set<string> lista2;
    set<string> inter;
    set<string> listasunidas;
    int n,n2,opt,opt2;
    string nombre;
    cout<<"Ingrese la cantidad de consultas: "<<endl;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>opt;
        switch (opt) {
            case 1: cin>>nombre; lista.insert(nombre); break;
            case 2: cin>>nombre; lista.erase(nombre); break;
            case 3: 
                cin>>nombre; 
                it=lista.find(nombre);
                if (it == lista.end()) {
                cout << "No se encuentra en la lista" << endl;
                }
                else if (*it == nombre) {
                cout << "Se encuentra en la lista" << endl;
                }
                break;
            case 4:
                cout<<"---TOTAL---"<<endl;
                cout<<"Se encuentran en lista " <<lista.size()<<" personas "<<endl;
                break;
            case 5:
                cout<<"---LISTA---"<<endl;
                for (const auto& nombre : lista) {
                    cout << nombre << endl;
                }
                break;
        }
    }

    cout<<"Ingrese la cantidad de consultas: "<<endl;
    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>opt2;
        switch(opt2){
            case 1: cin>>nombre; lista2.insert(nombre); break;
            case 2: cin>>nombre; lista2.erase(nombre); break;
            case 3: 
                cin>>nombre; 
                it=lista2.find(nombre);
                if (it == lista2.end()) {
                    cout << "No se encuentra en la lista" << endl;
                }
                else if (*it == nombre) {
                    cout << "Se encuentra en la lista" << endl;
                }
                break;
            case 4:
                cout<<"---TOTAL---"<<endl;
                cout<<"Se encuentran en lista " <<lista2.size()<<" personas "<<endl;
                break;
            case 5:
                cout<<"---LISTA---"<<endl;
                for (const auto& nombre : lista2) {
                    cout << nombre << endl;
                }
                break;
        }
    }
    
     //funcion para union de dos set
    set_union(lista.begin(), lista.end(),lista2.begin(), lista2.end(), inserter(listasunidas, listasunidas.begin()));
    cout<<"---LISTA COMPLETA---"<<endl;
    for (const auto& nombre : listasunidas) {
        cout << nombre << endl;
    }
    cout<<"\n\n";
    //funcion para interseccion de dos set
    set_intersection(lista.begin(), lista.end(),lista2.begin(), lista2.end(), inserter(inter, inter.begin()));
    cout<<"---LISTA EN COMUN---"<<endl;
    for (const auto& nombre : inter) {
        cout << nombre << endl;
    }
    
    return 0;
}
