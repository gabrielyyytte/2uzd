#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct studentas
{
    std::string vardas, pavarde;
    double egz;
};

int pasirinkimas();
int kiekis(int& k);
void ivedimas(std::vector<studentas>& A, int i);
int pasirinkimas2();
void generacija(std::vector<studentas>& A, int i);
void rezultatai(std::vector<studentas>& A, int i);
void spausdinimas(std::vector<studentas>& A, int i, int did_vard, int did_pav);
void remas(std::vector<studentas>& A, int i, int& did_vard, int& did_pav);
void remelis();
void rikiavimas(std::vector<studentas>& A, int& nr);
void skaitymas(std::vector<studentas>& A, int& nr);
void generacija_txt(int i, int& nr);
double Galutinis(std::vector<int>& HW, int egz);
void skaitymas_v(std::vector<studentas>& A, int& i);
void skaitymas_l(std::list<studentas>& A, int& i);
void skaitymas_d(std::deque<studentas>& A, int& i);
void spausdinimasrez_v(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& i);
void spausdinimasrez_l(std::list<studentas>& kieti, std::list<studentas>& silpni, int& i);
void spausdinimasrez_d(std::deque<studentas>& kieti, std::deque<studentas>& silpni, int& i);
void rusiavimas_v(std::vector<studentas>& A, std::vector<studentas>& kieti);
void rusiavimas_l(std::list<studentas>& A, std::list<studentas>& kieti);
void rusiavimas_d(std::deque<studentas>& A, std::deque<studentas>& kieti);



#endif // FUNCTIONS_H_INCLUDED
