#include <stdlib.h>
#include "Employee.h"
#include <string.h>



Employee* employee_new()
{
    Employee* newEmployee;

    newEmployee = (Employee*)malloc(sizeof(Employee));

    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int id;
    int horasTrabajadas;
    int sueldo;
    Employee* oneEmployee;
    oneEmployee = employee_new();


    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);

    if(oneEmployee != NULL)
    {
        employee_setId(oneEmployee, id);
        employee_setNombre(oneEmployee, nombreStr);
        employee_setHorasTrabajadas(oneEmployee, horasTrabajadas);
        employee_setSueldo(oneEmployee, sueldo);
    }

    return oneEmployee;
}


int employee_setId(Employee* this,int id)
{
    int auxReturn;

    auxReturn=0;

    if(this != NULL && id >0)
    {
        this->id = id;
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int auxReturn;

    auxReturn = 0;


    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int auxReturn;

    auxReturn = 0;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int auxReturn;

    auxReturn = 0;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        auxReturn = 1;
    }

    return auxReturn;
}


int employee_getId(Employee* this,int* id)
{
    int auxReturn;

    auxReturn = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int auxReturn;

    auxReturn = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int auxReturn;

    auxReturn = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int auxReturn;

    auxReturn = 0;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        auxReturn = 1;
    }

    return auxReturn;
}

int employee_CompareByName(void* e1, void* e2)
{
    Employee* auxUno;
    Employee* auxDos;
    char nombreUno[51];
    char nombreDos[51];


    auxUno = NULL;
    auxDos = NULL;

    auxUno = (Employee*)e1;
    auxDos = (Employee*)e2;

    employee_getNombre(auxUno, nombreUno);
    employee_getNombre(auxDos, nombreDos);


    return strcmp(nombreUno, nombreDos);
}

int employee_CompareById(void* e1, void* e2)
{
    int auxReturn;
    int idUno;
    int idDos;
    Employee* auxE1;
    Employee* auxE2;

    auxReturn = 0;
    idUno = 0;
    idDos = 0;

    auxE1 = (Employee*)e1;
    auxE2 = (Employee*)e2;

    employee_getId(auxE1, &idUno);
    employee_getId(auxE2, &idDos);

    if(idUno > idDos)
    {
       auxReturn = 1;
    }
    else
    {
        auxReturn = -1;
    }



    return auxReturn;
}

