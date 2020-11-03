#include <stdio.h>
#include <stdlib.h>




int menu_modify()
{
   int ans;


   printf("\n\nQue queres modificar?");
   printf("\n 1- Nombre \n 2- Horas Trabajadas \n 3- Sueldo \n 4- Salir ");
   fflush(stdin);
   scanf("%d", &ans);



    return ans;
}

int menu_main()
{
    int ans;

    printf("\t\n\n\n-----Bienvenido al Menu-----\n\n\n");
    printf("\t1. Cargar los datos de los empleados desde el archivo data.csv.\n\t2. Cargar los datos de los empleados desde el archivo data.dat.\n\t3. Alta de empleado.\n\t4. Modificar datos de empleado.\n\t5. Baja de empleado.\n\t6. Listar empleados.\n\t7. Ordenar empleados.\n\t8. Guardar los datos de los empleados en el archivo data.csv.\n\t9. Guardar los datos de los empleados en el archivo data.dat.\n\t10. Salir. ");
    scanf("%d", &ans);


    return ans;
}

int menu_sort()
{
    int ans;

        printf("\n*** Menu de ordenamiento ***\n");
        printf("1.Ordenar por nombre de la A-Z.\n2.Ordenar por nombre de la Z-A.\n3.Ordenar ID por orden descendente.\n4.Ordenar ID por orden ascendente.\n5.Salir\n");
        scanf("%d",&ans);

    return ans;

}




