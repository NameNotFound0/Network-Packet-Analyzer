#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "diccionario.h"
#include "ethernet.h"
#include "arp.h"
#include "ipv4.h"
#include "icmpv4.h"
#include "ipv6.h"
#include "pcap.h"
using namespace std;

int main()
{
    char e[30];
    int t;
    bool v=false;
    cout<<endl<<"Ingrese Nombre de Paquete: ";
    cin>>e;
    cout<<endl;
    ///Agregar el .bin
    string ee(e);
    t=ee.size();
    if(ee[t-4]=='.')
    {
        if(ee[t-3]=='b')
        {
            if(ee[t-2]=='i')
            {
                v=true;
            }
        }
    }
    if(!v)
    {
        ee.append(".bin");
    }
    strncpy(e, ee.c_str(), sizeof(e));
    e[sizeof(e) - 1] = 0;
    ifstream ar (e);
    if(!ar.is_open())
    {
        cout<<endl<<"Error.";
    }else
    {
        ///------------ETHERNET-----------------------------
        ifstream ar (e);
        int in,fn,t;
        string s;
        in= ar.tellg();
        ar.seekg (0, ios::end);
        fn= ar.tellg();
        t=fn-in-18;
        ar.seekg (0);
        //mostrarbin(e);
        cout<<"Tamano Paquete: "<<fn<<endl;
        ///direcciones
        direcciones(e);
        ///tipo
        s=tipo(e);
        ///Carga util
        cout<<endl<<"Hay "<<t<<" Bytes de carga util.";
        ///crc
        crc(e, t);
        cout<<endl;
        for(int i=0; i<100; i++)
        {
            if(dEthertype[i]==s)
            {
                if(dEthertype[i+2]=="ARP")
                {
                    ///------------ARP----------------------------------
                    arp(e);
                }
                if(dEthertype[i+2]=="IPV4")
                {
                    ///------------IPV4----------------------------------
                    ipv4(e);
                }
                if(dEthertype[i+2]=="IPV6")
                {
                    ///------------IPV6----------------------------------
                    ipv6(e);
                }
            }
        }
        //int pca;
        //pca=pcap();
    }
    ar.close();
    return 0;
}
