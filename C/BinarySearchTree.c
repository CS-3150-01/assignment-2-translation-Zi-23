#include <stdio.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *Node(int data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

void factorial(int fact, int num){
    int fact = 1;    
        if(num == 0){ 
            return 1;    
        else {    
            while(num > 1) {    
                fact = fact * num;    
                num--;    
            }    
            return fact;    
        } 
    }      
}

void numOfBST(int key){
    int catalanNumber = factorial(2 * key)/(factorial(key + 1) * factorial(key));    
        return catalanNumber;   
}

int main() {
    return 0;
}