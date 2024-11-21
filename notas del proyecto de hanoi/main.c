/*
5x07-Torres_de_Hanoi_parte_2
24/01/2012

Escribe un programa (se recomienda que sea recursivo) que d� soluci�n al problema de las torres de Hanoi.
El enunciado es el siguiente: Se dispone de una torre formada por varios discos de diferentes di�metros denominada torre O (origen),
donde cada disco es de di�metro inferior a todos los que est�n por debajo. Se dispone de otras dos torres para dejar discos, una denominada torre A (auxiliar) y otra torre D (destino).
El problema consiste en pasar todos los discos de la torre O a la torre D respetando dos normas muy simples:

Los discos se pasan de una torre a otra de uno en uno.
Nunca un disco de mayor di�metro puede estar sobre otro de menor di�metro.
Se preguntar� al inicio del programa por el tama�o de la torre O (entendiendo que tendr� el n�mero de discos indicados, con alg�n l�mite preestablecido).
Las torres A y D estar�n inicialmente vac�as.
Se debe ofrecer la soluci�n que da el programa a este problema paso a paso, mostrando el resultado de una forma gr�fica. El inicio podr�a ser algo as�:

*
    ***
   *****
*******
*********
    ===========		==========		==========
O				A				D


Formula para calcular movimientos m�nimos necesarios:
m = 2^n -1

http://www.rodoval.com/heureka/hanoi/
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void imprime( int *tab, int fil, int col, int ultNum ) /* hay un puntero, el siguiente es un entero que indica las filas, el tercero es un entero que indica las columnas, el ultimo es un entero.*/
{

    /*
    Precondici�n:
    *tab	Puntero a una matriz de tipo entero.
    fil		Entero que indica el numero de filas de la matriz.
    col		Entero que indica el numero de columnas de la matriz.
    disc	Par�metro de tipo entero que indica el numero de discos usados.
    ultNum	Entero que indica el numero que esta usando el disco mas grande.
    */


    int f, c; /* esta indentificando dos variables .*/
    int i, esp; /* esta indentificando dos variables .*/


    for( c=col-1; c >= 0; c-- ) /* este es un for que repite esta formula varias para la columna vez con los enteros y variables indentificados. */
    {
        for( f=0; f < fil; f++ ) /* este es un for que repite esta formula varias para la filas vez con los enteros y variables indentificados. */
    {
        {
            esp = ( ultNum - tab[col*f+c] )/2;  /*Calcula los espacios necesarios para centrar el disco actual.*/

// Espacios a la izquierda
            for( i=0; i < esp; i++ ) /* Imprime espacios a la izquierda del disco. */
                printf( " " );

// Imprime los comodines
            for( i=0; i < tab[col*f+c]; i++ ) /*Imprime el disco con * proporcional al tama�o almacenado en la matriz.*/
                printf( "*" );

// Espacios a la derecha
            for( i=0; i < esp; i++ ) /* Imprime espacios a la derecha del disco. */
                printf( " " );

            printf( "\t" ); /*A�ade un tabulador entre torres.*/
        };

        printf( "\n" );
    };


};


void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest )  /*filOrig: Torre de origen. filDest: Torre de destino.*/
{
    /*
    Precondici�n:
    *tab	Puntero a una matriz de tipo entero.
    fil		Entero que indica el numero de filas de la matriz.
    col		Entero que indica el numero de columnas de la matriz.
    disc	Par�metro de tipo entero que indica el numero de discos usados.
    ultNum	Entero que indica el numero que esta usando el disco mas grande.
    filOrig	Entero que indica el numero de fila de la matriz en la cual hay que coger el numero/disco
    filDest	Entero que indica el numero de fila de la matriz en la cual hay que dejar el numero/disco.
    Poscondici�n:
    Se mueve el disco y se llama a la funci�n que imprime el tablero.
    */


    int cO=col-1, cD=col-1; /*Inicializa cO y cD en la posici�n m�s alta de las columnas correspondientes a las torres origen y destino.*/


// Se busca el disco que se encuentre mas arriba y por lo tanto el mas peque�o de la fila de origen.
    while( cO >= 0  &&  tab[col*filOrig+cO] == 0 ) /* Busca el disco m�s alto en la torre origen.*/
    {
        cO--;
    };
    if( cO < 0 ) /*Asegura que cO no sea negativo (en caso de que la torre est� vac�a).*/
        cO = 0;

// Ahora se calcula cual es la posici�n libre mas arriba de la fila de destino
    while( cD >= 0  &&  tab[col*filDest+cD] == 0 ) /* Busca la posici�n m�s alta disponible en la torre destino.*/
    {
        cD--;
    };

// Se mueve el disco de la fila de origen a la de destino:
    tab[col*filDest+cD+1] = tab[col*filOrig+cO];
    tab[col*filOrig+cO] = 0; /*Mueve el disco desde la torre origen a la torre destino.*/

// Se imprime el tablero:
    imprime( tab, fil, col, ultNum ); /*Mueve el disco desde la torre origen a la torre destino.*/
};


void hanoi( int *tab, int fil, int col, int disc, int ultNum, int O, int A, int D ) /* disc: N�mero de discos restantes a mover. O, A, D: Torres de origen, auxiliar y destino. */
{
    /*
    Precondici�n:
     *tab	Puntero a una matriz de tipo entero.
     fil		Entero que indica el numero de filas de la matriz.
     col		Entero que indica el numero de columnas de la matriz.
     disc	Par�metro de tipo entero que indica el numero de discos usados.
     ultNum	Entero que indica el numero que esta usando el disco mas grande.
     O,A,D	Tres enteros que indican la fila desde donde se ha de coger el disco y a donde se ha de traspasar. La primera vez que se llama a hanoi tienen los valores de: 0 ,1 y 2 respectivamente.
    Poscondici�n:
     Se llama recursivamente a hanoi hasta resolver el tablero.
    */


    if( disc==1 ) /* Caso base: si hay un solo disco, simplemente se mueve. */
    {
// Se borra la pantalla, se imprime la tabla y se hace una
//pausa que varia dependiendo del numero de discos:
        system("cls"); /* Limpia la pantalla y mueve el disco de origen a destino. */
        mueveDisco( tab, fil, col, ultNum, O, D ); /* Ajusta el tiempo de pausa seg�n el n�mero de discos. */
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1); /* Ajusta el tiempo de pausa seg�n el n�mero de discos. */
    }
    else
    {
        hanoi( tab, fil, col, disc-1, ultNum, O, D, A );

        system("cls");
        mueveDisco( tab, fil, col, ultNum, O, D );  /* Divide el problema en tres pasos recursivos: Mueve n-1 discos al auxiliar.
                                                         Mueve el disco m�s grande al destino.
                                                         Mueve los n-1 discos del auxiliar al destino. */
        if(col<=5) delay(4);
        else if(col<=10) delay(3);
        else if(col<=15) delay(2);
        else if(col>15) delay(1);

        hanoi( tab, fil, col, disc-1, ultNum, A, O, D );
    };

};

void delay(int tiempo) /* Introduce una pausa simulando retraso mediante bucles anidados. */
{

    int c, d;
    while(tiempo >= 0)
    {
        for (c = 1; c <= 10000; c++)
            for (d = 1; d <= 10000; d++)
            {}
        tiempo--;
    }

}

 int main()
 {
    int fil=3, col, *tablero = NULL; /* Inicializa variables.
                                     fil = 3: Siempre hay tres torres.
                                     col: Se definir� por el n�mero de discos ingresado por el usuario.
                                     tablero: Matriz din�mica para representar las torres. */
    int f, c, disc=1, ultNum;


    printf( "Indique el numero de discos: " ); /* Solicita el n�mero de discos al usuario. */
    scanf( "%i", &col );


    tablero = (int *)malloc( sizeof(int)*fil*col ); /* Reserva memoria para la matriz que representa las torres. */


// Resetea las torres poniendo "los discos" en una de ellas y 0 en el resto.
    for( f=0; f < fil; f++ )
        for( c=col-1; c >= 0; c-- )
            if( f==0 )
            {
                tablero[col*f+c] = disc; /* Llena la torre de origen con los discos y deja las otras vac�as. */
                disc+=2;
            }
            else
                tablero[col*f+c] = 0;

    ultNum = disc; /* Configura el disco m�s grande, imprime el estado inicial y a�ade un retraso antes de comenzar. */

// Se imprime el tablero antes de iniciar ning�n movimiento:
    system("cls");
    imprime( tablero, fil, col, ultNum );
    delay(6);


// Se llama a hanoi para comenzar "la partida":
    hanoi( tablero, fil, col, col, ultNum, 0, 1, 2 ); /* Inicia el algoritmo recursivo de las Torres de Hanoi. */
};
