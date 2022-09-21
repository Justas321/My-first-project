#include "mylib.h"

struct duom{
  string vardas;
  string pavarde;
  double pazymiai[20];
  int egzaminas;
};

duom ivedimas(int &n);
void isvedimas(duom laikinas, int n);
void mediana(duom temp, int n);

int main(){
  duom asmuo1, masyvas[25];
  int n, m;
  cout<<"Iveskite studentu kieki: "; cin>>n;
  for (int i=0;i<n;i++){
       masyvas[i]=ivedimas(m);
       isvedimas (masyvas[i], m);
    }
}

duom ivedimas(int &n){
    duom studentas;
    cout<<"Iveskite varda: "; cin>>studentas.vardas;
    cout<<"Iveskite pavarde: "; cin>>studentas.pavarde;
    srand(time(NULL));
    cout<<"Iveskite egzamino bala(Jei norite sugeneruoti atsitiktini egzamino bala, iveskite 20) : "; cin>>studentas.egzaminas;
    if(studentas.egzaminas==20)studentas.egzaminas=1+(rand()%10);

  //---- Dinaminis C masyvas

    /*int *p = new int[20];
    if(!p)cout << "allocation of memory failed\n";
    else {
        n=0;
        for(int kint=0;kint<20;kint++){
            cout<<"Iveskite "<<kint+1<<" semestro pazymi(Jei suvedete visus pazymius, iveskite 0): ";
            cin>>p[kint];
            if(p[kint]==0)break;
            else{
                studentas.pazymiai[kint]=p[kint];
                n++;
    }
  }
  }*/
    /*cout<<"Iveskite semestro pazymiu kieki:"; cin>>n;
    if (n <0 || n >=20) cin>>n;
    for (int kint=0;kint<n; kint++){
        cout<<"Iveskite "<<kint+1<<" pazymi: ";
        cin>>studentas.pazymiai[kint];
    }*/

    vector<int> v;
    v.reserve(50);
    n=0;
    for(int kint=0;kint<20;kint++){
        cout<<"Iveskite semestro pazymi(Jei suvedete visus pazymius, iveskite 11, o jeigu norite pazymi sugeneruoti atsitiktinai iveskite 20): ";
        cin>>v[kint];
        if(v[kint]==11)break;
        else if(v[kint]==20){
            studentas.pazymiai[kint]=1+(rand()%10);
        }
        else{
            studentas.pazymiai[kint] = v[kint];
        }
        n++;
        v.push_back(kint);
    }
    v.shrink_to_fit();
    //delete [] p;
    return studentas;
}

void mediana(duom temp,int n){
    int N = sizeof(temp.pazymiai)/sizeof(temp.pazymiai[0]);
    sort(temp.pazymiai,temp.pazymiai+n);
}

void isvedimas(duom laikinas, int n){

    cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(43)<<left<<"Galutinis (Vid.) / Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<left<<laikinas.vardas<<setw(20)<<left<<laikinas.pavarde;
    int suma = 0;
    for(int i=0;i<n;i++) suma = suma + laikinas.pazymiai[i];
    cout<<fixed<<setprecision(2)<<setw(20)<<left<<0.4*suma/n+0.6*laikinas.egzaminas;
    mediana(laikinas,n);
    if(n%2!=0)cout<<fixed<<setprecision(2)<<setw(23)<<left<<laikinas.pazymiai[(n-1)/2]<<endl;
    else cout<<fixed<<setprecision(2)<<setw(23)<<left<<(laikinas.pazymiai[n/2-1]+laikinas.pazymiai[n/2])/2<<endl;
}
