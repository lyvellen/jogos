#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std ;

int main (){
     cout << "**************************************" <<  endl;
     cout << "Bem vindos ao jogo da advinhação!" << endl;
     cout << "\nVamos descobrir o número secreto!\n"<< endl;
     cout << "\n**************************************" << endl;

cout << "Escolha o seu nível de dificuldade:" << endl;
cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;
char dificuldade;
cin >> dificuldade;

int numero_de_tentativas;

if(dificuldade == 'F'){
    numero_de_tentativas = 15;
}
else if(dificuldade == 'M'){
    numero_de_tentativas = 10;
}
else {
    numero_de_tentativas = 5;
}
srand(time(NULL));
const int NUMERO_SECRETO= rand() % 100;



bool nao_acertou=true;
int tentativas =0;

double pontos= 1000.0; 

for(tentativas =1;tentativas <= numero_de_tentativas;tentativas++) {
 
 int chute; 
 cout<<"Tentativa "<<  tentativas <<endl;
 cout<< "Qual seu palpite?" <<endl;
 cin >> chute;

 double pontos_perdidos= abs(chute - NUMERO_SECRETO)/2.0;
 pontos -= pontos_perdidos;

 cout <<"\no valor do seu chute é: "<< chute <<endl;
 bool acertou = chute == NUMERO_SECRETO;
 bool maior = chute > NUMERO_SECRETO;

 if (acertou)
        {
            cout << "Exato!! Você acertou o número secreto!" << endl;
            nao_acertou = false;
            break;
        }

  
   else if (maior)
   {
      cout << "\nhmm, passou longe. Tente novamente\n" <<endl; 
  }
   else {
      cout << "\nSeu numero foi menor. Tente novamente!"<<endl;
  }

}
  cout<<"\nEndgame!"<<endl;
 
 if(nao_acertou) {
     cout<<"você perdeu, tente novamente!";
 }
 else {
    cout<<"Você acertou o número secreto em " << tentativas <<" tentativas" <<endl;
    cout.precision(2);
    cout<< fixed;
    cout<<"Sua pontuação foi de "<< pontos << " pontos. " << endl;
 }

}



