//NOME:PEDRO DIAS DOS SANTOS
//TURMA:ES21
//O QUE FAZ -> SIMULA UM JOGO DE RPG ENTRE DOIS PERSONAGENS ESCOLHIDOS PELO USUÁRIO DENTRE 3 CLASSES DE HÉROIS POSSÍVES

#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>

    typedef enum class{

        MAGE,
        ARCHER,
        DWARF
    }typeClass;

    typedef struct hero {

    char name[50];
    int hp;              // vida do personagem
    int strength;        // força do personagem
    int spell;          // ataque do personagem
    typeClass heroes;  // pertencente a enum class...

    }Hero;     // nome dado para identificar minha função

    Hero dataBattles();              // dados dos personagens
    float randomNumber();           // Número randômico
    void roundHeroes(Hero hero1);  // Round entre os personagens
    float damageHero();            // Dano que o héroi pode dar
    float roundBattle();           // batalha entre os personagens


int main(){

    int score1 = 0,score2 = 0;
    short int i;

    setlocale(LC_ALL,"portuguese");

    Hero hero1,hero2;

    srand(time(NULL));          // semente do número randômico, NULL serve para não "congelar o tempo"...

    printf("JOGADOR 1\n");
    hero1 = dataBattles();
    printf("\n\nJOGADOR 2\n");
    hero2 = dataBattles();

    for(i = 1;i < 4;i++){

        if(roundBattle(hero1,hero2) == 1){

            printf("\n\n===================================================\n\n");
            printf("O jogador 2, %s, ganhou o round %hi. ", hero2.name , i);
            printf("\n\n===================================================");
            score1++;
        }else{

            printf("\n\n===================================================\n\n");
            printf("O jogador 1, %s, ganhou o round %hi. ", hero1.name , i);
            printf("\n\n===================================================");
            score2++;
        }
        Sleep(1500);

    }

       if(score1 > score2){
            printf("\n\nO vencedor geral dos rounds foi %s !\n", hero2.name);
       }

       if(score1 < score2){
            printf("\n\nO vencedor geral dos rounds foi %s !\n", hero1.name);
       }

return 0;
}

    Hero dataBattles(Hero hero1){  // função para recolher os dados dos personagens(vida, força, ataque e a classe a que pertence)...

            printf("\nInforme o nome do personagem: ");
            fflush(stdin);
            fgets(hero1.name,50,stdin);

            if(hero1.name[strlen(hero1.name) -1] == '\n')     // O strlen possibilita a manipulção da posição do vetor
                hero1.name[strlen(hero1.name) -1] = '\0';

            while(1){

                    printf("\nEscolha a classe do personagem: ");
                    printf("\n<0> - Mago ");
                    printf("\n<1> - Arqueiro ");
                    printf("\n<2> - Anão\n");
                    scanf("%d", &hero1.heroes);

                    if(hero1.heroes != 0 && hero1.heroes != 1 && hero1.heroes != 2){

                        printf("\nOpção inváida, tente novamente !");

                    }else{

                        break;
                    }
            }

             if(hero1.heroes == MAGE){

                printf("\nO personagem escolhido foi o mago e seu nome é %s. \n", hero1.name);

            }
            if(hero1.heroes == ARCHER){

                printf("\nO personagem escolhido foi o arqueiro e seu nome é %s. \n", hero1.name);

            }
            if(hero1.heroes == DWARF){

                printf("\nO personagem escolhido foi o anão e seu nome é %s. \n", hero1.name);
            }

            while(1){

                    printf("\nInforme a vida do personagem escolhido: ");
                    scanf("%d", &hero1.hp);

                    if(hero1.hp > 49 && hero1.hp < 101){

                        break;

                    }else{

                        printf("\nValor inválido !");
                        printf("\n\nValores aceitos somente entre 50 e 100.\n");
                    }
            }


                while(1){

                    printf("\nInforme o valor de ataque do personagem: ");
                    scanf("%d", &hero1.spell);

                    if(hero1.spell > 49 && hero1.spell < 101){

                        break;

                    }else{

                        printf("\nVALOR INVÁLIDO !");
                        printf("\n\nValores aceitos somente entre 50 e 100.\n");

                    }
                }

                while(1){

                    printf("\nInforme o valor da força do personagem: ");
                    scanf("%d", &hero1.strength);

                    if(hero1.strength > 49 && hero1.strength < 101){

                        break;

                    }else{

                        printf("\nVALOR INVÁLIDO !");
                        printf("\n\nValores aceitos somente entre 50 e 100.\n");
                    }
                }

                return hero1;
    }

    float randomNumber(){              // Função para calcular o número randômico

        float x;
        x =  ((rand() % 30) + 10);
        x = x/100;
        return x;
    }

    void roundHeroes(Hero hero1){        // função identificar o vencedor e a vida restante do personagem

        printf("\nNome do personagem: %s", hero1.name);
        printf("\nVida do personagem: %d", hero1.hp);

   }
    float damageHero(Hero hero){        // função para calcular o tanto de dano que o personagem produz

        int bonus;

        switch(hero.heroes){

        case MAGE:
            bonus = 3;
            break;

        case ARCHER:
            bonus = 2;
            break;

        case DWARF:
            bonus = 5;
            break;

        }

        return ((hero.strength + hero.spell)/2 + bonus)*randomNumber();

    }

    float roundBattle(Hero hero1,Hero hero2){        // função para simular as batalhas

        float damage;

        while(1){
                 if(hero1.hp > 0){

                    damage = damageHero(hero1);
                    printf("\n\nDano recebido: %f", damage);
                    hero2.hp -= damage;
                    roundHeroes(hero2);
                 }
                 if(hero1.hp <= 0){
                     break;
                 }
                 Sleep(1500);

                if(hero2.hp > 0){

                    damage = damageHero(hero2);
                    printf("\n\nDano recebido: %f", damage);
                    hero1.hp -= damage;
                    roundHeroes(hero1);
                }

                if(hero2.hp <= 0){
                    break;
                }

        }

                if(hero1.hp <= 0){
                    return 1;
                }
                if(hero2.hp <= 0){
                    return 2;
                }

        }



