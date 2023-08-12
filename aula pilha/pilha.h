// pilha = stack
typedef int TipoItem;
const int max_itens = 100;

class pilha {
    private:
    int tamanho;
    TipoItem* estrutura;
    public:
    pilha(); //construtora //stack
    ~pilha(); //destrutora //~stack
    bool estacheia(); //verifica se a pilha está cheia //isfull
    bool estavazia(); //verifica se a pilha está vazia //isempty
    void inserir(TipoItem); //ou push
    TipoItem remover(); //ou pop
    void imprimir(); //ou print
    int qualtamanho(); //ou lenght
};