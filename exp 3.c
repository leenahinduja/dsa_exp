#include<stdio.h>
#define MAX 100
int arr[MAX];
int front=-1,rear=-1;
int enqueue(int data){
    if(rear==MAX-1){
        return -1;
    }
    if(front==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    arr[rear]=data;
    return 1;
}
int dequeue(){
    if(front==-1){
        return -1;
    }
    int data=arr[rear];
    if(front==rear){
        front=rear=-1;
    }else{
        front++;
    }
    return data;
}
int peek(){
    if(front==-1){
        return -1;
    }
    return arr[rear];
}
void display(){
    int i;
    if(front==-1){
        printf("Array is empty");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d\t",arr[i]);
        }
    }
        printf("\n");
}
void main(){
    enqueue(12);
    display();
    enqueue(9);
    display();
    enqueue(8);
    display();
    enqueue(7);
    display();
    printf("%d",peek());
}
