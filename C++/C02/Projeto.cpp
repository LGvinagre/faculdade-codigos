#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib> 

using namespace std;

void cadastrarUsuario() {
    string username, senha;

    cout << "Digite o nome de usuario: ";
    cin >> username;

    cout << "Digite a senha: ";
    cin >> senha;

    
    ofstream arquivo("registros.txt", ios::app);

    if (arquivo.is_open()) {
        arquivo << username << ":" << senha << endl;
        cout << "Usuario registrado com sucesso!" << endl;
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo." << endl;
    }
}


bool verificarLogin(const string& username, const string& senha) {
    ifstream arquivo("registros.txt");
    string linha;

    
    while (getline(arquivo, linha)) {
        stringstream ss(linha);
        string user, pass;

        
        getline(ss, user, ':');
        getline(ss, pass);

        
        if (user == username && pass == senha) {
            return true;  
        }
    }

    return false;  
}
// ==========================================================================================================================================

// LOGIN (FUNÇÕES)

const int MAX_USUARIOS = 100;  // Defina o número máximo de usuários

struct Usuario 
{
    string nomeUsuario;
    string senha;
};

int numUsuarios = 0;  // Contador de usuários

bool usuarioExiste(const Usuario usuarios[], int numUsuarios, const string& nomeUsuario) 
{
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].nomeUsuario == nomeUsuario) {
            return true;  // Nome de usuário já em uso
        }
    }
    return false;  // Nome de usuário disponível
}

void registrarUsuario(Usuario usuarios[]) 
{
    if (numUsuarios >= MAX_USUARIOS) {
        cout << "Limite de usuarios atingido.\n";
        return;
    }

    Usuario novoUsuario;
    cout << "Digite um nome de usuario: ";
    cin >> novoUsuario.nomeUsuario;

    while (usuarioExiste(usuarios, numUsuarios, novoUsuario.nomeUsuario)) {
        cout << "Nome de usuario ja em uso. Tente outro: ";
        cin >> novoUsuario.nomeUsuario;
    }

    cout << "Digite uma senha: ";
    cin >> novoUsuario.senha;

    usuarios[numUsuarios] = novoUsuario;
    ++numUsuarios;

    cout << "Usuario registrado com sucesso!\n";
}

bool fazerLogin(const Usuario usuarios[], int numUsuarios, const string& nomeUsuario, const string& senha) 
{
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].nomeUsuario == nomeUsuario && usuarios[i].senha == senha) {
            return true;  // Login bem-sucedido
        }
    }
    return false;  // Nome de usuário ou senha incorretos
}
// ==========================================================================================================================================

// ==========================================================================================================================================

// SKILL SELECT (FUNÇÕES)

// Função para escolher atividade complementar
string escolherHabilidade() 
{
    cout << "Escolha uma atividade complementar:\n";
    cout << "1. Monitoria"<< endl;
    cout << "2. Voluntario" << endl;
    cout << "3. Iniciacao Cientifica" << endl;
    cout << "4. Fetin" << endl;
    cout << "5. Estagio" << endl;

    int escolha;
    cin >> escolha;

    switch (escolha) 
	{
        case 1:
            return "Monitoria";
        case 2:
            return "Voluntario";
        case 3:
        	return "Iniciacao Cientifica";
  	    case 4: 
  	    	return "Fetin";
    	case 5:
    		return "Estagio";
        default:
            return "Habilidade inválida";
    }
}

// Função para responder à pergunta
int responderPergunta() {
    cout << "Como você avalia sua evolução com essa atividade?" << endl;
    cout << "1 - Muito Negativo" << endl;
    cout << "2 - Razoavelmente Negativo" << endl;
    cout << "3 - Pouco Negativo" << endl;
    cout << "4 - Neutro" << endl;
    cout << "5 - Pouco Positivo" << endl;
    cout << "6 - Razoavelmente Positivo" << endl;
    cout << "7 - Muito Positivo" << endl;

    int escolha;
    cin >> escolha;

    if (escolha >= 1 && escolha <= 7) {
        return escolha;
    } else {
        cout << "Opção inválida. Escolha um número de 1 a 7.\n";
        return -1;  // Valor inválido para indicar um problema na escolha
    }
}

// ==========================================================================================================================================



int main() {
    Usuario usuarios[MAX_USUARIOS];
    bool logado = false;

    while (!logado) 
	{
        cout << "1. Registrar" << endl;
        cout << "2. Login" << endl;;
        cout << "3. Sair" << endl;
        cout << "4. Info AC" << endl;
        cout << "Escolha uma opcao: ";

        int escolha;
        cin >> escolha;

        switch (escolha) 
		{
            case 1:
                registrarUsuario(usuarios);
                break;
            case 2: 
			{
                string nomeUsuario, senha;
                cout << "Digite seu nome de usuario: ";
                cin >> nomeUsuario;
                cout << "Digite sua senha: ";
                cin >> senha;

                if (fazerLogin(usuarios, numUsuarios, nomeUsuario, senha)) 
				{
                    cout << "Login bem-sucedido!" << endl;
                    logado = true;
                } else 
				{
                    cout << "Nome de usuario ou senha incorretos." << endl;;
                }
                break;
            }
            case 3:
                cout << "Saindo..." << endl;
                return 0;
             case 4:
                // Informações sobre atividades complementares
                cout << "=================== Informacoes sobre Atividades Complementares ===================" << endl;
                cout << " " << endl;
                cout << "Aqui teremos informacoes sobre quanto normalmente cada AC te ajuda a evoluir em uma escola de 1-5 para o usuario se basear" << endl;
                cout << " " << endl;
                cout << "1. Monitoria: COMUNICACAO (5/5) ADAPTABILIDADE (4/5) PENSAMENTO CRITlCO (5/5) CRIATIVIDADE (4/5) AUTONOMIA (5/5) LIDERANCA (5/5) ETICA (5/5) EMPATIA (5/5) RESPONSABILIDADE (5/5) INTELIGENCIA EMOCIONAL (4/5)   AUTOGERENCIAMENTO (5/5)" << endl;					
                cout << " " << endl;
				cout << "2. Voluntariado: COMUNICACAO (4/5) ADAPTABILIDADE (4/5) PENSAMENTO CRITlCO (5/5) CRIATIVIDADE (5/5) AUTONOMIA (4/5) LIDERANCA (4/5) ETICA (5/5) EMPATIA (5/5) RESPONSABILIDADE (5/5) INTELIGENCIA EMOCIONAL (4/5) AUTOGERENCIAMENTO (5/5)" << endl;
                cout << " " << endl;
				cout << "3. Iniciação Cientifica: COMUNICACAO (3/5) ADAPTABILIDADE (3/5) PENSAMENTO CRITlCO (5/5) CRIATIVIDADE (4/5) AUTONOMIA (4/5) LIDERANCA (4/5) ETICA (5/5) EMPATIA (4/5) RESPONSABILIDADE (5/5)                     INTELIGENCIA EMOCIONAL (4/5) AUTOGERENCIAMENTO (5/5)" << endl;
                cout << " " << endl;
				cout << "4. Fetin: COMUNICACAO (5/5) ADAPTABILIDADE (5/5) PENSAMENTO CRITlCO (5/5) CRIATIVIDADE (5/5) AUTONOMIA (5/5) LIDERANCA (4/5) ETICA (5/5) EMPATIA (4/5) RESPONSABILIDADE (5/5) INTELIGENCIA EMOCIONAL (5/5)       AUTOGERENCIAMENTO (5/5)" << endl;
                cout << " " << endl;
				cout << "5. Estagio: COMUNICACAO (5/5) ADAPTABILIDADE (5/5) PENSAMENTO CRITlCO (4/5) CRIATIVIDADE (3/5) AUTONOMIA (4/5) LIDERANCA (3/5) ETICA (4/5) EMPATIA (3/5) RESPONSABILIDADE (5/5) INTELIGENCIA EMOCIONAL (5/5)     AUTOGERENCIAMENTO (4/5)" << endl;
                cout << " " << endl;
				cout << "============================================================================" << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente."<< endl;;
        }
    }
    
        string habilidadeEscolhida = escolherHabilidade();
    int resposta = responderPergunta();

    if (resposta != -1) 
	{
        cout << "Você escolheu a habilidade: " << habilidadeEscolhida << endl;
        cout << "Sua resposta à pergunta: " << resposta << " - ";

        switch (resposta) 
		{
            case 1:
                cout << "Muito Negativo" << endl;
                break;
            case 2:
                cout << "Razoavelmente Negativo" << endl;
                break;
            case 3:
                cout << "Pouco Negativo" << endl;
                break;
            case 4:
                cout << "Neutro" << endl;
                break;
            case 5:
                cout << "Pouco Positivo" << endl;
            case 6:
                cout << "Razoavelmente Positivo" << endl;
                break;
            case 7:
                cout << "Muito Positivo" << endl;
                break;
        }
    }
	
    return 0;
}
