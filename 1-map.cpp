#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    map <string, int> estudiantes;
    int Q, nota, type;
    string nombre;
    cin>>Q;
    for(int i=0; i<Q; i++){
        cin>>type;
        
        switch (type) {
            case 1:
                cin>>nombre;
                cin>>nota;
                estudiantes[nombre]+=nota;
                break;      
            case 2: cin >> nombre; estudiantes.erase(nombre); break;
            case 3:
                cin>>nombre;
                cout<<estudiantes[nombre]<<endl;
                break;
            case 4: 
                cout<<"---REGISTRO TOTAL---"<<endl;
                for (auto registro : estudiantes) {
                   cout << registro.first << " => " << registro.second << endl;
                }
                break;
            case 5:
                cout<<"Ingrese el nombre del estudiante: "<<endl;
                cin>>nombre;
                if(estudiantes.find(nombre) == estudiantes.end()){
                   cout << "Estudiante no registrado" << endl;
                } else{
                    cout<<"El estudiante se encuentra ya registrado "<<endl;
                }
                break;
            case 6:
                cout<<"---Alumnos---"<<endl;
                cout<<"Se encuentran registrados "<< estudiantes.size()<<" estudiantes "<<endl;
                break;
            
        }
        
    }   
    return 0;
}
