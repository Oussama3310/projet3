#include<stdio.h>
#include<string.h>
typedef struct {
	char id[50],mdp[50];
}uti;

int log_in( int n, uti u[400], char id[50], char mdp[50])
	{int i,log;
	log=2;
    for(i=0;i<n;i++)
	{
	    if(strcmp(id,u[i].id)==0)
		{log=1;
			if(strcmp(mdp,u[i].mdp)==0)
			{   log=4;
				if(i==0)
				{	
				    log=3;
				}
			}
			
		}

	}
	return log;	
}

void affichage(int n, uti u[400])
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("-Utilisateur %d:  %s\n",i+1,u[i].id);
	}	
}


int ajouter( int n, uti u[400],char id[50], char mdp[50])
{
	int aj=0,i;
	for(i=0;i<n;i++)
	{
		if(strcmp(id,u[i].id)==0)
		{
			aj=1;	
		}
	}
	
	if(aj==0)
	{
		strcpy(u[n].id,id);
		strcpy(u[n].mdp,mdp);

	}
	return aj;	
}

int mdp_admin( int n, uti u[400],char id[50], char mdp[50])
{
	int i;
	int mod=1;
	for(i=0;i<n;i++)
	{
		if(strcmp(id,u[i].id)==0)
		{
			mod=0;
			strcpy(u[i].mdp,mdp);
		
	    }
	}
	return mod;
	
}

int mdp_uti(char id[50], char mdp[50],char nvmdp[50], int n, uti u[400])
{
	int log,mod2,i;
	log=log_in(n,u,id,mdp);
	
	if(log==0||log==3)
	{
		strcpy(u[i].mdp,nvmdp);
		mod2=3;
	}
	else if(log==1)
	{
		mod2=1;
	}
	else if(log==2)
	{
		mod2=2;
	}
	return mod2;	
	
	}
	
main()
{
	uti u[400];
	char id[50],mdp[50],nvmdp[50];
	int n,log,mod,mod2,aj,s,choix,fin;
	fin=1;
	n=1;
	
	printf("\n\n\t\t\t***ADMINE*\n");
	printf("\n-Choisir un identifiant pour l'admin:  ");
	scanf("%s",u[0].id);
	printf("-Choisir un mot de passe pour l'admin: ");
	scanf("%s",u[0].mdp);
	
	
	
	while(fin==1){
		printf("\n\t\t\t******");
	printf("\n-Connectez-vous a votre compte: ");
	fflush(stdin);
	gets(id);
	printf("-Entrer votre mot de passe:     ");
	gets(mdp);
	log=log_in(n,u,id,mdp);
	
	if(log==1)
	{
		printf("Oups, il semblerait que ce ne soit pas le bon mot de passe.\n");
	}
	else if(log==2)
	{
		printf("Oups, cette adresse id n'est pas valide.\n");
	}
	else if(log==3)
	{
		printf("\n              $$$ Connexion avec succes $$$\n\n");
		do{s=1;
		
		printf(" 1---> Ajouter un utilisateur\n");
		printf(" 2---> Changer le mot de passe d'un utilisateur\n");
		printf(" 3---> Afficher la liste des utilisateurs\n");
		printf(" 4---> Changer votre mot de passe\n");
		printf(" 5---> Se deconnecter\n");
		printf("-Entrer votre choix: ");
		scanf("%d",&choix);
		
		switch(choix)
		{
			case 1: {
				printf("---------------Ajouter un utilisateur---------------\n\n");
				printf("-Choisir un identifiant: ");
				fflush(stdin);
				gets(id);
				printf("-Choisir un mot de passe: ");
				gets(mdp);
				aj=ajouter(n,u,id,mdp);
				if(aj==1)
				{
					printf("\n*Ce nom d'utilisateur est deja utilise. Essayez un autre nom.*\n\n");
				}
				else if (aj==0)
				{
					printf("\n              $$$ L'ajout d'utilisateur avec succes   $$$\n\n");
					n++;
				}
				break;
			}
			
			case 2:{
				printf("---------------Changer le mot de passe d'un utilisateur---------------\n\n");
				printf("-Entrer son identifiant : ");
				fflush(stdin);
				gets(id);
				printf("-Entre le nouveau mot de passe: ");
				gets(mdp);
				mod=mdp_admin(n,u,id,mdp);
				if(mod==1)
				{
					printf("Oups, cette adresse id n'est pas valide.\n");
				}
				else
				{
					printf("Mot de passe change\n");
				}

				break;
			}
			case 3:{
				printf("---------Affichage de liste des utilisateurs---------\n\n");
				affichage(n,u);
				break;
			}
			case 4:{
				printf("---------------Changement de votre mot de passe---------------\n\n");
				printf("-Veuillez entrer votre identifiant: ");
				fflush(stdin);
				gets(id);
				printf("-Veuillez entre votre Ancien mot de passe: ");
				gets(mdp);
				printf("-Veuillez entre le nouveau mot de passe: ");
				gets(nvmdp);
				mod2=mdp_uti(id,mdp,nvmdp,n,u);
				if(mod2==2)
	            {
	            printf("Oups, cette adresse id n'est pas valide.\n");
	            }
	             else if(mod2==1)
	            {
		        printf("Oups, il semblerait que ce ne soit pas le bon mot de passe.\n");
	            }
	            else if(mod2==3)
	            {
	            	printf("Changement de mdp avec succes\n");
				}
				
				
				break;
			}
			case 5:{
				s=0;
				printf("              $$$ Vous vous etes deconnecter avec succes $$$\n");
				
				break;
			}
			
			
		}
		
		
	}while(s==1);
	}
	else if(log==4)
	{
		printf("\n              $$$ Connexion avec succes $$$\n\n");
		do{s=1;
			
		    
		    printf(" 1---> Afficher la liste des utilisateurs\n");
	    	printf(" 2---> Changer votre mot de passe\n");
		    printf(" 3---> Se déconnecter\n");
		    printf("Entrer votre choix: ");
		    scanf("%d",&choix);
		
		switch(choix){
			case 1:{
				printf("--------Affichage de liste des utilisateurs--------\n\n");
				affichage(n,u);	
				break;
			}
			case 2:{
				printf("--------Changement de votre mot de passe--------\n\n");
				printf("-Veuillez entrer votre identifiant: ");
				fflush(stdin);
				gets(id);
				printf("-Veuillez entre votre Ancien mot de passe: ");
				gets(mdp);
				printf("-Veuillez entre le nouveau mot de passe: ");
				gets(nvmdp);
				mod2=mdp_uti(id,mdp,nvmdp,n,u);
				if(mod2==2)
	            {
	           	printf("Oups, cette adresse id n'est pas valide.\n");
	            }
	             else if(mod2==1)
	            {
		        printf("Oups, il semblerait que ce ne soit pas le bon mot de passe.\n");
	            }
	            else if(mod2==3)
	            {
	            	printf("-Mot de passe change\n");
				}
				
				
				break;
			}
			case 3:{
				s=0;
				printf("              $$$ Vous vous etes deconnecter avec succes $$$\n");
				
				
				break;
			}	
		}	
		
		}while(s==1);
			}

	}
	
	
	
}
