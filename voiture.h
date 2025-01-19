#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED

FILE *f;

typedef struct{
int id;
char marque[20],modele[20],carburant[20];
int nbrPlaces;
char transmission[20];
float prixJour;
int disponible;
}voiture;

void saisirNom();
void ajouterVoiture();
void affichierVoiture();
void modifierVoiture();
void supprimerVoiture();
void rechrcherVoiture();
void trierVoiture();

void rechrcherVoiture_Disponibilite();
void rechrcherVoiture_Marque();

#endif // VOITURE_H_INCLUDED
