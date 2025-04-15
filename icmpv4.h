#ifndef ICMP_H_INCLUDED
#define ICMP_H_INCLUDED
#include <iostream>
#include <fstream>
#include "diccionario.h"

using namespace std;

void icmp4 (char *c,int t)
{
    int ident;
    int tam;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if(!ar.is_open())
    {
        cout<<endl<<"Error."<<endl;
    }else
    {
        cout<<endl<<endl<<"                ICMPV4                 "<<endl;
        string s;
        ///----------------TYPE, CODE-----------------------
        tam=2;
        ch = new unsigned char [tam];
        ar.seekg (34, ios::beg);
        ar.read ((char*)ch, tam);
        char *bin, *cc;
        stringstream ss;
        ss<<(int)ch[0];
        if((int)ch[0]==3||(int)ch[0]==5||(int)ch[0]==11)
        {
            ss<<"-"<<(int)ch[1];
        }else{
            ss<<"-0";
        }
        s=ss.str();
        ident=verificarIcmp4(s);
        ///---------------Checksum----------------------------
        tam=2;
        ar.seekg (36, ios::beg);
        ar.read ((char*)ch, tam);
        stringstream sss;
        sss<<hex<<setw(2)<<setfill('0')<<(int)ch[0];
        sss<<hex<<setw(2)<<setfill('0')<<(int)ch[1];
        s="0x"+sss.str();
        cout<<endl<<"Header Checksum: "<<s;
        if(ident==0||ident==8)
        {
            ///--------------Identificador-------------------------
            tam=2;
            ar.seekg (38, ios::beg);
            ar.read ((char*)ch, tam);
            long int n;
            stringstream z;
            bin=chartobin(ch[0]);
            z<<bin;
            bin=chartobin(ch[1]);
            z<<bin;
            s=z.str();
            n=strtoull(s.c_str(), &cc, 2);
            cout<<endl<<"Identificador: "<<n;
            ///--------------Secuencia------------------------------
            tam=2;
            ar.seekg (40, ios::beg);
            ar.read ((char*)ch, tam);
            stringstream z2;
            bin=chartobin(ch[0]);
            z2<<bin;
            bin=chartobin(ch[1]);
            z2<<bin;
            s=z2.str();
            n=strtoull(s.c_str(), &cc, 2);
            cout<<endl<<"Numero de Secuencia: "<<n;
            ///------------------Payload-----------------------------
            cout<<endl<<"Payload Lenght: "<<t-8;
        }else if(ident==3)
        {
            cout<<endl<<"Payload Lenght: "<<t-4;
        }else if(ident==5)
        {
            ///--------------Gateway---------------------------------
            tam=4;
            ar.seekg (38, ios::beg);
            ar.read ((char*)ch, tam);
            cout<<endl<<"Gateway: ";
            for(int j=0; j<4; j++)
            {
                printf("%d", (int)ch[j]);
                if(j<3)
                {
                    cout<<".";
                }
            }
            ///------------Payload------------------------------------
            cout<<endl<<"Payload Lenght: "<<t-8;
        }else if(ident==1)
        {
            cout<<endl<<"Payload Lenght: "<<t-4;
        }

    }
}
#endif // ICMP_H_INCLUDED
