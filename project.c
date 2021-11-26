#include<stdio.h>
#include<string.h>
typedef struct compte{
	char nom[50];
	char prenom[50];
	char cin[50];
	float montant;
}Cpt;

Cpt tab[2000];
int size = 5;
void data(){
	Cpt c1 = {"a","a","a",500};
	Cpt c2 = {"b","b","b",300};
	Cpt c3 = {"c","c","c",700};
	Cpt c4 = {"d","d","d",100};
	Cpt c5 = {"e","e","e",900};
	tab[0] = c1;
	tab[1] = c2;
	tab[2] = c3;
	tab[3] = c4;
	tab[4] = c5;
}
Cpt *search(){
	char nom[50];
	int i;
	printf("\n\t\tChercher un client (CIN): ");
	scanf("%s",nom);
	for(i=0;i<size;i++){
		if(strcmp(nom,tab[i].cin) == 0)
			return &tab[i];
	}
	
	return NULL;
}
int menu_principale(){	
	int choix;
	do{
		printf("\n\t--1-----ajouter un compte-----------");
		printf("\n\t--2-----ajouter des comptes-----------");
		printf("\n\t--3-----affichier les comptes bancaires");
		printf("\n\t--4-----affichier les comptes bancaire ascendant");
		printf("\n\t--5-----affichier les comptes bancaire descendant");
		printf("\n\t--6-----affichier les comptes bancaire ascendant sup un montant");
		printf("\n\t--7-----affichier les comptes bancaire descendant sup un montant");
		printf("\n\t--8-----retrait");
		printf("\n\t--9-----depot");
		printf("\n\t--10----chercher un client (CIN)");
		printf("\n\t--11----Fidilisation");
		printf("\n\t--0-----Quitte----");
		printf("\n\t-------**********------- \n");
		printf("\n\t  entre votre choix : ");
		scanf("%d",&choix);
	}while(choix<0 || choix > 11);
	return choix;
}
void print_client(Cpt client){
	printf("\n\t\t%s----------%10s----------%10s----------%10.2f",client.prenom,client.nom,client.cin,client.montant);
}
void ajouter_compte(){
	Cpt nv_cpt;
	printf("\n\t\tNom: ");
	scanf("%s",&nv_cpt.nom);
	printf("\n\t\tPrenom: ");
	scanf("%s",&nv_cpt.prenom);
	printf("\n\t\tCIN: ");
	scanf("%s",&nv_cpt.cin);
	printf("\n\t\tMontant: ");
	scanf("%f",&nv_cpt.montant);
	tab[size] = nv_cpt;
	size++;
	print_client(nv_cpt);
}
void ajouter_comptes(){
	int x,i;
	printf("\n\tNombre de comptes a ajouter: ");
	scanf("%d",&x);
	for(i=0;i<x;i++){
		printf("\n\t\tCompte N--->%d :\n",i+1);
		ajouter_compte();
	}
}
void print_clients(Cpt clients[]){
	int i;
	char mt[] = "Montant";
	printf("\n\t\t%s--------%10s--------%10s---------%10s","Prenom","Nom","Cin",mt);
	for(i=0;i<size;i++){
		print_client(clients[i]);
	}
}
void print_ascendant(){
	int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size-1;j++)
			if(tab[j].montant > tab[j+1].montant){
				Cpt tem;
				tem      = tab[j+1];
				tab[j+1] = tab[j];
				tab[j]   = tem;
			}
}
void print_descendant(){
		int i,j;
	for(i=0;i<size;i++)
		for(j=0;j<size-1;j++)
			if(tab[j].montant < tab[j+1].montant){
				Cpt tem;
				tem      = tab[j+1];
				tab[j+1]   = tab[j];
				tab[j] = tem;
			}
}
int main(){
	int choix;
	data();
	do{ 
		choix = menu_principale();
		switch(choix){
			case 1 : {
				ajouter_compte();
				break;
			}
			case 2 : {
				ajouter_comptes();
				break;
			}
			case 3 : {
				print_clients(tab);
				break;
			}
			case 4 : {
				print_ascendant();
				print_clients(tab);
				break;
			}
			case 5 : {
				print_descendant();
				print_clients(tab);
				break;
			}
			case 6 : {
				break;
			}
			case 7 : {
				break;
			}
			case 8 : {
				Cpt *return_client = search();
				if(return_client != NULL){
					float m;
					printf("\n\t\tMontant: ");
					scanf("%f",&m);
					if((*return_client).montant >= m){
						float x, y;
						x = (*return_client).montant;
						(*return_client).montant = (*return_client).montant - m;
						y = (*return_client).montant;
						printf("\n\t\Retrait: %.2f\n\t\tSolde actuelle: %.2f",m,y);
						printf("\n\t\tOperation terminer avec suceccees");
					}
					else 
						printf("\n\t\tSolde insifusant.");
				}
				else 
					printf("\n\t\tAucune compte avec cette CIN.");
				break;
			}
			case 9 : {
				Cpt *return_client = search();
				if(return_client != NULL){
					float m;
					printf("\n\t\tMontant: ");
					scanf("%f",&m);
						float x, y;
						x = (*return_client).montant;
						(*return_client).montant = (*return_client).montant + m;
						y = (*return_client).montant;
					printf("\n\t\tSolde: %.2f Dhs\n\t\tSolde actuelle: %.2f Dhs",x,y);
					printf("\n\t\tOperation terminer avec suceccees");
				}
				else 
					printf("\n\t\tAucune compte avec cette CIN.");
				break;
			}
			case 10 : {
				Cpt *s = search();
				if(s == NULL){
					printf("\n\t\tN'exist pas.");
				}
				else 
					print_client(*s);
				break;
			}
			case 11 : {
				print_descendant();
				int i;
				for(i=0;i<3;i++) 
					tab[i].montant += (tab[i].montant)*0.013;
				char mt[] = "Montant";
				printf("\n\t\t%s--------%10s--------%10s---------%10s","Prenom","Nom","Cin",mt);
				for(i=0;i<3;i++) 
					print_client(tab[i]);
				break;
			}
			default:{
				break;
			}
		}
		char isok[10];
		printf("\n\n\n\t\t........  ");
		scanf("%s",isok);
	}while(choix != 0);
	return 0;
}
