/*
Description:
    - There are multiple tourist groups.
    - Each group consists of several people, and each person is assigned to a different room.
    - Rooms on each floor are structured as nodes in a linked list.
      Each node stores the room status and related information.
    - All group leaders stay on the ground floor (floor 0).
    - If the leader’s name is known, all other members of the group
      and their corresponding room numbers can be identified.

Requirements:
    - forget her
    - A function to add an entire tourist group to the hotel.
    - A function to add a single person to an existing group
      and assign them a room.
    - A function to check out a single person.
    - A function to check out an entire group.
*/

#include <stdio.h>
#include <stdlib.h>
// assume the hotel have 5 floors, each floor has 5 rooms
// there 3 groups of tourists with the first one being the leader
// 1: (7) T L Q T D V D
// 2: (4) D Q P T
// 3: (6) P T K N H S

#define MAX_FLOOR 5
#define MAX_ROOM 5
//=========================== STRUCTING ==================================
// Each room consists of a status and a customer name.
// The hotel is represented as a 2D array P[m][n],
// where m is the number of floors and n is the number of rooms per floor.
//
// Each tourist group is represented as a linked list.
// Each person in the group is a node in the linked list,
// storing the address of the room they are assigned to.
// The first node of the list is the group leader.

typedef struct room{
    char customerName;
    int status;
}room;

typedef struct memberNode{
    char name;
    struct room* roomAddress;
    int floor, room;
    struct memberNode* next;
}memberNode;

typedef struct memberList{
    memberNode* leader;
}memberList;

//====================== MEMBER LIST PROCESSING FUNCTION ==========================
void initList(memberList* list){
    list->leader = NULL;
}

void freeList(memberList* list){
    if(list->leader == NULL){
        return ;
    }
    
    memberNode* current = list->leader;
    while(current != NULL){
        memberNode* temp = current;
        current = current->next;
        free(temp);
    }
    
    list->leader = NULL;
}

memberNode* createMemberNode(char name){
    memberNode* newMember = (memberNode*)malloc(sizeof(memberNode));
    
    newMember->name = name;
    newMember->floor = newMember->room = -1;
    newMember->roomAddress = NULL;
    
    newMember->next = NULL;
    return newMember;
}

void inputMember(memberList* list, char name){
    memberNode* newNode = createMemberNode(name);
    
    if(list->leader == NULL){
        list->leader = newNode;
        return;
    }
    
    memberNode* current = list->leader;
    while(current->next != NULL){
        current = current->next;
    }
    
    current->next = newNode;
    
}

void inputGroup(memberList* list, char group[], int n){
  for(int i = 0; i < n; i++){
    inputMember(list, group[i]);
  }
}


//======================= CHECK-IN FUNC =================================
void checkinLeader(memberNode* member, room hotel[MAX_FLOOR][MAX_ROOM]){
    for(int i = 0; i < MAX_ROOM; i++){
        if(hotel[0][i].status == 0){
            hotel[0][i].status = 1;
            hotel[0][i].customerName = member->name;
            member->floor = 0;
            member->room = i;
            member->roomAddress = &hotel[0][i];
            return;
        }
    }
}

void checkinPerson(memberNode* member, room hotel[MAX_FLOOR][MAX_ROOM]){
    for(int i = 1; i < MAX_FLOOR; i++){
        for(int j = 0; j < MAX_ROOM; j++){
            if(hotel[i][j].status == 0){
                hotel[i][j].status = 1;
                hotel[i][j].customerName = member->name;
                member->floor = i;
                member->room = j;
                member->roomAddress = &hotel[i][j];
                return;
            }
        }
    }
}

void checkinGroup(memberList* list, room hotel[MAX_FLOOR][MAX_ROOM]){
    if(list->leader == NULL){
        printf("Invalid group input!\n");
        return;
    }
    
    memberNode* current = list->leader;
    checkinLeader(current, hotel);
    current = current->next;
    
    while(current != NULL){
        checkinPerson(current, hotel);
        current = current->next;
    }
    return ;
}


void checkingStatus(room hotel[MAX_FLOOR][MAX_ROOM]){
  for(int i = 0; i < MAX_FLOOR; i++){
    for(int j = 0; j < MAX_ROOM; j++){
      printf("Floor: %d | Room: %d / RoomAddress: %p| Status: %d | CustomerName: %c\n", 
        i, j, &hotel[i][j], hotel[i][j].status, hotel[i][j].customerName);
    }
  }
}

//========================== RECEPTIONIST FUNCTION ========================================
//problem state that if we know the leader address we can print or output all other member's information in that
//group.
//But the address in computing is changing continuosly so in theory we cannot know the address of
//the leader, so i choose the easy way

void printInformation(memberNode* member){
  printf("MemberName: %c | Floor: %d | Room: %d | RoomAddress: %p\n",
    member->name, member->floor, member->room, member->roomAddress);
}

void printListInformation(memberList* list){
  if(list->leader == NULL){
    printf("Invalid list!\n");
    return ;
  }
  
  memberNode* current = list->leader;
  
  while(current != NULL){
    printInformation(current);
    current = current->next;
  }
  
}



int main() {
    room poHotel[MAX_FLOOR][MAX_ROOM] = {
        {{0,0},{0,0},{0,0},{0,0},{0,0}},
        {{0,0},{0,0},{0,0},{0,0},{0,0}},
        {{0,0},{0,0},{0,0},{0,0},{0,0}},
        {{0,0},{0,0},{0,0},{0,0},{0,0}},
        {{0,0},{0,0},{0,0},{0,0},{0,0}},
    };
    
    char group1[7] = {'T', 'L', 'Q', 'T', 'D', 'V', 'D'};
    
    memberList list1;
    initList(&list1);
    
    inputGroup(&list1, group1, 7);
    checkinGroup(&list1, poHotel);
    
    printListInformation(&list1);
    freeList(&list1);
    
    
    return 0;
}





