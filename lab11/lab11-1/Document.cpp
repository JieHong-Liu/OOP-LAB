#pragma once
#include "Document.h"
// constructor
Document::Document()
{
    this->text = "";
}

Document::Document(string text)
{
    this->text = text;
}

void Document::setText(string text)
{
    this->text = text;
}

string Document::getText() const
{
    return this->text;
}

Document &Document::operator=(Document &doc)
{
    if (this == &doc)
    {
        return *this;
    }
    else
    {
        this->setText(doc.getText());
        return *this;
    }
}
