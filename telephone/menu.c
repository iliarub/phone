#include "struct.h"
abonent *add(abonent *note, int i)
{
	char n[10], ln[10], f[11];
	printf("Vvedite imya \n");
	scanf("%s", n);
	printf("Vvedite familiu \n");
	scanf("%s", ln);
	printf("Vvedite nomer telephona \n");
	scanf("%s", f);


 note = realloc(note, i*sizeof(abonent));
	strcpy(note[i-1].name, n);
	strcpy(note[i-1].lname, ln);
	strcpy(note[i-1].tel, ln);
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
{	if(n==0) printf("znacheniu net");
	else{
	printf("Nomera\n");

	for(int i=0;i!=n ; i++)
	{	printf("%d) ", i+1);
		printf("Name: %s     ", note[i].name);
		printf("Lastname: %s     ", note[i].lname);
		printf("Nomber: %s \n", note[i].tel);
	}
	    }
}

int search(abonent *note, int n)
{
	char tmp[11];
	char tmp2[11];
	int sw=1;
	while (sw) {
		printf("Poisk po: \n1) name\n2) lastname\n3) telephone\n 0) exit\n");
		scanf("%d", &sw);
		if (sw == 0||sw>3) return(0);
		printf("Vvedite znachenie poiska \n");
		scanf("%s", tmp2);

for (int y = 0; y < n; y++)
{
	if (sw == 1) strcpy(tmp, note[y].name);
	if (sw == 2) strcpy(tmp, note[y].lname);
	if (sw == 3) strcpy(tmp, note[y].tel);
		for (int i=0; tmp[i] != 0; i++)
		{
			for (int a = i, j = 0; tmp[a] == tmp2[j]; a++, j++)
			{
				if (tmp2[j + 1] == 0)
				{
					return (y+1);
				}
			}
		}
	}

}
}
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

		case 3: {

			int prn=search(note, nabb);
	       printf("%d) ", prn);
                printf("Name: %s     ", note[prn-1].name);
                printf("Lastname: %s     ", note[prn-1].lname);
                printf("Nomber: %s \n", note[prn-1].tel);

			break;

		}
		case 4: print(note, nabb);
			break;
		case 0: free(note);
		default:
			break;
		}
	}

}




















