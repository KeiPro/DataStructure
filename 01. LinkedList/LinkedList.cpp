/*
	* 연결 리스트란?
		: 배열을 사용하여 리스트를 구현하면, 구현이 간단하다는 장점이 있지만 
		  크기가 고정된다는 단점이 존재한. 즉, 동적으로 크기가 늘어날 수 없어서 
		  맥스 크기를 넘어가게 된다면 더이상 데이터 삽입을 할 수 없는 문제가 발생하게 된다.
		  또한 데이터의 삽입과 삭제가 일어날 경우, 데이터의 이동이 필요하다.

		  연결리스트는 동적으로 크기가 변할 수 있으며 데이터의 삽입과 삭제시
		  데이터를 이동할 필요가 없다. 연결리스트는 데이터와 링크로 구성되어 있고
		  링크가 데이터들을 연결하는 역할을 수행한다.

		  * Node = Data Field + Link Field
		  * 연결리스트의 첫 번째 노드를 Head Pointer라고 한다.
		  * 연결리스트의 마지막 노드의 링크는 NULL을 가리키고 있다.

		  --> 연결리스트의 단점?
					- 1. 링크 필드를 위한 추가공간이 필요하다.
					- 2. 연산의 구현이나 사용 방법이 배열에 비해 복잡하다.

	* 연결 리스트는 3가지가 존재한다.
		- 단순 연결리스트
		- 원형 연걸리스트
		- 이중 연결리스트
*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode
{
	element data;
	ListNode* link;
};


int main(void)
{
	ListNode* p1 = (ListNode*)malloc(sizeof(ListNode));
	p1->data = 10;
	p1->link = NULL;

	ListNode* p2 = (ListNode*)malloc(sizeof(ListNode));
	p2->data = 20;
	p2->link = NULL;

	p1->link = p2;

	printf("%d", p1->link->data);


	free(p1);
	free(p2);

	return 0;
}

