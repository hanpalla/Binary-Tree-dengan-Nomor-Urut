#include <stdio.h>
#include <stdlib.h>

typedef struct node tree;

struct node
{
    int angka;
    int absen;
    tree *left;
    tree *right;
};

tree *newNode;
tree *root = NULL;
tree *bantu, *temp;

void tambah(int value);
void tampil();
void cari(tree *root, int nomor);
void cetak(tree *root);

int flag = 0;

int main(){
    int urut;
    system("cls");
    printf("PROGRAM BINARY TREE SEDERHANA DENGAN NOMOR URUT.\n\n");

    tambah(10);
    tambah(23);
    tambah(47);
    tambah(8);
    tambah(22);
    tambah(30);
    tambah(4);
    
    printf("\nInput Nomor Urut\t: ");
    scanf("%d", &urut);

    cari(root, urut);
    if(flag == 0)
        printf("Ketersediaan\t\t: Tidak ada\n\n");
    else
        printf("Ketersediaan\t\t: Ada\n\n");

    printf("Angka dalam Tree yang tersedia.\n--------------------------\n");
    cetak(root);

}

void tambah(int value){
    int x = 1;

    newNode = (tree *)malloc(sizeof(tree));
    newNode->angka = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->absen = x;

    if(root == NULL)
        root = newNode;
    else{
        bantu = root;
        temp = root;
        while(bantu != NULL){
            temp = bantu;
            if(temp->angka > newNode->angka){
                x = x * 2;
                bantu = temp->left;
            }
            else{
                x = (x * 2) + 1;
                bantu = temp->right;
            }
        }
        if(temp->angka > newNode->angka){
            temp->left = newNode;
            newNode->absen = x;
        }
        else{
            temp->right = newNode;
            newNode->absen = x;
        }
    }
}

void cari(tree *root, int nomor){
    if(root != NULL){
        if(root->absen == nomor)
            flag = 1;
        cari(root->left, nomor);
        cari(root->right, nomor);
    }
}

void cetak(tree *root){
    if(root != NULL){
        printf("Nomor urut %d",root->absen);
        printf(" dengan angka %d.\n",root->angka);
        cetak(root->left);
        cetak(root->right);
    }
}
