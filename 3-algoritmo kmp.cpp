#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
typedef vector<int> vectI;

void getLPSArray(const string& pat, vectI& lps) {
    int M = pat.length();
    int len = 0;
    int i = 1;
    lps[0] = 0; // lps[0] siempre es 0
    // el bucle calcula lps[i] para i=1 a M-1
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string& pat, string& txt) {
    int M = pat.length();
    int n = txt.length();
    vectI lps(M);
    int count = 0; // contador de ocurrencias del patrón
    getLPSArray(pat, lps);

    int j = 0; // índice para pat[]
    for (int k = 0; k < n; k++) {
        if (pat[j] == txt[k]) {
            j++;
        }
        else if (j > 0) {
            j = lps[j - 1];
            k--;
        }

        if (j == M) {
            count++;
            // Eliminar dígitos del patrón del texto
            int start = k - M + 1;
            int end = k;
            txt.erase(start, end - start + 1);
            cout << "Después de borrar en txt: " << txt << endl;
            //k = start + lps[M - 1] - 1;
            k = 0;
            n = n - (end - start + 1);
            j = 0;
        }
    }

    // Mostrar el texto modificado
    cout << "Texto: " << txt << endl;
    if (count == 0) {
        cout << "No se encontró el patrón." << endl;
    }
    if (count > 3) {
        cout << "El patrón es muy frecuente en el texto." << endl;
    }
}

int main() {
    string text;
    string pattern;
    int t; // Número entero que indica el número de casos de prueba
    cout << "Ingrese t: ";
    do {
        cin >> t;
    } while (t < 1 || t > 10000);
    cout << "\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia el búfer de entrada

    int i = 1;
    while (i <= t) {
        text.clear();
        pattern.clear();
        cout << "CASO DE PRUEBA " << i << "\n\n";
        cout << "Ingresa el texto   :  ";
        getline(cin, text);
        cout << "Ingresa el patrón  :  ";
        getline(cin, pattern);
        cout << "Texto: " << text << endl;
        KMPSearch(pattern, text);
        i++;
    }
    return 0;
}
