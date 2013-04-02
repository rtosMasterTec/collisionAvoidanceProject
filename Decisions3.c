#include <stdio.h>   /* required for file operations */
#include <time.h>
#include <stdbool.h>


    unsigned posX, posY, destX, destY, Xanterior, Yanterior;

    unsigned R1X, R1Y, R2X, R2Y, R3X, R3Y;

    char R1dir, R2dir, R3dir;

    bool R1N, R1S, R1O, R1E, R2N, R2S, R2O, R2E, R3N, R3S, R3O, R3E;

    bool robots[3];

    unsigned mapa [30][30];

    unsigned i, j;


unsigned tomaDecisiones (void) {

    if ((posX == destX) && (posY == destY)) return 0;

    /* Evalua el robot 1 */
    if (robots[0]) {
        /* Evalua si R1 bloquea el camino */
        /* Si el robot va hacia el Este */
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R1X) && (posY == R1Y+1) && (R1dir == 'N')) return 0;
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R1X) && (posY == R1Y-1) && (R1dir == 'S')) return 0;
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R1X) && (posY == R1Y)) return 0;
        /* Si el robot va hacia el Oeste */
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R1X) && (posY == R1Y+1) && (R1dir == 'N')) return 0;
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R1X) && (posY == R1Y-1) && (R1dir == 'S')) return 0;
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R1X) && (posY == R1Y)) return 0;
        /* Si el robot va hacia el Norte */
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R1Y) && (posX == R1X+1) && (R1dir == 'E')) return 0;
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R1Y) && (posX == R1X-1) && (R1dir == 'O')) return 0;
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R1Y) && (posX == R1X)) return 0;
        /* Si el robot va hacia el Sur */
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R1Y) && (posX == R1X+1) && (R1dir == 'E')) return 0;
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R1Y) && (posX == R1X-1) && (R1dir == 'O')) return 0;
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R1Y) && (posX == R1X)) return 0;


        /* Evalua si hay obstaculos en la posicion Sur del robot 1 */
        if (R1S) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R1X > posX) && (posY == R1Y-1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R1X < posX) && (posY == R1Y-1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R1Y-1 > posY) && (posX == R1X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R1Y-1 < posY) && (posX == R1X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Norte del robot 1 */
        if (R1N) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R1X > posX) && (posY == R1Y+1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R1X < posX) && (posY == R1Y+1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R1Y+1 > posY) && (posX == R1X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R1Y+1 < posY) && (posX == R1X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Este del robot 1 */
        if (R1E) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R1X+1 > posX) && (posY == R1Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R1X+1 < posX) && (posY == R1Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R1Y > posY) && (posX == R1X+1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R1Y < posY) && (posX == R1X+1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Oeste del robot 1 */
        if (R1O) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R1X-1 > posX) && (posY == R1Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R1X-1 < posX) && (posY == R1Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R1Y > posY) && (posX == R1X-1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R1Y < posY) && (posX == R1X-1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
    } /* End if robots[0] */

/* ------------------------------------------------------------------------------------------------------ */

    /* Evalua el robot 2 */
    if (robots[1]) {
        /* Evalua si R2 bloquea el camino */
        /* Si el robot va hacia el Este */
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R2X) && (posY == R2Y+1) && (R2dir == 'N')) return 0;
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R2X) && (posY == R2Y-1) && (R2dir == 'S')) return 0;
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R2X) && (posY == R2Y)) return 0;
        /* Si el robot va hacia el Oeste */
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R2X) && (posY == R2Y+1) && (R2dir == 'N')) return 0;
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R2X) && (posY == R2Y-1) && (R2dir == 'S')) return 0;
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R2X) && (posY == R2Y)) return 0;
        /* Si el robot va hacia el Norte */
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R2Y) && (posX == R2X+1) && (R2dir == 'E')) return 0;
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R2Y) && (posX == R2X-1) && (R2dir == 'O')) return 0;
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R2Y) && (posX == R2X)) return 0;
        /* Si el robot va hacia el Sur */
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R2Y) && (posX == R2X+1) && (R2dir == 'E')) return 0;
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R2Y) && (posX == R2X-1) && (R2dir == 'O')) return 0;
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R2Y) && (posX == R2X)) return 0;


        /* Evalua si hay obstaculos en la posicion Sur del robot 2 */
        if (R2S) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R2X > posX) && (posY == R2Y-1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R2X < posX) && (posY == R2Y-1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R2Y-1 > posY) && (posX == R2X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R2Y-1 < posY) && (posX == R2X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Norte del robot 2 */
        if (R2N) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R2X > posX) && (posY == R2Y+1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R2X < posX) && (posY == R2Y+1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R2Y+1 > posY) && (posX == R2X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R2Y+1 < posY) && (posX == R2X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Este del robot 2 */
        if (R2E) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R2X+1 > posX) && (posY == R2Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R2X+1 < posX) && (posY == R2Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R2Y > posY) && (posX == R2X+1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R2Y < posY) && (posX == R2X+1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Oeste del robot 2 */
        if (R2O) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R2X-1 > posX) && (posY == R2Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R2X-1 < posX) && (posY == R2Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R2Y > posY) && (posX == R2X-1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R2Y < posY) && (posX == R2X-1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
    } /* End if robots[1] */

/* ------------------------------------------------------------------------------------------------------ */

    /* Evalua el robot 3 */
    if (robots[2]) {
        /* Evalua si R3 bloquea el camino */
        /* Si el robot va hacia el Este */
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R3X) && (posY == R3Y+1) && (R3dir == 'N')) return 0;
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R3X) && (posY == R3Y-1) && (R3dir == 'S')) return 0;
        if ((posY == Yanterior) && (posX > Xanterior) && (posX+1 == R3X) && (posY == R3Y)) return 0;
        /* Si el robot va hacia el Oeste */
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R3X) && (posY == R3Y+1) && (R3dir == 'N')) return 0;
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R3X) && (posY == R3Y-1) && (R3dir == 'S')) return 0;
        if ((posY == Yanterior) && (posX < Xanterior) && (posX-1 == R3X) && (posY == R3Y)) return 0;
        /* Si el robot va hacia el Norte */
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R3Y) && (posX == R3X+1) && (R3dir == 'E')) return 0;
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R3Y) && (posX == R3X-1) && (R3dir == 'O')) return 0;
        if ((posX == Xanterior) && (posY > Yanterior) && (posY+1 == R3Y) && (posX == R3X)) return 0;
        /* Si el robot va hacia el Sur */
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R3Y) && (posX == R3X+1) && (R3dir == 'E')) return 0;
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R3Y) && (posX == R3X-1) && (R3dir == 'O')) return 0;
        if ((posX == Xanterior) && (posY < Yanterior) && (posY-1 == R3Y) && (posX == R3X)) return 0;


        /* Evalua si hay obstaculos en la posicion Sur del robot 3 */
        if (R3S) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R3X > posX) && (posY == R3Y-1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R3X < posX) && (posY == R3Y-1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R3Y-1 > posY) && (posX == R3X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R3Y-1 < posY) && (posX == R3X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Norte del robot 3 */
        if (R3N) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R3X > posX) && (posY == R3Y+1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R3X < posX) && (posY == R3Y+1) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R3Y+1 > posY) && (posX == R3X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R3Y+1 < posY) && (posX == R3X) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Este del robot 3 */
        if (R3E) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R3X+1 > posX) && (posY == R3Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R3X+1 < posX) && (posY == R3Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R3Y > posY) && (posX == R3X+1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R3Y < posY) && (posX == R3X+1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
        /* Evalua si hay obstaculos en la posicion Oeste del robot 3 */
        if (R3O) {
            /* Si el robot va hacia el Este */
            if ((posY == Yanterior) && (posX > Xanterior) && (R3X-1 > posX) && (posY == R3Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Oeste */
            if ((posY == Yanterior) && (posX < Xanterior) && (R3X-1 < posX) && (posY == R3Y) && (mapa[posY+1][posX] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posY = posY + 1;
                return 0;
            }
            /* Si el robot va hacia el Norte */
            if ((posX == Xanterior) && (posY > Yanterior) && (R3Y > posY) && (posX == R3X-1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
            /* Si el robot va hacia el Sur */
            if ((posX == Xanterior) && (posY < Yanterior) && (R3Y < posY) && (posX == R3X-1) && (mapa[posY][posX+1] == 0)) {
                Xanterior = posX;
                Yanterior = posY;
                posX = posX + 1;
                return 0;
            }
        }
    } /* End if robots[1] */

/* ------------------------------------------------------------------------------------------------------ */
    /* Toma de decisiones de movimiento */
    if (destX > posX) {
        if ((mapa[posY][posX+1] == 0) && (posX+1 != Xanterior)) {
            Xanterior = posX;
            Yanterior = posY;
            posX = posX + 1;
            return 0;
        }
        else {
            if (destY >= posY) {
                if ((mapa[posY+1][posX] == 0) && (posY+1 != Yanterior)) {
                    Yanterior = posY;
                    Xanterior = posX;
                    posY = posY + 1;
                    return 0;
                }
                else {
                    if (Xanterior == posX){
                        if ((mapa[posY+1][posX] == 1) && (mapa[posY][posX+1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        if ((mapa[posY+1][posX] == 1) && (mapa[posY][posX-1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        if (mapa[posY+1][posX] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posY = posY + 1;
                            return 0;
                        }
                    }
                    if (Xanterior != posX+1){
                        if (mapa[posY][posX+1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                    }
                    if (Xanterior != posX-1){
                        if (mapa[posY][posX-1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                    }
                }
            }
            if (destY < posY) {
                if ((mapa[posY-1][posX] == 0) && (posY-1 != Yanterior)) {
                    Yanterior = posY;
                    Xanterior = posX;
                    posY = posY - 1;
                    return 0;
                }
                else {
                    if (Xanterior == posX){
                        if ((mapa[posY-1][posX] == 1) && (mapa[posY][posX+1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        if ((mapa[posY-1][posX] == 1) && (mapa[posY][posX-1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        if (mapa[posY+1][posX] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posY = posY + 1;
                            return 0;
                        }
                    }
                    if (Xanterior != posX+1){
                        if (mapa[posY][posX+1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        else {
                            if (mapa[posY+1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY + 1;
                                return 0;
                            }
                            if (mapa[posY-1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY - 1;
                                return 0;
                            }
                        }

                    }
                    if (Xanterior != posX-1){
                        if (mapa[posY][posX-1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        else {
                            if (mapa[posY+1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY + 1;
                                return 0;
                            }
                            if (mapa[posY-1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY - 1;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if (destX < posX) {
        if ((mapa[posY][posX-1] == 0) && (posX-1 != Xanterior)) {
            Xanterior = posX;
            Yanterior = posY;
            posX = posX - 1;
            return 0;
        }
        else {
            if (destY >= posY) {
                if ((mapa[posY+1][posX] == 0) && (posY+1 != Yanterior)) {
                    Yanterior = posY;
                    Xanterior = posX;
                    posY = posY + 1;
                    return 0;
                }
                else {
                    if (Xanterior == posX){
                        if ((mapa[posY+1][posX] == 1) && (mapa[posY][posX+1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        if ((mapa[posY+1][posX] == 1) && (mapa[posY][posX-1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        if (mapa[posY+1][posX] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posY = posY + 1;
                            return 0;
                        }
                    }
                    if (Xanterior != posX+1) {
                        if (mapa[posY][posX+1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        else {
                            if (mapa[posY+1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY + 1;
                                return 0;
                            }
                            if (mapa[posY-1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY - 1;
                                return 0;
                            }
                        }
                    }
                    if (Xanterior != posX-1) {
                        if (mapa[posY][posX-1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        else {
                            if (mapa[posY+1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY + 1;
                                return 0;
                            }
                            if (mapa[posY-1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY - 1;
                                return 0;
                            }
                        }
                    }
                }
            }
            if (destY < posY) {
                if ((mapa[posY-1][posX] == 0) && (posY-1 != Yanterior)) {
                    Yanterior = posY;
                    Xanterior = posX;
                    posY = posY - 1;
                    return 0;
                }
                else {
                    if (Xanterior == posX){
                        if ((mapa[posY-1][posX] == 1) && (mapa[posY][posX+1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        if ((mapa[posY-1][posX] == 1) && (mapa[posY][posX-1] == 1)) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        if (mapa[posY+1][posX] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posY = posY + 1;
                            return 0;
                        }
                    }
                    if (Xanterior != posX+1){
                        if (mapa[posY][posX+1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX + 1;
                            return 0;
                        }
                        else {
                            if (mapa[posY+1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY + 1;
                                return 0;
                            }
                            if (mapa[posY-1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY - 1;
                                return 0;
                            }
                        }
                    }
                    if (Xanterior != posX-1){
                        if (mapa[posY][posX-1] == 0) {
                            Yanterior = posY;
                            Xanterior = posX;
                            posX = posX - 1;
                            return 0;
                        }
                        else {
                            if (mapa[posY+1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY + 1;
                                return 0;
                            }
                            if (mapa[posY-1][posX] == 0) {
                                Yanterior = posY;
                                Xanterior = posX;
                                posY = posY - 1;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    if (destX == posX) {
        if (destY > posY) {
            if ((mapa[posY+1][posX] == 0) && (posY+1 != Yanterior)) {
                Yanterior = posY;
                Xanterior = posX;
                posY = posY + 1;
                return 0;
            }
            else {
                if (mapa[posY][posX+1] == 0) {
                    Yanterior = posY;
                    Xanterior = posX;
                    posX = posX + 1;
                    return 0;
                }
            }
        }
        if (destY < posY) {
            if ((mapa[posY-1][posX] == 0) && (posY-1 != Yanterior)) {
                Yanterior = posY;
                Xanterior = posX;
                posY = posY - 1;
                return 0;
            }
            else {
                if (mapa[posY][posX+1] == 0) {
                    Yanterior = posY;
                    Xanterior = posX;
                    posX = posX + 1;
                    return 0;
                }
            }
        }
    }
    return 0;
} /* Fin procedimiento tomaDecisiones */

void readfile (void) {

   FILE *fr;            /* declare the file pointer */
   char line[80];
   int linea;				/* Numero de linea leido en el archivo de texto */
   int i;

   fr = fopen ("map.txt", "rt");  /* open the file for reading */

   linea = 0;
   i = 0;

   while(fgets(line, 80, fr) != NULL)
   {
	 /* get a line, up to 80 chars from fr.  done if NULL */

        for(i=0;i<30;i++)
        {
            if (line[i] == '1') mapa[linea][i] = 1;
            else mapa[linea][i] = 0;
        }
        linea = linea + 1;
   } /* Close While */

   fclose(fr);  /* close the file */

   /* Despliegue de informacion obtenida del archivo */

    for(i=0;i<30;i++)
    {
        for(linea=0;linea<30;linea++)
        {
            printf("%d",mapa[i][linea]);
        }
        printf("\n");
    }

    i = 0;

    while (1) {
        tomaDecisiones();

        i = i + 1;
        if ((i >= 28) && (i < 36)) R1X = R1X + 1;

        printf ("Posicion: %d, %d \n", posX, posY);
        if ((posX == destX) && (posY == destY)) {
            printf("Destino alcanzado!!\n");
            return;
        }

        if (posY == 1 && posX == 1) {
            printf("Yanterior: %d", Yanterior);
            return;
        }

    }

}


/*main()

{
    posX = 2;
    posY = 14;
    destX = 27;
    destY = 2;

    Xanterior = posX;
    Yanterior = posY;

    R1X = 20;
    R1Y = 5;

    R2X = 0;
    R2Y = 0;
    R3X = 0;
    R3Y = 0;

    R1dir = 'E';
    R2dir = 'N';
    R3dir = 'O';

    R1N = true;
    R1S = false;
    R1O = false;
    R1E = false;

    R2N = false;
    R2S = false;
    R2O = false;
    R2E = false;

    R3N = false;
    R3S = false;
    R3O = false;
    R3E = false;

    robots[0] = true;
    robots[1] = false;
    robots[2] = false;


    readfile();

}*/ 
