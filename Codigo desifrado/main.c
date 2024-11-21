#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() //32-126 define el punto de inicio del programa.
{
	char frase[100]; /* arreglo de caracteres para almacenar la frase incresada por la persona. */
	int key; /* variable entera para la clave de cifrado ingresada por el usuario */
	int i,salto=0; /* i, contador para recorrer los caracteres de la cadena. salto, variable que ajusta el desplazamiento de caracteres cifrados si se pasa del rango */

	while(1)
	{
		system("cls"); /* Limpia la pantalla */
		printf("Ingresa la frase a cifrar: "); /* pide a la persona que ponga una frase */
		gets(frase); //scanf("%s",frase); lee la frase ingresada, incluyendo espacios, y la almacena en frase
		do{
			printf("Inserisci la chiave di cifratura: ");
			scanf("%d",&key); /* Lee la clave ingresada y la almacena en key */
		}while(key<1 || key>10); /* solicita un número entero entre 1 y 10, si la entrada está fuera del rango, vuelve a pedirla **/
		printf("\n\n----------------------------------\nFrase cifrata:\n");

		for(i=0; i<strlen(frase); i++,salto=0) /* i = 0 inicializa el contador. i < strlen(frase) itera mientras i sea menor que la longitud de la frase. i++ incrementa el contador. salto = 0 restablece el valor de ajuste en cada iteración. */

			if(frase[i]>126-key) /* comprueba si el carácter cifrado supera el rango 126 */
			{
				salto=95; /* i el carácter excede el rango resta 95 para volver al rango 32-126. */
			}
			printf("%c",frase[i]+key-salto); /* frase[i] + key suma la clave para mover el carácter hacia adelante en el rango, - salto ajusta el valor si es necesario */
		}

		printf("\n\n");
		system("pause"); /* pausa el programa hasta que la persona presione una tecla. */
	}

