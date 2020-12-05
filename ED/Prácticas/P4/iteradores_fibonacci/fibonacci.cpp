#include <iostream> // cout, cerr
#include <string> // stoi

class SucesionFibonacci {
    const int first, second;

public:
    SucesionFibonacci(int x1, int x2) :first(x1), second(x2) {}

    class iterator { // clase iteradora interna a SucesionFibonacci
        int i1, i2;
        bool is_end; // un iterador que no sea el final nunca llega a serlo
        // constructores privados para que no se puedan construir arbitrariamente
        iterator() :i1(0), i2(0), is_end(true) {}
        iterator(int i1, int i2) :i1(i1), i2(i2), is_end(false) {}
        friend class SucesionFibonacci; // para usar los constructores desde la clase "exterior"

    public:
        iterator& operator++();

        int operator*() {
            return i1;
        }

        bool operator==(iterator other) {
            return (other.is_end && is_end) || other.i1 == i1 && other.i2 == i2;
        }

        bool operator!=(iterator other) {
            return !(*this == other);
        }

        iterator& operator=(iterator other) {
            i1 = other.i1;
            i2 = other.i2;
            is_end = other.is_end;
            return *this;
        }
    };

    // métodos de la clase externa que devuelven objetos de la interna
    iterator begin() {
        return iterator(first, second);
    }

    iterator end() {
        return iterator();
    }
};

SucesionFibonacci::iterator& SucesionFibonacci::iterator::operator++() {
    // calcula el siguiente elemento de la sucesión

    // i1=0 i2=1
    int aux = i2;
    i2 = i1 + i2;
    i1 = aux;
    // i1=1 i2=1
    return *this;
}

int main(int argc, char * argv[]) {
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " <primero> <segundo> <máximo>" << std::endl;
        return -1;
    }

    int first, second, max;
    first  = std::stoi(argv[1]);
    second = std::stoi(argv[2]);
    max    = std::stoi(argv[3]);

    SucesionFibonacci sf(first, second);
    SucesionFibonacci::iterator sucesion = sf.begin();
    // alternativamente:
    // auto sucesion = sf.begin();

    while (*sucesion < max) {
        std::cout << *sucesion << ", ";
        ++sucesion;
    }
}