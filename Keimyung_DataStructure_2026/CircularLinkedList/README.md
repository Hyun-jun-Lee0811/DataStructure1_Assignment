### 변경 사항

#### 1. `destoryCLinkedList` - 메모리 해제 시작 노드 수정
- `cl->tail`부터 해제 시작하는 것을`cl->tail->next`로 바꿔 첫 번째 노드부터 해제 시작하게 하였습니다.

#### 2. `insertFirstCLinkedList`, `insertLastCLinkedList` - 반환값 추가
- `int` 반환 선언이나 `return` 문 없기에 `return 1;` 추가하였습니다
