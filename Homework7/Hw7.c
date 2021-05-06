//Instrucciones//
//solo copia el codigo con el nombre Hw7.c y pega en tu compilador: main.c, crea otro documento y coloca el nombre: encabezado.h y pega el codigo que aparece en mi github con ese nombre
//Crea tambien 3 archivos más: system.txt, times.txt & log.txt, pero no agregues nada de texto simplemente crealos, el programa por su cuenta lo hara


//RECOMENDACIONES ANTES DE COMPILAR//
// -> El codigo fue realizado en su mayoria en Dev-C asi que te recomiendo correrlo ahi o en un programa similar de tu ordenador
// -> Si quieres correrlo en online GDB te saldran algunas advertencias que no afectaran el funcionamiento del codigo
// -> Para ambos tipos de compiladores el programa te abrira los documentos .txt necesarios para que el codigo funcione
//    si esto no pasa automaticamente te recomiendo crear los archivos por tu cuenta.
// -> En online GDB no se pq en mi caso es mas propenso a tener bugs el programa asi que si lo quieres correr ahi te recomiendo que cada que realices un movimiento cierres el programa (todos los datos ingresados se se guardan)
// -> Si tienes algun inconveniente o ves algo extraño te recomiendo mandarme un mensaje en discord para que te diga que ocurre
// -> Antes de que califiques el codigo te recomiendo que cheques bien lo que se escribe y que hayas seguido las indicaciones
// Yo he compilado el codigo en Online GDB, Dev-C y CodeBlocks y en todos jala, asi que si ocurre algo me avisas :)

#include "encabezado.h"
/*Inician Funciones/Subrutinas*/
int Registro(void)
{
	int nuevoPin = 1, pin, flag = 0;
	int checarPins(int pin);
    char horae[30], horas[30], dias[40];
    FILE *fichero;

    fichero = fopen("system.txt", "a");

    if (fichero == NULL)
    {
        printf("Error: No se ha podido crear el fichero system.txt\n");
    }
    else
    {
        while (1)
        {
           if (checarPins(nuevoPin))
           {
               nuevoPin++;
           }else {
               break;
           }
        }

        fichero = fopen("system.txt", "a");
        printf("El nuevo pin generado automaticamente es: '%d'\n", nuevoPin);
        printf("Introduce los dias que trabajara, sin espacios (ejemplos: LunesMartes   o   MiercolesJuevesViernes\n");
        fflush(stdin);
        scanf("%s", &dias);
        printf("Introduce la hora de entrada del trabajador (ejemplos: 10:30 , 23:00 ,etc)\n");
        fflush(stdin);
        scanf("%s", &horae);
        printf("Introduce la hora de salida del trabajador (ejemplos: 10:30 , 23:00 ,etc)\n");
        fflush(stdin);
        scanf("%s", &horas);
        fprintf(fichero, "c%d e%s s%s d%s\n", nuevoPin, horae, horas, dias);
        printf("Se ha registrado con exito al trabajador");
        fflush(fichero);
        fclose(fichero);
        fichero = fopen("times.txt", "a");
        fprintf(fichero, "%d 0 \n", nuevoPin);
        fflush(fichero);
        fclose(fichero);
        printf("\n");
    }
}


int checarPins(int pin)
{
    int pines[9], j = 0;
    int c;
    FILE *fichero;

    fichero = fopen("system.txt", "r");

    if (fichero == NULL)
    {
        printf("Error: No se ha podido crear el fichero system.txt\n");
    }
    else
    {
        while ((c = fgetc(fichero)) != EOF)
        {
            if (c == 'c')
            {
                c = fgetc(fichero);
                pines[j] = c - '0';
                if (pin == pines[j])
                {
                    fflush(fichero);
                    fclose(fichero);
                    return 1;
                }
                j = +1;
            }
        }
    }
    fflush(fichero);
    fclose(fichero);
}


int verAsistencias(int pin)
{
    int c, asistencias = 0;
    FILE *fichero;
    fichero = fopen("log.txt", "r");
    while ((c = fgetc(fichero)) != EOF)
    {
        if (c == 's')
        {
            c = fgetc(fichero) - '0';
            if (c == pin)
            {
                asistencias++;
            }
        }
    }
    fflush(fichero);
    fclose(fichero);
    printf("\n El usuario '%d' tiene: %d asistencias\n", pin, asistencias);
}


int verTiempoTrabajado(int pin)
{
    char tiempo1[20], tiempo2[20];
    int t1, t2, tiempo;
    int c, asistencias = 0;
    FILE *fichero;
    fichero = fopen("log.txt", "r");
    while ((c = fgetc(fichero)) != EOF)
    {
        if (c == 'e')
        {
            c = fgetc(fichero) - '0';
            if (c == pin)
            {
                c = fgetc(fichero) - '0';
                fgets(tiempo1, 11, fichero);
                t1 = atoi(tiempo1);
            }
        }
    }
    tiempo = (unsigned long)time(NULL) - t1;
    fflush(fichero);
    fclose(fichero);
    return tiempo;
}


int calcHorasLaboradas(int pin)
{
    int horas,c,pinarch ;
    FILE * fichero;
    fichero = fopen("times.txt", "r");
    while (1)
    {
        fscanf(fichero, "%d %d", &pinarch, &horas);
        if(pinarch==pin)
        {
            return horas;
            break;
        }

        }
}

/*Inicia la funcion principal*/
int main()
{
    printf("//INTRUCCIONES DE USO//\n");
    printf("1.-Corre el programa\n2.-Inicia como administrador (pin: '0')\n3.-Agrega un trabajador\n4.-Cierra y abre el programa pero ahora inicia sesion en modo trabajador con el pin que creaste.\n");
    printf("5.-registra tu entrada\n6.-Cierra y vuelve a abrir el programa (con el pin del trajador del paso anterior) y registra tu salida\n7.-vuelve a ejecutar el programa en modo administrador (pin: '0')\n");
	printf("\nListooo ahora verifica por ejemplo la asistencia de algun trabajador, las horas trabajadas, etc.\n\n->PD.Sino añades ningun trabajador antes es probable que el codigo no te deje trabajar\n");
	printf ("->Te recomiendo siempre despues de realizar un movimiento cerrar el codigo y volver a abrirlo, todo se guarda asi que ntp\n");
	printf("\n**ADVERTENCIA**: Si obervas algun tipo de bug o algo raro por parte del programa simplemente cierralo, toda le memoria y los usuarios se guardaran (a veces como que la maquina se sobre llena de memoria), gracias por la compresnion :)\n");
	printf("-------------------------------------------------------------------------------------------------\n\n");
	FILE *flujo;
    int temppin, temptime, flag = 1;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output, 128, "%d/%m/%y", tlocal);
    int pin, option, user;
    char buffer[32];
    struct tm *ts;
    size_t last;
    time_t timestamp = time(NULL);

    //obtiene dia
    ts = localtime(&timestamp);
    last = strftime(buffer, 32, "%A", ts);
    buffer[last] = '\0';
    //obtiene hora
    char hour[128];
    strftime(hour, 128, "%H:%M", tlocal);

    printf("*MENU INICIAL*\nQue eres?\n ->Presiona '0' si eres admin\n ->Presiona '1' si eres usuario\n");
    scanf("%d", &option);
    if (option == 1) //opciones de trabajador
    {
        option = 0;
        printf("Bienvenido, intruduce tu pin: \n");
        scanf("%d", &pin);
        if (checarPins(pin) != 1) //verificar si ese pin existe en el sistema
        {
            printf("ese pin no existe, checa el registro de pines validos en system.tx o crea a ese usuario como administrador\n");
            printf("Hasta pronto!\n");
            getchar();
            exit(1);
        }
        printf("*MENU WORKER*\nTrabajador #%d, Bienvenido al sistema :)\nQue deseas hacer? (introduce el numero con la opcion que requieras) \n", pin);
        printf("1.- Voy a entrar al jale\n2.- Voy a salir del jale\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1: //entrada al jale
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu entrada pin:%d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "e%d %lu %s %s\n", pin, (unsigned long)time(NULL), output, buffer);
            printf("Dale, a perseguir la chuleta");
            fflush(flujo);
            fclose(flujo);
            break;
        case 2: //salida del sale
            flujo = fopen("times.txt", "r+");
            while (flag != 0)
            {
                fscanf(flujo, "%d %d", &temppin, &temptime);
                if (temppin == pin)
                {
                    temptime += verTiempoTrabajado(pin);
                    fseek(flujo, -3, SEEK_CUR);
                    fprintf(flujo, "%d %d", pin, temptime);
                    fflush(flujo);
                    fclose(flujo);
                    flag = 0;
                }
            }
            flujo = fopen("log.txt", "a");
            printf("Se ha registrado tu salida pin: %d hoy:%s %s\n", pin, output, buffer);
            fprintf(flujo, "s%d %lu %s %s %d\n", pin, (unsigned long)time(NULL), output, buffer, verTiempoTrabajado(pin));
            printf("\n Has trabajado por %d segundos \n", verTiempoTrabajado(pin));
            printf("Bien hecho, ahora descansa");
            fflush(flujo);
            fclose(flujo);

            /* Cerramos "fichero1.txt". */
            fclose(flujo);
            fprintf(flujo, "%d %d\n", pin, verTiempoTrabajado(pin));
            break;
        }
        getchar();
        exit(1);
    }
    else if (option == 0) //opciones de admin
    {
        option = 0;
        printf("Bienvenido, intruduce tu pin: \n");
        scanf("%d", &pin);
        if (pin != 000)
        {
            printf("Tu no eres admin >:| Expulsado\n");
            getchar();
            exit(1);
        }
        else
        {
            while (1)
            {
                option = 0;
                printf("\n*MENU ADMIN*\nQue deseas hacer? (introduce el numero con la opcion que requieras) \n");
                printf("1.- Quiero ver las asistencias de un trabajador\n2.- Quiero agregar un nuevo trabajador\n3.- Quiero ver las horas trabajadas de un usuario\n");
                fflush(stdin);
                scanf("%d", &option);
                // acciones
                switch (option)
                {
                case 1:
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    verAsistencias(pin);
                    break;
                case 2:
                    Registro();
                    break;
                case 3:
                    printf("Escribe el pin del usuario para ver sus asistencias(asegurate de que sea valido): \n");
                    fflush(stdin);
                    scanf("%d", &pin);
                    printf("El usuario con el pin: '%d',  ha trabajado por %d segundos \n", pin ,calcHorasLaboradas(pin));
                    break;
                }

                printf("Si deseas hacer otro movimiento ingresa cualquier caracter, si deseas salir introduce '1'\n");
                fflush(stdin);
                scanf("%d", &option);
                if (option == 1)
                {
                    printf("Hasta la proximaaaa\n"),
                        getchar();
                    exit(1);
                }
            }
        }
    }
    else
    {
        printf("Lamentamos no poder atenderte pero no escribiste una opcion valida. Presione enter para salir ...");
        getchar();
        exit(1);
    }
    getchar();
    exit(1);
}


//Quiero agradecer a mi compañero Abner Z. por la ayuda brindada y al libro de Kerninghan, la C-refcard y las clases de Satuelisa :)
