#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> senhasGeradas;
    queue<int> senhasAtendidas;
    int senhaAtual = 0;
    int opcao;

    do {
        cout << "Selecione uma opcao:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Gerar senha" << endl;
        cout << "2. Realizar atendimento" << endl;
        cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cin >> opcao;

        switch(opcao) {
            case 1:
                senhaAtual++;
                senhasGeradas.push(senhaAtual);
                cout << "Senha gerada: " << senhaAtual << endl;
                break;
            case 2:
                if (!senhasGeradas.empty()) {
                    int senhaAtendida = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senhaAtendida);
                    cout << "Atendendo senha: " << senhaAtendida << endl;
                } else {
                    cout << "Nenhuma senha para atender." << endl;
                }
                break;
            case 0:
                if (!senhasGeradas.empty()) {
                    cout << "Ainda ha senhas aguardando atendimento. Termine os atendimentos antes de sair." << endl;
                    opcao = -1; // Evitar a saida do loop
                }
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                break;
        }
    } while(opcao != 0);

    cout << "Sistema encerrado. Total de senhas atendidas: " << senhasAtendidas.size() << endl;

    return 0;
}
