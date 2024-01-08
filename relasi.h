#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "jk.h"
#include <iostream>

using namespace std;

typedef struct ElmRelasi   *adr_Relasi;
struct ElmRelasi{
    adr_Kereta parent;
    adr_Penumpang child;
    adr_Relasi next;
    adr_Relasi prev;
};

struct List_R{
    adr_Relasi first;
};
//relasi
void createList_R(List_R &L);
adr_Relasi alokasi(adr_Kereta P, adr_Penumpang C);
void insertFirst_R(List_R &L,adr_Relasi P);
void deleteElement(List_R &L, adr_Relasi &P);

adr_Relasi findElement(List_R L, infotypeK px,infotypeP cx);

void connect(List_R &L,ListKereta LK,ListPenumpang LP,infotypeK px,infotypeP cx);
void disconnect(List_R &L,infotypeK px,infotypeP cx);

void printRelasi(List_R LR, ListKereta LK);

#endif // RELASI_H_INCLUDED
