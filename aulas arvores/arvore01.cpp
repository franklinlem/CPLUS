#include <iostream>

using namespace std;

struct NodeType{
        Aluno aluno;
        NodeType* esquerda;
        NodeType* direita;
    };

class Aluno{
        private:
            int ra;
            string nome;
        public:
            Aluno();
            Aluno(int ra, string nome);
            string getNome() const;
            int getRa() const;
    Aluno(){
        this -> ra = -1;
        this -> nome = "";
    }
    Aluno(int ra, string nome){
        this -> ra = ra;
        this -> nome = nome;
    }
    string getNome() const{
        return nome;
    }
    int getRa() const{
        return ra;
    }
    };



class SearchTree{
    public:
        SearchTree() {root = NULL;}
        ~SearchTree() {destroyTree(root);}
        bool isEmpty() const {
            return root == NULL;
        }
        bool isFull() const{
            NodeType* location;
            try {
                location = new NodeType;
                delete location;
                return false;
            }
            catch(bad_alloc exception){
                return true;
            }
        }
        void retrieveAluno(Aluno& item, bool& found) const{
            retrieveAluno(root, item, found);
        }
        void insertAluno(Aluno item){insertAluno(root, item);}
        void deleteAluno(int item){deleteAluno(root, item);}
        void printPreOrder() const {printPreOrder(root);}
        void printInOrder() const {printInOrder(root);}
        void printPostOrder() const {printPostOrder(root);}
    private:
        void destroyTree(NodeType*& tree){
            if (tree != NULL){
                destroyTree(tree->esquerda);
                destroyTree(tree->direita);
                delete tree;
            }
        }
        void retrieveAluno(NodeType* tree, Aluno& item, bool& found) const {
            if (tree == NULL)
                found = false;
            else if (aluno.getRa() < tree->aluno.getRa())
                retrieveAluno(tree->esquerda, aluno, found);
            else if (aluno.getRa() > tree->aluno.getRa())
                retrieveAluno(tree->direita, aluno, found);
            else {
                aluno = tree -> aluno;
                found = true;
            }
        }
        void insertAluno(NodeType*& tree, Aluno item){
            if(tree == NULL){
                tree = new NodeType;
                tree -> direita = NULL;
                tree -> esquerda = NULL;
                tree -> aluno = aluno;
            } else if (aluno.getRa() < tree -> aluno.getRa())
                insertAluno(tree->esquerda, aluno);
            else
                insertAluno(tree->direita, aluno);
        }
        void deleteAluno(NodeType*& tree, int item) {
            if (aluno < tree -> aluno.getRa())
                deleteAluno(tree->esquerda, aluno);
            else if (aluno > tree -> aluno.getRa())
                deleteAluno(tree->direita, aluno);
            else if (aluno == tree -> aluno.getRa())
                deleteNode(tree);
        }
        void deleteNode(NodeType*& tree){
            Aluno data;
            NodeType* tempPtr;
            tempPtr = tree;
            if (tree ->esquerda == NULL){
                tree = tree -> direita;
                delete tempPtr;
            }
            else if (tree -> direita == NULL){
                tree = tree -> esquerda;
                delete tempPtr;
            }
            else {
                getSuccessor(tree, data);
                tree -> aluno = data;
                deleteAluno(tree->direita, data.getRa());
            }
        }
        void getSuccessor(NodeType* tree, Aluno& data){
            tree = tree -> direita;
            while (tree -> esquerda != NULL)
                tree = tree -> esquerda;
            data = tree -> aluno;
        }
        void printTree(NodeType* tree) const;
        void printPreOrder(NodeType* tree) const{
            if (tree != NULL){
                cout << tree->aluno.getNome() << " , ";
                printPreOrder(tree->esquerda);
                printPreOrder(tree->direita);
            }
        }
        void printInOrder(NodeType* tree) const{
            if (tree != NULL){
                printInOrder(tree->esquerda);
                cout << tree->aluno.getNome() << ", ";
                printInOrder(tree->direita);
            }
        }
        void printPostOrder(NodeType* tree) const{
            if (tree!= NULL){
                printPostOrder(tree->esquerda);
                printPostOrder(tree->direita);
                cout << tree->aluno.getNome() << ", ";
            }
        }
        NodeType* root;
};

const int NUM_ALUNOS = 8;

int main(){
    SearchTree searchTree;
    int ras[NUM_ALUNOS] =  {20 ,18, 58, 7, 19, 26, 25, 30};
    string nomes[NUM_ALUNOS] = {"PEDRO", "RAUL", "PAULO", "CARLOS", "LUCAS", "MARIA", "SAMANTA", "ULISSES"};
    Aluno alunos[NUM_ALUNOS];
    for (int i = 0;i < NUM_ALUNOS; i++){
        Aluno aluno = Aluno(ras[i], nomes[i]);
        alunos[i] = aluno;
        searchTree.insertAluno(aluno);
    }
    cout << "Pre: ";
    searchTree.printPreOrder();
    cout << endl;
    cout << "In: ";
    searchTree.printInOrder();
    cout << endl;
    cout << "Post: ";
    searchTree.printPostOrder();
    cout << endl;
    return 0;
}