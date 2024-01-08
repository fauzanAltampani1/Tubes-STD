#include "jk.h"
#include <iostream>


void createList_K(ListKereta &LK){
    LK.first = NULL;
}


adr_Kereta alokasiK(infotypeK info){
    adr_Kereta p = new ElmKereta;
    p->info = info;
    p->next = NULL;
    return p;
}

void insertFirst_K(ListKereta &LK,adr_Kereta P){
    P->next = LK.first;
    LK.first = P;

}
void insertLast_K(ListKereta &LK,adr_Kereta P){
    adr_Kereta track;

    if (LK.first == NULL) {
        LK.first = P;
    } else {
        track = LK.first;
        while (track->next != NULL) {
            track = track->next;
        }
        track->next = P;
    }

}
void insertAfter_K(ListKereta &LK,adr_Kereta P){
    adr_Kereta Q;

    Q = LK.first;
    if (LK.first== NULL){
        LK.first = P;
    }else{
        while(Q->next != NULL){
             Q = Q->next;

        }
        Q->next = P;

    }
}

void printInfo_K(ListKereta LK){
    adr_Kereta P = LK.first;
    cout << "List Kereta" << endl;
    while(P!= NULL){
        cout << "Jenis Kereta: " << P->info.jenisKereta << ", Asal: " << P->info.asal << ", Tujuan: " << P->info.tujuan << ", Tanggal: " << P->info.tanggal << endl;
        P = P->next;
    }
}


adr_Kereta findElement_K(ListKereta &LK, infotypeK x){
    adr_Kereta P = LK.first;
    while(P!= NULL){
        if(P->info == x){
            return P;
        }
        P = P->next;
    }
    return NULL;  // Mengembalikan NULL jika tidak ditemukan
}

adr_Kereta findElementKbyJenis(ListKereta &LK, infotypeK x){
    adr_Kereta P = LK.first;
    while(P!= NULL){
        if(P->info.jenisKereta == x.jenisKereta){
            return P;
        }
        P = P->next;
    }
    return NULL;  // Mengembalikan NULL jika tidak ditemukan
}


void deleteAfterK(ListKereta &LK, string jenisKereta){
    if (LK.first == NULL) {
        cout << "Tidak ada data." << endl;
        return;
    }

    adr_Kereta P = LK.first;
    adr_Kereta prec = NULL;

    while (P != NULL && P->info.jenisKereta != jenisKereta) {
        prec = P;
        P = P->next;
    }

    if (P == NULL) {
        cout << "Tidak ada data dengan jenis kereta " << jenisKereta << "." << endl;
        return;
    }

    if (prec == NULL) {
        LK.first = P->next;
        delete P;
    } else {
        if (P->next == NULL) {
            prec->next = NULL;
            delete P;
        } else {
            prec->next = P->next;
            delete P;
        }
    }
}

bool operator==(const infotypeK& lhs, const infotypeK& rhs) {
    return (lhs.jenisKereta == rhs.jenisKereta) && (lhs.asal == rhs.asal) && (lhs.tujuan == rhs.tujuan) && (lhs.tanggal == rhs.tanggal);
}
