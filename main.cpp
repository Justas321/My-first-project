#include "mylib.h"
#include "struc.h"
#include "func.h"

double vid_med (char tikrinimas, vector <duom> stud, int laikinas, int kiek);
void Nuskaitymas(vector <duom> &stud, int &kiek, char tikrinimas);
void Isvedimas(vector <duom> stud, int kiek, char tikrinimas);
bool Palyginimas(duom pirmas, duom antras);

int main()
{
    int kiek=0;
  vector <duom> stud;
  char tikrinimas;
  cout<<"Jei norite studento galutini bala skaiciuoti naudojant mediana iveskite \"m\", o jei norite galutini bala skaiciuoti naudojant vidurki iveskite \"v\"\n";cin>>tikrinimas;
  while (tolower(tikrinimas) != 'v' && tolower(tikrinimas) != 'm') {
    cout<<"Turite ivesti \"v\" arba \"m\"!"<<endl;
    cin>>tikrinimas;
  }
  Nuskaitymas(stud, kiek, tikrinimas);
  sort(stud.begin(), stud.end(),Palyginimas);
  Isvedimas(stud, kiek, tikrinimas);
    return 0;
}
