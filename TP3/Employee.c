#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "validaciones.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    Employee* newEmployee;

    newEmployee = employee_new();

    if(newEmployee != NULL)
    {
        if((employee_setId(newEmployee, atoi(idStr))== -1)||(employee_setNombre(newEmployee, nombreStr)==-1)||(employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr))==-1)||(employee_setSueldo(newEmployee, atoi(sueldo))==-1))
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

int employee_setId(Employee* this,int id)
{
    int error = -1;

    if(this != NULL && id >0 && id <= 10000)
    {
        this-> id = id;
        error = 1;
    }
    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = -1;
    if(this != NULL && id!=NULL)
    {
        *id = this-> id;
        error = 1;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = -1;

    if (this != NULL  && strlen(nombre) >= 3  && strlen(nombre) < 127)
    {
        strcpy(this ->nombre,nombre);
        error = 1;
    }
    return error;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int error = -1;
    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        error = 1;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int error = -1;

    if(this != NULL && horasTrabajadas >0 && horasTrabajadas <= 2000 )
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 1;
    }
    return error;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int error = -1;
    if(this!= NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 1;
    }
    return error;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int error = -1;

    if(this != NULL && sueldo >0 && sueldo <= 200000 )
    {
        this-> sueldo = sueldo;
        error = 1;
    }
    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = -1;
    if ( this != NULL && sueldo != NULL)
    {
        *sueldo = this -> sueldo;
        error = 1;
    }
    return error;
}

void employee_delete(Employee* this )
{
    if(this != NULL)
    {
        free(this);
    }
}

int mostrarEmpleado(Employee* this)
{
    int error =-1;
    if(this != NULL)
    {
        error = 1;
        printf("%4d  %20s  %4d                    %5d \n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }
    return error;
}

int compareEmployeesByName(void* empA,void* empB)
{
    int orden = 0;
    if( empA != NULL && empB != NULL )
    {
        Employee* pEmpA = (Employee*) empA;
        Employee* pEmpB = (Employee*) empB;
        if (strcmp(pEmpA->nombre, pEmpB->nombre) > 0)
        {
            orden = 1;
        }
        else if(strcmp(pEmpA->nombre, pEmpB->nombre) < 0)
        {
            orden = -1;
        }
    }
    return orden;
}

int menuDeModificacion()
{
    int opcion;
    system("cls");
    printf("\n****** Sub Menu De Modificacion De Empleado ****** \n");
    printf("-------------------------------------------------------");
    printf("\n1.  Modificar Nombre.\n");
    printf("2.  Modificar Horas Trabajadas.\n");
    printf("3.  Modificar Sueldo.\n");
    printf("4.  Salir.\n");

    if(utn_getNumero(&opcion,"Ingrese opcion:  ","",1,4,0) == -1)
    {
        opcion = 0;
    }
    return opcion;
}

int modificarEmpleado(Employee* this)
{
    int error = -1;
    int horasTrabajadas;
    int sueldo;
    int nuevoNombre;
    int nuevasHorasTrabajadas;
    int nuevoSueldo;
    char continuar = 's';
    char nombre[128];

    system("cls");
    do
    {
        switch(menuDeModificacion())
        {
        case 1:
            nuevoNombre = utn_getNombre(nombre, 127,"Ingrese Nombre Nuevo: ","Ingrese Solo Letras O Su Nombre Es Muy Largo!!",3);
            if (nuevoNombre== 1)
            {
                employee_setNombre(this, nombre);
                modificacionSinError(this);
                error = 1;
            }
            break;
        case 2:
            nuevasHorasTrabajadas = utn_getNumero(&horasTrabajadas, "Ingrese Cantidad Nueva De Horas Trabajadas: ","Error!! La Cantidad De Horas Tiene Que Ser Entre 1 Y 2000.\n",1,2000,3);
            if (nuevasHorasTrabajadas ==1)
            {
                employee_setHorasTrabajadas(this, horasTrabajadas);
                modificacionSinError(this);
                error = 1;
            }
            break;
        case 3:
            nuevoSueldo = utn_getNumero(&sueldo, "Ingrese Nuevo Sueldo: ","Error!! El Sueldo Tiene Que Ser Entre 1 y 100000.\n",1,100000,3);
            if(nuevoSueldo == 1)
            {
                employee_setSueldo(this, sueldo);
                modificacionSinError(this);
                error = 1;
            }
            break;
        case 4:
            continuar = 'n';
            break;
        case 0:
            printf("\nError!! Opcion Invalida!!\n");
            break;
        }
    }
    while(continuar=='s');

    return error;
}

void modificacionSinError(Employee* this)
{
    printf("Se Modifico Empleado Correctamente!!\n\n");
    printf("\n  ID                Nombre  Horas Trabajadas          Sueldo \n");
    printf("--------------------------------------------------------------------------\n");
    mostrarEmpleado(this);
    system("PAUSE");
}

int buscarEmpleadoPoriD(LinkedList* pArrayListEmployee, int id)
{
    int empleadoIndice = -1;
    int idAuxiliar;
    Employee* auxEmpleado;

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmpleado = ll_get(pArrayListEmployee, i);
        if(employee_getId(auxEmpleado, &idAuxiliar) && idAuxiliar == id)
        {
            empleadoIndice = i;
            break;
        }
    }
    return empleadoIndice;
}

int menu()
{
    int opcion;

    system("cls");
    printf("********************************************************************************* \n\n");
    printf("*************************** \n");
    printf("**** Menu De Empleados **** \n");
    printf("*************************** \n\n");
    printf("1.   Cargar los datos de los empleados desde el archivo data.csv (modo texto).  \n");
    printf("2.   Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
    printf("3.   Alta de empleado.\n");
    printf("4.   Modificar datos de empleado.\n");
    printf("5.   Baja de empleado.\n");
    printf("6.   Listar empleados.\n");
    printf("7.   Ordenar empleados.\n");
    printf("8.   Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9.   Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10.  Salir.\n");
    printf("********************************************************************************* \n\n");
    if(utn_getNumero(&opcion,"Ingrese Opcion: "," ",1,10,0)== -1)
    {
        opcion = 0;
    }
    return opcion;
}


