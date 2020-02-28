#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

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

int pasirinkimas ()
{
    int f;
    std::cout << "Jei duomenis norite ivesti pats spauskite 0, jei norite, kad duomenys butu nuskaityti is tekstinio failo spauskite 1" <<std::endl;
    std::cin >> f;
    return f;
}
int kiekis(int &k)
{
    std::cout <<"Iveskite studentu skaiciu"<<std::endl;
    std::cin >> k;
    return k;
}
void ivedimas (std::vector<studentas>&A, int i)
{
    std::cout << "Iveskite studento varda ir pavarde" <<std::endl;
    std::cin >> A[i].vardas;
    std::cin >> A[i].pavarde;
}
int pasirinkimas2()
{
    int a;
    std::cout << "Jei norite generuoti rezultatus automatiskai spauskite 0. Jei norite duomenis ivesti patys spauskite 1"<<std::endl;
    std::cin >> a;

    return a;
}
void rezultatai(std::vector<studentas> &A, int i)
{
    int b;
    std::cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0" <<std::endl;
    do
    {
        std::cin >> b;
        if (b > 0 && b < 11)
        {
            A[i].nd.push_back(b);
            A[i].sk++;
            A[i].sum += b;
        }
    }
    while (b != 0);
    std::cout << "Iveskite egzamino pazymi" <<std::endl;
    std::cin >> A[i].egz;
    std::cout << "----------------------------------------" <<std::endl;

}
double rastimediana(std::vector<studentas> &A, int i)
{
    std::sort(A[i].nd.begin(), A[i].nd.end(), std::greater<int>());

    if (A[i].sk% 2 != 0)
    {
        A[i].med=(double)A[i].nd[A[i].sk/2];
        return A[i].med;
    }
    else
    {
        A[i].med=(double)(A[i].nd[(A[i].sk-1)/2] + A[i].nd[A[i].sk/2])/2.0;
        return A[i].med;
    }

}
void vidurkis(std::vector<studentas> &A, int i)
{
    A[i].vid=(double)A[i].sum/(double)A[i].sk;
}
bool skaicius(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
void generacija(std::vector<studentas> &A, int i)
{
    int kiek;
    int laik;
    std::cout << "Kiek skaiciu norite generuoti?" <<std::endl;
    std::cin >> kiek;

    srand (time(NULL));
    A[i].sk=kiek;
    std::cout<<"Jusu rezultatai:"<<std::endl;
    for (int j = 0; j <kiek; j++)
    {
        laik = rand() % 10 + 1;
        A[i].nd.push_back(laik);
        A[i].sum += laik;
        std::cout<<laik<<" ";
    }
    std::cout<<std::endl;
    std::cout << "----------------------------------------" <<std::endl;
    laik = rand() % 10 + 1;
    A[i].egz = laik;
}
void remas ()
{
    std::cout << "Pavarde" << std::right << std::setw(20) << "Vardas" << std::right<< std::setw(20) <<"Galutinis (Vid.)"<< std::right <<std::setw(20) <<"Galutinis (Med.)"<<std::endl;
    std::cout << "------------------------------------------------------------------------" <<std::endl;
}
void spausdinimas(std::vector<studentas> &A, int i)
{
    A[i].galutinisV = 0.4 * A[i].vid + 0.6 *(double) A[i].egz;
    A[i].galutinisM = 0.4 * A[i].med + 0.6 * (double) A[i].egz;
    std::cout <<  std::left <<std::setw(20)<< A[i].pavarde << std::left <<std::setw(20) << A[i].vardas << std::left <<std::setw(20)<< std::fixed << std::setprecision(2) << std::left << A[i].galutinisV <<std::setw(20) << std::left<< A[i].galutinisM <<std::endl;
}
void rikiavimas (std::vector<studentas> &A, int &nr)
{
    for (int i=0; i<nr-1; i++)
        for (int j=i+1; j<nr; j++)
            if (A[i].pavarde>A[j].pavarde)
            {
                std::swap (A[i], A[j]);
            }
}
void skaitymas (std::vector<studentas> &A, int &nr)
{
    int s=0, h=0, egz=0, y=0;
    std::string temp;
    std::string eil, vard, pav;;
    std::ifstream fd("kursiokai.txt");

while (std::getline(fd, eil))
    {
        A.push_back(studentas());
        std::istringstream in_line(eil);
        in_line >> vard >> pav;
        A[nr].vardas = vard;
        A[nr].pavarde = pav;
        nr++;

        while (in_line >> temp)
        {
            int ivedu = std::stoi(temp);
            if (ivedu >= 0 && ivedu <= 10)
            {
                A[s].nd.push_back(ivedu);
                A[s].sum+=ivedu;
                A[s].sk++;
            }
        }
        s++;
        in_line.end;
        egz = A[h].nd[A[h].sk-1];
        A[h].egz=egz;

        h++;
        A[s-1].nd[A[s-1].sk-1]=0;
        A[s-1].sum=A[s-1].sum-A[h-1].egz;
        A[s-1].sk--;
    }

    fd.close();
}
int main ()
{
    std::vector<studentas>A;
    int k = 0;
    const int a = pasirinkimas();
    if (a == 0)
    {
        int n = kiekis(k);
        for (int i = 0; i < n; i++)
        {
            A.push_back(studentas());
            ivedimas(A, i);
            int b = pasirinkimas2();
            if (b == 0)
            {
                generacija(A, i);
                rastimediana(A, i);
                vidurkis(A, i);
            }
            else
            {
                rezultatai(A, i);
                rastimediana(A, i);
                vidurkis(A, i);
            }
        }
        remas();
        for (int i = 0; i < n; i++)
        {
            rikiavimas(A, n);
            spausdinimas(A, i);
        }
    }
    else
    {
        int nr=0;
        skaitymas(A, nr);
        for (int i=0; i<nr; i++)
        {
            rastimediana(A, i);
            vidurkis(A, i);
            if (i==0)
                remas();
            rikiavimas(A, nr);
            spausdinimas (A, i);
        }
    }
    return 0;
}
