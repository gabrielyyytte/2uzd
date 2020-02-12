#include <iostream>
#include <iomanip>
int main()
{
    std::string vardas, pavarde;
    int n, k, vidurkis=0;
    double nd, egz, galutinis;
    std::cout<<"Iveskite zmoniu kieki"<<std::endl;
    std::cin>>k;
    for (int j=0; j<k; j++)
    {
        std::cout<<"Iveskite varda ir pavarde"<<std::endl;
        std::cin>>vardas>>pavarde;
        std::cout<<"Iveskite namu darbu kieki"<<std::endl;
        std::cin>>n;
        std::cout<<"Iveskite namu darbu rezultatus"<<std::endl;
        for (int i=0; i<n; i++)
        {
            std::cin>>nd;
            vidurkis+=nd;
        }
        std::cout<<"Iveskite egzamino rezultata"<<std::endl;
        std::cin>>egz;
        std::cout<<"------------------------------------------"<<std::endl;
    }


    std::cout<<"Pavarde"<<std::setw(15) <<"Vardas"<<std::setw(25) <<"Galutinis (vid.)"<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
    std::cout<<pavarde<<std::setw(16) <<vardas<<std::setw(17) <<0.4*vidurkis/n+0.6*egz<<std::endl;



}
