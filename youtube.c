#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>



    typedef struct youtube{

        char name[50];
        int views;
        int subscribes;

    }Youtube;

    // Criação das funções...

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

        printf("Quantos registros serão armazenados: ");
        fflush(stdin);
        scanf("%hi", &amount);

        if(amount <= 0){
            printf("\nA quantidade de registros não pode ser uma letra, menor ou igual a zero, tente outra vez !");
            printf("\n\n");
        }else{
            printf("\nA quantidade inserida é % hi. ", amount);
            printf("\nAlocação de memória realizada com sucesso !");
            break;
        }
    }

    if(youtuber == NULL){
            printf("\nErro na alocação de memória, tente novamente ! ");
            return -1;
        }


    youtuber = (Youtube*)malloc(amount * sizeof(Youtube)); // Função malloc... Sendo que Youtube é o tipo do dado e youtuber é o endereço de memória

    do{
    n++;
    printf("\n\n");
    printf("================================================================");
    printf("\nMenu de opções: ");
    printf("\n<1> - Inserir um novo youtuber: ");
    printf("\n<2> -  Listar os youtubers cadastrados: ");
    printf("\n<3> - Liberar memória e sair:\n ");
    scanf("%hi", &option);

    switch(option){

    case 1:
    add(youtuber,amount,i);  // Chamada da função...
    print(youtuber,amount,i);  // Chamada de função...
    i++;  // Sistema de controle do código...

    break;

    case 2:
    List(youtuber,amount, i);   // Chamada de função...
    break;

    case 3:
    free(youtuber);  // Função exit...
    exit(0);
    break;

    default:printf("\nERRO !");  // Função default caso a opção escolhida seja inválida...

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

    int List(Youtube* youtuber, short int amount, short int i){  // Função de listar os youtubers...

        short int p;

        for(p = 0;p < i;p++){
            print(youtuber,amount,p);  // Chamada da função para printar os dados na tela...
        }

    }



    int print(Youtube* youtuber, short int amount, short int i){

        printf("\nDados do [%hi] youtuber: ",i + 1);
        printf("\nO nome do canal é: %s ", youtuber[i].name);
        printf("A quantidade de views é de: %d", youtuber[i].views);
        printf("\nA quntidade de inscritos é de: %d", youtuber[i].subscribes);
        printf("\n\n");

    }
