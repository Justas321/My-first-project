#include "mylib.h"

struct duom{
  string vardas;
  string pavarde;
  double pazymiai[20];
  int egzaminas;
};

duom ivedimas(int &n);
void isvedimas(duom laikinas, int n);
void rusiavimas(duom temp, int n);

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
    cout<<"Iveskite egzamino bala(Jei norite sugeneruoti atsitiktini egzamino bala, iveskite 11) : "; cin>>studentas.egzaminas;
    while(studentas.egzaminas>11 || studentas.egzaminas<0){cout<<"Iveskite skaiciu nuo 1 iki 10, arba iveskite 11, jei norite bala sugeneruoti atsitiktinai "<<endl; cin>>studentas.egzaminas;}
    if(studentas.egzaminas==11)studentas.egzaminas=1+(rand()%10);

  //---- Dinaminis C masyvas

    /*int *p = new int[20];
    if(!p)cout << "allocation of memory failed\n";
    else {
        n=0;
        for(int kint=0;kint<20;kint++){
            cout<<"Iveskite "<<kint+1<<" semestro pazymi(Jei suvedete visus pazymius, iveskite 11, o jeigu norite pazymi sugeneruoti atsitiktinai iveskite 12): ";
            cin>>p[kint];
            while(p[kint]>12 || p[kint]<0){cout<<"Iveskite skaiciu nuo 1 iki 10, arba iveskite 11, jei suvedete visus pazymius, jeigu norite pazymi generuoti atsitiktinai iveskite 12 "<<endl; cin>>p[kint];}
            if(p[kint]==11)break;
            else if(p[kint]==12){
                studentas.pazymiai[kint]=1+(rand()%10);
        }
            else{
                studentas.pazymiai[kint]=p[kint];
    }
    n++;
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
        cout<<"Iveskite "<<kint+1<<" semestro pazymi(Jei suvedete visus pazymius, iveskite 11, o jeigu norite pazymi sugeneruoti atsitiktinai iveskite 12): ";
        cin>>v[kint];
        while(v[kint]>12 || v[kint]<0){cout<<"Iveskite skaiciu nuo 1 iki 10, arba iveskite 11, jei suvedete visus pazymius, jeigu norite pazymi generuoti atsitiktinai iveskite 12 "<<endl; cin>>v[kint];}
        if(v[kint]==11)break;
        else if(v[kint]==12){
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

void rusiavimas(duom temp,int n){
    sort(temp.pazymiai,temp.pazymiai+n);
}

void isvedimas(duom laikinas, int n){

    cout<<setw(20)<<left<<"Vardas"<<setw(20)<<left<<"Pavarde"<<setw(43)<<left<<"Galutinis (Vid.) / Galutinis (Med.)"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout<<setw(20)<<left<<laikinas.vardas<<setw(20)<<left<<laikinas.pavarde;
    int suma = 0;
    for(int i=0;i<n;i++) suma = suma + laikinas.pazymiai[i];
    cout<<fixed<<setprecision(2)<<setw(20)<<left<<0.4*suma/n+0.6*laikinas.egzaminas;
    rusiavimas(laikinas,n);
    if(n%2!=0)cout<<fixed<<setprecision(2)<<setw(23)<<left<<laikinas.pazymiai[(n-1)/2]<<endl;
    else cout<<fixed<<setprecision(2)<<setw(23)<<left<<(laikinas.pazymiai[n/2-1]+laikinas.pazymiai[n/2])/2<<endl;
}
