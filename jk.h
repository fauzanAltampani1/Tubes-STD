#ifndef JK_H_INCLUDED
#define JK_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct Kereta infotypeK;
typedef struct Penumpang infotypeP;
typedef struct ElmKereta *adr_Kereta;
typedef struct ElmPenumpang *adr_Penumpang;

struct Kereta{
    string jenisKereta;
    string asal;
    string tujuan;
    string tanggal;

};


struct ElmKereta{
    infotypeK info;
    adr_Kereta next;
};

struct ListKereta{
    adr_Kereta first;
};


struct Penumpang{
    string nama;
    string NIK;
    int usia;
    string JenisKelamin;

};



struct ElmPenumpang{
    infotypeP info;
    adr_Penumpang next;

};



struct ListPenumpang{
    adr_Penumpang first;
};


//kereta
void createList_K(ListKereta &LK);

adr_Kereta alokasiK(infotypeK info);
void menu();

void insertFirst_K(ListKereta &LK,adr_Kereta P);
void insertLast_K(ListKereta &LK,adr_Kereta P);
void insertAfter_K(ListKereta &LK,adr_Kereta P);
void printInfo_K(ListKereta LK);
adr_Kereta findElement_K(ListKereta &LK, infotypeK x);
adr_Kereta findElementKbyJenis(ListKereta &LK, infotypeK x);
void deleteAfterK(ListKereta &LK,string jenisKereta);
//penumpang
void createList_P(ListPenumpang &LP);

adr_Penumpang alokasiP(infotypeP info);

void insertFirst_P(ListPenumpang &LP,adr_Penumpang P);
void insertLast_P(ListPenumpang &LP,adr_Penumpang P);
void insertAfter_P(ListPenumpang &LP,adr_Penumpang P);
void printInfo_P(ListKereta LP);
adr_Penumpang findElement_P(ListPenumpang &LP, infotypeP x);
adr_Penumpang findElementPbyNIK(ListPenumpang &LP, infotypeP x);
void deleteAfterP(ListPenumpang &LP,string NIK);
bool operator==(const infotypeK& lhs, const infotypeK& rhs);
bool operator==(const infotypeP& lhs, const infotypeP& rhs);

#endif // JK_H_INCLUDED
