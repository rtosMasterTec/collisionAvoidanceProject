#include "scheduling.h"

// global variables
sch_config_t config;


unsigned lottery (void) {

    unsigned totalactivos = 0;
    unsigned winner = 0;
    unsigned winthread = 0;

    /* En caso ningun thread este activo */
    if (!config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) {
        winthread = 0;
        winner = 0;
        return winthread;
    }

    /* Determina el total de tiquetes que seran evaluados para obtener el ganador */
    if (config.threadbuffer[0]) totalactivos = config.tickets[0];
    if (config.threadbuffer[1]) totalactivos = (totalactivos + config.tickets[1]);
    if (config.threadbuffer[2]) totalactivos = (totalactivos + config.tickets[2]);
    if (config.threadbuffer[3]) totalactivos = (totalactivos + config.tickets[3]);
    if (config.threadbuffer[4]) totalactivos = (totalactivos + config.tickets[4]);

    /*printf ("config.tickets totales activos: %d\n", totalactivos);
    printf ("\n"); */

    /* Realiza la rifa y se obtiene de manera aleatoria el boleto ganador */
    do {
        winner = rand() % totalactivos;
    } while (winner == 0);

    printf ("Boleto ganador es: %d\n", winner);

    /* Determina segun el boleto cual es el thread ganador */

    /* Casos en q puede ganar thread 1 */
    if (config.threadbuffer[0] && winner <= config.tickets[0]) {
        winthread = 1;
        return winthread;
    }

    /* Casos en q puede ganar thread 2 */

    if (config.threadbuffer[0] && config.threadbuffer[1] && winner <= (config.tickets[1]+config.tickets[0])) {
        winthread = 2;
        return winthread;
    }
    if (!config.threadbuffer[0] && config.threadbuffer[1] && winner <= config.tickets[1]) {
        winthread = 2;
        return winthread;
    }

    /* Casos en q puede ganar thread 3 */

    if (config.threadbuffer[0]) {
        if (config.threadbuffer[1]) {
            if (config.threadbuffer[2] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[2])) {
                winthread = 3;
                return winthread;
            }
        }
        if (!config.threadbuffer[1]) {
            if (config.threadbuffer[2] && winner <= (config.tickets[0]+config.tickets[2])) {
                winthread = 3;
                return winthread;
            }
        }
    }
    if (!config.threadbuffer[0]) {
        if (config.threadbuffer[1]) {
            if (config.threadbuffer[2] && winner <= (config.tickets[1]+config.tickets[2])) {
                winthread = 3;
                return winthread;
            }
        }
        if (!config.threadbuffer[1]) {
            if (config.threadbuffer[2] && winner <= config.tickets[2]) {
                winthread = 3;
                return winthread;
            }
        }
    }

    /* Casos en q puede ganar thread 4 */

    if (config.threadbuffer[0]) {
        if (config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[2]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
        }
        if (!config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[0]+config.tickets[2]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[0]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
        }
    }
    if (!config.threadbuffer[0]) {
        if (config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[1]+config.tickets[2]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[1]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
        }
        if (!config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= (config.tickets[2]+config.tickets[3])) {
                    winthread = 4;
                    return winthread;
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3] && winner <= config.tickets[3]) {
                    winthread = 4;
                    return winthread;
                }
            }
        }
    }

    /* Casos en q puede ganar thread 5 */

    if (config.threadbuffer[0]) {
        if (config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[2]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[2]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[1]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
        }
        if (!config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[2]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[2]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[0]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
        }
    }
    if (!config.threadbuffer[0]) {
        if (config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[1]+config.tickets[2]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[1]+config.tickets[2]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[1]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[1]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
        }
        if (!config.threadbuffer[1]) {
            if (config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[2]+config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[2]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
            if (!config.threadbuffer[2]) {
                if (config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= (config.tickets[3]+config.tickets[4])) {
                        winthread = 5;
                        return winthread;
                    }
                }
                if (!config.threadbuffer[3]) {
                    if (config.threadbuffer[4] && winner <= config.tickets[4]) {
                        winthread = 5;
                        return winthread;
                    }
                }
            }
        }
    }

    return winthread;
}


bool invalidateThread (unsigned ID) {
    bool Done = false;

    if (ID == 1) config.threadbuffer[0] = false;
    if (ID == 2) config.threadbuffer[1] = false;
    if (ID == 3) config.threadbuffer[2] = false;
    if (ID == 4) config.threadbuffer[3] = false;
    if (ID == 5) config.threadbuffer[4] = false;

    Done = !(config.threadbuffer[0] | config.threadbuffer[1] | config.threadbuffer[2] | config.threadbuffer[3] | config.threadbuffer[4]);

    if (Done) printf("Ningun thread activo\n");

    return Done;
}


unsigned priorityScheduling (void) {

    unsigned winthread = 0;

    /* En caso ningun thread este activo */
    if (!config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00000 - 0*/
        winthread = 0;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00001 - 1*/
        winthread = 1;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00010 - 2*/
        winthread = 2;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00011 - 3*/
        if (config.priority[0] > config.priority[1]) winthread = 1;
        else winthread = 2;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00100 - 4*/
        winthread = 3;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00101 - 5*/
        if (config.priority[0] > config.priority[2]) winthread = 1;
        else winthread = 3;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00110 - 6*/
        if (config.priority[1] > config.priority[2]) winthread = 2;
        else winthread = 3;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && !config.threadbuffer[4]) { /* 00111 - 7*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[2]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[2]) winthread = 2;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[1]) winthread = 3;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01000 - 8*/
        winthread = 4;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01001 - 9*/
        if (config.priority[0] > config.priority[3]) winthread = 1;
        else winthread = 4;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01010 - 10*/
        if (config.priority[1] > config.priority[3]) winthread = 2;
        else winthread = 4;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01011 - 11*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[3]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[3]) winthread = 2;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[1]) winthread = 4;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01100 - 12*/
        if (config.priority[2] > config.priority[3]) winthread = 3;
        else winthread = 4;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01101 - 13*/
        if (config.priority[0] > config.priority[2] && config.priority[0] > config.priority[3]) winthread = 1;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[3]) winthread = 3;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[2]) winthread = 4;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01110 - 14*/
        if (config.priority[1] > config.priority[2] && config.priority[1] > config.priority[3]) winthread = 2;
        if (config.priority[2] > config.priority[1] && config.priority[2] > config.priority[3]) winthread = 3;
        if (config.priority[3] > config.priority[1] && config.priority[3] > config.priority[2]) winthread = 4;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && !config.threadbuffer[4]) { /* 01111 - 15*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[2] && config.priority[0] > config.priority[3]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[2] && config.priority[1] > config.priority[3]) winthread = 2;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[1] && config.priority[2] > config.priority[3]) winthread = 3;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[1] && config.priority[3] > config.priority[2]) winthread = 4;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10000 - 16*/
        winthread = 5;
        return winthread;
    }

   if (config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10001 - 17*/
        if (config.priority[0] > config.priority[4]) winthread = 1;
        else winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10010 - 18*/
        if (config.priority[1] > config.priority[4]) winthread = 2;
        else winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10011 - 19*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[1]) winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10100 - 20*/
        if (config.priority[2] > config.priority[4]) winthread = 3;
        else winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10101 - 21*/
        if (config.priority[0] > config.priority[2] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[2]) winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10110 - 22*/
        if (config.priority[1] > config.priority[2] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[2] > config.priority[1] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[4] > config.priority[1] && config.priority[4] > config.priority[2]) winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && !config.threadbuffer[3] && config.threadbuffer[4]) { /* 10111 - 23*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[2] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[2] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[1] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[1] && config.priority[4] > config.priority[2]) winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11000 - 24*/
        if (config.priority[3] > config.priority[4]) winthread = 4;
        else winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11001 - 25*/
        if (config.priority[0] > config.priority[3] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11010 - 26*/
        if (config.priority[1] > config.priority[3] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[3] > config.priority[1] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[1] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && !config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11011 - 27*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[3] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[3] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[1] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[1] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11100 - 28*/
        if (config.priority[2] > config.priority[3] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[3] > config.priority[2] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[2] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && !config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11101 - 29*/
        if (config.priority[0] > config.priority[2] && config.priority[0] > config.priority[3] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[3] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[2] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[2] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    if (!config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 11110 - 30*/
        if (config.priority[1] > config.priority[2] && config.priority[1] > config.priority[3] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[2] > config.priority[1] && config.priority[2] > config.priority[3] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[3] > config.priority[1] && config.priority[3] > config.priority[2] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[1] && config.priority[4] > config.priority[2] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    if (config.threadbuffer[0] && config.threadbuffer[1] && config.threadbuffer[2] && config.threadbuffer[3] && config.threadbuffer[4]) { /* 01111 - 31*/
        if (config.priority[0] > config.priority[1] && config.priority[0] > config.priority[2] && config.priority[0] > config.priority[3] && config.priority[0] > config.priority[4]) winthread = 1;
        if (config.priority[1] > config.priority[0] && config.priority[1] > config.priority[2] && config.priority[1] > config.priority[3] && config.priority[1] > config.priority[4]) winthread = 2;
        if (config.priority[2] > config.priority[0] && config.priority[2] > config.priority[1] && config.priority[2] > config.priority[3] && config.priority[2] > config.priority[4]) winthread = 3;
        if (config.priority[3] > config.priority[0] && config.priority[3] > config.priority[1] && config.priority[3] > config.priority[2] && config.priority[3] > config.priority[4]) winthread = 4;
        if (config.priority[4] > config.priority[0] && config.priority[4] > config.priority[1] && config.priority[4] > config.priority[2] && config.priority[4] > config.priority[3]) winthread = 5;
        return winthread;
    }

    return winthread;
}
