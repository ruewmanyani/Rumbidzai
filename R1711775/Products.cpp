#include <iostream>
#include<fstream>
#include<cstring>
#include "Products.h"

Products::Products()
{

}

 Products::Products(int pnumber, char* pname, char* exp, char* b, int p) {
        productnumber = pnumber;
        price = p;
        strcpy(productname, pname);
        strcpy(brand, b);
        strcpy(expirydate, exp);
    }

 void Products::GetProduct() {
        cout << "\n";
        cout << "Product name...." << productname << endl;
        cout << "product number...." << productnumber << endl;
        cout << "product brand...." << brand << endl;
        cout << "expiry date...." << expirydate << endl;
        cout << "price...." << price << endl;
    }
    void Products::GetRecordDetails() {
    char opt;
    char ch;

    int pnumber;
    char pname[40];
    char b[40];
    char exp[20];
    float p;

    do {
        cout << "Enter Product number..";
        cin >> pnumber;
        cin.ignore();
        cout << "Enter productname..";
        cin.getline(pname, 40);
        cout << "Enter brand..";
        cin.getline(b, 40);
        cout << "Enter expirydate..";
        cin.getline(exp, 20);
        cout << "Enter price..$..";
        cin >> p;
        cin.ignore();
        Products product(pnumber, pname, b, exp, p);
        WriteToFile(product);

        cout << "Another record <y-yes n-no>" << endl;
        opt = getchar();
        cin.ignore();

    }while (opt != 'n');

    }

    void Products::WriteToFile(Products product) {

    ofstream outFile("products", ios::app | ios::binary);
    outFile.write((char*) &product, sizeof (Products));
    outFile.flush();

    if (outFile)
        cout << "\nRecord saved successfully" << endl;
    else
        cout << "Error saving file" << endl;

    outFile.close();

}

void Products::ReadRecordPosition() {
    streamsize position;
    cout << "Enter the record number to retrieve...";
    cin>>position;
    ReadFromFile(position);
}

void Products::ReadFromFile(int position) {
    Products product;

    ifstream inFile("products", ios::in | ios::binary);

inFile.seekg(sizeof (Products)*(position - 1), ios::beg);
    while(inFile.read((char *) &product, sizeof (Products))){

    product.GetProduct();

    }
     inFile.close();
}
