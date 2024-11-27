#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Produto {
public:
    int id;
    string nome;
    int quantidade;

    Produto(int id, string nome, int quantidade) : id(id), nome(nome), quantidade(quantidade) {}
};

class Estoque {
public:
    vector<Produto> produtos;

    void adicionarProduto(int id, string nome, int quantidade) {
        produtos.push_back(Produto(id, nome, quantidade));
        cout << "Produto adicionado com sucesso!\n";
    }

    void removerProduto(int id) {
        for (auto it = produtos.begin(); it != produtos.end(); ++it) {
            if (it->id == id) {
                produtos.erase(it);
                cout << "Produto removido com sucesso!\n";
                return;
            }
        }
        cout << "Produto com ID " << id << " nao encontrado.\n";
    }

    void listarProdutos() {
        if (produtos.empty()) {
            cout << "Nenhum produto no estoque.\n";
        } else {
            cout << "Lista de produtos:\n";
            for (const auto& produto : produtos) {
                cout << "ID: " << produto.id << " | Nome: " << produto.nome << " | Quantidade: " << produto.quantidade << endl;
            }
        }
    }

    void atualizarQuantidade(int id, int novaQuantidade) {
        for (auto& produto : produtos) {
            if (produto.id == id) {
                produto.quantidade = novaQuantidade;
                cout << "Quantidade atualizada com sucesso!\n";
                return;
            }
        }
        cout << "Produto com ID " << id << " nao encontrado.\n";
    }
};

class Funcionario {
public:
    int id;
    string nome;

    Funcionario(int id, string nome) : id(id), nome(nome) {}
};

class GerenciadorFuncionarios {
public:
    vector<Funcionario> funcionarios;

    void adicionarFuncionario(int id, string nome) {
        funcionarios.push_back(Funcionario(id, nome));
        cout << "Funcionario adicionado com sucesso!\n";
    }

    void removerFuncionario(int id) {
        for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
            if (it->id == id) {
                funcionarios.erase(it);
                cout << "Funcionario removido com sucesso!\n";
                return;
            }
        }
        cout << "Funcionario com ID " << id << " nao encontrado.\n";
    }

    void listarFuncionarios() {
        if (funcionarios.empty()) {
            cout << "Nenhum funcionario cadastrado.\n";
        } else {
            cout << "Lista de funcionarios:\n";
            for (const auto& funcionario : funcionarios) {
                cout << "ID: " << funcionario.id << " | Nome: " << funcionario.nome << endl;
            }
        }
    }
};

int main() {
    Estoque estoque;
    GerenciadorFuncionarios gerenciadorFuncionarios;
    int opcao;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Adicionar Produto\n";
        cout << "2. Remover Produto\n";
        cout << "3. Listar Produtos\n";
        cout << "4. Atualizar Quantidade do Produto\n";
        cout << "5. Adicionar Funcionario\n";
        cout << "6. Remover Funcionario\n";
        cout << "7. Listar Funcionarios\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1: {
            int id, quantidade;
            string nome;
            cout << "Digite o ID do produto: ";
            cin >> id;
            cin.ignore();
            cout << "Digite o nome do produto: ";
            getline(cin, nome);
            cout << "Digite a quantidade: ";
            cin >> quantidade;
            estoque.adicionarProduto(id, nome, quantidade);
            break;
        }
        case 2: {
            int id;
            cout << "Digite o ID do produto a ser removido: ";
            cin >> id;
            estoque.removerProduto(id);
            break;
        }
        case 3:
            estoque.listarProdutos();
            break;
        case 4: {
            int id, novaQuantidade;
            cout << "Digite o ID do produto: ";
            cin >> id;
            cout << "Digite a nova quantidade: ";
            cin >> novaQuantidade;
            estoque.atualizarQuantidade(id, novaQuantidade);
            break;
        }
        case 5: {
            int id;
            string nome;
            cout << "Digite o ID do funcionario: ";
            cin >> id;
            cin.ignore();
            cout << "Digite o nome do funcionario: ";
            getline(cin, nome);
            gerenciadorFuncionarios.adicionarFuncionario(id, nome);
            break;
        }
        case 6: {
            int id;
            cout << "Digite o ID do funcionario a ser removido: ";
            cin >> id;
            gerenciadorFuncionarios.removerFuncionario(id);
            break;
        }
        case 7:
            gerenciadorFuncionarios.listarFuncionarios();
            break;
        case 0:
            cout << "Saindo do sistema...\n";
            break;
        default:
            cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

return 0;
}