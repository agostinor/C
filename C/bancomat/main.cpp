#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <cstring>

typedef struct node {
    int val;
    struct node * next;
    struct tm time;
} node_t;

static void push(node **head, int v, tm *tmp)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->val = v;
    temp->time = *tmp;
    temp->next = *head;
    *head = temp;
}

void print_prelievi(node_t * head) {
    node_t * current = head;

    printf("Somme prelevate:\n");
    while (current != NULL) {
        if(current->time.tm_sec <10)
        printf("%d euro il %d/%d/%d alle %d:%d:0%d\n", current->val, current->time.tm_mday, current->time.tm_mon, current->time.tm_year+1900, current->time.tm_hour, current->time.tm_min, current->time.tm_sec);
        else
        printf("%d euro il %d/%d/%d alle %d:%d:%d\n", current->val, current->time.tm_mday, current->time.tm_mon, current->time.tm_year+1900, current->time.tm_hour, current->time.tm_min, current->time.tm_sec);
        current = current->next;
    }
}

void print_versamenti(node_t * head) {
    node_t * current = head;

    printf("Somme versate:\n");
    while (current != NULL) {
        if(current->time.tm_sec <10)
            printf("%d euro il %d/%d/%d alle %d:%d:0%d\n", current->val, current->time.tm_mday, current->time.tm_mon, current->time.tm_year+1900, current->time.tm_hour, current->time.tm_min, current->time.tm_sec);
        else
            printf("%d euro il %d/%d/%d alle %d:%d:%d\n", current->val, current->time.tm_mday, current->time.tm_mon, current->time.tm_year+1900, current->time.tm_hour, current->time.tm_min, current->time.tm_sec);

        current = current->next;
    }
}

void leggiFile(FILE **f){
    *f = fopen("/home/ago/ClionProjects/bancomat/file.txt", "r");
    char c;
    //questo fa saltare la prima righa
    while (c != EOF){
        c = fgetc (*f);
        if(c=='.'){
            break;
        }
    }

    if (f==NULL) perror ("Error opening file");
    else
    {
        while (c != EOF){
            c = fgetc (*f);
            if(c == EOF){
                break;
            }
            printf("%c", c);
            if (c == '.'){
                c = fgetc (*f);
                if(c == '\n'){
                    printf("\n");
                } else{
                    printf("\n%c", c);
                }
            }
        }
        fclose(*f);
    }
}

int pickContoCorrenteFile(FILE **f){
    *f = fopen("/home/ago/ClionProjects/bancomat/file.txt", "r");
    int number = 0;
    fscanf(*f, "Conto corrente attuale: %d.", &number);
    fclose(*f);
    return number;
}

char* concat(const char *s1, const char *s2)
{
    char *result = (char *) malloc(strlen(s1) + strlen(s2) + 1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int find_length(char *input){
    int length = 0;
    while(input[length]!='\0')  //  remove ;
    {
        length++;
    }
    return length;
}

void setFirstRow(FILE **f, int a) {
    char * strNumber;
    char * str= "Conto corrente attuale: ";
    sprintf(strNumber, "%d.", a);
    str = concat(str, (const char *) strNumber);
    int l = find_length(str);
    *f = fopen("/home/ago/ClionProjects/bancomat/file.txt", "r+");
    for(int i = 0; i< l+1; i++){
        fputc(str[i], *f);
    }
    fclose(*f);
}

int main() {

    const char * path = "/home/ago/ClionProjects/bancomat/file.txt";
    FILE *f;

    int conto = pickContoCorrenteFile(&f);
    int preOvers = 0;
    int contaPrelievi = 0;
    int contaVersamenti = 0;

    node_t *prelievi;
    node_t *versamenti;

    char *s = (char*) malloc( 100 );
    int i = 0;
    char c;

    printf("\nIl tuo conto è di %d euro.\n", conto);
    printf("Scrivi se vuoi prelevare o versare danaro.\n");
    printf("Scrivi movimenti se vuoi vedere i movimenti effettuati.\n");
    printf("Scrivi exit se vuoi chiudere il bancomat.\n");
    printf("ATTENZIONE: puoi inserire soltanto numeri interi.\n");
    do{
        if(i!=0){
            setFirstRow(&f, conto);
            printf("Ora il tuo conto è %d.\n", conto);
            printf("Prelevare o versare?\n");
            printf("Digita movimenti se vuoi visulizzare quelli del tuo ultimo accesso.\n");
            printf("Digita file se vuoi visulizzare tutti i tuoi movimenti.\n");
            printf("Exit per uscire.\n");
        } else{
            i++;
        }
        time_t t = time(NULL);
        struct tm tiempo = *localtime(&t);


        scanf("%s",s);
        switch (s[0]) {
            case 'p':
                printf("Quanto vuoi prelevare?\n");
                scanf("%d", &preOvers);
                conto-= preOvers;
                if(contaPrelievi==0){
                    prelievi = (node_t *) malloc(sizeof(node_t));
                    prelievi->val = preOvers;
                    prelievi->time = tiempo;
                    prelievi->next = NULL;
                }else{
                    push(&prelievi, preOvers, &tiempo);
                }
                    f = fopen(path, "a");
                    fprintf(f, "In data %d/%d/%d alle %d:%d:%d hai prelevato %d euro.\n", tiempo.tm_mday,
                                        tiempo.tm_mon, tiempo.tm_year + 1900, tiempo.tm_hour, tiempo.tm_min,
                                        tiempo.tm_sec, preOvers);
                    contaPrelievi++;
                fclose(f);
                break;
            case 'v':
                printf("Quanto vuoi versare?\n");
                scanf("%d", &preOvers);
                conto+= preOvers;
                if(contaVersamenti==0){
                    versamenti = (node_t *) malloc(sizeof(node_t));
                    versamenti->val = preOvers;
                    versamenti->time = tiempo;
                    versamenti->next = NULL;
                }else{
                    push(&versamenti, preOvers, &tiempo);
                }
                f = fopen(path, "a");
                fprintf(f, "In data %d/%d/%d alle %d:%d:%d hai versato %d euro.\n", tiempo.tm_mday,
                        tiempo.tm_mon, tiempo.tm_year + 1900, tiempo.tm_hour, tiempo.tm_min,
                        tiempo.tm_sec, preOvers);
                contaVersamenti++;
                fclose(f);
                break;
            case 'm':
                printf("Scrivi se vuoi vedere i versamenti o i prelievi effettuati\n");
                scanf("%s",s);
                if(*s=='p'){
                    print_prelievi(prelievi);
                } else if(*s=='v'){
                    print_versamenti(versamenti);
                } else {
                    printf("Comando errato. Scrivi p versamenti o prelievi.\n");
                }
                break;
            case 'f':
                leggiFile(&f);
                break;
        }
    }while (s[0]!='e' && s[0]!='E');
    printf("Bancomat spento.");
    return 0;
}
