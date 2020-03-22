#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct studentas
{
    std::string vardas, pavarde;
    std::deque <int> nd;
    int egz = 0;
};

int pasirinkimas();
int kiekis(int& k);
void ivedimas(std::deque<studentas>& A, int i);
int pasirinkimas2();
void generacija(std::deque<studentas>& A, int i);
void rezultatai(std::deque<studentas>& A, int i);
double rastimediana(std::deque<studentas>& A, int i);
double vidurkis(std::deque<studentas>& A, int i);
void spausdinimas(std::deque<studentas>& A, int i, int did_vard, int did_pav);
void remas(std::deque<studentas>& A, int i, int& did_vard, int& did_pav);
void remelis();
void rikiavimas(std::deque<studentas>& A, int& nr);
void skaitymas(std::deque<studentas>& A, int& nr);
void generacija_txt(int i, int& nr);
void skaitymas_gen(std::deque<studentas>& A, int& i);
void spausdinimasrez(std::deque<studentas>& kieti, std::deque<studentas>& silpni, int& i);
void rusiavimas(std::deque<studentas>& A, std::deque<studentas>& kieti);


#endif // FUNCTIONS_H_INCLUDED
