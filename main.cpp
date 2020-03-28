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

int main()
{
    int k = 0;
    int p;
    char rusis;
    std::cout << "Jei norite generuoti 5 tekstinius failus, spauskite 5, jei norite duomenis ivesti pats arba nuskaityti is jau egzistuojancio failo, spauskite bet kuri kita skaiciu:" << std::endl;
    std::cin >> p;
    std::remove("silpnuoliai.txt");
    std::remove("kietiakai.txt");
    int nr = 100;
    int laikinas;

    if (p == 5)
    {

        std::cout << "Iveskite pirmaja raide konteinerio, kuri naudosite(vector - v, list - l, deque - d):" << std::endl;
        std::cin >> rusis;
        if (rusis == 'v')
        {

            std::vector<studentas> A, kieti;
            for (int i = 0; i < 5; i++)
            {
                nr = nr * 10;
                auto startas = std::chrono::system_clock::now();
                generacija_txt(i, nr);
                auto pabaiga = std::chrono::system_clock::now();
                auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                laikinas = i;
                std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                skaitymas_v(A, i);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                A.shrink_to_fit();
                startas = std::chrono::system_clock::now();
                rusiavimas_v(A, kieti);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                spausdinimasrez_v(kieti, A, i);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
            }
        }
        else if (rusis == 'l')
        {

            std::list<studentas> A, kieti;
            for (int i = 0; i < 5; i++)
            {
                nr = nr * 10;
                auto startas = std::chrono::system_clock::now();
                generacija_txt(i, nr);
                auto pabaiga = std::chrono::system_clock::now();
                auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                laikinas = i;
                std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                skaitymas_l(A, i);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                rusiavimas_l(A, kieti);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                spausdinimasrez_l(kieti, A, i);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
            }
        }
        else if (rusis == 'd')
        {

            std::deque<studentas> A, kieti;
            for (int i = 0; i < 5; i++)
            {
                nr = nr * 10;
                auto startas = std::chrono::system_clock::now();
                generacija_txt(i, nr);
                auto pabaiga = std::chrono::system_clock::now();
                auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                laikinas = i;
                std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                skaitymas_d(A, i);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                A.shrink_to_fit();
                startas = std::chrono::system_clock::now();
                rusiavimas_d(A, kieti);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                startas = std::chrono::system_clock::now();
                spausdinimasrez_d(kieti, A, i);
                pabaiga = std::chrono::system_clock::now();
                uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
            }
        }
    }

    std::vector<studentas> A, kieti;
    if (p == 5)
        return 0;

    int did_vard = 0;
    int did_pav = 0;
    double med;
    if (p != 5)
    {
        int m = 0;
        const int a = pasirinkimas();
        if (a == 0)
        {
            int i;
            int n = kiekis(k);
            for (i = 0; i < n; i++)
            {
                A.push_back(studentas());
                ivedimas(A, i);
                int b = pasirinkimas2();
                if (b == 0)
                {
                    generacija(A, i);
                }
                else
                {
                    rezultatai(A, i);
                }
            }
            remelis();
            for (int i = 0; i < n; i++)
            {
                rikiavimas(A, n);
                spausdinimas(A, i, did_vard, did_pav);
            }
        }

        else
        {
            int nr = 0;
            skaitymas(A, nr);
            for (int i = 0; i < nr; i++)
            {
                if (i == 0)
                    remelis();
                rikiavimas(A, nr);
                spausdinimas(A, i, did_vard, did_pav);
            }
        }
        return 0;
    }
}
