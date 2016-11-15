#include <stdio.h>

//
// Created by agostino on 26/10/16.
//


int es1(int array[], int l){
    int i;
    for (i = 0; i < l; i++) {
        printf("array[%d] -> %d\n", i, array[i]);
    }
}

int esercizio2(int array[], int l){
    int i;
    int somma = 0;
    for (i = 0; i < l; i++) {
        somma+=array[i];
    }
    printf("%d",somma);
}

int es3(int array[], int l){
    int i;
    int sottrazione = array[0];
    for (i = 1; i < l; i++) {
        sottrazione-=array[i];
    }
    printf("%d",sottrazione);
}

void es4(float array[], int l){
    int i;
    float molt = 1.0;
    for (i = 0; i < l; i++) {
        molt = molt * array[i];
    }
    printf("%0.2f",molt);
}

void es5(float array[], int l){
    int i;
    float sottrazione = array[0];
    for (i = 1; i < l; i++) {
        sottrazione = sottrazione - array[i];
    }
    printf("%0.2f",sottrazione);
}

void es6(){
    float array[] = {35.4, 46.7, 77.55, 11.1, 9.04, 0.7};
    int i;
    float somma = 0.0;
    for (i = 0; i < 6; i++) {
        somma = somma + array[i];
    }
    somma = somma/6;
    printf("%.2f",somma);
}

void es7(){
    float array[] =  { 35.4, 46.7, 77.55, 11.1, 9.04, 0.7};
    int i;
    int l = 6;
    float mediaPond = 0.0;
    float sommaCredit = 0.0;
    for(i = 0; i<l/2; i++){
        mediaPond += (array[i] * array[l-i-1]);
        sommaCredit += array[l-i-1];
    }
    mediaPond = mediaPond/sommaCredit;
    printf("%f", mediaPond);
}


void es9(){
    int l=6;
    float array[] = { 35.4, 46.7, 77.55, 11.1, 9.04, 0.7};
    float memory;
    for(int i = 0; i<l; i++){
        for(int j = i+1; j<l;j++){
            if(array[j]<array[i]){
                memory = array[j];
                array[j] = array[i];
                array[i] = memory;
            }
        }
    }
    for(int a = 0; a<5; a++){
        if(a==4){
            printf("%0.2f ",array[a]);
        } else{
            printf("%0.2f - ",array[a]);
        }
    }
}

float magg(float array[], int length);
float min(float array[], int length);
float media(float array[], int length);

void es8(){

    float array[] = { 35.4, 46.7, 77.55, 11.1, 9.04, 0.75 };
    int length = sizeof(array)/sizeof(*array);

    printf("Max: %.2f\n", magg(array, length));
    printf("Min: %.2f\n", min(array, length));
    printf("Media : %.2f\n", media(array, length));


}

float media(float arr[], int l){
    float media = 0;
    for(int i = 0; i<l; i++){
        media += arr[i];
    }
    return media /=l;
}

float min(float arr [], int l){
    float min = arr[0];
    for(int i = 1; i<l; i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    return min;
}


float magg(float arr[], int l){
    float max = arr[0];
    for(int i = 1; i<l; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}

int main() {
    int arrGenericInt[] = {100, 20, 30, 50};
    int lengthArrGenericInt = sizeof(arrGenericInt)/sizeof(*arrGenericInt);

    float  arrFloat[] = {10.0, 0.5, 0.2, 0.1};
    int lengthArrFloat = sizeof(arrFloat)/sizeof(*arrFloat);

    float arrEs[] = {35.4, 46.7, 77.55, 11.1, 9.04, 0.75};
    int lengtharrEs = sizeof(arrEs)/sizeof(*arrEs);

    //int arrGenericFloat[] = {};

    for(int i = 0; 1!=0; i++){
        int a;
        printf("\nInserisci il numero dell'esercizio che vuoi eseguire\n");
        printf("Se vuoi uscire dal ciclo premi 0\n");
        printf("ATTENZIONE: puoi inserire soltanto numeri interi\n");

        scanf("%d", &a);
        switch (a) {
            case 0:
                return 0;
            case 1:
                es1(arrGenericInt,lengthArrGenericInt);
                break;
            case 2:
                esercizio2(arrGenericInt, lengthArrGenericInt);
                break;
            case 3:
                es3(arrGenericInt, lengthArrGenericInt);
                break;
            case 4:
                es4(arrFloat, lengthArrFloat);
                break;
            case 5:
                es5(arrFloat, lengthArrFloat);
                break;
            case 6:
                es6();
                break;
            case 7:
                es7();
                break;
            case 8:
                es8();
                break;
            case 9:
                es9();
                break;
            default:
                printf("Ritenta, sarai più fortunato.");
                break;
        }
    }
}