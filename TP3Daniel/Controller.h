
/** \brief Es una funcion de tipo controller que carga los archivos de tipo .csv.
 *
 * \param path char*    Recibe el nombre del archivo.
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que carga los archivos de tipo .dat.
 *
 * \param path char*    Recibe el nombre del archivo.
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que agrega un empleado al array.
 *
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que edita un empleado del array.
 *
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que elimina un empleado del array.
 *
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que muestra todos los empleados del array.
 *
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que ordena los empleados del array.
 *
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Es una funcion de tipo controller que guarda los empleados en tipo .csv.
 *
 * \param path char*    Recibe el nombre del archivo.
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que guarda los empleados en tipo .dat.
 *
 * \param path char*    Recibe el nombre del archivo.
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \return int  Retorna 1 si se pudo realizar la carga, de lo contrario retorna 0
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Es una funcion de tipo controller que busca el indice de un ID.
 *
 * \param pArrayListEmployee LinkedList*    Recibe un puntero a LinkedList del array de los empleados.
 * \param id int    Recibe el ID para buscarlo en memoria.
 * \return int  Retorna el indice en memoria del ID ingresado.
 *
 */
int controller_searchIndexById(LinkedList* pArrayListEmployee, int id);

