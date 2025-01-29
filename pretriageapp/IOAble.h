#ifndef SENECA_IOAble_H_
#define SENECA_IOAble_H_
#include <iostream>

using namespace std;
namespace seneca {
    class IOAble {
    public:
        virtual ostream& write(ostream& os) const = 0; // receives a reference of an ostream and returns a reference of an ostream
        virtual istream& read(istream& is) = 0; // receives a reference of istream and returns a reference of an istream
        virtual ~IOAble() {} // empty virtual destructor
    };
    ostream& operator<<(ostream& os, const IOAble& ioable); // insert the information of an IOAble object into ostream
    istream& operator>>(istream& is, IOAble& ioable); // extract information from an istream into an IOAble object
}
#endif // !SENECA_IOAble_H_