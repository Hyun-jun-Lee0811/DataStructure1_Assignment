# [자료구조1] Assignment 9 - 2026.04.15
##  과제 개요
- 순차 리스트는 배열로 구현되므로, 미리 할당된 칸을 모두 소모하면 데이터를 더이상 추가할 수 없는 포화 상태(Full)가 된다.
- 이때, realloc을 사용하여 동적으로 배열의 크기를 늘리는 방법으로 포화 상태를 해결할 수 있도록 순차 리스트를 개선한다.
### 내용
- 공간이 부족할 때마다 기존 용량의 2배로 확장하여, 빈번한 메모리 재할당으로 인한 오버헤드를 줄였습니다.
- realloc은 실패 시 NULL을 반환하며 기존 포인터 주소를 잃어버릴 수 있기에 임시포인터를 사용하였습니다.

  ### 코드
```text
if (isFullArrayList(al)) {
    int newCapacity = al->capacity * 2;
    elementArrayList* temp = (elementArrayList*)realloc(al->data, sizeof(elementArrayList) * newCapacity);
    
    if (temp == NULL) {
        // 메모리 부족 시 안전하게 종료하거나 에러 로그 출력
        fprintf(stderr, "Critical Error: Memory allocation failed.\n");
        return 0;
    }
    
    al->data = temp;
    al->capacity = newCapacity;
}
```
