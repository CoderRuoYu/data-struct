#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include "test.h"
typedef struct {
    ElemType* elem;   
    int count;          
    int sizeindex;   
} HashTable;

Status SearchHash(HashTable H, KeyType K, int& p, int& c) {
   
    p = K % 11;
    while (H.elem[p] != 0 && H.elem[p] != K) {
        c++;       
        p = p + c;
    }
    if (H.elem[p] == K)return SUCCESS;
    else return UNSUCCESS; 
}
Status InsertHash(HashTable& H, ElemType e) {
    int c = 0;  
    int p;
    if (SearchHash(H, e, p, c) == SUCCESS) {
        return DUPLICATE;
    }
    else if (c < H.sizeindex) {
        H.elem[p] = e;
        H.count++;
        return SUCCESS;
    }
}

typedef  struct {
    ElemType* elem;
    int  length;           
} SSTable;

typedef struct BiNode {
    ElemType data;
    struct BiNode* LChild, * RChild;
}BiNode, * BiTree;

int Search(SSTable ST, KeyType key) {
    ST.elem[0] = key;
    int i = ST.length;
    for (; i != key; i--);
    return i;// 找不到时，i为0

}

Status Search_BST(BiTree T, KeyType key, BiTree& temp, BiTree ftemp) {
    if (!T) {
        temp = ftemp;
        return FALSE;
    }
    else  if (T->data == key) {
        temp = T;
        return TRUE;
    }
    else if (T->data > key) {
        Search_BST(T->LChild, key, temp, T);
    }
    else {
        Search_BST(T->RChild, key, temp, T);
    }
}

Status Insert_BST(BiTree& T, ElemType e)
{ 
    BiTree temp;
    if (!Search_BST(T, e, temp, NULL)) {
        BiTree new_temp = (BiTree)calloc(sizeof(struct BiNode), 1);
        new_temp->LChild = new_temp->RChild = NULL;
        new_temp->data = e;
        if (!temp) {
            T = new_temp;   //空树的情况
        }
        else if (e > temp->data) {
            temp->RChild = new_temp;
        }
        else {
            temp->LChild = new_temp;
        }
        return TRUE;
    }
    else return FALSE;
} // Insert BST

Status Delete_BST(BiTree& T, ElemType key) {
    if (!T) {
        return FALSE;    //树为空
    }
    else if (T->data == key) {
        BiTree temp = T;
        if (!T->RChild) {  //只有左子树
            temp = T;
            T = T->LChild;
            free(temp);
        }
        else if (!T->LChild) {
            temp = T;
            T = T->RChild;
            free(temp);
        }
        else {   //左右子树都有
            BiTree new_temp;   //寻找左子树最大的元素替代这个位置
            //这个元素在左子树的最右边
            new_temp = T->LChild;
            while (new_temp->RChild) {
                temp = new_temp;
                new_temp = new_temp->RChild;
            }
            T->data = new_temp->data;   //替代
            temp->RChild = new_temp->LChild;   //这个位置只有左子树
            free(new_temp);
        }
        return OK;
    }
    else if (T->data > key) {  //查找该元素的位置
        Delete_BST(T->LChild, key);
    }
    else {
        Delete_BST(T->RChild, key);
    }
}

int Search_Bin(SSTable ST, KeyType key) {
    //二分查找
    int low = 1, high = ST.length, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ST.elem[mid] == key)
            return mid;
        else if (ST.elem[mid] > key)
            high = mid - 1;
        else {
            low = mid + 1;
        }
    }
    return 0;
}

Status DiguiInOrderTraverse(BiTree T) {
    //递归中序遍历二叉树
    if (T) {
        DiguiInOrderTraverse(T->LChild);
        printf("%d ", T->data);
        DiguiInOrderTraverse(T->RChild);
    }
    return OK;
}

Status InOrderSearch(BiTree T) {
    if (T) {
        InOrderSearch(T->LChild);
        printf("%d ", T->data);
        InOrderSearch(T->RChild);
    }
    return OK;
}
int main() {
    BiTree T = NULL, temp;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf_s("%d", &m);
        Insert_BST(T, m);

    }
    printf("中序遍历：\n");
    DiguiInOrderTraverse(T);
    HashTable H;
    H.elem = (int*)calloc(sizeof(int), 11);
    H.count = 0;
    H.sizeindex = 12;
    for (int i = 0; i < 11; i++) {
        int m;
        scanf_s("%d", &m);
        InsertHash(H, m);

    }
    //InOrderSearch(T);
    //Delete_BST(T,50);
    for (int i = 0; i < 11; i++) {
        printf("%d ", H.elem[i]);
    }
}