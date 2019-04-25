#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

class Products
{
    public:

          Products();
          Products(int pnumber, char* pname, char* exp, char* b, int p);
          void GetProduct();
          void WriteToFile(Products product);
          void GetRecordDetails();
          void ReadFromFile(int position);
          void ReadRecordPosition();

    private:

    char productname[40];
    int productnumber;
    char expirydate[20];
    float price;
    char brand[40];
};

#endif // PRODUCTS_H
