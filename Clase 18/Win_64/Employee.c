

int employeeSortByName(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    char nombreA[128];
    char nombreB[128];

    //if(empleadoA != NULL && empleadoB != NULL)
    //{
        //Employee* empA = (Employee*)empleadoA;//casteo de una forma

        //if(employee_getNombre(empA, nombreA) &&//traes empA
             //cargas las dos cadenas con el get
        if(employee_getNombre((Employee*)empleadoA, nombreA) &&//traes empA
           employee_getNombre((Employee*)empleadoB, nombreB)//casteo de una forma directa
        {
            retorno = strcmp(nombreA, nombreB);
        }


    //}
    return retorno;
}

int employeeSortById(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int idA;
    int idB;

    if(employee_getId((Employee*)empleadoA, &idA) &&
       employee_getId((Employee*)empleadoB, &idB)
    {
        retorno = idA - idB;
    }

    return retorno;
}

int employeeSortByWorkHours(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int harasA;
    int horasB;

    if(employee_getHorasTrabajadas((Employee*)empleadoA, &horasA) &&
       employee_getHorasTrabajadas((Employee*)empleadoB, &horasB)
    {
        retorno = horasA - horasB;
    }

    return retorno;
}

int employeeSortBySalary(void* empleadoA, void* empleadoB)
{
    int retorno = 0;
    int sueldoA;
    int sueldoB;

    if(employee_getSueldo((Employee*)empleadoA, &sueldoA) &&
       employee_getSueldo((Employee*)empleadoB, &sueldoB)
    {
        retorno = sueldoA - sueldoB;
    }

    return retorno;
}
