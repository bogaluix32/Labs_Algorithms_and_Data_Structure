/* Laboratorio 1 
Estudiantes: Luis Jimenez Bogantes y Valentina Mendez Solano*/

#include <stdio.h>
#include <math.h>

int producto_Tres_Numeros()
    {
        int numero1, numero2, numero3, resultado = 1; 

        printf("Ingrese el primer numero: ");
        scanf("%d", &numero1);
        printf("Ingrese el segundo numero: ");
        scanf("%d", &numero2);
        printf("Ingrese el tercer numero: ");
        scanf("%d", &numero3);

        resultado = numero1 * numero2 * numero3;

        return resultado;
    }

int calcular_cuadrado_cubo()
    {
        int rangoInicio, rangoFin, contador, cuadrado, cubo; 

        printf("Ingrese el numero de inicio: ");
        scanf("%d", &rangoInicio);
        printf("Ingrese el numero de fin: ");
        scanf("%d", &rangoFin);

        printf("Numero \t Cuadrado \t Cubo\n");
        for (contador = rangoInicio; contador <= rangoFin; contador++){
            cuadrado = pow(contador, 2);
            cubo = pow(contador, 3);
            printf("%d\t %d\t\t %d\n", contador, cuadrado, cubo);
        }

        return 0; 
    }

int contadora_numeros()
    {
        float numero;
        int contadorNegativos = 0, contadorCeros = 0, contadorPositivos = 0;

        while (numero != 1.0){

            printf("Ingrese numeros enteros o 1.0 para terminar: ");
            scanf("%f", &numero); 

            if (numero == 2.5)
                break; 
            else {
                if (numero < 0)
                    contadorNegativos++;
                else if (numero == 0)
                    contadorCeros++;
                else
                    contadorPositivos++;
            }
        }

        printf("La cantidad de numeros negativos es: %d\n", contadorNegativos);
        printf("La cantidad de numeros positivos es: %d\n", contadorPositivos);
        printf("La cantidad de ceros es: %d\n", contadorCeros);

        return 0;
    }

int estado_nota()
    {
        float nota; 
        
        printf("Ingrese la nota obtenida en el curso: ");
        scanf("%f", &nota); 

        if (nota >= 0 && nota < 5.0)
            printf("Suspenso");

        else if (nota >= 5.0 && nota < 6.5)
            printf("Aprobado");

        else if (nota >= 6.5 && nota < 8.5)
            printf("Notable");
            
        else if (nota >= 8.5 && nota < 10)
            printf("Sobresaliente");

        else if (nota == 10)
            printf("Nota de honor");
        
        return 0;
    }

int main()
    {
        printf("El resultado de la mutiplicacion es: %d\n", producto_Tres_Numeros());
        calcular_cuadrado_cubo();
        contadora_numeros();
        estado_nota();

        return 0;
    }