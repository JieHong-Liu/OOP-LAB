#pragma once
#include <iostream>
using std::string;
class Document
{
    // constructor
public:
    Document();
    Document(string text);
    void setText(string text);
    string getText() const;
    Document &operator=(Document &doc);

private:
    string text;
};
