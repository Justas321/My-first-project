#include "mylib.h"
#include "struc.h"

double vid_med (char tikrinimas, vector <duom> stud, int laikinas, int kiek)
{
  double vid;
  if (tolower(tikrinimas) == 'v') {
    if (stud[kiek].pazymiai.size() == 0) vid = 0;
    else vid = double(laikinas) / double(stud[kiek].paz_sk);
  }
  else
  {
    if (stud[kiek].pazymiai.size() == 0)
    {
      vid = 0;
    }
    else{
      sort(stud[kiek].pazymiai.begin(), stud[kiek].pazymiai.end());
      if (stud[kiek].paz_sk % 2 == 0)
      {
          vid = (stud[kiek].pazymiai[stud[kiek].paz_sk / 2 - 1] + stud[kiek].pazymiai[stud[kiek].paz_sk / 2]) / 2;
      }
      else
      {
          vid = stud[kiek].pazymiai[stud[kiek].paz_sk / 2];
      }
    }

  }
  stud[kiek].galutinis = vid * 0.4 + (double)stud[kiek].egzaminas * 0.6;
  return stud[kiek].galutinis;
}

void Nuskaitymas(vector <duom> &stud, int &kiek, char tikrinimas)
{
    try
    {
      float paz, s;
      ifstream df;
      df.open("Studentai10000.txt");
      string eil;
      if (df.is_open())
      {
        int sk;
        getline(df >> ws, eil);
        stringstream stream(eil);
        sk = (distance(istream_iterator<string>(stream), istream_iterator<string>())) - 3;
        while (true)
        {
          stud.resize(stud.size() + 1);
          df >> stud.at(kiek).vardas;
          if (df.eof()) { stud.pop_back(); break;}
          df >> stud.at(kiek).pavarde;
          stud.at(kiek).paz_sk=sk;
          s=0;
          for (int i = 0; i < stud.at(kiek).paz_sk; i++)
          {
            df >> paz;
            s+=paz;
            stud.at(kiek).pazymiai.push_back(paz);
          }
          df >> stud.at(kiek).egzaminas;
          stud[kiek].galutinis = vid_med(tikrinimas, stud, s, kiek);
          kiek++;
        }
      }
      df.close();
    }
    catch(const exception& e){
     cout << "Failo nuskaityti nepavyko arba failas jau nuskaitytas" << endl;
  }
}

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

bool Palyginimas(duom pirmas, duom antras)
{
    if (pirmas.vardas != antras.vardas)
        return pirmas.vardas > antras.vardas;
    if (pirmas.pavarde != antras.pavarde)
        return pirmas.pavarde > antras.pavarde;
    return pirmas.galutinis > antras.galutinis;
}
