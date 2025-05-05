#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct {
    int numero;
    int lunghezza;
} raccolta;


int Dijkstra(int d, int **matrice,int sorgente);
void maxheapify(raccolta *A, int n,int k);


int main() {
  int d = 0;
  int k = 0;
  raccolta *risultati = NULL;
  int **matrice = NULL;
  char res ;
  int v =0;
  int cont = -1;
  int i;
  int s;
int start = 0;
int tmp;



  res = getchar();
  while(res != ' ') {
   d = d*10 + (res - '0');
   res  = getchar(); }

   res = getchar();
   while (res != '\n') {
     k = k*10 + (res - '0');
     res = getchar() ;
}


risultati = malloc(k* sizeof(raccolta*));


  res = getchar();
  while (res != EOF) {

      if(res == 'A') {
        res = getchar();
        while(res != '\n') {
          res = getchar();
        }
        matrice =(int**) malloc (d*sizeof( int*));

          for (i = 0; i < d; i++) {
            matrice[i] = (int*)malloc(d*sizeof( int));
        for(s=0;s<d-1;s++) {
          matrice[i][s]=0;
            res = getchar();
            while(res != ',') {
                matrice[i][s] = (matrice[i][s] * 10)+ (res - '0');
                res = getchar();
            }
        }

        matrice[i][d-1] = 0;
          res = getchar();
          while(res != '\n') {
            matrice[i][d-1] = (matrice[i][d-1]*10) + (res - '0');
            res = getchar();
          }
        }

          if(v == k) {
              cont = cont +1;
              if(start == 0) {
                i = (k/2)-1;
                do {
                  maxheapify(risultati,i,k);
                  i--;
                } while(i != 0);


                start =1;
              }

              tmp = Dijkstra(d,matrice,0);
if(tmp < risultati[0].lunghezza) {
  risultati[0].lunghezza = tmp;
  risultati[0].numero = cont;
  maxheapify(risultati,0,k);
}

          }

          else {
              cont = cont + 1;
                  risultati[v].lunghezza = Dijkstra(d,matrice,0);
                  risultati[v].numero = cont;
                  v = v + 1;
          }
for(i = 0;i<d;i++) {
  free(matrice[i]);
}
free(matrice);
 matrice = NULL;

res = getchar();
      }



    else if(res == 'T') {
      res = getchar();
      while(res != '\n') {
        res = getchar();
      }

      if(cont == -1) {
        printf("\n");
      }
      else {

            if(cont >= k) {
              for (i = 0; i<k-1;i++) {
                  printf("%d ",risultati[i].numero);
              }
              i = k-1;
              printf("%d\n",risultati[i].numero);
          }
        else {
          for(i =0;i<cont;i++) {
            printf("%d ",risultati[i].numero);
          }
          i = cont;
          printf("%d\n",risultati[i].numero);
        }
      }

res = getchar();
    }

}




  return 0;
}





int Dijkstra(int d,  int **matrice,int partenza) {
    int dist[d] , visited[d];
    int i, mind, count;
    int totale = 0;
    int next = 0;
    int massimo = 2000000000;
    int controllo = 0;


    for(i = 1; i<d; i++) {
   if(matrice[partenza][i] != 0) {
     controllo = 1;
   }
 }
    if(controllo == 0) {
      return totale;
   }

    else {

      for(i = 0; i<d;i++) {
        dist[i]= matrice[partenza][i];
        visited[i]=0;

      }

    dist[partenza] = 0;
    visited[partenza]=1;
    count = 1;

    while (count < d-1) {
        mind = massimo;
        for(i = 1 ; i<d; i++) {
          if(!visited[i]) {
            if(dist[i] <= mind && dist[i]!=0) {
            mind = dist[i];
            next = i;
          }
        }
      }
        visited[next]= 1;
        for(i = 1;i<d;i++) {
            if(!visited[i]) {
              if( matrice[next][i] > 0 ) {
                  if(dist[i]==0) {
                    dist[i]= mind + matrice[next][i];
                  }
                  else { if(mind + matrice[next][i] < dist[i]) {
                    dist[i]= mind + matrice[next][i];
                  }

                  }

                }
            }
          }

        count++;
    }

    for(i=1;i<d;i++) {
      if(dist[i] >0 ) {
      totale = totale + dist[i];
    }
}


return totale;

}
}


void maxheapify(raccolta *A, int n,int k) {
  int l = 2*n + 1;
  int r = 2*n + 2;
  int posmax,tempo;

  if(l < k && (A[l].lunghezza > A[n].lunghezza)) {
      posmax = l;
  }
  else {
    posmax = n;
  }
  if(r< k && (A[r].lunghezza > A[posmax].lunghezza)) {
    posmax = r;
  }

  if(posmax != n) {
  
  tempo = A[n].lunghezza;
  A[n].lunghezza = A[posmax].lunghezza;
  A[posmax].lunghezza = tempo;

  tempo = A[n].numero;
  A[n].numero = A[posmax].numero;
  A[posmax].numero = tempo;
    maxheapify(A,posmax,k);
  }
}
