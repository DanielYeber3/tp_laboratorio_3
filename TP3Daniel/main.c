#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
    1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
    2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
    3. Alta de empleado
    4. Modificar datos de empleado
    5. Baja de empleado
    6. Listar empleados
    7. Ordenar empleados
    8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
    9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* miLista;
    int answer;
    Employee* aux;

    miLista = ll_newLinkedList();


    do
    {


        answer = menu_main();

        switch(answer)
        {


        case 1:
                system("cls");
                controller_loadFromText("data.csv",miLista);

            break;
        case 2:
                system("cls");
                controller_loadFromBinary("data.bin",miLista);

            break;
        case 3:
                system("cls");
                controller_addEmployee(miLista);

            break;
        case 4:
                system("cls");
                controller_editEmployee(miLista);

            break;
        case 5:
                system("cls");
                controller_removeEmployee(miLista);

            break;
        case 6:
                system("cls");
                controller_ListEmployee(miLista);
                system("pause");

            break;
        case 7:
                system("cls");
                controller_sortEmployee(miLista);

            break;
        case 8:
                system("cls");
                controller_saveAsText("data.csv",miLista);

            break;
        case 9:
                system("cls");
                controller_saveAsBinary("data.bin",miLista);

            break;
        case 10:



            break;
        default:
            fflush(stdin);
            printf("\n\n La opcion que seleccionaste no existe! \n\n");
            break;




        }

    }
    while(answer!=10);



    return 0;
}















