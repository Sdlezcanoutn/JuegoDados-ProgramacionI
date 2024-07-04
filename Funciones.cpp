#include <iostream>
#include "Funciones.h"
#include "Dados.h"
#include "rlutil.h"
#include <cstdlib>
#include <ctime>

using namespace std;


////////////////////////////////////////////////////////////////// MODO UN JUGADOR //////////////////////////////////////////////////////////////////////
void juegoUnJugador() {
    rlutil::hidecursor(); ///OCULTA EL CURSOR
    rlutil::saveDefaultColor(); ///GUARDA EL COLOR PREDETERMINADO

    string nombre;
    cout << "                                                                    --- JUEGO UN JUGADOR ---                                                                   " << endl << endl;
    cout << "Ingrese el nombre del jugador: ";
    getline(cin, nombre); // uso de string, luego se ignora asi hace el corte entre este getline con el que sigue de while


    while (nombre == "") {/// CHEQUEA QUE EL NOMBRE NO ESTE VACIO
        cout << "Por favor ingrese un nombre: ";
        getline(cin, nombre);

}
    int puntajeTotal = 0; /// INICIO DE PUNTAJES
    int ronda = 0; ///INICIO DE RONDA
    //PRUEBA
    int dados[TAM_CANTIDAD_DADO];


    ///PRUEBAAAAAAAAAAAA
    int puntuacionMaxima = 0;
    string nombreMaximaPuntuacion;


/// SI SE LLEGA A 100 GANA (PRINCIPAL)
while (puntajeTotal < 100) {
        int maxPuntajeRonda = 0; /// INICIA MAX PUNTAJE
        ronda++; /// SUMA LAS RONDAS
        rlutil::cls();

        cout << "" << endl;
        cout << " ----------------------------------------------------------- INICIO RONDA N: " << ronda << " | PUNTAJE ACUMULADO: " << puntajeTotal << " -----------------------------------------------------" << endl;
        cout << "" << endl << endl;

        /// TRES LANZAMIENTOS POR RONDA
        for (int i = 1; i <= 3; ++i) {
            rlutil::locate(45,20);
            cout << "Presione una tecla para comenzar con la tirada NUMERO " << i << " de la ronda actual...";
            rlutil::anykey();
            rlutil::cls();
            cout << endl << endl;

            cout << "                                            TURNO DE " << nombre << " | RONDA NUMERO " << ronda << " | PUNTAJE MAXIMO DE RONDA ACTUAL: " << maxPuntajeRonda << " PUNTOS." << endl << endl << endl;

            cout << "LANZAMIENTO NUMERO " << i << ": " << endl;
            int puntajeLanzamiento = calcularPuntaje(dados);

            rlutil::locate(1, 17); ///POSICION PARA QUE SE VEA
            cout << "PUNTAJE: " << puntajeLanzamiento << endl << endl;

            /// ACA SE CONSULTAN LOS DADOS PARA DAR PUNTOS
            if (puntajeLanzamiento == 100) {
                cout << "SUMASTE 100 PUNTOS Y GANASTE LA PARTIDA POR HABER OBTENIDO UNA ESCALERA." << endl;
                i = 4; ///SALIDA
            } else if (puntajeLanzamiento == 0) {
                puntajeTotal = 0;
                cout << "SACASTE SEXTETO DE 6 Y POR ESO TU PUNTAJE VUELVE A 0." << endl;
            }
            if (puntajeLanzamiento > maxPuntajeRonda) {
                maxPuntajeRonda = puntajeLanzamiento; // Actualizo puntos de mejor tirada.
            }

            if (puntajeTotal + puntajeLanzamiento >= 100) {
                puntajeTotal += puntajeLanzamiento;
                i = 4; ///PARA SALIR PORQUE I TIENE QUE IR HASTA 3 POR SUS LANZAMIENTOS
            }

            if (i == 3) {
                puntajeTotal += maxPuntajeRonda;
                cout << "MAXIMO PUNTAJE OBTENIDO DE LA RONDA: " << maxPuntajeRonda << endl;
                cout << "PUNTAJE TOTAL DE PARTIDA: " << puntajeTotal << endl << endl;
                rlutil::locate(60,25);
                cout << "Presione una tecla para pasar a la ronda NUMERO " << ronda + 1;
                rlutil::anykey();
            }
        }

        cout << "PUNTAJE TOTAL RONDA ACTUAL: " << maxPuntajeRonda << " | PUNTAJE TOTAL: " << puntajeTotal << endl << endl;
if (puntajeTotal >= 100) { ///define ganador
        PlaySound(TEXT("victoria.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << nombre << " GANO LA PARTIDA CON " << puntajeTotal << " PUNTOS EN " << ronda << " RONDAS." << endl;


            ///PARTE DE PRUEBAAAAAAAAAAAAAAAAA
           if (puntajeTotal > puntuacionMaxima)
            {
                puntuacionMaxima = puntajeTotal; // Si es mayor a la puntuacion maxima, lo actualizo con el nuevo puntaje final.
                nombreMaximaPuntuacion = nombre; // Actualizo nombre.
                rlutil::locate(46,26);
                cout << "PUNTUACION MAXIMA DEL JUEGO: " << " [ " << puntuacionMaxima << " ] " << " Y LO REALIZO: " << " [ " << nombreMaximaPuntuacion << " ] " << endl;
            }
        }
    }
    rlutil::locate(1,40);
    cout << " Presione una tecla para volver a menu principal...";
    rlutil::anykey();
    rlutil::cls();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// JUEGO DOS JUGADORES /////////////////////////////////////////////////

void juegoDosJugadores() {
    rlutil::hidecursor(); // OCULTA EL CURSOR
    rlutil::saveDefaultColor(); // GUARDA EL COLOR PREDETERMINADO

    string nombre1, nombre2;
    cout << "INGRESE EL NOMBRE DEL JUGADOR 1: ";
    getline(cin, nombre1);
    while (nombre1 == "") { // CHEQUEA QUE EL NOMBRE NO ESTE VACIO
        cout << "Por favor ingrese un nombre: ";
        getline(cin, nombre1);
    }

    cout << endl << "INGRESE EL NOMBRE DEL JUGADOR 2: ";
    getline(cin, nombre2);
    while (nombre2 == "") { // CHEQUEA QUE EL NOMBRE NO ESTE VACIO
        cout << "Por favor ingrese un nombre: ";
        getline(cin, nombre2);
    }

    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    int ronda = 0;
    int dados[TAM_CANTIDAD_DADO];
    bool rondaTerminada = false; /// BANDERA PARA FINALIZAR LAS RONDAS POR MAS QUE SE HAYA LLEGADO AL OBJETIVO
    int tiradasJugador1 = 0, tiradasJugador2 = 0; ///INICIO EN 0 (SON 3 TIRADAS)

    while (!rondaTerminada) { ///USO DE BANDERA
        ronda++;
        int maxPuntajeRonda1 = 0; ///INICIO DE 0 PARA LUEGO MODIFICAR
        int maxPuntajeRonda2 = 0;

        rlutil::cls();
        rlutil::locate(50, 1);
        cout << "-----------------------------------------------------------" << endl;
        rlutil::locate(69, 2);
        cout << "RONDA N: " << ronda << " | PUNTAJES ACUMULADOS:" << endl;
        rlutil::locate(73, 3);
        cout << nombre1 << ": " << puntajeJugador1 << " | " << nombre2 << ": " << puntajeJugador2 << endl;
        rlutil::locate(50, 4);
        cout << "-----------------------------------------------------------" << endl << endl;

        // Turno del Jugador 1
        for (int i = 1; i <= 3; ++i) { ///CANT TIRADAS
            tiradasJugador1++; ///ACA YA SUMA PARA SEGUIR CON LA TIRADA SIGUENTE
            rlutil::locate(45, 30);
            cout << "Presione una tecla para que " << nombre1 << " comience con la tirada NUMERO " << i << " de la ronda actual...";
            rlutil::anykey();
            rlutil::cls();
            cout << endl << endl;

            cout << "                                            TURNO DE " << nombre1 << " | RONDA NUMERO " << ronda << " | PUNTAJE MAXIMO DE RONDA ACTUAL: " << maxPuntajeRonda1 << " PUNTOS." << endl << endl << endl;
            cout << "LANZAMIENTO NUMERO " << i << ": " << endl;
            int puntajeLanzamiento = calcularPuntaje(dados); ///FUNCION PUNTAJEL ES IGUAL AL CALCULO DE LOS DADOS

            rlutil::locate(1, 17); // POSICION PARA QUE SE VEA
            cout << "PUNTAJE: " << puntajeLanzamiento << endl << endl;
            if (puntajeLanzamiento == 100) { ///COMO EL CALCULO PUNTAJE YA HIZO SU FUNCION, ACA PREGUNTAMOS SI FUE IGUAL A 100 ASI YA SE DEFINE GANADOR
                cout << "SUMASTE 100 PUNTOS Y GANASTE LA PARTIDA POR HABER OBTENIDO UNA ESCALERA." << endl;
                puntajeJugador1 += 100;
                break;
            } else if (puntajeLanzamiento == 0) { ///SI ES 0 REPENTINAMENTE ES PORQUE SACO 6 DE 6
                puntajeJugador1 = 0;
                cout << "SACASTE SEXTETO DE 6 Y POR ESO TU PUNTAJE VUELVE A 0." << endl;
                break;
            }///CONSULTA SI EL LANZAMIENTO ACTUAL ES MAYOR AL MAX
            if (puntajeLanzamiento > maxPuntajeRonda1) { ///SI ES ASI MAX Y LANZAMIENTO
                maxPuntajeRonda1 = puntajeLanzamiento;
            }

            if (i == 3) { ///I DE 3 TIRADAS
                puntajeJugador1 += maxPuntajeRonda1; ///ACUMULA LO MEJOR DE LAS 3 TIRADAS
                cout << "MAXIMO PUNTAJE OBTENIDO DE LA RONDA: " << maxPuntajeRonda1 << endl;
                cout << "PUNTAJE TOTAL DE PARTIDA: " << puntajeJugador1 << endl << endl;
                rlutil::locate(60, 25);
                cout << "Presione una tecla para pasar a la tirada del Jugador 2...";
                rlutil::anykey();
                rlutil::cls();
            }
        }

        // Turno del Jugador 2
        for (int i = 1; i <= 3; ++i) {
            tiradasJugador2++;
            rlutil::locate(45, 20);
            cout << "Presione una tecla para que " << nombre2 << " comience con la tirada NUMERO " << i << " de la ronda actual...";
            rlutil::anykey();
            rlutil::cls();
            cout << endl << endl;

            cout << "                                            TURNO DE " << nombre2 << " | RONDA NUMERO " << ronda << " | PUNTAJE MAXIMO DE RONDA ACTUAL: " << maxPuntajeRonda2 << " PUNTOS." << endl << endl << endl;
            cout << "LANZAMIENTO NUMERO " << i << ": " << endl;
            int puntajeLanzamiento = calcularPuntaje(dados);

            rlutil::locate(1, 17); // POSICION PARA QUE SE VEA
            cout << "PUNTAJE: " << puntajeLanzamiento << endl << endl;
            if (puntajeLanzamiento == 100) {
                cout << "SUMASTE 100 PUNTOS Y GANASTE LA PARTIDA POR HABER OBTENIDO UNA ESCALERA." << endl;
                puntajeJugador2 += 100;
                break;
            } else if (puntajeLanzamiento == 0) {
                puntajeJugador2 = 0;
                cout << "SACASTE SEXTETO DE 6 Y POR ESO TU PUNTAJE VUELVE A 0." << endl;
                break;
            }
            if (puntajeLanzamiento > maxPuntajeRonda2) {
                maxPuntajeRonda2 = puntajeLanzamiento;
            }

            if (i == 3) {
                puntajeJugador2 += maxPuntajeRonda2;
                cout << "MAXIMO PUNTAJE OBTENIDO DE LA RONDA: " << maxPuntajeRonda2 << endl;
                cout << "PUNTAJE TOTAL DE PARTIDA: " << puntajeJugador2 << endl << endl;
                rlutil::locate(60, 25);
                cout << "Presione una tecla para pasar a la siguiente ronda...";
                rlutil::anykey();
            }
        }

        if (puntajeJugador1 >= 100 || puntajeJugador2 >= 100) {
            rondaTerminada = true;
        }
    }

    // MUESTRA cartel final con el ganador y los puntajes
    rlutil::cls();
    rlutil::locate(50, 15);
    if (puntajeJugador1 == puntajeJugador2) { ///SI SON IGUALES LOS PUNTAJES
        cout << "¡EMPATE! Ambos jugadores tienen los mismos puntos." << endl;
        cout << "Desempate por menor cantidad de tiradas." << endl;
        if (tiradasJugador1 < tiradasJugador2) { // esto me parece que no, fue probar
            rlutil::locate(65,11);
            PlaySound(TEXT("victoria.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "¡" << nombre1 << " GANO LA PARTIDA!" << endl;
            rlutil::locate(57,13);
            cout << "Le llevo " << tiradasJugador1 << " tiradas para alcanzar el puntaje máximo." << endl;
        } else {
            rlutil::locate(65,11);
            PlaySound(TEXT("victoria.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "¡" << nombre2 << " GANO LA PARTIDA!" << endl;
            rlutil::locate(57,13);
            cout << "Le llevo " << tiradasJugador2 << " tiradas para alcanzar el puntaje máximo." << endl;
        }
    } else if (puntajeJugador1 > puntajeJugador2) {
        rlutil::locate(65,11);
        PlaySound(TEXT("victoria.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "¡" << nombre1 << " GANO LA PARTIDA!" << endl;
        rlutil::locate(57,13);
        cout << "Le llevo " << ronda << " rondas para ganar la partida." << endl;
    } else if (puntajeJugador2 > puntajeJugador1) {
        rlutil::locate(65,11);
        PlaySound(TEXT("victoria.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "¡" << nombre2 << " GANO LA PARTIDA!" << endl;
        rlutil::locate(57,13);
        cout << "Le llevo " << ronda << " rondas para ganar la partida." << endl;
    }

    cout << "PUNTAJE FINAL: " << endl;
    cout << nombre1 << ": " << puntajeJugador1 << " puntos" << endl;
    cout << nombre2 << ": " << puntajeJugador2 << " puntos" << endl;

    rlutil::locate(1, 40);
    cout << "Presione una tecla para volver a menu principal...";
    rlutil::anykey();
    rlutil::cls();
}

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                            ///CALCULADORA

/// CALCULAR PUNTAJE DE LOS NUMEROS DADOS
int calcularPuntaje(int dados[]) {
    int puntos = 0;
    tirarDados(dados);

    int cont = 0;
    for (int i = 0; i < TAM_CANTIDAD_DADO; i++) { ///Recorre cada dado
        for (int x = 0; x < TAM_CANTIDAD_DADO; x++) { ///Recorre nuevamente para compararlo con el dado actual
            if (dados[i] == dados[x]) { /// Compara, si son iguales incrementa "CONT"
                cont++;
            }
        }
    } //4 IF POR 3 CASOS Y SI NINUNO SE DA SE SUMA LO OBTENIDO
    /// SI SE OBTUVO ESCALERA...
    if (cont == 6) {
        rlutil::locate(40,15); /// para que se vea abajo de los dados
        cout << "¡ESCALERA!" << endl << endl;
        puntos = 100;
    }

/// SEIS NUMEROS IGUALES, SE MULTIPLICA POR 10 EL NUMERO DEL DADO
    if (cont == 36 && dados[0] != 6) {
        puntos = dados[0] * 10;
        rlutil::locate(1,16);
        cout << "SEXTETO DE " << dados[0] << endl << endl;
    }
    /// SEIS 6, SE VUELVE A 0
    if (cont == 36 && dados[0] == 6) { /// 36 PQ TODOS LOS DADOS TIENEN LOS MISMO N°, SE COMPARAN DANDO QUE COINCIDAN 6 VECES (6*6 = 36)
        rlutil::locate(60,15);
        cout << "SEXTETO DE 6" << endl << endl;
        puntos = 0;
    }
    /// SUMA LOS PUNTOS DE AMBOS PQ LO ANTERIOR NO SE CUMPLIO
    if (cont != 6 && cont != 36) {
        for (int i = 0; i < TAM_CANTIDAD_DADO; i++) {
            puntos += dados[i]; //acumula en vecDados
        }
    }
    return puntos;
}

