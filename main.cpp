#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;


struct Node
{
    char name[10];              //��� ����
    Node *left;                     //����� �����
    Node *right;                    //������ �����
};

Node *tree = NULL;

void addNode(char a[10], Node **t)
{
    if ((*t) == NULL)
    {
        (*t) = new Node;
        strcpy((*t)->name, a);
        (*t)->left = (*t)->right = NULL;
        return;
    }

    int m = -1;
    if ((*t)->right == NULL)
        cout << endl <<" ��� ������ �����, ��������, ����� ������� ����";
    else
        cout << "\n������ ���� � ������: " << (*t)->right->name;

    if ((*t)->left == NULL)
        cout << endl <<" ��� ����� �����, ��������, ����� ������� ����";
    else
        cout << "\n����� ���� � ������: " << (*t)->left->name;
    cout << endl << "0 - ������� ���� ,1 - ������� �����: " ;

    cin >> m;
    switch ( m ) {
    case 0:
        if ((*t)->left == NULL){
            (*t)->left = new Node;

            strcpy((*t)->left->name, a);
            (*t)->left->left = (*t)->left->right = NULL;
        }
        else
            addNode(a, &(*t)->left);
      break;
    case 1:
      if ((*t)->right == NULL){
            (*t)->right = new Node;
            strcpy((*t)->right->name, a);
            (*t)->right->left = (*t)->right->right = NULL;
        }
        else
            addNode(a, &(*t)->right);
      break;
    default:
      cout << "������������ ����";
      return;
      break;
    }
/*
if (m==0)
    {
        if ((*t)->left == NULL){
            (*t)->left = new Node;

            strcpy((*t)->left->name, a);
            (*t)->left->left = (*t)->left->right = NULL;
        }
        else
            addNode(a, &(*t)->left);
    }
    else
    {
        if ((*t)->right == NULL){
            (*t)->right = new Node;
            strcpy((*t)->right->name, a);
            (*t)->right->left = (*t)->right->right = NULL;
        }
        else
            addNode(a, &(*t)->right);
    }


 */
}


int main ()
{
    setlocale(LC_ALL, "rus");
    int n;
    char s[10];
    cout << "������� ���-�� ���������: ";
    cin >> n;

    for (int i=0; i<n; ++i)
    {
        cout << endl << "������� ��� ���� (���� 10 ��������): ";
        cin >> s;

        addNode(s, &tree);
    }
    cout << endl << "���� ������\n";
    print(tree, 0);
    cin.ignore().get();

}
