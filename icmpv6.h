#ifndef ICMPV6_H_INCLUDED
#define ICMPV6_H_INCLUDED
#include <iostream>
#include <fstream>
#include "diccionario.h"
using namespace std;

void icmp6 (char *c)
{
    int tam;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if(!ar.is_open())
    {
        cout<<endl<<"Error."<<endl;
    }else
    {
        cout<<endl<<endl<<"                ICMPV6                 "<<endl;
        string s;
        int ident;
        ///----------------TYPE, CODE-----------------------
        tam=2;
        ch = new unsigned char [tam];
        ar.seekg (54, ios::beg);
        ar.read ((char*)ch, tam);
        char *bin, *cc;
        stringstream ss;
        ss<<(int)ch[0];
        if((int)ch[0]<10)
        {
            ss<<"-"<<(int)ch[1];
        }else{
            ss<<"-0";
        }
        s=ss.str();
        ident=verificarIcmp6(s);
        ///---------------Checksum----------------------------
        tam=2;
        ar.seekg (56, ios::beg);
        ar.read ((char*)ch, tam);
        stringstream sss;
        sss<<hex<<setw(2)<<setfill('0')<<(int)ch[0];
        sss<<hex<<setw(2)<<setfill('0')<<(int)ch[1];
        s="0x"+sss.str();
        cout<<endl<<"Header Checksum: "<<s;
    }
}
#endif // ICMPV6_H_INCLUDED
