#include<fstream>
#include<string>
#include<typeinfo>
#include<iostream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

class Bunuri
{
protected:
    int tip;
    double pret;
    double cantitate;
public:
    Bunuri(int,double,double);
    virtual double cost(double)=0;
    double getPret();
    int getTip();
    double getCantitate();
    void setPret(double);
    void setTip(int);
    void setCantitate(double);
};

Bunuri::Bunuri(int a,double b, double c)
{
    tip=a;
    pret=b;
    cantitate=c;
}

double Bunuri::getPret()
{
    return pret;
}

int Bunuri::getTip()
{
    return tip;
}

void Bunuri::setPret(double x)
{
    pret = x;
}

void Bunuri::setTip(int x)
{
    tip=x;
}

double Bunuri::getCantitate()
{
    return cantitate;
}

void Bunuri::setCantitate(double x)
{
    cantitate=x;
}

class Varza: public Bunuri
{
    string nume;
    string origine;
public:
    Varza(string,string,int,double,double);
    ~Varza();
    friend ifstream& operator>>(ifstream&, Varza&);
    friend ofstream& operator<<(ofstream&, Varza&);
    double cost(double);
    string getNume();
    string getOrigine();
    void setNume(string);
    void setOrigine(string);
};

Varza::Varza(string nume="",string origine="",int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->nume=nume;
    this->origine=origine;
}

Varza::~Varza()
{

}

double Varza::cost(double cantitate)
{
    return getPret()*cantitate;
}

string Varza::getNume()
{
    return nume;
}

string Varza::getOrigine()
{
    return origine;
}

void Varza::setNume(string x)
{
    nume = x;
}

void Varza::setOrigine(string x)
{
    origine = x;
}

ifstream& operator>>(ifstream& fin, Varza& ob)
{
    fin>>ob.nume>>ob.origine>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Varza& ob)
{
    fout<<ob.nume<<" "<<ob.origine<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}

class Faina:public Bunuri
{
    int calitate;
    string nume;
public:
    Faina(int,string,int,double,double);
    ~Faina();
    friend ifstream& operator>>(ifstream&, Faina&);
    friend ofstream& operator<<(ofstream&, Faina&);
    double cost(double);
    string getNume();
    int getCalitate();
    void setNume(string);
    void setCalitate(int);
};

Faina::Faina(int calitate=0,string nume="",int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->calitate=calitate;
    this->nume=nume;
}

Faina::~Faina()
{

}

double Faina::cost(double cantitate)
{
    return getPret()*cantitate;
}

string Faina::getNume()
{
    return nume;
}

int Faina::getCalitate()
{
    return calitate;
}

void Faina::setNume(string x)
{
    nume = x;
}

void Faina::setCalitate(int x)
{
    calitate = x;
}

ifstream& operator>>(ifstream& fin, Faina& ob)
{
    fin>>ob.nume>>ob.calitate>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Faina& ob)
{
    fout<<ob.nume<<" "<<ob.calitate<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}

class Bere: public Bunuri
{
    string brand;
    string varietate;
public:
    Bere(string,string,int,double,double);
    ~Bere();
    friend ifstream& operator>>(ifstream&, Bere&);
    friend ofstream& operator<<(ofstream&, Bere&);
    double cost(double);
    string getBrand();
    string getVarietate();
    void setBrand(string);
    void setVarietate(string);
};

Bere::Bere(string brand="",string varietate="",int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->brand=brand;
    this->varietate=varietate;
}

Bere::~Bere()
{

}

double Bere::cost(double cantitate)
{
    return getPret()*cantitate;
}

string Bere::getBrand()
{
    return brand;
}

string Bere::getVarietate()
{
    return varietate;
}

void Bere::setBrand(string x)
{
    brand = x;
}

void Bere::setVarietate(string x)
{
    varietate = x;
}

ifstream& operator>>(ifstream& fin, Bere& ob)
{
    fin>>ob.brand>>ob.varietate>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Bere& ob)
{
    fout<<ob.brand<<" "<<ob.varietate<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}

class Cartofi:public Bunuri
{
    string varietate;
public:
    Cartofi(string,int,double,double);
    ~Cartofi();
    friend ifstream& operator>>(ifstream&, Cartofi&);
    friend ofstream& operator<<(ofstream&, Cartofi&);
    double cost(double);
    string getVarietate();
    void setVarietate(string);
};

Cartofi::Cartofi(string varietate="",int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->varietate=varietate;
}

Cartofi::~Cartofi()
{

}

double Cartofi::cost(double cantitate)
{
    return getPret()*cantitate;
}

string Cartofi::getVarietate()
{
    return varietate;
}

void Cartofi::setVarietate(string x)
{
    varietate = x;
}

ifstream& operator>>(ifstream& fin, Cartofi& ob)
{
    fin>>ob.varietate>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Cartofi& ob)
{
    fout<<ob.varietate<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}

class Jucarie: public Bunuri
{
    string nume;
public:
    Jucarie(string,int,double,double);
    ~Jucarie();
    friend ifstream& operator>>(ifstream&, Jucarie&);
    friend ofstream& operator<<(ofstream&, Jucarie&);
    double cost(double);
    string getNume();
    void setNume(string);
};

Jucarie::Jucarie(string nume="",int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->nume=nume;
}

Jucarie::~Jucarie()
{

}

double Jucarie::cost(double cantitate)
{
    return getPret()*cantitate;
}

string Jucarie::getNume()
{
    return nume;
}

void Jucarie::setNume(string x)
{
    nume = x;
}

ifstream& operator>>(ifstream& fin, Jucarie& ob)
{
    fin>>ob.nume>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Jucarie& ob)
{
    fout<<ob.nume<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}

class Vin_varsat: public Bunuri
{
    int varietate;
public:
    Vin_varsat(int,int,double,double);
    ~Vin_varsat();
    friend ifstream& operator>>(ifstream&, Vin_varsat&);
    friend ofstream& operator<<(ofstream&, Vin_varsat&);
    double cost(double);
    int getVerietate();
    void setVarietate(int);
};

Vin_varsat::Vin_varsat(int varietate=0,int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->varietate=varietate;
}

Vin_varsat::~Vin_varsat()
{

}

double Vin_varsat::cost(double cantitate)
{
    return getPret()*cantitate;
}

int Vin_varsat::getVerietate()
{
    return varietate;
}

void Vin_varsat::setVarietate(int x)
{
    varietate=x;
}

ifstream& operator>>(ifstream& fin, Vin_varsat& ob)
{
    fin>>ob.varietate>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Vin_varsat& ob)
{
    fout<<ob.varietate<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}

class Vin_de_soi: public Bunuri
{
    string nume;
    string origine;
    int varietate;
    int an;
public:
    Vin_de_soi(string,string,int,int,int,double,double);
    ~Vin_de_soi();
    friend ifstream& operator>>(ifstream&, Vin_de_soi&);
    friend ofstream& operator<<(ofstream&, Vin_de_soi&);
    double cost(double);
    string getNume();
    void setNume(string);
    string getOrigine();
    void setOrigine(string);
    int getVerietate();
    void setVarietate(int);
    int getAn();
    void setAn(int);
};

Vin_de_soi::Vin_de_soi(string nume="",string origine="",int varietate=0,int an=0,int a=0,double b=0.0,double c=0.0):Bunuri(a,b,c)
{
    this->nume=nume;
    this->origine=origine;
    this->varietate=varietate;
    this->an=an;
}

Vin_de_soi::~Vin_de_soi()
{

}

double Vin_de_soi::cost(double cantitate)
{
    return getPret()*cantitate;
}

string Vin_de_soi::getNume()
{
    return nume;
}

void Vin_de_soi::setNume(string x)
{
    nume=x;
}

string Vin_de_soi::getOrigine()
{
    return origine;
}

void Vin_de_soi::setOrigine(string x)
{
    origine=x;
}

int Vin_de_soi::getVerietate()
{
    return varietate;
}

void Vin_de_soi::setVarietate(int x)
{
    varietate=x;
}

int Vin_de_soi::getAn()
{
    return an;
}

void Vin_de_soi::setAn(int x)
{
    an=x;
}
ifstream& operator>>(ifstream& fin, Vin_de_soi& ob)
{
    fin>>ob.nume>>ob.origine>>ob.varietate>>ob.an>>ob.pret>>ob.tip>>ob.cantitate;
    return fin;
}

ofstream& operator<<(ofstream& fout, Vin_de_soi& ob)
{
    fout<<ob.nume<<" "<<ob.origine<<" "<<ob.varietate<<" "<<ob.an<<" "<<ob.pret<<" "<<ob.tip<<" "<<ob.cantitate;
    return fout;
}
int main()
{
    int n,m,j;
    Varza *varza;
    Faina *faina;
    Bere *bere;
    Vin_varsat *vin_varsat;
    Vin_de_soi *vin_de_soi;
    Cartofi *cartofi;
    Jucarie *jucarii;
    fin>>n;
    //obiecte din magazin
    varza= new Varza [n+1];
    faina= new Faina [n+1];
    bere= new Bere[n+1];
    vin_varsat=new Vin_varsat[n+1];
    vin_de_soi= new Vin_de_soi[n+1];
    cartofi=new Cartofi[n+1];
    jucarii= new Jucarie[n+1];

    for(int i=0; i<7; i++)
    {
        fin>>m;
        for(j=0; j<m; j++)
            switch (i)
            {
            case 0:
                fin>>varza[j];
                break;

            case 1:
                fin>>faina[j];
                break;

            case 2:
                fin>>bere[j];
                break;

            case 3:
                fin>>vin_varsat[j];
                break;

            case 4:
                fin>>vin_de_soi[j];
                break;

            case 5:
                fin>>cartofi[j];
                break;

            case 6:
                fin>>jucarii[j];
                break;
            }
    }

    int suma_totala=0, suma_totala_pt_o_zi=0;
    fin>>m; // nr total de liste
    int care,cantitate;
    int cata_varza, cata_faina, cata_bere, cat_vin1, cat_vin2, cati_cartofi, cate_jucarii;
    int care_varza, care_faina, care_bere, care_vin1, care_vin2, care_cartofi, care_jucarii;
    int varza_pt_o_zi=0, faina_pt_o_zi=0, bere_pt_o_zi=0, vin_varsat_pt_o_zi=0, vin_de_soi_pt_o_zi=0, cartofi_pt_o_zi=0, jucarii_pt_o_zi=0;
    for(int i=0; i<m; i++)
    {
        for(j=0; j<7; j++)
        {
            fin>>care>>cantitate;
            switch(j)
            {
            case 0:
                cata_varza = cantitate;
                care_varza=care;
                break;

            case 1:
                cata_faina=cantitate;
                care_faina=care;
                break;

            case 2:
                cata_bere=cantitate;
                care_bere=care;
                break;

            case 3:
                cat_vin1=cantitate;
                care_vin1=care;
                break;

            case 4:
                cat_vin2=cantitate;
                care_vin2=care;
                break;

            case 5:
                cati_cartofi=cantitate;
                care_cartofi=care;
                break;

            case 6:
                cate_jucarii=cantitate;
                care_jucarii=care;
                break;

            }

        }
        if(varza[care_varza-1].getCantitate()>=cata_varza &&
                faina[care_faina-1].getCantitate()>=cata_faina &&
                bere[care_bere-1].getCantitate()>=cata_bere &&
                vin_varsat[care_vin1-1].getCantitate()>=cat_vin1 &&
                vin_de_soi[care_vin2-1].getCantitate()>=cat_vin2 &&
                cartofi[care_cartofi-1].getCantitate()>= care_cartofi &&
                jucarii[cate_jucarii-1].getCantitate()>=care_jucarii
          )
        {
            suma_totala=0;
            suma_totala=varza[care_varza-1].getPret()*cata_varza +
                        faina[care_faina-1].getPret()*cata_faina +
                        bere[care_bere-1].getPret()*cata_bere +
                        vin_varsat[care_vin1-1].getPret()*cat_vin1 +
                        vin_de_soi[care_vin2-1].getPret()*cat_vin2 +
                        cartofi[cati_cartofi-1].getPret()* care_cartofi +
                        jucarii[cate_jucarii-1].getPret()*care_jucarii;
            cout<<suma_totala;
            int ok;
            cout<<"Daca suma totala e ok 1, altfel 0!";
            cin>>ok;
            if(ok)
            {
                varza[care_varza-1].setCantitate(varza[care_varza-1].getCantitate()-cata_varza);
                faina[care_faina-1].setCantitate(faina[care_faina-1].getCantitate()-cata_faina);
                bere[care_bere-1].setCantitate(bere[care_bere-1].getCantitate()-cata_bere);
                vin_varsat[care_vin1-1].setCantitate(vin_varsat[care_vin1-1].getCantitate()-cat_vin1);
                vin_de_soi[care_vin2-1].setCantitate(vin_de_soi[care_vin2-1].getCantitate()-cat_vin2);
                cartofi[cati_cartofi-1].setCantitate(cartofi[cati_cartofi-1].getCantitate()- care_cartofi);
                jucarii[cate_jucarii-1].setCantitate(jucarii[cate_jucarii-1].getCantitate()-care_jucarii);

                suma_totala_pt_o_zi+=suma_totala;
                varza_pt_o_zi+=cata_varza;
                faina_pt_o_zi+=cata_faina;
                bere_pt_o_zi+=cata_bere;
                vin_varsat_pt_o_zi+=cat_vin1;
                vin_de_soi_pt_o_zi+=cat_vin2;
                cartofi_pt_o_zi+=cati_cartofi;
                jucarii_pt_o_zi+=cate_jucarii;

            }
        }
        else
            cout<<"Indisponibil!";
    }

    cout<<"Bucati varza:"<<varza_pt_o_zi<<"\nKilograme faina:"<<faina_pt_o_zi<<"\nDoze de bere:"<<bere_pt_o_zi<<"\nLitrii de vin varsat:"<<vin_varsat_pt_o_zi;
    cout<<"\nSticle de vin de soi:"<<vin_de_soi_pt_o_zi<<"\nKilograme de cartofi:"<<cartofi_pt_o_zi<<"\nJucarii:"<<jucarii_pt_o_zi<<"\nSuma incasata:"<<suma_totala_pt_o_zi;

}



