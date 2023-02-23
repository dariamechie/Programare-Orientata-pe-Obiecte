#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Animal
{
protected:
    string nume_specie;
    int varsta;

public:
    Animal() : nume_specie(""), varsta(0) {}
    Animal(string nume_specie, int varsta) : nume_specie(nume_specie), varsta(varsta) {}

    Animal(const Animal &animal)
    {
        this->nume_specie = animal.nume_specie;
        this->varsta = animal.varsta;
    }

    virtual ~Animal() {}
    void setNumeSpecie(string nume_specie)
    {
        this->nume_specie = nume_specie;
    }

    void setVarsta(int varsta)
    {
        this->varsta = varsta;
    }

    string getNumeSpecie()
    {
        return nume_specie;
    }

    int getVarsta()
    {
        return varsta;
    }

    Animal &operator=(const Animal &animal)
    {
        this->nume_specie = animal.nume_specie;
        this->varsta = animal.varsta;

        return *this;
    }

    friend istream &operator>>(istream &, Animal &);
    friend ostream &operator<<(ostream &, const Animal &);
};

istream &operator>>(istream &in, Animal &animal)
{
    in >> animal.nume_specie >> animal.varsta;
    return in;
}

ostream &operator<<(ostream &out, const Animal &animal)
{
    out << animal.nume_specie << ' ' << animal.varsta;
    return out;
}

class Vertebrate : public Animal
{
protected:
    static int nr_vertebrate;

public:
    Vertebrate() : Animal()
    {
        nr_vertebrate++;
    }
    Vertebrate(string nume_specie, int varsta) : Animal(nume_specie, varsta)
    {
        nr_vertebrate++;
    }
    Vertebrate(const Vertebrate &vertebrate)
    {
        this->nume_specie = vertebrate.nume_specie;
        this->varsta = vertebrate.varsta;

        nr_vertebrate++;
    }
    virtual ~Vertebrate()
    {
        nr_vertebrate--;
    }

    static int getNrVertebrate()
    {
        return nr_vertebrate;
    }

    Vertebrate &operator=(const Vertebrate &vertebrate)
    {
        this->nume_specie = vertebrate.nume_specie;
        this->varsta = vertebrate.varsta;

        return *this;
    }

    friend istream &operator>>(istream &in, Vertebrate &vertebrate);
    friend ostream &operator<<(ostream &out, const Vertebrate &vertebrate);
};
istream &operator>>(istream &in, Vertebrate &vertebrate)
{
    in >> vertebrate.nume_specie >> vertebrate.varsta;

    return in;
}
ostream &operator<<(ostream &out, const Vertebrate &vertebrate)
{
    out << vertebrate.nume_specie << ' ' << vertebrate.varsta;

    return out;
}

int Vertebrate::nr_vertebrate = 0;

class Nevertebrate : public Animal
{
private:
    static int nr_nevertebrate;

public:
    Nevertebrate() : Animal()
    {
        nr_nevertebrate++;
    }
    Nevertebrate(string nume_specie, int varsta) : Animal(nume_specie, varsta)
    {
        nr_nevertebrate++;
    }
    Nevertebrate(const Nevertebrate &vertebrate)
    {
        this->nume_specie = vertebrate.nume_specie;
        this->varsta = vertebrate.varsta;

        nr_nevertebrate++;
    }
    ~Nevertebrate()
    {
        nr_nevertebrate--;
    }

    static int getNrNevertebrate()
    {
        return nr_nevertebrate;
    }

    Nevertebrate &operator=(const Nevertebrate &nevertebrate)
    {
        this->nume_specie = nevertebrate.nume_specie;
        this->varsta = nevertebrate.varsta;

        return *this;
    }

    friend istream &operator>>(istream &, Nevertebrate &);
    friend ostream &operator<<(ostream &, const Nevertebrate &);
};

istream &operator>>(istream &in, Nevertebrate &nevertebrate)
{
    in >> nevertebrate.nume_specie >> nevertebrate.varsta;
    return in;
}

ostream &operator<<(ostream &out, const Nevertebrate &nevertebrate)
{
    out << nevertebrate.nume_specie << ' ' << nevertebrate.varsta;
    return out;
}

int Nevertebrate::nr_nevertebrate = 0;

class Pesti : public Vertebrate
{
private:
    float lungime;

public:
    Pesti() : Vertebrate(), lungime(0) {}
    Pesti(string nume_specie, int varsta, float lungime) : Vertebrate(nume_specie, varsta), lungime(lungime) {}
    Pesti(const Pesti &peste)
    {
        this->nume_specie = peste.nume_specie;
        this->varsta = peste.varsta;
        this->lungime = peste.lungime;
    }
    ~Pesti() {}
    void setLungime(float lungime)
    {
        this->lungime = lungime;
    }
    float getLungime()
    {
        return lungime;
    }
    Pesti &operator=(const Pesti &peste)
    {
        this->nume_specie = peste.nume_specie;
        this->varsta = peste.varsta;
        this->lungime = peste.lungime;

        return *this;
    }
    friend istream &operator>>(istream &, Pesti &);
    friend ostream &operator<<(ostream &, const Pesti &);
};

istream &operator>>(istream &in, Pesti &peste)
{
    in >> peste.nume_specie >> peste.varsta >> peste.lungime;
    return in;
}
ostream &operator<<(ostream &out, const Pesti &peste)
{
    out << peste.nume_specie << ' ' << peste.varsta << ' ' << peste.lungime;
    return out;
}

class Pasari : public Vertebrate
{
private:
    float greutate;

public:
    Pasari() : Vertebrate(), greutate(0) {}
    Pasari(string nume_specie, int varsta, float greutate) : Vertebrate(nume_specie, varsta), greutate(greutate) {}
    Pasari(const Pasari &pasare)
    {
        this->nume_specie = pasare.nume_specie;
        this->varsta = pasare.varsta;
        this->greutate = pasare.greutate;
    }
    ~Pasari() {}
    void setGreutate(float greutate)
    {
        this->greutate = greutate;
    }
    float getGreutate()
    {
        return greutate;
    }
    Pasari &operator=(const Pasari &pasare)
    {
        this->nume_specie = pasare.nume_specie;
        this->varsta = pasare.varsta;
        this->greutate = pasare.greutate;

        return *this;
    }
    friend istream &operator>>(istream &, Pasari &);
    friend ostream &operator<<(ostream &, const Pasari &);
};

istream &operator>>(istream &in, Pasari &pasare)
{
    in >> pasare.nume_specie >> pasare.varsta >> pasare.greutate;
    return in;
}

ostream &operator<<(ostream &out, const Pasari &pasare)
{
    out << pasare.nume_specie << ' ' << pasare.varsta << ' ' << pasare.greutate;
    return out;
}

class Mamifere : public Vertebrate
{
private:
    float greutate;

public:
    Mamifere() : Vertebrate(), greutate(0) {}
    Mamifere(string nume_specie, int varsta, float greutate) : Vertebrate(nume_specie, varsta), greutate(greutate) {}
    Mamifere(const Mamifere &mamifer)
    {
        this->nume_specie = mamifer.nume_specie;
        this->varsta = mamifer.varsta;
        this->greutate = mamifer.greutate;
    }
    ~Mamifere() {}
    void setGreutate(float greutate)
    {
        this->greutate = greutate;
    }
    float getGreutate()
    {
        return greutate;
    }
    Mamifere &operator=(const Mamifere &mamifer)
    {
        this->nume_specie = mamifer.nume_specie;
        this->varsta = mamifer.varsta;
        this->greutate = mamifer.greutate;

        return *this;
    }
    friend istream &operator>>(istream &, Mamifere &);
    friend ostream &operator<<(ostream &, const Mamifere &);
};

istream &operator>>(istream &in, Mamifere &mamifer)
{
    in >> mamifer.nume_specie >> mamifer.varsta >> mamifer.greutate;
    return in;
}
ostream &operator<<(ostream &out, const Mamifere &mamifer)
{
    out << mamifer.nume_specie << ' ' << mamifer.varsta << ' ' << mamifer.greutate;
    return out;
}

class Reptile : public Vertebrate
{
private:
    float greutate;

public:
    Reptile() : Vertebrate(), greutate(0) {}
    Reptile(string nume_specie, int varsta, float greutate) : Vertebrate(nume_specie, varsta), greutate(greutate) {}
    Reptile(const Reptile &reptila)
    {
        this->nume_specie = reptila.nume_specie;
        this->varsta = reptila.varsta;
        this->greutate = reptila.greutate;
    }
    ~Reptile() {}
    void setGreutate(float greutate)
    {
        this->greutate = greutate;
    }
    float getGreutate()
    {
        return this->greutate;
    }
    Reptile &operator=(const Reptile &reptila)
    {
        this->nume_specie = reptila.nume_specie;
        this->varsta = reptila.varsta;
        this->greutate = reptila.greutate;
    }
    friend istream &operator>>(istream &, Reptile &);
    friend ostream &operator<<(ostream &, const Reptile &);
};

istream &operator>>(istream &in, Reptile &reptila)
{
    in >> reptila.nume_specie >> reptila.varsta >> reptila.greutate;
    return in;
}

ostream &operator<<(ostream &out, const Reptile &reptila)
{
    out << reptila.nume_specie << ' ' << reptila.varsta << ' ' << reptila.greutate;
    return out;
}

template <class T>
class AtlasZoologic
{
private:
    int nr_animale;
    vector<T *> animale;

public:
    AtlasZoologic() : nr_animale(0) {}
    AtlasZoologic(const AtlasZoologic &atlas)
    {
        this->nr_animale = atlas.nr_animale;
        T *daria;
        for (T *i : atlas.animale)
        {
            daria = new T(*i);              // creez un obiect nou din vectorul atlas.animale care e dat spre a fi copiat
            this->animale.push_back(daria); // si il pun in vectorul animale din clasa curenta
        }
    }
    ~AtlasZoologic()
    {
        int n = animale.size() - 1;
        T *daria;
        while (animale.empty() == 0)
        {
            daria = animale[n]; // atribuim in pointer ul daria pointer ul de pe poz n din vect animale
            n--;
            animale.pop_back();
            delete daria;
        }
    }

    void stergere(int i)
    {
        if(i <= animale.size())
        {
            typename vector<T *>::iterator it = this->animale.begin() + i - 1;
            T *p = this->animale[i - 1];
            this->animale.erase(it);
            delete p;
        }
        else
            throw 1;
    }

    void afisare(int i) const
    {
        if(i <= animale.size())
        {
           if (Vertebrate *p = dynamic_cast<Vertebrate *>(this->animale[i - 1]))
            {
                if (Pesti *q = dynamic_cast<Pesti *>(p))
                    cout << *q;
                if (Pasari *q = dynamic_cast<Pasari *>(p))
                    cout << *q;
                if (Mamifere *q = dynamic_cast<Mamifere *>(p))
                    cout << *q;
                if (Reptile *q = dynamic_cast<Reptile *>(p))
                    cout << *q;
            }
            if (Nevertebrate *p = dynamic_cast<Nevertebrate *>(this->animale[i - 1]))
                cout << *p;
            cout << '\n';
        }
        else
            throw 1;
    }

    AtlasZoologic &operator=(const AtlasZoologic &atlas)
    {
        int n = this->animale.size() - 1;
        T *daria;
        while (!this->animale.empty())
        {
            daria = this->animale[n];
            n--;
            this->animale.pop_back();
            delete daria;
        }

        this->nr_animale = atlas.nr_animale;

        for (T *i : atlas.animale)
        {
            daria = new T(*i);
            this->animale.push_back(daria);
        }

        return *this;
    }
    AtlasZoologic &operator+=(T *daria)
    {
        nr_animale++;
        this->animale.push_back(daria);
        return *this;
    }
    template <class U>
    friend ostream &operator<<(ostream &, const AtlasZoologic<U> &);
};

template <class U>
ostream &operator<<(ostream &out, const AtlasZoologic<U> &atlas)
{
    U *daria;
    for (U *i : atlas.animale)
    {
        if (Vertebrate *p = dynamic_cast<Vertebrate *>(i))
        {
            if (Pesti *q = dynamic_cast<Pesti *>(p))
                out << *q;
            if (Pasari *q = dynamic_cast<Pasari *>(p))
                out << *q;
            if (Mamifere *q = dynamic_cast<Mamifere *>(p))
                out << *q;
            if (Reptile *q = dynamic_cast<Reptile *>(p))
                out << *q;
        }
        if (Nevertebrate *p = dynamic_cast<Nevertebrate *>(i))
            out << *p;
        out << '\n';
    }

    return out;
}

template <>
class AtlasZoologic<Pesti *>
{
private:
    int nr_animale;
    vector<Pesti *> animale;

public:
    void afisare_pesti_mari()
    {
        for (Pesti *i : animale)
        {
            if (i->getLungime() > 1)
                cout << *i << '\n';
        }
    }
};

int main()
{
    AtlasZoologic<Animal> Atlas;
    cout << "Cu ajutorul acestui meniu modificam agenda de abonati." << '\n';
    cout << "Optiuni:" << '\n'
         << '\n';
    cout << "0: Exit\n";
    cout << "1: Adauga animal\n";
    cout << "2: Stergere animal din Atlas\n";
    cout << "3: Afisare animal\n";
    cout << "4: Afisare toate animalele\n";
    cout << "5: Afisare numar vertebrate\n";
    cout << "6: Afisare numar nevertebrate\n";

    int nr;
    string s1;
    int varsta;
    float lungime, greutate;
    while (true)
    {
        cout << "\n\n"
             << "Introduceti instructiune\n";
        cin >> nr;
        switch (nr)
        {
        case 0:
            exit(0);
        case 1:
        {
            cout << "Introduceti tipul de animal\n";
            char s[101];
            cin >> s;
            if (tolower(s[0]) == 'v')
            {
                cout << "Introduceti tipul de vertebrata(peste, pasare, mamifer, reptila)\n";
                cin >> s;
                if (tolower(s[0]) == 'p')
                {
                    if (tolower(s[1]) == 'e')
                    {
                        cout << "Introduceti numele speciei, varsta si lungimea\n";
                        cin >> s1 >> varsta >> lungime;
                        Pesti *p = new Pesti(s1, varsta, lungime);
                        Atlas += p;
                    }
                    else
                    {
                        cout << "Introduceti numele speciei, varsta si greutatea\n";
                        cin >> s1 >> varsta >> greutate;
                        Pasari *p = new Pasari(s1, varsta, greutate);
                        Atlas += p;
                    }
                }
                if (tolower(s[0] == 'm'))
                {
                    cout << "Introduceti numele speciei, varsta si greutatea\n";
                    cin >> s1 >> varsta >> greutate;
                    Mamifere *p = new Mamifere(s1, varsta, greutate);
                    Atlas += p;
                }
                if (tolower(s[0]) == 'r')
                {
                    cout << "Introduceti numele speciei, varsta si greutatea\n";
                    cin >> s1 >> varsta >> greutate;
                    Reptile *p = new Reptile(s1, varsta, greutate);
                    Atlas += p;
                }
            }
            else
            {
                cout << "Introduceti numele speciei si varsta\n";
                cin >> s1 >> varsta;
                Nevertebrate *p = new Nevertebrate(s1, varsta);
                Atlas += p;
            }
            break;
        }
        case 2:
        {
            cout << "Introduceti indexul animalului dat spre a fi sters\n";
            cin >> lungime;
            try {
                Atlas.stergere(lungime);
            }
            catch(int exc)
            {
                cout << "Nu exista nici un animal in atlas cu indexul dat\n";
            }
            break;
        }
        case 3:
        {
            cout << "Introduceti indexul animalului dat spre a fi afisat\n";
            cin >> lungime;
            try
            {
                Atlas.afisare(lungime);
            }
            catch (int exc)
            {
                cout << "Nu exista nici un animal in atlas cu indexul dat\n";
            }
            break;
        }
        case 4:
        {
            cout << Atlas;
            break;
        }
        case 5:
        {
            cout << Vertebrate::getNrVertebrate() << '\n';
            break;
        }
        case 6:
        {
            cout << Nevertebrate::getNrNevertebrate() << '\n';
        }
        }
    }

    return 0;
}
