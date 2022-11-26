#include <iostream>
#include <vector>
#include <fstream>

class Guest {
public:
    std::string get_lastName() const;

    std::string get_email() const;

    void set_lastName(std::string lastName);

    void set_email(std::string email);

private:
    std::string lastName;
    std::string email;
};
//provided access to private
std::string Guest::get_lastName() const {
    return lastName;
}

std::string Guest::get_email() const {
    return email;
}

void Guest::set_lastName(std::string lastName) {
    if (lastName.length() > 0)
    {
        this->lastName = lastName;
    }
}

void Guest::set_email(std::string email) {
    if (email.length() > 0)
    {
        this->email = email;
    }
}

class Room
{
public:

    bool get_vacant_room() const;

    void set_vacant_room(bool vacant);

private:
    bool vacant = false;
};

bool Room::get_vacant_room() const {
    return vacant;
}

void Room::set_vacant_room(bool vacant) {
    this->vacant = vacant;
}

class Hotel
{
public:
    Room rooms[10];
    Guest checkin;
};


int main() {
    std::ofstream file;
    file.open("Guest_list.txt");

    Hotel g1;
    for (int i = 0; i < 9; i++)
    {
        g1.rooms[i].set_vacant_room(false);
    }

    bool done = true;

    do {
        std::cout << "Cat Hotel checkin" << std::endl;
        std::cout << " 1 Look up" << std::endl;
        std::cout << " 2 add guest" << std::endl;
        std::cout << " 3 remove guest" << std::endl;
        std::cout << " 4 move guest" << std::endl;
        std::cout << " 0 Quit" << std::endl;


        int input;
        std::cin >> input;
        bool fail = std::cin.fail();
        bool isNumber = !fail;
        if (!isNumber || input < 0 || input > 4)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 1)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 2)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 3)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 4)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else
        {
            done = true;
        }
    } while (!done);
}

