# Antroji ISI 1 kurso objektinio programavimo užduotis
Ši programa suskaičiuoja bei išveda studentų vidurkius arba medianą.

# Programos naudojimas
## v0.1 versijos paleidimas
Programą sudaro du .cpp failai, viename atlikta programa su C kalbos masyvais, kita su STD bibliotekos vektoriais.
- Paleiskite vieną iš pasirinktų .cpp failų per IDE programą, turinčią G++ kompiliatorių.
## v0.2 versijos paleidimas
- Paleiskite main.cpp failą su IDE programa, turinčia G++ kompiliatorių.
## v0.3 versijos paleidimas
- Naudokite komandine eilute ir makefile (v0.3.1).
  Per terminalą atsidarykite projekto aplanką ir veskite komandas iš eilės po vieną: 
  ```
  make
  ./main
  ```
- Pagal aprašytus programos nurodymus pasirinkite norimus parametrus.
## v0.4 versijos paleidimas
- Paleiskite terminalą ir atsidarykite jame projekto aplanką.
- Į terminalą veskite komandas paeiliui: 
  ```
  make test
  ./main
  ```
## v0.5 versijos paleidimas
- Paleiskite terminalą ir atsidarykite jame projekto aplanką.
- Į terminalą įveskite komandas paeiliui:
```
make test2
./main
```
## v1.0 versijos paleidimas
- Paleiskite terminalą ir atsidarykite jame projekto aplanką.
- Į terminalą įveskite komandas paeiliui:
```
make test2
./main
```


# Programos išleidimai
## 1. [v0.1.1 programos versija](https://github.com/Matas86/AntrojiUzduotis/releases/tag/v0.1.1)
- Ši programa leidžia naudojantis tiek masyvais, tiek vektoriais apskaičiuoti ir gauti studentų pažymių vidurkius arba medianą.
- Programa leidžia arba atsitiktinai generuoti, arba įvesti kiekvieno studento pažymius ranka.
- Programa leidžia pasirinkti ar norite gauti medianą, ar pažymių vidurkį pagal formulę.
## 2. [v0.2.1 programos versija](https://github.com/Matas86/AntrojiUzduotis/releases/tag/v0.2.1)
- Ši programos versija leidžia naudotojui pateikti kursiokai.txt duomenų failą ir pateikti duomenis būtent tame faile
- Pateikti duomenis ranka
- Gauti rezultatus komandinėje eilutėje arba rezultatų faile atsakymai.txt
## 3. [v0.3.1 programos versija](https://github.com/Matas86/AntrojiUzduotis/releases/tag/v0.3.1)
- Ši programos versija leidžia naudotojui pateikti savo duomenų failą ir įvesti jo pavadinimą
- Programa yra atskirta į .cpp ir .h failus
- Sukurtas makefile ir pilnai funkcionuojantis sukonfiguruotas make failas kiekvieną kartą atnaujinamas, jeigu .cpp ar .h failai yra atnaujinami paleidus komandą make.
## 4. [v0.4.1 programos versija](https://github.com/Matas86/AntrojiUzduotis/releases/tag/v0.4.1)
- Ši programos versija leidžia vartotojui generuoti atsitiktinius duomenis į naujus failus pavadinimais studentai1000, studentai10000 ir t.t.
- Ši programos versija rūšiuoja studentus pagal jų vidurkį atitinkamai virš 5 balų bei žemiau.
- Atskiras dvi studentų grupes išveda į du atskirus duomenų failus.
- Matuoja kiekvieno proceso testavimo metu laiko sąnaudas.
#Testavimo laikai
![Testo 1 laikai](https://i.imgur.com/uMCOVSg.png)
![Testo 2 laikai](https://i.imgur.com/vPU36D7.png)
![Testo 3 laikai](https://i.imgur.com/nm5V6Po.png)
![Testo 4 laikai](https://i.imgur.com/M0rVJzJ.png)
![Testo 5 laikai](https://i.imgur.com/DxxCXr9.png)
## 5. [v0.5 programos versija](https://github.com/Matas86/AntrojiUzduotis/releases/tag/v0.5)
- Ši programos versija leidžia vartotojui paleisti testinę programos versija, kurioje sugeneruojami atsitiktiniai duomenys į duomenų failus studentai1000, studentai10000 ir t.t.
- Ši programos versija ištestuoja failų nuskaitymo, stundetų atskyrimo bei studentų išrikiavimo laikus naudojant tris skirtingus konteinerius - vector, list ir deque.
- Atskirų studentų grupių neišveda į duomenų failus, kadangi svarbiausia yra testavimo laikai.
# Testavimo laikai 
![Testo laikai](https://i.imgur.com/lFcy8sH.png)
## 6. [v1.0 programos versija](https://github.com/Matas86/AntrojiUzduotis/releases/tag/v1.0)
- Ši programos versija leidžia vartotojui paleisti testinę programos versiją, kurioje sugeneruojami atsitiktiniai duomenys į duomenų failus studentai1000, studentai10000 ir t.t.
- Ši programos versija ištestuoja nuskaitytų iš duomenų failų į tris atskirus konteinerius atskyrimą dviem būdais, nurodytais užduoties sąlygoje.
- Atskirų studentų grupių neišveda į duomenų failus, kadangi svarbiausia yra testavimo laikai.
# Testavimo laikai 
![Testo laikai](https://i.imgur.com/UEoBCVy.png)
# Testavimui panaudoto kompiuterio specifikacijos:
- Intel i7 3770k boosted to 3,9GHz (8 cores)
- 8GB DDR3 1600MHz
- SATA3 SSD (550/450MB/s)
