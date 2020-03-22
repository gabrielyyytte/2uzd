#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
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
    std::deque<studentas> A, kieti;
    int k = 0;
    int p;
    std::cout << "Jei norite generuoti 5 tekstinius failus, spauskite 5, jei norite duomenis ivesti pats arba nuskaityti is jau egzistuojancio failo, spauskite bet kuri kita skaiciu:" << std::endl;
    std::cin >> p;
    std::remove("silpnuoliai.txt");
    std::remove("kietiakai.txt");
    int nr = 100;
    int laikinas;

    if (p == 5)
    {

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
            skaitymas_gen(A, i);
            pabaiga = std::chrono::system_clock::now();
            uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
            std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
            startas = std::chrono::system_clock::now();
            rusiavimas(A, kieti);
            pabaiga = std::chrono::system_clock::now();
            uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
            std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
            startas = std::chrono::system_clock::now();
            spausdinimasrez(kieti, A, i);
            pabaiga = std::chrono::system_clock::now();
            uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
            std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
        }
    }

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
                rastimediana(A, i);
                vidurkis(A, i);
                if (i == 0)
                    remelis();
                rikiavimas(A, nr);
                spausdinimas(A, i, did_vard, did_pav);
            }
        }
        return 0;
    }
}
