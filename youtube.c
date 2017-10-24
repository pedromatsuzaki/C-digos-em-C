#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>



    typedef struct youtube{

        char name[50];
        int views;
        int subscribes;

    }Youtube;

    // Cria��o das fun��es...

    int add(Youtube* youtuber, short int amount, short int i);
    int print(Youtube* youtuber, short int amount, short int i);
    int List(Youtube* youtuber, short int i, short int amount);



int main(){

    setlocale(LC_ALL,"portuguese");

    Youtube *youtuber;  // Ponteiro de uma struct...

    char name[50];
    short int amount = 0,option = 0,n = 0;
    int views = 0,subscribes = 0,i = 0;
    int tecla = NULL;

    while(1){

        printf("Quantos registros ser�o armazenados: ");
        fflush(stdin);
        scanf("%hi", &amount);

        if(amount <= 0){
            printf("\nA quantidade de registros n�o pode ser uma letra, menor ou igual a zero, tente outra vez !");
            printf("\n\n");
        }else{
            printf("\nA quantidade inserida � % hi. ", amount);
            printf("\nAloca��o de mem�ria realizada com sucesso !");
            break;
        }
    }

    if(youtuber == NULL){
            printf("\nErro na aloca��o de mem�ria, tente novamente ! ");
            return -1;
        }


    youtuber = (Youtube*)malloc(amount * sizeof(Youtube)); // Fun��o malloc... Sendo que Youtube � o tipo do dado e youtuber � o endere�o de mem�ria

    do{
    n++;
    printf("\n\n");
    printf("================================================================");
    printf("\nMenu de op��es: ");
    printf("\n<1> - Inserir um novo youtuber: ");
    printf("\n<2> -  Listar os youtubers cadastrados: ");
    printf("\n<3> - Liberar mem�ria e sair:\n ");
    scanf("%hi", &option);

    switch(option){

    case 1:
    add(youtuber,amount,i);  // Chamada da fun��o...
    print(youtuber,amount,i);  // Chamada de fun��o...
    i++;  // Sistema de controle do c�digo...

    break;

    case 2:
    List(youtuber,amount, i);   // Chamada de fun��o...
    break;

    case 3:
    free(youtuber);  // Fun��o exit...
    exit(0);
    break;

    default:printf("\nERRO !");  // Fun��o default caso a op��o escolhida seja inv�lida...

    }


    }while(1);


return 0;
}

    int add(Youtube* youtuber, short int amount, short int i){


        printf("\nQual o nome do canal no youtube:  ");
        fflush(stdin);
        fgets(youtuber[i].name,50,stdin);

        printf("Quantos views tem o canal: ");
        scanf("%d", &youtuber[i].views);

        printf("Quantos inscritos possui o canal: ");
        scanf("%d", &youtuber[i].subscribes);

    }

    int List(Youtube* youtuber, short int amount, short int i){  // Fun��o de listar os youtubers...

        short int p;

        for(p = 0;p < i;p++){
            print(youtuber,amount,p);  // Chamada da fun��o para printar os dados na tela...
        }

    }



    int print(Youtube* youtuber, short int amount, short int i){

        printf("\nDados do [%hi] youtuber: ",i + 1);
        printf("\nO nome do canal �: %s ", youtuber[i].name);
        printf("A quantidade de views � de: %d", youtuber[i].views);
        printf("\nA quntidade de inscritos � de: %d", youtuber[i].subscribes);
        printf("\n\n");

    }
