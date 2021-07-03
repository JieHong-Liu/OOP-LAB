#pragma once
#include <iostream>
using std::string;
class Document 
{
	// constructor
public:
	Document();
	Document(string text);
	Document& operator = (Document doc);

};

class Email :public Document // Ä~©ÓDocument
{
	Email();
	Email(string text, string sender, string recipient, string title);
	Email& operator = (Email e);
};

class File
{
	File();
	File(string text, string pathname);
	File& operator = (File f);
};