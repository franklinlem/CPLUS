#include <iostream>

using namespace std;

class Aluno{
        private:
            int ra;
            string nome;
        public:
            Aluno();
            Aluno(int ra, string nome);
            string getNome() const;
            int getRa() const;
    };

struct NodeType{
        Aluno aluno;
        NodeType *esquerda;
        NodeType *direita;
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
        void retrieveAluno(NodeType* tree, Aluno& aluno, bool& found) const {
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
        void insertAluno(NodeType*& tree, Aluno aluno){
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
        void deleteAluno(NodeType*& tree, int item);
        void deleteNode(NodeType*& tree);
        void getSuccessor(NodeType* tree, Aluno& data);
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

Aluno::Aluno(){
        this->ra = -1;
        this->nome = " ";
    };
    Aluno::Aluno(int ra, string nome){
        this->ra = ra;
        this->nome = nome;
    }
    string Aluno::getNome() const{
        return nome;
    }
    int Aluno::getRa() const{
        return ra;
    }

int main(){

    return 0;
}