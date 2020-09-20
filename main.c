/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: vojta
 *
 * Created on September 19, 2020, 9:52 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define VSTUP "casy.txt"
#define VYSTUP "odpoledne.txt"


int hodiny(int hodina){
    if(hodina == 0)
        return hodina + 12;
    if(hodina > 12)
        return hodina - 12;
    else
        return hodina;
}

int cas(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}


int main(int argc, char** argv) {
    
    FILE * vstup;
    FILE * vystup;
    int h;
    int m;
    int s;
    int poradi = 0, poradiS = 0;
    int hA;
    
    
    
    if((vstup = fopen(VSTUP, "r"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VSTUP);
    if((vystup = fopen(VYSTUP, "w"))== NULL)
        printf("Soubor %s se nepodarilo otevrit.\n", VYSTUP);
    
    printf("               U D A J E  Z E  S O U B O R U              \n");
    printf("----------------------------------------------------------\n");
    printf("poradi casu|evropsky cas| anglicky cas|sekundy od pulnoci|\n");
    printf("----------------------------------------------------------\n");
    fprintf(vystup,"                     O D P O L E D N E                    \n");
    fprintf(vystup,"----------------------------------------------------------\n");
    fprintf(vystup,"poradi casu|evropsky cas| anglicky cas|sekundy od pulnoci|\n");
    fprintf(vystup,"----------------------------------------------------------\n");
    while((fscanf(vstup, "%d %d %d", &h, &m, &s))!= EOF){
           poradi++;
           hA = hodiny(h);
           printf("%10d.|%4d:%2d:%2d  |%3d:%2d:%2d %s |%18d|\n", poradi, h, m, s, hA, m, s, (h >= 0 && h <= 11) ? "AM" : "PM", cas(h, m, s));
           if(h >= 12){
               poradiS++;
               fprintf(vystup,"%10d.|%4d:%2d:%2d  |%3d:%2d:%2d PM |%18d|\n", poradi, h, m, s, hA, m, s, cas(h, m, s));
           }
        }
    printf("----------------------------------------------------------\n");
    fprintf(vystup,"----------------------------------------------------------\n");
    printf("Ze souboru %s bylo precteno %d udaju o case.\n\n", VSTUP, poradi);
    fprintf(vystup,"Do souboru %s bylo yapsano %d udaju o case.", VYSTUP, poradiS);
    
    if((fclose(vstup))==EOF)
        printf("Soubor %s se nepodarilo uzavrit.\n", VSTUP);
    if((fclose(vystup))==EOF)
        printf("Soubor %s se nepodarilo uzavrit.\n", VYSTUP);
    else
        printf("Byl vytvoren soubor %s.\n", VYSTUP);
    return (EXIT_SUCCESS);
}

