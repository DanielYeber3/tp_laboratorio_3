#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int auxReturn;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* oneEmployee;

    auxReturn= 0;

    pFile = fopen("data.csv", "r");


    if(pFile == NULL)
    {
        printf("El archivo no existe");
        auxReturn = -1;
    }


    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);


    do
    {

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

        oneEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

        if(oneEmployee != NULL)
        {
            ll_add(pArrayListEmployee, oneEmployee);
            auxReturn = 1;
        }

    }while(!feof(pFile));

    fclose(pFile);


    return auxReturn;
}



int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* anEmployee;
    int auxReturn;
    int aux;

    auxReturn = -1;

    if(pFile != NULL)
    {
        do
        {
            anEmployee = employee_new();
            aux = fread(anEmployee, sizeof(Employee), 1, pFile);
            if(aux != NULL)
            {
                ll_add(pArrayListEmployee, anEmployee);
            }

        }while(!feof(pFile));

        auxReturn = 0;
    }
    return auxReturn;
}
