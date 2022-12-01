#include <iostream>
#include "Hotel.h"


int main() {
    bool done;
    int size = 10;
    Hotel arr_ptr[size];
    for (int i = 0; i < size; i++)
    {
        arr_ptr[i].room_info.set_vacant(true);
    }
    int input = 0;
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