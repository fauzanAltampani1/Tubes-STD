#include "jk.h"
#include <iostream>


void createList_P(ListPenumpang &LP){
    LP.first = NULL;
}
adr_Penumpang alokasiP(infotypeP info){
    adr_Penumpang p = new ElmPenumpang;
    p->info = info;
    p->next = NULL;
    return p;
}

void insertFirst_P(ListPenumpang &LP,adr_Penumpang P){
    P->next = LP.first;
    LP.first = P;
}

void insertLast_P(ListPenumpang &LP,adr_Penumpang P){
   adr_Penumpang track;

    if (LP.first == NULL) {
        LP.first = P;
    } else {
        track = LP.first;
        while (track->next != NULL) {
            track = track->next;
        }
        track->next = P;
    }

}
void insertAfter_P(ListPenumpang &LP,adr_Penumpang P){
  adr_Penumpang Q;

    Q = LP.first;
    if (LP.first== NULL){
        LP.first = P;
    }else{
        while(Q->next != NULL){
             Q = Q->next;

        }
   Q->next = P;

    }

}

void printInfo_P(ListPenumpang LP){
    adr_Penumpang P = LP.first;
    cout << "List Penumpang" << endl;
    while(P!= NULL){
        cout << "Nama: " << P->info.nama << ", NIK: " << P->info.NIK << ", Usia: " << P->info.usia << ", Jenis Kelamin: " << P->info.JenisKelamin << endl;
        P = P->next;
    }
}

adr_Penumpang findElement_P(ListPenumpang &LP, infotypeP x){
    adr_Penumpang P = LP.first;
    while(P!= NULL){
        if(P->info == x){
            return P;
        }
        P = P->next;
    }
    return NULL;  // Mengembalikan NULL jika tidak ditemukan
}

adr_Penumpang findElementPbyNIK(ListPenumpang &LP, infotypeP x){
    adr_Penumpang P = LP.first;
    while(P!= NULL){
        if(P->info.NIK == x.NIK){
            return P;
        }
        P = P->next;
    }
    return NULL;  // Mengembalikan NULL jika tidak ditemukan
}


void deleteAfterP(ListPenumpang &LP,string NIK){
  if (LP.first == NULL) {
        cout << "Tidak ada data." << endl;
        return;
    }

    adr_Penumpang P = LP.first;
    adr_Penumpang prec = NULL;

    // Mencari elemen dengan NIK yang sesuai
    while (P != NULL && P->info.NIK != NIK) {
        prec = P;
        P = P->next;
    }

    if (P == NULL) {
        cout << "Tidak ada data dengan NIK " << NIK << "." << endl;
        return;
    }

    // Kondisi 1: Menghapus first element
    if (prec == NULL) {
        LP.first = P->next;
        delete P;
    } else {
        // Kondisi 2: Menghapus elemen setelah first
        if (P->next == NULL) {
            prec->next = NULL;
            delete P;
        } else {
            // Kondisi 3: Menghapus elemen di tengah
            prec->next = P->next;
            delete P;
        }
    }

}
bool operator==(const infotypeP& lhs, const infotypeP& rhs) {
    return (lhs.nama == rhs.nama) && (lhs.NIK == rhs.NIK) && (lhs.usia == rhs.usia) && (lhs.JenisKelamin == rhs.JenisKelamin);
}
