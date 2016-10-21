#include <stdio.h>
#include <stdlib.h>

//BATAILLE NAVALE AVEC FONCTIONS ET SAUVEGARDE, 2 MODES DE JEU

//djfhshfkdfkshf

void saisieDimMap(int* tailleX, int* tailleY){

    do{
        printf("choisir tailleX (minimum 15/maximum 50) : ");
        scanf("%d[0-9]", tailleX);
        fflush(stdin);
    }while(*tailleX < 15 || *tailleX > 50);


    do{
        printf("choisir tailleY (minimum 15/maximum 50: ");
        scanf("%d[0-9]", tailleY);
        fflush(stdin);
    }while(*tailleY < 15 || *tailleY > 50);
}

void remplissageMapIAvsIA(int tailleX, int tailleY, int mapJ1[tailleX][tailleY], int mapJ2[tailleX][tailleY]){
    int xJ1 = 0;
    int yJ1 = 0;
    int xJ2 = 0;
    int yJ2 = 0;
    int i = 0;
    int j = 0;
    int verif = 10;
    int placementbateaux =  0;

     for(i=1; i < 5;i++){
        do{
            verif = 1;
            xJ1 = doRand(0,tailleX);
            yJ1 = doRand(0,tailleY);
            placementbateaux = rand()%(2);

            for(j = 0; j < i; j++){
                if(placementbateaux == 0){
                    if(mapJ1[xJ1][yJ1 + j] != 0){
                        verif = 0;
                        break;
                    }
                }else if(placementbateaux == 1){
                    if(mapJ1[xJ1 + j][yJ1]){
                        verif = 0;
                    }
                }
            }
        }while(mapJ1[xJ1][yJ1] != 0 || tailleX - xJ1 < i || tailleY - yJ1 < i || verif == 0);

    for(j=0; j <  i; j++){

        if(placementbateaux == 0){
            mapJ1[xJ1][yJ1 + j] = i;
        }else if(placementbateaux == 1){
            mapJ1[xJ1 + j][yJ1] = i;
        }
    }
}

//
 for(i=1; i < 5;i++){
        do{
            verif = 1;
            xJ2 = doRand(0,tailleX);
            yJ2 = doRand(0,tailleY);
            placementbateaux = rand()%(2);

            for(j = 0; j < i; j++){
                if(placementbateaux == 0){
                    if(mapJ2[xJ2][yJ2+j] != 0){
                        verif = 0;
                        break;
                    }
                }else if(placementbateaux == 1){
                    if(mapJ2[xJ2+j][yJ2]){
                        verif = 0;
                    }
                }
            }
        }while(mapJ2[xJ2][yJ2] != 0 || xJ2 < i || tailleX - xJ2 < i || yJ2 < i || tailleY - yJ2 < i || verif == 0);

            for(j=0; j <  i; j++){

                if(placementbateaux == 0){
                    mapJ2[xJ2][yJ2 + j] = i;
                }else if(placementbateaux == 1){
                    mapJ2[xJ2 + j][yJ2] = i;
                }
            }
    }
}

void affichageMapIAvsIA(int tailleX, int tailleY, int mapJ1[tailleX][tailleY], int mapJ2[tailleX][tailleY]){

    int i = 0;
    int j = 0;

    for (i = 0; i < tailleX; i++){
        for (j = 0; j < tailleY; j++){
            printf("%d", mapJ1[i][j]);
            }
            printf("\n");
        }

    printf("\n\n");

    for(i = 0; i < tailleX; i++){
        for (j = 0; j < tailleY; j++){
            printf("%d", mapJ2[i][j]);
            }
            printf("\n");
        }
    printf("\n");
    printf("\n");
    getchar();
}

void affichageMapIAvsJoueur(int tailleX, int tailleY, int mapJ1[tailleX][tailleY], int mapJ2[tailleX][tailleY]){

    int i = 0;
    int j =0;

    for(i = 0; i < tailleX; i++){
        for (j = 0; j < tailleY; j++){
            printf("%d", mapJ2[i][j]);
            }
            printf("\n");
        }
    printf("\n");
    printf("\n");
    getchar();
}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}

void remplissageMapJoueurVsIA(int tailleX, int tailleY, int mapJ1[tailleX][tailleY], int mapJ2[tailleX][tailleY]){

int xJ1 = 0;
int yJ1 = 0;
int xJ2 = 0;
int yJ2 = 0;
int placementbateaux = 0;
int i = 0;
int j = 0;
int verif = 10;

for(i=1; i < 5;i++){
        do{
            verif = 1;
            xJ1 = doRand(0,tailleX);
            yJ1 = doRand(0,tailleY);
            placementbateaux = rand()%(2);

            for(j = 0; j < i; j++){
                if(placementbateaux == 0){
                    if(mapJ1[xJ1][yJ1+j] != 0){
                        verif = 0;
                        break;
                    }
                }else if(placementbateaux == 1){
                    if(mapJ1[xJ1+j][yJ1]){
                        verif = 0;
                    }
                }
            }
        }while(mapJ1[xJ1][yJ1] != 0 || xJ1 < i || tailleX - xJ1 < i || yJ1 < i || tailleY - yJ1 < i || verif == 0);

    for(j=0; j <  i; j++){

        if(placementbateaux == 0){
            mapJ1[xJ1][yJ1 + j] = i;
        }else if(placementbateaux == 1){
            mapJ1[xJ1+j][yJ1] = i;
        }
    }
}

for(i=1; i < 5;i++){
            do{
                verif = 1;
                printf("Choisir une coordonnée x et une coordonnée y pour placer le bateau %d (minimum a 4 cases de chaque bordure de la carte) \n", i);
                do{
                    printf("Coordonnée x : \n");
                    scanf("%d[0-9]", &xJ2);
                }while(xJ2 < 0 || xJ2 > tailleX);

                do{
                    printf("Coordonnée y : \n");
                    scanf("%d[0-9]", &yJ2);
                }while(yJ2 < 0 || yJ2 > tailleY);

                do{
                    printf("Choisir le type de placement du bateau (vertical : 0 / horizontal : 1) \n");
                    scanf("%d", &placementbateaux);
                }while(placementbateaux != 0 && placementbateaux != 1);

                for(j = 0; j < i; j++){
                if(placementbateaux == 0){
                    if(mapJ2[xJ2][yJ2+j] != 0){
                        verif = 0;
                        break;
                    }
                }else if(placementbateaux == 1){
                    if(mapJ2[xJ2+j][yJ2]){
                        verif = 0;
                    }
                }
            }

        }while(mapJ2[xJ2][yJ2] != 0 || xJ2 < i || tailleX - xJ2 < i || yJ2 < i || tailleY - yJ2 < i || verif == 0);

            for(j=0; j <  i; j++){

                if(placementbateaux == 0){
                    mapJ2[xJ2][yJ2 + j] = i;
                }else if(placementbateaux == 1){
                    mapJ2[xJ2+j][yJ2] = i;
                }
                }

    }
}

void attaquesIAvsIA(int tailleX, int tailleY, int mapJ1[tailleX][tailleY], int mapJ2[tailleX][tailleY]){

int positionX1 = 0;
int positionY1 = 0;
int positionX2 = 0;
int positionY2 = 0;
int scoreJ1 = 0;
int scoreJ2 = 0;

    do{
            do{
                positionX1=doRand(0,tailleX+1);
                positionY1=doRand(0,tailleY+1);
            }while(mapJ2[positionX1][positionY1] == 5 || mapJ2[positionX1][positionY1] == 6);

            if(mapJ2[positionX1][positionY1] == 1 || mapJ2[positionX1][positionY1] == 2 || mapJ2[positionX1][positionY1] == 3 ||
                    mapJ2[positionX1][positionY1] == 4){
                            mapJ2[positionX1][positionY1] = 5;
                            scoreJ1 = scoreJ1 + 1;
                            printf("J1 touche J2 en %d/%d \n", positionX1, positionY1 );
                            printf("Score J1 : %d/10 \n", scoreJ1);
                            }else if(mapJ2[positionX1][positionY1] == 0){
                                mapJ2[positionX1][positionY1] = 6;
                            }

            do{
                positionX2=doRand(0,tailleX+1);
                positionY2=doRand(0,tailleY+1);
            }while(mapJ1[positionX2][positionY2] == 5 || mapJ1[positionX2][positionY2] == 6);

            if(mapJ1[positionX2][positionY2] == 1 || mapJ1[positionX2][positionY2] == 2 || mapJ1[positionX2][positionY2] == 3 ||
                    mapJ1[positionX2][positionY2] == 4){
                            mapJ1[positionX2][positionY2] = 5;
                            scoreJ2 =  scoreJ2 + 1;
                            printf("J2 touche J1 en %d/%d \n", positionX2, positionY2 );
                            printf("Score J2 : %d/10 \n", scoreJ2);
                            }else if(mapJ1[positionX2][positionY2] == 0){
                                mapJ1[positionX2][positionY2] = 6;
                            }
    }while(scoreJ1 != 10 && scoreJ2 != 10);

    if(scoreJ1 == 10){
            printf(" GAME OVER ");
            printf("Le joueur 1 gagne !! \n");
        }else if(scoreJ2 == 10){
            printf(" GAME OVER ");
            printf("Le joueur 2 gagne !! \n");
        }

    getchar();
    affichageMapIAvsIA(tailleX, tailleY, mapJ1, mapJ2);
}

void attaquesJoueurVsIA(int tailleX, int tailleY, int mapJ1[tailleX][tailleY], int mapJ2[tailleX][tailleY]){

int positionX1 = 0;
int positionY1 = 0;
int positionX2 = 0;
int positionY2 = 0;
int scoreJ1 = 0;
int scoreJ2 = 0;


    do{
                do{
                    positionX1=doRand(0,tailleX+1);
                    positionY1=doRand(0,tailleY+1);
                }while(mapJ2[positionX1][positionY1] == 5 || mapJ2[positionX1][positionY1] == 6);

                if(mapJ2[positionX1][positionY1] == 1 || mapJ2[positionX1][positionY1] == 2 || mapJ2[positionX1][positionY1] == 3 ||
                        mapJ2[positionX1][positionY1] == 4){
                                mapJ2[positionX1][positionY1] = 5;
                                scoreJ1 = scoreJ1 + 1;
                                printf("IA touche JOUEUR en %d/%d \n", positionX1, positionY1 );
                                printf("Score IA : %d/10 \n", scoreJ1);
                                }else if(mapJ2[positionX1][positionY1] == 0){
                                    mapJ2[positionX1][positionY1] = 6;
                                    printf("IA echoue son tir \n");
                                }

            do{
                printf("Choisir des coordonnées x et y d'attaque \n");
                do{
                    printf("Coordonnée x : \n");
                    scanf("%d[0-9]", &positionX2);
                }while(positionX2 < 0 || positionX2 > tailleX);

                do{
                    printf("Coordonnée y : \n");
                    scanf("%d[0-9]", &positionY2);
                }while(positionY2 < 0 || positionY2 > tailleY);
            }while(mapJ1[positionX2][positionY2] == 5 || mapJ1[positionX2][positionY2] == 6);

            if(mapJ1[positionX2][positionY2] == 1 || mapJ1[positionX2][positionY2] == 2 || mapJ1[positionX2][positionY2] == 3 ||
                    mapJ1[positionX2][positionY2] == 4){
                            mapJ1[positionX2][positionY2] = 5;
                            scoreJ2 = scoreJ2 + 1;
                            printf("JOUEUR touche IA en %d/%d \n", positionX2, positionY2 );
                            printf("Score JOUEUR : %d/10 \n", scoreJ2);
                            }else if(mapJ1[positionX2][positionY2] == 0){
                                mapJ1[positionX2][positionY2] = 6;
                                printf("Joueur echoue son tir \n");
                            }
    }while(scoreJ1 != 10 && scoreJ2 != 10);

    if(scoreJ1 == 10){
            printf(" GAME OVER ");
            printf("Le joueur 1 gagne !! \n");
        }else if(scoreJ2 == 10){
            printf(" GAME OVER ");
            printf("Le joueur 2 gagne !! \n");
        }

    getchar();
    affichageMapIAvsIA(tailleX, tailleY, mapJ1, mapJ2);
}

int choixMode(int mode){
    do{
        printf("CHOIX MODE DE JEU \n");
        printf("MODE 1 : IA VS IA \n");
        printf("MODE 2 : IA VS JOUEUR \n");
        printf("Votre choix : (1 ou 2) \n");
        scanf("%d[1-2]", &mode);
    }while(mode != 1 && mode != 2);
return mode;
}

int main()
{
    int mapJ1[50][50] = {0};
    int mapJ2[50][50] = {0};
    int tailleX = 0;
    int tailleY = 0;
    int xJ1 = 0;
    int xJ2 = 0;
    int yJ1 = 0;
    int yJ2 = 0;
    int positionX1 = 0;
    int positionX2 = 0;
    int positionY1 = 0;
    int positionY2 = 0;
    int tailleBateau = 0;
    int mode = 0;
    int choix = 0;

    choix = choixMode(mode);
    saisieDimMap(&tailleX, &tailleY);
    if(choix == 1){
        remplissageMapIAvsIA(tailleX, tailleY, mapJ1, mapJ2);
        affichageMapIAvsIA(tailleX, tailleY, mapJ1, mapJ2);
        attaquesIAvsIA(tailleX, tailleY, mapJ1, mapJ2);
    }else if(choix == 2){
        remplissageMapJoueurVsIA(tailleX, tailleY, mapJ1, mapJ2);
        affichageMapIAvsJoueur(tailleX, tailleY, mapJ1, mapJ2);
        attaquesJoueurVsIA(tailleX, tailleY, mapJ1, mapJ2);
    }
    return 0;
}
