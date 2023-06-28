#include<functional>
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T element;
	Node* left;
	Node* equ;
	Node* right;
};

template<class T>
class TreeTB {
	typedef function<int(T, T)> Comp;
	Node<T>* root;
	void(*procesar)(T);
	Comp compare;
private:
	bool _insert(Node<T>*& node, T e) {
		if (node == nullptr) {
			node = new Node<T>();
			node->element = e;
			return true;
		}
		else
		{
			int n = compare(node->element, e);
			if (n < 0) return _insert(node->right, e);
			else if (n == 0) return _insert(node->equ, e);
			else return _insert(node->left, e);
		}
	}

	void _preOrden(Node<T>* node) {
		if (node == nullptr) return;
		procesar(node->element);
		_preOrden(node->left);
		_preOrden(node->equ);
		_preOrden(node->right);
	}

	int _quantity(Node<T>* node) {
		if (node == nullptr) return 0;
		else {
			int ql, qr, qe;
			ql = _quantity(node->left);
			qr = _quantity(node->right);
			qe = _quantity(node->equ);
			return ql + qr + qe + 1;
		}
	}

	bool _search(Node<T>* node, T e) {
		if (node == nullptr) return 0;
		else if (node->element == e)return 1;
		else {
			int n = compare(node->element, e);
			if (n < 0) return _search(node->right, e);
			else if (n == 0) return _search(node->equ, e);
			else return _search(node->left, e);
		}
	}


public:
	TreeTB(void(*value)(T)) {
		this->procesar = value;
		this->compare = [](T a, T b)->int {return int(a[0]) - int(b[0]); };
		root = nullptr;
	}

	bool insert(T e) {
		return _insert(root, e);
	}
	void preOrden() {
		_preOrden(root);
	}
	int quantity() {
		return _quantity(root);
	}
	bool search(T e) {
		return _search(root, e);
	}
};


void print(string e)
{
	cout << " " << e;
}

int main() {
	TreeTB<string>* tree = new TreeTB<string>(print);
	int opci;
	string name;
	cout << "==================Menu================" << endl;
	cout << "\n1. Agregar a estudiante" << endl;
	cout << "2. Buscar a estudiante matriculado" << endl;
	cout << "3. Vizualizar todos los estudiantes matriculados" << endl;
	cout << "4. Salir" << endl;
	
	do {
		cout << "Elija una opcion: "; cin >> opci;
		cout << endl;
		switch (opci)
		{
		case 1:cout << "Digite el nombre del estudiante a matricular: "; cin >> name;

			if (tree->insert(name)) {
				cout << "El estudiante " << name << " fue matriculado exitosamente" << endl;
			}
			cin.ignore();
			break;
		case 2: cout << "Escriba el nombre del estudiante a buscar: "; cin >> name;
			if (tree->search(name)) {
				cout << "El estudiante " << name << " pertenece a esta escuela" << endl;
			}
			cin.ignore();
			break;
		case 3: cout << "Estos son los estudiantes matriculados" << endl;
			tree->preOrden();
			break;
		case 4: break;
		default:
			break;
		}
		cout << endl;
	} while (opci != 4);
	

	cin.get();
	cin.ignore();
	return 0;
}
