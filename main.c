#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <inttypes.h>
#include "ismaelspallettafunciones.h"


int main()
{
    int primerOperador=0;
    int segundoOperador=0;
    char opcion;
    int banderaDeOperacionesRealizadas=0;
    int banderaDeOperadorUnoIngresados=0;
    int banderaDeOperadorDosIngresados=0;

    do{
    printf("\n***CALCULADORA UTN***\n");
    printf("\n 1.   Ingresar 1er operador. (A=%d)\n",primerOperador);
    printf("\n 2.   Ingresar 2do operador. (B=%d)\n",segundoOperador);
    printf("\n 3.   Calcular todas las operaciones.\n");
    printf("\n \t a)   Calcular la suma.\n");
    printf("\n \t b)   Calcular la resta.\n");
    printf("\n \t c)   Calcular la division.\n");
    printf("\n \t d)   Calcular la multiplicacion.\n");
    printf("\n \t e)   Calcular el factorial.\n");
    printf("\n 4.   Informar resultados.\n");
    printf("\n \t a)   El resultado de A+B es: r\n");
    printf("\n \t b)   El resultado de A-B es: r\n");
    printf("\n \t c)   El resultado de A/B es: r\n");
    printf("\n \t d)   El resultado de A*B es: r\n");
    printf("\n \t c)   El factorial de A es: r1 y El factorial de B es:r2\n");
    printf("\n 5.   Salir\n");
    printf("\n\nIngrese Opcion: ");
    fflush(stdin);
    scanf("%c",&opcion);
    getch();

    switch(opcion)
    {

    case '1':
        system("cls");
        printf("Ingrese el primer operador:\n");
        scanf("%d",&primerOperador);
        banderaDeOperadorUnoIngresados=1;
        break;
    case '2':
        system("cls");
        printf("Ingrese el segundo operador:\n");
        scanf("%d",&segundoOperador);
        banderaDeOperadorDosIngresados=1;
        break;
    case '3':
        system("cls");
        if((banderaDeOperadorUnoIngresados&&banderaDeOperadorDosIngresados)==0){
            printf("Error... Primero tiene que ingresar los 2 operadores.");
        }
        else{
            int calcularSuma(int primerOperador,int segundoOperador);
            int calcularResta(int primerOperador,int segundoOperador);
            float calcularDivision(int primerOperador,int segundoOperador);
            int calcularMultiplicacion(int primerOperador,int segundoOperador);
            int factorialPrimerOperador(int primerOperador);
            int factorialSegundoOperador(int segundoOperador);
            printf("Calculando...\n");
            banderaDeOperacionesRealizadas=1;
        }
        break;
    case '4':
        system("cls");
        if(banderaDeOperacionesRealizadas==1){

            printf("El resultado de A+B es: %d\n",calcularSuma(primerOperador,segundoOperador));
            printf("El resultado de A-B es: %d\n",calcularResta(primerOperador,segundoOperador));
            if(segundoOperador==0){
                printf("No se puede dividir por 0.\n");
            }
            else{
                printf("El resultado de A/B es: %.2f\n",calcularDivision(primerOperador,segundoOperador));
            }
            printf("El resultado de A*B es: %d\n",calcularMultiplicacion(primerOperador,segundoOperador));
           if(primerOperador <0 || segundoOperador < 0){
                printf("No se puede realizar factorial de un numero negativo.");
           }
           else{
                printf("El factorial de A! es: %d y El factorial de B! es: %d",factorialPrimerOperador(primerOperador),factorialSegundoOperador(segundoOperador));
           }

        }
        else{
            printf("Para Mostrar los resultados primero tiene que calcular...");
        }
        break;
    case '5':
        system("exit");
        break;
    default:
            printf("Opcion Invalida!!!\n\n");
            break;
    }
   }while(opcion!='5');
    return 0;
}


