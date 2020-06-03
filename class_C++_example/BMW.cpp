//
// Created by zagor on 1/5/2020.
//

#include "BMW.h"

float BMW::getPrice()  {
    return this->price;
}

void BMW::setPrice(float price) {
    this->price = price;
}

short BMW::getSeats()  {
    return this->seats;
}

void BMW::setSeats(short seats) {
    this->seats = seats;
}
BMW::BMW() {}
BMW::BMW(float price, short seats) : price(price), seats(seats) {}

