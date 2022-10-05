#include "mylib.h"
#include "struc.h"
#include "func.h"

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
