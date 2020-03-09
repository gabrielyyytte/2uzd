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
#include <chrono>
#include <ctime>
#include <random>
#include "functions.h"

int pasirinkimas()
{
    int f;
    std::cout << "Jei duomenis norite ivesti pats spauskite 0, jei norite, kad duomenys butu nuskaityti is tekstinio failo spauskite 1" << std::endl;
    std::cin >> f;
    return f;
}
int kiekis(int& k)
{
    std::cout << "Iveskite studentu skaiciu" << std::endl;
    std::cin >> k;
    return k;
}
void ivedimas(std::vector<studentas>& A, int i)
{
    std::cout << "Iveskite studento varda ir pavarde" << std::endl;
    std::cin >> A[i].vardas;
    std::cin >> A[i].pavarde;
}
int pasirinkimas2()
{
    int a;
    std::cout << "Jei norite generuoti rezultatus automatiskai spauskite 0. Jei norite duomenis ivesti patys spauskite 1" << std::endl;
    std::cin >> a;

    return a;
}
void rezultatai(std::vector<studentas>& A, int i)
{
    int b;
    std::cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0" << std::endl;
    do
    {
        std::cin >> b;
        if (b > 0 && b < 11)
        {
            A[i].nd.push_back(b);
          //  A[i].sk++;
        }
    } while (b != 0);
    std::cout << "Iveskite egzamino pazymi" << std::endl;
    std::cin >> A[i].egz;
    std::cout << "----------------------------------------" << std::endl;

}
double rastimediana(std::vector<studentas>& A, int i)
{
    double medi;
    typedef std::vector<double>::size_type dydis;
    dydis size = A[i].nd.size();
    if (size == 0)
    {
        throw std::domain_error("negalima skaiciuoti medianos tusciam vektoriui");
    }

    std::sort(A[i].nd.begin(), A[i].nd.end(), std::greater<int>());

    if (A[i].nd.size() % 2 != 0)
    {
        medi = (double)A[i].nd[A[i].nd.size() / 2];
        return medi;
    }
    else
    {
        medi = (double)(A[i].nd[(A[i].nd.size() - 1) / 2] + A[i].nd[A[i].nd.size() / 2]) / 2.0;
        return medi;
    }

}
double vidurkis(std::vector<studentas>& A, int i)
{
    double vid;
    int suma = 0;
    for (int a = 0; a < A[i].nd.size(); a++)
        suma += A[i].nd[a];
    vid = suma / (double)A[i].nd.size();
    return vid;
}

double vidurkisStudento(studentas& stud)
{
    double vid;
    int suma = 0;
    for (int a = 0; a < stud.nd.size(); a++)
        suma += stud.nd[a];
    vid = suma / (double)stud.nd.size();
    return vid;
}

bool skaicius(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
void generacija(std::vector<studentas>& A, int i)
{
    int kiek;
    int laik;
    std::cout << "Kiek skaiciu norite generuoti?" << std::endl;
    std::cin >> kiek;

    srand(time(NULL));
   // A[i].sk = kiek;
    std::cout << "Jusu rezultatai:" << std::endl;
    for (int j = 0; j < kiek; j++)
    {
        laik = rand() % 10 + 1;
        A[i].nd.push_back(laik);
        std::cout << laik << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    laik = rand() % 10 + 1;
    A[i].egz = laik;
}
void remas(std::vector<studentas>& A, int i, int& did_vard, int& did_pav)
{
    if (A[i].vardas.size() > did_vard)
        did_vard = A[i].vardas.size();

    if (A[i].pavarde.size() > did_pav)
        did_pav = A[i].pavarde.size();

    std::cout << std::left << std::setw(did_vard + 15) << "Vardas ";
    std::cout << std::left << std::setw(did_vard + 15) << "Pavarde ";
    std::cout << std::left << std::setw(did_vard + 15) << "Galutinis (Vid.)";
    std::cout << std::left << std::setw(did_vard + 15) << ("Galutinis (Med.)");
    std::cout << std::endl;

    for (int g = 0; g < did_vard + did_pav + 70; g++)
        std::cout << std::left << "-";

    std::cout << std::endl;

}
void remelis()
{
    std::cout << "Pavarde" << std::right << std::setw(20) << "Vardas" << std::right<< std::setw(20) <<"Galutinis (Vid.)"<< std::right <<std::setw(20) <<"Galutinis (Med.)"<<std::endl;
    std::cout << "------------------------------------------------------------------------" <<std::endl;
}

void spausdinimas(std::vector<studentas>& A, int i, int did_vard, int did_pav)
{
    std::cout << std::left << std::setw(did_pav + 15) << A[i].pavarde;
    std::cout << std::left << std::setw(did_vard + 15) << A[i].vardas;
    std::cout << std::left << std::setw(did_vard + 15) << 0.4 * vidurkis(A, i) + 0.6 * (double)A[i].egz;
    std::cout << std::left << std::setw(did_vard + 15) << 0.4 * rastimediana(A, i) + 0.6 * (double)A[i].egz;
    std::cout << std::endl;

    for (int g = 0; g < did_vard + did_pav + 70; g++)
        std::cout << std::left << "-";
    std::cout << std::endl;
}
void rikiavimas(std::vector<studentas>& A, int& nr)
{
    for (int i = 0; i < nr - 1; i++)
        for (int j = i + 1; j < nr; j++)
            if (A[i].pavarde > A[j].pavarde)
            {
                std::swap(A[i], A[j]);
            }
}
void skaitymas(std::vector<studentas>& A, int& nr)
{
    int s = 0, h = 0, egz = 0, y = 0;
    std::string temp;
    std::string eil, vard, pav;;
    std::ifstream fd("kursiokai.txt");
    try
    {
        if (!fd.good())
        {
            throw "Failas neegzistuoja";
        }
    }
    catch (const char* exc)
    {
        std::cout << exc << std::endl;
    }
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
            }
            s++;
            in_line.end;
            egz = A[h].nd[A[h].nd.size() - 1];
            A[h].egz = egz;

            h++;
            A[s - 1].nd[A[s - 1].nd.size() - 1] = 0;
            //A[s - 1].sk--;
        }

        fd.close();
    }
}
void generacija_txt(int i, int& nr)
{
    std::string file_name[5] = { "test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt" };

    srand(time(NULL));
    int laik;

    std::ofstream outfile(file_name[i]);
    std::mt19937 mt(1729);
    std::uniform_int_distribution <int> dist(1, 10);

    for (int g = 0; g <= nr; g++)
    {
        outfile << "Vardas" << g << " " << "Pavarde" << g << " ";

        for (int j = 0; j < 5; j++)
        {

            laik = dist(mt);
            outfile << laik << " ";
        }

        outfile << std::endl;
    }

    outfile.close();
}
void skaitymas_gen(std::vector<studentas>& A, int& i)
{
    int nr = 0;
    int kiekis = 0;
    std::string temp;
    std::string eil, vard, pav;
    std::string file_name[5] = { "test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt" };
    std::ifstream in_file(file_name[i]);

    if (in_file.fail())
    {
        std::cout << "Rasymo i faila klaida";
        in_file.clear();
    }

    while (std::getline(in_file, eil))
    {
        std::istringstream in_line(eil);
        while (in_line >> temp)
            nr++;
        nr -= 3;

        studentas laikinas;
        laikinas.nd.reserve(nr);
        std::string row;
        std::stringstream dataRow;

        int laikinind;
        while (std::getline(in_file, row)) {
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            laikinas.nd.clear();
            for (int i = 0; i < nr; i++) {
                dataRow >> laikinind;
                laikinas.nd.push_back(laikinind);
            }
            dataRow >> laikinas.egz;
            try
            {
                A.push_back(laikinas);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko. Nuskaitytu irasu kiekis: " << kiekis << std::endl;
                return;
            }
            kiekis++;
        }
    }
}

void spausdinimasrez(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& i)
{
    std::string kietieji = "kietiakai" + std::to_string(i) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(i) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::app);
    std::ofstream silpnuFailas(silpnieji, std::ios::app);
    for (int i = 0; i < kieti.size(); i++)
    {
        kietuFailas << kieti[i].vardas << " " << kieti[i].pavarde << " " << 0.4 * vidurkis(kieti, i) + 0.6 * (double)kieti[i].egz << std::endl;
    }
    for (int i = 0; i < silpni.size(); i++)
    {
        silpnuFailas << silpni[i].vardas << " " << silpni[i].pavarde << " " << 0.4 * vidurkis(silpni, i) + 0.6 * (double)silpni[i].egz << std::endl;
    }
    kietuFailas.close();
    silpnuFailas.close();
}

void rusiavimas(std::vector<studentas>& A, std::vector<studentas>& kieti)
{
    std::sort(A.begin(), A.end(), [](studentas& s1, studentas& s2) {return ( 0.4 * vidurkisStudento(s1) + 0.6 * (double)s1.egz) < (0.4 * vidurkisStudento(s2) + 0.6 * (double)s2.egz); });

    int blogiStudentai = 0;
    while ((0.4 * vidurkisStudento(A[blogiStudentai]) + 0.6 * (double)A[blogiStudentai].egz) < 5.0)
        blogiStudentai++;

    kieti.reserve(A.size() - blogiStudentai);
    try {
        std::copy(A.begin() + blogiStudentai, A.end(), std::back_inserter(kieti));
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "Nepavyko isrusiuoti visu studentu" << std::endl;
    }
    try {
        A.resize(blogiStudentai);
    }
    catch (std::bad_alloc & ba)
    {

    }
    try {
        A.shrink_to_fit();
    }
    catch (std::bad_alloc & ba)
    {

    }
}
