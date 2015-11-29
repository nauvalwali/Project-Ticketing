#include <iostream>
#include "asd.h"


using namespace std;

void createstudio (List &l)
{
    first(l)=nil;
    last(l)=nil;
};

void createfilm (List_Film &m)
{
    first(m)=nil;
    last(m)=nil;
};

addressstudio alokasi_studio (studio x)
{
    addressstudio p=new elmstudio;
    info_studio(p)=x;
    next(p)=nil;
    prev(p)=nil;
    return p;
};

addressfilm alokasi_film(Film y)
{
    addressfilm p=new elmFilm;
    info_film(p)=y;
    next(p)=nil;
    return p;
};


void insertfirst_studio (List &l, addressstudio p)
{
    if (first(l)==nil)
    {
        first(l)=p;
        last(l)=p;
    }
    else
    {
        next(p)=first(l);
        prev(first(l))=p;
        first(l)=p;
    }
};

void insertfirst_film (List_Film &m, addressfilm &q)
{
    if (first(m)==nil)
    {
        first(m)=q;
        last(m)=q;
    }
    else
    {
        next(q)=first(m);
        prev(first(m))=q;
        first(m)=q;
    }
};

void insertlast_studio (List &l, addressstudio p)
{
    if(first(l)==nil)
    {
        first(l)=p;
        last(l)=p;
    }
    else
    {
        prev(p)=last(l);
        next(last(l))=p;
        last(l)=p;
    }
};

void insertafter_studio (List &l, addressstudio p, addressstudio prec)
{
    prec=next(first(l));

    if (first(l)==nil)
    {
        insertfirst_studio(l,p);
    }
    else if (last(l) == nil)
    {
        insertlast_studio(l,p);
    }
    else
    {
        next(p)=next(prec);
        prev(p)=prec;
        prev(next(prec))=p;
        next(prec)=p;
    }
};

void insertlast_film (List_Film &m, addressfilm &q)
{
    if(first(m)==nil)
    {
        first(m)=q;
        last(m)=q;
    }
    else
    {
        prev(q)=last(m);
        next(last(m))=q;
        last(m)=q;
    }
};

void deletefirst_studio (List &l, addressstudio &p)
{
    if (first(l)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(l)==last(l))
    {
        first(l)=nil;
        last(l)=nil;
    }
    else
    {
        p=first(l);
        first(l)=next(first(l));
        next(p)=nil;
        prev(first(l))=nil;
    }
};

void deletefirst_film (List_Film &m, addressfilm &q)
{
    if (first(m)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(m)==last(m))
    {
        first(m)=nil;
        last(m)=nil;
    }
    else
    {
        q=first(m);
        first(m)=next(first(m));
        next(q)=nil;
        prev(first(m))=nil;
    }
};

void deleteafter_film (List_Film &m,addressfilm &q, addressfilm prec)
{
    if(q==first(m))
    {
        deletefirst_film(m,q);
    }
    else if(q==last(m))
    {
        deletelast_film(m,q);
    }
    else
    {
        prec=prev(q);
        next(prec)=next(q);
        prev(next(q))=prec;
        prev(q)=nil;
        next(q)=nil;
    }
};

void deleteafter_studio (List &l,addressstudio &p, addressstudio prec)
{
    if(p==first(l))
    {
        deletefirst_studio(l,p);
    }
    else if(p==last(l))
    {
        deletelast_studio(l,p);
    }
    else
    {
        prec=prev(p);
        next(prec)=next(p);
        prev(next(p))=prec;
        prev(p)=nil;
        next(p)=nil;
    }
};

void deletelast_studio (List &l, addressstudio &p)
{
    if (first(l)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(l)==last(l))
    {
        first(l)=nil;
        last(l)=nil;
    }
    else
    {
        p=last(l);
        last(l)=prev(last(l));
        prev(p)=nil;
        next(last(l))=nil;
    }
};

void deletelast_film (List_Film &m, addressfilm &q)
{
    if (first(m)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(m)==last(m))
    {
        first(m)=nil;
        last(m)=nil;
    }
    else
    {
        q=last(m);
        last(m)=prev(last(m));
        prev(q)=nil;
        next(last(m))=nil;
    }
};

addressstudio findelm_studio (List l,int x)
{
    addressstudio p;
    p=first(l);
    if(p==nil)
    {
        return nil;
    }
    while (p!=nil)
    {
        if(info_studio(p).id_studio==x)
        {
            return p;
        }
        p=next(p);

    }
    return 0;
};

addressstudio findelm_studio_sama (List l,int x)
{
    addressstudio p;
    p=first(l);
    while(p!=nil)
    {
        if (info_studio(p).id_studio==x)
        {
            return p;
        }
        else
        {
            p=next(p);
        }
    }

};

addressfilm findelm_film (List_Film m,int y)
{
    addressfilm q;
    q=first(m);
    if(q==nil)
    {
        return nil;
    }
    while (q!=nil)
    {
        if(info_film(q).idfilm==y)
        {
            return q;
        }
        q=next(q);
    }
    return nil;
};

void setFilm(addressstudio p, addresschild r)
{
    if(firstchild(p)==nil)
    {
        firstchild(p)=r;
        lastchild(p)=r;
    }
    else
    {
        prev(r)=lastchild(p);
        next(lastchild(p))=r;
        lastchild(p)=r;
    }
};

addressfilm findelm_film_sama (List_Film m,int y)
{
    addressfilm q;
    q=first(m);
    while(q!=nil)
    {
        if (info_film(q).idfilm==y)
        {
            return q;
        }
        else
        {
            q=next(q);
        }
    }
};

void printinfo_studio (List l)
{
    addressstudio p;
    p=first(l);
    while (p!=nil)
    {
        cout <<"ID Studio   : "<<info_studio(p).id_studio<<endl
             <<"Nama Studio : "<<info_studio(p).nama<<endl<<endl;
        p=next(p);
    }
}
void printinfo_film (List_Film m)
{
    addressfilm q;
    q=first(m);
    while (q!=nil)
    {
        cout <<"ID Film   : "<<info_film(q).idfilm<<endl
             <<"Nama film : "<<info_film(q).namafilm<<endl
             <<"Durasi    : "<<info_film(q).durasi<<endl
             <<endl;
        q=next(q);
    }
};

void add_studio(studio &x)
{
    cout <<"ID Studio   : ";
    cin >> x.id_studio;
    cout <<"Nama Studio : ";
    cin >> x.nama;
};
void add_film(Film &y)
{
    cout <<"ID Film : ";
    cin >> y.idfilm;
    cout <<"Nama Film : ";
    cin >> y.namafilm;
    cout <<"Durasi  : ";
    cin >> y.durasi;
};
