#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{ 
   
  int op;
  do
{
  system("cls");//limpia la pantalla
  system("color f4");//cambia el color 
  printf("*----------------------*\n");
  printf("|        Menu          |\n");
  printf("|        Agenda FI     |\n");
  printf("|   1.Buscar           |\n");
  printf("|   2.Registrar        |\n");
  printf("|   3.Modificar        |\n");
  printf("|   4.Borrar           |\n");
  printf("|   5.Listado          |\n");
  printf("|   6.Salir          |\n");
  printf("*----------------------*\n");
  printf("Seleccione una opcion\n");
  scanf("%d", &op);
  system("color f1");
    switch (op)                    
    {
      case(1): printf("Funcion Buscar\n");//obviamente se sustiruira el printf por la funcion 
            system ("pause");//pausa el programa hasta ingresemos una tecla
      break;
 
      case(2): printf("Aqui va FRegistrar\n");
      system ("pause");
      break;

      case(3): printf("Aqui va FModificar\n"); 
      system ("pause");
      break;

      case(4): printf("Aqui va FBorrar\n");
      system ("pause");
      break;
 
      case(5): printf("Aqui va FListado\n");
      system ("pause");
      break;
	  
	  case(6): printf("Hasta Pronto\n");
	  system ("pause");
	  break;
	  
	  default: printf("ERROR\n");
      system ("pause");
     }
   }while (op!=6);
  return 0;
}


 

    
