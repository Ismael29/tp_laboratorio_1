#include "ismaelspallettafunciones.h"

int calcularSuma(int primerOperador,int segundoOperador){
    int suma;
    suma=primerOperador+segundoOperador;
    return suma;
}
int calcularResta(int primerOperador,int segundoOperador){
    int resta;
    resta=primerOperador-segundoOperador;
    return resta;
}
float calcularDivision(int primerOperador,int segundoOperador){
    float division;
    division=primerOperador/segundoOperador;
    return division;
}
int calcularMultiplicacion(int primerOperador,int segundoOperador){
    int multiplicacion;
    multiplicacion=primerOperador*segundoOperador;
    return multiplicacion;
}
int factorialPrimerOperador(int primerOperador){

    int factorial=1;

    for(int i=1; i<=primerOperador; i++){
        factorial=factorial*i;
    }
    return factorial;
}
int factorialSegundoOperador(int segundoOperador){

    int factorial=1;

    for(int i=1; i<=segundoOperador; i++){
        factorial=factorial*i;
    }
    return factorial;
}
