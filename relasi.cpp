#include "jk.h"
#include "relasi.h"
#include <iostream>


void createList_R(List_R &L){
    L.first = NULL;
}

adr_Relasi alokasi(adr_Kereta P, adr_Penumpang C){
    adr_Relasi R = new ElmRelasi;
    R->parent = P;
    R->child = C;
    R->next = NULL;
    R->prev = NULL;
    return R;
}

void insertFirst_R(List_R &L, adr_Relasi P){
    if (L.first == NULL){
        L.first = P;
        P->next = P;
        P->prev = P;
    }else{
        P->next = L.first;
        P->prev = L.first->prev;
        P->prev->next = P;
        L.first->prev = P;
        L.first = P;
    }
}

void deleteElement(List_R &L, adr_Relasi &P){
    if(P->next == P){
        L.first = NULL;
    }else{
        if(L.first == P){
            L.first = P->next;
        }
        P->prev->next = P->next;
        P->next->prev = P->prev;
    }
    P->prev = NULL;
    P->next = NULL;
}

adr_Relasi findElement(List_R L, infotypeK px, infotypeP cx){
    adr_Relasi R = L.first;
    if (R != NULL){
        do{
            if((R->parent->info == px) && (R->child->info == cx)){
                return R;
            }
            R = R->next;
        } while(R != L.first);
    }
    return NULL;
}





void connect(List_R &L,ListKereta LK,ListPenumpang LP,infotypeK px,infotypeP cx){
    adr_Kereta P = findElementKbyJenis(LK, px);
    adr_Penumpang C = findElementPbyNIK(LP,cx);
        if (P!=NULL && C != NULL){
	        adr_Relasi R=alokasi(P,C);
	        insertFirst_R(L,R);
    }
}


void disconnect(List_R &L,infotypeK px,infotypeP cx){
    adr_Relasi R= findElement(L,px,cx);
    if(R != NULL){
		deleteElement(L,R);
	}
	delete R;


}

void printRelasi(List_R LR, ListKereta LK){
    adr_Kereta p = LK.first;
    cout<<"List Kereta dan Penumpang"<<endl;
    while(p!=NULL){
        cout << "Kereta: " <<endl;
        cout << p->info.jenisKereta << endl;
        cout << p->info.asal << endl;
        cout << p->info.tujuan << endl;
        cout << p->info.tanggal << endl;
        cout << "Penumpang: "<<endl;

        adr_Relasi R = LR.first;
        if(R!=NULL){
            do{
                if(R->parent == p){
                    cout<<"     Nama: "<< R->child->info.nama<<endl;
                    cout<<"     NIK: "<< R->child->info.NIK<<endl;
                    cout<<"     Usia: "<< R->child->info.usia<<endl;
                    cout<<"     Jenis Kelamin: "<< R->child->info.JenisKelamin<<endl;
                    cout<<endl;
                }
                R = R->next;
            }while(R!=LR.first);
        }
        cout<<endl;
        p = p->next;
    }
    cout<<endl;

}
