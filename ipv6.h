#ifndef IPV6_H_INCLUDED
#define IPV6_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "diccionario.h"
#include "icmpv6.h"


using namespace std;

void versionipv6(char *c)
{
    string s;
    stringstream ss, ss2;
    int n;
    char *cc;
    for(int i=0; i<4; i++)
    {
        ss<<c[i];
    }
    s=ss.str();
    n=strtoull(s.c_str(), &cc, 2);
    cout<<"Version: "<<n<<" ("<<s<<")"<<" -> IPV6";
}
void trafficClass(char *c, char *c2)
{
    string s,s2;
    stringstream ss, ss2;
    int n, n2;
    char *cc;
    for(int i=4; i<8; i++)
    {
        ss<<c[i];
    }
    s=ss.str();
    n=strtoull(s.c_str(), &cc, 2);

    for(int i=0; i<4; i++)
    {
        ss2<<c2[i];
    }
    s2=ss2.str();
    n2=strtoull(s.c_str(), &cc, 2);
    printf("\nTraffic Class: 0x%02x%02x",n, n2);
}
void flowLabel(char *c, char *c2, char *c3)
{
    string s,z;
    stringstream ss, ss2, ss3,zz;
    unsigned long int n;
    char *cc;
    for(int i=4; i<8; i++)
    {
        ss<<c[i];
    }
    s=ss.str();
    ///n=strtoull(s.c_str(), &cc, 2);
    zz<<s;
    for(int i=0; i<8; i++)
    {
        ss2<<c2[i];
    }
    s=ss2.str();
    zz<<s;
    ///n=strtoull(s.c_str(), &cc, 2);
    for(int i=0; i<8; i++)
    {
        ss3<<c3[i];
    }
    s=ss3.str();
    zz<<s;
    z=zz.str();
    n=strtoull(z.c_str(), &cc, 2);
    cout<<endl<<"Flow Label: "<<n;
}

void ipv6(char *c)
{
    int tam;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if(!ar.is_open())
    {
        cout<<endl<<"Error."<<endl;
    }else
    {
        cout<<endl<<"                IPV6                 "<<endl;
        char *bin, *bin2, *bin3;
        ///-------------version---------------------
        tam=1;
        ch = new unsigned char [tam];
        ar.seekg (14, ios::beg);
        ar.read ((char*)ch, tam);
        bin=chartobin(ch[0]);
        versionipv6(bin);
        ///----------Traffic class-------------------
        tam=2;
        ar.seekg (14, ios::beg);
        ar.read ((char*)ch, tam);
        bin=chartobin(ch[0]);
        bin2=chartobin(ch[1]);
        trafficClass(bin, bin2);
        ///----------Flow Label-----------------------
        tam=3;
        ar.seekg (15, ios::beg);
        ar.read ((char*)ch, tam);
        bin=chartobin(ch[0]);
        bin2=chartobin(ch[1]);
        bin3=chartobin(ch[2]);
        flowLabel(bin, bin2, bin3);
        ///----------Payload Lenght-------------------
        tam=2;
        ar.seekg (18, ios::beg);
        ar.read ((char*)ch, tam);
        char *cc;
        long int n;
        string s;
        stringstream ss,z;
        bin=chartobin(ch[0]);
        ss<<bin;
        bin=chartobin(ch[1]);
        ss<<bin;
        s=ss.str();
        n=strtoull(s.c_str(), &cc, 2);
        cout<<endl<<"Payload Lenght: "<<n;
        ///----------Next Header-------------------
        int num;
        tam=1;
        ar.seekg (20, ios::beg);
        ar.read ((char*)ch, tam);
        stringstream sss;
        sss<<(int)ch[0];
        s=sss.str();
        num=verificarIPT6(s);
        ///----------Hop Limit---------------------
        tam=1;
        ar.seekg (21, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Hop Limit: "<<(int)ch[0];
        ///----------Source address----------------
        tam=16;
        ar.seekg (22, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Source Address: ";
        int cont=0;
        for(int j=0; j<16; j++)
        {
            printf("%02x", (int)ch[j]);
            cont++;
            if(j<15)
            {
                if(cont==2)
                {
                cont=0;
                cout<<":";
                }
            }
        }
        /*tam=16;
        ar.seekg (22, ios::beg);
        ar.read ((char*)ch, tam);
        stringstream sa;
        int cont=0;
        for(int j=0; j<16; j++)
        {
            sa<<hex<<setw(2)<<setfill('0')<<(int)ch[j];
            cont++;
            if(j<15)
            {
                if(cont==2)
                {
                    cont=0;
                    sa<<":";
                }
            }
        }
        s=sa.str();
        cout<<endl<<"Source Address: "<<s;*/
        ///----------Destination address-----------
        tam=16;
        ar.seekg (38, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Destination Address: ";
        cont=0;
        for(int j=0; j<16; j++)
        {
            printf("%02x", (int)ch[j]);
            cont++;
            if(j<15)
            {
                if(cont==2)
                {
                cont=0;
                cout<<":";
                }
            }
        }
        /*tam=16;
        ar.seekg (38, ios::beg);
        ar.read ((char*)ch, tam);
        stringstream sd;
        cont=0;
        for(int j=0; j<16; j++)
        {
            sd<<hex<<setw(2)<<setfill('0')<<(int)ch[j];
            cont++;
            if(cont==2)
            {
                if(j<15)
                {
                    cont=0;
                    sd<<":";
                }
            }
        }
        s=sd.str();
        cout<<endl<<"Destination Address: "<<s;*/
        ///-----------------DATA--------------------
        if(num==58)
        {
            icmp6(c);
        }
    }
    delete[] ch;
    ar.close();
}

#endif // IPV6_H_INCLUDED
