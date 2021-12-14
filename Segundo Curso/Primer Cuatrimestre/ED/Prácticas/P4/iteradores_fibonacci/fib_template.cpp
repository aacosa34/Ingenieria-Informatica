#include <iostream> // cout, cerr
#include <string> // stof

template<class T>
class SucesionFibonacci {
    const T first, second;

public:
    SucesionFibonacci(T x1, T x2) :first(x1), second(x2) {}

    class iterator { // clase iteradora interna a SucesionFibonacci
        T i1, i2;
        bool is_end; // un iterador que no sea el final nunca llega a serlo
        // constructores privados para que no se puedan construir arbitrariamente
        iterator() :i1(0), i2(0), is_end(true) {}
        iterator(T i1, T i2) :i1(i1), i2(i2), is_end(false) {}
        friend class SucesionFibonacci; // para usar los constructores desde la clase "exterior"

    public:
        iterator& operator++();

        T operator*() {
            return i1;
        }

        bool operator==(iterator other) {
            return other.i1 == i1 && other.i2 == i2;
        }

        bool operator!=(iterator other) {
            return !(*this == other);
        }

        iterator& operator=(iterator other) {
            i1 = other.i1;
            i2 = other.i2;
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

// Un método de una template hay que precederlo con la misma notación
template<typename T>
// Si se devuelve un objeto de tipo dependiente de una template, se indica "typename"
typename SucesionFibonacci<T>::iterator& SucesionFibonacci<T>::iterator::operator++() {
    // calcula el siguiente elemento de la sucesión
    T aux = i2;
    i2 = i1 + i2;
    i1 = aux;
    return *this;
}

int main(int argc, char * argv[]) {
    if (argc < 4) {
        std::cerr << "Uso: " << argv[0] << " <primero> <segundo> <máximo>" << std::endl;
        return -1;
    }

    float first, second, max;
    first  = std::stof(argv[1]);
    second = std::stof(argv[2]);
    max    = std::stof(argv[3]);

    SucesionFibonacci<float> sf(first, second);
    SucesionFibonacci<float>::iterator sucesion = sf.begin();
    // alternativamente:
    // auto sucesion = sf.begin();

    while (*sucesion < max) {
        std::cout << *sucesion << ", ";
        ++sucesion;
    }
}