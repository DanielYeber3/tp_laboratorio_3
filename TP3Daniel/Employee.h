#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Es una funcion que reserva un espacio en memoria dinamica.
 *
 * \return Employee*    Retorna el empleado ya cargado en la memoria.
 *
 */
Employee* employee_new();

/** \brief  Es una funcion que carga a un empleado con los atributos en string para su guardado.
 *
 * \param idStr char*   ID del empleado.
 * \param nombreStr char*   Nombre del empleado.
 * \param horasTrabajadasStr char*  Horas Trabajadas del empleado.
 * \param sueldoStr char*   Sueldo del empleado.
 * \return Employee*    Retorna un puntero de la estructura Employee.
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);


/** \brief  Es una funcion de tipo set que asigna un atributo de tipo ID al empleado.
 *
 * \param this Employee*   Recibe un puntero de tipo Employee.
 * \param id int    Recibe el ID para asignarlo al empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_setId(Employee* this,int id);

/** \brief  Es una funcion de tipo get que recibe un atributo de tipo ID al empleado.
 *
 * \param this Employee*    Recibe un puntero de tipo Employee.
 * \param id int*   Recibe un puntero de tipo int que contiene la direccion de memoria del ID del empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief  Es una funcion de tipo set que asigna un atributo de tipo NOMBRE al empleado.
 *
 * \param this Employee*   Recibe un puntero de tipo Employee.
 * \param nombre int    Recibe el NOMBRE para asignarlo al empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief  Es una funcion de tipo get que recibe un atributo de tipo NOMBRE al empleado.
 *
 * \param this Employee*    Recibe un puntero de tipo Employee.
 * \param nombre int*   Recibe un puntero de tipo int que contiene la direccion de memoria del NOMBRE del empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief  Es una funcion de tipo set que asigna un atributo de tipo HORAS TRABAJADAS al empleado.
 *
 * \param this Employee*   Recibe un puntero de tipo Employee.
 * \param horasTrabajadas int    Recibe el HORAS TRABAJADAS para asignarlo al empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief  Es una funcion de tipo get que recibe un atributo de tipo HORAS TRABAJADAS al empleado.
 *
 * \param this Employee*    Recibe un puntero de tipo Employee.
 * \param horasTrabajadas int*   Recibe un puntero de tipo int que contiene la direccion de memoria del HORAS TRABAJADAS del empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief  Es una funcion de tipo set que asigna un atributo de tipo SUELDO al empleado.
 *
 * \param this Employee*   Recibe un puntero de tipo Employee.
 * \param sueldo int    Recibe el SUELDO para asignarlo al empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief  Es una funcion de tipo get que recibe un atributo de tipo SUELDO al empleado.
 *
 * \param this Employee*    Recibe un puntero de tipo Employee.
 * \param sueldo int*   Recibe un puntero de tipo int que contiene la direccion de memoria del SUELDO del empleado.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Es una funcion que compara el valor de los nombres.
 *
 * \param e1 void*  Puntero a void con el valor del primer empleado a evaluar.
 * \param e2 void*  Puntero a void con el valor del segundo empleado a evaluar.
 * \return int  Retorna el valor de los empleados comparados.
 *
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief Es una funcion que compara el valor de los ID's.
 *
 * \param e1 void*  Puntero a void con el valor del primer empleado a evaluar.
 * \param e2 void*  Puntero a void con el valor del segundo empleado a evaluar.
 * \return int  Retorna el valor de los empleados comparados.
 *
 */
int employee_CompareById(void* e1, void* e2);

#endif // employee_H_INCLUDED
