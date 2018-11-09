#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


int main(int argc, char const *argv[])
{

    const clock_t t0 = clock();


    ifstream archivo;
    archivo.open(argv[1], ios::in);

//Inicializar contadores para las secuencias [Se puede buscar una secuencia
//especifica, pero es mas facil en este caso por ser numeros consecutivos]

    int seq[5] = {0,0,0,0,0};
    int c = 0;

//number sera cada uno de los caracteres del archivo a evaluar
    char number;
    archivo.get(number);

////////////////////////CONTEO DE APARICIONES///////////////////////////////////

//Evalua cada caracter progresivamente hasta terminar con todo el archivo
    while(!archivo.eof()){
        if(number== 1){
            c=1;
            seq[0]++;
        }
        else{
            if(number-'0'== c+1){
                seq[c]++;
                c++;
                if(c==5){
                    c=0;
                    }
            }
            else{
                c=0;
                }
        }

        archivo.get(number);
    }

////////////////////////EXPORTAR CUENTAS Y TIEMPOS//////////////////////////////

//Exportar datos de numero de apariciones de la secuencia a un nuevo documento
    ofstream Respuestas;
    Respuestas.open(argv[2]);
    for(int i=0;i<5;i++)
    {
        Respuestas << seq[i] << endl;
    }
    Respuestas.close();


//Exportar datos de tiempos de ejecucion de tarea a un nuevo documento
    ofstream TiemposEjec;
    TiemposEjec.open(argv[3]);
    TiemposEjec << float(clock()-t0)/CLOCKS_PER_SEC;
    TiemposEjec.close();

////////////////////////FIN DEL CODIGO/////////////////////////////////////////
    return 0;

}
