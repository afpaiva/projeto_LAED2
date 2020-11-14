#include <stdio.h>

// Funções abaixo são para trocar as cores
void pink(void) {
    printf("\033[1;35m");
}

void yellow(void) {
    printf("\033[1;33m");
}

void blue(void) {
    printf("\033[1;34m");
}

void green(void) {
    printf("\033[1;32m");
}

void red(void) {
    printf("\033[1;31m");
}

void white(void) {
    printf("\033[1;29m");
}

void reset_cores(void) {
    printf("\033[0m");
}
