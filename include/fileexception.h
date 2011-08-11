#ifndef FILEEXCEPTION_H
#define FILEEXCEPTION_H

#include "baseexception.h"

using namespace std;

class FileNotFoundException : public BaseException {


public:
    string filename;
    FileNotFoundException( string fname):BaseException(""){};
    inline string getFilename() { return filename; };
    
    // Overriding getMessage() method
    inline string getMessage() {
        stringstream ss;
        ss << "Exception Raised - " << filename << " file not found";
        return ss.str();
    };    
    
};
#endif
