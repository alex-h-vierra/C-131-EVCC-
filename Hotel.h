/**
 * Lab_4
 * Hotel.h
 * This file holds the class definitions for a
 * guest at a hotel.
 * @author Michael Smith
 * @version 12/1/2022
 */

#ifndef EXAM_PRACTICE_HOTEL_H
#define EXAM_PRACTICE_HOTEL_H

#include <string>

class Guest
{
    std::string email;
    std::string name;
public:
    void set_email(std::string email);
    std::string get_email();
    void set_name(std::string full_name);
    std::string get_name();
};

std::string Guest::get_email()
{
    return email;
}
void Guest::set_email(std::string email)
{
    this->email = email;
}
std::string Guest::get_name()
{
    return name;
}
void Guest::set_name(std::string full_name)
{
    this->name = full_name;
}
class Room
{
    bool vacant;
public:
    void set_vacant(bool vacant);
    bool get_vacant();
};

bool Room::get_vacant()
{
    return vacant;
}
void Room::set_vacant(bool vacant)
{
    this->vacant = vacant;
}

class Hotel
{
public:
    Room room_info;
    Guest guest_info;

};

void add_guest(Hotel arr_ptr[], int roomNumber);
void remove_guest(Hotel arr_ptr[], int roomNumber);
void view_rooms(Hotel arr_ptr[], int size);
void move_rooms(Hotel arr_ptr[], int size);


#endif //EXAM_PRACTICE_HOTEL_H
