// Para testearlo tienes que colocar todo el codigo del archivo main.c en la pestaña principal para luego abrir una nueva pestaña o documento y colocarle el nombre de "tree.h" 
//y colocar todo el codigo del archivo tree.h del otro archivo de la misma carpeta.
// Sino sigues estas indicaciones probablemente el programa no se compilara. Cualquier duda mandame mensaje en discordsito :)


//Durante la realizacion y testing del codigo arroja una advertencia en el compilador GDB online (no es nada grave si deja trabajar al codigo) 
//que no fui capaz de resolver, si tu sabes como resolver esto puedes enviarme un mensaje en discord y lo agradeceria :)
//RECORDATORIO: yo testie el codigo en GDB online unas mil ocho mil veces asi que te recomiendo compilarlo ahi :)

/* Archivo principal*/
#include "tree.h"
usuario *nuevoNodo(char username[MAX], char password[MAX]){  // Solicitar almacenamiento de datos
    size_t tamanioNodo = sizeof(usuario);
    size_t tamanioNodopass = sizeof(usuario);
    usuario *nodo = (usuario *)malloc(tamanioNodo);
    usuario *nodopass = (usuario *)malloc(tamanioNodopass);
    strcpy(nodo->username, username);    // Asignar el dato e iniciar hojas
    strcpy(nodo->password, password);
    nodo->leftChild = nodo->rightChild = NULL;
    return nodo;
}

void agregar(usuario *nodo, char *cadena, char *password)
{
    if (strcmp(cadena, nodo->username) > 0)
    {
        if (nodo->rightChild == NULL)
        {
            nodo->rightChild = nuevoNodo(cadena, password);
        }
        else
        {
            agregar(nodo->rightChild, cadena, password);
        }
    }
    else
    {
        if (nodo->leftChild == NULL)
        {
            nodo->leftChild = nuevoNodo(cadena, password);
        }
        else
        {
            agregar(nodo->leftChild, cadena, password);
        }
    }
}

usuario *checarUsername(usuario *nodo, char *cadena)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->username) == 0)
    {
        return nodo;
    }
    else if (strcmp(cadena, nodo->username) > 0)
    {
        return checarUsername(nodo->rightChild, cadena);
    }
    else
    {
        return checarUsername(nodo->leftChild, cadena);
    }
}
usuario *checarPassword(usuario *nodo, char *cadena, char *pass)
{
    if (nodo == NULL)
    {
        return NULL;
    }
    if (strcmp(cadena, nodo->username) == 0)
    {
        if (strcmp(pass, nodo->password) == 0)
        {
            *nodo->username = NULL;
            *nodo->password=NULL;
            return NULL;
        }
    }
    else if (strcmp(cadena, nodo->username) > 0)
    {
        return checarPassword(nodo->rightChild, cadena, pass);
    }
    else
    {
        return checarPassword(nodo->leftChild, cadena, pass);
    }
}

void ordenar(usuario *nodo) // de aqui surge la raiz
{
    
    if (nodo != NULL)
    {
        ordenar(nodo->leftChild);
        printf("%s\n", nodo->username);
        ordenar(nodo->rightChild);
    }
}


/*Aqui juntamos todas las subrutinas y damos paso al mecanismo*/
int main()
{
    char user[MAX];
    char pass[MAX];
    usuario *raiz = NULL;
    printf("\nBienvenido\n\nPrimero deberas crear al usuario raiz \n");
    printf("Escribe el usuario que deseas agregar:\n");
    scanf("%s", &user[0]);
    printf("Escribe el password:\n");
    scanf("%s", &pass[0]);
    printf("\n\tSe ha agregado al usuario '%s'\n", user);
    raiz = nuevoNodo(user,pass);
    int add = FALSO, eliminacion = FALSO, ordenamiento = FALSO;
    char c, j;
    while ((c = getchar()) != EOF)
    {
        
        printf("\n-> Presiona '+' si quieres agregar un usuario\n-> Presiona 'x' si quieres eliminar un usuario\n-> Presiona 'v' si quiere ver la lista de los usuarios actuvis alfabeticamente\n\n");

        scanf("%c", &j);
        switch (j)
        {
        case '+': // se quiere añadir algo
            add = VERDADERO;
            break;
        case 'x': //se quiere eliminar algo
            eliminacion = VERDADERO;
            break;
        case 'v': // si quiere ver los usuarios alfabeticamente
            ordenamiento = VERDADERO;
            break;
        default:
            printf("Prueba con algo valido");
            break;
        }
        if (add != 0 || eliminacion != 0 || ordenamiento != 0)
        {
            if (add == VERDADERO)
            {
                char user[MAX];
                char pass[MAX];
                printf("Escribe el usuario que deseas agregar:\n");
                scanf("%s", &user[0]);
                struct nodoCadena *apuntadorUser = checarUsername(raiz, user);
                if (apuntadorUser != NULL)
                {
                    printf("\n\tLo siento pero '%s' ya existe en el sistema!!\n", user);
                }
                else
                {
                    printf("Escribe el password que deseas asignarle:\n");
                    scanf("%s", &pass[0]);
                    agregar(raiz, user, pass);
                    printf("\n\tSe ha agregado al usuario '%s'\n", user);
                }
            }
            else if (eliminacion == VERDADERO)
            {
                char user[MAX];
                char pass[MAX];
                printf("Escribe el usuario que deseas eliminar:\n");
        
                scanf("%s", &user[0]);
                struct nodoCadena *apuntadorUser = checarUsername(raiz, user);
                if (apuntadorUser != NULL)
                {
                    printf("Escribe el password del usuario para eliminarlo:\n");
                    scanf("%s", &pass[0]);
                    struct nodoCadena *apuntadorPass = checarPassword(raiz, user, pass);
                    if (apuntadorPass == NULL)
                    {
                        printf("\n\t Se ha eliminado al usuario '%s'\n", user);
                    }
                    else
                    {
                        printf("\tPassword incorrecta!!\n");
                    }
                }
                else
                {
                    printf("\n El usuario no se encuentra en nuestro sistemas!!\n");
                }
            }
            else if (ordenamiento == 1)
            {
                 printf("//lista de usuarios//\n");
                ordenar(raiz);
                printf("\nPresiona enter para continuar\n");
                getchar();
            }
        }
        add = FALSO;
        eliminacion = FALSO;
        ordenamiento = FALSO;
    }
    return 0;
}

//Quiero agradecer a mi compañero Abner Z. por la ayuda para realizar el codigo, Abner si ves esto te tkm <3
