#include <iostream>

using namespace std;
class Vector
{
    int n, *v;
public:
    Vector()
    {
        n=0;
        v=NULL;                     ///constructor de initializare
    }
    Vector(int n, int c=0)
    {
        this->n=n;
        v=new int[n];
        for(int i=0; i<this->n; i++)
            v[i]=c;
    }
    ~Vector()
    {
        delete []v;                         ///destructor
    }

    Vector(const Vector&);                  ///constructor de copiere
    friend istream& operator>>(istream&, Vector&);      ///citire
    friend ostream& operator<<(ostream&, Vector&);      ///afisare

    Vector& operator=(Vector&);

    void Suma(int &suma)
    {
        for(int i=0;i<n;i++)
            suma+=v[i];
    }

     void Maxim(int &Max, int &imax)
     {
        int i;
        Max=v[0];
        imax=0;
        for(i=1;i<n;i++)
            if(v[i]>Max)
                Max=v[i], imax = i;
    }

     void Sortare()
     {
        int i, j;
        for(i=0; i<n-1; i++)
            for(j=i+1; j<n; j++)
                if(v[i] > v[j])
                    swap(v[i],v[j]);

    }

    void SetPrimul(int pozitie, int valoare) { if(pozitie >= 0 && pozitie < n) v[pozitie] = valoare;} /// set pt elem de pe poz data

    int GetPrimul(int pozitie) { return v[pozitie];} /// get pt elem de pe poz data

    void Setn(int valoare) { this -> n = valoare;} /// set pt nr elem

    int Getn() { return n;} /// get pt nr elem

    ///void GetVecttor() { for( int i = 0; i < n; i++) cout << v[i] << ' '; cout<<endl;} /// get pt tot vectorul

};
Vector::Vector(const Vector& obiect)
{
    this->n=obiect.n;
    this->v=new int[this->n];
    for(int i=0;i<this->n;i++)              ///constr de copiere
                                            ///nu modifica val, fiind const
        this->v[i]=obiect.v[i];

}
istream& operator>>(istream&in, Vector& v1)
{
    in>>v1.n;
    delete []v1.v;
    v1.v=new int[v1.n];
    for(int i=0;i<v1.n;i++)
        in>>v1.v[i];
    return in;
}
ostream& operator<<(ostream&out, Vector& v1)
{
    out<<"Vectorul are "<<v1.n<<" elemente"<<endl;
    out<<"Elementele vectorului sunt: ";
    for(int i=0;i<v1.n;i++)
        out<<v1.v[i]<<' ';
    return out;
}

Vector& Vector::operator=(Vector& obiect)
{
    this->n=obiect.n;
    delete []v;
    this->v=new int[this->n];
    for(int i=0;i<this->n;i++)
        this->v[i]=obiect.v[i];
}
int Max, imax, suma;
int main()
{
    Vector v1,v2,v3(3, 5);
    cin>>v1;
    v2=v1;
    cout<<v2<<endl;
    v1.Maxim(Max,imax);
    cout<<"Maximul din vector este: "<<Max<<" si se afla pe pozitia "<<imax<<endl;
    v1.Suma(suma);
    cout<<"Suma elementelor vectorului este "<<suma<<endl;
    v1.Sortare();
    int nrelemente=v1.Getn();
    for(int i=0;i<nrelemente;i++)
        cout<<v1.GetPrimul(i)<<' ';
    cout<<v3;

    return 0;
}
