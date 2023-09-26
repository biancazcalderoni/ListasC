#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <math.h>
#include "Secuenciales.h"
#include "Vinculadas.h"

/* GRUPO 1 - Santiago Politti Gil y Bianca Zoé Calderoni Alvarez

    LSO y LSOBB, al ser listas secuenciales ordenadas, trabajan dando de alta y de baja Artículos de forma ordenada, realizando
    corrimientos para dejar cada artículo en su lugar. La diferencia entre ambas estructuras radica al momento de evocar, ya que
    la búsqueda binaria trabaja descartando la mitad de los datos de la estructura en la que no hay posibilidad que se encuentre
    el elemento una y otra vez hasta llegar a una lista de tamaño 1; mientras que la LSO va consultando celda por celda hasta
    encontrar al elemento o uno mayor a éste. En definitiva, comparando ambas, siempre va a ser más conveniente la búsqueda binaria
    que la secuencial ordenada, ya que sus costos en altas y bajas son iguales pero difieren de manera considerable en sus costos
    al localizar.

    Ahora, hablando de las listas vinculadas, podemos decir que son estructuras muy eficientes en las altas y bajas, ya que estas
    presentan un costo constante. En cambio, cuando hablamos de las evocaciones, nos encontramos que la LVO trabaja de la misma
    forma que la LSO, ya que la forma de recorrer las listas es ir consultando celda por celda hasta dar con el elemento buscado
    o uno mayor. En cambio, la forma de recorrer una LVD buscando un elemento es consultar celda por celda revisando si el elemento
    contenido en ésta es el mismo hasta encontrarlo o llegar al final de la lista.

    La principal diferencia entre las listas vinculadas y las listas secuenciales se encuentra en los costos de altas y bajas:

    En las listas secuenciales van a variar sus costos dependiendo de qué tan grande sea el tamaño de sus listas, ya que analizamos
    la cantidad de corrimientos. Por consiguiente, tanto en las altas como en las bajas, los casos más costosos van a ser cuando
    demos un alta o una baja al inicio de la estructura, porque eso va a significar que tenemos que hacer más corrimientos en la
    lista.

    En cambio, en las listas vinculadas no tenemos que hacer ningún tipo de corrimiento, solo actualizaciones de punteros que son
    mucho menos costosas y poseen un costo constante, ya que podemos agregar en cualquier lugar redireccionando los punteros para
    ubicar el nuevo elemento en el lugar deseado (lo mismo pasa para las bajas).

    Ahora hablando del lote de Artículos que presenta el archivo de Operaciones.txt:

                            *****************************************************************************
                            *                          Comparacion de Estructuras                       *
                            *****************************************************************************
                            *   Costos                LVD      LVO      LSO      LSOBB                  *
                            *   ----------------------------------------------------------------------  *
                            *   MAX.ALTA              1.00     1.00     22.50    22.50                  *
                            *   MEDIO ALTA            1.00     1.00     5.44     5.44                   *
                            *   MAX.BAJA              0.50     0.50     81.00    81.00                  *
                            *   MEDIO BAJA            0.50     0.50     31.50    31.50                  *
                            *   MAX. EVOC. EX.        60       60       60       7                      *
                            *   MED. EVOC. EX.        24.15    24.49    24.49    5.38                   *
                            *   MAX. EVOC. NO EX.     18       7        7        6                      *
                            *   MED. EVOC. NO EX.     12.81    3.67     3.67     4.00                   *
                            *                                                                           *
                            *****************************************************************************

    Podemos ver, según los resultados, que las listas vinculadas van a ser listas extremadamente eficientes cuando lo que se quiere
    priorizar es dar altas y bajas. En contraparte, las listas secuenciales van a ser muy costosas para esta tarea debido a los
    corrimientos.

    Hablando sobre las evocaciones, en las listas ordenadas, por lo general, hay mayor eficiencia en función de la cantidad de celdas
    consultadas que en una lista desordenada. Esta diferencia se presenta más crítica a la hora de buscar un elemento que no se
    encuentra en la estructura, ya que, para una lista desordenada habría que recorrerla por completo, mientras que en una ordenada
    frenaría la ejecución al encontrar un elemento mayor.

    La diferencia en cuanto a costos entre las listas desordenadas y ordenadas va a depender de en qué orden los artículos sean
    ingresados y consultados. Ya que puede haber casos particulares en donde se inserten los elementos de manera desordenada y que
    la búsqueda también sea desordenada de la misma manera. Esto haría que los costos de las listas desordenadas puedan llegar a ser
    menores que las listas ordenadas en algunos casos. Por lo general, siempre va a convenir tener una lista ordenada de todas maneras,
    pero tener en claro que esos casos particulares pueden existir.

    En conclusión: si el uso principal de nuestro programa, además de eventualmente dar altas o bajas, es hacer consultas, la mejor
    estructura, por diferencia, es la LSOBB. Esto se debe a que es la única de las 4 estructuras que cambia su estrategia de búsqueda
    para hacerla más eficiente. Pero si nuestro programa hiciera énfasis en altas, bajas y consultas por igual, elegiríamos la LVO, ya
    que proporciona mucha eficiencia en altas y bajas, y una eficiencia decente en las búsquedas. No es tan buena con la LSOBB en
    consultas, pero posee un balance general en cuanto a las operaciones que tiene que realizar.

*/

int main()
{

        int typeEstructura = 0, decision = 0, codOperador=0, opciones = 0, cargadosLSO = 0, cargadosLSOBB = 0, rAlta = 0, rBaja = 0, rEvocar = 0, intBasura=0;
        float floatBasura;
        char codigoAux[9], tipoArtAux[21], marcaAux[31], descAux[101];
        Articulo aux, arregloLSO[MAX], arregloLSOBB[MAX];
        Lista listaLVD, listaLVO;

        inicializar(&listaLVD);
        inicializar(&listaLVO);

        //Le avisamos al usuario que puede salir en cualquier momento con 0
        printf("------------------------- ATENCION -------------------------\n"
               "En cualquier etapa del programa puede ingresar '0' para salir\n");
               system("pause");
               system("cls");


        do{
            do {
                printf("\n*****************************************************************************\n"
                       "*                               Opciones                                    *\n"
                       "*****************************************************************************\n"
                       "*                                                                           *\n"
                       "*   <0> Salir                                                               *\n"
                       "*   <1> Administrar Estructuras                                             *\n"
                       "*   <2> Comparar Estructuras                                                *\n"
                       "*                                                                           *\n"
                       "*****************************************************************************\n\n");
                scanf("%d", &opciones);
                getchar();
                system("cls");
            }while (opciones<0 || opciones >2);

            switch(opciones){
                case 0:{
                    break;
                }
                case 1:{
                     do{
                        do{
                            printf("\n*****************************************************************************\n"
                                   "*                      Con que estructura desea trabajar?                   *\n"
                                   "*****************************************************************************\n"
                                   "*                                                                           *\n"
                                   "*   <0> Salir                                                               *\n"
                                   "*   <1> Lista Vinculada Desordenada                                         *\n"
                                   "*   <2> Lista Vinculada Ordenada                                            *\n"
                                   "*   <3> Lista Secuencial Ordenada                                           *\n"
                                   "*   <4> Lista Secuencial Ordenada - Busqueda Binaria                        *\n"
                                   "*                                                                           *\n"
                                   "*****************************************************************************\n\n");
                            scanf("%d", &typeEstructura);
                            getchar();
                            system("cls");
                        } while (typeEstructura<0 || typeEstructura>4);

                        switch(typeEstructura){
                             default:{
                                 do {
                                    do {
                                        if(typeEstructura == 1){
                                            printf("\n~~~~~~~~ Usted esta trabajando con la LVD ~~~~~~~~\n\n");
                                        } else if (typeEstructura == 2){
                                            printf("\n~~~~~~~~ Usted esta trabajando con la LVO ~~~~~~~~\n\n");
                                        } else if (typeEstructura == 3){
                                            printf("\n~~~~~~~~ Usted esta trabajando con la LSO ~~~~~~~~\n\n");
                                        } else if (typeEstructura == 4){
                                            printf("\n~~~~~~~~ Usted esta trabajando con la LSOBB ~~~~~~~~\n\n");
                                        }
                                        printf("\n*************************************************************************\n"
                                               "*                           Que desea hacer?                            *\n"
                                               "*************************************************************************\n"
                                               "*                                                                       *\n"
                                               "*   <0> Salir                                                           *\n"
                                               "*   <1> Ingresar nuevo articulo                                         *\n"
                                               "*   <2> Eliminar articulo existente                                     *\n"
                                               "*   <3> Consultar un articulo                                           *\n"
                                               "*   <4> Mostrar estructura                                              *\n"
                                               "*   <5> Memorizacion previa                                             *\n"
                                               "*                                                                       *\n"
                                               "*************************************************************************\n\n");
                                        scanf("%d", &decision);
                                        getchar();
                                        system("cls");
                                    } while (decision<0 || decision>5);

                                    switch(decision){
                                        case 0:{
                                            break;
                                        }
                                        case 1:{
                                            //Pedir datos y meter en aux
                                            printf("\n ---------------------------------------------------------- \n");
                                            printf("Ingrese el codigo del articulo: \n");
                                            scanf("%[^\n]s", codigoAux);
                                            getchar();

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (strcmp(codigoAux, "0") == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            strcpy(aux.codigo,codigoAux);

                                            printf("Ingrese el tipo de articulo: \n");
                                            scanf("%[^\n]s", tipoArtAux);
                                            getchar();

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (strcmp(tipoArtAux, "0") == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            strcpy(aux.tipoArt,tipoArtAux);

                                            printf("Ingrese la marca: \n");
                                            scanf("%[^\n]s", marcaAux);
                                            getchar();

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (strcmp(marcaAux, "0") == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            strcpy(aux.marca,marcaAux);

                                            printf("Ingrese la descripcion del articulo: \n");
                                            scanf("%[^\n]s", descAux);
                                            getchar();

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (strcmp(descAux, "0") == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            strcpy(aux.desc,descAux);

                                            do{
                                                printf("Ingrese el precio del producto (No puede ser 0 ni menor): \n");
                                                scanf("%lf",&aux.precio);
                                            } while(aux.precio<0);

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (aux.precio == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            do{
                                                printf("Ingrese la cantidad de stock (No puede ser 0 ni menor) : \n");
                                                scanf("%d",&aux.cantidad);
                                            } while(aux.cantidad<0);

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (aux.cantidad == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }
                                            intBasura = 0;
                                            switch(typeEstructura){
                                                case 1:{
                                                    altaVin(&listaLVD, &rAlta, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                                case 2:{
                                                    altaVin(&listaLVO, &rAlta, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                                case 3:{
                                                    altaSec(arregloLSO, &cargadosLSO, &rAlta, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                                case 4:{
                                                    altaSec(arregloLSOBB, &cargadosLSOBB, &rAlta, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                            }

                                            if(rAlta == 1){
                                                printf("\n El alta ha sido exitosa \n");
                                            } else if (rAlta == 0){
                                                printf("\n El alta ha fallado porque el elemento ya se encuentra en la estructura \n");
                                            } else {
                                                printf("\n El alta ha fallado porque no hay espacio en la estructura \n");
                                            }
                                            break;

                                        }
                                        case 2:{
                                            //Eliminar
                                            printf("\n ---------------------------------------------------------- \n");
                                            printf("Ingrese el codigo del articulo a eliminar: \n");
                                            scanf("%[^\n]s", codigoAux);
                                            getchar();

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (strcmp(codigoAux, "0") == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            strcpy(aux.codigo,codigoAux);
                                            //Pedimos solo el código pero lo metemos en un Artículo Aux
                                            intBasura = 0;
                                            switch(typeEstructura){
                                                case 1:{
                                                    bajaVin(&listaLVD, &rBaja, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                                case 2:{
                                                    bajaVin(&listaLVO, &rBaja, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                                case 3:{
                                                    bajaSec(arregloLSO, &cargadosLSO, &rBaja, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                                case 4:{
                                                    bajaSec(arregloLSOBB, &cargadosLSOBB, &rBaja, typeEstructura, aux, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                    break;
                                                }
                                            }

                                            if(rBaja == 1){
                                                printf("\n La baja ha sido exitosa \n");
                                            } else if (rBaja == 0){
                                                printf("\n La baja ha fallado \n");
                                            }

                                            break;

                                        }
                                        case 3:{
                                            //Consultar
                                            printf("\n ---------------------------------------------------------- \n");
                                            printf("Ingrese el codigo del articulo a consultar: \n");
                                            scanf("%[^\n]s", codigoAux);
                                            getchar();

                                            // Si el usuario ingresa 0 sale de la ejecución
                                            if (strcmp(codigoAux, "0") == 0){
                                                printf("Se ha cancelado el alta ya que ha escrito '0' \n");
                                                break;
                                            }

                                            switch(typeEstructura){
                                                case 1:{
                                                    aux = evocarVin(&listaLVD, &rEvocar, typeEstructura, &codigoAux, intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura);
                                                    if(rEvocar == 1){
                                                        printf("Se econtro el articulo y es:\n");
                                                        printArt(aux);
                                                    } else {
                                                        printf("No se encontro el articulo\n");
                                                    }

                                                    break;
                                                }
                                                case 2:{
                                                    aux = evocarVin(&listaLVO, &rEvocar, typeEstructura, &codigoAux, intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura);
                                                    if(rEvocar == 1){
                                                        printf("Se econtro el articulo y es:\n");
                                                        printArt(aux);
                                                    } else {
                                                        printf("No se encontro el articulo\n");
                                                    }

                                                    break;
                                                }
                                                case 3:{
                                                    aux = evocarSec(arregloLSO, &codigoAux, cargadosLSO, &rEvocar, typeEstructura, intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura);
                                                    if(rEvocar == 1){
                                                        printf("Se econtro el articulo y es:\n");
                                                        printArt(aux);
                                                    } else {
                                                        printf("No se encontro el articulo\n");
                                                    }

                                                    break;
                                                }
                                                case 4:{
                                                    aux = evocarSec(arregloLSOBB, &codigoAux, cargadosLSOBB, &rEvocar, typeEstructura, intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura, &intBasura);
                                                    if(rEvocar == 1){
                                                        printf("Se econtro el articulo y es:\n");
                                                        printArt(aux);
                                                    } else {
                                                        printf("No se encontro el articulo\n");
                                                    }

                                                    break;
                                                }
                                                break;
                                            }
                                            break;
                                        }
                                        case 4:{
                                            switch (typeEstructura){
                                                case 1:{
                                                    reset(&listaLVD);
                                                    if(isEmpty(listaLVD)){
                                                        printf("La Lista Vinculada Desordenada se encuentra vacia \n\n");
                                                        system("pause");
                                                    }
                                                    while(isOos(listaLVD) != 1){
                                                        copiar(listaLVD, &aux);
                                                        printArt(aux);
                                                        avanzar(&listaLVD);
                                                        system("pause");
                                                    }
                                                    break;
                                                }
                                                case 2:{
                                                    reset(&listaLVO);
                                                    if(isEmpty(listaLVO)){
                                                        printf("La Lista Vinculada Ordenada se encuentra vacia \n\n");
                                                        system("pause");
                                                    }
                                                    while(isOos(listaLVO) != 1){
                                                        copiar(listaLVO, &aux);
                                                        printArt(aux);
                                                        avanzar(&listaLVO);
                                                        system("pause");
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    if(cargadosLSO == 0){
                                                        printf("La Lista Secuencial Ordenada se encuentra vacia \n\n");
                                                        system("pause");
                                                    }
                                                    for(int i=0; i<cargadosLSO; i++){
                                                        printArt(arregloLSO[i]);
                                                        system("pause");
                                                    }
                                                    break;
                                                }
                                                case 4: {
                                                    if(cargadosLSOBB == 0){
                                                        printf("La Lista Secuencial Ordenada con Busqueda Binaria se encuentra vacia \n\n");
                                                        system("pause");
                                                    }
                                                    for(int i=0; i<cargadosLSOBB; i++){
                                                        printArt(arregloLSOBB[i]);
                                                        system("pause");
                                                    }
                                                    break;
                                                }
                                                break;
                                            }
                                            break;
                                        }
                                        case 5:{
                                            FILE *fp;
                                            Articulo art;
                                            if ((fp = fopen("Articulos.txt","r"))== NULL){
                                                printf("No se puedo abrir el archivo\n");
                                                return 0;
                                            }
                                            if (ferror(fp)!=0) printf("Ocurrio un error en la lectura\n");
                                            else {
                                                while(!(feof(fp))){
                                                    fgets(art.codigo,10,fp);
                                                    art.codigo[strlen(art.codigo)-1] = '\0';
                                                    fgets(art.tipoArt,21,fp);
                                                    art.tipoArt[strlen(art.tipoArt)-1] = '\0';
                                                    fgets(art.marca,31,fp);
                                                    art.marca[strlen(art.marca)-1] = '\0';
                                                    fgets(art.desc,101,fp);
                                                    art.desc[strlen(art.desc)-1] = '\0';
                                                    fscanf(fp,"%lf",&art.precio);
                                                    fgetc(fp);
                                                    fscanf(fp,"%d",&art.cantidad);
                                                    fgetc(fp);

                                                    switch (typeEstructura){
                                                        case 1:{
                                                            altaVin(&listaLVD, &rAlta, typeEstructura, art, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                            break;
                                                        }
                                                        case 2:{
                                                            altaVin(&listaLVO, &rAlta, typeEstructura, art, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                            break;
                                                        }
                                                        case 3:{
                                                            altaSec(arregloLSO, &cargadosLSO, &rAlta, typeEstructura, art, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                            break;
                                                        }
                                                        case 4:{
                                                            altaSec(arregloLSOBB, &cargadosLSOBB, &rAlta, typeEstructura, art, intBasura, &floatBasura, &floatBasura, &intBasura);
                                                            break;
                                                        }
                                                        break;
                                                    }

                                                }

                                                printf("Se cargaron correctamente todos los articulos \n\n");
                                            fclose(fp);
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                 } while (decision != 0);
                                 break;
                            }
                            case 0:{
                                break;
                            }
                            break;
                        }
                     } while (typeEstructura != 0);
                     break;
                }
                case 2:{
                    vaciarLista(&listaLVD);
                    vaciarLista(&listaLVO);
                    cargadosLSO=0;
                    cargadosLSOBB=0;
                                //Costos Alta LSO
                                float costoMaxAltaLSO=0, sumCostosAltaLSO=0, costoMedioAltaLSO=0;
                                int cantExitosAltaLSO=0;

                                //Costos Baja LSO
                                float costoMaxBajaLSO=0, sumCostosBajaLSO=0, costoMedioBajaLSO=0;
                                int cantExitosBajaLSO=0;

                                //costos EvocarLSO Exito
                                float costoMedioEvoExitoLSO=0;
                                int costoMaxEvoExitoLSO=0, sumCostosEvoExitoLSO=0, cantExitosEvoLSO=0;

                                //costos EvocarLSO Fracaso
                                float costoMedioEvoFracasoLSO=0;
                                int costoMaxEvoFracasoLSO=0, sumCostosEvoFracasoLSO=0, cantFracasosEvoLSO=0;

                                //Costos Alta LSOBB
                                float costoMaxAltaLSOBB=0, sumCostosAltaLSOBB=0, costoMedioAltaLSOBB=0;
                                int cantExitosAltaLSOBB=0;

                                //Costos Baja LSOBB
                                float costoMaxBajaLSOBB=0, sumCostosBajaLSOBB=0, costoMedioBajaLSOBB=0;
                                int cantExitosBajaLSOBB=0;

                                //costos EvocarLSOBB Exito
                                float costoMedioEvoExitoLSOBB=0;
                                int costoMaxEvoExitoLSOBB=0, sumCostosEvoExitoLSOBB=0, cantExitosEvoLSOBB=0;

                                //costos EvocarLSOBB Fracaso
                                float costoMedioEvoFracasoLSOBB=0;
                                int costoMaxEvoFracasoLSOBB=0, sumCostosEvoFracasoLSOBB=0, cantFracasosEvoLSOBB=0;

                                //Costos Alta LVD
                                float costoMaxAltaLVD=0, sumCostosAltaLVD=0, costoMedioAltaLVD=0;
                                int cantExitosAltaLVD=0;

                                //Costos Baja LVD
                                float costoMaxBajaLVD=0, sumCostosBajaLVD=0, costoMedioBajaLVD=0;
                                int cantExitosBajaLVD=0;

                                //costos EvocarLVD Exito
                                float costoMedioEvoExitoLVD=0;
                                int costoMaxEvoExitoLVD=0, sumCostosEvoExitoLVD=0, cantExitosEvoLVD=0;

                                //costos EvocarLVD Fracaso
                                float costoMedioEvoFracasoLVD=0;
                                int costoMaxEvoFracasoLVD=0, sumCostosEvoFracasoLVD=0, cantFracasosEvoLVD=0;

                                //Costos Alta LVO
                                float costoMaxAltaLVO=0, sumCostosAltaLVO=0, costoMedioAltaLVO=0;
                                int cantExitosAltaLVO=0;

                                //Costos Baja LVO
                                float costoMaxBajaLVO=0, sumCostosBajaLVO=0, costoMedioBajaLVO=0;
                                int cantExitosBajaLVO=0;

                                //costos EvocarLVO Exito
                                float costoMedioEvoExitoLVO=0;
                                int costoMaxEvoExitoLVO=0, sumCostosEvoExitoLVO=0, cantExitosEvoLVO=0;

                                //costos EvocarLVO Fracaso
                                float costoMedioEvoFracasoLVO=0;
                                int costoMaxEvoFracasoLVO=0, sumCostosEvoFracasoLVO=0, cantFracasosEvoLVO=0;

                                FILE *fp;
                                Articulo art;
                                if ((fp = fopen("Operaciones.txt","r"))== NULL){
                                    printf("No se puedo abrir el archivo\n");
                                    return 0;
                                }

                                if (ferror(fp)!=0) printf("Ocurrio un error en la lectura\n");
                                    else {
                                        while(!(feof(fp))){
                                            fscanf(fp, "%d", &codOperador);
                                            fgetc(fp);
                                            fscanf(fp, "%[^\n]", &art.codigo);
                                            fgetc(fp);

                                            if(codOperador == 1 || codOperador == 2){
                                                fgets(art.tipoArt,21,fp);
                                                art.tipoArt[strlen(art.tipoArt)-1] = '\0';
                                                fgets(art.marca,31,fp);
                                                art.marca[strlen(art.marca)-1] = '\0';
                                                fgets(art.desc,101,fp);
                                                art.desc[strlen(art.desc)-1] = '\0';
                                                fscanf(fp,"%lf",&art.precio);
                                                fgetc(fp);
                                                fscanf(fp,"%d",&art.cantidad);
                                                fgetc(fp);

                                                if(codOperador == 1){
                                                    altaVin(&listaLVD, &rAlta, 1, art, 1, &costoMaxAltaLVD, &sumCostosAltaLVD, &cantExitosAltaLVD);
                                                    altaVin(&listaLVO, &rAlta, 2, art, 1, &costoMaxAltaLVO, &sumCostosAltaLVO, &cantExitosAltaLVO);
                                                    altaSec(arregloLSO, &cargadosLSO, &rAlta, 3, art, 1, &costoMaxAltaLSO, &sumCostosAltaLSO, &cantExitosAltaLSO);
                                                    altaSec(arregloLSOBB, &cargadosLSOBB, &rAlta, 4, art, 1, &costoMaxAltaLSOBB, &sumCostosAltaLSOBB, &cantExitosAltaLSOBB);
                                                } else if (codOperador == 2) {
                                                    bajaVin(&listaLVD, &rAlta, 1, art, 1, &costoMaxBajaLVD, &sumCostosBajaLVD, &cantExitosBajaLVD);
                                                    bajaVin(&listaLVO, &rAlta, 2, art, 1, &costoMaxBajaLVO, &sumCostosBajaLVO, &cantExitosBajaLVO);
                                                    bajaSec(arregloLSO, &cargadosLSO, &rAlta, 3, art, 1, &costoMaxBajaLSO, &sumCostosBajaLSO, &cantExitosBajaLSO);
                                                    bajaSec(arregloLSOBB, &cargadosLSOBB, &rAlta, 4, art, 1, &costoMaxBajaLSOBB, &sumCostosBajaLSOBB, &cantExitosBajaLSOBB);
                                                }
                                            } else if (codOperador == 3){
                                                evocarVin(&listaLVD, &rEvocar, 1, art.codigo, 1, &costoMaxEvoExitoLVD, &sumCostosEvoExitoLVD, &cantExitosEvoLVD, &costoMaxEvoFracasoLVD, &sumCostosEvoFracasoLVD, &cantFracasosEvoLVD);
                                                evocarVin(&listaLVO, &rEvocar, 2, art.codigo, 1, &costoMaxEvoExitoLVO, &sumCostosEvoExitoLVO, &cantExitosEvoLVO, &costoMaxEvoFracasoLVO, &sumCostosEvoFracasoLVO, &cantFracasosEvoLVO);
                                                evocarSec(arregloLSO, art.codigo, cargadosLSO, &rEvocar, 3, 1, &costoMaxEvoExitoLSO, &sumCostosEvoExitoLSO, &cantExitosEvoLSO, &costoMaxEvoFracasoLSO, &sumCostosEvoFracasoLSO, &cantFracasosEvoLSO);
                                                evocarSec(arregloLSOBB, art.codigo, cargadosLSOBB, &rEvocar, 4, 1, &costoMaxEvoExitoLSOBB, &sumCostosEvoExitoLSOBB, &cantExitosEvoLSOBB, &costoMaxEvoFracasoLSOBB, &sumCostosEvoFracasoLSOBB, &cantFracasosEvoLSOBB);
                                            } else {
                                                printf("Error, el codigo de operacion no fue reconocido\n");
                                            }

                                            codOperador = 0;

                                        }

                                    printf("Se cargaron correctamente todos los articulos \n\n");
                                    fclose(fp);
                                    }

                                    //COSTO MEDIO DE ALTAS

                                    costoMedioAltaLSO = sumCostosAltaLSO / cantExitosAltaLSO;
                                    costoMedioAltaLSOBB = sumCostosAltaLSOBB / cantExitosAltaLSOBB;
                                    costoMedioAltaLVD = sumCostosAltaLVD / cantExitosAltaLVD;
                                    costoMedioAltaLVO = sumCostosAltaLVO / cantExitosAltaLVO;

                                    //COSTO MEDIO DE BAJAS

                                    costoMedioBajaLSO = sumCostosBajaLSO / cantExitosBajaLSO;
                                    costoMedioBajaLSOBB = sumCostosBajaLSOBB / cantExitosBajaLSOBB;
                                    costoMedioBajaLVD = sumCostosBajaLVD / cantExitosBajaLVD;
                                    costoMedioBajaLVO = sumCostosBajaLVO / cantExitosBajaLVO;

                                    //COSTO MEDIO DE EVOCAR EXITO

                                    costoMedioEvoExitoLSO = sumCostosEvoExitoLSO *1.0/ cantExitosEvoLSO;
                                    costoMedioEvoExitoLSOBB = sumCostosEvoExitoLSOBB *1.0/ cantExitosEvoLSOBB;
                                    costoMedioEvoExitoLVD = sumCostosEvoExitoLVD *1.0/ cantExitosEvoLVD;
                                    costoMedioEvoExitoLVO = sumCostosEvoExitoLVO *1.0/ cantExitosEvoLVO;

                                    //COSTO MEDIO DE EVOCAR FRACASO

                                    costoMedioEvoFracasoLSO = sumCostosEvoFracasoLSO *1.0/ cantFracasosEvoLSO;
                                    costoMedioEvoFracasoLSOBB = sumCostosEvoFracasoLSOBB *1.0/ cantFracasosEvoLSOBB;
                                    costoMedioEvoFracasoLVD = sumCostosEvoFracasoLVD *1.0/ cantFracasosEvoLVD;
                                    costoMedioEvoFracasoLVO = sumCostosEvoFracasoLVO *1.0/ cantFracasosEvoLVO;

                            printf("\n*****************************************************************************\n"
                                   "*                          Comparacion de Estructuras                       *\n"
                                   "*****************************************************************************\n"
                                   "*   Costos                LVD      LVO      LSO      LSOBB                  *\n"
                                   "*   ----------------------------------------------------------------------  *\n");
                            printf("*   MAX.ALTA              %.2f     %.2f     %.2f    %.2f                  *\n", costoMaxAltaLVD, costoMaxAltaLVO, costoMaxAltaLSO, costoMaxAltaLSOBB);
                            printf("*   MEDIO ALTA            %.2f     %.2f     %.2f     %.2f                   *\n", costoMedioAltaLVD, costoMedioAltaLVO, costoMedioAltaLSO, costoMedioAltaLSOBB);
                            printf("*   MAX.BAJA              %.2f     %.2f     %.2f    %.2f                  *\n", costoMaxBajaLVD, costoMaxBajaLVO, costoMaxBajaLSO, costoMaxBajaLSOBB);
                            printf("*   MEDIO BAJA            %.2f     %.2f     %.2f    %.2f                  *\n", costoMedioBajaLVD, costoMedioBajaLVO, costoMedioBajaLSO, costoMedioBajaLSOBB);
                            printf("*   MAX. EVOC. EX.        %d       %d       %d       %d                      *\n", costoMaxEvoExitoLVD, costoMaxEvoExitoLVO, costoMaxEvoExitoLSO, costoMaxEvoExitoLSOBB);
                            printf("*   MED. EVOC. EX.        %.2f    %.2f    %.2f    %.2f                   *\n", costoMedioEvoExitoLVD, costoMedioEvoExitoLVO, costoMedioEvoExitoLSO, costoMedioEvoExitoLSOBB);
                            printf("*   MAX. EVOC. NO EX.     %d       %d        %d        %d                      *\n", costoMaxEvoFracasoLVD, costoMaxEvoFracasoLVO, costoMaxEvoFracasoLSO, costoMaxEvoFracasoLSOBB);
                            printf("*   MED. EVOC. NO EX.     %.2f    %.2f     %.2f     %.2f                   *\n", costoMedioEvoFracasoLVD, costoMedioEvoFracasoLVO, costoMedioEvoFracasoLSO, costoMedioEvoFracasoLSOBB);
                            printf("*                                                                           *\n"
                                   "*****************************************************************************\n\n");
                    break;
                }
                break;
            }
        } while (opciones != 0);

        printf("\n      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                 "      |                                                   |\n"
                 "      |    Muchas gracias por utilizar nuestro programa   |\n"
                 "      |                                                   |\n"
                 "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        return 0;
}
