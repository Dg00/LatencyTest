//
//  main.c
//  latencytest
//
//  Created by Dhiraj Gupta on 26/01/20.
//  Copyright © 2020 Dhiraj Gupta. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ONE ptr = ptr->next;
#define FOUR    ONE ONE ONE ONE
#define EIGHT  FOUR FOUR
#define TH2   EIGHT EIGHT EIGHT EIGHT
#define HUNDRED28 TH2 TH2 TH2 TH2


struct node {
    struct node *next;
    //int data;
};
struct node *head = NULL;
struct node *head2,*head3 = NULL;
struct node *ptr = NULL;
void create(int size,struct node **hd){
    
    for (int i =0; i<size;i++){
        struct node *link = (struct node*) malloc(sizeof(struct node));
        link->next = *hd;
        //link->data = i;
        *hd = link;
    }
}
void print(){
    
    ptr = head;
    while(ptr != NULL){
        //printf("data %d\n",ptr->data);
        ptr = ptr->next;
        
    }
}

int main(){
    
    
    const int L1_SIZE =  32768/sizeof(struct node);
    const int L2_SIZE =  262144/sizeof(int);
    const int L3_SIZE =  6291456/sizeof(int);
    const int NS_IN_SEC = 1000000000;
    int count=L1_SIZE/128;
    int index=0;
    double memAccessTime, cacheL1AccessTime, cacheL2AccessTime;
    struct timespec startTime, endTime;
    create(L1_SIZE,&head);
    create(L2_SIZE,&head2);
    create(L3_SIZE,&head3);
    //print();
     ptr = head;
     
     clock_gettime(CLOCK_REALTIME, &startTime);
     while(index<count){
         HUNDRED28;
         index ++;
     }
     clock_gettime(CLOCK_REALTIME, &endTime);
     
     memAccessTime = (((endTime.tv_sec - startTime.tv_sec)*NS_IN_SEC)+(endTime.tv_nsec - startTime.tv_nsec));
     //memAccessTime /= count*100;
     printf("Memorytime %lf\n",memAccessTime);
     
     
     
     clock_gettime(CLOCK_REALTIME, &startTime);
     while(index<count){
         HUNDRED28
         index ++;
     }
     clock_gettime(CLOCK_REALTIME, &endTime);
     
     cacheL1AccessTime = (((endTime.tv_sec - startTime.tv_sec)*NS_IN_SEC)+(endTime.tv_nsec - startTime.tv_nsec));
     //cacheL1AccessTime /= L1_SIZE;
     printf("L1time %lf\n",cacheL1AccessTime);
    
    return 0;
}

