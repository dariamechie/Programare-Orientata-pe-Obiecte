#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Persoana
{
protected:
    int id;
    string nume;
public:
    Persoana(): id(0), nume("") {} //constr de init fara param
    Persoana(int id, string nume): id(id), nume(nume) {}  //constr de init cu param

    Persoana(const Persoana& persoana)  //constr de copiere
    {
        this->id = persoana.id;
        this->nume = persoana.nume;
    }

    virtual ~Persoana() {} //destr

    void setId(int x)
    {
        this->id = id;
    }
    void setNume(string nume)
    {
        this->nume = nume;
    }
    int getId()
    {
        return id;
    }

    string getNume()
    {
        return nume;
    }

    friend istream& operator>> (istream&, Persoana&);
    friend ostream& operator<< (ostream&, const Persoana&);

    Persoana& operator=(const Persoana &obiect) //suprascrierea op =
    {
        this->id=obiect.id;
        this->nume=obiect.nume;

        return *this;
    }

};

istream& operator>> (istream& in, Persoana& persoana)
{
    in >> persoana.id >> persoana.nume;
    return in;
}

ostream& operator<< (ostream& out, const Persoana& persoana)
{
    out << persoana.id << ' ' << persoana.nume;
    return out;
}

class Abonat : public Persoana
{
protected:
    string nr_telefon;
public:
    Abonat(): Persoana(), nr_telefon("") {} //init fara param
    Abonat(int id, string nume, string nr_telefon): Persoana(id, nume), nr_telefon(nr_telefon) {} //init cu param
    Abonat(const Abonat& abonat) //copiere
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
    }
    virtual ~Abonat() {}
    void setNrTelefon(string nr_telefon)
    {
        this->nr_telefon = nr_telefon;
    }
    string getNrTelefon()
    {
        return nr_telefon;
    }
    friend istream& operator>> (istream&, Abonat&);
    friend ostream& operator<< (ostream&, const Abonat&);

    Abonat& operator=(const Abonat &obiect)
    {
        this->id=obiect.id;
        this->nume=obiect.nume;
        this->nr_telefon=obiect.nr_telefon;

        return *this;
    }
};

istream& operator>> (istream& in, Abonat& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon;
    return in;
}

ostream& operator<< (ostream& out, const Abonat& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon;
    return out;
}

class Abonat_Skype: public Abonat
{
protected:
    string id_skype;
public:
    Abonat_Skype():Abonat(), id_skype("") {}
    Abonat_Skype(int id, string nume, string nr_telefon, string id_skype): Abonat(id, nume, nr_telefon), id_skype(id_skype) {}
    Abonat_Skype(const Abonat_Skype& abonat)
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
        this->id_skype = abonat.id_skype;
    }
    virtual ~Abonat_Skype() {}
    void setIdSkype(string id_skype)
    {
        this->id_skype = id_skype;
    }
    string getIdSkype()
    {
        return id_skype;
    }
    friend istream& operator>> (istream&, Abonat_Skype&);
    friend ostream& operator<< (ostream&, const Abonat_Skype&);

    Abonat_Skype& operator=(const Abonat_Skype &obiect)
    {
        this->id=obiect.id;
        this->nume=obiect.nume;
        this->nr_telefon=obiect.nr_telefon;
        this->id_skype=obiect.id_skype;

        return *this;
    }

};


istream& operator>> (istream& in, Abonat_Skype& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon >> abonat.id_skype;
    return in;
}

ostream& operator<< (ostream& out, const Abonat_Skype& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon << ' ' << abonat.id_skype;
    return out;
}

class Abonat_Skype_Romania: public Abonat_Skype
{
private:
    static int nr_abonati;
    string adresa_mail;
public:
    Abonat_Skype_Romania(): Abonat_Skype(), adresa_mail("")
    {
        nr_abonati++;
    }
    Abonat_Skype_Romania(int id, string nume, string nr_telefon, string id_skype, string adresa_mail): Abonat_Skype(id, nume, nr_telefon, id_skype), adresa_mail(adresa_mail)
    {
        nr_abonati++;
    }
    Abonat_Skype_Romania(const Abonat_Skype_Romania& abonat)
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
        this->id_skype = abonat.id_skype;
        this->adresa_mail = abonat.adresa_mail;
    }
    ~Abonat_Skype_Romania()
    {
        nr_abonati--;
    }
    void setAdresaMail(string adresa_mail)
    {
        this->adresa_mail = adresa_mail;
    }
    string getAdresaMail()
    {
        return adresa_mail;
    }
    friend istream& operator>> (istream&, Abonat_Skype_Romania&);
    friend ostream& operator<< (ostream&, const Abonat_Skype_Romania&);

    Abonat_Skype_Romania& operator=(const Abonat_Skype_Romania &obiect)
    {
        this->id=obiect.id;
        this->nume=obiect.nume;
        this->nr_telefon=obiect.nr_telefon;
        this->id_skype=obiect.id_skype;
        this->adresa_mail=obiect.adresa_mail;

        return *this;
    }
    static int getNrAbonatiRomania()
    {
        return nr_abonati;
    }

};

int Abonat_Skype_Romania::nr_abonati=0;

istream& operator>> (istream& in, Abonat_Skype_Romania& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon >> abonat.id_skype >> abonat.adresa_mail;
    return in;
}

ostream& operator<< (ostream& out, const Abonat_Skype_Romania& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon << ' ' << abonat.id_skype << ' ' << abonat.adresa_mail;
    return out;
}


class Abonat_Skype_Extern: public Abonat_Skype
{
private:
    string tara;
    static int nr_abonati;
public:
    Abonat_Skype_Extern(): Abonat_Skype(), tara("")
    {
        nr_abonati++;
    }
    Abonat_Skype_Extern(int id, string nume, string nr_telefon, string id_skype, string tara): Abonat_Skype(id, nume, nr_telefon, id_skype), tara(tara)
    {
        nr_abonati++;
    }
    Abonat_Skype_Extern(const Abonat_Skype_Extern& abonat)
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
        this->id_skype = abonat.id_skype;
        this->tara = abonat.tara;
    }
    ~Abonat_Skype_Extern()
    {
        nr_abonati--;
    }
    void setTara(string tara)
    {
        this->tara = tara;
    }
    string getTara()
    {
        return tara;
    }
    friend istream& operator>> (istream&, Abonat_Skype_Extern&);
    friend ostream& operator<< (ostream&, const Abonat_Skype_Extern&);
    static int getNrAbonatiExtern()
    {
        return nr_abonati;
    }
    Abonat_Skype_Extern& operator=(const Abonat_Skype_Extern &obiect)
    {
        this->id = obiect.id;
        this->nume = obiect.nume;
        this->nr_telefon = obiect.nr_telefon;
        this->id_skype = obiect.id_skype;
        this->tara = obiect.tara;

        return *this;
    }
};

int Abonat_Skype_Extern::nr_abonati=0;
istream& operator>> (istream& in, Abonat_Skype_Extern& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon >> abonat.id_skype >> abonat.tara;
    return in;
}

ostream& operator<< (ostream& out, const Abonat_Skype_Extern& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon << ' ' << abonat.id_skype << ' ' << abonat.tara;
    return out;
}

class Agenda
{
private:
    vector<Abonat_Skype *> lista_abonati; //retin obiecte de tip abonat_skype in vect lista_abonati
public:
    Agenda() : lista_abonati() {}

    Agenda(const Agenda& obiect) //constr de copiere
    {
        for(Abonat_Skype* i: obiect.lista_abonati) //parcurge toata lista
        {
            Abonat_Skype *daria = new Abonat_Skype(*i);
            this->lista_abonati.push_back(daria);
        }
    }

    ~Agenda()
    {
        Abonat_Skype *q;
        int n = this->lista_abonati.size() - 1;
        while(this->lista_abonati.empty() == 0)
        {
            q = this->lista_abonati[n];
            this->lista_abonati.pop_back();
            delete q;
            n--;
        }
    }

    Agenda& operator=(const Agenda &obiect)
    {

        Abonat_Skype *q;
        int n = this->lista_abonati.size() - 1;
        while(this->lista_abonati.empty() == 0)
        {
            q = this->lista_abonati[n];
            this->lista_abonati.pop_back();
            delete q;
            n--;
        }

        for(Abonat_Skype* i: obiect.lista_abonati) //parcurge toata lista
        {
            Abonat_Skype *daria = new Abonat_Skype(*i);
            this->lista_abonati.push_back(daria);
        }

        return *this;
    }
    void Adaugare_element(Abonat_Skype &obiect)
    {
        Abonat_Skype *daria=new Abonat_Skype(obiect);
        this->lista_abonati.push_back(daria);
    }
    void Adaugare_element_romania(int id, string nume, string nr_tel, string id_skype, string adresa_mail)
    {
        Abonat_Skype_Romania *q = new Abonat_Skype_Romania(id, nume, nr_tel, id_skype, adresa_mail);
        this->lista_abonati.push_back(q);
    }
    void Adaugare_element_extern(int id, string nume, string nr_tel, string id_skype, string tara)
    {
        Abonat_Skype_Extern *q = new Abonat_Skype_Extern(id, nume, nr_tel, id_skype, tara);
        this->lista_abonati.push_back(q);
    }
    void Eliminare_element(int index)
    {
        if(index <= this->lista_abonati.size())
        {
            std :: vector <Abonat_Skype* > :: iterator it = this->lista_abonati.begin() + index - 1;
            Abonat_Skype* q = this->lista_abonati[index - 1];
            this->lista_abonati.erase(it);
            delete q;
        }
        else
        {
            cout << "Nu exista nici un abonat cu indexul " << index << '\n';
        }
    }
    Abonat_Skype* operator[] (string nume) //suprascrierea op de indexare []
    {
        for(Abonat_Skype* i: this->lista_abonati)
            if(i->getNume() == nume)
                return i;
        return NULL; //returnez null in caz ca nu exista nici un abonat cu numele dat
    }
    int getNrAbonatiRomania()
    {
        return Abonat_Skype_Romania::getNrAbonatiRomania();
    }
    int getNrAbonatiExtern()
    {
        return Abonat_Skype_Extern::getNrAbonatiExtern();
    }
};

int main()
{
    Agenda Ag;
    cout<<"Cu ajutorul acestui meniu modificam agenda de abonati."<<'\n';
    cout<<"Optiuni:"<<'\n'<<'\n';

    cout<<"0: Exit\n";
    cout<<"1: Creeaza abonat\n";
    cout<<"2: Sterge abonat cu indexul\n";
    cout<<"3: Afisare angajat cu numele\n";
    cout<<"4: Afisare numar abonati din Romania\n";
    cout<<"5: Afisare numar abonati externi\n";

    int nr;
    while(true)
    {
        cout << "\n\n" << "Introduceti instructiune\n";
        cin >> nr;
        switch (nr)
        {
        case 0:
            exit(0);
        case 1:
        {
            cout<<"Introduceti tipul abonatului (Romania/extern)\n";
            char str[10];
            cin>>str;
            if(str[0]=='R')
            {
                cout<<"Introduceti id-ul, numele, nr de telefon, id skype si adresa de mail:\n";
                int id;
                string nume, nr_tel, id_skype, adresa_mail;
                cin >> id >> nume >> nr_tel >> id_skype >> adresa_mail;
                Ag.Adaugare_element_romania(id, nume, nr_tel, id_skype, adresa_mail);
            }
            if(str[0]=='e')
            {
                cout<<"Introduceti id-ul, numele, nr de telefon, id skype si tara:\n";
                int id;
                string nume, nr_tel, id_skype, tara;
                cin >> id >> nume >> nr_tel >> id_skype >> tara;
                Ag.Adaugare_element_extern(id, nume, nr_tel, id_skype, tara);
            }
            break;
        }
        case 2:
        {
            cout << "Introduceti indexul abonatului spre a fi sters:\n";
            int nr;
            cin >> nr;
            Ag.Eliminare_element(nr);

            break;
        }
        case 3:
        {
            cout<<"Introduceti numele abonatului:\n";
            string nume;
            cin>>nume;
            Abonat_Skype* q= Ag[nume]; // supraincarcarea operatorului [] returneaza un pointer de tip Abonat_Skype, iar pentru a afisa toate datele despre acel abonat trebuie sa fac downcast spre clasa din care apartine
            if(q == NULL) // verific daca exista un abonat cu acest nume
                cout << "Nu exista nici un angajat cu numele " << nume;
            else
            {
                if(Abonat_Skype_Extern* pointer = dynamic_cast < Abonat_Skype_Extern* > (q))
                    cout << *pointer;
                if(Abonat_Skype_Romania* pointer = dynamic_cast < Abonat_Skype_Romania* > (q))
                    cout << *pointer;
            }
            break;
        }

        case 4:
        {
            cout << Ag.getNrAbonatiRomania() << '\n';
            break;
        }
        case 5:
        {
            cout << Ag.getNrAbonatiExtern() << '\n';
            break;
        }
        }
    }


    return 0;
}
