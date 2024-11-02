#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "shuffle.c"
#include "compute.c"
#include "text.c"
#include "print.c"

// #include <stdbool.h>
// #include <inttypes.h>
int main() {
    int f[P], ff[P], g[G], gg[G], a[G], M[S][S], h[H][H];
    randomize(M);permutize(f,P);permutize(g,G);
    invert(g,gg,G);invert(f,ff,P);

    print_perm(f,P);
    print_perm(ff,P);
    //print_perm(g, G);


    //print_matrix(M);
    //print_values(M);
    //forward(M, g);
    //print_matrix(M);
        //print_matrix(M);


    //values(M,h,g);
    //print_matrix(M);
    print_values(M);
    forward(M, g);
    permute(M,f);


    //forward(M, g);
    //values(M,h,g);
   // print_matrix(M);
    print_values(M);

    permute(M,ff);
    forward(M, gg);

    //forward(M, gg);
    //values(M,h,g);
    //print_matrix(M);
    // print_values(M);
    cls();
    seed(M);
    cursor_to(0,0);
    print_matrix(M);
    sleep(3);
    int T = 100;
    hide_cursor();
    while(1) {

    
        for (int i = 0; i < T ; i++) {
            
            forward(M, g);
            permute(M,f);
            cursor_to(0,0);
            print_matrix(M);
            usleep(400000);
        }
        for (int i = 0; i < T ; i++) {
            permute(M,ff);
            forward(M, gg);
            cursor_to(0,0);
            print_matrix(M);
            usleep(400000);
        }
        sleep(3);
    }
}