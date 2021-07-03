#include "Email.h"
Email::Email()
{
    this->sender = "";
    this->recipient = "";
    this->title = "";
}

Email::Email(string text, string sender, string recipient, string title)
{
    this->setText(text);
    this->sender = sender;
    this->recipient = recipient;
    this->title = title;
}
string Email::getSender() const
{
    return this->sender;
}
string Email::getRecipient() const
{
    return this->recipient;
}
string Email::getTitle() const
{
    return this->title;
}
Email &Email::operator=(const Email &e)
{
    if (this == &e)
    {
        return *this;
    }
    else
    {
        this->setText(e.getText());
        this->sender = e.getSender();
        this->recipient = e.getRecipient();
        this->title = e.getTitle();
        return *this;
    }
}
