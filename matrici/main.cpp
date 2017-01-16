#include <iostream>
#include <fstream>

using namespace std;

void es1(int array[10][10]){
    int sum = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            sum += array[i][j];
        }
    }
    cout << "La somma è: " << sum;
}

void es2(int array[10][10]){
    double molt = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            molt *= array[i][j];
        }
    }
    cout << "La moltiplicazione è: " << molt;
}

void es3(int array[10][10]){
    double molt = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            molt *= array[i][j];
        }
    }
    cout << "La media è: " << molt/100;
}


void es4(int array[10][10]){
    for(int i = 0; i < 10; i++){
        int sum = 0;
        for(int j = 0; j<10; j++){
            sum += array[i][j];
            if(j==9){
                cout << "La somma della " << i+1<<"° riga è " << sum << "\n";
            }
        }
    }
}

void es5(int array[10][10]){
    int sum = 0;
    int j = 0;

    for(int i = 1; j<10; i++){
        sum += array[i][j];
        if(i==9){
            cout << "La somma della " << j+1<<"° colonna è " << sum << "\n";
            i = 0;
            j++;
            sum = 0;
        }
    }
}

void es6(int array[10][10]){
    int j = 0;
    for(int i = 0; i < 10; i++){
        int min = array[i][0];
        for(int j = 0; j<10; j++){
            if(min>array[i][j]){
                min = array[i][j];
            }
            if(j==9){
                cout << "Il minimo della " << i+1<<"° riga è " << min << "\n";
            }
        }
    }
}

void es7(int array[10][10]){
    int min = array[0][0];
    int j = 0;

    for(int i = 0; j<10; i++){
        if(min > array[i][j]){
            min = array[i][j];
        }
        if(i==9){
            cout << "Il minimo della " << j+1<<"° colonna è " << min << "\n";
            i = 0;
            j++;
            min = array[i][j];
        }
    }

}

void es8(int array[10][10]){
    int sum = 0;
    for(int i = 0; i < 10; i++){
        sum += array[i][i];
    }
    cout << "La somma della diagonale è: " << sum <<"\n";
}

void stampa(int array[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            cout << array[i][j] << " ";
            if (j==9){
                cout <<"\n";
            }
        }
    }
}

void es9(int array[10][10]){
    ofstream myfile; myfile.open("/home/ago/ClionProjects/matrici/file.txt");


    if (myfile.is_open())
    {
        for(int i = 0; i < 10; i++){
            for(int j = 0; j<10; j++){
                myfile << array[i][j] << "\t";
                cout << array[i][j] << "\t";
                if (j==9){
                    myfile << "\n";
                    cout <<"\n";
                }
            }
        }
        myfile.close();
    }
    else cout << "Can't open file";

}

int main() {

    int matrice[10][10];
    srand((unsigned)time(NULL));

    int i = 0;
    for(i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            matrice[i][j] = rand() % 50;
        }
    }

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
                es1(matrice);
                break;
            case 2:
                es2(matrice);
                break;
            case 3:
                es3(matrice);
                break;
            case 4:
                es4(matrice);
                break;
            case 5:
                es5(matrice);
                break;
            case 6:
                es6(matrice);
                break;
            case 7:
                es7(matrice);
                break;
            case 8:
                es8(matrice);
                break;
            case 9:
                es9(matrice);
                break;
            case 99:
                stampa(matrice);
                break;
        }
    }while (a!=0);
}