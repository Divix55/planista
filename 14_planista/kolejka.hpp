/*
 Struktury kolejki opisanej w pliku kolejka.cpp.
 */

#ifndef kolejka_hpp
#define kolejka_hpp

#include <stdio.h>
#include <iostream>

struct ElemKolejki{
    int dana;
    ElemKolejki *nowy;
    
    ElemKolejki(){
        dana = 0;
        nowy = nullptr;
    }
};

struct Kolejka{
    ElemKolejki *glowa;
    
    int front();
    int size();
    bool empty();
    void push(int);
    void pop();
    Kolejka(){
        glowa = nullptr;
    }
};

#endif /* kolejka_hpp */
