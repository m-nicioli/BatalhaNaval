#include <iostream>
#include <locale>
#include <limits>
using namespace std;

char tabuleiroBatalhaNavalX[10][10];
char tabuleiroBatalhaNavalO[10][10];
char jogadorAtual = 'X';
int pontosJogadorX = 0;
int pontosJogadorO = 0;

void inicializarTabuleiroBatalhaNaval(char tabuleiro[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            tabuleiro[i][j] = '-';
        }
    }
}

void exibirTabuleiroBatalhaNaval(char tabuleiro[10][10]) {
    cout << "### Batalha Naval ###" << endl;
    cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i << " ";
        for (int j = 0; j < 10; ++j) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

void posicionarNavios(char tabuleiro[10][10]) {
    cout << "Posicione seus navios." << endl;
    exibirTabuleiroBatalhaNaval(tabuleiro);
    for (int n = 1; n <= 5; ++n) { // Supondo que cada jogador tem 5 navios
        int linha, coluna;
        cout << "Posicione o navio " << n << " (linha e coluna - 0 a 9): ";
        cin >> linha >> coluna;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

        if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10 && tabuleiro[linha][coluna] == '-') {
            tabuleiro[linha][coluna] = 'N';
        } else {
            cout << "Posição inválida ou ocupada. Tente novamente." << endl;
            --n; // Repetir a iteração para a mesma posição
        }
    }
}

void realizarAtaque(char tabuleiro[10][10], char tabuleiroOponente[10][10], int& pontosJogador) {
    int linha, coluna;
    cout << "Jogador " << jogadorAtual << ", é sua vez. Digite a linha e a coluna (0-9): ";
    cin >> linha >> coluna;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada

    if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10) {
        if (tabuleiroOponente[linha][coluna] == 'N') {
            cout << "Acertou um navio!" << endl;
            tabuleiro[linha][coluna] = '*';
            tabuleiroOponente[linha][coluna] = '*';
            pontosJogador++;
        } else if (tabuleiroOponente[linha][coluna] == '-') {
            cout << "Água!" << endl;
            tabuleiro[linha][coluna] = 'O';
            tabuleiroOponente[linha][coluna] = 'O';
        } else {
            cout << "Posição já atacada. Tente novamente." << endl;
            realizarAtaque(tabuleiro, tabuleiroOponente, pontosJogador); // Ataque repetido, solicitar nova coordenada
        }
    } else {
        cout << "Posição inválida. Tente novamente." << endl;
        realizarAtaque(tabuleiro, tabuleiroOponente, pontosJogador); // Coordenadas fora do tabuleiro, solicitar nova coordenada
    }
}

bool verificarVitoriaBatalhaNaval(int pontosJogador) {
    return pontosJogador == 5; // O jogador vence quando todos os navios do oponente forem destruídos
}

void jogarBatalhaNaval() {
    inicializarTabuleiroBatalhaNaval(tabuleiroBatalhaNavalX);
    inicializarTabuleiroBatalhaNaval(tabuleiroBatalhaNavalO);

    posicionarNavios(tabuleiroBatalhaNavalX); // Posicionar os navios do jogador X
    posicionarNavios(tabuleiroBatalhaNavalO); // Posicionar os navios do jogador O

    while (true) {
        if (jogadorAtual == 'X') {
            exibirTabuleiroBatalhaNaval(tabuleiroBatalhaNavalX); // Mostrar tabuleiro do jogador atual
            realizarAtaque(tabuleiroBatalhaNavalX, tabuleiroBatalhaNavalO, pontosJogadorX);
        } else {
            exibirTabuleiroBatalhaNaval(tabuleiroBatalhaNavalO); // Mostrar tabuleiro do jogador atual
            realizarAtaque(tabuleiroBatalhaNavalO, tabuleiroBatalhaNavalX, pontosJogadorO);
        }

        if (verificarVitoriaBatalhaNaval((jogadorAtual == 'X' ? pontosJogadorX : pontosJogadorO))) {
            cout << "Jogador " << jogadorAtual << " venceu!" << endl;
            break;
        }

        jogadorAtual = (jogadorAtual == 'X' ? 'O' : 'X'); // Trocar de jogador
    }

    // Exibir o resultado final da batalha naval
    cout << "Resultado final da Batalha Naval:" << endl;
    cout << "Pontos do jogador X: " << pontosJogadorX << endl;
    cout << "Pontos do jogador O: " << pontosJogadorO << endl;
    if (pontosJogadorX > pontosJogadorO) {
        cout << "Jogador X venceu!" << endl;
    } else if (pontosJogadorO > pontosJogadorX) {
        cout << "Jogador O venceu!" << endl;
    } else {
        cout << "Empate!" << endl;
    }
}

int main() {
    jogarBatalhaNaval();
    return 0;
}
