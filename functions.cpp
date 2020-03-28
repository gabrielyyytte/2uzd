#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <list>
#include <deque>
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
    std::vector<int> HW;
    int b, egz;
    std::cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0" << std::endl;
    do
    {
        std::cin >> b;
        if (b > 0 && b < 11)
        {
            HW.push_back(b);
        }
    } while (b != 0);
    std::cout << "Iveskite egzamino pazymi" << std::endl;
    std::cin >> egz;
    A[i].egz = Galutinis(HW, egz);
    std::cout << "----------------------------------------" << std::endl;
}

bool skaicius(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
void generacija(std::vector<studentas>& A, int i)
{
    int kiek;
    int laik, egz;
    std::vector<int> HW;
    std::cout << "Kiek skaiciu norite generuoti?" << std::endl;
    std::cin >> kiek;

    srand(time(NULL));
    std::cout << "Jusu rezultatai:" << std::endl;
    for (int j = 0; j < kiek; j++)
    {
        laik = rand() % 10 + 1;
        HW.push_back(laik);
        std::cout << laik << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    laik = rand() % 10 + 1;
    egz = laik;
    A[i].egz = Galutinis(HW, egz);
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
    std::cout << "Pavarde" << std::right << std::setw(20) << "Vardas" << std::right << std::setw(20) << "Galutinis (Vid.)" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
}

void spausdinimas(std::vector<studentas>& A, int i, int did_vard, int did_pav)
{
    std::cout << std::left << std::setw(did_pav + 15) << A[i].pavarde;
    std::cout << std::left << std::setw(did_vard + 15) << A[i].vardas;
    std::cout << std::left << std::setw(did_vard + 15) << A[i].egz;
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
    std::vector<int> HW;
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


        while (in_line >> temp)
        {
            int ivedu = std::stoi(temp);
            if (ivedu >= 0 && ivedu <= 10)
            {
                HW.push_back(ivedu);
            }
            s++;
            in_line.end;
            egz = HW.size() - 1;
            HW.erase(HW.end());
        }
        A[nr].egz = Galutinis(HW, egz);
        nr++;
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
double vidurkis(std::vector<int>& HW, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += HW[i];
    return (sum / n);
}
double Galutinis(std::vector<int>& HW, int egz)
{
    double hw;
    if (!HW.empty())
        hw = vidurkis(HW, HW.size());
    else hw = 0;
    return (0.4 * hw + 0.6 * egz);
}
void skaitymas_v(std::vector<studentas>& A, int& i)
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
        int tempHW, egz;
        std::string row;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row)) {
            dataRow.clear();
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            HW.clear();
            for (int i = 0; i < nr; i++) {
                dataRow >> tempHW;
                HW.push_back(tempHW);
            }
            dataRow >> egz;
            laikinas.egz = Galutinis(HW, egz);
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

void skaitymas_l(std::list<studentas>& A, int& i)
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
        int tempHW, egz;
        std::string row;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row)) {
            dataRow.clear();
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            HW.clear();
            for (int i = 0; i < nr; i++) {
                dataRow >> tempHW;
                HW.push_back(tempHW);
            }
            dataRow >> egz;
            laikinas.egz = Galutinis(HW, egz);
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

void skaitymas_d(std::deque<studentas>& A, int& i)
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
        int tempHW, egz;
        std::string row;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row)) {
            dataRow.clear();
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            HW.clear();
            for (int i = 0; i < nr; i++) {
                dataRow >> tempHW;
                HW.push_back(tempHW);
            }
            dataRow >> egz;
            laikinas.egz = Galutinis(HW, egz);
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

void spausdinimasrez_v(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& i)
{
    std::string kietieji = "kietiakai" + std::to_string(i) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(i) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::app);
    std::ofstream silpnuFailas(silpnieji, std::ios::app);
    for (int i = 0; i < kieti.size(); i++)
    {
        kietuFailas << kieti[i].vardas << " " << kieti[i].pavarde << " " << kieti[i].egz << std::endl;
    }
    for (int i = 0; i < silpni.size(); i++)
    {
        silpnuFailas << silpni[i].vardas << " " << silpni[i].pavarde << " " << silpni[i].egz << std::endl;
    }
    kietuFailas.close();
    silpnuFailas.close();
}


void spausdinimasrez_l(std::list<studentas>& kieti, std::list<studentas>& silpni, int& i)
{
    std::string kietieji = "kietiakai" + std::to_string(i) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(i) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::app);
    std::ofstream silpnuFailas(silpnieji, std::ios::app);
    int nr = 0;
    for (std::list<studentas>::iterator it = kieti.begin(); it != kieti.end(); ++it)
    {
        kietuFailas << it->vardas << " " << it->pavarde << " " << it->egz << std::endl;
        nr++;
    }
    nr = 0;
    for (std::list<studentas>::iterator it = silpni.begin(); it != silpni.end(); ++it)
    {
        silpnuFailas << it->vardas << " " << it->pavarde << " " << it->egz << std::endl;
        nr++;
    }
    kietuFailas.close();
    silpnuFailas.close();
}


void spausdinimasrez_d(std::deque<studentas>& kieti, std::deque<studentas>& silpni, int& i)
{
    std::string kietieji = "kietiakai" + std::to_string(i) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(i) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::app);
    std::ofstream silpnuFailas(silpnieji, std::ios::app);
    for (int i = 0; i < kieti.size(); i++)
    {
        kietuFailas << kieti[i].vardas << " " << kieti[i].pavarde << " " << (double)kieti[i].egz << std::endl;
    }
    for (int i = 0; i < silpni.size(); i++)
    {
        silpnuFailas << silpni[i].vardas << " " << silpni[i].pavarde << " " << (double)silpni[i].egz << std::endl;
    }
    kietuFailas.close();
    silpnuFailas.close();
}

void rusiavimas_v(std::vector<studentas>& A, std::vector<studentas>& kieti)
{

    std::sort(A.begin(), A.end(), [](studentas& s1, studentas& s2) {return s1.egz < s2.egz; });

    int sil = 0;
    while (A[sil].egz < 5.0 && sil != A.size()) {
        sil++;
    }


    kieti.reserve(A.size() - sil);
    std::copy(A.begin() + sil, A.end(), std::back_inserter(kieti));

    A.resize(sil);
    A.shrink_to_fit();
}

void rusiavimas_l(std::list<studentas>& A, std::list<studentas>& kieti)
{
    int blogiStudentai = 0;
    for (std::list<studentas>::iterator it = A.begin(); it != A.end(); ++it)
    {
        if (it->egz < 5.0)
            blogiStudentai++;
    }

    try {
        kieti.assign(std::next(A.begin(), blogiStudentai), A.end());
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
}

void rusiavimas_d(std::deque<studentas>& A, std::deque<studentas>& kieti)
{
    std::sort(A.begin(), A.end(), [](studentas& s1, studentas& s2) {return s1.egz < s2.egz; });

    int sil = 0;
    while (A[sil].egz < 5.0 && sil != A.size())
        sil++;

    std::copy(A.begin() + sil, A.end(), std::back_inserter(kieti));

    A.resize(sil);
    A.shrink_to_fit();
}
