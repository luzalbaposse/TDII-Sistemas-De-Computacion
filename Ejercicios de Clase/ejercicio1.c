#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Hay que hacer una función que tome un string en minúscula y lo pase a mayúscula.
*/


void springToUpperCase(char *string){
    /*
    Requiere: que ingresemos un string en minúscula
    Devuelve: el mismo string en mayúscula
    */
    int i = 0;
    if (string == NULL){
        return;
    }else{
        while(string[i]!= '\0'){ // Mientras el string no termine
        if (string[i] >= 'a' && string[i] <= 'z'){ // Si el caracter es una letra minúscula lo pasa a mayúscula teniendo en cuenta la tabla ASCII
            string[i]= string[i]-32; // Le restamos 32 bits para que llegue a mayúscula
        }
        i++;
    }
    return;

    }
}

// Testeamos
