#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

void es1(int array[], int length){
    for (int i = 0; i < length; i++) {
        cout << "array[" << i << "] -> " << array[i] <<"\n";
    }
}

void es2(int array[], int length){
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    cout << sum;
}

void es3(int array[], int length){
    int sot = array[0];
    for (int i = 1; i < length; i++) {
        sot -= array[i];
    }
    cout << sot;
}

void es4(float array[], int l){
    int i;
    float molt = 1.0;
    for (i = 0; i < l; i++) {
        molt = molt * array[i];
    }
    cout << fixed <<setprecision(2) << molt;
}

void es5(float array[], int l){
    int i;
    float sottrazione = array[0];
    for (i = 1; i < l; i++) {
        sottrazione = sottrazione - array[i];
    }
    cout << fixed <<setprecision(2) << sottrazione;
}

void es6(){
    float array[] = {35.4, 46.7, 77.55, 11.1, 9.04, 0.7};
    int i;
    float somma = 0.0;
    for (i = 0; i < 6; i++) {
        somma = somma + array[i];
    }
    somma = somma/6;
    cout << fixed <<setprecision(2) << somma;
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
    cout << mediaPond;
}


float magg(float array[], int length);
float min(float array[], int length);
float media(float array[], int length);

void es8(){

    float array[] = { 35.4, 46.7, 77.55, 11.1, 9.04, 0.75 };
    int length = sizeof(array)/sizeof(*array);

    cout << "Max: " << magg(array, length) << "\n";
    cout << "Min: " << min(array, length) << "\n";
    cout << "Media: " << media(array, length) << "\n";


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
            cout << fixed <<setprecision(2) << array[a] << "\n";
        } else{
            cout << fixed <<setprecision(2) << array[a] << "\n";
        }
    }
}

int main() {

    int arrGenericInt[] = {100, 20, 30, 50};
    int lengthArrGenericInt = sizeof(arrGenericInt)/sizeof(*arrGenericInt);

    float  arrFloat[] = {10.0, 0.5, 0.2, 0.1};
    int lengthArrFloat = sizeof(arrFloat)/sizeof(*arrFloat);

    float arrEs[] = {35.4, 46.7, 77.55, 11.1, 9.04, 0.75};
    int lengtharrEs = sizeof(arrEs)/sizeof(*arrEs);

    int a;
    do{
        cout << "\nInserisci il numero dell'esercizio che vuoi eseguire\n";
        cout << "Se vuoi uscire dal ciclo premi 0\n";
        cout << "ATTENZIONE: puoi inserire soltanto numeri interi\n";

        cin >> a;

        switch (a) {
            case 0:
                cout << "Grazie per avere usato il nostro programma! Buona giornata.";
                return 0;
            case 1:
                es1(arrGenericInt, lengthArrGenericInt);
                break;
            case 2:
                es2(arrGenericInt, lengthArrGenericInt);
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
        }
    }while (a!=0);
    return 0;
}