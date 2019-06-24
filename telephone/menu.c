#include "struct.h"
abonent *add(abonent *note, int i)
{
	
	char n[10], ln[10];
	unsigned int f;
	printf("Vvedite imya \n");
	scanf("%s", n);
	printf("Vvedite familiu \n");
	scanf("%s", ln);
	printf("Vvedite nomer telephona \n");
	scanf("%d", &f);


 note = realloc(note, i*sizeof(abonent));
	strcpy(note[i-1].name, n);
	strcpy(note[i-1].lname, ln);
	note[i-1].tel=f;
	return note;
	}


abonent *del(abonent *note,int n,  int d)
{
	for (int i=0; i!=n; i++)
		{
			if(i>=(d-1)) note[i]=note[i+1];
		}

return (realloc(note, n*sizeof(abonent)));
}
void print(abonent* note, int n)
{
	printf("Nomera\n");

	for(int i=0;i!=n ; i++)
	{	printf("%d) ", i+1);
		printf("Name: %s     ", note[i].name);
		printf("Lastname: %s     ", note[i].lname);
		printf("Nomber: %d \n", note[i].tel);
	}
}
/*

plug* search(int i, plug *plg)
{plug *tmp;
		tmp = plg;
	i--;
	while (i!=0)
	{
		if (tmp == NULL) { printf("Pusto"); return (plg); }
		plg = plg->next;
		i--;
	}
	return(tmp);
}
void use(plug* plg)
{
	if (plg != 0)
	{
		cc cc3;
		void* dl;
		char lib[20]="plag/";
			strcat(lib, plg->namebib);
		dl = dlopen((const char*)lib, RTLD_NOW);
		if (!dl) { printf("no open\n"); }
		else
		{
			cc(*tempf)();
			tempf = dlsym(dl, (const char*)plg->namefunc);
			cc3 = tempf();
			printf("%f + %fi\n", cc3.d, cc3.m);
			dlclose(dl);
		}
	}

}
*/
void menu()
{



	abonent *note=0;
	int nabb=0;
	int t = 5;
	while (t) {
		printf("vibirite deistvie: \n 1-add  \n 2-del \n 3-search \n 4-print\n 0-exit\n");
		scanf("%d", &t);

		switch (t)
		{
		case 1: {	nabb++;
				note = add(note, nabb);
			break;  }
		case 2: {	int de=0;
				printf("Vvedite N elem na udalenie ");
				print(note, nabb);
				scanf("%d", &de);
				nabb--;
				del(note, nabb ,de);
			}

		/*case 3: {

			int i;
			printf("viberete plagin\n");
			print(b);
			scanf("%d", &i);
			use(search(i, b));
			break;

		}*/
		case 4: print(note, nabb);
			break;
		case 0: free(note);
		default:
			break;
		}
	}

}




















