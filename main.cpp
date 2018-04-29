#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Minge {

private:
    char* nume;

public:
    Minge() {};

    void setNume(const char * new_nume)
    {
        delete nume;
        nume=new char[strlen(new_nume)+1];
        strcpy_s(nume, 20 new_nume);
    }

    const char* getNume() const
    {
        return &nume[0];
    }

    Minge(const char* obj)
            :nume(new char[std::strlen(obj)+1])
        {
            std::strcpy(nume, obj);
        }

    virtual ~Minge()
    {
        delete[] nume;
    }

	Minge(const Minge& obj)
	{
	    nume=new char[std::strlen(obj.nume)+1];
	    std::strcpy(nume, obj.nume);
	}

	Minge(Minge&& obj)
        :nume(obj.nume)
    {
        obj.nume=nullptr;
    }

    Minge& operator=(const Minge& obj)
    {
        char *tmp_nume=new char[std::strlen(obj.nume)+1];
        std::strcpy(tmp_nume, obj.nume);
        delete[] nume;
        nume=tmp_nume;
        return *this;
    }

    Minge& operator=(Minge&& obj)
    {
        if(this!=&obj)
        {
            delete[] nume;
            nume=obj.nume;
            obj.nume=nullptr;
        }
        return *this;
    }

    friend bool Contine(const Minge& n1);
    friend std::ostream& operator<< (std::ostream& os, const Minge& p1);
    friend bool operator ==(const Minge& p1, const Minge& p2);
};

bool Contine(const Minge& n1)
    {
        char s1[20];
        strcpy(s1, "Minge football");
        int rez=strcmp(n1.getNume(), s1);
        if(rez==0) return true;
        else return false;
    }

bool operator==(const Minge& p1, const Minge& p2)
    {
        return p1.getNume()==p2.getNume();
    }

std::ostream& operator<<(std::ostream& os, const Minge& p1)
    {
        os<<p1.getNume()<<" | ";
        return os;
    }


int main() {

	std::vector<Minge> vectorMinge;
	vectorMinge.push_back("Minge basketball");
	vectorMinge.push_back("Minge voleyball");
	vectorMinge.push_back("Minge football");
	vectorMinge.push_back("Minge tennis");

	std::cout<<"Vectorul are: "<<" "l
	for(std::vector<Minge>::iterator i=vectorMinge.begin(); i!= vectorMinge.end(); ++i)
    {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;

    std::vector<Minge>::iterator i=std::find_if(vectorMinge.begin(), vectorMinge.end()-1, Contine);
    std::cout<<"Vectorul contine minge de football?"<<std::endl;
    std::cout<<"Vectorul contine: "<<*i<<'\n';

    std::cout<<"Daca vectorul contine minge football, sterge"<<std::endl;
    vectorMinge.erase(std::remove_if(vectorMinge.begin(), vectorMinge.end(), Contine), vectorMinge.end());

    std::cout<<"Vectorul contine: "<< " ";
    for(std::vector<Minge>::iterator i= vectorMinge.begin(); i!=vectorMinge.end(); ++i)
    {
        std::cout<<*i<<" ";
    }

    std::cout<<std::endl;
    std::cin.get();
}
