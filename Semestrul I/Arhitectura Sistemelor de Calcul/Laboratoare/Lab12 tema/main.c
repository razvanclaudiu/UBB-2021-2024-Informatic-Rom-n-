#include <stdio.h>

int sign(int nr);

/* 19. Se citesc din fisierul numere.txt mai multe numere (pozitive si negative). Sa se creeze 2 siruri rezultat N si P astfel: N - doar numere negative si P - doar numere pozitive. Afisati cele 2 siruri rezultate pe ecran.*/
int main()
{
   /*num - variabila pentru fiecare numar din fisier*/
   /*nr - numarul de numere din fisier*/
   /*i - folosit pentru parcurgerea numerelor din fisier*/
   /*P[100] - sirul de numere pozitive*/
   /*N[100] - sirul de numere negative*/
   /*nrp - pozitia in sirul de numere pozitive*/
   /*nrn - pozitia in sirul de numere negative*/
   /*sig - variabila prin care se verifica daca un numar este pozitiv sau negativ*/
   /* *fptr - pointer-ul fisierului */
   int num, nr, i = 0, P[100], N[100], nrp = -1, nrn = -1, sig;
   FILE *fptr;
    
   /*Se deschide fisierul*/
   fptr = fopen("program.txt","r");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   /*Se citeste din fisier primul numar, aceste fiind numarul de numere din fisier*/
   fscanf(fptr, "%d", &nr);
   
   /*Se parcurge fisierul si se apeleaza modulul "sign" prin care se verifica daca un numar este pozitiv sau negativ si se adauga in sirul potrivit*/
   while(i < nr)
   {
       fscanf(fptr, "%d", &num);
       sig = sign(num);
       if(sig == 1)
            P[++nrp] = num;
       else N[++nrn] = num;
       i++;
   }
   /*Se afiseaza un mesaj urmat de sirul de numere pozitive*/
   printf("Numere pozitive: "); 
   for(i = 0; i<=nrp; i++)
       printf("%d ", P[i]);
   
   /*Newline*/
   printf("\n"); 
   
   /*Se afiseaza un mesaj urmat de sirul de numere negative*/
   printf("Numere negative: "); 
   for(i = 0; i<=nrn; i++)
       printf("%d ", N[i]);
    
   /*Se inchide fisierul*/
   fclose(fptr);

   return 0;
}