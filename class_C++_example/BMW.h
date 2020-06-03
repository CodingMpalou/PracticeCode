//
// Created by zagor on 1/5/2020.
//

#ifndef CLASS_C_EXAMPLE_BMW_H
#define CLASS_C_EXAMPLE_BMW_H


class BMW {
    public:
        BMW();
        BMW(float price, short seats);
        enum color {BLUE, RED};

        float getPrice();
        void setPrice(float price);
        short getSeats();
        void setSeats(short seats);

    private:
        float price;
        short seats;
};


#endif //CLASS_C_EXAMPLE_BMW_H
