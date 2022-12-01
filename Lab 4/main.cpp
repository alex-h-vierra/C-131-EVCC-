#include <iostream>
#include "Classes_and_Prototypes.h"

int main() {

    bool done;
    int size = 10;
    int input = 0;
    Hotel arr_ptr[size];
    for (int i = 0; i < size; i++)
    {
        arr_ptr[i].room_info.set_vacant(true);
    }
    do
    {
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "|Menu          |" << std::endl;
        std::cout << "|1 view        |" << std::endl;
        std::cout << "|2 add guest   |" << std::endl;
        std::cout << "|3 delete guest|" << std::endl;
        std::cout << "|4 move guest  |" << std::endl;
        std::cout << "|0 Quit        |" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
        std::cin >> input;
        bool fail = std::cin.fail();
        bool isNumber = !fail;
        if (!isNumber || input > 4 || input < 0)
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 1)
        {
            view_rooms(arr_ptr, size);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 2)
        {
            add_guest(arr_ptr, size);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 3)
        {
            remove_guest(arr_ptr, size);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = false;
        }
        else if (input == 4)
        {
            move_rooms(arr_ptr, size);
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

void remove_guest(Hotel arr_ptr[], int roomNumber)
{
    std::cout << "Please enter the guest room number: ";
    std::cin >> roomNumber;
    arr_ptr[roomNumber].guest_info.get_name().clear();
    arr_ptr[roomNumber].guest_info.get_email().clear();
    arr_ptr[roomNumber].room_info.set_vacant(true);
}

void add_guest(Hotel arr_ptr[], int roomNumber)
{
    std::string name = " ";
    std::string email = " ";
    std::cout << "Please enter a free room: " << std::endl;
    std::cin >> roomNumber;
    std::cout << "Please enter Guest name: " << std::endl;
    std::cin >> name;
    std::cout << "Please enter Guest email: " << std::endl;
    std::cin >> email;

    arr_ptr[roomNumber].guest_info.set_name(name);
    arr_ptr[roomNumber].guest_info.set_email(email);
    arr_ptr[roomNumber].room_info.set_vacant(false);
}

void view_rooms(Hotel arr_ptr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr_ptr[i].room_info.get_vacant())
        {
            std::cout << "Room " << i << " is open" << std::endl;
        }
        else
        {
            std::cout << "Room "<< i << " is closed" << std::endl;
        }
    }
}

void move_rooms(Hotel arr_ptr[], int size)
{
    int roomNumber = 0;
    int roomNumberTwo = 0;
    std::cout << "Please enter the guest room: " << std::endl;
    std::cin >> roomNumber;
    std::cout << "Please enter in a room to switch to: " << std::endl;
    std::cin >> roomNumberTwo;

    arr_ptr[roomNumberTwo].guest_info.get_name() = arr_ptr[roomNumber].guest_info.get_name();
    arr_ptr[roomNumberTwo].guest_info.get_email() = arr_ptr[roomNumber].guest_info.get_email();
    arr_ptr[roomNumberTwo].room_info.set_vacant(false);
    arr_ptr[roomNumber].guest_info.get_name().clear();
    arr_ptr[roomNumber].guest_info.get_email().clear();
    arr_ptr[roomNumber].room_info.set_vacant(true);
}
