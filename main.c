

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
///IGNACIO NIZETICH| UTN MAR DEL PLATA

int const fila = 4;
int const columna = 20;
void cargarMatriz(int matriz[][columna], int fila, int columna);
void mostrarMatriz(int matriz[][columna], int fila, int columna);
void MatrizAleatoria(int matriz2[][columna], int fila, int columna);
void MostrarAleatoria(int matriz2[][columna], int fila, int columna);
void mostarArregloString (char arreglo [][columna], int validos);
void buscarDatoEnLaMatriz(int matriz[][columna],int fila,int columna, int dato);
float promedioMatriz(int matriz2[][columna], int fila, int columna);
int datoABuscar();
int sumarMatriz(int matriz2[][columna], int fila, int columna);
int determinarString (char arreglo[][columna], int validos);
int cargarArregloString(char arreglo[][columna], int dim);


int main() {
    srand(time(NULL));
    int matriz[fila][columna];
    int matriz2[fila][columna];
    int mostrar, validos, opc, resultado;
    printf("----------------ELIJA UNA OPCION----------------\n 1    7     13 \n 2    8     14\n 3    9     15\n 4    10    16\n 5    11    17\n 6    12    18\n 7    13    19\n 8    16\n  ");
    fflush(stdin);
    scanf("%i", &opc);

    switch (opc)
    {
    case 1:
        printf("Usted esta en el punto %i \n\n", opc);
        cargarMatriz(matriz, fila, columna);
        mostrarMatriz(matriz, fila, columna);
        break;

    case 2:
        printf("Usted esta en el punto %i \n\n", opc);
        cargarMatriz(matriz, fila, columna);
        mostrarMatriz(matriz, fila, columna);
        break;

    case 3:
        printf("Usted esta en el punto %i \n\n", opc);
        MatrizAleatoria(matriz2, fila, columna);
        MostrarAleatoria(matriz2, fila, columna);
        break;

    case 4:
        printf("Usted esta en el punto %i \n\n", opc);
        MatrizAleatoria(matriz2, fila, columna);
        printf("La matriz que va a ser sumada: \n ");
        MostrarAleatoria(matriz2, fila, columna);
        int suma=sumarMatriz(matriz2, fila, columna);
        printf("La suma de los datos de la matriz es: %i", suma);
        break;

    case 5:
        printf("Usted esta en el punto %i \n\n", opc);
        MatrizAleatoria(matriz2, fila, columna);
        printf("La matriz: \n ");
        MostrarAleatoria(matriz2, fila, columna);
        float promedio = promedioMatriz(matriz2, fila, columna);
        printf("El promedio de los datos de la matriz es: %f", promedio); //ANDA BIEN PERO REDONDEA EL NUMERO NO SE PORQUE
        break;

    case 6:
        printf("Usted esta en el punto %i \n\n", opc);
        cargarMatriz(matriz, fila, columna);
        int dato = datoABuscar();
        buscarDatoEnLaMatriz(matriz,fila,columna,dato);
        break;
    case 7:
        printf("Usted esta en el punto %i \n\n", opc);
        char arreglo[100][columna];
        int validosPunto7=  cargarArregloString(arreglo, 100);
        printf("Se cargaron %i datos \n", validosPunto7);
        mostarArregloString (arreglo,validosPunto7);
        break;
       case 8:
            printf("Usted esta en el punto %i \n\n", opc);
            mostarArregloString (arreglo,validos);
            break;
          case 9:
         resultado =  determinarString(arreglo, validos);
         printf("1 = se encontro la palabra en el arreglo. \n -1 = no se encontro la palabra en el arreglo.", resultado);


          break;

            default:
            printf("OPCION NO VALIDA.");
            break;
    }

    return 0;
}

void cargarMatriz(int matriz[][columna], int fila, int columna) {
    int i = 0;
    int j = 0;

    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            printf("Ingrese un valor para la matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarMatriz(int matriz[][columna], int fila, int columna) {
    int i, j;
    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            printf("|%d|", matriz[i][j]);
        }
        printf("\n");
    }
}

void MatrizAleatoria(int matriz2[][columna], int fila, int columna) {
    int i = 0;
    int j = 0;

    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            matriz2[i][j] = rand() % 10;
        }
    }
}

void MostrarAleatoria(int matriz2[][columna], int fila, int columna) {
    int i = 0, j = 0;

    for (i = 0; i < fila; i++) {
        for (j = 0; j < columna; j++) {
            printf("| %i |", matriz2[i][j]);
        }
        printf("\n");
    }
}

int sumarMatriz(int matriz2[] [columna], int fila, int columna){
int i=0;
int j=0;
int suma=0;

for (i=0; i<fila; i++){
    for(j=0;j<columna;j++){
        suma = suma + matriz2[i][j];
    }
}
return suma;
}

float promedioMatriz(int matriz2[][columna],int fila, int columna){
int i=0;
int j=0;
int contador=0;
int suma=0;
float promedio=0;

for (i=0;i<fila;i++){
    for (j=0;j<columna;j++){
        contador=contador+1;
        suma=suma+matriz2[i][j];
    }
}

promedio=suma/contador;

return promedio;
}

int datoABuscar (){
    int dato;
printf("Ingrese el numero que desea saber si esta en la matriz: ");
fflush(stdin);
scanf("%i", &dato);

return dato;
}

void buscarDatoEnLaMatriz(int matriz[][columna],int fila,int columna, int dato){
int i=0;
int j=0;
int flag=0;

for (i=0;i<fila;i++){
    for(j=0;j<columna;j++){
        if (dato==matriz[i][j]){
            flag=1;
        } else {
        flag=0;
        }

        if (flag==1){
                 printf("El dato se encuentra en la matriz, en la poscion %i %i \n ", i, j);
            mostrarMatriz(matriz,fila,columna);
            i=100;
            j=100;
        }
    }

}
if (flag==0){
    printf("El dato no se encuentra en la matriz \n");
}
}

int cargarArregloString(char arreglo[][columna], int dim){
    int i=0;
    char eleccion='s';

    while(i<dim && eleccion=='s')
    {
        printf("Ingrese una palbra: ");
        fflush(stdin);
        scanf("%s", &arreglo[i]);

        printf("Desea ingresar otro nombre? (S/N): ");
        fflush(stdin);
        scanf("%c", &eleccion);
        i++;
    }
    return i;
}

void mostarArregloString (char arreglo [][columna], int validos)
{
    int i=0;
    while(i<validos)
    {
        printf ("| %s |", arreglo[i]);
        printf("\n");
i++;
}
}


int determinarString (char arreglo[][columna], int validos){
    char palabra[20];
    int i = 0, j = 0, flag = 0;
printf("escriba la palabra que desea buscar: ");
fflush(stdin);
scanf("%s", &palabra);
for (i = 0; i<fila;i++){
    for (j = 0; j<columna; j++){
       if (strcmp(palabra, arreglo[i]) == 0) {
                printf("La palabra se encuentra en el arreglo.\n");
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            break;
        }
    }

    if (flag != 1) {
        printf("La palabra no se encuentra en el arreglo.\n");
        flag = -1;
    }

    return flag;
}
