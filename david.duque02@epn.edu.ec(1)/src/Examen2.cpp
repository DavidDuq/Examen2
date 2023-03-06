#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <unistd.h>
#include <string>
#include <conio.h>
#include <iomanip>
#include "../lib/ddcolor.h"

// https://github.com/DavidDuq/Examen2.git

using namespace std;

// AUTOR : DAVID ALEJANDRRO DUQUE INTRIAGO
// FECHA : 06/03/2023

const int ddcedula = 1753494523;
const string ddnombrecompleto = "David Alejandro Duque Intriago"; 


void ddCoordenadas( string nombreArchivo) 
{
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    cout << "[+]Coordenadas leidas.....: " << endl;
       cout << COLOR_RED;
    cout << "     ERROR :   cap,   Geo,   Tipo Arcenal -->stoi" << endl;
        cout << COLOR_WHITE;
    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            int jq =0;
            string c= "-"; 
            for(int i=0; i<= 100  ; i++)
            {   
                if(i % 4 ==0)
                jq =0;
                    cout  << "\r" << c[jq++]   
                    << "    " << i << "%";
            usleep(9000);
            }
        cout << linea << endl;
        }
        archivo.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo." <<endl;
   }
}
 


 void ddinformacion()
 {
    cout <<COLOR_BLUE << "\n[+] Informacion Arbol Binario de capacidad belica Ucranica" << endl;
        cout <<"\t Devloper-Nombre :" << ddnombrecompleto <<endl;
        cout <<"\t Devloper-Cedula :" << ddcedula         <<endl;
        cout <<"\t Capacidad Belica:10"                   <<endl;
        cout <<"\t Coordenada total:3"                    <<endl;
        cout <<"\t Coordenada-Secarga: 1, 7, 2"           <<endl;

 }


struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;

ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}


int main()
 {
    string archivo_cordenadas ="data/cordenadas.txt";
    ddCoordenadas(archivo_cordenadas);
   
    // ABB arbol = NULL;   // creado Arbol

    // int n;  // numero de nodos del arbol
    // int x; // elemento a insertar en cada nodo

    // cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    // cout << " Numero de nodos del arbol:  ";
    // cin >> n;
    // cout << endl;

    // for(int i=0; i<n; i++)
    // {
    //     cout << " Numero del nodo " << i+1 << ": ";
    //     cin >> x;
    //     insertar( arbol, x);
    // }

    // cout << "\n Mostrando ABB \n\n";  verArbol( arbol, 0);
    // cout << "\n Recorridos del ABB";
    // cout << "\n\n En orden   :  ";   enOrden(arbol);
    // cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    // cout << "\n\n Post Orden :  ";   postOrden(arbol);
    // cout << endl << endl;
    // return 0;
    ddinformacion();

 }

