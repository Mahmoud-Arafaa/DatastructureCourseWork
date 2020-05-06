#ifndef INORDERLIST_H_INCLUDED
#define INORDERLIST_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include <string.h>
#include <fstream>
#include<sstream>
using namespace std;
class InordList{

private:
    struct Node
    {
        string data;
        Node *next;
        int lnum;
    };
    Node *head;
    Node *last;
    Node *current;

public:
    InordList();
    int wordCount();
    int distWord(int &n);
    int charCount(fstream file);
    void frequentWord();
    int countWord(string &s);
    void starting(string &s);
    void containing(string &s);
    void search(string &s);
    void  print();
    void  Sort();
    bool insert_(const string &s,int &n);


};

#endif // INORDERLIST_H_INCLUDED
