#include <winsock.h>
#include<stdio.h>
#include<mysql.h>
#include<string.h>

MYSQL *conn;
MYSQL_ROW row;
MYSQL_RES * res;
char *query;

char *test_string(int n1, char *fa){
    int id,strleng;
    char string[30];
    Notation *no;
    id = n1;
    strcpy(string,fa);
    //get data
//    printf("Choose one of FA : ");
//    scanf("%d",&id);
    no=getAllData(id);

    Transition *nov;
    nov=no->tr;
//    while(nov!=NULL){
//        printf("%d %d %d\n",nov->state_at,nov->alphabet_at,nov->state_next);// working
//        nov=nov->next;
//    }

//    printf("Input string : ");
//    scanf("%s",&string);
    strleng=strlen(string);
//    printf("length input = %d\n",strleng); //working
//    printf("string input = %s\n",string); //working
    int strInNum[strleng];
    Alphabet *tmp;
    int emptyStr=-1;
    //encrypt input string to id number reference
    for(int i=0;i<strleng;i++){
        tmp=no->al;
        while(tmp!=NULL){
            if(string[i]==tmp->symbol[0]){
                strInNum[i]=tmp->id;
            }
            if(tmp->symbol[0]=='#'){ //"#" represent as epsilon or empty_string
                emptyStr=tmp->id;
            }
            tmp=tmp->next;
        }
    }
//    printf("id represent of string input = ");
//    for(int i=0;i<strleng;i++){ //working
//        printf("%d",strInNum[i]);
//    }
//    printf("\n");

    //find start state
    State *tmp1;
    int start;
    tmp1=no->st;
    while(tmp1!=NULL){
        if(tmp1->start_st==1){
            start=tmp1->id;
            break;
        }
        tmp1=tmp1->next;
    }
//    printf("start state id = %d\n",start);

    Tempo *count;  //count as head of LL count->next is address with value
    count=(Tempo*)malloc(sizeof(Tempo));
    count->next=NULL;
    count->id=-99;
    linkerTempo(count,start);
    Tempo *tmp2;
    Tempo *tmp3;
    Tempo *test,*test1;
    int z=1;

/*
     //for testing
    test=count->next;
    tmp3=count->next;

    while(test!=NULL){
        printf(" %d! ",test->id);
        test=test->next;
    }
    tmp2=getNextState(no,tmp3->id,strInNum[0],emptyStr); //id null is error
    printf(" %d$ ",tmp2->id);
    delete_dataTempo(count,tmp3->id);
    saveCountDataTempo(count,tmp2);

    test1=count->next;
    if(test1==NULL){
        printf(" @Null ");
    }
    while(test1!=NULL){
        printf(" %d@ ",test1->id);
        test1=test1->next;
    }
*/

    //test string
    for(int i=0;i<strleng;i++){ //loop all input string character
        tmp3=count->next;
//        printf("\n z=%d ",z); //
        for(int j=0;j<z;j++){ //loop all state that have
//            printf(" i=%d ",i);//
            if(tmp3->id!=NULL){
//                printf(" start=%d$ ",tmp3->id);
                tmp2=getNextState(no,tmp3->id,strInNum[i],emptyStr);
            }
//            printf(" j=%d \n",j);//
            delete_dataTempo(count,tmp3->id);
            if(tmp2!=NULL){
                saveCountDataTempo(count,tmp2);
            }
            tmp3=tmp3->next;
        }
        test=count->next;
        z=0;
        while(test!=NULL){
            test=test->next;
            z++;
        }
    }

    test=count->next;
//    printf("\nFinal output state id = ");

//    while(test!=NULL){
//        printf(" %d ",test->id);
//        test=test->next;
//    }
    char *value;
    tmp2=count->next;
    while(tmp2!=NULL){
        tmp1=no->st;
        while(tmp1!=NULL){
            if(tmp1->final_st==1){
                if(tmp2->id==tmp1->id){
                    strcpy(&value,"Accepted.");
                    z=-20;
                    break;
                }
            }
            tmp1=tmp1->next;
        }
        if(z==-20){
            break;
        }
        tmp2=tmp2->next;
    }
    if(z!=-20){
        strcpy(&value,"Denied.");
    }
    return value;
}
//test FA
int testFA(int id){
//    int id;
//    printf("Input an ID: ");scanf("%d", &id);
    Notation *fa;
    fa = (Notation* )malloc(sizeof(Notation));
    fa = linkerToAll();
    fa = getAllData(id);

    Alphabet *tmp_alp;
    tmp_alp = fa->al;

    int empty_string = -1;
    while (tmp_alp != NULL){
        if (tmp_alp ->symbol[0] == '#'){
            empty_string = tmp_alp->id;
            break;
        }
        tmp_alp = tmp_alp->next;
    }
    State *tmp_state;
    tmp_state = fa->st;
    Tempo *tmp_next_state;
    int value;
    int c;
    if (empty_string == -1){
        while (tmp_state != NULL){
            tmp_alp = fa->al;
            while (tmp_alp != NULL){
                tmp_next_state = getNextState(fa, tmp_state->id, tmp_alp->id, empty_string);
//                printf("%d* ", tmp_next_state);
                c = 0;
                while (tmp_next_state != NULL){
                    c++;
                    tmp_next_state = tmp_next_state->next;
                }
//                printf("%d ", c);
                if (c != 1){
                    break;
                }
                tmp_alp = tmp_alp->next;
            }
            printf("\n");
            if (c != 1){
                break;
            }
            tmp_state = tmp_state->next;
        }

    }
    if(c != 1){
        value = 1;
    }
    else{
        value = 2;
    }
    return value;
}
