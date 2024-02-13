/* Vec.h provides a simple vector class named Vec.
 * Student Name:
 * Date:
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;

typedef double Item;

class Vec {
   public:
	Vec();
	virtual ~Vec();


   unsigned getSize() const;
   Vec(unsigned size);  // explicit-value constructor
   Item getItem(unsigned index) const;
   void setItem(unsigned index, const Item& it);
   Vec(const Vec& original);
   Vec& operator=(const Vec& original);


   private:
   unsigned mySize;
   Item * myArray;
};

#endif /*VEC_H_*/
