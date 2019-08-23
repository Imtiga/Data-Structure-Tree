#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild; //左右孩子指针
}BiTNode, *BiTree;

typedef struct Stack{
    char Stack[30];
    int top;
}Stack;

void Init_Stack(Stack *S){
    S->top = -1;
}

void Stack_Pop(Stack *S){
    printf("%c",S->Stack[S->top]);
    S->top--;
}

void Stack_Push(Stack *S, char data){
    S->top++;
    S->Stack[S->top] = data;
}

BiTree CreateBiTree(){
    //按先序次序输入二叉树中节点的值，空格字符表示空树
    //构造二叉链表表示的二叉树T
    BiTree T;
    char data;
    scanf("%c",&data);
    if (data == '!') T = NULL;
    else{
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = data;
        T->lchild = CreateBiTree();
        T->rchild = CreateBiTree();
        //printf("%c",T->data);
    }
    return T;
}

void InOrderTraverse(BiTree T){
    //中序非递归遍历二叉树
    int i = 0;
    BiTree p, S[30];
    p = T;
    do{
        while(p != NULL){
            S[i++] = p;
            p=p->lchild;
        }
        if(i >0){
            p=S[--i];
            printf("%c",p->data);
            p=p->rchild;
        }
    }while(i>0 || p!=NULL);
}

void PreOrderTraverse(BiTree T){
    //先序遍历二叉树
    int i = 0;
    BiTree p, S[30];
    p = T;
    do{
        while(p != NULL){
            S[i++] = p;
            printf("%c",p->data);
            p=p->lchild;
           
        }
        if(i >0){
            p=S[--i];
            p=p->rchild;
        }
    }while(i>0 || p!=NULL);
}

void Find_elements(BiTree T, char elem){
    //中序遍历二叉树
    int i = 0;
    int flag= 0;
    BiTree p, S[30];
    p = T;
    do{
        while(p != NULL){
            S[i++] = p;
            p=p->lchild;
            
        }
        if(i >0){
            p=S[--i];
            if(p->data == elem){
                //printf("%d\n",i);
                //printf("%c\n",p->data);
                for(int g=0;g<=i;g++){
                    printf("%c\n",S[g]->data);
                }
                flag = 1;
            }
            p=p->rchild;
           
        }
    }while(flag==0 && (i>0 || p!=NULL));
}


int main() {
    printf("A binary tree will be created!\n");
    printf("Plz enter the elemnets:（按先序次序输入） \n");
    printf("Tips:如果到了叶子节点，接下来的左、右子树分别赋值为'!' e.g. 12!!3!!就是2<-1->3这样的二叉树\n");
    BiTree T= (BiTree)sizeof(BiTree);
    T = CreateBiTree();
    printf("中序遍历: \n");
    InOrderTraverse(T);
    printf("\n");
    printf("先序遍历: \n");
    PreOrderTraverse(T);
    printf("\n");
    printf("Which element would you like to find?\n");
    char elem;
    scanf("%c",&elem);
    scanf("%c",&elem);//必须重复scanf才能读到，原因未知
    printf("The path to it is: \n");
    printf("若有重复，只显示离根节点最近的路径。\n");
    Find_elements(T, elem);
    return 0;
}
