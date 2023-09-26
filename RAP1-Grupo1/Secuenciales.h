#ifndef SECUENCIALES_H_INCLUDED
#define SECUENCIALES_H_INCLUDED
#include "Articulo.h"

//Recibo por parámetro una Lista de Artículos, el id del que busco, pos y resultado como variables globales, y la cantidad cargados
//pos es una variable que almacena la posición en la que encontramos el artículo
//resultado es una variable que almacena un booleano si logramos localizar o no el artículo
//typeEstructura es una variable que denota con que estructura estamos trabajando

void localizarSec(Articulo *arreglo, char *idBuscado, int *pos, int *rLocalizar, int cargados, int typeEstructura, int *cantConsultas){
    //Función strcmpi (No usamos strcmp porque es CaseSensitive)
    //0 si a = b
    //<0 si a < b
    //>0 si a > b
    *pos = 0; *rLocalizar = 0;
    int arregloDeCostos[MAX] = {0};

    if(cargados > 0){
        if(typeEstructura == 3){
            //typeEstructura == 3 significa que está usando LSO
            while (*pos<cargados && strcmpi(arreglo[*pos].codigo, idBuscado)<0){
                (*pos)++;
                (*cantConsultas)++;
            }

            if (*pos<cargados){
                (*cantConsultas)++;
            }

            if (*pos<cargados && strcmpi(arreglo[*pos].codigo, idBuscado)==0){
                *rLocalizar = 1; //Localizar exitoso
            } else {
                *rLocalizar = 0; // Localizar falla
            }

        } else if (typeEstructura == 4){
            //typeEstructura == 4 significa que está usando LSOBB
            // li inclusivo, ls exclusivo, segmento más grande a la izquierda, testigo a la derecha
            int li=0,ls=cargados;

            //pos es el testigo
            (*pos) = floor((li+ls+1)/2);

            while (li < ls - 1){

                if (strcmpi(arreglo[*pos].codigo, idBuscado) <= 0){
                    li = (*pos);
                } else {
                    ls = (*pos);
                }

                if(arregloDeCostos[*pos] == 0){
                    (*cantConsultas)++;
                    arregloDeCostos[*pos] = 1;
                }

            (*pos) = floor((li+ls+1)/2);
            //Reiteramos la consigna
            }

            if(arregloDeCostos[li] == 0){
                    (*cantConsultas)++;
                    arregloDeCostos[li] = 1;
            }
            //pos -1
            //Si es menor entonces devuelvo li, si es mayor devuelvo pos

            if(strcmpi(arreglo[li].codigo, idBuscado)>=0){
                (*pos)=li;
            }

            if (strcmpi(arreglo[li].codigo, idBuscado)==0){
                *rLocalizar = 1; // Localizar exitoso
            } else {
                *rLocalizar = 0; // Localizar fallido
            }

        }
    } else {
        *rLocalizar = 2; //No hay elementos en la lista
    }

}

void altaSec(Articulo *arreglo, int *cargados, int *rAlta, int typeEstructura, Articulo aux, int lecOp, float *costoMax, float *sumCostos, int *cantExitos){
    *rAlta = 0;
    int rLocalizar = 0, pos = 0, intBasura = 0;
    float sumAux = 0;

    if (*cargados < MAX){
           localizarSec(arreglo, aux.codigo, &pos, &rLocalizar, *cargados, typeEstructura, &intBasura);
            if(rLocalizar == 1){
                *rAlta = 0; //Como se encontró el elemento entonces el alta falla
            } else {

                //Corrimiento al pedo en caso de cargados = 0
                if(*cargados > 0){
                        //Revisar esto
                        for(int i=(*cargados); i>pos; i--){
                            arreglo[i] = arreglo [i-1];
                            if(lecOp == 1){
                                //1 porque significa que estamos evaluando costos
                                sumAux += 1.5;
                            }
                        }
                }

            arreglo[pos] = aux;
            (*cargados)++;

            if(lecOp == 1){
                *sumCostos += sumAux;
                if (sumAux > *costoMax){
                    *costoMax = sumAux;
                }
                (*cantExitos)++;
            }

            *rAlta = 1; //El alta fue exitosa
            }
        } else {
            *rAlta = 2; //El alta falla porque no hay más espacio en la estructura
    }
}

void bajaSec(Articulo *arreglo, int *cargados, int *rBaja, int typeEstructura, Articulo aux, int lecOp, float *costoMax, float *sumCostos, int *cantExitos){
    *rBaja = 0;
    int eleccion = 0, rLocalizar = 0, pos = 0, intBasura = 0;
    float sumAux = 0;

    localizarSec(arreglo, aux.codigo, &pos, &rLocalizar, *cargados, typeEstructura, &intBasura);

    if(rLocalizar == 1){
        if(lecOp == 0){
            //ESTAMOS EN ADMINISTRACIÓN
            printf("El articulo que quiere borrar es: \n");
            printArt(arreglo[pos]);

            do{
                printf("\n\n Esta seguro que quiere borrarlo? \n"
                       "<1> -------- Si --------\n"
                       "<2> -------- No --------\n");
                scanf("%d", &eleccion);
                getchar();
            } while (eleccion < 1 || eleccion > 2);
        } else {
            //ESTAMOS EN OPERACIONES
            if(strcmpi(arreglo[pos].tipoArt, aux.tipoArt)==0 && strcmpi(arreglo[pos].marca, aux.marca)==0 && strcmpi(arreglo[pos].desc, aux.desc)==0 && arreglo[pos].precio == aux.precio && arreglo[pos].cantidad == aux.cantidad){
                eleccion = 1;
            }
        }
        if (eleccion == 1){
            for(int i = pos; i < (*cargados - 1); i++){
                arreglo[i] = arreglo[i+1];
                if (lecOp == 1){
                    sumAux += 1.5;
                }
            }

            if(lecOp == 1){
                if(sumAux > *costoMax){
                    *costoMax = sumAux;
                }
                *sumCostos += sumAux;
                (*cantExitos)++;
            }

            *rBaja = 1; //Baja exitosa
            (*cargados)--;

        }

    } else {
        rBaja = 0; //La baja falla
    }
}

Articulo evocarSec(Articulo *arreglo, char *idBuscado, int cargados, int *rEvocar, int typeEstructura, int lecOp, int *costoMaxExito, int *sumCostosExito, int *cantExitos, int *costoMaxFracaso, int *sumCostosFracaso, int *cantFracasos){
    int rLocalizar = 0, pos = 0, cantConsultas = 0;
    Articulo aux;
    localizarSec(arreglo, idBuscado, &pos, &rLocalizar, cargados, typeEstructura, &cantConsultas);

    if (rLocalizar == 1){
        *rEvocar = 1;
        if(lecOp == 1){
            *sumCostosExito += cantConsultas;
            (*cantExitos)++;
            if(*costoMaxExito < cantConsultas){
                *costoMaxExito = cantConsultas;
            }
        }
        return arreglo[pos];
    } else {
        *rEvocar = 0;
        if(lecOp == 1){
            *sumCostosFracaso += cantConsultas;
            (*cantFracasos)++;
            if(*costoMaxFracaso < cantConsultas){
                *costoMaxFracaso = cantConsultas;
            }
        }
        return aux;
    }
}


#endif // SECUENCIALES_H_INCLUDED
