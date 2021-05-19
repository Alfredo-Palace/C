#include "top.h"

int saca (int max, char *buf){
	char *c, i;
		if (fgets(buf, max, stdin)) { // Leemos solamente "max" numero de caracteres.
			c = strchr(buf, '\n'); // Buscamos el salto de linea
		if (c) {
				*c = '\0'; // Si existe el salto de linea, lo reemplazamos por nulo.
			} else { // Si no eixste salgo de línea vaciamos el búfer
				while (((i = getchar()) != '\n')
					&& !feof(stdin)
					&& !ferror(stdin)
					);
				buf[max-1] = '\0'; // En caso de no haber fin de linea, ponemos nulo al final.
				// Advertimos al usuario.
		    printf ("\n**ADVERTENCIA**\n");
			printf("Entrada demasiado larga, acotado a \"%s\"", buf);
		}

		return strlen(buf);
	} else return 0;
}


//-------------------Apellidos y nombres---------------- 
char primeraVocal (char *buf){
	while ( *buf != '\0' ){
		switch (toupper(*buf)){
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			return *buf;
			default:
			break;
		}
		buf++;
	}

	return '\0';
}

char primeraConsonante (char *buf) {
	while ( *buf != '\0' ){
		switch ( toupper(*buf) ){
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
			break;
			default:
			return *buf;
		}
		buf++;
	}
	return '\0';
}

int Primer_QuintoTotem (char *buf, char *curp){
	const char delimiter[2] = " ";
	char *token,*cpy;
	size_t i;
	char caracter = toupper(*cpy);
	
	if (strlen(buf) < 2){
		return 1;
	}

	else if (cpy = buf){
	while (*(cpy++) != '\0'){
		if ( !(caracter == ' ' || caracter == '\0' || (caracter >= 'A' && caracter <= 'Z')) ){ //Si el caracter no es un espacio, un salto de linea o una letra arrojar advertencia
			printf ("\n**ADVERTENCIA**\n");
			printf ("El nombre debe ser solamente texto sin acentos\n");
			return 1;
		}
  	  }
	}

	// Apellido paterno.
	if (token = strtok(buf, delimiter)){
		curp[0] = toupper (token[0]); 
		curp[1] = toupper (primeraVocal(token));
		curp[13] = toupper (primeraConsonante(token+1));	
	}else{
	    printf ("\n**ADVERTENCIA**\n");
		printf ("Debe ingresar un nombre con apellido paterno\n");
		return 1;
	}
	
	 // Apellido materno.
	if (token = strtok(NULL, delimiter)){
		curp[2] = toupper (token[0]);
		curp[14] = toupper (primeraConsonante(token+1));
	}else{
	    printf ("\n**ADVERTENCIA**\n");
		printf ("Debe ingresar un nombre con apellido materno\n");
		return 1;
	}
	
	 // Primer Nombre.
	if (token = strtok(NULL, delimiter)){
		curp[3] = toupper (token[0]);
		curp[15] = toupper (primeraConsonante(token+1));
	}else{
	    printf ("\n**ADVERTENCIA**\n");
		printf ("Debe ingresar su nombre(s)\n");
		return 1;
	}	
	return 0;
}



//----------Fecha de nacimiento-----------------
int SegundoTotem (char *buf, char *curp){
	if (strlen(buf) < 2){
		return 1;
	}
	int anno, mes, dia;
	char *anno_s, *mes_s, *dia_s;
	size_t anno_s_size = sizeof(char) *5;
	size_t diames_s_size = sizeof(char) *3;

	anno_s = (char *) malloc ( anno_s_size ); //Generamos Memoria
	mes_s = (char *) malloc ( diames_s_size );
	dia_s = (char *) malloc ( diames_s_size );
	
	if (anno_s == NULL || mes_s == NULL || dia_s == NULL){
	    printf ("\n**ADVERTENCIA**\n");
		printf("Memoria insuficiente");
		return 1;
	}

	memset(anno_s, 0, anno_s_size);
	memset(mes_s, 0, diames_s_size); //Reiniciamos la Memoria
	memset(dia_s, 0, diames_s_size);

	strncpy(anno_s, buf, sizeof(char) *4);
	strncpy(mes_s, buf+5, sizeof(char) *2);
	strncpy(dia_s, buf+8, sizeof(char) *2);

	anno = atoi(anno_s);
	mes = atoi(mes_s);
	dia = atoi(dia_s);

	if ( (!anno + !mes + !dia) > 2 ){
	    printf ("\n**ADVERTENCIA**\n");
		printf("La fecha debe tener el formato adecuado: AAAA-MM-dd, (ejemplo 1990-01-21)\n");
		return 1;
	}

	if (anno == FALSE){
	    printf ("\n**ADVERTENCIA**\n");
		printf("El año debe estar formado de cuatro dígitos y mayor a cero\n");
		return 1;
	} 

	if (mes == FALSE){
	    printf ("\n**ADVERTENCIA**\n");
		printf("El mes debe ser a dos dígitos y mayor a cero, con 01=Enero, 02=Febrero...\n");
		return 1;
	}else {
	        if (mes > 12) {
	    printf ("\n**ADVERTENCIA**\n");
        printf("El año solamente tiene 12 meses checa bien el mes que introduciste.\n");
				return 1;
    }
	}

	if (dia == FALSE){
	    printf ("\n**ADVERTENCIA**\n");
		printf("El dia debe ser a dos dígitos y mayor a cero, ejemplo: 01, 02, 03 ... 31\n");
		return 1;
	}


	//Problema años biciesto
	int es_biciesto = anno % 4 == 0  && (anno % 100 != 0  ||  anno % 400 == 0);

	if ( !es_biciesto && mes == 2 && dia > 28 ){
	    printf ("\n**ADVERTENCIA**\n");
		printf("El año %d no es biciesto, sin embargo usted indicó una fecha de Febrero que lo requiere.\n", anno);
		return 1;
	} 

	if ( mes != 2 ) {

		if ( mes % 2 == 0 && mes != 8){
			if ( dia > 30 ){
			    printf ("\n**ADVERTENCIA**\n");
				printf("El mes %02d solamente tiene 30 días.\n", mes);
				return 1;
			}

		}else {
			if ( dia > 31) {
			    printf ("\n**ADVERTENCIA**\n");
				printf("El mes %02d solamente tiene 31 días.\n", mes);
				return 1;
			}
		}
	}
	strncpy(curp+4, anno_s+2, 2 );
	strncpy(curp+6, mes_s, 2 );
	strncpy(curp+8, dia_s, 2);

	free(anno_s);
	free(mes_s);
	free(dia_s);
	return 0;
}

//-----------------Sexo de la persona------------------------------
int TercerTotem (char *buf, char *curp){
if (strlen(buf) == 0){
		return 1;
	}
		
	if ( toupper(buf[0]) == 'H' || toupper (buf[0]) == 'M'){
		curp[10] = toupper(buf[0]);
		return 0;
	}
    else { if (toupper( buf[0] ) != 'H' || toupper (buf[0]) != 'M'){
    printf ("\n**ADVERTENCIA**\n");
	printf ("Debe ingresar un sexo valido\n");
	return 1;
        }
    }
}


//--------------------Lugar de nacimiento---------------
int CuartoTotem (int indice, char * curp) {
	const char estados[33][2];
     if (indice == 1){
		curp[11] = 'A';
		curp[12] = 'S';
	}else if (indice == 2){
		curp[11] = 'B';
		curp[12] = 'C';
	}else if (indice == 3){
		curp[11] = 'B';
		curp[12] = 'S';
	}else if (indice == 4){
		curp[11] = 'C';
		curp[12] = 'C';
	}else if (indice == 5){
		curp[11] = 'C';
		curp[12] = 'S';
	}else if (indice == 6){
		curp[11] = 'C';
		curp[12] = 'H';
	}else if (indice == 7){
		curp[11] = 'C';
		curp[12] = 'L';
	}else if (indice == 8){
		curp[11] = 'C';
		curp[12] = 'M';
	}else if (indice == 9){
		curp[11] = 'D';
		curp[12] = 'F';
	}else if (indice == 10){
		curp[11] = 'D';
		curp[12] = 'G';
	}else if (indice == 11){
		curp[11] = 'G';
		curp[12] = 'T';
	}else if (indice == 12){
		curp[11] = 'G';
		curp[12] = 'R';
	}else if (indice == 13){
		curp[11] = 'H';
		curp[12] = 'G';
	}else if (indice == 14){
		curp[11] = 'J';
		curp[12] = 'C';
	}else if (indice == 15){
		curp[11] = 'M';
		curp[12] = 'C';
	}else if (indice == 16){
		curp[11] = 'M';
		curp[12] = 'N';
	}else if (indice == 17){
		curp[11] = 'M';
		curp[12] = 'S';
	}else if (indice == 18){
		curp[11] = 'N';
		curp[12] = 'T';
	}else if (indice == 19){
		curp[11] = 'N';
		curp[12] = 'L';
	}else if (indice == 20){
		curp[11] = 'O';
		curp[12] = 'C';
	}else if (indice == 21){
		curp[11] = 'P';
		curp[12] = 'L';
	}else if (indice == 22){
		curp[11] = 'Q';
		curp[12] = 'T';
	}else if (indice == 23){
		curp[11] = 'Q';
		curp[12] = 'R';
	}else if (indice == 24){
		curp[11] = 'S';
		curp[12] = 'P';
	}else if (indice == 25){
		curp[11] = 'S';
		curp[12] = 'L';
	}else if (indice == 26){
		curp[11] = 'S';
		curp[12] = 'R';
	}else if (indice == 27){
		curp[11] = 'T';
		curp[12] = 'C';
	}else if (indice == 28){
		curp[11] = 'T';
		curp[12] = 'S';
	}else if (indice == 29){
		curp[11] = 'T';
		curp[12] = 'L';
	}else if (indice == 30){
		curp[11] = 'V';
		curp[12] = 'Z';
	}else if (indice == 31){
		curp[11] = 'Y';
		curp[12] = 'N';
	}else if (indice == 32){
		curp[11] = 'Z';
		curp[12] = 'S';
	}else if (indice == 33){
		curp[11] = 'N';
		curp[12] = 'E';
	} 

else { 
        printf ("\n**ADVERTENCIA**\n");    
		printf ("Debe ingresar una opción del menu.\n");
		return 1;
	}

return 0;
}

//-----------------Homoclave-----------------------
int SextoTotem (char *curp){
	srand(time(NULL));
	int anno;
	char a, b; 
	if (anno <= 1999){
	     a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random () % 26];
	}
	else  if (anno >= 2000){
	     a = "0123456789"[random () % 10];
	}
    
    b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"[random () % 36];
	curp[16] = a;
	curp[17] = b;
	return 0;
}


//---------------Funcion principal--------------------//
int main(int estado){
	const int string_short_buffer_len = 8; // Longitudes de strings.
	const int string_curp_len = 18;
	const int string_buffer_len = 200;
		
	const size_t curp_size = sizeof(char) *string_curp_len; // Tamaños de memoria.
	const size_t buffer_size = sizeof(char) *string_buffer_len;
	const size_t short_buffer_size = sizeof(char) *string_short_buffer_len;
	
	char *curp = (char *) malloc (curp_size);
	char *nombre = (char *) malloc (buffer_size); 	// Generamos la memoria.
	char *fecha = (char *) malloc (buffer_size);
	char *sexo = (char *) malloc (short_buffer_size);
   
	if (curp == NULL || nombre == NULL
		|| fecha == NULL || sexo == NULL){ //Para que no explote la memoria
		printf ("\n**ADVERTENCIA**\n");  
		printf("Memoria insuficiente\n");
		return 1;
	}

	// Inicializamos la memoria a ceros.
	memset(curp, 0, curp_size);
	memset(nombre, 0, buffer_size);
	memset(fecha, 0, buffer_size);
	memset(sexo, 0, short_buffer_size);

	printf ("**BIENVENIDO A LA CALCULADORA DE CURP**\n");
	printf ("Advertencia: Para el correcto funcionamiento, no debe ingresar acentos en ningún campo y siga todas las indicaciones dadas.\n");

      while(Primer_QuintoTotem (nombre, curp)){        // Pedimos el nombre.
        printf ("\n-----------------------------------------------\n");
        printf ("Debe ingresar su nombre completo\n");
	    printf ("Introduzca su nombre iniciando por apellido paterno (ejemplo \"Gomez Pérez Maria Antonieta\"):\n");
		saca (string_buffer_len, nombre);
	};

	while(SegundoTotem (fecha, curp)){ 		// Pedimos la fecha.
	  printf ("\n-----------------------------------------------\n");
	  printf ("Debe ingresar una fecha\n");
	  printf ("Introduzca su fecha de nacimiento YYYY-MM-dd (ejemplo \"1980-09-02\" para el 2 de septiembre de 1980):\n");
		saca (string_buffer_len, fecha);  
	};

	while(TercerTotem (sexo, curp)){	// Pedimos el sexo.
	  	printf ("\n-----------------------------------------------\n");
	  	printf ("Debe ingresar un sexo\n");
	  	printf ("Introduzca su sexo (M para mujer, H para hombre):\n");
		saca (string_short_buffer_len, sexo);  
	};

	do{
		printf ("\n-----------------------------------------------\n");
		printf ("Seleccione su estado de nacimiento.\n");   // Pedimos el lugar de nacimiento.
		printf (
			"1) Aguascalientes\n"
			"2) Baja california\n"
			"3) Baja california sur\n"
			"4) Campeche\n"
			"5) Chiapas\n"
			"6) Chihuahua\n"
			"7) Coahuila\n"
			"8) Colima\n"
			"9) Distrito Federal\n"
			"10) Durango\n"
			"11) Guanajuato\n"
			"12) Guerrero\n"
			"13) Hidalgo\n"
			"14) Jalisco\n"
			"15) Estado de Mexico\n"
			"16) Michoacán\n"
			"17) Morelos\n"
			"18) Nayarit\n"
			"19) Nuevo León\n"
			"20) Oaxaca\n"
			"21) Puebla\n"
			"22) Querétaro\n"
			"23) Quintana Roo\n"
			"24) San Luis Potosí\n"
			"25) Sinaloa\n"
			"26) Sonora\n"
			"27) Tabasco\n"
			"28) Tamaulipas\n"
			"29) Tlaxcala\n"
			"30) Veracruz\n"
			"31) Yucatán\n"
			"32) Zacatecas\n"
			"33) Extranjero\n");
        printf ("\n**ADVERTENCIA**-> Para el correcto funcionamiento del codigo unicamente introduce numeros\n");
		printf ("Introduzca el número de estado donde ha nacido:\n");
		scanf ("%d", &estado);
	}while(CuartoTotem (estado, curp));

	SextoTotem (curp); //Damos la homoclave
	printf ("\n-----------------------------------------------\n");
	printf ("Su CURP (con homoclave y verificación simulada): %s \n", curp);
	printf ("\n**Gracias por venir**\n");  

	free(curp);
	free(nombre); //Liberar la memoria
	free(fecha);
	free(sexo);

	return 0;
}

