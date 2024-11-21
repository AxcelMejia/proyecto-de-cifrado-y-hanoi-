#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() //32-126 Define la función principal que ejecuta el programa.
{
	char frase[100]; /*Cadena para almacenar la frase ingresada. */
	int key; /* Almacena el valor de la clave de descifrado que introduzca el usuario.*/
	int i,salto=0; /* i contador para iterar sobre la cadena, salto es una Variable que ajusta el desplazamiento en caso de que los caracteres descifrados salgan del rango 32 a 126. */

	while(1)
	{
		system("cls"); /* Limpia la pantalla */
		printf("Ingresa la frase a decifrar: "); /* pide que diga la frase*/
		gets(frase); //scanf("%s",frase); /* lee la entrada como una cadena completa, permitiendo espacios. */
		do{
			printf("Inserisci la chiave di cifratura: "); /* Solicita al usuario un número para usar como clave de descifrado. */
			scanf("%d",&key);
		}while(key<1 || key>10); /* Valida que la clave esté en el rango de 1 a 10 si no vuelve a pedir la clave. */
		printf("\n\n----------------------------------\nFrase decifrata:\n");

		for(i=0; i<strlen(frase); i++,salto=0) /* i = 0 inicializa el índice del carácter, i < strlen(frase) repite el bucle mientras i sea menor que la longitud de la cadena,
		                                        i++ incrementa i en cada iteración, salto = 0 reinicia el ajuste de desplazamiento en cada iteración */
		{
			if(frase[i]<32+key) /* Comprueba si el carácter actual, después de descifrarlo, caería fuera del rango 32 */
			{
				salto=95; /* Ajusta el desplazamiento sumando 95 para volver al inicio del rango del 32 a 126 */
			}
			printf("%c",frase[i]-key+salto); /* descifra la letra actual aplicando la fórmula */
		}

		printf("\n\n");
		system("pause"); /* pausa la ejecución del programa hasta que la persona presione una tecla. */
	}
}
