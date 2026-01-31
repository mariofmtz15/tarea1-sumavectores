#include <iostream>
#include <omp.h>

#define N 50
#define chunk 5
#define mostrar 20

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando arreglos en paralelo \n";

    // Creando arreglos
    float a[N], b[N], c[N];
    int i;
    
    // Generación de numeros para asignar a los arreglos
    for(i = 0; i < N; i++){
        a[i] = i * 10;
        b[i] = (i + 3) * 2 + 8 * 5;
    }
    
    int pedazos = chunk;
    
    // Usando OpenMP para usar programación en paralelo
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    
    // Haciendo la suma
    for (i = 0; i < N; i++){
        c[i] = a[i] + b[i];
    }
    
    // Imprimiendo arreglos
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);
    
    
    
}

// Método auxiliar para imprimir arreglos
void imprimeArreglo(float *d){
    for(int i = 0; i < mostrar; i++){
        std::cout << d[i] << " - ";
    }
    std::cout << std::endl;
}


