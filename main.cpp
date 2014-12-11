// queue::push/pop
#include "Evaluador.h"
#include "NodoAVL.h"
#include <iostream>
#include "tinyxml2.h"
#include <iostream>
#include <list>
using namespace std;
using namespace tinyxml2;

//Devuelve la cantidad de usuarios que tiene 18 anios o mas dado el nombre de un archivo XML
int contarMayoresDeEdadXML(string nombre_archivo)
{
    int n = 0;
    int edad = 0;
    XMLDocument doc;
    doc.LoadFile(nombre_archivo.c_str());
    XMLElement* Usuarios = doc.FirstChildElement("Usuarios");
    for(XMLElement* Usuario = Usuarios->FirstChildElement("Usuario");
            Usuario!=NULL;
            Usuario=Usuario->NextSiblingElement())
    {
        if (atoi(Usuario->Attribute("edad")) >= 18){
            n++;
        }
    }
    return n;
    return -1;
}

//Devuelve el numero anterior del nodo raiz de un Arbol dado
int obtenerNumeroAnterior(NodoAVL* raiz)
{
    NodoAVL* temp= raiz->izq;
    int n;
    while(temp != NULL){
        n=temp->num;
        temp = temp->der;
    }
    return n;
}

//Devuelve el numero siguiente del nodo raiz de un Arbol dado
int obtenerNumeroSiguiente(NodoAVL* raiz)
{
    NodoAVL* temp;
    int n;
    for(temp = raiz->der; temp != NULL; temp=temp->izq){
        n=temp->num;
    }
    return n;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
