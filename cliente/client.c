/****************************************************************************/
/*                                                                        	*/
/*	adn_c - Aplicación Cliente/Servidor para traducir cadenas de ADN.	*/
/*                                                                        	*/
/*			Internetworking - 2015                                   		*/
/*                                                                        	*/
/*       	UTN  | Universidad Tecnologica Nacional                         */
/*       	FRLP | Facultad Regional La Plata                               */
/*             	   Buenos Aires, Argentina                                  */
/*                                                                        	*/
/*       	> Cagliardi, Pablo Esteban    <cagliardipablo@yahoo.com.ar>     */
/*                                                                        	*/
/****************************************************************************/

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

//HEADERS

//VARIABLES
int sockfd, portno, n;
struct sockaddr_in serv_addr;
struct hostent *server;

char buffer[256];

FILE *archin;
FILE *archout;

char carain='\0';	/*cara:caracter; in:entrada*/
char caraout='\0';	/*cara: caracter; out:salida*/
int ain,cin,gin,tin; /*A,C,G,T --> Adenine, Cytosine, Guanine, Thymine*/
int aout,cout,gout,uout; /*A,C,G,T --> Adenine, Cytosine, Guanine, Thymine*/
char charin;
int opcion;

//MAIN
int main(int argc, char *argv[]) {

	ain = cin = gin = tin = 0;
	aout = cout = gout = uout = 0;

   if (argc < 3) {
      fprintf(stderr,"\nUtilice %s hostname puerto\nEjemplo: %s localhost 5001\n", argv[0], argv[0]);
      exit(0);
   }

	printf("\nAplicación Cliente para traducir cadenas de ADN v1.0");

   portno = atoi(argv[2]); //Puerto ingresado desde linea de comando
   //portno=5001;

   /* Crea un socket */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("\nERROR abriendo socket (opening socket)\n");
      exit(1);
   }

   server = gethostbyname(argv[1]);	//Obtiene el nombre del server pasado como argumento

   if (server == NULL) {
      fprintf(stderr,"\nERROR, no se encuentra el host (no such host)\n");
      exit(0);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   /* Establece la coneccion con el server */
   if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("\nERROR conectando (connecting)\n");
      exit(1);
   }

	/*Ahora, pedir al usuario un mensaje, este mensaje va a ser leido por el servidor*/

	do{

			printf("\nMenu:\n");
			printf("1) Ingresar una cadena de ADN manualmente \n");
			printf("2) Ingresar una cadena de ADN desde un archivo \n");
			printf("9) Salir\n");
			printf("Elija una opción:");

		do {
			charin=getchar();
			opcion=charin - '0';	//Convierte char en int

		}while ((opcion != 1) && (opcion != 2) && (opcion != 9));

		switch(opcion) {
        case 1:		//Entrada manual de datos

			printf("\nIngrese la secuencia de ADN (A,C,G,T):");

			getchar();

			bzero(buffer,sizeof(buffer));//Inicializa el buffer
   			fgets(buffer,sizeof(buffer),stdin);

   			/* Envia el mensaje al servidor */
   			n = send(sockfd, buffer, sizeof(buffer),0);

			if (n < 0) {
	      		perror("\nERROR escribiendo en el socket (writing to socket)\n");
      			exit(1);
   			}

	   		/* Lee la respuesta del servidor */
	   		bzero(buffer,sizeof(buffer));	//Inicializa el buffer
	   		n = recv(sockfd, buffer, sizeof(buffer),0);

			//printf("\nBytes:%i\n",n);
	   		if (n < 0) {
		  		perror("\nERROR leyendo desde el socket (reading from socket)\n");
		  		exit(1);
	   		}

	   		printf("Respuesta: %s\n",buffer);	//Muestra el mensaje!!!

			break;

		case 2:	//Desde archivo
			archin = fopen("adn_in.txt","r");
			archout = fopen("adn_out.txt","w");

			if (archin == NULL){
		 		printf("\nError de apertura del archivo. \n\n");
				fputs ("File error",stderr);
				exit (1);}
			else{
		 		printf("ADN  ARN\n");
				printf("---  ---\n");

				while (feof(archin) == 0)
				{
					carain = fgetc(archin);

					if (carain == 'A'){ caraout='U';++ain;++uout;}
					else {if (carain == 'C'){ caraout='G';++cin;++gout;}
					else {if (carain == 'G'){ caraout='C';++gin;++cout;}
					else {if (carain == 'T'){ caraout='A';++tin;++aout;}
					else {caraout='?';}}}}

					if (caraout!='?'){
						fputc (caraout, archout);
						printf("%c ---> %c\n",carain,caraout);
					}
				}

				fclose(archin);
				fclose(archout);
			}
				printf("\nEstadísticas\n");
				printf("ADN: A=%i C=%i G=%i T=%i\n",ain,cin,gin,tin);
				printf("ARN: A=%i C=%i G=%i U=%i\n",aout,cout,gout,uout);

			break;
		case 9:	//Salir
			printf("\nBye!\n");
			exit(0);
		}
	}while (opcion !=9);

	return 0;
}
