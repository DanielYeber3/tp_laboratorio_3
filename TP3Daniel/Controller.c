#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"





int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* oneEmployee;
    int id;
    int ansMenu;
    char nombre[21];
    int sueldo;
    int horasTrabajadas;
    char auxNombre[21];
    int auxSueldo=0;
    int auxHorasTrabajadas;
    char ansAux;
    int idReturned;



    oneEmployee = NULL;

    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese el ID del empleado que desea modificar: ");
    fflush(stdin);
    scanf("%d",&id);

    idReturned = controller_searchIndexById(pArrayListEmployee, id);

    oneEmployee = (Employee*)ll_get(pArrayListEmployee, idReturned);

    employee_getNombre(oneEmployee, nombre);
    employee_getSueldo(oneEmployee, &sueldo);
    employee_getHorasTrabajadas(oneEmployee, &horasTrabajadas);



    if(oneEmployee != NULL)
    {

        system("cls");
        printf("\n\t   %s %d %d\n\n", nombre, horasTrabajadas, sueldo);
        ansMenu = menu_modify();

            switch(ansMenu)
            {

                case 1:
                    system("cls");
                    printf("\nIngrese el nuevo nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]", auxNombre);

                    printf("\nEstas seguro de querer modificar el nombre?(s/n):");
                    fflush(stdin);
                    scanf("%c",&ansAux);

                    if(ansAux == 's')
                    {
                        employee_setNombre(oneEmployee, auxNombre);
                        printf("\nSe ha modificado el nombre exitosamente!\n");
                    }
                    else
                    {
                        printf("\nNo se ha modificado el nombre.\n");
                    }
                    break;
                case 2:
                    system("cls");
                    printf("\nIngrese las nuevas horas trabajadas: ");
                    fflush(stdin);
                    scanf("%d",&auxHorasTrabajadas);

                    printf("\nEstas seguro de modificar las horas trabajadas?(s/n):");
                    fflush(stdin);
                    scanf("%c",&ansAux);

                    if(ansAux == 's')
                    {
                        employee_setHorasTrabajadas(oneEmployee, auxHorasTrabajadas);
                        printf("\nSe han modificado las horas exitosamente!\n");
                    }
                    else
                    {
                        printf("\nNo se han modificado las horas trabajadas.\n");
                    }
                    break;
                case 3:
                    system("cls");
                    printf("\nIngrese el nuevo sueldo: ");
                    fflush(stdin);
                    scanf("%d",&sueldo);

                    printf("\nEstas seguro de querer modificar el sueldo?(s/n):");
                    fflush(stdin);
                    scanf("%c",&ansAux);

                    if(ansAux == 's')
                    {
                        employee_setSueldo(oneEmployee, auxSueldo);
                        printf("\nSe ha modificado el sueldo exitosamente!\n");
                    }
                    else
                    {
                        printf("\nNo se ha modificado el sueldo.");
                    }
                    break;
                case 4:
                    break;
            }

    }

    return 1;

}


int controller_searchIndexById(LinkedList* pArrayListEmployee, int id)
{
    int index;
    int i;
    int len;
    Employee* auxEmployee;

    len = ll_len(pArrayListEmployee);
    index = 0;


    for(i=0;i<len;i++)
    {
        auxEmployee  = (Employee*)ll_get(pArrayListEmployee, i);

        if(auxEmployee->id == id)
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }

    return index;
}



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;


    pFile = fopen(path, "r");
    parser_EmployeeFromText(pFile, pArrayListEmployee);

    if(pFile == NULL)
    {
        printf("\nNo existe el archivo\n");
    }
    fclose(pFile);

    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("\nNo existe el archivo\n");
    }
     fclose(pFile);

    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    Employee* anEmployee = NULL;
    int i;
    int len;
    int intId;
    char id[21];
    char nombre[51];
    char sueldo[21];
    char horasTrabajadas[21];


    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        if(pArrayListEmployee != NULL)
        {
            intId = len + 1;

            employee_setId(anEmployee, intId);


            itoa(intId, id, 10);

            printf("\nIngrese el nombre del nuevo empleado: ");
            fflush(stdin);
            scanf("%[^\n]", nombre);

            printf("\nIngrese las horas trabajadas del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", horasTrabajadas);

            printf("\nIngrese el sueldo del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", sueldo);

        }
    }
        anEmployee = employee_newParametros(id, nombre,  horasTrabajadas, sueldo);
        ll_add(pArrayListEmployee, anEmployee);



    return 1;
}



int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int ans;
    int tam;
    int i;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;
    char ansAux;

    ans = 0;
    ansAux = 'n';

    tam = ll_len(pArrayListEmployee);
    for(i=0;i<tam;i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee, i);

        employee_getId(aux, &id);
        employee_getNombre(aux, nombre);
        employee_getHorasTrabajadas(aux, &horasTrabajadas);
        employee_getSueldo(aux, &sueldo);

        printf("\n%7d)   %15s   %10d   %15d", id, nombre, horasTrabajadas, sueldo);
    }

    printf("\nQue empleado desea eliminar?");
    scanf("%d",&ans);



    if(ans!=0)
    {

        employee_getId(aux, &id);
        employee_getHorasTrabajadas(aux, &horasTrabajadas);
        employee_getSueldo(aux, &sueldo);
        employee_getNombre(aux, nombre);

        printf("\n%4d.   %15s   %4d   %8d\n", id, nombre, horasTrabajadas, sueldo);


        printf("\nEsta seguro que desea eliminar a este empleado? ");
        fflush(stdin);
        scanf("%c", &ansAux);

        if(ansAux == 's')
        {
            aux = (Employee*)ll_pop(pArrayListEmployee,ans-1);
            printf("\nSe elimino de la lista a:\n%4d.   %15s   %4d   %8d\n",  id, nombre, horasTrabajadas, sueldo);
            system("pause");

        }

        else
        {
            system("cls");
            printf("\nOperacion Cancelada.\n");
            system("pause");
        }

    }



    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tam;
    Employee* aux;
    int i;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    tam = ll_len(pArrayListEmployee);

    for(i=0;i<tam;i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee, i);

        employee_getId(aux, &id);
        employee_getNombre(aux, nombre);
        employee_getHorasTrabajadas(aux, &horasTrabajadas);
        employee_getSueldo(aux, &sueldo);

        printf("\n%7d)   %15s   %10d   %15d", id, nombre, horasTrabajadas, sueldo);
    }

    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ans;

    do
    {
        ans = menu_sort();
        switch(ans)
        {
            case 1:
                ll_sort(pArrayListEmployee, employee_CompareByName, 1);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_CompareByName, 0);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_CompareById, 1);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_CompareById, 0);
                break;
            case 5:
                break;
            default:
                printf("\nPor favor ingrese una opcion valida");
                break;
        }

        break;

    }while(ans != 5);

    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int auxReturn = 0;
    int tam;
    FILE* pFile;
    Employee* auxEmployee;
    int i;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    pFile = fopen(path, "w");


    tam = ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        for(i=0;i<tam;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);

            employee_getId(auxEmployee,&id);
            employee_getNombre(auxEmployee, &nombre);
            employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas   );
            employee_getSueldo(auxEmployee, &sueldo);

            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);

            auxReturn = 1;

        }


    }


    fclose(pFile);


    return auxReturn;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int auxReturn = 0;
    int tam;
    FILE* pFile;
    Employee* auxEmployee;
    int i;
    int auxWrite;


    pFile = fopen(path,"wb");
    tam = ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        for(i=0;i<tam;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);

            auxWrite=fwrite(auxEmployee,sizeof(Employee),1,pFile);


              auxReturn = 1;



        }

    }


    fclose(pFile);


    return auxReturn;
}
