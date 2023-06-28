#include<vector>
#include<string>
#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
const int MAX = 1e5;

struct Node {
    int v;
    Node() {}
    Node(int v) : v(v) {}
};

Node ope(Node A, Node B) {
    if (A.v < B.v) return A;
    return B;
}

struct SegmentTree {
    Node t[2 * MAX]; int n;

    void build() {
        for (int i = n - 1; i > 0; i--)
            t[i] = ope(t[i << 1], t[i << 1 | 1]);
    }

    void modify(int p, Node val) {
        for (t[p += n] = val; p >>= 1; )
            t[p] = ope(t[p << 1], t[p << 1 | 1]);
    }
    
};

SegmentTree ST;

int main() {

    int n;

    do {
        cout << "\nIngresar N notas: ";
        cin >> n;
    } while (n < 0 || n>50);

    ST.n = n;
    int numalea;
    srand(time(NULL));

    for (int i = 0; i < n; i++) {

        cout << "\nElemento " << i << ": ";
        numalea = 1 + rand() % (20 - 1);
        cout << numalea;
        ST.t[n + i].v = numalea;
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++) {
        cout << ST.t[n + i].v << " ";
    }

    ST.build();
    cout << "\n";
    int Q, q, l, r, i, v,sum;
    float prom;
    char opc;
    do {
        cout << "\nIngrese numero de consultas: ";
        cin >> Q;
    } while (Q < 1 || Q>200);

    for (int i = 0; i < Q; i++) {

        cout << "Ingrese su opcion(a,b, c o d): "; cin >> opc;

        switch (opc) {
        case 'a':
            do {
                cout << "\nIngresar indice l: ";
                cin >> l;
                cout << "\nIngresar índice r: ";
                cin >> r;
            } while (l<1 || l>r || r > n);
            
            for (int i = l; i <= r; i++) {
                cout << ST.t[r+i].v << " ";
            }
            cout<<endl;
            break;

        case 'b':
            do {
                cout << "\nIngresar indice i: ";
                cin >> i;
                cout << "\nIngresar nuevo valor v: ";
                cin >> v;

            } while (i<1 || i>n || v < 1 || v>30);
            ST.modify(i, v);
            for (int i = 0; i < n; i++) {
                cout << ST.t[n + i].v << " ";
            }
            break;
        case 'c':
            cout<<"SUMA NOTAS: ";
            for (int i = 0; i < n; i++) {
                 sum+=ST.t[n + i].v;
            }
            cout<<sum<<endl;
            break;
        case 'd':
            cout<<"PROMEDIO NOTAS: ";
            for (int i = 0; i < n; i++) {
                 sum+=ST.t[n + i].v;
            }
            prom=sum/n;
            cout<<prom<<endl;

        cout << "\n";
            
        }
    }
    return 0;
}
