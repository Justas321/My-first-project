# 1-oji užduotis
# v1.0
#### Programos papildymas
```diff
+ Pridėta antra vector ir list strategija, kuomet rūšiavimas vyksta panaudojant tik vieną naują konteinerį "vargšiukai", tokiu atveju vienas studentas yra tik viename faile
- Panaikintas failų nuskaitymo ir surušiavimo trukmės bei bendro laiko naudojant list ir vector struktūras lyginimas
```
## Testavimo rezultatai:
![1k](https://user-images.githubusercontent.com/113771423/201479142-aa54d212-f748-47d3-96a6-ae3f80c9bfd1.png)  
![10k](https://user-images.githubusercontent.com/113771423/201479145-de8fff28-6186-4507-90e7-ba22240e5f15.png)  
![100k](https://user-images.githubusercontent.com/113771423/201479147-1210f9bf-bd96-4d9e-afbd-f7b5cdcd845e.png)  
![1m](https://user-images.githubusercontent.com/113771423/201479153-a1cb1215-06ec-457a-95e3-e4c03297c591.png)  
![10m](https://user-images.githubusercontent.com/113771423/201479158-b23931df-7529-49a5-aea3-c1d2db1f52e3.png)  
# v0.4
#### Programos papildymas
```diff
+ Lyginama failų nuskaitymo ir surūšiavmo trukmė bei bendras laikas naudojant list ir vector struktūras
```
## Kompiuterio parametrai: 
* CPU: Intel(R) Core(TM) i7-8750H CPU @ 2.20GHz
* RAM: 16.0 GB
* HDD: TOSHIBA MQ04ABF100 1TB
* SSD: HYNIX HFS128G39TND-N210A 128GB
## Testavimo rezultatai:
![1000](https://user-images.githubusercontent.com/113771423/199517022-79109dfe-419d-4de4-bc50-366cdd14b5d6.png)
![10k](https://user-images.githubusercontent.com/113771423/199517038-106ecf72-f559-479d-8e27-5deb2d9bf91b.png)
![100k](https://user-images.githubusercontent.com/113771423/199517120-804e509a-9be2-4d93-a051-e61e00e93050.png)
![1m](https://user-images.githubusercontent.com/113771423/199517137-b9368ff3-93aa-40e9-b2c0-5b79fea78546.png)
![10m](https://user-images.githubusercontent.com/113771423/199517150-462631ee-d5a0-4902-971b-3a5a7891a849.png)
# v0.3
#### Programos papildymas
```diff
+ Programa sugeneruoja 5 failus su 1 000, 10 000, 100 000, 1 000 000, 10 000 000 duomenų
+ Studentai surušiuojami į 2 failus - vargšiukus ir galvočius pagal jų galutinį balą, jei balas < 5, studentai atsidurs vargšiukų faile, o jei galutinis balas >= 5, tuomet studentai bus įrašyti į galvočių failą
+ Skaičiuojamas užtruktas programos laikas generuojant skirtingo dydžio failus, juos nuskaitant, rūšiuojant bei išvedant
```
# v0.2
***Programa perdaryta iš pagrindų dėl kilusių klaidų***
```diff
- Iš programos pašalintas darbas su ekranu
```
#### Programos papildymas
```diff
+ Naudotojas pasirenka kaip bus skaičiuojamas galutinis studento balas, naudojant medianą ar naudojant vidurkį
+ Studento vardas, pavardė, egzamino rezultatas ir namų darbų pažymiai nuskaitomi iš failo
+ Studento vardas, pavardė, galutinis rezultatas, suskaičiuotas pagal medianą arba vidurkį pasirinktinai, išvedamas i rezultatų failą
```
# v0.1
#### Programos veikimas
```diff
+ Naudotojo prašoma įvesti studento vardą ir pavardę
+ Naudotojas pasirenka ar egzamino balą įves pats, ar jį sugeneruos atsitiktinai
+ Naudotojas yra paprašomas įvesti arba atsitiktinai sugeneruoti namų darbų pažymį, suvedus arba sugeneravus visus pažymius įvedamas nurodytas skaičius užbaigti šiai programos daliai
+ Naudotojui ekrane išvedama lentelė, kurioje yra studento vardas, pavardė, galutinis pažymys suskaičiuotas pagal vidurkį bei galutinis pažymys suskaičiuotas pagal medianą
```
