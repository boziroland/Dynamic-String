	#include <stdio.h>
	#include <stdbool.h>

	typedef enum Allapot
	{
		begin,negaltkereszt_volt,underscore_volt,nulla_volt,
		szam_volt,w_volt,hat_volt,anychar_volt0,AZ_volt,
		anychar_volt1,q_volt1,q_volt2,r_volt,i_volt,q_volt3,
		Avb_volt
	}Allapot;

	char myid[]   = "Bozi Roland Sa'ndor,1MI,I16,L1B <boziroland99@gmail.com> EO7EGE\n";
	char mytask[] = "Feladat = 6 ISO 8859-2\n";

	int decToOct(int decSzam)
	{
		int octSzam=0,i=1;
		while(decSzam!=0)
		{
			octSzam+=(decSzam%8)*i;
			decSzam/=8;
			i*=10;
		}
		return octSzam;
	}

	int main()
	{
		setbuf(stdout, NULL);
		printf("%s",myid);
		printf("%s",mytask);
		int sorok=0;
		char input;
		int illeszkedo=0;
		Allapot all = begin;
		//FILE *fp;
		//fp=fopen("joteszt.txt","wt");
		bool voltmarq=0;
		while((input=getchar ()) !=EOF)
		{
			//fprintf(fp,"%c",input);
			//fputc(input, stderr);
			switch (all)
			{
				case begin:
					if(input!='#') all=negaltkereszt_volt;
					break;
				case negaltkereszt_volt:
					if(input=='_') all=underscore_volt;
					else if(input=='0') all=nulla_volt;
					else if(input>'0'&&input<='9') all=szam_volt;
					break;
				case underscore_volt:
					if(input=='_') all=underscore_volt;
					else if(input=='0') all=nulla_volt;
					break;
				case nulla_volt:
					if(input>='0'&&input<='9') all=szam_volt;
					break;
				case szam_volt:
					if(input>='0'&&input<='9') all=szam_volt;
					else if(input=='W') all=w_volt;
					
					//else all=begin;
					break;
				case w_volt:
					if(input=='6') all=hat_volt;
					
					//else all=begin;
					break;
				case hat_volt:
					if(input!='\n') all=anychar_volt0;
					
					//else all=begin;
					break;
				case anychar_volt0:
					if(input>='A'&&input<='Z') all=AZ_volt;
					break;
				case AZ_volt:
					if(input!='\n') all=anychar_volt1;
					break;
				case anychar_volt1:
					if(input=='q'&&voltmarq)
						all=q_volt2;

					else if(input=='q'&&!voltmarq) 
					{
						voltmarq=1;
					}
					else if(voltmarq) voltmarq=0;
					break;
				case q_volt1:
					if(input=='q') all=q_volt2;
					
					//else all=begin;
					break;
				case q_volt2:
					if(input=='r') all=r_volt;
					else 
					{
						//all=begin;
						voltmarq=0;
					}
					break;
				case r_volt:
					if(input=='i') all=i_volt;
					
					else 
					{
						//all=begin;
						voltmarq=0;
					}
					break;
				case i_volt:
					if(input=='q') all=q_volt3;
					
					else 
					{
						//all=begin;
						voltmarq=0;
					}
					break;
				case q_volt3:
					if(input=='A'||input=='b')
					{
						//all=begin;
						illeszkedo++;
						voltmarq=0;
					}
					
					all=begin;
					break;
			}
			if(input=='\n') sorok++;
		}
		printf("%d/%d\n",decToOct(sorok),decToOct(illeszkedo));
		return 0;
	}
/*
6. feladat Bozi Roland Sándor (EO7EGE) részére:
Írjon C programot, amely a standard inputon érkezõ szöveg sorait
megszámolja, és megszámolja azokat a sorokat is amelyekre az alábbi
(ld. 4. feladat) reguláris kifejezes illeszkedik:

  ^[^#]_*(0)*[0-9]+W6.+[A-Z]+.+qqriq(A|b)

A program az eredményt két oktális számként írja ki a standard outputra!
A két számot / jellel válassza el, és a sort sorvégjellel zárja le pl:
123/71

A fenti reguláris kifejést Önnek kell értelmeznie és nem kell értelmezõ
programot készítenie hozzá! Pl. a [A-Z]+ kifejezéshez olyan állapotgépet
kell készítenie, ami felismeri a nagybetûkbõl álló sorozatot.
*/
