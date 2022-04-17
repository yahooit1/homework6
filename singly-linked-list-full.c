/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

/* 필요한 헤더파일 추가 */

typedef struct Node { //Node를 struct로 선언(지정)
	int key; //정수형변수 key 선언
	struct Node* link; //Node에 대한 포인터 link 선언
} listNode; //구조체 호출시 사용할 이름 

typedef struct Head {//Head를 struct로 선언(지정)
	struct Node* first; //Node에 대한 포인터 first선언
}headNode; //구조체 호출시 사용할 이름


/* 함수 리스트 */
headNode* initialize(headNode* h); //headNode에 메모리를 할당하여 초기화하는 함수 선언
int freeList(headNode* h); //할당된 메모리를 해제하는 함수 선언

int insertFirst(headNode* h, int key); //list 처음에 key에 대한 노드하나를 추가하는 함수 선언
int insertNode(headNode* h, int key); //리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 함수 선언
int insertLast(headNode* h, int key); //list에 key에 대한 노드하나를 추가하는 함수 선언

int deleteFirst(headNode* h); //list의 첫 노드 삭제 함수 선언
int deleteNode(headNode* h, int key); //list에서 key에 대한 노드 삭제하는 함수 선언
int deleteLast(headNode* h); //list의 마지막 노드 삭제하는 함수 선언
int invertList(headNode* h); //list의 링크를 역순으로 재 배치하는 함수 선언

void printList(headNode* h); //list 출력

int main()
{
	char command; //문자형 변수 command 선언
	int key; //정수형 변수 key 선언
	headNode* headnode=NULL; //headnode에 대한 포인터 headnode 선언 및 초기화

	do{
		printf("[----- [Gahyun.Kim] [2020045070] -----]");
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = "); //메뉴선택입력받기
		scanf(" %c", &command); //command 입력받기

		switch(command) {//command 값에 따른 switch 조건문
		case 'z': case 'Z': //z를 입력받았을 경우 (대소문자 모두 가능)
			headnode = initialize(headnode); //headnode에 initialize 함수의 리턴 값 대입(초기화한 headnode)
			break;
		case 'p': case 'P'://p를 입력받았을 경우 (대소문자 모두 가능)
			printList(headnode); //headnode를 출력하는 함수
			break;
		case 'i': case 'I': //i를 입력받았을 경우 (대소문자 모두 가능)
			printf("Your Key = ");
			scanf("%d", &key); //정수형 변수 key입력받기
			insertNode(headnode, key); //
			break;
		case 'd': case 'D': //d를 입력받았을 경우 (대소문자 모두 가능)
			printf("Your Key = ");
			scanf("%d", &key); //정수형 변수 key의 값 입력받기
			deleteNode(headnode, key);
			break;
		case 'n': case 'N': //n를 입력받았을 경우 (대소문자 모두 가능)
			printf("Your Key = ");
			scanf("%d", &key); //정수형 변수 key의 값 입력받기
			insertLast(headnode, key);
			break;
		case 'e': case 'E': //e를 입력받았을 경우 (대소문자 모두 가능)
			deleteLast(headnode);
			break;
		case 'f': case 'F'://f를 입력받았을 경우 (대소문자 모두 가능)
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T': //t를 입력받았을 경우 (대소문자 모두 가능)
			deleteFirst(headnode);
			break;
		case 'r': case 'R': //r를 입력받았을 경우 (대소문자 모두 가능)
			invertList(headnode);
			break;
		case 'q': case 'Q': //q를 입력받았을 경우 (대소문자 모두 가능)
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); //q가 입력되지 않는 동안 반복

	return 1;
}

headNode* initialize(headNode* h) {
	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL) //headNode h가 NULL이 아니면 즉, 노드가 존재할때
		freeList(h); //할당된 메모리 해제

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode)); //headNode의 크기만큼 temp에 저장
	temp->first = NULL; //temp의 first에 NULL 저장
	return temp; //temp 반환
}

int freeList(headNode* h){ //
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first; //listNode 포인터 p 선언 후 h를 통해 first 노드(headnode) 연결하여 p에 저장

	listNode* prev = NULL; //listNode 포인터 prev 선언 후 NULL로 초기화
	while(p != NULL) { //p가 NULL이 아닐 동안(노드가 존재할 동안)
		prev = p; //prev에 p 대입
		p = p->link; // p의 link를 p에 저장
		free(prev);//할당된 prev 메모리 해제
	}
	free(h); //할당된 h 메모리 해제
	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//listnode의 포인ㅌ터 node에 listnode 크기의 메모리를 할당
	node->key = key; // node의 key에 key 저장
	node->link = NULL; //node의 link에 NULL값 저장

	if (h->first == NULL) //h의 first가 NULL일 때
	{
		h->first = node;//h의 first에 node를 대입
		return 0;
	}

	listNode* n = h->first; //포인터 n에 h의 first를 저장
	listNode* trail = h->first; //포인터 trail 에 h의 first를 저장

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) { //n이 != NULL일 동안 , 노드가 존재할 동안
		if(n->key >= key) { //n의 key가 입력받은 key보다 클 때,
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {//n이 first(첫번째 노드)일 경우
				h->first = node; //first에 node를 저장
				node->link = n; //n을 node의 link에 저장
			} else { /* 중간이거나 마지막인 경우 */
				node->link = n; //n을 node의 link에 저장
				trail->link = node; //trail의 link에 node를 저장
			}
			return 0;
		}

		trail = n; //trail에 n을 저장
		n = n->link; //n에 n의 link를 저장
	}

	/* 마지막 노드까지 찾지 못한 경우 , 마지막에 삽입 */
	trail->link = node; //trail의 link에 node 저장
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //포인터node에 listnode 크기 만큼의 메모리 할당
	node->key = key; //node의 key에 입력받은 key값 저장
	node->link = NULL; //node의 link에 NULL값 저장(초기화)

	if (h->first == NULL) //h의 first가 NULL일때
	{
		h->first = node; //h의 first에 node 저장
		return 0;
	}

	listNode* n = h->first; //listnode n에 h의 first 저장
	while(n->link != NULL) {//n의 link!=NULL일 동안, 노드가 존재할 동안
		n = n->link; //n에 n의 link 저장
	}
	n->link = node; //n의 link에 node 저장
	return 0;
}

/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); //node에 listNode 크기만큼의 메모리 할당
	node->key = key; //node의 key에 입력받은 key 저장

	node->link = h->first; //node의 link에 h의 시작주소 저장
	h->first = node; //first에 node 저장

	return 0;
}

/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {

	if (h->first == NULL) //h의 first가 NULL일때
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; //포인터 n에 h의 first 저장
	listNode* trail = NULL; //포인터 trail 초기화

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) { //n!=NULL일 동안, 노드가 존재 할 동안
		if(n->key == key) { //n의 key가 입력된 key와 같을때
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) { //n가 h의 first일 경우 
				h->first = n->link; //n의 link를 h의 frist에 저장
			} else { /* 중간인 경우거나 마지막인 경우 */
				trail->link = n->link; //n의 link를 trail의 link에 저장
			}
			free(n); //n에 할당된 메모리 해제
			return 0;
		}

		trail = n; //trail에 n 저장
		n = n->link; //n에 n의 link를 저장 
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);
	return 0;

}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) { 

	if (h->first == NULL) //h의 first가 NULL일 때
	{
		printf("nothing to delete.\n"); //삭제할노드가없음
		return 0;
	}

	listNode* n = h->first; //n에 h의 frist 저장
	listNode* trail = NULL; //trail 초기화

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->link == NULL) { //n의  link가 NULL일때
		h->first = NULL; //h의 first를 NULL로 초기화
		free(n); //n에 할당된 메모리 해제
		return 0;
	}

	/* 마지막 노드까지 이동 */
	while(n->link != NULL) { //n->link != NULL일동안, 노드가 존재할 동안
		trail = n; //trail에 n 저장
		n = n->link; //n에 n의 link 저장
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->link = NULL; //trail의 link  NULL처리 
	free(n); //n에 할당된 메모리 해제

	return 0;
}
/**
 * list의 첫번째 노드 삭제
 */
int deleteFirst(headNode* h) {

	if (h->first == NULL) //h의 first가 NULL이면
	{
		printf("nothing to delete.\n"); //삭제할노드가없음
		return 0;
	}
	listNode* n = h->first; //n에 h의 first를 저장

	h->first = n->link; //h의 first에 n의 link 저장
	free(n); //n에 할당된 메모리 해제

	return 0;
}


/*
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {


	if(h->first == NULL) { //h의 first가 NULL일 경우
		printf("nothing to invert...\n"); //바꿀 노드가 없음
		return 0;
	}
	listNode *n = h->first; //포인터 n에 h의 first 저장
	listNode *trail = NULL; //포인터 trail NULL로 초기화
	listNode *middle = NULL; //포인터 middle NULL로 초기화

	while(n != NULL){ //n!=NULL일 동안 , 노드가 존재할 동안
		trail = middle; //trail에 middle 저장
		middle = n; //middle에는 n 저장
		n = n->link; //n에는 n의 link 저장
		middle->link = trail; //middle의 link에 trail 저장 
	}

	h->first = middle; //h의 first에는 middle 저장

	return 0;
}


void printList(headNode* h) {
	int i = 0; //정수형 변수 i 선언 후 0으로 초기화
	listNode* p; //listNode 포인터 p 선언

	printf("\n---PRINT\n");

	if(h == NULL) { //h가 NULL인 경우
		printf("Nothing to print....\n"); //출력할 노드 없음
		return;
	}

	p = h->first; //p에 h의 first 저장

	while(p != NULL) { //p가 NULL이 아닌 동안, 노드가 존재할 동안
		printf("[ [%d]=%d ] ", i, p->key);//i=p의 key 출력
		p = p->link; //p에 p의 link 저장
		i++; //i 증가
	}

	printf("  items = %d\n", i); //i출력 
}

