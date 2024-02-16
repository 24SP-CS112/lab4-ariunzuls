 /* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Ariunzul Saruul, Aisha Abdullahi
 * Date: 13 Feb 2024
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#include "Vec.h"


Vec::Vec(unsigned size) { // explicit-value constructor
    mySize = size;
    
    if (size > 0) { 
        myArray = new Item[size]; // dynamic allocation
        for (unsigned int i = 0; i < size; i ++) {
            myArray [i] = 0;
        }
    }
    else {
        myArray = nullptr;
    }
  }

Vec::Vec() { // default constructor
    mySize = 0;
    myArray = nullptr;
}

Vec::~Vec() { // destructor
    delete [] myArray;
    myArray = nullptr;
    mySize =0;
}

Vec::Vec(const Vec& original) { // copy constructor
    mySize = original.mySize;
    
    if (mySize > 0) {
        myArray = new Item[mySize]; // dynamic allocation
        for (unsigned int i = 0; i < mySize; i++) {
            myArray[i] = original.myArray[i];
        }
        
    }
    else {
            myArray = nullptr;
        }
  }


unsigned Vec::getSize() const {
    return mySize;
}

Item Vec::getItem(unsigned index) const { // getItem
	if (index < 0 || index >= mySize) {
     	throw range_error("Bad index");
	}
	return myArray[index];
}

void Vec::setItem(unsigned index, const Item& it) { // setItem
	if (index < 0 || index >= mySize) {
    	throw range_error("Bad index");
	}
	myArray[index] = it;
}

Vec& Vec::operator=(const Vec& original) {
      	if (this != &original){
            if (mySize != original.mySize){
                if (mySize > 0){
                    delete [] myArray;
                    myArray = nullptr;
                }
                if  (original.mySize > 0){
                    myArray = new Item[original.mySize]; 
                }
                mySize = original.mySize;
            }
            for (unsigned int i = 0; i < mySize; i++) {
            myArray[i] = original.myArray[i];
        }
        }

        return *this;
}

void Vec::setSize(unsigned newSize) {
    if (mySize != newSize){
        if (newSize == 0){
            delete [] myArray;
            myArray = nullptr;
            mySize = 0;
        }
        else {
            Item *newArray;
            newArray = new Item[newSize];
            if(mySize < newSize){
                for (unsigned int i = 0; i < mySize ; i++){
                    newArray [i] = myArray[i];
                }
                for (unsigned int i = mySize; i < newSize; i++){
                    newArray [i] = 0;
                }
            }
            else {
                for (unsigned int i = 0; i < newSize ; i++){
                     newArray [i] = myArray[i];
                }
            }
            mySize = newSize;
            delete [] myArray;
            myArray = newArray;
        }
    }
}

bool Vec::operator==(const Vec& v2) const {
    if (mySize != v2.mySize){
        return false;
    }
    for (unsigned int i = 0 ; i < mySize; i++){
        if (myArray[i] != v2.myArray[i]){
            return false;
        }
    }
    return true;
}
void Vec::writeTo(ostream& out) const {
    for (unsigned int i = 0 ; i < mySize; i++){
        out<< myArray[i] << " ";
    }
}

void Vec::readFrom(istream& in) {
    int i = 0;
    while (in >> myArray[i]){
        i++;
    }
}