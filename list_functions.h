#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct studentas
{
    std::string vardas, pavarde;
    std::list <int> nd;
    int egz = 0;
};

int pasirinkimas();
int kiekis(int& k);
void ivedimas(std::list<studentas>& A, int i);
int pasirinkimas2();
void generacija(std::list<studentas>& A, int i);
void rezultatai(std::list<studentas>& A, int i);
double rastimediana(std::list<studentas>& A, int i);
double vidurkis(std::list<studentas>& A, int i);
void spausdinimas(std::list<studentas>& A, int i, int did_vard, int did_pav);
void remas(std::list<studentas>& A, int i, int& did_vard, int& did_pav);
void remelis();
void rikiavimas(std::list<studentas>& A, int& nr);
void skaitymas(std::list<studentas>& A, int& nr);
void generacija_txt(int i, int& nr);
void skaitymas_gen(std::list<studentas>& A, int& i);
void spausdinimasrez(std::list<studentas>& kieti, std::list<studentas>& silpni, int& i);
void rusiavimas(std::list<studentas>& A, std::list<studentas>& kieti);


#endif // FUNCTIONS_H_INCLUDED
