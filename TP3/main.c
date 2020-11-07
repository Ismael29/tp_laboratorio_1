#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
//ismael ignacio spalletta 1A Segundo Cuatrimestre 2020 TP3
int main()
{
    char seguir='s';
    char confirma=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            system("PAUSE");
            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            system("PAUSE");
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
                system("PAUSE");
            }
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            system("PAUSE");
            break;
        case 6:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 7:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv",listaEmpleados);
                printf("Empleados Guardados Correctamente!!\n");
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 9:
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("Empleados Guardados Correctamente!!\n");
                }
                else
                {
                    printf("Error Al Guardar!! Intentelo Nuevamente. \n");
                }
            }
            else
            {
                printf("La Lista De Empleados Esta Vacia!! Primero Cargue Un Empleado. \n");
            }
            system("PAUSE");
            break;
        case 10:
            printf("Seguro Quiere Salir Del Programa?? (s/n): ");
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
            fflush(stdin);
        }
    }while(seguir=='s');
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
