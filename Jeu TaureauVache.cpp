#include <stdio.h> //bibliotheque des entr�s sortie standard
#include <stdlib.h> //bibliotheque Gestion de la m�moire, conversions et fonctions syst�mes
#include <string.h> // bibliotheque de gestion de chaine de caractere
int get_random_val (int min,int max) //cr�ation de fonction return valeur al�atoire entier de parametre min et max
{
	return (rand()%(max-min)+min);//resultat retourn�
}
int test(int n) //cr�ation de fonction test si un  nombre est distinct
{
	char k[4]; //d�claration de tableau de chaine de caracteres local � tester
	int i,j,er;//d�claration des variables local
	er=0;  //initialisation d'un erreur si le nombre n'est pas distinct
	sprintf(k,"%d",n); //convertir un varible entier � chaine de caractere
	for(j=0;j<=3;j++)//boucle pour d�placer jusqu'� la case 2
	{
		for(i=j+1;i<5;i++)//boucle pour deplacer de j+1 � la fin de tableau de chaine de caractere
		{
			if(k[j]==k[i])//test d'egalite entre les chiffres d'un nombre
			{
				er++;//incr�mentation d'un erreur 
			}
		}
	}
	if(er>0) //test de pr�sence d'un erreur
	{
	    return -1; //return false 
	}
	else 
	{
		return 1;//return true
	}
}
int saisir() //cr�ation de fonction de saisie un entier de 4 chiffres distincts
{
	int n; //d�claration vairiable local
	do //boucle de repition
	{
		printf("donner un valeur\n"); //ecrire sur l'ecran donner un valleur avec retour a la ligne
		scanf("%d",&n); //attendre le joeueur pour donner une valeur et la sauvegarder dans n
	}
	while(((n>=1000)||(n<=9999))&&(test(n)== -1));//condition de sortie et appelle au fontion test
	return n;//return un entier n
}
int traitement_t(char chn[],char chal[]) //cr�ation de fonction de traitement de nombre de taureau
{
	int i,t;//d�claration des variables local
	t=0;//initialisation taureau
	for(i=0;i<4;i++)//boucle de compteur i se d�place de debut de tableau jusqu'a la fin
	{
		if(chn[i]==chal[i])//verife le meme chiffre et la meme position
		{
			t++; //incr�mentation taureau
		}
	}
	return t;//return nombre de t (taureau)
}
int taritement_v(char chn[],char chal[]) //cr�ation de fonction de traitement de nombre de vache
{
	int i,v,j;//d�claration des variables local
	v=0;// initialisation vache
	for(i=0;i<=3;i++)//boucle pour fixer un chiffre et le comparer
	{
		for(j=0;j<=3;j++)//boucle pour chercher un chiffre egale a la chiffre de boucle pr�c�dente
		{
			if(chal[i]==chn[j])//verife le meme chiffre
			{
				if(i!=j) //verife que les deux chiffres de position differente
				{
					v++;//incr�mentation vache
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
{ //d�but du programme principale
 	int al,n,t,v;//d�claration des variable entier et alocation d'un espace m�moire
 	char chn[4],chal[4];//declaration de tableau de chaine de caractere et alocation d'un espace memoire
 	do //boucle de repition
	{
		al=get_random_val(1000,9999); // appelle au fonction qui donne des valeur al�atoire
	}
	while(test(al)==-1);//condition de sortie et appelle au fonction test
	printf("alia egale %d\n",al);
	do //boucle de repition
	{
 		n=saisir(); // appelle au fonction saisie un entier de 4 chiffres distincts
 		sprintf(chal,"%d",al); // convertir un entier al al�atoire a un chaine de caractere chal
 		sprintf(chn,"%d",n); //convertir un entier n a un chaine de caractere chn
 		t=traitement_t(chn,chal); //appelle au fonction traitement_t
 		v=taritement_v(chn,chal); //appelle au fonctionn traitement_v
 		afficher(t,v); //appelle au procedure qui ecrit sur l'ecran le resultat
 	}
 	while(t<4); //condition de sortie
return 0; //indique que le programmee s'est termin� avec succ�s
} //fin du programme

