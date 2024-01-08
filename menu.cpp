#include "jk.h"
#include "relasi.h"
#include "menu.h"
#include <iostream>



void menu(){
    int x;
    char repeat;
    infotypeK Z;
    ListKereta LK;
    ListPenumpang LP;
    List_R lr;
    createList_K(LK);
    createList_P(LP);
    createList_R(lr);
    do{
        cout<<"============ MENU JADWAL KERETA ============"<<endl;
        cout<<"1. Tambah Data Kereta  "<<endl;
        cout<<"2. TampiLKan Data Kereta "<<endl;
        cout<<"3. Hapus Data Kereta "<<endl;
        cout<<"4. Cari Data Kereta Yang ada "<<endl;
        cout<<"5. Cari Data Penumpang Yang ada"<<endl;
        cout<<"6. Tambah Data Penumpang  "<<endl;
        cout<<"7. Tambah Penumpang pada kereta "<<endl;
        cout<<"8. TampiLKan data kereta beserta penumpangnya  "<<endl;
        cout<<"9. Cari Data Penumpang pada Kereta  "<<endl;
        cout<<"10. Hapus data penumpang pada kereta  "<<endl;
        cout<<"11. Hitung Jumlah penumpang pada kereta  "<<endl;
        cout <<endl;

        cout<<"Pilihan anda: ";
        cin>> x;

        switch (x)
        {
        case 1:
            TambahDataKereta(LK);
            break;
        case 2:
            TampiLKanKeretaTersedia(LK);
            break;
        case 3:
            hapusDataKereta(lr,LK,Z);
            break;
        case 4:
            cariParent(LK);
            break;
        case 5:
            cariChild(LP);
            break;
        case 6:
            TambahDataPenumpang(LP);
            break;
        case 7:
            TambahkanPenumpangKeKereta(lr,LK,LP);
            break;
        case 8:
            printRelasi(lr, LK);

            break;
        case 9:
            CariDataPenumpangpadaKereta(lr,LK,LP);
            break;
        case 10:
            HapusDataPenumpangpadaKereta(lr,LK,LP);
            break;
        case 11:
            HitungDataPenumpangpadaKereta(lr,LK);
            break;
        default:
            cout<< "Menu tidak tersedia"<< endl;
        }
        cout<< endl;

        cout<< "Kembali ke menu utama (y/n)?";
        cin >>repeat;
        cout<<endl;
    }while(repeat != 'n');

    cout << "Terimakasih !"<< endl;

}

//case 1
void TambahDataKereta(ListKereta &LK){
    infotypeK K;
    adr_Kereta JadwaLKereta;




    cout <<"Masukkan Nama Jenis Kereta: ";
    cin >> K.jenisKereta;
    cout <<"Masukkan Asal Kereta: ";
    cin >> K.asal;
    cout <<"Masukkan Tujuan Kereta: ";
    cin >> K.tujuan;
    cout <<"Masukkan Tanggal Keberangkatan Kereta: ";
    cin >> K.tanggal;
    cout <<endl<<endl;

    JadwaLKereta = alokasiK(K);

    int menu;
    cout << "Pilih Menu: " << endl;
    cout << "1. Tambah Jadwal Keberangkatan Kereta Awal" << endl;
    cout << "2. Tambah Jadwal Keberangkatan Kereta Akhir" << endl;
    cout << "Pilih: ";
    cin >> menu;

    switch (menu) {
        case 1:
            insertFirst_K(LK, JadwaLKereta);
            cout << "Data Kereta berhasil ditambahkan di awal." << endl;
            break;
        case 2:
            insertLast_K(LK, JadwaLKereta);
            cout << "Data Kereta berhasil ditambahkan di akhir." << endl;
            break;
        default:
            cout << "Menu tidak valid." << endl;
    }
}

//case 2
void TampiLKanKeretaTersedia(ListKereta &LK){
    printInfo_K(LK);

}

//case 3
void hapusDataKereta(List_R &L, ListKereta &LK, infotypeK x) {
    string jenisKereta;
    cout << "Masukkan Jenis Kereta yang ingin dihapus: ";
    cin >> jenisKereta;

    x.jenisKereta = jenisKereta;
    adr_Kereta P = findElementKbyJenis(LK, x);

    if (P == NULL) {
        cout << "Kereta dengan jenis " << x.jenisKereta << " tidak ditemukan." << endl;
        return;
    } else {
        cout << "Jenis Kereta: " << P->info.jenisKereta << endl;
        cout << "Asal: " << P->info.asal << endl;
        cout << "Tujuan: " << P->info.tujuan << endl;
        cout << "Tanggal: " << P->info.tanggal << endl;

        // Hapus kereta dari ListKereta (LK)
        deleteAfterK(LK, jenisKereta);

        // Hapus relasi yang terkait dengan kereta yang dihapus dari List_R (L)
        adr_Relasi R = L.first;
        adr_Relasi prec = NULL;

        if (R != NULL) {
            do {
                if (R->parent == P) {
                    if (R == L.first) {
                    adr_Relasi T = R;
                    deleteElement(L,T);
                    delete T;

                    R = L.first;
                    } else {
                    adr_Relasi T = R;
                    deleteElement(L,T);
                    delete T;

                        R = prec->next;
                    }
                } else {
                    prec = R;
                    R = R->next;
                }
            } while (R != L.first);
        }

        cout << "Data Kereta beserta Penumpangnya berhasil dihapus." << endl;
    }
}


//case 4
void cariParent(ListKereta &LK){
    string jenis;
    infotypeK X;
    adr_Kereta P;
    cout<<"Masukkan Jenis Kereta: "<<endl;
    cin>> jenis;
    X.jenisKereta = jenis;
    P = findElementKbyJenis(LK,X);
    if(P!=NULL){
        cout<<"Jenis: " <<P->info.jenisKereta<< endl;
        cout<<"Asal: " <<P->info.asal<< endl;
        cout<<"Tujuan: " <<P->info.tujuan<< endl;
        cout<<"tanggal: " <<P->info.tanggal<< endl;
    }else{
        cout<<"tidak ditemukan"<<endl;
    }
}
//case 5
void cariChild(ListPenumpang &LP){
    string nik;
    infotypeP X;
    adr_Penumpang P;
    cout<<"Masukkan NIK Penumpang: "<<endl;
    cin>> nik;
    X.NIK = nik;
    P = findElementPbyNIK(LP,X);
    if(P!=NULL){
        cout<<"Nama: " <<P->info.nama<< endl;
        cout<<"NIK: " <<P->info.NIK<< endl;
        cout<<"Usia: " <<P->info.usia<< endl;
        cout<<"Jenis Kelamin: " <<P->info.JenisKelamin<< endl;
    }else{
        cout<<"tidak ditemukan"<<endl;
    }
}

//case 6
void TambahDataPenumpang(ListPenumpang &LP){
    infotypeP X;
    adr_Penumpang P;




    cout <<"Masukkan Nama Penumpang: ";
    cin >> X.nama;
    cout <<"Masukkan NIK: ";
    cin >> X.NIK;
    cout <<"Masukkan Usia: ";
    cin >> X.usia;
    cout <<"Masukkan Jenis Kelamin Penumpang: ";
    cin >> X.JenisKelamin;
    cout <<endl<<endl;

    P = alokasiP(X);

    insertLast_P(LP,P);
    cout<<"Data Penumpang Berhasil Dimasukkan! "<<endl;
}

//case 7
void TambahkanPenumpangKeKereta(List_R &LR, ListKereta &LK, ListPenumpang &LP){

    int opt;
    cout << "1. Tambah Penumpang dari List penumpang yang sudah ada ke Kereta" << endl;
    cout << "2. Tambah Penumpang baru ke Kereta" << endl;
    cout << "Pilih : ";
    cin >> opt;
    switch (opt)
        {
        case 1:
            {

            string jeniskereta;
            string nik;
            infotypeP P;

            cout<<"Masukkan NIK penumpang"<<endl;
            cin>> nik;
            P.NIK = nik;
            adr_Penumpang C = findElementPbyNIK(LP,P);
            cout<<"Nama: " <<C->info.nama<< endl;
            cout<<"NIK: " <<C->info.NIK<< endl;
            cout<<"Usia: " <<C->info.usia<< endl;
            cout<<"Jenis Kelamin: " <<C->info.JenisKelamin<< endl;

            cout <<"Masukkan Jenis Kereta : ";
            cin >> jeniskereta;

            // Ubah jenis kereta menjadi objek Kereta (infotypeK)
            infotypeK X;
            X.jenisKereta = jeniskereta;
            adr_Kereta kereta = findElementKbyJenis(LK, X);

            if (kereta== NULL){
                cout << "Kereta dengan jenis " << jeniskereta << " tidak ditemukan." << endl;
                return;
            }

            cout << "Jenis Kereta: " << kereta->info.jenisKereta << endl;
            cout << "Asal: " << kereta->info.asal << endl;
            cout << "Tujuan: " << kereta->info.tujuan << endl;
            cout << "Tanggal: " << kereta->info.tanggal << endl;

            connect(LR,LK,LP,X,P);
            break;
            }
        case 2:
            {
            string jeniskereta;
            cout <<"Masukkan Jenis Kereta : ";
            cin >> jeniskereta;

            // Ubah jenis kereta menjadi objek Kereta (infotypeK)
            infotypeK X;
            X.jenisKereta = jeniskereta;
            adr_Kereta kereta = findElementKbyJenis(LK, X);

            if (kereta== NULL){
                cout << "Kereta dengan jenis " << jeniskereta << " tidak ditemukan." << endl;
                return;
            }

            cout << "Jenis Kereta: " << kereta->info.jenisKereta << endl;
            cout << "Asal: " << kereta->info.asal << endl;
            cout << "Tujuan: " << kereta->info.tujuan << endl;
            cout << "Tanggal: " << kereta->info.tanggal << endl;

            infotypeP P;
            adr_Penumpang Y;
            cout <<"Masukkan Nama Penumpang :";
            cin >> P.nama;

            cout <<"Masukkan NIK Penumpang :";
            cin >> P.NIK;

            cout << "Masukkan Usia Penumpang :";
            cin >> P.usia;

            cout <<"Masukkan Jenis Kelamin Penumpang (L/P) :";
            cin >>P.JenisKelamin;

            Y = alokasiP(P);
            insertLast_P(LP,Y);

            connect(LR,LK,LP,X,P);

            /*adr_Relasi relasi = alokasi(kereta, penumpangK);
            insertFirst_R(LR, relasi);*/

            cout << "Penumpang berhasil ditambahkan ke kereta." << endl;
            }
            break;
        default:
            cout<<"Menu Tidak Tersedia"<<endl;
        }

}

//case 8
//done
//case9
// Case 9
void CariDataPenumpangpadaKereta(List_R &LR, ListKereta &LK, ListPenumpang &LP){
    string jenisKereta, NIK;

    cout <<"Masukkan Jenis Kereta: ";
    cin >> jenisKereta;


    infotypeK X;
    X.jenisKereta = jenisKereta;
    adr_Kereta kereta = findElementKbyJenis(LK, X);

    if (kereta == NULL) {
        cout << "Kereta dengan jenis " << jenisKereta << " tidak ditemukan." << endl;
        return;
    }

    cout << "Jenis Kereta: " << kereta->info.jenisKereta << endl;
    cout << "Asal: " << kereta->info.asal << endl;
    cout << "Tujuan: " << kereta->info.tujuan << endl;
    cout << "Tanggal: " << kereta->info.tanggal << endl;

    cout << "Masukkan NIK Penumpang yang dicari: ";
    cin >> NIK;


    infotypeP Y;
    Y.NIK = NIK;
    adr_Penumpang penumpang = findElementPbyNIK(LP, Y);

    if (penumpang == NULL) {
        cout << "Penumpang dengan NIK " << NIK << " tidak ditemukan." << endl;
        return;
    }

    cout << "Data Penumpang yang dicari:" << endl;
    cout << "Nama: " << penumpang->info.nama << endl;
    cout << "NIK: " << penumpang->info.NIK << endl;
    cout << "Usia: " << penumpang->info.usia << endl;
    cout << "Jenis Kelamin: " << penumpang->info.JenisKelamin << endl;


    adr_Relasi relasi = findElement(LR, kereta->info, penumpang->info);
    if (relasi != NULL) {
        cout << "Penumpang ini berada pada kereta tersebut." << endl;
    } else {
        cout << "Penumpang ini tidak berada pada kereta tersebut." << endl;
    }
}

//case10
void HapusDataPenumpangpadaKereta(List_R &LR, ListKereta &LK, ListPenumpang &LP){
    string jenisKereta,NIK;
    cout <<"Masukkan Jenis Kereta :";
    cin >>jenisKereta;

    infotypeK X;
    X.jenisKereta=jenisKereta;
    adr_Kereta P=findElementKbyJenis(LK,X);
    if(P == NULL){
        cout <<"Kereta dengan jenis "<<jenisKereta<<"Tidak ditemukan."<<endl;
        return;
    }

    cout << "Jenis Kereta: " << P->info.jenisKereta << endl;
    cout << "Asal: " << P->info.asal << endl;
    cout << "Tujuan: " << P->info.tujuan << endl;
    cout << "Tanggal: " << P->info.tanggal << endl;

    cout << "Masukkan NIK Penumpang yang ingin dihapus: ";
    cin >> NIK;

    infotypeP Z;
    Z.NIK =NIK;
    adr_Penumpang Penumvang=findElementPbyNIK(LP,Z);
    if(Penumvang ==NULL){
        cout <<"Penumpang dengan NIK"<<NIK<<"Tidak ditemukan."<<endl;
        return;
    }
    cout <<" Data Penumpang yang dicari "<<endl;
    cout <<"Nama : "<<Penumvang->info.nama<<endl;
    cout <<"Usia : "<<Penumvang->info.usia<<endl;
    cout <<"NIK  : "<<Penumvang->info.NIK<<endl;
    cout <<"Jenis Kelamin : "<<Penumvang->info.JenisKelamin<<endl;

    disconnect(LR,P->info,Penumvang->info);


    cout <<"Data Penumpang Berhasil Dihapuskan Dari Kereta."<<endl;

}


// Case 11
void HitungDataPenumpangpadaKereta(List_R &LR, ListKereta &LK) {
    string jenisKereta;

    cout << "Masukkan Jenis Kereta: ";
    cin >> jenisKereta;

    infotypeK X;
    X.jenisKereta = jenisKereta;
    adr_Kereta kereta = findElementKbyJenis(LK, X);

    if (kereta == NULL) {
        cout << "Kereta dengan jenis " << jenisKereta << " tidak ditemukan." << endl;
        return;
    }

    cout << "Jenis Kereta: " << kereta->info.jenisKereta << endl;
    cout << "Asal: " << kereta->info.asal << endl;
    cout << "Tujuan: " << kereta->info.tujuan << endl;
    cout << "Tanggal: " << kereta->info.tanggal << endl;
    adr_Relasi R = LR.first;
    int jumlahPenumpang = 0;

    if(R->parent == kereta){
        jumlahPenumpang++;
        R = R->next;
    }else{
        R = R->next;
    }
    if(R!=NULL){
        do{
            if(R->parent == kereta){
                jumlahPenumpang++;
                R = R->next;
            }else{
                R = R->next;
            }
        }while(R!=LR.first);
    }
    cout << "Jumlah Penumpang pada Kereta " << kereta->info.jenisKereta << ": " << jumlahPenumpang << endl;
}
