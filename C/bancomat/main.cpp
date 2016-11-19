#include <stdio.h>
#include <time.h>
#include <cstdlib>

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

int main() {
    int conto = 10000;
    int preOvers = 0;
    int contaPrelievi = 0;
    int contaVersamenti = 0;

    node_t *prelievi;
    node_t *versamenti;

    printf("\nIl tuo conto è di %d euro\n", conto);
    printf("Scrivi se vuoi prelevare o versare danaro\n");
    printf("Scrivi movimenti se vuoi vedere i movimenti effettuati\n");
    printf("Scrivi exit se vuoi chiudere il bancomat\n");
    printf("ATTENZIONE: puoi inserire soltanto numeri interi\n");
    for(int i = 0; 1!=0; i++){

        if(i!=0){
            printf("Ora il tuo conto è %d\n", conto);
            printf("Prelevare o versare?\n");
            printf("Digita movimenti se vuoi visulizzarli\n");
        }

        time_t t = time(NULL);
        struct tm tiempo = *localtime(&t);

        char *s = (char*) malloc( 100 );
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
                contaPrelievi++;
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
                contaVersamenti++;
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
            case 'e':
                printf("Bancomat spento.");
                return 0;
        }
    }
}
