#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct studentas
{
    std::string vardas, pavarde;
    std::vector <int> nd;
    double galutinisV=0;
    double galutinisM=0;
    double vid=0;
    double med=0;
    int egz=0;
    int sum=0;
    int sk=0;
};

int pasirinkimas ();
int kiekis (int &k);
void ivedimas (std::vector<studentas> &A, int i);
int pasirinkimas2();
void generacija(std::vector<studentas> &A, int i);
void rezultatai(std::vector<studentas> &A, int i);
double rastimediana(std::vector<studentas> &A, int i);
void vidurkis(std::vector<studentas> &A, int i);
void spausdinimas(std::vector<studentas> &A, int i);
void remas ();
void rikiavimas (std::vector<studentas> &A, int &nr);
void skaitymas (std::vector<studentas> &A, int &nr);


#endif // FUNCTIONS_H_INCLUDED
