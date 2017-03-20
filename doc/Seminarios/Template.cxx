
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <class Type>


class Mycomplex{
	private:
		Type a;
		Type b;
	public:
		Mycomplex(Type a1 , Type b1){
			a = a1;
			b = b1;
		}
		Type real() { return a; }
		Type img() { return b; }
		Mycomplex operator+ (Mycomplex & other){
			Mycomplex aux(a + other.real(), b + other.img() );
			return aux;
		}
		Mycomplex operator+ (Type c){
			Mycomplex aux(a + c , b );
			return aux;
		}
		Mycomplex operator* (Mycomplex & other){
			Mycomplex aux((a * other.real() - b * other.img()),(a * other.img() + b * other.real() ));
			return aux;
		}
		Mycomplex operator* (Type c){
			Mycomplex aux(a * c,b* c);
			return aux;
		}
    void print(){
        cout << "(" << a << "," << b << ")" << endl;
    }
};

template <class Type1>

class MyMatrix{

private:
	
    int n;
    vector<Type1> _vec;
	
public:
    MyMatrix(int n1){
        n = n1;
    }
    
    void print(){
        for(int i = 0; i < _vec.size(); ++i){
            cout << _vec[i] << " ";
            if((i+1)%n == 0 and i != 0) cout << endl;
        }
        cout << endl;
    }
    void addElement(Type1 t){
        _vec.push_back(t);
    }
    
    vector<Type1> getVec(){
        return _vec;
    }

    MyMatrix operator+ (Type1 c){
        MyMatrix res(n);
        for (int i = 0; i < _vec.size(); ++i) {
            res.addElement(_vec[i] + c);
        }
        return res;
    }
    MyMatrix operator* (Type1 c){
        MyMatrix res(n);
        for (int i = 0; i < _vec.size(); ++i) {
            res.addElement(_vec[i] * c);
        }
        return res;
    }
    MyMatrix operator+ (MyMatrix & other){
        MyMatrix res(n);
        vector<Type1> aux = other.getVec();
        for (int i = 0; i < _vec.size(); ++i) {
            res.addElement(_vec[i] + aux[i]);
        }
        return res;
    }
    MyMatrix operator* (MyMatrix & other){
        MyMatrix res(n);
        int r = 0;
        int c = 0;
        int x = 0;
        vector<Type1> aux = other.getVec();
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j){
                r = _vec[c] * aux[x] + _vec[c+1] * aux[x+3] + _vec[c+2] * aux[x+6];
                ++x;
                res.addElement(r);
            }
            x = 0;
            c+=3;
        }
        return res;
    }
    
};
	
	
int main(){
    int aux;
    MyMatrix<int> t(3); //matriu A
    t.addElement(2);t.addElement(0);t.addElement(1);
    t.addElement(3);t.addElement(0);t.addElement(0);
    t.addElement(5);t.addElement(1);t.addElement(1);
    
    MyMatrix<int> t1(3);//matriu B
    t1.addElement(1);t1.addElement(0);t1.addElement(1);
    t1.addElement(1);t1.addElement(2);t1.addElement(1);
    t1.addElement(1);t1.addElement(1);t1.addElement(0);
    
    
    int a, b, a1, b1;
    a = 1;
    b = 3;
    a1 = 4;
    b1 = 5;
    
    cout << " 1. Complex + Complex" << endl;
    cout << " 2. Complex * Complex" << endl;
    cout << " 3. Complex + Type" << endl;
    cout << " 4. Complex * Type" << endl;
    cout << " 5. Matrix + Matrix" << endl;
    cout << " 6. Matrix * Matrix" << endl;
    cout << " 7. Matrix + Type" << endl;
    cout << " 8. Matrix * Type" << endl;
    cout << " 0. EXIT" << endl;
    
    while(cin >> aux and aux != 0){
        if(aux == 1){
            cout << "Complex A: ";
            Mycomplex <int> first(a,b);
            first.print();
            cout << "Complex B: ";
            Mycomplex <int> second(a,b);
            second.print();
            cout << "Resultat: ";
            Mycomplex <int> res = first + second;
            res.print();
        }
        if(aux == 2){
            cout << "Complex A: ";
            Mycomplex <int> first(a,b);
            first.print();
            cout << "Complex B: ";
            Mycomplex <int> second(a,b);
            second.print();
            cout << "Resultat: ";
            Mycomplex <int> res = first * second;
            res.print();
        }
        if(aux == 3){
            cout << "Complex A: ";
            Mycomplex <int> first(a,b);
            first.print();
            cout << "Type B: " << a1 << endl;
            cout << "Resultat: ";
            Mycomplex <int> res = first + a1;
            res.print();
        }
        if(aux == 4){
            cout << "Complex A: ";
            Mycomplex <int> first(a,b);
            first.print();
            cout << "Type B: " << a1 << endl;
            cout << "Resultat: ";
            Mycomplex <int> res = first * a1;
            res.print();
        }
        if(aux == 5){
            cout << "Matriu A: " << endl;
            t.print();
            cout << "Matriu B: " << endl;
            t1.print();
            MyMatrix<int> res = t + t1;
            cout << "Resultat: " << endl;
            res.print();
        }
        if(aux == 6){
            cout << "Matriu A: " << endl;
            t.print();
            cout << "Matriu B: " << endl;
            t1.print();
            MyMatrix<int> res = t * t1;
            cout << "Resultat: " << endl;
            res.print();
        }
        if(aux == 7){
            cout << "Matriu A: " << endl;
            t.print();
            cout << "Type B: " << a <<  endl;
            MyMatrix<int> res = t + a;
            cout << "Resultat: " << endl;
            res.print();
        }
        if(aux == 8){
            cout << "Matriu A: " << endl;
            t.print();
            cout << "Type B: " << a <<  endl;
            MyMatrix<int> res = t * b;
            cout << "Resultat: " << endl;
            res.print();
        }

    }
}
