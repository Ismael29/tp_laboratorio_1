#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define LEN 1000
/*
Ismael ignacio spalletta , Com 1A.
Todas las funciones y variables estan escritas en ingles para respetar como fueron entregados los prototipos (todos en ingles).
Las funciones con punteros fueron modificadas para no utilizarlas ya que en nuestro curso se explica luego del primer parcial.
*/
int main()
{
    int nextIdOfEmployee=0;
    int answer;
    int continueWithLoop=5;
    char confirm;
    Employee employeeList[LEN];
    int flagEmployeeExist=0;

    if(initEmployees(employeeList,LEN)==0)
    {
        nextIdOfEmployee++;
        printf("El Sistema Inicializo Correctamente!!!\n\n");
    }
    else
    {
        printf("Fallo la Inicializacion del programa!!\n\n");
    }
    do
    {
        system("PAUSE");
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");
            if(enterAddEmployee(employeeList,LEN,nextIdOfEmployee)==0)
            {
                nextIdOfEmployee++;
                printf("Empleado Agregado!!\n");
                flagEmployeeExist=1;
            }
            else
            {
                printf("No se puede agregar un nuevo empleado!!\n");
            }
            break;
        case 2:
            system("cls");
            if(flagEmployeeExist==1)
            {
                system("cls");

                answer=modifyEmployee(employeeList,LEN);

                if(answer==0)
                {
                    printf("Se modifico con exito\n");
                }
                else if(answer==2)
                {

                    printf("Modificacion Cancelada por el usuario\n");
                }
                else
                {
                    printf("Error en la Modificaicon\n");
                }
            }
            else
            {
                printf("Para modificar un empleado primero debe existir uno!!!\n\n\n");
            }
            break;
        case 3:
            system("cls");
            if(flagEmployeeExist==1)
            {
                answer=removeEmployee1(employeeList,LEN);
                if(answer==0)
                {
                    printf("Empleado dado de baja!! \n\n");
                }
                else if(answer==-1)
                {
                    printf("Error..no se puede dar de baja un empleado\n\n");
                }
                else
                {
                    printf("El usuario cancelo la accion!!\n\n");
                }
            }
            else
            {
                printf("Para dar de baja un empleado primero debe existir uno!!\n\n\n");
            }
            break;
        case 4:
            system("cls");
            sortEmployees(employeeList,LEN,1);  // ordena priorizando el sector sobre el apellido, luego si el sector es el mismo por el apellido, cambiando 0 y 1 se cambia el orden del ordenamiento
            printEmployees(employeeList,LEN);
            printSalaryFull(employeeList,LEN);
            break;
        case 5:
            system("cls");
            printf("Seguro que quiere salir?:\n ");
            fflush(stdin);
            scanf("%c", &confirm);
            confirm = tolower(confirm);
            if(confirm == 's')
            {
                continueWithLoop = 'n';
            }
            break;
        }
    }
    while(continueWithLoop==5);

    return 0;
}
