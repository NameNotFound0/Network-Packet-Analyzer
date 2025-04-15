#ifndef ARP_H_INCLUDED
#define ARP_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;

void arp (char *c)
{
    int tam;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if(!ar.is_open())
    {
        cout<<endl<<"Error."<<endl;
    }else
    {
        cout<<endl<<"                ARP                 "<<endl;
        tam=2;
        ch = new unsigned char [tam];
        ///-------Hardware type------------------------
        ar.seekg (14, ios::beg);
        ar.read ((char*)ch, tam);
        char *bin, *cc;
        long int n;
        string s;
        stringstream sss,z;
        bin=chartobin(ch[0]);
        sss<<bin;
        bin=chartobin(ch[1]);
        sss<<bin;
        s=sss.str();
        n=strtoull(s.c_str(), &cc, 2);
        z<<n;
        s=z.str();
        verificarHT(s);
        //cout<<endl<<"Hardware Type: "<<s;
        /*cout<<endl<<"Hardware Type: "<<(int)ch[0];
        if((int)ch[0]==1)
        {
            cout<<" -> Ethernet";
        }*/
        ///-------Protocol Type------------------------
        tam=2;
        ar.seekg (16, ios::beg);
        ar.read ((char*)ch, tam);
        stringstream ss;
        ss<<hex<<setw(2)<<setfill('0')<<(int)ch[0];
        ss<<hex<<setw(2)<<setfill('0')<<(int)ch[1];
        s="0x"+ss.str();
        cout<<endl<<"Protocol Type: ";
        verificardE(s);
        //printf("0x%02x%02x", (int)ch[0], (int)ch[1]);
        ///-------Hardware Size------------------------
        tam=1;
        ar.seekg (18, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Hardware Size: "<<(int)ch[0];
        ///-------Protocol Size------------------------
        tam=1;
        ar.seekg (19, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Protocol Size: "<<(int)ch[0];
        ///-------OPCODE/request/reply-----------------
        tam=1;
        cout<<endl<<"OPCODE: ";
        ar.seekg (21, ios::beg);
        ar.read ((char*)ch, tam);
        if((int)ch[0]==1)
        {
            cout<<(int)ch[0]<<" -> Request";
        }else
        {
            cout<<(int)ch[0]<<" -> Reply";
        }
        ///--------Sender Mac----------------------
        tam=6;
        ar.seekg (22, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Sender Mac: ";
        for(int j=0; j<6; j++)
        {
            printf("%02x", (int)ch[j]);
            if(j<5)
            {
                cout<<":";
            }
        }
        ///-----------Sender IP---------------------
        tam=4;
        ar.seekg (28, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Sender IP: ";
        for(int j=0; j<4; j++)
        {
            printf("%d", (int)ch[j]);
            if(j<3)
            {
                cout<<".";
            }
        }
        ///-----------Tarjet MAC----------------------
        tam=6;
        ar.seekg (32, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Tarjet Mac: ";
        for(int j=0; j<6; j++)
        {
            printf("%02x", (int)ch[j]);
            if(j<5)
            {
                cout<<":";
            }
        }
        ///------------Tarjet IP----------------------
        tam=4;
        ar.seekg (38, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<endl<<"Tarjet IP: ";
        for(int j=0; j<4; j++)
        {
            printf("%d", (int)ch[j]);
            if(j<3)
            {
                cout<<".";
            }
        }

        delete[] ch;
    }
    ar.close();
}
#endif // ARP_H_INCLUDED
