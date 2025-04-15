#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <limits.h>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <iostream>
#include <fstream>
#include "diccionario.h"
using namespace std;

void imprimir(char c)
{
    for (int i = 7; i >= 0; --i)
    {
        putchar( (c & (1 << i)) ? '1' : '0' );
    }
    putchar('\n');
}

char* chartobin ( unsigned char c )
{
    static char bin[CHAR_BIT + 1] = { 0 };
    int i;

    for ( i = CHAR_BIT - 1; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }

    return bin;
}

char* chartobin2 ( unsigned char c )
{
    static char bin[9] = { 0 };
    int i;

    for ( i = 7; i >= 0; i-- )
    {
        bin[i] = (c % 2) + '0';
        c /= 2;
    }

    return bin;
}

void cast (char *c)
{
    if(c[7]=='1')
    {
        cout<<" Es Multicast";
    }
    if(c[7]=='0')
    {
        cout<<" Es Unicast ";
    }
}

void direcciones (char *c)
{
    int tam;
    tam=6;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if(!ar.is_open())
    {
        cout<<endl<<"Error."<<endl;
    }else
    {
        ch = new unsigned char [tam];
        ar.seekg (0, ios::beg);
        ar.read ((char*)ch, tam);

        char *bin;
        //----------------Destino----------------------------------------------------------
        cout<<"Direccion Destino: ";
        for(int j=0; j<6; j++)
        {
            if(j==0)
            {
                bin=chartobin(ch[j]);
            }
            printf("%02x", (int)ch[j]);
            if(j==5)
            {
                cout<<" ->";
            }else
            {
                cout<<":";
            }
        }
        cast(bin);
        //--------------Origen--------------------------------------------------------------
        cout<<endl;
        ar.seekg (6, ios::beg);
        ar.read ((char*)ch, tam);
        cout<<"Direccion Origen: ";
        for(int j=0; j<6; j++)
        {
            if(j==0)
            {
                bin=chartobin(ch[j]);
            }
            printf("%02x", (int)ch[j]);
            if(j==5)
            {
                cout<<" ->";
            }else
            {
                cout<<":";
            }
        }
        cast(bin);
        delete[] ch;
    }
    ar.close();
}

void mac (char *c)
{
    ifstream::pos_type size;
    unsigned char * memblock;
    ifstream file (c, ios::in|ios::binary|ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new unsigned char [size];
        file.seekg (0, ios::beg);
        file.read ((char*)memblock, size);

        for (int l=0; l<size; l++){
            //cout << (int)memblock[l]<<endl;
            printf("%x", (int)memblock[l]);
        }

        file.close();


        delete[] memblock;
    }else
    {
        cout<<endl<<"Error."<<endl;
    }
}
void mostrarbin(char *c)
{
    char re;
    char *bin;
    int con=0;
    ifstream ar(c);
    if(!ar.is_open())
    {
        cout<<endl<<"Error."<<endl;
    }else
    {
        while(!ar.eof())
        {
            if(ar.eof())
            {
                break;
            }
            ar.get(re);
            bin=chartobin(re);
            cout<<bin<<endl;
            con++;
        }
        cout<<endl<<con<<endl;
    }
    ar.close();
}
string tipo(char *c)
{
    int tam;
    tam=2;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if (ar.is_open())
    {
        ch = new unsigned char [tam];
        ar.seekg (12, ios::beg);
        ar.read ((char*)ch, tam);
        string s;
        stringstream ss;
        ss<<hex<<setw(2)<<setfill('0')<<(int)ch[0];
        ss<<hex<<setw(2)<<setfill('0')<<(int)ch[1];
        s="0x"+ss.str();
        cout<<endl<<"Tipo: ";
        verificardE(s);
        //printf("\nTipo: 0x%02x%02x", (int)ch[0], (int)ch[1]);
        delete[] ch;
        ar.close();
        return s;
    }else
    {
        cout<<endl<<"Error."<<endl;
        return "error";
    }
    ar.close();
    return "...";
}
void crc(char *c, int t)
{
    int tam;
    tam=4;
    unsigned char * ch;
    ifstream ar (c, ios::in|ios::binary);
    if (ar.is_open())
    {
        ch = new unsigned char [tam];
        ar.seekg (t+14, ios::beg);
        ar.read ((char*)ch, tam);
        printf("\nCRC: 0x%02x%02x%02x%02x", (int)ch[0], (int)ch[1], (int)ch[2], (int)ch[3]);
        delete[] ch;
    }else
    {
        cout<<endl<<"Error."<<endl;
    }
    ar.close();
}

#endif // FUNCIONES_H_INCLUDED
