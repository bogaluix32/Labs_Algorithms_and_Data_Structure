/* Laboratorio 2
Estudiante Luis Jimenez Bogantes*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h> 
#include <ctype.h>

/*Inicio reto 1:
Entradas: dos listas del mismo tamano (vector1[] y vector2[]).
Salidas: una lista (vectorResultado[]) con el resultado de sumar cada elemento de la primera lista con el elemento de la segunda lista que está en el mismo indice
Restricciones: las listas de entrada deben ser del mismo tamano.
*/

int sumar_elementos_vectores(){
        int i, tamano;
        float numeroEnVector1, numeroIngresado, numeroEnVector2, suma;

        printf("Ingrese el tamano de las listas: ");
        scanf("%d", &tamano);

        float vector1[tamano], vector2[tamano], vectorResultado[tamano];

        for (i = 0; i < tamano; i++){
            printf("Ingrese un numero para anadir a la primera lista: ");
            scanf("%f", &numeroIngresado);

            vector1[i] = numeroIngresado;
        }

        for (i = 0; i < tamano; i++){
            printf("Ingrese un numero para anadir a la segunda lista: ");
            scanf("%f", &numeroIngresado);

            vector2[i] = numeroIngresado;
        }

        for (i = 0; i < tamano; i++){
            numeroEnVector1 = vector1[i];
            numeroEnVector2 = vector2[i];
            suma = numeroEnVector1 + numeroEnVector2;
            vectorResultado[i] = suma;
        }

        for (i = 0; i < tamano; i++){
            printf("La suma es: %.1f\n", vectorResultado[i]);
        }

        return 0;
    }

//Fin reto 1.

/*Inicio reto 2:
Entradas: una matriz[n][m]
Salidas: True si en la matriz hay un 0. False en caso contrario.
Restricciones: La matriz no debe estar vacía.
*/

char* hay_ceros_matriz(int filas, int columnas, int matriz[filas][columnas]){
        int i, j; 
        char* verdadero = "True";
        char* falso = "False";

        for (i = 0; i < filas; i++){
            for (j = 0; j < columnas; j++){
                if (matriz[i][j] == 0){
                    return verdadero;
                }
            }
        }

        return falso;
    }

//Fin reto 2

/*Inicio reto 3:
Entradas: una frase(cadena).
Salidas: el numero de palabras que conforman la frase.
Restricciones: la frase no debe ser vacía.
*/

void cantidad_palabras_frase(char* cadena){
        int i, contadorPalabras = 1, longitudFrase;

        longitudFrase = strlen(cadena);

        for (i = 0; i < longitudFrase; i++){
            if (cadena[i] == ' ' && cadena[i+1] != '\0'){
                contadorPalabras++;
            }
        }

        printf("La cantidad de palabras es: %d\n", contadorPalabras);
    }

//Fin reto 3

/*Inicio reto 4:
Entradas: una frase(cadena).
Salidas: el numero de vocales que contiene la frase.
Restricciones: la frase no debe ser vacía.
*/

void contar_vocales(char* cadena){
        int i, contadorVocalA = 0, contadorVocalE = 0, contadorVocalI = 0, contadorVocalO = 0, contadorVocalU = 0, longitudCadena;

        longitudCadena = strlen(cadena);

        for (i = 0; i < longitudCadena; i++){
            if (cadena[i] == 'A' || cadena[i] == 'a')
                contadorVocalA++;
            else if (cadena[i] == 'E' || cadena[i] == 'e')
                    contadorVocalE++; 
            else if (cadena[i] == 'I' || cadena[i] == 'i')
                    contadorVocalI++;
            else if (cadena[i] == 'O' || cadena[i] == 'o')
                    contadorVocalO++;
            else if (cadena[i] == 'U' || cadena[i] == 'u')
                    contadorVocalU++;
        }

        printf("Cadena evaluada: %s\n", cadena);
        printf("Cantidades de vocales A: %d\n", contadorVocalA);
        printf("Cantidades de vocales E: %d\n", contadorVocalE);
        printf("Cantidades de vocales I: %d\n", contadorVocalI);
        printf("Cantidades de vocales O: %d\n", contadorVocalO);
        printf("Cantidades de vocales U: %d\n", contadorVocalU);
    }

//Fin reto 4

/*Inicio reto 5:
Entradas: ISBN, nombre del autor, nacionalidad del autor, genero del libro, fecha de publicacion, cantidad de libros a registrar.
Salidas: la cantidad de libros por genero.
Restricciones: los datos no pueden ser vacíos.
*/

void registro_libros(){
        int i, cantidadLibros, suspensoContador = 0, terrorContador = 0, educacionContador = 0, cienciaFiccionContador = 0, romanticismoContador = 0, novelasContador = 0, poesiaContador = 0, otrosContador = 0;
        bool repetir;

        printf("Ingrese la cantidad de libros a registrar:\n");
        scanf("%d", &cantidadLibros);

        struct RegistroLibros{
            int ISBN;
            int generoLibro;
            char* fecha;
            struct DatosAutor{
                char* nombre;
                char* nacionalidad;
            }vectorAutores[cantidadLibros];
            
        }vectorLibros[cantidadLibros];
        
        for (i = 0; i < cantidadLibros; i++){

            printf("Ingrese el ISBN del libro:\n");
            scanf("%d", &vectorLibros[i].ISBN);

            do{
                printf("Generos disponibles:\n 1. Suspenso | 2. Terror | 3. Educacion | 4. Ciencia ficcion | 5. Romanticismo | 6. Poesia | 7. Novela | 8. Otros generos\n");
                printf("Ingrese el numero correspondiente a cada genero:\n");
                scanf("%d", &vectorLibros[i].generoLibro);

                switch (vectorLibros[i].generoLibro){

                    case 1:
                        ++suspensoContador;
                        repetir = false;
                        break;
                    
                    case 2:
                        ++terrorContador;
                        repetir = false;
                        break;
                    
                    case 3:
                        ++educacionContador;
                        repetir = false;
                        break;
                    
                    case 4: 
                        ++cienciaFiccionContador;
                        repetir = false;
                        break;
                    
                    case 5:
                        ++romanticismoContador;
                        repetir = false;
                        break;
                    
                    case 6:
                        ++poesiaContador;
                        repetir = false;
                        break;

                    case 7:
                        ++novelasContador;
                        repetir = false;
                        break;
                    
                    case 8:
                        ++otrosContador;
                        repetir = false;
                        break;
                    
                    default:
                        printf("Numero incorrecto\nIntente de nuevo\n");
                        repetir = true;
                        break;
                }

            } while (repetir == true);
        
            printf("Ingrese la fecha de publicacion del libro:\n");
            scanf("%s", &vectorLibros[i].fecha);

            printf("Ingrese el nombre del autor:\n");
            scanf("%s", &vectorLibros[i].vectorAutores[i].nombre);

            printf("Ingrese la nacionalidad del autor:\n");
            scanf("%s", &vectorLibros[i].vectorAutores[i].nacionalidad);
        }

        printf("Total de generos registrados: \n");
        printf("Suspenso: %d\n", suspensoContador);
        printf("Terror %d\n", terrorContador);
        printf("Educacion: %d\n", educacionContador);
        printf("Ciencia ficcion: %d\n", cienciaFiccionContador);
        printf("Romanticismo: %d\n", romanticismoContador);
        printf("Poesia: %d\n", poesiaContador);
        printf("Novela: %d\n", novelasContador);
        printf("Otros generos: %d\n", otrosContador);
    }

//Fin reto 5

int main(){   
        int matriz[4][3] = {{4,0,2},{5,1,8},{3,2,7},{9,6,2}};
        char* cadena = "Hola programador";

        //sumar_elementos_vectores();
        
        //printf("%s\n", hay_ceros_matriz(4, 3, matriz));

        //cantidad_palabras_frase(cadena);

        //contar_vocales(cadena);

        registro_libros();

        return 0;
    }