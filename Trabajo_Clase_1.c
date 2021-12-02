/* Trabajo de clase 1 
Estudiantes: Luis Jimenez Bogantes y Valentina Mendez Solano*/

#include <stdio.h>
#include <string.h>

int media_numeros_vector()
    {
        int i, numero, suma = 0, resultado = 0, vector[10];

        for (i = 0; i < 10; i++){
            printf("Ingrese un numero entero: ");
            scanf("%d", &numero);

            vector[i] = numero;
        }

        for (i = 0; i < 10; i++){
            suma += vector[i];
        }

        resultado = suma / 10;

        printf("La media de los numeros ingresado es: %d\n", resultado);

        return 0; 
    }

int multiplicacion_numeros_vector()
    {
        int i, numeroIngresado, numeroEnVector, numeroMultiplicado, vector[5], vectorResultado[5];

        for (i = 0; i < 5; i++){
            printf("Ingrese un numero entero: ");
            scanf("%d", &numeroIngresado);

            vector[i] = numeroIngresado;
        }

        for (i = 0; i < 5; i++){
            numeroEnVector = vector[i];
            numeroMultiplicado = numeroEnVector * 2;
            vectorResultado[i] = numeroMultiplicado;
        }

        for (i = 0; i < 5; i++){
            printf("La multiplicacion de los numeros ingresados es: %d\n", vectorResultado[i]);
        }

        return 0;
    }

int transpuesta_matriz()
    {
        int i, j, filas = 3, columnas = 3, matriz[filas][columnas], transpuesta[filas][columnas];

        printf("Ingrese los valores que coforman la matriz inicial: \n");

        for (i = 0; i < filas; i++){
            for (j = 0; j < columnas; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        for (i = 0; i < filas; i++){
            for (j = 0; j < columnas; j++){
                transpuesta[j][i] = matriz[i][j];
            }
        }

        for (i = 0; i < filas; i++){
            printf("\n");
            for (j = 0; j < columnas; j++){
                printf(" %d ", transpuesta[i][j]);
            }
        }

        return 0;
    }

int contar_apariciones_caracter(char* cadena, char caracter)
    {
        int i, apariciones = 0, longitudCadena;

        longitudCadena = strlen(cadena);

        for (i = 0; i < longitudCadena; i++){
            if (cadena[i] == caracter)
                apariciones++;
        }

        return apariciones;
    }

int registro_trabajadores()
    {
        int i, cantidadTrabajadores, nombreMayor, nombreMenor; 
        float mayorSalario = 0.0, menorSalario = 99999.0;

        printf("Ingrese la cantidad de empleados a registrar:\n");
        scanf("%d", &cantidadTrabajadores);

        struct RegistroTrabajador{
            char* nombre[50]; 
            char* sexo[10]; 
            float salario;
        } vectorTrabajador[cantidadTrabajadores];
        
        for (i = 0; i < cantidadTrabajadores; i++){

            printf("Ingrese el nombre del trabajador:\n");
            scanf("%s", &vectorTrabajador[i].nombre);

            printf("Ingrese el sexo del trabajador:\n");
            scanf("%s", &vectorTrabajador[i].sexo);

            printf("Ingrese el salario del trabajador:\n");
            scanf("%f", &vectorTrabajador[i].salario);

            if (vectorTrabajador[i].salario > mayorSalario){
                mayorSalario = vectorTrabajador[i].salario;
                nombreMayor = i;
            }

            if (vectorTrabajador[i].salario < menorSalario){
                menorSalario = vectorTrabajador[i].salario;
                nombreMenor = i;
            }
        }

        printf("%s tiene el mayor salario %.2f\n", vectorTrabajador[nombreMayor].nombre, mayorSalario);
        printf("%s tiene el menor salario %.2f\n", vectorTrabajador[nombreMenor].nombre, menorSalario);

        return 0;
    }

int main()
    {
        char* cadena = "Programacion en C"; 
        char caracter = 'o'; 

        media_numeros_vector();

        multiplicacion_numeros_vector();

        transpuesta_matriz();

        printf("\n");

        printf("La cantidad de apariciones del caracter %c en la cadena %s es: %d\n", caracter, cadena, contar_apariciones_caracter(cadena, caracter));
        
        registro_trabajadores();

        return 0;
    }