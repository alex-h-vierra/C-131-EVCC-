#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Person
{
public:
    std::string skinColor;
    std::string hairColor;
};



void write_file(std::vector<Person> personList, std::string name);
std::vector<Person> read_file(std::string name);
void addPerson(std::vector<Person>& vec);


int main() {

    std::string file_name = "file.txt";

    std::vector<Person> personList = read_file(file_name);

    addPerson(personList);

    write_file(personList,file_name);
}

void addPerson(std::vector<Person>& vec)
{
    std::string hair;
    std::string skin;

    std::cout << "Please Enter what hair color you want: " << std::endl;
    std::getline(std::cin, hair);
    std::cout << "Please Enter What skin you want: " << std::endl;
    std::cin >> skin;
    std::cin.ignore(100,'\n');

    vec.push_back(Person{skin,hair});
}

void write_file(std::vector<Person> personList, std::string name)
{
    std::ofstream out_file;
    out_file.open(name);
    for(int i = 0; i < personList.size(); i++)
    {
        out_file << personList[i].skinColor << std::endl;
        out_file << personList[i].hairColor << std::endl;
    }
    out_file.close();
}

std::vector<Person> read_file(std::string name)
{
    std::ifstream in_file;
    in_file.open(name);

    std::vector<Person> vec;
    std::string skin;
    std::string hair;

    if(in_file.good())
    {
        while (std::getline(in_file, skin))
        {
            in_file >> hair;
            in_file.ignore(100,'\n');
            vec.push_back(Person{skin,hair});
        }
    }
    return vec;
}



