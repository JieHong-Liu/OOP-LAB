#include "File.h"

File::File()
{
    this->pathname = "";
}
File::File(string text, string pathname)
{
    this->setText(text);
    this->pathname = pathname;
}
string File::getPathname()
{
    return this->pathname;
}
void File::setPathname(string pathname)
{
    this->pathname = pathname;
}
File &File::operator=(File &f)
{
    if (this == &f)
    {
        return *this;
    }
    else
    {
        this->setText(f.getText());
        this->pathname = f.getPathname();
        return *this;
    }
}
