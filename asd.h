#ifndef ASD_H_INCLUDED
#define ASD_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>

#define info_studio(p) (p)->info_studio
#define info_film(p) (p)->info_film
#define info(p) p->info
#define next(p) (p)->next
#define next_film(p) (p)->next_film
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define last(l) ((l).last)
#define firststudio(p) (p)->firststudio
#define laststudio(p) (p)->laststudio
#define firstfilm(p) (p)->firstfilm
#define lastfilm(p) (p)->lastfilm
#define firstchild(p) (p)->firstchild
#define lastchild(p) (p)->lastchild
#define nil NULL

using namespace std;

typedef struct elmstudio *addressstudio;
typedef struct elmschild *addresschild;
typedef struct elmFilm *addressfilm;


struct studio
{
    int id_studio;
    string nama;
};

struct elmstudio
{
    studio info_studio;
    addressstudio next,prev;
    addresschild firstchild;
    addresschild lastchild;
};

struct child
{
    addressfilm elmFilm;
};

struct elmschild
{
    child info;
    addresschild next,prev;
    addresschild first,last;
};

struct Film
{
    int idfilm;
    int durasi;
    string namafilm;
};

struct elmFilm
{
    Film info_film;
    addressfilm next,prev;
};


struct List
{
    addressstudio first,last;
};

struct List_Film
{
    addressfilm first,last;
};


void createstudio (List & );
void createfilm (List_Film &);

addressstudio alokasi_studio (studio );
addressfilm alokasi_film (Film );

void insertfirst_studio (List &, addressstudio );
void insertfirst_film (List_Film &, addressfilm &);

void insertafter_studio (List &, addressstudio, addressstudio );

void insertlast_studio (List &, addressstudio );
void insertlast_film (List_Film &, addressfilm &);

void deletefirst_studio (List &, addressstudio &);
void deletefirst_film (List_Film &, addressfilm &);

void deleteafter_studio (List &,addressstudio &,addressstudio );
void deleteafter_film (List_Film &, addressfilm &, addressfilm );

void deletelast_studio (List &, addressstudio &);
void deletelast_film (List_Film &, addressfilm &);

addressstudio findelm_studio (List ,int );
addressfilm findelm_film (List_Film ,int );

void printinfo_studio (List );
void printinfo_film (List_Film );

void add_studio(studio &);
void add_film(Film & );

addressstudio findelm_studio_sama (List ,int );
addressfilm findelm_film_sama (List_Film ,int );
void setFilm(addressstudio ,addresschild );


#endif // ASD_H_INCLUDED
