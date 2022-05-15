// En la instanciación implícita hay que quitar este include:
#include "pareja.h"

template<class T1, class T2> 
Pareja<T1, T2>::Pareja(T1 x, T2 y) {
    a = x;
    b = y;
}

template<class T1, class T2> 
const T1& Pareja<T1, T2>::first() const {
    return a;
}

template<class T1, class T2> 
const T2& Pareja<T1, T2>::second() const {
    return b;
}

// Instanciación explícita: declaramos las clases que necesitamos:
// template class Pareja<int, char>;
// template class Pareja<float, unsigned>;