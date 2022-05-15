#ifndef PAREJA_H
#define PAREJA_H

template<class T1, class T2>
class Pareja {
    T1 a;
    T2 b;

public:
    Pareja(T1 x, T2 y);
    const T1& first() const;
    const T2& second() const;
};

// Instanciación implícita: importamos toda la clase
// #include "pareja.cpp"

#endif