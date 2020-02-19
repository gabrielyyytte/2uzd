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
int pasirinkimas ()
{
    int f;
    std::cout << "Jei norite ivesti duomenis ranka, spauskite 0, jei norite is tekstinio failo spauskite 1:" <<std::endl;
    std::cin >> f;
    return f;
}
int kiekis (int &k)
{
    std::cout<<"Iveskite zmoniu kieki"<<std::endl;
    std::cin>>k;
    while(std::cin.fail())
    {
        std::cout << "Privalote ivesti skaiciu, ne kitoki simboli! Pakartotinai iveskite zmoniu kieki" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >>k;
    }

    return k;
}
void vardaspavarde (int k, int & vidurkis)
{
    std::vector<studentas>A;
    std::cout << "Iveskite studento varda ir pavarde" <<std::endl;
    for (int i=0; i<k; i++)
    {
        vidurkis = 0;
        A.push_back(studentas());
        std::cout<<"Iveskite varda ir pavarde"<<std::endl;
        A.push_back(studentas());
        std::cin>>A[i].vardas>>A[i].pavarde;
    }
}
void rezultatai(std::vector<studentas>A, int i)
 {
    int nd; //laikinas kintamasis pazymiui irasyti i vektoriu

    std::cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0:" <<std::endl;

    do {
        std::cin >> nd;
        if (nd> 0 && nd < 11) {
            A[i].b.push_back(nd);
            A[i].vidurkis += nd;
        }

    } while (nd!= 0);

    std::cout << "Iveskite egzamino pazymi:" <<std::endl;
    std::cin >> A[i].egzaminas;
  //      A[i].vidurkis=vidurkis/n;
}


double rastimediana(int a[], int n)
{
    std::sort(a, a+n);
    if (n % 2 != 0)
        return (double)a[n/2];

    return (double)(a[(n-1)/2] + a[n/2])/2.0;
}

int main()
{
    void skaitymas (std::vector<studentas> &A, int &nr) {
    int y = 0;
    string temp;
    string eil, vard, pav;
    std::ifstream in_file("kursiokai.txt");

    int sk = 0;
    int h=0;

    while (std::getline(in_file, eil)) {
        while (!in_file.eof()){
            try {
                if (!in_file.good()){
                    throw "Failas neegzistuoja";
                }
            } catch (const char* msg){
                cout << msg << endl;
                break;
            }
        duomenys.push_back(mok());
        std::istringstream in_line(eil);
        in_line >> vard >> pav;
        duomenys[nr].vardas = vard;
        duomenys[nr].pavarde = pav;
        nr++;

        while (in_line >> temp) {
            int ivedu = std::stoi(temp); //pavercia string i integer
            if (ivedu >= 0 && ivedu <= 10) {
                duomenys[sk].nd.push_back(ivedu);
                duomenys[sk].sum+=ivedu;
                duomenys[sk].paz_sk++;
            }

        }
        sk++;

        in_line.end;

        int egz = 0;
        int y=0;

        egz = duomenys[h].nd[duomenys[h].paz_sk-1];
        duomenys[h].egz=egz;



        h++;
        duomenys[sk-1].nd[duomenys[sk-1].paz_sk-1]=0;
        duomenys[sk-1].sum=duomenys[sk-1].sum-duomenys[h-1].egz;
        duomenys[sk-1].paz_sk--; //sumazinamas pazymiu skaicius, nes skaiciuoja ir egzaminas
    }


}
    std::vector<studentas>A;
    srand ( time ( NULL ));
    int n, k, egz;
    double vid=0, vidurkis;

for (int i=0; i<k; i++)
{
    double mediana = rastimediana(A[i].nd, A[i].n);
    A[i].mediana = mediana;
}

std::cout << "Pavarde" <<std::right <<std::setw(20) << "Vardas" << std::right <<std::setw(20) << "Galutinis (Vid.)" << std::right <<std::setw(20) << "Galutinis (Med.)" <<std::endl;
std::cout << "------------------------------------------------------------------------" <<std::endl;

for (int i=0; i<k; i++)
    std::cout << A[i].pavarde << std::right <<std::setw(20) << A[i].vardas << std::right <<std::setw(20) << std::fixed << std::setprecision(2) << std::right <<0.4*A[i].vidurkis+0.6*A[i].egzaminas <<std::setw(20) << std::right <<0.4*A[i].mediana+0.6*A[i].egzaminas<<std::endl;

return 0;
}
