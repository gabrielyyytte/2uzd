#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct studentas
{
    std::string vardas, pavarde;
    std::vector <int> nd;
    int egz = 0;
};

int pasirinkimas();
int kiekis(int& k);
void ivedimas(std::vector<studentas>& A, int i);
int pasirinkimas2();
void generacija(std::vector<studentas>& A, int i);
void rezultatai(std::vector<studentas>& A, int i);
double rastimediana(std::vector<studentas>& A, int i);
double vidurkis(std::vector<studentas>& A, int i);
void spausdinimas(std::vector<studentas>& A, int i, int did_vard, int did_pav);
void remas(std::vector<studentas>& A, int i, int& did_vard, int& did_pav);
void remelis();
void rikiavimas(std::vector<studentas>& A, int& nr);
void skaitymas(std::vector<studentas>& A, int& nr);
void generacija_txt(int i, int& nr);
void skaitymas_gen(std::vector<studentas>& A, int& i);
void spausdinimasrez(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& i);
void rusiavimas(std::vector<studentas>& A, std::vector<studentas>& kieti);


#endif // FUNCTIONS_H_INCLUDED
