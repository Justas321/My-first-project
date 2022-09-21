#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int n,i,j,daug,indeks;
    double mokestis[101]; double dienos[101]; double viso;
    string vardai[101];
    ifstream df ("gyven.txt");
    ofstream rf ("gyvrez.txt");
    viso=0; daug=0;
    df>>n;
    for(i=1;i<=n;i++)
    {
        df>>vardai[i]>>mokestis[i]>>dienos[i];
        viso=viso+dienos[i];
    }
    df.close();
    int nuo;
    for(i=1;i<=n;i++)
    {
        nuo=i;
        for(j=1;j<=n;j++)
        {
            nuo=j;
        }
        swap(mokestis[nuo],mokestis[i]);
        swap(vardai[nuo],vardai[i]);
        swap(dienos[nuo],dienos[i]);
    }
    for(i=1;i<=n;i++)
        if(dienos[i]>daug)
    {
        daug=dienos[i];
        indeks=i;
    }
    for(i=1;i<=n;i++)
    rf<<left<<setw(10)<<vardai[i]<<mokestis[i]<<" "<<dienos[i]<<endl;
    rf<<"Vidutiniskai: "<<fixed<<setprecision(1)<<viso/n<<endl;
    rf<<"Ilgiausiai: "<<vardai[indeks]<<", "<<dienos[indeks]<<" dienu"<<endl;



    return 0;
}
