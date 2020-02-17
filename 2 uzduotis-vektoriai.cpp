#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <time.h>
#include <ctype.h>
#include <algorithm>

struct studentas
{
    std::string vardas;
    std::string pavarde;
    double galutinis=0;
    double mediana=0;
    double vidurkis=0;
    int egzaminas;
    int nd[100];
    std::vector <int> b;
    int n;
};

double findMedian(int a[], int n)
{
    std::sort(a, a+n);
    if (n % 2 != 0)
        return (double)a[n/2];

    return (double)(a[(n-1)/2] + a[n/2])/2.0;
}

int main()
{
    srand ( time ( NULL ));

    int n, k, egz, vidurkis;
    double vid=0;
    std::cout<<"Iveskite zmoniu kieki"<<std::endl;
    std::cin>>k;
    while(std::cin.fail())
    {
        std::cout << "Privalote ivesti skaiciu, ne kitoki simboli! Pakartotinai iveskite zmoniu kieki" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >>k;
    }
    std::vector <studentas> A;

    for (int i=0; i<k; i++)
    {
        vidurkis = 0;
        A.push_back(studentas());
        std::cout<<"Iveskite varda ir pavarde"<<std::endl;
        A.push_back(studentas());
        std::cin>>A[i].vardas>>A[i].pavarde;
        std::cout<<"Iveskite namu darbu kieki"<<std::endl;
        std::cin>>n;
        while(std::cin.fail())
        {
            std::cout << "Privalote ivesti skaiciu, ne kitoki simboli! Pakartotinai iveskite namu darbu kieki" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >>n;
        }
        A[i].n = n;


label:
        int a;
        std::cout << "Jei norite namu darbu rezultatus generuoti automatiskai spauskite 0. Jei norite ivesti patys spauskite 1:" <<std::endl;
        std::cin >> a;
        if (a==1)
        {
            std::cout << "Iveskite namu darbu rezultatus" <<std::endl;
            for (int j=0; j<n; j++)
            {
                std::cin>>A[i].nd[j];
                vidurkis+=A[i].nd[j];
                if (A[i].nd[j]<=0 or A[i].nd[j]>10)
                {
                    std::cout << "Namu darbo rezultatas turi buti daugiau nei 0, bet daugiausiai 10"<<std::endl;
                    std::cout << "-----------------------------------------------------------------"<<std::endl;
                    goto label;
                }
            }
        }
        else
            for (int j = 0; j < n; j++)
            {
                A[i].nd[j]=rand()%10;
                std::cout << A[i].nd[j] <<std::endl;
                vidurkis+=A[i].nd[j];
            }
        if (n>0)
            A[i].vidurkis=vidurkis/n;
        else
            A[i].vidurkis =0;

label2:
        int e;
        std::cout << "Jei norite egzamino rezultata generuoti automatiskai spauskite 0. Jei norite ivesti patys spauskite 1:" <<std::endl;
        std::cin >> e;
        if (e==1)
        {
            std::cout<<"Iveskite egzamino rezultata"<<std::endl;
            std::cin>>egz;
            while(std::cin.fail())
            {
                std::cout << "Privalote ivesti skaiciu, ne kitoki simboli! Pakartotinai iveskite egzamino rezultata" << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >>egz;
            }
            if (egz<=0 or egz>10)
            {
                std::cout << "Namu darbo rezultatas turi buti daugiau nei 0, bet daugiausiai 10"<<std::endl;
                std::cout << "-----------------------------------------------------------------"<<std::endl;

                goto label2;
            }
            else A[i].egzaminas = egz;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                egz=rand()%10+1;
            }
            std::cout <<egz<<std::endl;
            A[i].egzaminas = egz;
        }
    }

    for (int i=0; i<k; i++)
    {
        double mediana = findMedian(A[i].nd, A[i].n);
        A[i].mediana = mediana;
    }

    std::cout << "Pavarde" <<std::right <<std::setw(20) << "Vardas" << std::right <<std::setw(20) << "Galutinis (Vid.)" << std::right <<std::setw(20) << "Galutinis (Med.)" <<std::endl;
    std::cout << "------------------------------------------------------------------------" <<std::endl;

    for (int i=0; i<k; i++)
        std::cout << A[i].pavarde << std::right <<std::setw(20) << A[i].vardas << std::right <<std::setw(20) << std::fixed << std::setprecision(2) << std::right <<0.4*A[i].vidurkis+0.6*A[i].egzaminas <<std::setw(20) << std::right <<0.4*A[i].mediana+0.6*A[i].egzaminas<<std::endl;

    return 0;
}

