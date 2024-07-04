#include <iostream>
#include "rlutil.h"
#include "Dados.h"


using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                               ///GRAFICOS

/// DIBUJA DADO, CUADRADO
void DibujarDado(int pos1, int pos2){
    rlutil::setColor(rlutil::WHITE);
    for(int x=pos1; x<=pos1+6; x++){ /// 7 de ancho
        for(int y=pos2; y<=pos2+2; y++){ /// 3 de largo
            rlutil::locate(x,y);
            cout << (char) 219; /// rectangulo
              }
    }
    rlutil::resetColor();
}

/// PONE LOS PUNTITOS QUE DICE EL NUMERO DE DADO
void NumeroDado(int numero, int pos1, int pos2) {
    DibujarDado(pos1, pos2);
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

     switch(numero){
    case 1:
        rlutil::locate(pos1+3,pos2+1);
        cout << (char) 254;
    break;

    case 2:
        if(rand()%2){
        rlutil::locate(pos1+1,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+5,pos2+2);
        cout << (char) 223;
        }
        else{
        rlutil::locate(pos1+1,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+5,pos2);
        cout << (char) 220;
        }
        break;

     case 3:
        if(rand()%3){
        rlutil::locate(pos1+3,pos2+1);
        cout << (char) 254;
        rlutil::locate(pos1+1,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+5,pos2+2);
        cout << (char) 223;
        }
        else{
        rlutil::locate(pos1+1,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+5,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+3,pos2+1);
        cout << (char) 254;
        }
        break;

    case 4:
        rlutil::locate(pos1+1,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+1,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+5,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+5,pos2+2);
        cout << (char) 223;
        break;

    case 5:
        rlutil::locate(pos1+3,pos2+1);
        cout << (char) 254;
        rlutil::locate(pos1+1,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+1,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+5,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+5,pos2+2);
        cout << (char) 223;
        break;

    case 6:
        if(rand()%6){
        rlutil::locate(pos1+1,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+1,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+3,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+3,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+5,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+5,pos2+2);
        cout << (char) 223;
        }
        else{
        rlutil::locate(pos1+1,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+1,pos2+1);
        cout << (char) 254;
        rlutil::locate(pos1+1,pos2+2);
        cout << (char) 223;
        rlutil::locate(pos1+5,pos2);
        cout << (char) 220;
        rlutil::locate(pos1+5,pos2+1);
        cout << (char) 254;
        rlutil::locate(pos1+5,pos2+2);
        cout << (char) 223;
        }
        break;
    }
    rlutil::resetColor(); ///para que corte el color en el dado y no siga
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        ///LANZAMIENTOS


/// LANZAMIENTO DE DADOS
void tirarDados(int dados[]) {
    for (int i = 0; i < TAM_CANTIDAD_DADO; i++) {
        dados[i] = tirarDado();
    }
    PlaySound(TEXT("tirada.wav"), NULL, SND_FILENAME | SND_ASYNC);
    //getchar(); SI SE LO DEJA HAY QUE VOLVER A PRESIONAR PERO ES PARTE DEL CODIGO DEL SONIDO
    mostrarDados(dados); ///llama a mostrarDados, solo necesita sus valores y ya es constante (6)
}
/// SIMULA LANZAMIENTO DE DADOS PQ ES ALEATORIO CON RAND
int tirarDado() {
    return rand() % 6 + 1; ///tira dados +1 asi no toma el 0
}


/////////////////////////////////////////////////////////////////////////////////////
                  ///MUESTRA LOS DADOS DEPENDIENDO DEL LANZAMIENTO

/// MUESTRA LOS DADOS POR PANTALLA
void mostrarDados(int dados[]) {
    for (int i = 0; i < TAM_CANTIDAD_DADO; i++) {
        int y = rand() % 4 + 8; /// y aleatoria pero dentro de rango 4 a la derecha y 8 abajo asi se ve lo anterior
        int x = 15 + i * 10; /// x aleatoria pero centrandolo hacia  a la derecha y una division de 10 entre cada dado
        NumeroDado(dados[i], x, y); ///llamo funcion NumeroDado para mostrar la posicion x y definida en otra libreria
        rlutil::msleep(40); //simula la accion de tirar dados retardando el tiempo
    }
}


/*tirarDados(int dados[]){
for (int i=0; i < TAM_CANTIDAD_DADO; I++){
    int numero;
    cout << "INGRESE EL VALOR DEL DADO: " << endl;
    cin >> numero;

    dados[i] = numero;
}

*/
