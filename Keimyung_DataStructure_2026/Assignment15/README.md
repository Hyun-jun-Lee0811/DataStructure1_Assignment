# [자료구조1] Assignment 15 - 2026.05.22

## 과제
1) 브라우저

-  수업시간에 진행한 Linked 스택 소스 코드를 바탕으로, 사용자가 메뉴를 통해 URL 목록을 다룰 수 있는 프로그램을 작성하여 웹 브라우저처럼 메뉴를 구현하시오. 메뉴는 다음과 같다.

 - 모든 연산은 스택의 특성이 적용된 연산을 활용해 동작해야 한다.

 - 마지막 데이터까지 모두 제거되고 나면 전체 메모리를 해제하고 프로그램을 종료한다.

 - 수업 시간에 구현한 연산 외에 ADT에서 이야기한 연산도 모두 구현한다.

  1. URL 추가: URL을 입력받아 스택에 URL을 추가

  2. URL 제거: URL을 입력받아 스택에서 URL을 제거

  3. 스택 확인: 현재 스택에 저장된 URL의 마지막 값을 출력



ADT)

create, destory, push, pop, empty, full, print, peak, 



예시)

입력 1

출력 URL 입력:

입력 https://www.google.com

출력 현재 창: https://www.google.com

입력 1

출력 URL 입력:

입력 https://www.naver.com

출력 현재 창: https://www.naver.com

입력 3


출력 현재 창: https://www.naver.com

입력 2

출력 이탈: https://www.naver.com

       현재 창: https://www.google.com

입력 2

출력 이탈: https://www.google.com

       브라우저가 종료되었습니다.
---

## 내용

### 메뉴 기반 프로그램 구현
반복문을 이용하여 사용자가 원하는 메뉴를 계속 선택할 수 있도록 구현하였다.

```c
while (menu != 0)
```

메뉴 번호 입력에 따라 각 스택 기능이 실행되도록 구성하였다.

---

### Linked Stack 생성
`createLinkedStack()` 함수를 이용하여 스택을 생성하였다.

```c
re->head = NULL;
re->size = 0;
```

초기 스택은 비어 있는 상태로 생성하도록 구현하였다.

---

### URL 추가 기능
`pushLinkedStack()` 함수를 이용하여 새로운 URL을 스택의 top 위치에 삽입하도록 구현하였다.

```c
temp->next = s->head;
s->head = temp;
```

새로운 노드를 head 앞에 연결하여 스택의 LIFO 구조를 유지하도록 구현하였다.

---

### URL 제거 기능
`popLinkedStack()` 함수를 이용하여 가장 최근에 추가된 URL을 제거하도록 구현하였다.

```c
Node* temp = s->head;
s->head = temp->next;
```

top 노드를 제거한 뒤 다음 노드를 새로운 top으로 설정하도록 구현하였다.

---

### 현재 URL 확인 기능
`peekLinkedStack()` 함수를 이용하여 현재 스택의 top URL을 출력하도록 구현하였다.

```c
return s->head->data;
```

스택의 가장 위에 있는 URL을 반환하도록 구현하였다.

---

### 스택 공백 확인 기능
`emptyLinkedStack()` 함수를 이용하여 스택이 비어 있는지 확인하도록 구현하였다.

```c
return s->size == 0;
```

스택의 크기가 0이면 비어 있는 상태로 판단하도록 구현하였다.

---

### 전체 스택 출력 기능
현재 스택에 저장된 모든 URL을 출력하도록 구현하였다.

```c
while (temp != NULL)
```

head부터 마지막 노드까지 순차적으로 출력하도록 구현하였다.

---

### 메모리 해제 기능
`destroyLinkedStack()` 함수를 이용하여 스택 내부의 모든 노드를 제거한 뒤 메모리를 해제하도록 구현하였다.

```c
while (!emptyLinkedStack(s))
```

스택이 빌 때까지 pop 연산을 반복하도록 구현하였다.

---

### 브라우저 종료 기능
마지막 URL까지 제거되면 브라우저가 자동 종료되도록 구현하였다.

```c
if (emptyLinkedStack(myStack))
```

모든 URL이 제거되면 메모리를 해제하고 프로그램을 종료하도록 구현하였다.

---

## 실행 예시

```text
1. URL 추가
2. URL 제거
3. 스택 확인
4. 전체 출력
0. 종료

입력: 1

URL 입력:
https://www.google.com

현재 창: https://www.google.com
```
