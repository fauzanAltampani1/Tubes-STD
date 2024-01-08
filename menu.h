#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "jk.h"
#include "relasi.h"
#include <iostream>
using namespace std;

void menu();
//case1
void TambahDataKereta(ListKereta &LK);

//case2
void TampiLKanKeretaTersedia(ListKereta &LK);

//case3
void hapusDataKereta(List_R &LR, ListKereta &LK,infotypeK x);

//case4
void cariParent(ListKereta &LK);

//case5
void cariChild(ListPenumpang &LP);

//case6
void TambahDataPenumpang(ListPenumpang &LP);

//case7
void TambahkanPenumpangKeKereta(List_R &LR, ListKereta &LK, ListPenumpang &LP);

//case8

//case9
void CariDataPenumpangpadaKereta(List_R &LR, ListKereta &LK, ListPenumpang &LP);

//case10
void HapusDataPenumpangpadaKereta(List_R &LR, ListKereta &LK, ListPenumpang &LP);

//case11
int hitungJumlahPenumpang(List_R LR, infotypeK px,infotypeP kx);
void HitungDataPenumpangpadaKereta(List_R &LR, ListKereta &LK);



#endif // MENU_H_INCLUDED
