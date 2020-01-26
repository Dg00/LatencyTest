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
    int data;
};
struct node *head_org, *head2_org, *head3_org = NULL;
struct node *head_invalidate, *head2_invalidate, *head3_invalidate = NULL;
struct node *ptr = NULL;
void create(int size,struct node **hd){
    
    for (int i =0; i<size;i++){
        struct node *link = (struct node*) malloc(sizeof(struct node));
        link->next = *hd;
        link->data = i;
        *hd = link;
    }
}
/*
 void print(){
 
 ptr = head_org;
 while(ptr != NULL){
 //printf("data %d\n",ptr->data);
 ptr = ptr->next;
 
 }
 }
 */

int main(){
    
    
    const int L1_SIZE =  32768/sizeof(struct node);
    const int L2_SIZE =  262144/sizeof(struct node);
    const int L3_SIZE =  6291456/sizeof(struct node);
    const int NS_IN_SEC = 1000000000;
    int countL1=L1_SIZE/128;
    int countL2=L2_SIZE/128;
    int countL3=L3_SIZE/128;
    int index=0;
    double memAccessTime, cacheL1AccessTime, cacheL2AccessTime, cacheL3AccessTime;;
    struct timespec startTime, endTime;
    create(L1_SIZE,&head_org);
    create(L1_SIZE,&head_invalidate);
    create(L2_SIZE,&head2_org);
    create(L2_SIZE,&head2_invalidate);
    create(L3_SIZE,&head3_org);
    create(L3_SIZE,&head3_invalidate);
    //print();
    ptr = head3_invalidate;
    
    for (int i =1;i<100;i++){
        while(index<countL1){
            HUNDRED28;
            index ++;
        }
    }
    
    
    ptr = head_org;
    index=0;
    clock_gettime(CLOCK_REALTIME, &startTime);
    while(index<countL1){
        HUNDRED28;
        index ++;
    }
    clock_gettime(CLOCK_REALTIME, &endTime);
    
    memAccessTime = (((endTime.tv_sec - startTime.tv_sec)*NS_IN_SEC)+(endTime.tv_nsec - startTime.tv_nsec));
    //memAccessTime /= count*100;
    printf("Memorytime %lf\n",memAccessTime/(countL1*128));
    
    
    for (int i =1;i<100;i++){
        ptr = head_org;
        index=0;
        while(index<countL1){
            HUNDRED28
            index ++;
        }
    }
    
    
    ptr = head_org;
    index=0;
    clock_gettime(CLOCK_REALTIME, &startTime);
    while(index<countL1){
        HUNDRED28
        index ++;
    }
    clock_gettime(CLOCK_REALTIME, &endTime);
    
    cacheL1AccessTime = (((endTime.tv_sec - startTime.tv_sec)*NS_IN_SEC)+(endTime.tv_nsec - startTime.tv_nsec));
    //cacheL1AccessTime /= L1_SIZE;
    printf("L1time %lf ns\n",cacheL1AccessTime/(countL1*128));
    
    
    for (int i =1;i<100;i++){
        index=0;
        ptr =head_invalidate;
        while(index<countL1){
            HUNDRED28
            index ++;
        }
    }
    index=0;
    ptr =head_org;
    clock_gettime(CLOCK_REALTIME, &startTime);
    while(index<countL1){
        HUNDRED28
        index ++;
    }
    clock_gettime(CLOCK_REALTIME, &endTime);
    
    cacheL2AccessTime = (((endTime.tv_sec - startTime.tv_sec)*NS_IN_SEC)+(endTime.tv_nsec - startTime.tv_nsec));
    //cacheL2AccessTime /= L2_SIZE;
    printf("L2time %lf ns\n",cacheL2AccessTime/(countL1*128));
    for (int i =1;i<100;i++){
        index=0;
        ptr =head2_invalidate;
        while(index<countL2){
            HUNDRED28
            index ++;
        }
    }
    index=0;
    ptr =head_org;
    clock_gettime(CLOCK_REALTIME, &startTime);
    while(index<countL1){
        HUNDRED28
        index ++;
    }
    clock_gettime(CLOCK_REALTIME, &endTime);
    
    cacheL3AccessTime = (((endTime.tv_sec - startTime.tv_sec)*NS_IN_SEC)+(endTime.tv_nsec - startTime.tv_nsec));
    //cacheL3AccessTime /= L3_SIZE;
    printf("L3time %lf ns\n",cacheL3AccessTime/(countL1*128));
    
    
    return 0;
    
}
