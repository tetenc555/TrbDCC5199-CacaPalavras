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

bool verifHoriz(char m[M][M], char p[], int l, int c) // feito por Estêvão
{
    int tamP = strlen(p),contP=0;
    for (int i=0;i<l;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (m[i][j] == p[contP])
            {
                contP++;
                if (contP == tamP)
                {
                    cout << "Palavra " << p << " foi localizada horizontalmente a partir de posição (" << i+1 << "," << j+1 << ").";
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

bool verifVert(char m[M][M], char p[], int l, int c){ // feito por João 
    bool encontrei=false;
    int tamanho = strlen(p);
    int h=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(m[j][i]==p[h]){
                h++;
                if(h == tamanho){
                    cout<<"Palavra "<<p<<" foi localizada verticalmente a partir de posição ("<<j+1<<","<<i++<<").";
                    encontrei = true;
                    return encontrei;
                }
            }else{
                h=0;
            }
        }
    }
    return encontrei;
}

bool verifDiag(char m[M][M], char p[], int l, int c){
    int tamP = strlen(p);
    for (int i=0;i<l;i++)
    {
        for (int j=0;j<c;j++)
        {
            int x = i, y = j, contP = 0;
            while (x < l && y < c && m[x][y] == p[contP])
            {
                contP++;
                x++;
                y++;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << i+1 << "," << j+1 << ").";
                    return true;
            }
            while (x < l && y < c && m[x][y] == p[contP])
            {
                contP++;
                x++;
                y--;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << i+1 << "," << j+1 << ").";
                    return true;
            }
            while (x < l && y < c && m[x][y] == p[contP])
            {
                contP++;
                x--;
                y++;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << i+1 << "," << j+1 << ").";
                    return true;
            }
            while (x < l && y < c && m[x][y] == p[contP])
            {
                contP++;
                x--;
                y--;
                if (contP == tamP)
                    cout << "A palavra " << p << " foi localizada diagonalmente a partir de posição (" << i+1 << "," << j+1 << ").";
                    return true;
            }
        }
    }
    return false;
}

int main(){
    char m[M][M],p[N];
    int n,k,v;
    cin>>n>>k>>v;
    cin.ignore();
    for(int i=0;i<n;i++){
        bool ho,ve,di;
        cin.getline(p,100);
        int TAM = strlen(p);
        while(TAM<4){
            cin.getline(p,100);
        }
        ho=verifHoriz(m, p, k, v);
        ve=verifVert(m, p, k, v);
        di=verifDiag(m, p, k, v);
        if (ho==false && ve==false && di==false)
        {
            cout<<"A palavra "<<p<<" não foi localizada."<<endl;
        }
    }
    return 0;
}