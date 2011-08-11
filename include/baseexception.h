#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <exception>
#include <string>

using namespace std;
class BaseException {

private:    
    string message;

public:
    BaseException( string message );
    inline string getMessage() { return message; };

};

#endif
