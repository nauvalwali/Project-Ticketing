#include <iostream>
#include "asd.h"
#include <stdlib.h>
using namespace std;

int main()
{
    List l;
    List_Film m;
    studio x;
    Film y;
    addressstudio p;
    addressfilm q;
    createstudio(l);
    createfilm(m);
    int pilihan;
    int cariID;
    int cariFilm;
    while (pilihan!=9)
    {
        system("CLS");
        cout << "1. Add Studio"<<"\n"
             << "2. Find Studio By ID"<<"\n"
             << "3. Edit Studio"<<"\n"
             << "4. Add Film"<<"\n"
             << "5. Find Film by ID"<<"\n"
             << "6. Set Film to Studio"<<"\n"
             << "7. Unset and Delete Film"<<"\n"
             << "8. Delete Studio"<<"\n"
             << "9. exit"<<"\n"
             << "pilihan: ";
        cin >> pilihan;

        if (pilihan==1)
        {
            system("CLS");
            add_studio(x);
            addressstudio r=findelm_studio_sama(l,x.id_studio);
            if(r==nil)
            {
                p=alokasi_studio(x);
                insertlast_studio(l,p);
                system("CLS");
            }
            else
            {
                cout << "Data Sudah Ada";
            };

            getch();
        }
        else if (pilihan==2)
        {
            system("CLS");
            cout << "Masukkan ID Studio yang akan dicari : ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if(p==nil)
            {
                cout <<"Tidak ditemukan"<<endl;
            }
            else
            {
                cout<<endl<<"Data sebagai berikut : \n" << endl
                <<"ID Studio : "<<info_studio(p).id_studio<<endl
                <<"Nama : "<<info_studio(p).nama<<endl;
            }
            getch();
            system("CLS");
        }
        else if (pilihan==3)
        {
            system("CLS");
            cout << "Masukkan ID Studio yang ingin Anda ubah : ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            cout <<"Nama Studio : ";
            cin >> info_studio(p).nama;
            cout << endl;
            cout << "Data berhasil di ubah";
            getch();
        }
        else if (pilihan==4)
        {
            system("CLS");
            add_film(y);
            addressfilm s=findelm_film_sama(m,y.idfilm);
            if(s==nil)
            {
                q=alokasi_film(y);
                insertlast_film(m,q);
                system("CLS");
                cout <<"Data Berhasil di Input" << endl;
            }
            else
            {
                cout << "Data Sudah Ada";
            };

            getch();
        }
        else if (pilihan==5)
        {
            system("CLS");
            cout << "Masukkan ID Film yang akan dicari : ";
            cin >> cariFilm;
            q=findelm_film(m,cariFilm);
            if(q==nil)
            {
                cout<<"data tidak ada"<<endl;
            }
            else
            {
                cout<<endl<<"Data sebagai berikut : \n" << endl
                <<"ID Film  : "<<info_film(q).idfilm<<endl
                <<"Nama Film: "<<info_film(q).namafilm<<endl
                <<"Durasi Film: "<<info_film(q).durasi<<endl;
            }
            getch();
            system("CLS");
        }
        else if (pilihan==6)
        {
            system("CLS");
            printinfo_studio(l);
            cout << "masukkan ID Studio yang ingin anda Set: ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if (p!=nil)
            {
                cout << endl;
                printinfo_film(m);
                cout << "masukkan ID Film yang ingin anda Set ke Studio: ";
                cin >> cariFilm;
                addressfilm filmAdd=findelm_film(m,cariFilm);
                if(filmAdd!=nil)
                {
                    addresschild filmChild=new elmschild;
                    filmChild->info.elmFilm=filmAdd;
                    setFilm(p,filmChild);
                    cout << "Berhasil";
                }
                else
                {
                    cout<<"Film tidak ditemukan";
                }
            }
            else
            {
                cout <<"Studio tidak ditemukan";
            }
            getch();
        }
        else if (pilihan==7)
        {
            system("CLS");
            addressfilm prec;
            printinfo_film(m);
            cout << "masukkan ID Film yang ingin anda hapus: ";
            cin >> cariFilm;
            q=findelm_film(m,cariFilm);
            if (q!=nil)
            {
                deleteafter_film(m,q,prec);
                system("CLS");
                cout << "data berhasil dihapus, berikut data sekarang: "<<endl<<endl;
                if(q==nil)
                {
                    cout << "tidak ada data lagi";
                }
                else
                {
                    printinfo_film(m);
                }
            }
            getch();
        }
        else if (pilihan==8)
        {
            system("CLS");
            addressstudio prec;
            printinfo_studio(l);
            cout << "masukkan ID Studio yang ingin anda hapus: ";
            cin >> cariID;
            p=findelm_studio(l,cariID);
            if (p!=nil)
            {
                deleteafter_studio(l,p,prec);
                system("CLS");
                cout << "data berhasil dihapus, berikut data sekarang: "<<endl<<endl;
                if(p==nil)
                {
                    cout << "tidak ada data lagi";
                }
                else
                {
                    printinfo_studio(l);
                }
            }
            getch();
        }
    }
    return 0;
}
