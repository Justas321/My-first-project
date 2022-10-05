#include "mylib.h"
#include "struc.h"
#include "func.h"

void Isvedimas(vector <duom> stud, int kiek, char tikrinimas) {
  ofstream rf;
  rf.open("rezultatai.txt");
  rf<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(18)<<left<<"Galutinis(vid.)/"<<left<<"Galutinis(med.)\n"<< "--------------------------------------------------------------------------\n";
  for (int i=0; i<kiek;i++)
  {
      rf<<setw(20)<<left<<stud[i].vardas<<setw(20)<<left<<stud[i].pavarde<<fixed<<setprecision(2)<<setw(18)<<left<<stud[i].galutinis<<endl;
  }
  rf.close();
}
