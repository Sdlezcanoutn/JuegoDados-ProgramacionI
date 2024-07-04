#include <iostream>
#include "Menu.h"
#include "rlutil.h"
#include "Dados.h"
#include "Funciones.h"

using namespace std;


void Menu(){ ///FUNCION MENU
    int opcion;

    do { /// MUENU PRINCIPAL ///
       PlaySound(TEXT("waiting.wav"), NULL, SND_FILENAME | SND_ASYNC);
        cout << "************************************************************************************************************************************************************************************************************************ BIENVENIDO/OS A CIEN O ESCALERA ***************************************************************************************************************************************************************************************************************************" << endl;
        rlutil::anykey(); /// PARA PRESIONAR TECLA Y CONTINUAR (system("pause>nul"))
        rlutil::cls(); /// LIMPIA LA PANTALLA (system("cls"))
        cout << "                                                                   ---------- MENU ----------                                                                  " << endl << endl;
        cout << "Ingrese una opcion: " << endl;
        cout << "1. MODO 1 JUGADOR" << endl;
        cout << "2. MODO 2 JUGADORES" << endl;
        cout << "3. RANKING" << endl;
        cout << "4. SALIR" << endl << endl;

        cin >> opcion;
       cin.ignore(); // Para que el Enter del cin anterior no quede en el buffer y no lo tome el getline posterior. /// EVITA PROBLEMAS CON LAS ENTRADAS POST

                switch (opcion) {
        case 1:
            rlutil::cls(); /// LIMPIA LA PANTALLA (system("cls"))
            juegoUnJugador(); // Llamada a la función juegoUnJugador
            break;
        case 2:
            rlutil::cls();
           juegoDosJugadores();
            break;
        case 3:
            rlutil::cls();

            break;
        case 4:
            rlutil::cls();
            rlutil::locate(1,20);
            cout << "                                                                    ¡ADIOS! NOS VEMOS PRONTO                                                                              " << endl;
        rlutil::anykey();
        rlutil::cls(); //
        break;
        ///si se selecciona otra opcion
        default:
            rlutil::cls();
            cout << "OPCION INVALIDA." << endl << endl;
            cout << "Presione una tecla para volver a menu principal...";
            rlutil::anykey();
            rlutil::cls();
            }
    } while (opcion != 4);


}

