#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED
#define MAX 350

typedef struct{
    char codigo[9]; // Uno m�s porque /s ocupa espacio
    char tipoArt[21];
    char marca [31];
    char desc [101];
    double precio;
    int cantidad;
} Articulo;

void printArt(Articulo aux){
    printf("\nCodigo: %s\n", aux.codigo);
    printf("Tipo de Articulo: %s\n", aux.tipoArt);
    printf("Marca: %s\n", aux.marca);
    printf("Descripcion: %s\n", aux.desc);
    printf("Precio: %f\n", aux.precio);
    printf("Cantidad disponible: %d\n", aux.cantidad);
}

#endif // ARTICULO_H_INCLUDED
