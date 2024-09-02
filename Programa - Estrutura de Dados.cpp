#include <iostream>
#include <cstdlib>
#define MAX_SIZE 10
#include <locale>
#include <limits>
using namespace std;

//Variáveis Utilizadas -----
// Fila e Pilha
int pilha[MAX_SIZE];
int topPilha = -1;

int fila[MAX_SIZE];
int inicioFila = 0;
int fimFila = -1;

// Jogo da Velha
char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

const char playerX = 'V';
const char playerO = '0';
char currentPlayer = playerX;
char vencedor = ' ';

// Batalha Naval
char tabuleiroBatalhaNavalX[10][10];
char tabuleiroBatalhaNavalO[10][10];
char jogadorAtual = 'X';
int pontosJogadorX = 0;
int pontosJogadorO = 0;

// Lista
struct NO {
    int valor;
    NO* prox;
};

// -- LISTA ---------------------------------------------------------------------------------
NO* cria_no(){
    NO* novo = new NO();
    return novo;
}

NO* inserirInicio(NO* lista, int dado) {
    NO* novo_no = cria_no();
    novo_no-> valor = dado;
    novo_no-> prox = lista;
    return novo_no;
}

void deletarLista(NO* &lista){
    while(lista != nullptr){
        NO* temp = lista;
        lista = lista->prox;
        delete temp;
    }
}

void pesquisa(NO* lista){
    system("cls");
    int posicao;
    cout << "Digite a posicao a ser pesquisada: "; cin >> posicao;

    NO* aux = lista;
    int contador = 1;
    while(aux != nullptr){
        if(contador == posicao){
            cout << "Valor da posicao " << posicao << " e: " << aux->valor << endl;
            return;
        }
        aux = aux->prox;
        ++contador;
    }
    cout << "Posicao nao encontrada"<<endl;
}

void ordemDESC(NO* lista){
    int x;
    if(!lista)return;
    for(NO* i = lista; i->prox != nullptr; i = i->prox){
        for(NO* j = i->prox; j != nullptr; j = j->prox){
            if(i->valor < j->valor){
                x = i->valor;
                i->valor = j->valor;
                j->valor = x;
            }
        }
    }
}

void ordemASC(NO* lista){
    int x;
    if(!lista) return;
    for(NO* i = lista; i->prox != nullptr; i = i->prox){
        for(NO* j = i->prox; j != nullptr; j = j->prox){
            if(i->valor > j->valor){
                x = i->valor;
                i->valor = j->valor;
                j->valor = x;
            }
        }
    }
}

void mostrarLista(NO* lista){
    NO* aux = lista;
    while(aux != nullptr){
        cout << aux->valor << ", ";
        aux = aux->prox;
    }
    cout << "Nullptr" << endl;
    cin.get();
    system("cls");
}

void base(NO* &lista){
    char escolha;
    int valor;

    do {
        cout << "Digite um valor para inserir na lista: ";
        cin >> valor;
        lista = inserirInicio(lista, valor);

        cout << "Deseja inserir outro valor? (s/n): ";
        cin >> escolha;
        cin.get();
        system("cls");
    } while (escolha == 's' || escolha == 'S');
}

int menu_lista(){
    NO* lista = nullptr;
    int opcaolista = -1;
    while (opcaolista != 0) {
        cout << "----------------------------------" << endl;
        cout << "         Menu Lista" << endl;
        cout << "----------------------------------" << endl;
        cout << "[1] - Adicionar elemento            " << endl;
        cout << "[2] - Visualizar elemento    " << endl;
        cout << "[3] - Ordenar por ASC          " << endl;
        cout << "[4] - Ordenar por DESC         " << endl;
        cout << "[5] - Pesquisar por posicao " << endl;
        cout << "[0] - Sair do programa                " << endl;
        cout << "---------------------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcaolista;
        cin.ignore(80, '\n');
        system("cls");

        switch (opcaolista) {
            case 1:
                base(lista);
                break;
            case 2:
               mostrarLista(lista);
                break;
            case 3:
                ordemASC(lista);
                break;
            case 4:
                ordemDESC(lista);
                break;
            case 5:
                pesquisa(lista);
                break;
            case 0:
                deletarLista(lista);
                cout << "Programa Encerrado" << endl;
                return 0;
            default:
                cout << "Opcao Invalida " << endl;
                break;
        }
    }
    return 0;
}

// -- PONTEIROS ------------------------------------------------------------------------------
// -- Ponteiros 3 -------------
void ponteiro3 () {
int matriz[5][2];
int *ponteiro;
    cout << " ENDERECO: "<<"|"<<" LIXO: "<< "|"<< "  ENDERECO: "<<"|"<<" LIXO: "<<"|"<<endl;
    cout << "------------------------------------------------------------------------"<<endl;

    for(int i = 0; i < 5; ++i){
        for(int j=0;j<2;++j){
            ponteiro = &matriz[i][j];
            cout << ponteiro <<" | "<< *ponteiro <<" | ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------";
    cout << "\n";
    cout << "Pressione enter para continuar...";
    cin.get();
    system("cls");

    for(int i = 0; i < 5; ++i){
        cout << "Linha "<<i+1<<" e ";
        for(int j = 0;j<2;++j){
            cout << "Coluna " <<j+1<<endl;
            cout <<"Entre um valor: "; cin >> matriz[i][j];
        }
    }
    system("cls");


    cout << "---------------------------------------------------------" << endl;
    cout << "                  Ponteiro Matriz" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " ENDERECO" <<"|"<<" LIXO" << "|"<< "  ENDERECO" << "|"<<" LIXO" <<"|"<<endl;
    for(int i = 0; i < 5; ++i){
        cout << "---------------------------------------------------------" << endl;
        for(int j=0;j<2;++j){
            ponteiro = &matriz[i][j];
            cout << ponteiro << " | "<< *ponteiro << " | ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
    cout << '\n';
    cout << "\n";
    cout << "Pressione enter para continuar...";
    cin.get();
    return;
}

// -- Ponteiros 2 -------------
void ponteiro2 () {
    int vetor[10];
    int *ponteiro;

    cout << "----------------------------------"<<endl;
    cout << "      Ponteiro Vetor"<<endl;
    cout << "----------------------------------"<<endl;
    cout <<"  ENDERECO: "<<"  | "<<" LIXO:    "<<endl;
    cout << "----------------------------------"<<endl;
    for(int i = 0; i < 10; ++i){
       ponteiro = &vetor[i];
       cout << ponteiro <<" | "<< *ponteiro <<endl;
    }
    cout << "\n";
    cout << "Pressione enter para continuar...";
    cin.get();
    system("cls");

    for(int i = 0; i < 10; ++i){
        cout <<"Entre valor "<<i+1<<" :"; cin >> vetor[i];
    }
    cout << "\n";
    cout << "Pressione enter para continuar...";
    cin.get();
    system("cls");

    cout << "----------------------------------"<<endl;
    cout << "      Ponteiro Vetor "<<endl;
    cout << "----------------------------------"<<endl;
    cout <<"  ENDERECO: "<<" | "<<" LIXO:    "<<endl;
    cout << "----------------------------------"<<endl;
    for(int i = 0; i < 10; ++i){
        ponteiro = &vetor[i];
        cout << ponteiro <<" | "<< *ponteiro <<endl;
    }
    cout << "\n";
    cout << "Pressione enter para continuar...";
    cin.get();
    system("cls");
    return;
}
// -- Ponteiros 1 -------------
void ponteiro1() {
int a, b, c, d, e, f, g, i, h, j;
int *pa, *pb, *pc, *pd, *pe, *pf, *pg, *pi, *ph, *pj;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;
    pe = &e;
    pf = &f;
    pg = &g;
    ph = &h;
    pi = &i;
    pj = &j;

    cout << "------------------------------------"<<endl;
    cout << "       Ponteiro Simples "<<endl;
    cout << "------------------------------------"<<endl;
    cout <<"     ENDERECO"<<" | "<<"LIXO "<<endl;
    cout << "------------------------------------"<<endl;
    cout << pa <<" | "<< *pa <<endl;
    cout << pb <<" | "<< *pb <<endl;
    cout << pc <<" | "<< *pc <<endl;
    cout << pd <<" | "<< *pd <<endl;
    cout << pe <<" | "<< *pe <<endl;
    cout << pf <<" | "<< *pf <<endl;
    cout << pg <<" | "<< *pg <<endl;
    cout << ph <<" | "<< *ph <<endl;
    cout << pi <<" | "<< *pi <<endl;
    cout << pj <<" | "<< *pj <<endl;
cout << "\n";
cout << "Pressione enter para continuar...";
cin.get();
system("cls");

cout << "-------------------------------" << endl;
cout << "         Inserir Valor   " << endl;
cout << "-------------------------------" << endl;
cout << "\n";
cout << "Entre valor A: "; cin >> a;
cout << "Entre valor B: "; cin >> b;
cout << "Entre valor C: "; cin >> c;
cout << "Entre valor D: "; cin >> d;
cout << "Entre valor E: "; cin >> e;
cout << "Entre valor F: "; cin >> f;
cout << "Entre valor G: "; cin >> g;
cout << "Entre valor H: "; cin >> h;
cout << "Entre valor I: "; cin >> i;
cout << "Entre valor J: "; cin >> j;
cout << "\n";
cout << "Pressione enter para continuar...";
cin.get();
system("cls");

    cout << "------------------------------------"<<endl;
    cout << "       Ponteiro Simples"<<endl;
    cout << "------------------------------------"<<endl;
    cout <<"     ENDERECO"<<" | "<<"LIXO "<<endl;
    cout << "------------------------------------"<<endl;
    cout << pa <<" | "<< *pa <<endl;
    cout << pb <<" | "<< *pb <<endl;
    cout << pc <<" | "<< *pc <<endl;
    cout << pd <<" | "<< *pd <<endl;
    cout << pe <<" | "<< *pe <<endl;
    cout << pf <<" | "<< *pf <<endl;
    cout << pg <<" | "<< *pg <<endl;
    cout << ph <<" | "<< *ph <<endl;
    cout << pi <<" | "<< *pi <<endl;
    cout << pj <<" | "<< *pj <<endl;
    cout << "\n";
    cout << "Pressione enter para continuar...";
    cin.get();
    system("cls");

    return;
}

// -- Menu Ponteiros -----------
int menu_ponteiros() {
    int opcao_ponteiros = 0;
    while (opcao_ponteiros != 4) {
        system("cls");
        cout << "---------------------------------------------------------" << endl;
        cout << "          Programas 5,6 e 7 - Ponteiros   " << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "[1] - Programa 5 - Ponteiros 1" << endl;
        cout << "[2] - Programa 6 - Ponteiros 2" << endl;
        cout << "[3] - Programa 7 - Ponteiros 3" << endl;
        cout << "[4] - Voltar p/ Menu Principal" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao_ponteiros;
        cin.ignore(80, '\n');
        system("cls");
        if (opcao_ponteiros >= 1 && opcao_ponteiros <= 4) {
            switch(opcao_ponteiros) {
                case 1:
                    ponteiro1();
                    break;
                case 2:
                    ponteiro2();
                    break;
                case 3:
                    ponteiro3 ();
                case 4:
                    return 0;
                default:
                    cout << "Opcao Invalida!" << endl;
                    cout << "\n";
                    break;
            }
        } else {
            cout << "Opcao Invalida!" << endl;
        }
        if (opcao_ponteiros != 3) {
            cout << "\n";
            cout << "Pressione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}
// -- BATALHA NAVAL --------------------------------------------------------------------------
void inicializarTabuleiroBatalhaNaval(char tabuleiro[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            tabuleiro[i][j] = '-';
        }
    }
}

void exibirTabuleiroBatalhaNaval(char tabuleiro[10][10]) {
    system("cls");
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
    system("cls");
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
    system("cls");
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

// -- JOGO DA VELHA --------------------------------------------------------------------------
void limparJogoVelha() {
    for (int l = 0; l < 3; ++l) {
        for (int c = 0; c < 3; ++c) {
            board[l][c] = ' ';
        }
    }
    vencedor = ' ';
    currentPlayer = playerX;
}

void jogoVelha() {
    int l, c;
    for (int i = 0; i < 9; i++) {
        // board
        cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;

        if (vencedor != ' ') {
            break;
        }

        cout << endl;
        cout << "O jogador atual e: " << currentPlayer << endl;
        while (true) {
            cout << "Entre l c de 0-2 para linha e coluna, com espaço (exemplo: 0 2): ";
            cin >> l >> c;
            if (l < 0 || l > 2 || c < 0 || c > 2) {
                cout << "Entrada inválida, tente novamente." << endl;
            } else if (board[l][c] != ' ') {
                cout << "Local/espaco ocupado, tente novamente." << endl;
            } else {
                break;
            }
            cin.clear();
            cin.ignore(10000, '\n');
        }

        board[l][c] = currentPlayer;
        currentPlayer = (currentPlayer == playerX) ? playerO : playerX;

        //checar vencedores
        //linha horizontal
        for (int l = 0; l < 3; ++l) {
            if (board[l][0] != ' ' && board[l][0] == board[l][1] && board[l][1] == board[l][2]) {
                vencedor = board[l][0];
                break;
            }
        }
        //coluna vertical
        for (int c = 0; c < 3; c++) {
            if (board[0][c] != ' ' && board[0][c] == board[1][c] && board[1][c] == board[2][c]) {
                vencedor = board[0][c];
                break;
            }
        }
        //diagonal
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            vencedor = board[0][0];
        } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            vencedor = board[0][2];
        }
    }

    if (vencedor != ' ') {
        limparJogoVelha();
        cout << "Player " << vencedor << " é o vencedor!" << endl;
    } else {
        cout << "Empate!" << endl;
    }
    cout << "Pressione enter para continuar...";
    cin.ignore();
    cin.get();
}

int menu_matrizes() {
    int opcao_matrizes = 0;
    while (opcao_matrizes != 3) {
        system("cls");
        cout << "---------------------------------------------------------" << endl;
        cout << "    Programas 3 e 4 - Jogo da Velha e Batalha Naval   " << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "[1] - Programa 3 - Jogo da Velha" << endl;
        cout << "[2] - Programa 4 - Batalha Naval" << endl;
        cout << "[3] - Voltar p/ Menu Principal" << endl;
        cout << "---------------------------------------------------------" << endl;
        cout << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao_matrizes;
        cin.ignore(80, '\n');
        system("cls");
        if (opcao_matrizes >= 1 && opcao_matrizes <= 3) {
            switch(opcao_matrizes) {
                case 1:
                    jogoVelha();
                    break;
                case 2:
                    jogarBatalhaNaval();
                    break;
                case 3:
                    return 0;
                default:
                    cout << "Opção Inválida!" << endl;
                    cout << "\n";
                    break;
            }
        } else {
            cout << "Opção Inválida!" << endl;
        }
        if (opcao_matrizes != 3) {
            cout << "\n";
            cout << "Pressione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}
// -- FILA --------------------------------------------------------------------------
int adicionarFila() {
    int elemento;
    cout << "Digite o elemento a ser adicionado na fila: ";
    cin >> elemento;
    if (fimFila < MAX_SIZE - 1) {
        fila[++fimFila] = elemento;
        cout << "Elemento adicionado na fila." << endl;
    } else {
        cout << "\n";
        cout << "A fila está cheia!" << endl;
    }
    return 0;
}

int removerFila() {
    if (inicioFila <= fimFila) {
        cout << "Elemento removido da fila: " << fila[inicioFila++] << endl;
        return 0;
    } else {
        cout << "\n";
        cout << "A fila está vazia!" << endl;
        return -1;
    }
}

void visualizarFila() {
    if (inicioFila <= fimFila) {
        cout << "Elementos na fila: ";
        for (int i = inicioFila; i <= fimFila; ++i) {
            cout << fila[i] << " ";
        }
        cout << endl;
    } else {
        cout << "\n";
        cout << "A fila está vazia!" << endl;
    }
}

void menu_Fila() {
    int opcaofila;
    do {
        system("cls");
        cout << "---------------------------------" << endl;
        cout << "        Programa Fila   " << endl;
        cout << "---------------------------------" << endl;
        cout << "[1] - Adicionar elemento" << endl;
        cout << "[2] - Remover elemento" << endl;
        cout << "[3] - Visualizar elemento" << endl;
        cout << "[4] - Sair" << endl;
        cout << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcaofila;
        cin.ignore(80, '\n');
        system("cls");
        switch (opcaofila) {
            case 1:
                adicionarFila();
                break;
            case 2:
                removerFila();
                break;
            case 3:
                visualizarFila();
                break;
            case 4:
                cout << "\n";
                cout << "Saindo do programa Fila..." << endl;
                break;
            default:
                cout << "Opção Inválida" << endl;
                break;
        }
        if (opcaofila != 4) {
            cout << "\n";
            cout << "Pressione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcaofila != 4);
}

// -- PILHA --------------------------------------------------------
int adicionarPilha() {
    int elemento;
    cout << "Digite o elemento a ser adicionado na pilha: ";
    cin >> elemento;
    if (topPilha < MAX_SIZE - 1) {
        pilha[++topPilha] = elemento;
        cout << "Elemento adicionado na pilha." << endl;
    } else {
        cout << "A pilha está cheia!" << endl;
    }
    return 0;
}

void removerPilha() {
    if (topPilha >= 0) {
        cout << "Elemento removido da pilha: " << pilha[topPilha--] << endl;
    } else {
        cout << "A pilha está vazia!" << endl;
    }
}

void visualizarPilha() {
    if (topPilha >= 0) {
        cout << "Elementos na pilha: ";
        for (int i = topPilha; i >= 0; --i) {
            cout << pilha[i] << " ";
        }
        cout << endl;
    } else {
        cout << "\n";
        cout << "A pilha está vazia!" << endl;
    }
}

void menu_pilha() {
    int opcaopilha;
    do {
        system("cls");
        cout << "---------------------------------" << endl;
        cout << "        Programa Pilha   " << endl;
        cout << "---------------------------------" << endl;
        cout << "[1] - Adicionar elemento" << endl;
        cout << "[2] - Remover elemento" << endl;
        cout << "[3] - Visualizar elemento" << endl;
        cout << "[4] - Sair" << endl;
        cout << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcaopilha;
        cin.ignore(80, '\n');
        system("cls");

        switch (opcaopilha) {
            case 1:
                adicionarPilha();
                break;
            case 2:
                removerPilha();
                break;
            case 3:
                visualizarPilha();
                break;
            case 4:
                cout << "\n";
                cout << "Saindo do programa Pilha..." << endl;
                break;
            default:
                cout << "Opção Inválida" << endl;
                break;
        }
        if (opcaopilha != 4) {
            cout << "\n";
            cout << "Pressione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcaopilha != 4);
}

// MENU PROGRAMA 1 E 2 -

int menu_programaPF() {
    int opcaoprogramaPF = 0;
    while (opcaoprogramaPF != 3) {
        system("cls");
        cout << "---------------------------------------" << endl;
        cout << "    Programas 1 e 2 - Pilha e Fila   " << endl;
        cout << "---------------------------------------" << endl;
        cout << "[1] - Programa 1 - Pilha" << endl;
        cout << "[2] - Programa 2 - Fila" << endl;
        cout << "[3] - Voltar p/ Menu Principal" << endl;
        cout << "---------------------------------------" << endl;
        cout << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcaoprogramaPF;
        cin.ignore(80, '\n');
        system("cls");
        if (opcaoprogramaPF >= 1 && opcaoprogramaPF <= 3) {
            switch(opcaoprogramaPF) {
                case 1:
                    menu_pilha();
                    break;
                case 2:
                    menu_Fila();
                    break;
                case 3:
                    return 0;
                default:
                    cout << "Opcao Invalida!" << endl;
                    cout << "\n";
                    break;
            }
        } else {
            cout << "Opcao Invalida!" << endl;
        }
        if (opcaoprogramaPF != 3) {
            cout << "\n";
            cout << "Pressione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
    return 0;
}

// PROGRAMA PRINCIPAL
int main() {
    int opcao = 0;
    while (opcao != 6) {
        system("cls");
        cout << "---------------------------------------------------------------" << endl;
        cout << "              Programa Menu - Menu Principal   " << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "[1] - Programas 1 e 2 - Fila e Pilha" << endl;
        cout << "[2] - Programas 3 e 4 - Jogo da Velha e Batalha Naval" << endl;
        cout << "[3] - Programas de Ponteiro 5, 6 e 7 - Matriz e Vetor" << endl;
        cout << "[4] - Programa de Lista" << endl;
        cout << "[5] - Programa de Grafo" << endl;
        cout << "[6] - Sair do programa" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore(80, '\n');
        system("cls");

        switch (opcao) {
            case 1:
                menu_programaPF();
                break;
            case 2:
                menu_matrizes();
                break;
            case 3:
                menu_ponteiros();
                break;
            case 4:
                menu_lista();
                break;
            case 5:
                cout << "Infelizmente, o programa selecionado nao foi encontrado :( Tente outro! ";
                break;
            case 6:
                cout << "\n";
                cout << "Saindo do programa..." << endl;
                return 0;
            default:
                cout << "Opção Inválida!" << endl;
                cout << "\n";
                break;
        }
        if (opcao != 6) {
            cout << "\n";
            cout << "Pressione enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }
}
