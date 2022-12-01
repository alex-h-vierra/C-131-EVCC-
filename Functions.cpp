/**
 * Lab_4
 * Hotel.cpp
 * This file holds the functions for a
 * guest at a hotel.
 * @author Michael Smith
 * @version 12/1/2022
 */
#include <iostream>
#include "Hotel.h"

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