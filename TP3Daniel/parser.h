
/** \brief  Es una funcion que decodifica los datos guardados en el formato .csv.
 *
 * \param pFile FILE*   Recibe un puntero de tipo FILE para la interaccion con la carpeta de empleados.
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int  Retorna valores si se pudo realizar el parseo.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief  Es una funcion que decodifica los datos guardados en el formato .dat.
 *
 * \param pFile FILE*   Recibe un puntero de tipo FILE para la interaccion con la carpeta de empleados.
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int  Retorna valores si se pudo realizar el parseo.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
