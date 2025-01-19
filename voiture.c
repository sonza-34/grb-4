#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "voiture.h"

void saisirNom(){
 char nom[20];
 printf("donner votre nom : ");scanf("%s",nom);
 printf("bien venu %s , choisir le choix qui tu veux \n\n",nom);
}

void ajouterVoiture(){
int idV;
voiture v;
int trouve=0;
 f=fopen("voiture.csv","a+");
 if(f==NULL){
    printf("erreur d'overteur");
 }
 printf("donner id de voiture :");scanf("%d",&idV);
 while(!feof(f)){
    fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible);
    if(idV==v.id){
        trouve=1;
        break;
    }
 }
    if(trouve==1){
        printf("voiture existe deja");
    }
    else{
        printf("donner marque de voiture : ");scanf("%s",v.marque);
        printf("donner modele de voiture : ");scanf("%s",v.modele);
        printf("donner carburant de voiture : ");scanf("%s",v.carburant);
        printf("donner transmission de voiture : ");scanf("%s",v.transmission);
        printf("donner nombre de places de voiture : ");scanf("%d",&v.nbrPlaces);
        printf("donner prix par jour de voiture : ");scanf("%f",&v.prixJour);
        printf("donner disponibilite de voiture (1-oui   2-non): ");scanf("%d",&v.disponible);
        fprintf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&idV,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible);
    }

 fclose(f);
}


void affichierVoiture(){
voiture v;
f=fopen("voiture.csv","r");

 if(f==NULL){
    printf("erreur d'overteur");
 }
    printf("******liste de voiture ********\n");
 while(fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible)==8){

  printf("id:%d\n la marque: %s\n modele: %s\n carburant: %s\n transmtion %s\n nombre de places : %d\n prix par jour : %f\n disponible (1- oui 0-non)%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible);

 }
fclose(f);
}
void rechrcherVoiture_Marque(){
int trouve=0;
char marqueV[20];
voiture v;
f=fopen("voiture.csv","r");

 if(f==NULL){
    printf("erreur d'overteur");
 }
 printf("entre la marque : ");scanf("%s",marqueV);
 while(fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible)==8){
    if(strcmp(marqueV,v.marque)==0){
        trouve=1;
        break;
    }
 }
    if(trouve==0){
        printf("le voiture n'existe pas\n");
    }
    else{
        printf("la voiture de marque : %s existe\n",marqueV);
    }
fclose(f);
}
void rechrcherVoiture_Disponibilite(){
int trouve=0;
int idV,dis;
voiture v;
f=fopen("voiture.csv","r");

 if(f==NULL){
    printf("erreur d'overteur");
 }
 printf("donner id de voiture : ");scanf("%d",&idV);
while(!feof(f)){
    fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible);
    if(idV==v.id){
        trouve=1;
        break;
    }
 }
 if(trouve==1){

    if(v.disponible==1){
        printf("voiture disponible\n");
    }
    else{
        printf("voiture n'ai pas disponible\n");
    }
   }

 else{
    printf("la voiture n'existe pas\n");
 }
fclose(f);
}
void rechrcherVoiture(){
int choix;
do{
    printf("1-rechrche la voiture par la marque\n");
    printf("2-rechrche voiture par disponibilite\n");
    printf("0-sortie\n");
    printf("donner le choix : ");scanf("%d",&choix);
    switch(choix) {
     case 1 : rechrcherVoiture_Marque();break;
     case 2 : rechrcherVoiture_Disponibilite();break;
     case 0 : printf("Fin");break;
     default : printf("erreur , entre dans l'intervalle [0-2]");
    }
}while(choix!=0);
fclose(f);
}


void modifierVoiture(){
  voiture v;
  int id;
  int trouve=0;
 f=fopen("voiture.csv","r");
 FILE *f1=fopen("tmp.csv","w");
 if(f==NULL || f1==NULL){
    printf("erreur d'ouverteur");
 }
 printf("entre id de voiture : ");scanf("%d",&id);
 while(fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible)==8){
    if(v.id==id){
        trouve =1;
        break;
    }
 }
 if(trouve=1){
        remove("voiture.csv");
        rename("tmp.csv","voiture.csv");
        printf("donner marque de voiture : ");scanf("%s",v.marque);
        printf("donner modele de voiture : ");scanf("%s",v.modele);
        printf("donner carburant de voiture : ");scanf("%s",v.carburant);
        printf("donner transmission de voiture : ");scanf("%s",v.transmission);
        printf("donner nombre de places de voiture : ");scanf("%d",&v.nbrPlaces);
        printf("donner prix par jour de voiture : ");scanf("%f",&v.prixJour);
        printf("donner disponibilite de voiture (1-oui   2-non): ");scanf("%d",&v.disponible);
        fprintf(f1,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible);
 }
 else{
    remove("voiture.csv");
    printf("la voiture n'existe pas");
 }
 fclose(f);
 fclose(f1);
}
void supprimerVoiture(){
 voiture v;
  int id;
  int trouve=0;
 f=fopen("voiture.csv","r");
 FILE *f1=fopen("tmp.csv","w");
 if(f==NULL || f1==NULL){
    printf("erreur d'ouverteur");
 }
 printf("entre id de voiture : ");scanf("%d",&id);
 while(fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible)==8){
    if(v.id!=id){
      fprintf(f1,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&v.id,v.marque,v.modele,v.carburant,v.transmission,&v.nbrPlaces,&v.prixJour,&v.disponible);
    }
    else{
        trouve=1;
    }
 }
remove("voiture.csv");
rename("tmp.csv","voiture.csv");
if(trouve==0){
    printf("la voiture n'existe pas");
}
else{
    printf("la voiture est supprime ");
}
fclose(f);
fclose(f1);
}

void trierVoiture(){
    voiture voitures[100],temp[30];
    int n = 0;

 f=fopen("voiture.csv","r");
if(f==NULL){
    printf("erreur d'overteur");
 }
while(fscanf(f,"%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&voitures[n].id,voitures[n].marque,voitures[n].modele,voitures[n].carburant,voitures[n].transmission,&voitures[n].nbrPlaces,&voitures[n].prixJour,&voitures[n].disponible)==8){
    n++;
}
fclose(f);

if (n == 0) {
        printf("Aucune voiture à trier.\n");
    }
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (voitures[j].prixJour > voitures[j + 1].prixJour) {
                temp[30]  = voitures[j];
                voitures[j] = voitures[j + 1];
                voitures[j + 1] = temp[30];
        }
    }
}
 printf("\n--- Liste triee ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n%s\n%s\n%s\n%s\n%d\n%f\n%d\n",&voitures[n].id,voitures[n].marque,voitures[n].modele,voitures[n].carburant,voitures[n].transmission,&voitures[n].nbrPlaces,&voitures[n].prixJour,&voitures[n].disponible);
    }

}











