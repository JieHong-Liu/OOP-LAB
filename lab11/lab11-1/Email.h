#pragma once
#include <iostream>
#include "Document.h"
using std::string;

class Email : public Document // inheribirt from Document
{
public:
    Email();
    Email(string text, string sender, string recipient, string title);
    string getSender() const;
    string getRecipient() const;
    string getTitle() const;
    Email &operator=(const Email &e);

private:
    string sender;
    string recipient;
    string title;
};
