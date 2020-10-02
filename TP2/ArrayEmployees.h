#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED



#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Ejecuta el menu grafico del proyecto
 *
 * \param - No posee
 * \param - No posee
 * \return -Funcion Void
 *
 */int menu();


/** \brief estructura de tupo Employe
 *
 * \param numero enterdo
 * \param nombre
 * \param apellido
 * \param salario
 * \param sector
 * \param numero qeu representa si hay espacio o no en la lista
 * \return
 *
 */struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;




/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/int initEmployees(Employee employeeList[], int len);




/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */int addEmployee(Employee employeeList[], int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */int findEmployeeById(Employee employeeList[], int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can'tfind a employee] - (0) if Ok
*
*/int removeEmployee(Employee employeeList[], int len,int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */int sortEmployees(Employee employeeList[], int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/int printEmployees(Employee employeeList[], int length);

/** \brief print one employee
 *
 * \param an employee type Employee
 *
 * \return un entero para validar condicion
 *
 */void printEmployee(Employee anEmployee);

 /** \brief busca el primer lugar con el isEmpty en 1
  *
  * \param lista de empleados de tipo empleado
  * \param tamaño
  * \return un entero para validar una condicion
  *
  */int searchForSpace(Employee employeeList[],int len);

/** \brief da debaja un empleado
 *
 * \param lista de empleados de tipo empleado
 * \param tamaño
 * \return un entero para validar una condicion
 *
 */int removeEmployee1(Employee employeeList[],int len);

 /** \brief da de alta a un empleado
  *
  * \param lista de empleados de tipo empleado
  * \param entero de tamaño
  * \return un entero para validar una condicion
  *
  */int enterAddEmployee(Employee employeeList[],int len,int id);

/** \brief modifica un campo de  un empleado a gusto bajo condicines
 *
 * \param lista de empleados de tipo empleado
 * \param entero de tamaño
 * \return un entero para validar una condicion
 *
 */ int modifyEmployee(Employee employeeList[], int len);

/** \brief sub menu grafico para seleccionar opciones
 *
 * \param ---
 * \param ---
 * \return entero de la opcion elegida
 *
 */ int subMenu();

 /** \brief imprime nombre
  *
  * \param nombre de tipo Employee
  * \param ---
  * \return ---
  *
  */ void printName(Employee name);

/** \brief imprime apellido
 *
 * \param employeeLastName Employee
 * \return void
 *
 */void printLastName(Employee employeeLastName);


/** \brief imprime salario
 *
 * \param employeeSalary Employee
 * \return void
 *
 */void printSalary(Employee employeeSalary);


/** \brief imprime sector
 *
 * \param Employee employeeSector
 *
 * \return ---
 *
 */void printSector(Employee employeeSector);


/** \brief imprime el salario completo , promedio y si hay algun empleado que gane mas que el promedio
 *
 * \param employeeList[] Employee
 * \param len int
 * \return void
 *
 */void printSalaryFull(Employee employeeList[],int len);






