#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include "Evaluador.h"
#include  <stdio.h>
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve el atributo *nombre* de *usuario*
string getNombre(Usuario* usuario)
{
    Usuario u = *usuario;
    return u.nombre;
}

//Escribe todos los atributos de *usuario* en un archivo con con nombre *nombre_archivo*
void escribir(string nombre_archivo, Usuario* usuario)
{
    Usuario n = *usuario;
   ofstream archivo(nombre_archivo.c_str());
    archivo<<n.nombre<<" "<<n.edad<<endl;
    archivo.close();
}

//Lee los atributos de un *Usuario* desde un archivo con nombre *nombre_archivo* y luego lo devuelve
Usuario* leer(string nombre_archivo)
{
   ifstream in(nombre_archivo.c_str());
   int edad;
    string nombre;
    in>>edad;
   in>>nombre;
   in.close();
   Usuario n(nombre,edad );
   Usuario* e = &n;
    return e;
}

//Devuelve cuantas veces existe *numero* en *numeros*
int contar(vector<int> numeros, int numero)
{
    int n = 0;
    for(int i=0; i<numeros.size(); i++)
    {
        if(numeros[i]==numero)
        {
            n+=1 ;
        }
    }
    return n;
}

//Devuelve *true* si existe al menos un valor repetido en *cadenas*
bool existeRepetida(list<string> cadenas)
{
   cadenas.sort();
   int m =cadenas.size();
    cadenas.unique();
    int n =cadenas.size();
    if (n==m){
         return false;
}
return true;
}

//Devuelve el contenido de *letras* invertido
vector<char> invertir(vector<char>letras)
{vector<char> r;
    int n = letras.size();
    for(int i = 0; i<n;i++){
    r.push_back(letras.back());
    letras.pop_back();
    }
    return r;

}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las siguientes clases dado el diagrama adjunto

//Lugar
//Lugar() Constructor vacio
//vendeComida() Funcion abstracta

//Restaurante
//Restaurante() Inicializa atributos
//vendeComida() Devuelve true

//Monumento
//Monumento() Inicializa atributos
//vendeComida() Devuelve false

///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();
class Lugar
{
    public:
        string Nombre;
        double Latitud;
        double Longitud;
        Lugar(){
        }
       virtual bool vendeComida();

};

class Restaurante
{
    public:
    string horario;
    string nombre;
    double latitud;
    double longitud;
     Restaurante(string nombre,double latitud,double longitud,string horario)
    {
        this->horario = horario;
        this->latitud = latitud;
        this->longitud = longitud;
        this->nombre = nombre;
    }
    bool vendeComida()
    {
        return true;
    }
};
class Monumento
{
    public:
    string nombre;
    double latitud;
    double longitud;
    Monumento(string nombre,double latitud,double longitud)
    {
        this->latitud = latitud;
        this->longitud = longitud;
        this->nombre =nombre;
    }
    bool vendeComida()
    {
     return false;
    }

};
int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////


void evaluar2()
{
    double nota = 0;

    cout<<"**Clase Restaurante**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Restaurante("Burger Queen",5.2,6.2,"24/7").nombre == "Burger Queen"
       && Restaurante("Burger Queen",6.1,6.2,"24/7").latitud == 6.1
       && Restaurante("Burger Queen",5.2,6.6,"24/7").longitud == 6.6
       && Restaurante("Burger Queen",5.2,6.2,"lunes a viernes").horario == "lunes a viernes"

       && Restaurante("Mc Ronald",5.2,6.2,"24/7").nombre == "Mc Ronald"
       && Restaurante("Mc Ronald",10.1,6.2,"24/7").latitud == 10.1
       && Restaurante("Mc Ronald",5.2,8.6,"24/7").longitud == 8.6
       && Restaurante("Mc Ronald",5.2,6.2,"siempre").horario == "siempre"
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(Restaurante("Burger Queen",5.2,6.2,"24/7").vendeComida()
       && Restaurante("Mc Ronalds",5.2,6.2,"24/7").vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    cout<<"**Clase Monumento**"<<endl;
    cout<<"Test constructor:\t\t";
    if(Monumento("Burger Queen",5.2,6.2).nombre == "Burger Queen"
       && Monumento("Burger Queen",6.1,6.2).latitud == 6.1
       && Monumento("Burger Queen",5.2,6.6).longitud == 6.6

       && Monumento("Mc Ronald",5.2,6.2).nombre == "Mc Ronald"
       && Monumento("Mc Ronald",10.1,6.2).latitud == 10.1
       && Monumento("Mc Ronald",5.2,8.6).longitud == 8.6
       )
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<"Test vendeComida():\t\t";

    if(!Monumento("Burger Queen",5.2,6.2).vendeComida()
       && !Monumento("Mc Ronalds",5.2,6.2).vendeComida())
    {
        nota+=2;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/8"<<endl;
}
