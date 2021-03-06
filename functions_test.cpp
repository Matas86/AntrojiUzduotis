#include "functions_test.h"
#include "student_test.h"

#include <iostream>
#include <iomanip>
#include <chrono>

void StartProgram()
{
    srand(time(NULL));

    std::string failas;
    std::cout<<"Ar duomenys bus nuskaitomi is duomenu failo? (taip - y, ne - n) \n";
    while(!(std::cin >> failas))
    {
        std::cout << "Bloga ivestis! Iveskite savo varda";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\n";
    }
    if(failas == "y")
    {

        std::vector <student> stud;
        stud.reserve(100000);
        //Skaityk(stud);
        //Isvesk(stud);
    }
    else
    {
        int N;

        std::cout<<"Iveskite studentu skaiciu: \n";
        while(!(std::cin >> N) || N<0)
        {
            std::cout << "Bloga ivestis! Iveskite studentu skaiciu skaitmeniu";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\n";
        }

        std::vector<student> stud;
        stud.reserve(100000);
        std::string randomas;
        for(int i=0; i<N; i++)
        {
            std::cout<<"Ar norite, kad studento pazymiai butu generuojami atsitiktinai? (taip - y, ne - n)"<<std::endl;
            while(!(std::cin >> randomas))
            {
                std::cout << "Bloga ivestis! Iveskite savo varda";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\n";
            }
            if(randomas == "y")
                stud[i].random = true;
            else
                stud[i].random = false;

            if(!stud[i].random)
        {
            student currentStud;
            std::cout<<"Iveskite savo varda: \n";
            while(!(std::cin >> currentStud.name))
            {
                std::cout << "Bloga ivestis! Iveskite savo varda";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\n";
            }

            std::cout<<"Iveskite savo pavarde: \n";
            while(!(std::cin >> currentStud.surname))
            {
                std::cout << "Bloga ivestis! Iveskite savo pavarde";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\n";
            }

            int skc;
            bool veda;
            std::string ats;
            skc = 0;
            veda = true;
            int skaicius;
            while(veda)
            {
                std::cout<<"Iveskite savo " << skc+1 << " namu darbu bala: \n";

                while(!(std::cin >> skaicius || skaicius>10 || skaicius<0))
                {
                    std::cout << "Bloga ivestis! Iveskite savo namu darbu bala skaiciumi (0-10)";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    std::cout<<"\n";
                }
                currentStud.homeworkSum += skaicius;
                skc++;
                currentStud.homework.push_back(skaicius);
                std::cout<<"Ar norite toliau vesti namu darbu balus? (taip - y, ne - n) \n";
                std::cin>>ats;
                if(ats == "n")
                {
                    veda=false;
                }
                
            }



            std::cout<<"Iveskite savo egzamino bala: \n";
            while(!(std::cin >> currentStud.exam) || currentStud.exam >10 || currentStud.exam<0)
            {
                std::cout << "Bloga ivestis! Iveskite savo egzamino bala skaiciumi (0-10)";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout<<"\n";
            }
            stud.push_back(currentStud);
        }
        else
        {
            student currentStud;
            std::cout<<"Iveskite savo varda: \n";
        while(!(std::cin >> currentStud.name))
        {
            std::cout << "Bloga ivestis! Iveskite savo varda";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\n";
        }

        std::cout<<"Iveskite savo pavarde: \n";
        while(!(std::cin >> currentStud.surname))
        {
            std::cout << "Bloga ivestis! Iveskite savo pavarde";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout<<"\n";
        }

        int skc;
        bool veda;
        std::string ats;
        skc = 0;
        veda = true;
        int skaicius;
        while(veda)
        {
            std::cout<<"Sugeneruotas " << skc+1 << " namu darbu balas: \n";
            skaicius = rand() %10 +1;
            std::cout<<skaicius<<std::endl;
            skc++;
            currentStud.homework.push_back(skaicius);
            std::cout<<"Ar norite toliau generuoti namu darbu balus? (taip - y, ne - n) \n";
            std::cin>>ats;
            if(ats == "n")
            {
                veda=false;
            }
        }



        std::cout<<"Sugeneruotas egzamino balas: \n";
        currentStud.exam = rand()%10 +1;
        std::cout<<currentStud.exam<<std::endl;
        stud.push_back(currentStud);
        }
            

        }
        Isvesk(stud);
    }
}

void Isvesk(std::vector<student> stud)
{
    using namespace std;
    FinalCounter(stud);
    string ats;
    cout<<"Norite isvesti atsakymus i komandine eilute ar i tekstini faila? (cmd - komandine eilute, file - tekstinis failas) \n";
    cin>>ats;
    if(ats=="cmd")
    {
        cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m) \n";
        string temp;
        cin>>temp;
        
        if(temp == "v")
        {
            cout<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Vid.)"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;


            for(int i=0; i<stud.size(); i++)

                cout<<setw(30)<<left<<stud[i].surname<<setw(30)<<left<<stud[i].name<<setw(5)<<left<<fixed<<setprecision(2)<<stud[i].finalGrade<<"\n";
        }

        else if( temp == "m")
        {
            cout<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Med.)"<<endl;
            cout<<"------------------------------------------------------------------------"<<endl;

            for(int i=0; i<stud.size(); i++)
            {

                sort(stud[i].homework.begin(), stud[i].homework.end());


                if(stud[i].homework.size()%2==1)
                {

                    cout<<setw(30)<<left<<stud[i].surname<<setw(30)<<left<<stud[i].name<<setw(5)<<left<<fixed<<setprecision(2)<<stud[i].homework[(stud[i].homework.size())/2]*1.0<<"\n";
                }
                else
                {
                    cout<<setw(30)<<left<<stud[i].surname<<setw(30)<<left<<stud[i].name<<setw(5)<<left<<fixed<<setprecision(2)<<(stud[i].homework[(stud[i].homework.size())/2 - 1] + stud[i].homework[((stud[i].homework.size())/2)])/2.0<<"\n";
                }

            }
        }
        else
        {
            cout<<"Bloga įvestis. \n";
        }
    }
    else
    {
        ofstream write("atsakymai.txt");
        cout<<"Norite gauti vidurki ar mediana? (Vidurkis - v, Mediana - m) \n";
        string temp;

        cin>>temp;
        if(temp == "v")
        {
            write<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Vid.)"<<endl;
            write<<"------------------------------------------------------------------------"<<endl;


            for(int i=0; i<stud.size(); i++)

                write<<setw(30)<<left<<stud[i].surname<<setw(30)<<left<<stud[i].name<<setw(5)<<left<<fixed<<setprecision(2)<<stud[i].finalGrade<<"\n";
        }

        else if( temp == "m")
        {
            write<<setw(30)<<left<<"Pavarde"<<setw(30)<<left<<"Vardas"<<setw(5)<<"Galutinis (Med.)"<<endl;
            write<<"-------------------------------------------------------------------------"<<endl;

            for(int i=0; i<stud.size(); i++)
            {

                sort(stud[i].homework.begin(), stud[i].homework.end());


                if(stud[i].homework.size()%2==1)
                {

                    write<<setw(30)<<left<<stud[i].surname<<setw(30)<<left<<stud[i].name<<setw(5)<<left<<fixed<<setprecision(2)<<stud[i].homework[(stud[i].homework.size())/2]*1.0<<"\n";
                }
                else
                {
                    write<<setw(30)<<left<<stud[i].surname<<setw(30)<<left<<stud[i].name<<setw(5)<<left<<fixed<<setprecision(2)<<(stud[i].homework[(stud[i].homework.size())/2 - 1] + stud[i].homework[((stud[i].homework.size())/2)])/2.0<<"\n";
                }

            }
        }
        else
        {
            cout<<"Bloga įvestis. \n";
        }
    }

}

void Skaityk(std::vector<student> &stud, std::string filename)
{
    std::ifstream file;
    while(true){
        try{
             file.open(filename, std::ifstream::in);
            if(!file.good()) throw "Nepavyko atidaryti failo, isitikinkite, kad jis egzistuoja";
            break;
        }catch(const char * e){
            std::cout << e << "\n";
        }
    }    
    std::string line;
    std::ifstream read(filename);
    std::getline(read,line);
    std::string pazymysSt;
    int pazInt;
    
    while(getline(read,line))
    {
        student *currentStud = new student();
        std::stringstream stream;
        stream<<line;
        stream>>currentStud->name>>currentStud->surname;
        while(stream>>pazymysSt)
        {
            try
            {
                pazInt = stoi(pazymysSt);
            }
            catch(const std::exception& e)
            {
                std::cout<<"Ivyko klaida nuskaitant pazymi \n";
            }
            
            currentStud->homework.push_back(pazInt);
        }

        currentStud->exam = currentStud->homework.back();
        currentStud->homework.pop_back();
        stud.push_back(*currentStud);
        delete currentStud;

    }
    file.close();
}


void FinalCounter(std::vector<student> &stud)
{
    for(int i=0; i<stud.size(); i++)
    {
        for(int j=0; j<stud[i].homework.size(); j++)
        {
           stud.at(i).homeworkSum+=stud.at(i).homework.at(j);
        }
        stud.at(i).finalGrade = (stud.at(i).homeworkSum*1.0/stud.at(i).homework.size()*0.4) + (stud.at(i).exam)*0.6;
        if(stud.at(i).finalGrade>=5) stud.at(i).cool = true;
        else stud.at(i).cool = false;
        //std::cout<<stud.at(i).finalGrade<<std::endl;
    }
    std::sort(stud.begin(),stud.end(), sortStudents);
}

bool sortStudents(student A, student B)
{
    if(B.name > A.name || B.surname > A.surname)
    {
        return true;
    }
    return false;
}

bool sortStudentsByGrade(student A, student B)
{
    if(B.finalGrade > A.finalGrade)
    {
        return true;
    }
    return false;
}
void Generate(int n)
{
    auto startFull = std::chrono::high_resolution_clock::now(); 
    std::vector<student> Students;
    Students.reserve(n);
    std::string filename = "studentai"+std::to_string(n)+".txt";
    std::cout<<"Pradedama dirbti su "<<std::to_string(n)<<" studentu duomenu failu\n";
    auto start = std::chrono::high_resolution_clock::now(); 
    std::ofstream write(filename);
    write<<std::setw(30)<<std::left<<"Pavarde"<<std::setw(30)<<std::left<<"Vardas";
    for(int j=0;j<10;j++, write<<std::setw(5)<<std::left<<"ND"+std::to_string(j));
    write<<std::setw(5)<<std::left<<"Exam"<<std::endl;

    for(int i=0;i<n;i++)
    {
        write<<std::setw(30)<<std::left<<"pavarde"+std::to_string(i);
        write<<std::setw(30)<<std::left<<"vardas"+std::to_string(i);

        for(int j=0;j<10;j++)
        {
            write<<std::setw(5)<<rand() %10 +1;
        }

        write<<std::setw(5)<<rand() %10 +1<<std::endl;
    }
    write.close();
    auto end = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> diff = end-start;
    std::cout<<"Failas sugeneruotas per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    Skaityk(Students,filename);
    end = std::chrono::high_resolution_clock::now(); 
    diff = end-start;
    std::cout<<"Failas perskaitytas per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    FinalCounter(Students);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai atskirti i dvi grupes per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    std::sort(Students.begin(),Students.end(), sortStudentsByGrade);
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai didejimo tvarka surusiuoti per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    std::string filename2 = "notcool"+std::to_string(n)+".txt";
    std::ofstream writenotCool(filename2);
    for(int i=0;i<Students.size();i++)
    {
        if(!Students[i].cool)
        {
            writenotCool<<std::setw(30)<<std::left<<Students[i].surname<<std::setw(30)<<std::left<<Students[i].name<<std::setw(5)<<std::left<<std::fixed<<std::setprecision(2)<<Students[i].finalGrade<<"\n";
        }
    }
    writenotCool.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai, kuriu vidurkis zemesnis 5, irasyti per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    start = std::chrono::high_resolution_clock::now(); 
    std::string filename3 = "cool"+std::to_string(n)+".txt";
    std::ofstream writeCool(filename3);
    for(int i=0;i<Students.size();i++)
    {
        if(Students[i].cool)
        {
            writeCool<<std::setw(30)<<std::left<<Students[i].surname<<std::setw(30)<<std::left<<Students[i].name<<std::setw(5)<<std::left<<std::fixed<<std::setprecision(2)<<Students[i].finalGrade<<"\n";
        }
    }
    writeCool.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end-start;
    std::cout<<"Studentai, kuriu vidurkis auksciau arba lygu 5, irasyti per: "<<std::fixed<<std::setprecision(2)<<diff.count()<<"s"<<std::endl;

    auto endFull = std::chrono::high_resolution_clock::now(); 
    diff = endFull-startFull;
    std::cout<< "Is viso " << n << " irasu testas padarytas per: " << std::fixed<<std::setprecision(2)<< diff.count() << "s\n";
    std::cout<<"Spauskite enter, norint pereiti prie kito testo generavimo \n";
    std::cin.ignore(256, '\n');
    std::cin.get();
}
