/*
Trabalho DCC5199 - Algoritmos I
Caça Palavras
Participantes c/ Matrícula:
-> Cauã Moreno Lopes Castro - Matrícula: 202335019
-> Estêvão Barbosa Fiorilo da Rocha - Matrícula: 202335030
-> João Pedro Ferreira SrBek - Matrícula: 202335034
*/
#include <iostream>
#include <cstring>
#define M 10
#define N 100
using namespace std;

//O trabalho foi feito em conjunto presencialmente, também utilizando o VSCode Live Share
//Desse modo, mantivemos os mesmos padrões nas nomeclaturas das variáveis

//primeiramente, definimos como as impressoes funcionariam
//nesse caso, cada um fazerá uma verificação de cada estilo de matriz
//por padrao, fizemos a impressao em caso da palavra for encontrada dentro da funcao
//se ela for encontrada, tambem retornara true. Caso contrario, retornará false
//por fim, no int main, ele imprimirá que não foi encontrada caso as 3 retorne false

bool verifHoriz(char m[M][M], char p[N], int l, int c) // feito por Estêvão
{
    int f;
    int q;
    int tamP = strlen(p),contP=0;
    for (int i=0;i<l;i++) 
    {
        for (int j=0;j<c;j++) //verificacao da esquerda pra direita
        {
            if (m[i][j] == p[contP]|| m[i][j]==p[contP]-'a'+'A' || m[i][j]==p[contP]-'A'+'a')
            {
                contP++;
                if (contP==1)
                {
                    f=i+1;
                    q=j+1;
                }
                if (contP == tamP)
                {
                    cout << "Palavra " << p << " foi localizada horizontalmente a partir de posição (" << f << "," << q << ")." << endl;
                    return true;
                }
            }
            else
            {
                contP=0;
            }
        }
        for (int j=c;j>=0;j--) //verificacao da direita pra esquerda
        {
              contP++;
                if (contP==1)
                {
                    f=i+1;
                    q=j-1;
                }
            if (m[i][j] == p[contP]|| m[i][j]==p[contP]-'a'+'A' || m[i][j]==p[contP]-'A'+'a')
            {
                contP++;
                if (contP==1)
                {
                    f=i+1;
                    q=j+1;
                }
                if (contP == tamP)
                {
                    cout << "Palavra " << p << " foi localizada horizontalmente a partir de posição (" << f << "," << q << ")." << endl;
                    return true;
                }
            }
            else
            {
                contP=0;
            }
        }
    }
    return false;
}

bool verifVert(char m[M][M], char p[N], int l, int c){ // feito por João 
    int f; 
    int q;
    bool encontrei=false;
    int tamanho = strlen(p);
    int contP=0;
    for(int j=0;j<c;j++){//verifica vertical de cima pra baixo
        for(int i=0;i<l;i++){
           if(m[i][j]==p[contP] || m[i][j]==p[contP]-'a'+'A' || m[i][j]==p[contP]-'A'+'a'){
                contP++;
                if (contP==1)
                {
                    f=i+1;
                    q=j+1;
                }
                if(contP == tamanho){
                    cout<<"Palavra "<<p<<" foi localizada verticalmente a partir de posição (" << f << "," << q << ")."<<endl;
                    encontrei = true;
                    return encontrei;
                }
            }else{
                contP=0;
            }
        }
        for(int i=l;i>=0;i--){//verifica vertical de baixo pra cima
         contP++;
         if (contP==1)
                {
                    f=i-1;
                    q=j+1;
                }
           if(m[i][j]==p[contP] || m[i][j]==p[contP]-'a'+'A' || m[i][j]==p[contP]-'A'+'a'){
                contP++;
                if(contP == tamanho){
                    cout<<"Palavra "<<p<<" foi localizada verticalmente a partir de posição (" << f << "," << q << ")."<<endl;
                    encontrei = true;
                    return encontrei;
                }
            }else{
                contP=0;
            }
        }
    }
    return encontrei;
}

bool verifDiag(char m[M][M], char p[N], int l, int c){ // feito por Cauã
    int f;
    int q;
    int contP = 0;
    int tamP = strlen(p);
    for (int i=0;i<l;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (contP==1)
                {
                    f=i+1;
                    q=j+1;
                }
            int x = i, y = j, contP = 0;
            while (x < l && y < c && (m[x][y] == p[contP] || m[x][y]==p[contP]-'a'+'A' || m[x][y]==p[contP]-'A'+'a'))
            {
                contP++;
                x++;
                y++;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << f+1 << "," << q+1 << ").";
                    return true;
            }
            x = i;
            y = j;
            contP = 0;
            while (x < l && y < c && (m[x][y] == p[contP] || m[x][y]==p[contP]-'a'+'A' || m[x][y]==p[contP]-'A'+'a'))
            {
                contP++;
                x++;
                y--;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << f+1 << "," << q+1 << ").";
                    return true;
            }
            x = i;
            y = j;
            contP = 0;
            while (x < l && y < c && (m[x][y] == p[contP] || m[x][y]==p[contP]-'a'+'A' || m[x][y]==p[contP]-'A'+'a'))
            {
                contP++;
                x--;
                y++;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << f+1 << "," << q+1 << ").";
                    return true;
            }
            x = i;
            y = j;
            contP = 0;
            while (x < l && y < c && (m[x][y] == p[contP] || m[x][y]==p[contP]-'a'+'A' || m[x][y]==p[contP]-'A'+'a'))
            {
                contP++;
                x--;
                y--;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << f+1 << "," << q+1 << ")." << endl;
                    return true;
            }
            x = i;
            y = j;
            contP = 0;
        }
    }
    return false;
}
int main(){
    bool ho, ve, di;
    char m[M][M]={},p[N][N]={};
    int n,k,v;
    cin>>n>>k>>v;
    cin.ignore();
    for(int i=0;i<n;i++){
        cin.getline(p[i],100);
        int TAM = strlen(p[i]);
        while(TAM<4){
            cin.getline(p[i],100);
            TAM = strlen(p[i]);
        }
    }
    for(int j=0;j<k;j++){
        for (int g=0;g<v;g++){
            cin>>m[j][g];
        }
    }
    for(int i=0;i<n;i++){
        ho = false;
        ve = false;
        di = false;
        ho = verifHoriz(m, p[i], k, v);
        ve = verifVert(m, p[i], k, v);
        di = verifDiag(m, p[i], k, v);
        if(ho==false && ve==false && di==false){
        cout << "A palavra " << p << " não foi localizada." << endl;
        }
    }
    return 0;
}