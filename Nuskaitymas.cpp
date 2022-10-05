#include "mylib.h"
#include "struc.h"
#include "func.h"

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
