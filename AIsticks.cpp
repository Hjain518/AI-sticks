#include<iostream>
#include<ctype.h>
#include<malloc.h>
#define N 1000
using namespace std;
struct node{
    int text,level;
    int win;
    struct node *next1,*next2,*next3;
};
int min_max(struct node *parent){
    int best=1;
    if(parent->text==0){
        if(parent->level%2==0) return 1;
        else return 0;
    }else{
        struct node *child1;
        struct node *child2;
        struct node *child3;
        child1=(struct node *)malloc(sizeof(struct node));
        child2=(struct node *)malloc(sizeof(struct node));
        child3=(struct node *)malloc(sizeof(struct node));
        child1->text=parent->text-1;
        child2->text=parent->text-2;
        child3->text=parent->text-3;
        child1->level=parent->level+1;
        child2->level=parent->level+1;
        child3->level=parent->level+1;
        parent->next1=child1;
        parent->next2=child2;
         parent->next3=child3;
        if(parent->level%2==0){
            child1->win=0;
            child2->win=0;
            child3->win=0;
        }else{
            child1->win=1;
            child2->win=1;
            child3->win=1;
        }
        int winn1=0,losss1=0;
        int winn2=0,losss2=0;
        int winn3=0,losss3=0;
       for(int i=0;i<N;i++)
           {if(child1->win==1) winn1++;
            else if(child1->win==0) losss1++;
            if(child2->win==1) winn2++;
            else if(child2->win==0) losss2++;
            if(child3->win==1) winn3++;
            else if(child3->win==0) losss3++;
           }
        if(parent->text-1>=0) child1->win=min_max(child1);
        if(parent->text-2>=0){
            if(parent->level%2==0){
                if(child1->win!=1) child2->win=min_max(child2);
            }
        else
                if(child1->win!=0) child2->win=min_max(child2);
        }
        if(parent->text-3>=0){
          if(parent->level%2==0){
            if(child1->win!=1&&child2->win!=1) child3->win=min_max(child3);
                else {};
            }
          else{
                if(child1->win!=0&&child2->win!=0) child3->win=min_max(child3);
                else {};
            }
        }
        if(parent->level%2==0){
          if(child1->win==1||child2->win==1||child3->win==1) parent->win=1;
            else parent->win=0;
        }
        else{
            if(child1->win==1&&child2->win==1&&child3->win==1)
               { if(parent->level!=0) parent->win=1;
                 else if(parent->level==0) parent->win=0;
               }
            else parent->win=0;
        }
        if(parent->level==0){
            if(parent->win==1){
                if(child1->win==1) return 1;
                else if(child2->win==1) return 2;
                else return 3;
            }
            else return 1;
        }else{
            if(parent->win==1) return 1;
            else return 0;
        }
    }
    return 0;
}
int choose_chance(int n,int turn,int cases){
    int chance;
    if(n<=0) return turn;
    else if(turn==0||cases==1)
       {
        struct node *parent,*child1,*child2,*child3;
        parent=(struct node *)malloc(sizeof(struct node));
        parent->text=n;
        parent->level=0;
        parent->win=0;
        child1=(struct node *)malloc(sizeof(struct node));
        child2=(struct node *)malloc(sizeof(struct node));
        child3=(struct node *)malloc(sizeof(struct node));
        chance=min_max(parent);
        cout<<"A.I "<<turn+1<<": "<<chance<<"\n";
        if(turn==1) turn=0;
        else turn=1;
        return choose_chance(n-chance,turn,cases);
       }
    else{
        cout<<"my turn: ";
        cin>>chance;
        if(turn==1) turn=0;
        else turn=1;
        int winn1=0;
        int winn2=0;
        int winn3=0;
       for(int i=0;i<N;i++)
           {for(int j=i;j<N;j++)
               if(turn==1)   winn1++;
               if(turn==2)   winn2++;
               if(turn==3)   winn3++;
           }
        return choose_chance(n-chance,turn,cases);
    }
}
int main(){
        int Case,n,turn,win;
        cout<<"Case no 1 or 2: ";
        cin>>Case;
         if(Case==1){
            cout<<"n: ";
            cin>>n;
            turn=rand()%2;
            win=choose_chance(n,turn,0);
        }else if(Case==2){
            cout<<"n: ";
            cin>>n;
            turn=rand()%2;
            win=choose_chance(n,turn,1);
        }
        cout<<"Player/AI "<< 1+win<<"won!!"<<"\n";
}
