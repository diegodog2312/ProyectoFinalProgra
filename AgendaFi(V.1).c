//AGENDA
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Tamaño del arreglo de contactos
#define MAX 5

//Estructura para los datos de contactos
struct persona{
	char nombre [50];
	char apellido [50];
	int telcel;
	int telcasa;
	int teltrab;
	char correo [50];
	char dir [50];
};

//Estructura para guardar el numero de contactos
struct p {
 int n;	
};

int contador();
void aumento();
void registrar ();
int buscar();
void mostrar();
void borrar();
int v=0;
void modificar();


int main () { 
 
  int op;
  do 
  
{
  system("cls");//limpia la pantalla
  system("color E0");//cambia el color 
  printf("*___________________________________________________________________________________________________________________________*\n");
  printf("*___________________________________________________________________________________________________________________________*\n");
  printf("|                                                                                                                           |\n");
  printf("|   :::   :::       ::::::::::       ::::    :::      :::    :::                                                            |\n");
  printf("|  :+:+: :+:+:      :+:              :+:+:   :+:      :+:    :+:                                                            |\n"); 
  printf("| +:+ +:+:+ +:+     +:+              :+:+:+  +:+      +:+    +:+                                                            |\n");
  printf("| +#+  +:+  +#+     +#++:++#         +#+ +:+ +#+      +#+    +:+                                                            |\n");
  printf("| +#+       +#+     +#+              +#+  +#+#+#      +#+    +#+                                                            |\n");
  printf("| #+#       #+#     #+#              #+#   #+#+#      #+#    #+#                                                            |\n");
  printf("| ###       ###     ##########       ###    ####       ########                                                             |\n");
  printf("|                                                                                                                           |\n");
  printf("|     :::      ::::::::  :::::::::: ::::    ::: :::::::::      :::              :::::::::: :::::::::::                      |\n");
  printf("|   :+: :+:   :+:    :+: :+:        :+:+:   :+: :+:    :+:   :+: :+:            :+:            :+:                          |\n");
  printf("|  +:+   +:+  +:+        +:+        :+:+:+  +:+ +:+    +:+  +:+   +:+           +:+            +:+                          |\n");
  printf("| +#++:++#++: :#:        +#++:++#   +#+ +:+ +#+ +#+    +:+ +#++:++#++:          :#::+::#       +#+                          |\n");
  printf("| +#+     +#+ +#+   +#+# +#+        +#+  +#+#+# +#+    +#+ +#+     +#+          +#+            +#+                          |\n");
  printf("| #+#     #+# #+#    #+# #+#        #+#   #+#+# #+#    #+# #+#     #+#          #+#            #+#                          |\n");
  printf("| ###     ###  ########  ########## ###    #### #########  ###     ###          ###        ###########                      |\n");
  printf("|                                                                                                                           |\n");
  printf("|  Total de contactos en la agenda: %i \n  ", contador()-v);																	  
  printf("|   1.Buscar                                                                                                                |\n");
  printf("|   2.Registrar                                                                                                             |\n");
  printf("|   3.Modificar                                                                                                             |\n");
  printf("|   4.Borrar                                                                                                                |\n");
  printf("|   5.Listado                                                                                                               |\n");
  printf("|   6.Salir                                                                                                                 |\n");
  printf("*___________________________________________________________________________________________________________________________*\n");
  printf("*___________________________________________________________________________________________________________________________*\n");
  printf("Seleccione una opcion: ");
  scanf("%d", &op);

  while (op!=1 && op!=2 &&op!=3 &&op!=4 && op!=5 && op!=6) {
  	  system("cls");
      system ("color 4");
	  printf("SELECCIONA UNA OPCION VALIDA\n");
	  printf("1.Buscar\n");
	  printf("2.Registrar\n");
	  printf("3.Modificar\n");
	  printf("4.Borrar\n");
	  printf("5.Listado\n");
	  printf("6.Salir\n");
	  scanf("%d", &op);
  }
  system("cls");
  system("color 7");
    switch (op)                    
    {
      case(1): 
	  buscar();
      system ("pause");//pausa el programa hasta ingresemos una tecla
      break;
 
      case(2): 
	  registrar();
      system ("pause");
      break;

      case(3): 
	  modificar();
      system ("pause");
      break;

      case(4): 
	  borrar();
	  v++;
      system ("pause");
      break;
 
      case(5):
	  mostrar();
      system ("pause");
      break;
      
      case(6): printf("\tVUELVA PRONTO\n");
      system ("pause");
      break;
      
    
     }
   } while (op!=6);
   
   
  return 0;
 
}

 
//CONTADOR
//Cuenta el numero de contactos
int contador(){
	int people;
	FILE *F;
	F = fopen("nocontactos.txt", "rb");
	struct p person;
	fread(&person, sizeof(struct p), 1, F);
	people = person.n;
	fclose(F);	
	return people;
}

//AUMENTO
//Aumenta cuando se registra un nuevo contacto
void aumento(){
	int i = contador();
	FILE *G;
	G = fopen("nocontactos.txt", "rb+");
	struct p person;
	person.n = i+1;
	fwrite(&person, sizeof(struct p), 1, G);
	fclose(G);	
}

//REGISTRAR   
 void registrar (){ 
	system("cls");
	FILE *F;
	int longi;
	int a = contador();
	F = fopen("contactos.txt", "rb");
	struct  persona personas[MAX];
	struct persona personass[MAX];
	fread(&personas, sizeof(struct persona), MAX, F);
	fclose(F);	
	system("color B0");
	printf("Ingrese el nombre: " );
    fflush(stdin);
	scanf("%s", &personas[a].nombre);
	longi = strlen(personas[a].nombre);
	while (longi==0) {
		system("cls");
		system ("color 4");
		printf("INGRESE UN NOMBRE: \n");
		fflush(stdin);
		scanf("%s", &personas[a].nombre);
		longi = strlen(personas[a].nombre);
	}
	system("color B0");
	setbuf(stdin, NULL);
    printf("==============================================================\n");    
	printf("Introduzca sus apellidos: ");
    scanf("%s", &personas[a].apellido);
	printf("==============================================================\n");
    printf("Digite su celular: ");
    scanf("%i", &personas[a].telcel);
    printf("==============================================================\n");    
    printf(" Digite su Telefono de casa: ");
    scanf("%i", &personas[a].telcasa);
    printf("==============================================================\n");    
    printf("Digite su Telefono de trabajo: ");
    scanf("%i", &personas[a].teltrab);
    printf("==============================================================\n");    
    printf("Introduzca su direccion: ");
    scanf("%s", &personas[a].dir);
    printf("==============================================================\n");    
    printf("Introduzca su correo electronico: ");
    scanf("%s", &personas[a].correo);
    setbuf(stdin, NULL);
	
	
	for(int i=0;i<MAX;i++){
		strcpy(personass[i].nombre, personas[i].nombre);
		strcpy(personass[i].apellido, personas[i].apellido);
		personass[i].telcel = personas[i].telcel;
		personass[i].telcasa = personas[i].telcasa;
		personass[i].teltrab = personas[i].teltrab;
		strcpy(personass[i].correo, personas[i].correo);
		strcpy(personass[i].dir, personas[i].dir);
	}
	F = fopen("contactos.txt", "wb");
	
	
	fwrite(&personass, sizeof(struct persona), MAX, F);
	fclose(F);
	
	printf("\nSe ha registrado correctamente.\n");
	aumento();
}

//MODIFICAR
 void modificar(){
	system("cls");
	FILE *F;
    F = fopen("contactos.txt", "rb");
    struct persona personas[MAX];
	struct persona personass[MAX];
    int i = buscar();
	fread(&personas, sizeof(struct persona), MAX, F);
	fclose(F);
	int me ,ci, op;
	
	do
	{
		ci=0;
		system("cls");
		system ("color 03");
		printf("\nQue desea modificar?");
		printf("\n 1.-Nombre \n 2.-Apellidos \n 3.-Numero de celular \n 4.-Numero de casa \n 5.-Numero de trabajo \n 6.-Direccion \n 7.-E-mail \n 8.-Salir\n");
		printf("\nSelecciona una de las siguientes opciones: ");
		scanf("%i",&op);
		switch (op)
		{
            case 1:
                system ("cls");
                system ("color 0c");
		        printf("\t MODIFICAR NOMBRE\n");
                printf("Nombre actual: ");
				printf("%s",personas[i].nombre);
				printf("\nNuevo nombre: ");
				setbuf(stdin, NULL);		       
                scanf("%s",&personas[i].nombre);

                printf("\n\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);               
            break;
            case 2:
                system ("cls");
                system ("color 08");
		        printf("\t MODIFICAR APELLIDOS\n");
				printf("Apellidos actuales: ");
				printf("%s",personas[i].apellido);
				setbuf(stdin, NULL);
				printf("\nNuevos apellidos: ");
				scanf("%s",&personas[i].apellido);         
                printf("\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);
                
            break;
            case 3:
                system ("cls");
                system ("color 05");
		        printf("\t MODIFICAR NUMERO DE CELULAR\n");
				printf("Numero de celular actual: ");
				printf("%i", personas[i].telcel);
				printf("\nNuevo numero de celular: ");
				setbuf(stdin, NULL);
				scanf("%i", &personas[i].telcel);
                
                printf("\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);
            break;
            case 4:
                system ("cls");
                system ("color 0a");
		        printf("\t MODIFICAR NUMERO DE CASA\n");
				printf("Numero de casa actual: ");
				printf("%i", personas[i].telcasa);
		        printf("\nNuevo numero de casa: ");
				setbuf(stdin, NULL);
				scanf("%i", &personas[i].telcasa);
                printf("\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);
            break;
            case 5:
                system ("cls");
                system ("color 0e");
		        printf("\t MODIFICAR NUMERO DE TRABAJO\n");
				printf("Numero de trabajo actual: ");
				printf("%i", personas[i].teltrab);
				printf("\nNuevo numero de trabajo: ");
				setbuf(stdin, NULL);
				scanf("%i", &personas[i].teltrab);
                printf("\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);
               
            break;
            case 6:
                system ("cls");
                system ("color 0d");
		        printf("\t MODIFICAR DIRECCION\n");
				printf("Direccion actual: ");
				printf("%s", personas[i].dir);
				setbuf(stdin, NULL);
				printf("\nNueva direccion: ");
				scanf("%s", &personas[i].dir);                
                printf("\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);                
            break;
            case 7:
                system ("cls");
                system ("color 02");
		        printf("\t MODIFICAR E-MAIL\n");
				printf("E-mail actual: ");
				printf("%s", personas[i].correo);
		        printf("\nNuevo E-mail: ");
				setbuf(stdin, NULL);
				scanf("%s", &personas[i].correo);
                
                printf("\n\nSe guardo exitosamente \n");
                do{
                    printf("Desea seguir modificando?  \n Escriba  1  para continuar o escriba  0  para salir: ");
                    scanf("%i",&me);
                    if ( me!= 1 && me != 0)
                    {
                        printf("\nOpcion invalida. Por favor intentelo de nuevo \n ");
                    }
                }while( me!= 1 && me != 0);             
            break;
            case 8:
                break;
            break;
            default:
                ci = -1;
                system("cls");
                printf("\n Opcion invalida \n\n\n");
		}
	}while(ci != -1 && me != 0);
	
	for(int i=0;i<MAX;i++){
		strcpy(personass[i].nombre, personas[i].nombre);
		strcpy(personass[i].apellido, personas[i].apellido);
		personass[i].telcel = personas[i].telcel;
		personass[i].telcasa = personas[i].telcasa;
		personass[i].teltrab = personas[i].teltrab;
		strcpy(personass[i].correo, personas[i].correo);
		strcpy(personass[i].dir, personas[i].dir);
	}
	
	F = fopen("contactos.txt", "wb");
	fwrite(&personass, sizeof(struct persona), MAX, F);
	fclose(F);
	
}


//BORRAR
void borrar(){
	int b = buscar();
	int op;
	
	FILE *F;
	F = fopen("contactos.txt", "rb");
	struct persona personas[MAX];
	struct persona personass[MAX];
	fread(&personas, sizeof(struct persona), MAX, F);
	fclose(F);	
	
	printf("Desea eliminar a %s?\n (1 = si / 2 = no): ",personas[b].nombre);
	scanf("%i",&op);
	
	if (op == 1){
		printf("\nEliminando...");
		strcpy(personas[b].nombre,"0");
		strcpy(personas[b].apellido,"0");
		personas[b].telcel = 0;
		personas[b].telcasa = 0;
		personas[b].teltrab = 0;
		strcpy(personas[b].correo,"0");
		strcpy(personas[b].dir,"0");
	    printf(" Se ha eliminado correctamente!\n");
	} 	
	
	for(int i=0;i<5;i++){
		strcpy(personass[i].nombre, personas[i].nombre);
		strcpy(personass[i].apellido, personas[i].apellido);
		personass[i].telcel = personas[i].telcel;
		personass[i].telcasa = personas[i].telcasa;
		personass[i].teltrab = personas[i].teltrab;
		strcpy(personass[i].correo, personas[i].correo);
		strcpy(personass[i].dir, personas[i].dir);
	}
	F = fopen("contactos.txt", "wb");
	
	fwrite(&personass, sizeof(struct persona), MAX, F);
	fclose(F);
}

//BUSCAR
int buscar(){
	system("cls");
	FILE *F;
	int i=0;
	char nom[50];
	int aux[MAX];
	int coincidencia=0;
	int j=0;
	int aux2=1000;
	F = fopen("contactos.txt", "rb");
	struct persona personas[MAX];
	printf("BUSCAR\n");
	printf("Ingrese el nombre del contacto: ");
	scanf("%s", &nom);
	
	fread(&personas, sizeof(struct persona), MAX, F);
	
	for(i=0;i<MAX;i++) {
		if (strcmp(nom,personas[i].nombre) == 0){
			aux[coincidencia] = i;
			coincidencia++;
			aux2=i;
		}
	}
	
	if (coincidencia>1){
		printf("Se ha encontrado mas de una coincidencia: \n");
		for(int k=0; k<coincidencia;k++){
			printf("%i. %s %s\n", k+1,personas[aux[k]].nombre,personas[aux[k]].apellido);
		}
		printf("\n Elija uno: ");
		scanf("%i", &j);
		printf("Nombre: %s\n",personas[aux[j-1]].nombre);
		printf("Apellido: %s\n",personas[aux[j-1]].apellido);
		printf("Telefono de celular: : %i\n",personas[aux[j-1]].telcel);
		printf("Telefono de casa: : %i\n",personas[aux[j-1]].telcasa);			
		printf("Telefono de trabajo: : %i\n",personas[aux[j-1]].teltrab);
		printf("Correo electronico: %s\n",personas[aux[j-1]].correo);
		printf("Direccion: %s\n",personas[aux[j-1]].dir);
		return (aux[j-1]);
		
	} else {
		if (aux2==1000){
			printf("No hay resultados\n");
			return (0);
		} else {
			printf("Nombre: %s\n",personas[aux2].nombre);
			printf("Apellido: %s\n",personas[aux2].apellido);
			printf("Telefono de celular: : %i\n",personas[aux2].telcel);
			printf("Telefono de casa: : %i\n",personas[aux2].telcasa);			
			printf("Telefono de trabajo: : %i\n",personas[aux2].teltrab);
			printf("Correo electronico: %s\n",personas[aux2].correo);
			printf("Direccion: %s\n",personas[aux2].dir);
			return (aux2);
		}
	}
					
	fclose(F);	
}

//MOSTRAR
void mostrar(){
	system("cls");
	int j=1;
	FILE *F;
	F = fopen("contactos.txt", "rb");
	struct persona personass[MAX];
	fread(&personass, sizeof(struct persona), MAX, F);
	
	printf("Estos son tus %i contactos: \n", contador()-v);
	for(int i=0; i<MAX; i++) {
		if(personass[i].telcel!=0){
			printf("==============================================================\n");    
			printf("%i. \tNombre: %s\n",j,personass[i].nombre);
			printf("Apellido: %s\n",personass[i].apellido);
			printf("Telefono de celular: : %i\n",personass[i].telcel);
			printf("Telefono de casa: : %i\n",personass[i].telcasa);			
			printf("Telefono de trabajo: : %i\n",personass[i].teltrab);
			printf("Correo electronico: %s\n",personass[i].correo);
			printf("Direccion: %s\n",personass[i].dir);
			j++;
		}
	}	
	
	fclose(F);	
}
