/*
 Planista, zadanie 14
 w programie wykorzystuje liste dwukierunkowa oraz kolejke,
 kolejka ma za zadnie przetrzymywac listy zadan poszczegolnych
 procesow. Lista dwukierunkowa przetrzymuje procesy i zarzadza
 ich przydzielaniem.
 */

#include "kolejka.hpp"

using namespace std;

struct Element{
    Element *nastepny;
    Element *poprzedni;
    int priorytet;
    int id;
    Element(){
        priorytet = 2;
        id = 0;
        nastepny = nullptr;
        poprzedni = nullptr;
    };
};

struct Lista{
    Element *glowa;
    Element *ogon;
    
    void przydzielCzas(Kolejka *, Kolejka *, Kolejka *);
    void utworzProces(int, int);
    void zakonczProces(int);
    void listaZadan(Kolejka *);
    Lista(){
        glowa = nullptr;
        ogon = nullptr;
    };
};

void wypiszZadania(Element *tmp, int);
void usunZKolejki(Kolejka *, int);

int main(int argc, const char * argv[]) {
    
    Lista *nowaLista=new Lista;
    char polecenie;
    int id, priorytet;
    
    Kolejka nkolejkaH, nkolejkaM, nkolejkaL;
    
    while(cin>>polecenie){
        if(polecenie=='n'){
            if(nkolejkaH.empty() && nkolejkaM.empty() && nkolejkaL.empty())
                cout<<"idle"<<endl;
            else
                nowaLista->przydzielCzas(&nkolejkaH, &nkolejkaM, &nkolejkaL);
        }
        if(polecenie=='c'){
            cin>>id>>priorytet;
            nowaLista->utworzProces(id, priorytet);
            if(priorytet==1) nkolejkaH.push(nowaLista->ogon->id);
            if(priorytet==0) nkolejkaM.push(nowaLista->ogon->id);
            if(priorytet==-1) nkolejkaL.push(nowaLista->ogon->id);
            
        }
        if(polecenie=='t'){
            cin>>id;
            nowaLista->zakonczProces(id);
            if(!nkolejkaH.empty()) usunZKolejki(&nkolejkaH, id);
            if(!nkolejkaM.empty()) usunZKolejki(&nkolejkaM, id);
            if(!nkolejkaL.empty()) usunZKolejki(&nkolejkaL, id);
        }
        if(polecenie=='p'){
            cin>>id>>priorytet;
            nowaLista->zakonczProces(id);
            if(!nkolejkaH.empty()) usunZKolejki(&nkolejkaH, id);
            if(!nkolejkaM.empty()) usunZKolejki(&nkolejkaM, id);
            if(!nkolejkaL.empty()) usunZKolejki(&nkolejkaL, id);
            nowaLista->utworzProces(id, priorytet);
            if(priorytet==1) nkolejkaH.push(nowaLista->ogon->id);
            if(priorytet==0) nkolejkaM.push(nowaLista->ogon->id);
            if(priorytet==-1) nkolejkaL.push(nowaLista->ogon->id);
        }
        if(polecenie=='l'){
            cout<<"1: ";
            nowaLista->listaZadan(&nkolejkaH);
            cout<<"0: ";
            nowaLista->listaZadan(&nkolejkaM);
            cout<<"-1: ";
            nowaLista->listaZadan(&nkolejkaL);
        }
    }
    return 0;
}

void Lista::utworzProces(int nowyId, int nowyPriorytet){
    Element *nowa = new Element;
    
    nowa->id=nowyId;
    nowa->priorytet=nowyPriorytet;
    if(glowa==nullptr){
        glowa=nowa;
        ogon=nowa;
        nowa->poprzedni=nullptr;
    }
    else{
        nowa->nastepny=ogon;
        nowa->poprzedni=nullptr;
        ogon=nowa;
        if(nowa->nastepny!=0){
            nowa->nastepny->poprzedni=nowa;
        }
    }
}

void Lista::listaZadan(Kolejka *kolejka){
    if(!kolejka->empty()){
        int poczatek=kolejka->front(), tmp;
        do{
            cout<<kolejka->front()<<" ";
            tmp=kolejka->front();
            kolejka->pop();
            kolejka->push(tmp);
        }while(kolejka->front()!=poczatek);
    }
    cout<<endl;
}

void usunZKolejki(Kolejka *kolejka, int id){
    long iloscElementow=kolejka->size();
    Kolejka kolejkaPom;
    
    for(int i=0; i<iloscElementow; i++){
        if(kolejka->front()!=id){
            kolejkaPom.push(kolejka->front());
            kolejka->pop();
        }
        else kolejka->pop();
    }
    *kolejka=kolejkaPom;
}

void Lista::przydzielCzas(Kolejka *kolejkaH, Kolejka *kolejkaM, Kolejka *kolejkaL){
    int tmp;
    if(glowa==nullptr){
        cout<<"idle"<<endl;
    }
    else{
        if(kolejkaH->empty()){
            if(kolejkaM->empty()){
                cout<<kolejkaL->front()<<endl;
                tmp=kolejkaL->front();
                kolejkaL->pop();
                kolejkaL->push(tmp);
            }
            else{
                cout<<kolejkaM->front()<<endl;
                tmp=kolejkaM->front();
                kolejkaM->pop();
                kolejkaM->push(tmp);
            }
        }
        else{
            cout<<kolejkaH->front()<<endl;
            tmp=kolejkaH->front();
            kolejkaH->pop();
            kolejkaH->push(tmp);
        }
    }
}

void Lista::zakonczProces(int usunId){
    Element *tmp = ogon;
    while(tmp){
        if(tmp->id==usunId){
            if(tmp->poprzedni){
                tmp->poprzedni->nastepny=tmp->nastepny;
            }
            else
                ogon=tmp->nastepny;
            if(tmp->nastepny){
                tmp->nastepny->poprzedni=tmp->poprzedni;
            }
            else
                glowa=tmp->poprzedni;
        }
        tmp=tmp->nastepny;
    }
}
