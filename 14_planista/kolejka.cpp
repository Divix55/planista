/*
 Funkcje struktury Kolejka stworzonej w uproszczeniu, w 
 oparciu o model kolejki znanej z STL, implementacja 
 wlasna w oparciu o liste jednokierunkowa.
 */

#include "kolejka.hpp"

int Kolejka::front(){
    if(glowa!=nullptr)
        return glowa->dana;
    else
        return NULL;
}

int Kolejka::size(){
    ElemKolejki *tmp;
    int licznik=0;
    tmp=glowa;
    while(tmp){
        licznik++;
        tmp=tmp->nowy;
    }
    return licznik;
}

bool Kolejka::empty(){
    if(glowa==nullptr)
        return true;
    else
        return false;
}

void Kolejka::push(int liczba){
    ElemKolejki *nowyElem, *tmp;
    nowyElem = new ElemKolejki;
    nowyElem->dana=liczba;
    nowyElem->nowy=nullptr;
    tmp=glowa;
    if(tmp==nullptr){
        glowa=nowyElem;
    }
    else{
        while(tmp->nowy){
            tmp=tmp->nowy;
        }
        tmp->nowy=nowyElem;
        tmp->nowy->nowy=nullptr;
    }
}

void Kolejka::pop(){
    ElemKolejki *elem;
    if(glowa!=nullptr){
        elem=glowa->nowy;
        delete glowa;
        glowa=elem;
    }
}
