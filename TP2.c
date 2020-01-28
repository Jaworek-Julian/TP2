#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct perso_s{
    int hp;
    int mp;
    int atq;
    int atqSpe;

    int exp;
    int lvl;

    int action; // 0 = ne rien faire, 1 = attaquer, 2=se défendre, 3=attaque spéciale
    int statu; // Permetra aux ennemis d'être empoisonner
    int target; // Focus du personnage
    int id; // Chiffre permettant d'identifier chaques personnages (ser uniquement pour la fonction targetName)
} perso_t;

perso_t perso1;
perso_t perso2;
perso_t perso3;
perso_t perso4;
perso_t monstre1;
perso_t monstre2;
perso_t monstre3;
perso_t monstre4;
perso_t boss;

// On utilise des pinteurs pour faciliter la
perso_t * getPerso(int index){
    switch (index) {
    case 1:
        return &perso1;
        break;
    case 2:
        return &perso2;
        break;
    case 3:
        return &perso3;
        break;
    case 4:
        return &perso4;
        break;
    default:
        return &monstre1;
        break;
    case 5:
        return &monstre2;
        break;
    case 6:
        return &monstre3;
        break;
    case 7:
        return &monstre4;
        break;
    case 8:
        return &boss;
        break;
    }
}

int main(){

    perso1.hp = 100;
    perso1.mp = 10;
    perso1.atq = 25;
    perso1.atqSpe = 5;
    perso1.exp = 0;
    perso1.lvl = 1;
    perso1.action = 0;
    perso1.id = 1;
    perso1.target ;


    perso2.hp     =100;
    perso2.mp     =100;
    perso2.atq    = 15;
    perso2.atqSpe = 35;  // Fireball
    perso2.exp = 0;
    perso2.lvl = 1;
    perso2.action = 0;
    perso2.id = 2;
    perso2.target;

    perso3.hp     =100;
    perso3.mp     =50;
    perso3.atq    =15;
    perso3.atqSpe = 40;  // Heal
    perso3.exp = 0;
    perso3.lvl = 1;
    perso3.action = 0;
    perso3.target;
    perso3.id = 3;

    perso4.hp     =100;
    perso4.mp     = 50;
    perso4.atq    =25;
    perso4.atqSpe = 15;  // Athenaarrow
    perso4.exp = 0;
    perso4.lvl = 1;
    perso4.action = 0;
    perso4.id = 4;
    perso4.target;


    monstre1.hp   =100;
    monstre1.mp   =30;
    monstre1.atq  =25;
    monstre1.action = 0;
    monstre1.id = 5;
    monstre1.target;



    monstre2.hp   =100;
    monstre2.mp   =30;
    monstre2.atq  =25;
    monstre2.action = 0;
    monstre2.id = 6;
    monstre2.target;


    monstre3.hp   =100;
    monstre3.mp   =30;
    monstre3.atq  =25;
    monstre3.action = 0;
    monstre3.id = 7;
    monstre3.target;



    monstre4.hp   =100;
    monstre4.mp   =30;
    monstre4.atq  =25;
    monstre4.action = 0;
    monstre4.id = 8;
    monstre4.target;




    boss.hp     =200;
    boss.mp     = 60;
    boss.atq    =400;
    boss.atqSpe =50;  //Armagedon
    boss.action;
    boss.statu = 0; // Poison cumulable, se prend 1 fois les dégats de l'attauqe spé par stack
    boss.target;
    boss.id = 9;

    int nbennemis = 0;

    int nbLife = 4;
    int bossLife = 1;
    int action1;
    int focus1;
    int action2;
    int action3;
    int action4;

    int bossaction;
    int bossfocus;
    int targetAlive;
    int monsterLife = 4;




    while (perso1.lvl != 10){







        printf("quels monstres voulez vous affronter?\n1: un Boss\n2: un groupe de monstre\n");
        scanf("%d",&nbennemis);




        if (nbennemis == 1){
            while (nbLife > 1 || boss.hp >= 0){

                nbLife = 4;

                // résumé
                printf("Twingo a %d HP / %d MP\n", perso1.hp, perso1.mp);
                printf("BMW a %d HP / %d MP\n", perso2.hp, perso2.mp);
                printf("Audi a %d HP / %d MP\n", perso3.hp, perso3.mp);
                printf("Merco a %d HP / %d MP\n", perso4.hp, perso4.mp);
                printf("Boss a %d HP / %d MP\n", boss.hp, boss.mp);



                // Actions du joueur
    //---------------------------------------------------------------------------------------
                if (perso1.hp > 0){
                    printf("TOUR DE TWINGO\n1:attaque\n2:defendre\n3:empoisonner\n");
                    scanf("%d",&action1);
                }
    //---------------------------------------------------------------------------------------
                if (perso2.hp > 0){
                    printf("TOUR DE BMW\n1:attaque\n2:defendre\n3:fireball (33 MP)\n");
                    scanf("%d",&action2);
                }
    //---------------------------------------------------------------------------------------
                if (perso3.hp > 0){
                    printf("TOUR DE Audi\n1:attaque\n2:defendre\n3:heal (25 MP)\n");
                    scanf("%d",&action3);

                // Condition si le joueur décide de soigner
                    if (action3 == 3){
                        printf("Quel personnage voulez-vous soignez?\n1: Twingo\n2: BMW\n3: Audi\n4: Merco");
                        scanf("%d",&perso3.target);
                    }
                }
    //---------------------------------------------------------------------------------------
                if (perso4.hp > 0){
                    printf("TOUR DE Merco\n1:attaque\n2:defendre\n3:athenaarrow (20 MP)\n");
                    scanf("%d",&action4);
                }

                // Défini la cible du heal
                perso_t * heal = getPerso(perso3.target);


                // Rand for the boss attack
                time_t t;
                srand((unsigned) time(&t));


                boss.action = rand()%3+1;
                boss.target = rand()%4+1;

                printf("le rand : %d     %d\n",boss.action,boss.target);

                // Transforme la variable perso en pointeur
                perso_t * perso = getPerso(boss.target)
                ;
                // A partir de là, nous utilisons les pointeurs, les . sont donc remplacer par des -> lorsqu'on utilise la variable perso

                //condition si la cible du boss est en vie ou non

                while (targetAlive != 1)
                {
                    perso = getPerso(boss.target);
                    if (perso->hp <= 0)
                    {
                        boss.target = rand() % 4 + 1;
                    }
                    else
                    {
                        targetAlive = 1;
                    }
                }
                targetAlive = 0;
                //fin condition ----------------------------------


                    // Action du Bos --------------------------------
                if (boss.action == 2){
                    printf("le Boss se defend\n");
                }

                if (boss.action == 1){

                    if (perso->action == 2){
                        perso->hp -= (boss.atq/4);
                        printf("le boss attaque et inflige %d degats\n",(boss.atq/4));
                    }
                    else{

                        perso->hp -= boss.atq;
                        printf("et lui inflige %d degats\n",boss.atq);
                    }


                }
                if (boss.action == 3 && boss.mp >= 30){
                    boss.mp -= 30;
                        if (perso->action == 2){
                            perso->hp -=  (boss.atqSpe/4);
                        }
                        else{
                            perso->hp -= boss.atqSpe;
                            printf("ATTAUQE SPECIALE il reste %d hp",perso->hp);
                        }
                }else if (boss.action == 3){
                        printf("the boss need more mana\n");
                }

                    // Fin action du Bos --------------------------------



                //1st character----------------------------------------------------

                if (perso1.hp > 0){

                    if (action1 == 1){
                        if (boss.action == 2){
                            boss.hp -= (perso1.atq/4);
                            printf("Twingo attaque, il a fait %d de degat au Boss\n",(perso1.atq/4));
                        }
                        else{
                            boss.hp -= perso1.atq;
                            printf("Twingo attaque, il a fait %d de degat au Boss\n",perso1.atq);
                        }
                    if (action1 == 2){
                        printf("Twingo se défend\n");
                        }
                    }
                    if (action1 == 3 && perso1.mp >= 10){
                            boss.statu += 1;
                            perso1.mp -= 10;
                            printf("Twingo à empoisonner le Boss\n");
                    }
                    else if (perso1.mp < 10 ){
                        printf("il faut plus de mana à Twingo\n");
                    }

                }else{
                    printf("Twingo est mort\n");
                }

                // End 1st character

                //2nd character----------------------------------------------------

                if (perso2.hp > 0){
                    if (action2 == 1){
                        if (boss.action == 2){
                            boss.hp -= (perso2.atq/4);
                            printf("BMW attaque, il a fait %d de degat au Boss\n",(perso2.atq/4));
                        }
                        else{
                            boss.hp -= perso2.atq;
                            printf("BMW attaque, il a fait %d de degat au Boss\n",perso2.atq);
                        }
                    }
                    if (action2 == 2){
                        printf("BMW se défend\n");
                        }
                    if (action2 == 3 && perso2.mp >= 10){
                            boss.hp -= perso2.atqSpe;
                            perso2.mp -= 33;
                            printf("BMW utilise fireball, le Boss perd %d hp\n",perso2.atqSpe);
                    }
                    else if (perso2.mp < 10 ){
                        printf("il faut plus de mana à BMW\n");
                    }
                }else{
                    printf("BMW est mort\n");
                }

                // End 2nd character

                // 3th character----------------------------------------------------

                if (perso3.hp > 0){
                    if (action3 == 1){
                        if (boss.action == 2){
                            boss.hp -= (perso3.atq/4);
                            printf("Audi attaque, il a fait %d de degat au Boss\n",(perso3.atq/4));
                        }
                        else{
                            boss.hp -= perso3.atq;
                            printf("Audi attaque, il a fait %d de degat au Boss\n",perso3.atq);
                        }
                    }
                    if (action3 == 2){
                        printf("Audi se defend\n");
                        }
                    if (action3 == 3 && perso3.mp >= 10){
                            heal->hp += perso3.atqSpe;
                            perso3.mp -= 25;
                            printf("Audi utilise soigne %d points de degats\n",perso3.atqSpe);
                    }
                    else if (perso3.mp < 10 ){
                        printf("il faut plus de mana à Audi\n");
                    }
                }else{
                    printf("Audi est mort\n");
                }

                // End 3th character


                //4th character----------------------------------------------------

                if (perso4.hp > 0){
                    if (action4 == 1){
                        if (boss.action == 2){
                            boss.hp -= (perso4.atq/4);
                            printf("Merco attaque, il a fait %d de degat au Boss\n",(perso4.atq/4));
                        }
                        else{
                            boss.hp -= perso4.atq;
                            printf("Merco attaque, il a fait %d de degat au Boss\n",perso4.atq);
                        }
                    if (action4 == 2){
                        printf("Merco se defend\n");
                        }
                    }
                    if (action4 == 3 && perso4.mp >= 10){
                            boss.hp -= perso4.atqSpe;
                            perso4.mp -= 20
                            ;
                            printf("Merco utilise athenaarrow et inflige %d points de degats\n",perso3.atqSpe);
                    }
                    else if (perso4.mp < 10 ){
                        printf("il faut plus de mana à Merco\n");
                    }
                }else{
                    printf("Merco est mort\n");
                }

                // End 4th character


    printf("FIN DE TOUR -----------------\n\n\n",perso->hp);



                    if (perso1.hp <= 0){
                    nbLife -= 1;
                    }
                    if (perso2.hp <= 0){
                    nbLife -= 1;
                    }
                    if (perso3.hp <= 0){
                        nbLife -= 1;
                    }
                    if (perso4.hp <= 0){
                        nbLife -= 1;
                    }

                    printf("%d\n",nbLife);


                boss.hp -= (perso1.atqSpe*boss.statu);




            }

            if (boss.hp <= 0){
                printf("Félicitation, vous avez battus le boss, vous gagnez 100 px\n");
                perso1.exp += 100;
                perso2.exp += 100;
                perso3.exp += 100;
                perso4.exp += 100;
            }else{
                printf("VOUS ETES MORTS");
            }



            if (perso1.exp >= 100){

                perso1.lvl += 1;
                perso2.lvl += 1;
                perso3.lvl += 1;
                perso4.lvl += 1;

                perso1.mp = 5;
                perso1.atq += 3;
                perso1.atqSpe += 1;

                perso2.mp = 10;
                perso2.atq += 2;
                perso2.atqSpe += 5;

                perso3.mp += 5;
                perso3.atq += 2;
                perso3.atqSpe += 5;

                perso4.mp += 3;
                perso4.atq += 3;
                perso4.atqSpe += 3;

                perso1.exp = 0;
                perso2.exp = 0;
                perso3.exp = 0;
                perso4.exp = 0;
            }


            perso1.hp = 100;
            perso2.hp = 100;
            perso3.hp = 100;
            perso4.hp = 100;
            boss.hp = 200;


        }

    // Fin de la boucle combat contre le Boss


























    if (nbennemis == 2){
            while (nbLife > 0 || monsterLife > 0){

                    nbLife = 4;
                    monsterLife = 4;


                printf("Twingo a %d HP / %d MP\n", perso1.hp, perso1.mp);
                printf("BMW a %d HP / %d MP\n", perso2.hp, perso2.mp);
                printf("Audi a %d HP / %d MP\n", perso3.hp, perso3.mp);
                printf("Merco a %d HP / %d MP\n", perso4.hp, perso4.mp);
                printf("Montre1 a %d HP / %d MP\n", monstre1.hp, boss.mp);
                printf("Montre2 a %d HP / %d MP\n", monstre2.hp, boss.mp);
                printf("Montre3 a %d HP / %d MP\n", monstre3.hp, boss.mp);
                printf("Montre4 a %d HP / %d MP\n", monstre4.hp, boss.mp);



                // Actions du joueur
    //---------------------------------------------------------------------------------------
                if (perso1.hp > 0){
                    printf("TOUR DE TWINGO\n1:attaque\n2:defendre\n3:empoisonner\n");
                    scanf("%d",&action1);
                    if (action1 == 1 || action1 == 3){
                        printf("Quel ennemis voulez-vous cibler?\n5: Montre1\n6: Monstre2\n7: Monstre3\n8: Monstre4\n");
                        scanf("%d",&perso1.target);
                    }
                }
    //---------------------------------------------------------------------------------------
                if (perso2.hp > 0){
                    printf("TOUR DE BMW\n1:attaque\n2:defendre\n3:fireball (33 MP)\n");
                    scanf("%d",&action2);
                    if (action2 == 1 || action2 == 3){
                        printf("Quel ennemis voulez-vous cibler?\n5: Montre1\n6: Monstre2\n7: Monstre3\n8: Monstre4\n");
                        scanf("%d",&perso2.target);
                    }
                }
    //---------------------------------------------------------------------------------------
                if (perso3.hp > 0){
                    printf("TOUR DE Audi\n1:attaque\n2:defendre\n3:heal (25 MP)\n");
                    scanf("%d",&action3);
                    if (action3 == 1 || action3 == 3){
                        printf("Quel ennemis voulez-vous cibler?\n5: Montre1\n6: Monstre2\n7: Monstre3\n8: Monstre4\n");
                        scanf("%d",&perso3.target);
                    }else if (action3 == 3){
                        printf("Quel personnage voulez-vous soignez?\n1: Twingo\n2: BMW\n3: Audi\n4: Merco\n");
                        scanf("%d",&perso3.target);
                    }
                }
    //---------------------------------------------------------------------------------------
                if (perso4.hp > 0){
                    printf("TOUR DE Merco\n1:attaque\n2:defendre\n3:athenaarrow (20 MP)\n");
                    scanf("%d",&action4);
                    if (action4 == 1){
                        printf("Quel ennemis voulez-vous cibler?\n5: Montre1\n6: Monstre2\n7: Monstre3\n8: Monstre4\n");
                        scanf("%d",&perso4.target);
                    }
                }


                // Défini la cible des personnages
                perso_t * perso1target = getPerso(perso1.target);
                perso_t * perso2target = getPerso(perso2.target);
                perso_t * perso3target = getPerso(perso3.target);
                perso_t * perso4target = getPerso(perso4.target);


                // Rand Seed
                time_t t;
                srand((unsigned) time(&t));

                // Défini les actions des monstres (aléatoires)
                monstre1.action = rand()%2+1;
                monstre2.action = rand()%2+1;
                monstre3.action = rand()%2+1;
                monstre4.action = rand()%2+1;

                // Défini la cible des monstres
                monstre1.target = rand()%4+1;
                monstre2.target = rand()%4+1;
                monstre3.target = rand()%4+1;
                monstre4.target = rand()%4+1;

                // Transforme la variable perso en pointeur
                perso_t * monstre1target = getPerso(monstre1.target);
                perso_t * monstre2target = getPerso(monstre2.target);
                perso_t * monstre3target = getPerso(monstre3.target);
                perso_t * monstre4target = getPerso(monstre4.target);

                ;
                // A partir de là, nous utilisons les pointeurs, les . sont donc remplacer par des -> lorsqu'on utilise la variable perso


                //condition si la cible est en vie ou non
                while (targetAlive != 1)
                {
                    monstre1target = getPerso(monstre1.target);
                    if (monstre1target->hp <= 0)
                    {
                        monstre1.target = rand() % 4 + 1;
                    }
                    else
                    {
                        targetAlive = 1;
                    }
                }
                targetAlive = 0;
                //fin condition ----------------------------------

                // Monstre 1 ----------------------------------------------
                if (monstre1.hp > 0){
                    if (monstre1.action == 2){
                        printf("le Monstre1 se defend\n");
                    }

                    if (monstre1.action == 1){

                        if (monstre1target->action == 2){
                            monstre1target->hp -= (monstre1.atq/4);
                            printf("le Monstre1 attaque et inflige %d degats\n",(monstre1.atq/4));
                        }
                        else{

                            monstre1target->hp -= monstre1.atq;
                            printf("et lui inflige %d degats\n",monstre1.atq);
                        }
                    }
                }
                // Fin Monstre 1 ----------------------------------------------



                //1st character----------------------------------------------------

                if (perso1.hp > 0){

                    if (action1 == 1){
                        if (perso1target->action == 2){
                            perso1target->hp -= (perso1.atq/4);
                            printf("Twingo attaque, il a fait %d de degat au Monstre\n",(perso1.atq/4));
                        }
                        else{
                            perso1target->hp -= perso1.atq;
                            printf("Twingo attaque, il a fait %d de degat au Monstre\n",perso1.atq);
                        }
                    if (action1 == 2){
                        printf("Twingo se défend\n");
                        }
                    }
                    if (action1 == 3 && perso1.mp >= 10){
                            perso1target->statu += 1;
                            perso1.mp -= 10;
                            printf("Twingo à empoisonner le Monstre\n");
                    }
                    else if (perso1.mp < 10 ){
                        printf("il faut plus de mana à Twingo\n");
                    }

                }

                // End 1st character




                // Monstre 2 ----------------------------------------------

                //condition si la cible est en vie ou non
                while (targetAlive != 1)
                {
                    monstre2target = getPerso(monstre2.target);
                    if (monstre2target->hp <= 0)
                    {
                        monstre2.target = rand() % 4 + 1;
                    }
                    else
                    {
                        targetAlive = 1;
                    }
                }
                targetAlive = 0;
                //fin condition ----------------------------------

                if (monstre2.hp > 0){
                    if (monstre2.action == 2){
                        printf("le Monstre1 se defend\n");
                    }

                    if (monstre2.action == 1){

                        if (monstre2target->action == 2){
                            monstre2target->hp -= (monstre2.atq/4);
                            printf("le Monstre2 attaque et inflige %d degats\n",(monstre2.atq/4));
                        }
                        else{

                            monstre2target->hp -= monstre2.atq;
                            printf("et lui inflige %d degats\n",monstre2.atq);
                        }
                    }
                }


                // End Monstre 2 --------------------------------------------------







                //2nd character----------------------------------------------------

                if (perso2.hp > 0){
                    if (action2 == 1){
                        if (perso2target->action == 2){
                            perso2target->hp -= (perso2.atq/4);
                            printf("BMW attaque, il a fait %d de degat au Monstre\n",(perso2.atq/4));
                        }
                        else{
                            perso2target->hp -= perso2.atq;
                            printf("BMW attaque, il a fait %d de degat au Monstre\n",perso2.atq);
                        }
                    if (action2 == 2){
                        printf("BMW se défend\n");
                        }
                    if (action2 == 3 && perso2.mp >= 10){
                            perso2target->hp -= perso2.atqSpe;
                            perso2.mp -= 33;
                            printf("BMW utilise fireball, le Monstre perd %d hp\n",perso2.atqSpe);
                        }
                    else if (perso2.mp < 10 ){
                        printf("il faut plus de mana à BMW\n");
                        }
                    }
                }

                // End 2nd character ----------------------------------------------




                // Monstre 3 ----------------------------------------------

                //condition si la cible est en vie ou non
                while (targetAlive != 1)
                {
                    monstre3target = getPerso(monstre3.target);
                    if (monstre3target->hp <= 0)
                    {
                        monstre3.target = rand() % 4 + 1;
                    }
                    else
                    {
                        targetAlive = 1;
                    }
                }
                targetAlive = 0;
                //fin condition ----------------------------------


                if (monstre3.hp > 0){
                    if (monstre3.action == 2){
                        printf("le Monstre1 se defend\n");
                    }

                    if (monstre3.action == 1){

                        if (monstre3target->action == 2){
                            monstre3target->hp -= (monstre3.atq/4);
                            printf("le Monstre3 attaque et inflige %d degats\n",(monstre3.atq/4));
                        }
                        else{

                            monstre3target->hp -= monstre3.atq;
                            printf("et lui inflige %d degats\n",monstre3.atq);
                        }
                    }
                }


                // End Monstre 3 --------------------------------------------------






                // 3th character----------------------------------------------------

                if (perso3.hp > 0){
                    if (action3 == 1){
                        if (perso3target->action == 2){
                            perso3target->hp -= (perso3.atq/4);
                            printf("Audi attaque, il a fait %d de degat au Monstre\n",(perso3.atq/4));
                        }
                        else{
                            perso3target->hp -= perso3.atq;
                            printf("Audi attaque, il a fait %d de degat au Monstre\n",perso3.atq);
                        }
                    }
                    if (action3 == 2){
                        printf("Audi se defend\n");
                        }
                    if (action3 == 3 && perso3.mp >= 10){
                            perso3target->hp += perso3.atqSpe;
                            perso3.mp -= 25;
                            printf("Audi utilise soigne %d points de degats\n",perso3.atqSpe);
                    }
                    else if (perso3.mp < 10 ){
                        printf("il faut plus de mana à Audi\n");
                    }
                }

                // End 3th character


                // Monstre 4 ----------------------------------------------

                //condition si la cible est en vie ou non
                while (targetAlive != 1)
                {
                    monstre4target = getPerso(monstre4.target);
                    if (monstre4target->hp <= 0)
                    {
                        monstre4.target = rand() % 4 + 1;
                    }
                    else
                    {
                        targetAlive = 1;
                    }
                }
                targetAlive = 0;
                //fin condition ----------------------------------



                if (monstre4.hp > 0){
                    if (monstre4.action == 2){
                        printf("le Monstre1 se defend\n");
                    }

                    if (monstre4.action == 1){

                        if (monstre4target->action == 2){
                            monstre4target->hp -= (monstre4.atq/4);
                            printf("le Monstre4 attaque et inflige %d degats\n",(monstre4.atq/4));
                        }
                        else{

                            monstre4target->hp -= monstre4.atq;
                            printf("et lui inflige %d degats\n",monstre4.atq);
                        }
                    }
                }


                // End Monstre 4 --------------------------------------------------



                //4th character----------------------------------------------------

                if (perso4.hp > 0){
                    if (action4 == 1){
                        if (perso4target->action == 2){
                            perso4target->hp -= (perso4.atq/4);
                            printf("Merco attaque, il a fait %d de degat au Monstre\n",(perso4.atq/4));
                        }
                        else{
                            perso4target->hp -= perso4.atq;
                            printf("Merco attaque, il a fait %d de degat au Monstre\n",perso4.atq);
                        }
                    if (action4 == 2){
                        printf("Merco se defend\n");
                        }
                    }
                    if (action4 == 3 && perso4.mp >= 10){
                            monstre1.hp -= perso4.atqSpe;
                            monstre2.hp -= perso4.atqSpe;
                            monstre3.hp -= perso4.atqSpe;
                            monstre4.hp -= perso4.atqSpe;
                            perso4.mp -= 20;
                            printf("Merco utilise athenaarrow et inflige %d points de degats\n",perso3.atqSpe);
                    }
                    else if (perso4.mp < 10 ){
                        printf("il faut plus de mana à Merco\n");
                    }
                }

                // End 4th character


    printf("FIN DE TOUR -----------------\n\n\n");

                 // Calcul des vies des personnages

                if (perso1.hp < 0){
                    nbLife = nbLife - 1;
                }
                if (perso2.hp < 0){
                    nbLife = nbLife - 1;
                }
                if (perso3.hp < 0){
                    nbLife = nbLife - 1;
                }
                if (perso4.hp < 0){
                    nbLife = nbLife - 1;
                }


                // Calcul des vies des monstres

                if (monstre1.hp < 0){
                    nbLife = nbLife - 1;
                }
                if (monstre2.hp < 0){
                    nbLife = nbLife - 1;
                }
                if (monstre3.hp < 0){
                    nbLife = nbLife - 1;
                }
                if (monstre4.hp < 0){
                    nbLife = nbLife - 1;
                }

                // Dégats du poison
                monstre1.hp -= (perso1.atqSpe*monstre1.statu);
                monstre2.hp -= (perso1.atqSpe*monstre2.statu);
                monstre3.hp -= (perso1.atqSpe*monstre3.statu);
                monstre4.hp -= (perso1.atqSpe*monstre4.statu);



            }

            if (monsterLife <= 0){
                printf("Félicitation, vous avez battus les monstres, vous gagnez 100 px\n");
                perso1.exp += 25;
                perso2.exp += 25;
                perso3.exp += 25;
                perso4.exp += 25;
            }else{
                printf("VOUS ETES MORTS");
            }



            if (perso1.exp >= 100){

                perso1.lvl += 1;
                perso2.lvl += 1;
                perso3.lvl += 1;
                perso4.lvl += 1;

                perso1.mp = 5;
                perso1.atq += 3;
                perso1.atqSpe += 1;

                perso2.mp = 10;
                perso2.atq += 2;
                perso2.atqSpe += 5;

                perso3.mp += 5;
                perso3.atq += 2;
                perso3.atqSpe += 5;

                perso4.mp += 3;
                perso4.atq += 3;
                perso4.atqSpe += 3;

                perso1.exp = 0;
                perso2.exp = 0;
                perso3.exp = 0;
                perso4.exp = 0;
            }


            perso1.hp = 100;
            perso2.hp = 100;
            perso3.hp = 100;
            perso4.hp = 100;


            }

        }

}

















