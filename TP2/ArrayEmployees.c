#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

int menu()
{
    int opcion;

    printf("* * * Sistema ABM UTN TP2 * * *\n\n\n");
    printf("1) ALTAS.\n\n");
    printf("2) MODIFICAR.\n\n");
    printf("3) BAJA.\n\n");
    printf("4) INFORMAR.\n\n");
    printf("5) SALIR.\n\n");
    printf("\n\nIngrese Opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    while(isalpha(opcion)!=0)
    {
        printf("Error Ingrese un numero...\n");
        fflush(stdin);
        printf("\n\nIngrese Opcion: ");
        scanf("%d",&opcion);
    }
    return opcion;
}
int initEmployees(Employee employeeList[], int len)
{
    int error= -1 ;

    if(employeeList!= NULL && len > 0 ) // validar vector con != de null
    {
        for(int i=0; i < len ; i++)
        {
            employeeList[i].isEmpty = 1; // se recorre todo empty y lo cambia a 1
        }
        error=0;
    }
    return error;
}

int enterAddEmployee(Employee employeeList[],int len,int id)
{
    int answerScanner;
    int error=-1;

    Employee auxEmployee;

    printf("Ingrese Nombre: ");
    fflush(stdin);
    gets(auxEmployee.name);

    printf("Ingrese Apellido: ");
    fflush(stdin);
    gets(auxEmployee.lastName);


    printf("Ingrese Sueldo: ");
    fflush(stdin);
    answerScanner=scanf("%f",&auxEmployee.salary);

    while(auxEmployee.salary<0 || answerScanner==0)
    {
        printf("Error...Sueldo no valido ingrese nuevamente");
        printf("\n\nIngrese Sueldo: ");
        fflush(stdin);
        answerScanner=scanf("%f",&auxEmployee.salary);
    }

    printf("Ingrese sector: ");
    fflush(stdin);
    answerScanner=scanf("%d",&auxEmployee.sector);
    while(auxEmployee.sector<0 || answerScanner==0)
    {
        printf("Error...Sector no valido ingrese nuevamente!!\n\n");
        printf("Ingrese sector: ");
        fflush(stdin);
        answerScanner=scanf("%d",&auxEmployee.sector);
    }
    auxEmployee.id=id;
    if(addEmployee(employeeList,len,auxEmployee.id,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector)==0)
    {
        error=0;
    }
    return error;
}

int addEmployee(Employee employeeList[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int error=-1;
    int index;

    if( employeeList != NULL && len > 0)
    {
        index=searchForSpace(employeeList,len);
        if(index==-1)
        {
            printf("No hay espacio,sistema lleno!!\n");
        }
        strncpy(employeeList[index].name,name,51);
        strncpy(employeeList[index].lastName,lastName,51);
        employeeList[index].id = id;
        employeeList[index].salary = salary;
        employeeList[index].sector = sector;
        employeeList[index].isEmpty = 0;
        error = 0;
    }
    return error;
}

int searchForSpace(Employee employeeList[],int len)
{
    int index=-1;

    for(int i=0 ; i < len ; i++)
    {
        if(employeeList[i].isEmpty == 1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int findEmployeeById(Employee employeeList[], int len,int id)
{

    int index=-1;

    for(int i=0 ; i < len ; i++)
    {
        if(employeeList[i].id == id && employeeList[i].isEmpty==0)
        {
            index=i;
            break;
        }
    }
    return index;
}
int removeEmployee1(Employee employeeList[],int len)
{
    int error=-1;
    int id;
    printEmployees(employeeList,len);
    printf("Ingrese Id: ");
    scanf("%d",&id);

    if(removeEmployee(employeeList,len,id)==0)
    {
        error=0;

        printf("Baja de empleado exitosa!!");
    }
    return error;
}


int removeEmployee(Employee employeeList[], int len,int id) //0 baja exitosa, 1 problemas, 2 se cancelo la baja
{
    int error=-1;
    int index;
    char confirm;

    if(employeeList!=NULL && len > 0 && id > 0)
    {
        system("cls");

        printf(" * * * * Dar De Baja Un Empleado * * * * \n\n");

        index=findEmployeeById(employeeList,len,id);

        if(index == -1 )
        {
            printf("No hay ninguna persona con ese id.\n");
        }
        else
        {
            printEmployee(employeeList[index]);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s')
            {
                employeeList[index].isEmpty=1;
                error=0;
            }
            else
            {
                error=2;
            }
        }
    }
    return error;
}

int sortEmployees(Employee employeeList[], int len, int order)
{
    int error=-1;
    Employee aux;
    if(employeeList != NULL && len > 0 && order >= 0)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(order==0 && employeeList[i].sector > employeeList[j].sector) // ordena des
                {
                    aux=employeeList[i];
                    employeeList[i]=employeeList[j];
                    employeeList[j]=aux;
                }
                else if(order==1 && employeeList[i].sector < employeeList[j].sector) //ordena asc
                {
                    aux=employeeList[i];
                    employeeList[i]=employeeList[j];
                    employeeList[j]=aux;
                }
                else if(employeeList[i].sector == employeeList[j].sector && employeeList[i].lastName > employeeList[j].lastName && order==0) // ordena des
                {
                    aux=employeeList[i];
                    employeeList[i]=employeeList[j];
                    employeeList[j]=aux;
                }
                else if(employeeList[i].sector == employeeList[j].sector && employeeList[i].lastName < employeeList[j].lastName && order==1) // ordena  asc
                {
                    aux=employeeList[i];
                    employeeList[i]=employeeList[j];
                    employeeList[j]=aux;
                }
            }
        }
        error=0;
    }
    return error;
}

int printEmployees(Employee employeeList[], int length)
{
    int flag=0;
    if(employeeList!=NULL && length>0)
    {
        printf("\n\n ID      Nombre     Apellido     Salario     Sector     IsEmpty \n\n ");
        printf("---------------------------------------------------------------\n\n ");
        for( int i = 0 ; i < length ; i++ )
        {
            if(employeeList[i].isEmpty ==0)
            {
                printEmployee(employeeList[i]);
                flag=1;
            }
        }
        if(flag == 0)
        {
            printf("No existen empleados todavia... \n\n");
        }
    }
    return 0;
}

void printEmployee(Employee anEmployee)
{
    printf("\n%d     %s     %s     %.2f       %d           %d \n\n",anEmployee.id,anEmployee.name,anEmployee.lastName,anEmployee.salary,anEmployee.sector,anEmployee.isEmpty);
}

int modifyEmployee(Employee employeeList[], int len)
{
    int answerScann;
    int error=-1;
    int indice;
    int id=1;
    char confirma;
    Employee newEmployee;
    if(employeeList!= NULL && len > 0 && id > 0 )
    {
        system("cls");
        printf("*** Modificar Empleado***");
        printEmployees(employeeList,len);
        printf("Ingrese ID: ");
        scanf("%d",&id);

        indice=findEmployeeById(employeeList,len,id);

        if(indice==-1)
        {
            printf("No hay ninguna persona con ese ID\n");
        }
        else
        {
            system("cls");
            printEmployee(employeeList[indice]);
            printf("Que Quiere Modificar?\n");
            switch(subMenu())
            {
            case 1:
                fflush(stdin);
                printf("Ingrese nuevo Nombre:  ");
                gets(newEmployee.name);
                printName(newEmployee);
                printf("Confirma nuevo Nombre: ??\n");
                fflush(stdin);
                scanf("%c",&confirma);
                if(confirma =='s')
                {
                    strcpy(employeeList[indice].name,newEmployee.name);
                    error=0;

                }
                else
                {
                    error=2;
                }
                break;
            case 2:
                system("cls");
                fflush(stdin);
                printf("Ingrese nuevo Apellido:  ");
                gets(newEmployee.lastName);
                printLastName(newEmployee);
                printf("Confirma nuevo Apellido: ??\n");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma =='s')
                {
                    strcpy(employeeList[indice].lastName,newEmployee.lastName);
                    error=0;
                }
                else
                {
                    error=2;
                }
                break;
            case 3:
                do
                {
                    printf("Ingrese nuevo Salario:  ");
                    fflush(stdin);
                    answerScann=scanf("%f",&newEmployee.salary);
                    printSalary(newEmployee);

                }
                while(answerScann==0);

                printf("Confirma nuevo Salario: ??\n");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma =='s')
                {
                    employeeList[indice].salary=newEmployee.salary;
                    error=0;
                }
                else
                {
                    error=2;
                }
                break;
            case 4:
                printf("Ingrese nuevo Sector:  ");
                scanf("%d",&newEmployee.sector);
                printSector(newEmployee);
                printf("Confirma nuevo Sector: ??\n");
                fflush(stdin);
                scanf("%c",&confirma);
                if(confirma =='s')
                {
                    employeeList[indice].sector=newEmployee.sector;
                    error=0;
                }
                else
                {
                    error=2;
                }
                break;
            }
        }
    }
    return error;
}

int subMenu()
{
    int opcion;

    system("cls");
    printf("* * * Que quiere modificar? * * *\n\n\n");
    printf("1) NOMBRE.\n\n");
    printf("2) APELLIDO.\n\n");
    printf("3) SALARIO.\n\n");
    printf("4) SECTOR.\n\n");
    printf("\n\nIngrese Opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
void printName(Employee employeeName)
{
    printf("Nombre: %s \n",employeeName.name);
}

void printLastName(Employee employeeLastName)
{
    printf("Apellido: %s \n",employeeLastName.lastName);
}

void printSalary(Employee employeeSalary)
{

    printf("Salario: %.2f \n",employeeSalary.salary);
}

void printSector(Employee employeeSector)
{
    printf("Sector: %d \n",employeeSector.sector);
}

void printSalaryFull(Employee employeeList[],int len)
{
    float totalSalary=0;
    float averageSalary=0;
    int countEmployee=0;
    int employeeMoreThanAverage=0;

    for(int i = 0 ; i < len ; i++)
    {
        if(employeeList[i].isEmpty==0)
        {
            totalSalary=totalSalary+employeeList[i].salary;
            countEmployee++;
        }
    }
    averageSalary=totalSalary/countEmployee;

    for(int i =0; i<len; i++)
    {
        if(employeeList[i].isEmpty==0)
        {
            if(employeeList[i].salary>averageSalary)
            {
                employeeMoreThanAverage++;
            }
            else
            {
                printf("\nNo hay empleados con un sueldo superior al promedio de los mismos...\n");
            }
        }
    }
    printf("La suma total de los sueldos es: %.2f \n\n",totalSalary);
    printf("El promedio del salario es: %.2f  \n\n",averageSalary);
    printf("El numero de empleados que gana mas que el promedio es: %d  \n\n",employeeMoreThanAverage);
}



