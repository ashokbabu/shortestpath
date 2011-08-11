#include <string>
#include <sstream>
#include <fileexception.h>
using namespace std;

FileNotFoundException::FileNotFoundException(){

}

FileNotFoundException::FileNotFoundException(string fname ): filename(fname){


}
