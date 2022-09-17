#include <stdio.h> //bibliotheque des entrés sortie standard
#include <stdlib.h> //bibliotheque Gestion de la mémoire, conversions et fonctions systèmes
#include <string.h> // bibliotheque de gestion de chaine de caractere
int get_random_val (int min,int max) //création de fonction return valeur aléatoire entier de parametre min et max
{
	return (rand()%(max-min)+min);//resultat retourné
}
int test(int n) //création de fonction test si un  nombre est distinct
{
	char k[4]; //déclaration de tableau de chaine de caracteres local à tester
	int i,j,er;//déclaration des variables local
	er=0;  //initialisation d'un erreur si le nombre n'est pas distinct
	sprintf(k,"%d",n); //convertir un varible entier à chaine de caractere
	for(j=0;j<=3;j++)//boucle pour déplacer jusqu'à la case 2
	{
		for(i=j+1;i<5;i++)//boucle pour deplacer de j+1 à la fin de tableau de chaine de caractere
		{
			if(k[j]==k[i])//test d'egalite entre les chiffres d'un nombre
			{
				er++;//incrémentation d'un erreur 
			}
		}
	}
	if(er>0) //test de présence d'un erreur
	{
	    return -1; //return false 
	}
	else 
	{
		return 1;//return true
	}
}
int saisir() //création de fonction de saisie un entier de 4 chiffres distincts
{
	int n; //déclaration vairiable local
	do //boucle de repition
	{
		printf("donner un valeur\n"); //ecrire sur l'ecran donner un valleur avec retour a la ligne
		scanf("%d",&n); //attendre le joeueur pour donner une valeur et la sauvegarder dans n
	}
	while(((n>=1000)||(n<=9999))&&(test(n)== -1));//condition de sortie et appelle au fontion test
	return n;//return un entier n
}
int traitement_t(char chn[],char chal[]) //création de fonction de traitement de nombre de taureau
{
	int i,t;//déclaration des variables local
	t=0;//initialisation taureau
	for(i=0;i<4;i++)//boucle de compteur i se déplace de debut de tableau jusqu'a la fin
	{
		if(chn[i]==chal[i])//verife le meme chiffre et la meme position
		{
			t++; //incrémentation taureau
		}
	}
	return t;//return nombre de t (taureau)
}
int taritement_v(char chn[],char chal[]) //création de fonction de traitement de nombre de vache
{
	int i,v,j;//déclaration des variables local
	v=0;// initialisation vache
	for(i=0;i<=3;i++)//boucle pour fixer un chiffre et le comparer
	{
		for(j=0;j<=3;j++)//boucle pour chercher un chiffre egale a la chiffre de boucle précédente
		{
			if(chal[i]==chn[j])//verife le meme chiffre
			{
				if(i!=j) //verife que les deux chiffres de position differente
				{
					v++;//incrémentation vache
				}
			}
		}
	}
	return v;//return nombre de v (vache)
}
void afficher(int t,int v)//creation de procedure d'affichage
{
	printf(" T%d V%d ",t,v);//ecrire sur l'ecran le resultat
}
int main() //fonction de programme principale
{ //début du programme principale
 	int al,n,t,v;//déclaration des variable entier et alocation d'un espace mémoire
 	char chn[4],chal[4];//declaration de tableau de chaine de caractere et alocation d'un espace memoire
 	do //boucle de repition
	{
		al=get_random_val(1000,9999); // appelle au fonction qui donne des valeur aléatoire
	}
	while(test(al)==-1);//condition de sortie et appelle au fonction test
	printf("alia egale %d\n",al);
	do //boucle de repition
	{
 		n=saisir(); // appelle au fonction saisie un entier de 4 chiffres distincts
 		sprintf(chal,"%d",al); // convertir un entier al aléatoire a un chaine de caractere chal
 		sprintf(chn,"%d",n); //convertir un entier n a un chaine de caractere chn
 		t=traitement_t(chn,chal); //appelle au fonction traitement_t
 		v=taritement_v(chn,chal); //appelle au fonctionn traitement_v
 		afficher(t,v); //appelle au procedure qui ecrit sur l'ecran le resultat
 	}
 	while(t<4); //condition de sortie
return 0; //indique que le programmee s'est terminé avec succés
} //fin du programme

