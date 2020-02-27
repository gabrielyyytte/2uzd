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
#include "functions.h"
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

