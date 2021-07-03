#include <iostream>
#include "Document.h"
using std::string;

class File : public Document // inheribirt from Document
{
public:
    File();
    File(string text, string pathname);
    string getPathname();
    void setPathname(string pathname);
    File &operator=(File &f);

private:
    string pathname;
};
