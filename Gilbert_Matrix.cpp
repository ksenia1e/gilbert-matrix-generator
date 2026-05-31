#include <iostream>
#include <stdio.h>
#include <cmath>

int main()
{
   FILE *myfile;
   int n = 0;
   

   scanf_s("%d", &n);

   fopen_s(&myfile, "n.txt", "w");
   fprintf_s(myfile, "%d", n);
   fclose(myfile);

   double *di = new double[n];
   int *ia = new int[n + 1];

   fopen_s(&myfile, "ia.txt", "w");
   ia[0] = 0;
   ia[1] = 0;
   for ( int i = 2; i < n + 1; i++ )
      ia[i] = ia[i - 1] + (i - 1);
   for ( int i = 0; i < n + 1; i++ )
      fprintf_s(myfile, "%d ", ia[i]);
   fclose(myfile);

   int m = ia[n];
   double *al = new double[m];

   fopen_s(&myfile, "di.txt", "w");
   for ( int i = 0, ne = 1; i < n; i++, ne++ )
   {
     di[i] = 1.0 / (2 * ne - 1);
   }
   for ( int i = 0; i < n; i++ )
      fprintf_s(myfile, "%.14lf ", di[i]);
   fclose(myfile);

   for ( ; n > 1; )
   {
      fopen_s(&myfile, "al.txt", "w");
      int il = 0;
      for ( int i = 1; i < n; i++ )
      {
         int p = ia[i + 1] - ia[i];
         for ( int k = 1; k <= p; k++ )
         {
            al[il] = 1.0 / (p + k);
            il += 1;
         }
      }
      for ( int i = 0; i < m; i++ )
         fprintf_s(myfile, "%.14lf ", al[i]);
      fclose(myfile);
      break;
   }
}