#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* aux = primeiro;
	while (aux != NULL) {
        	if (aux->valor == novo->valor) {
			cout << "ja existe um elemento com esse valor! \n";
			free(novo);
			return;
       		}
		aux = aux->prox;
    	}

    	if (primeiro == NULL || primeiro->valor > novo->valor) {
        	novo->prox = primeiro;
        	primeiro = novo;
    	} else {
        	NO* anterior = NULL;
        	aux = primeiro;
        	while (aux != NULL && aux->valor < novo->valor) {
           		anterior = aux;
            		aux = aux->prox;
        	}
        	anterior->prox = novo;
		novo->prox = aux;
    	}

    	cout << "elemento inserido! \n";
}

void buscarElemento()
{
	int valorBusca;
	cout << "digite o valor que deseja buscar: ";
	cin >> valorBusca;

	NO* aux = primeiro;
	while (aux != NULL && aux->valor <= valorBusca) {
        	if (aux->valor == valorBusca) {
            		cout << "o elemento esta na lista. \n";
            		return;
        	}
        	aux = aux->prox;
    	}
	
	cout << "o elemento nao foi encontrado. \n";
}

void excluirElemento()
{
	int valorExcluir;
	cout << "digite o valor que deseja excluir: ";
	cin >> valorExcluir;

    	NO* aux = primeiro;
	NO* anterior = NULL;

    	while (aux != NULL && aux->valor < valorExcluir) {
        	anterior = aux;
        	aux = aux->prox;
   	}

    	if (aux != NULL && aux->valor == valorExcluir) {
        	if (anterior == NULL) {
            	primeiro = aux->prox;
        	} else {
        		anterior->prox = aux->prox;
        	}
        	free(aux);
        	cout << "elemento excluido! \n";
	} else {
        	cout << "o elemento nao foi encontrado. \n";
	}
}
