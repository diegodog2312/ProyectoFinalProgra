//INICIALIZAR
//Sirve para iniciar todo en 0, solo se ejecuta una vez 
#include <stdio.h>
#include <string.h>
#define MAX 5

struct p {
 int n;	
};

struct persona{
	char nombre [50];
	char apellido [50];
	int telcel;
	int telcasa;
	int teltrab;
	char correo [50];
	char dir [50];
};
int main (){
	FILE *F;
	F = fopen("nocontactos.txt", "wb");
	struct p personas;
	personas.n = 0;
	fwrite(&personas,sizeof(struct p),1,F);
	fclose(F);	
	
	FILE *G;
	G = fopen("contactos.txt", "wb");
	struct persona personass[MAX];
	for(int i=0; i<MAX; i++){
		strcpy(personass[i].nombre,"0");
		strcpy(personass[i].apellido,"0");
		personass[i].telcel = 0;
		personass[i].telcasa = 0;
		personass[i].teltrab = 0;
		strcpy(personass[i].correo,"0");
		strcpy(personass[i].dir,"0");
		
		printf("%i. \tNombre: %s\n",i+1,personass[i].nombre);
		printf("Apellido: %s\n",personass[i].apellido);
		printf("Telefono de celular: : %i\n",personass[i].telcel);
		printf("Telefono de casa: : %i\n",personass[i].telcasa);			
		printf("Telefono de trabajo: : %i\n",personass[i].teltrab);
		printf("Correo electronico: %s\n",personass[i].correo);
		printf("Direccion: %s\n",personass[i].dir);
	}
	fwrite(&personass, sizeof(struct persona), MAX, F);
	fclose(G);	
return 0;	
}