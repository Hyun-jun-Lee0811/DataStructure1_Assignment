# [자료구조1] Assignment 16 - 2026.05.23

## 과제
- 수업시간에 진행한 https://github.com/kmu-datastructure-ju/data-structure/tree/master/Calculator 코드에는 오류가 존재한다. 해당 소스코드의 오류를 정상 동작하도록 수정한다.

- 또한, Postfix의 evalPostfix까지 정상적으로 동작하도록 코드를 수정하여 코드를 제출한다.

- 각 진행 과정에서 현재 연산 상태를 매번 출력하여 진행 과정이 보이도록 해야하며, 코드는 수업 시간 코드를 수정하여 활용하여야 한다.

---

## 내용

### Array Stack 생성
`createArrayStack()` 함수를 이용하여 스택을 생성하도록 구현하였다.

```c
re->top = -1;
re->size = size;
```

스택의 top을 -1로 초기화하여 빈 스택 상태를 표현하도록 구현하였다.

---

### 스택 공백 및 포화 확인 기능
`emptyArrayStack()`과 `fullArrayStack()` 함수를 이용하여 스택 상태를 확인하도록 구현하였다.

```c
return s->top == -1;
```

스택이 비어 있는지 확인하도록 구현하였다.

```c
return s->top == s->size - 1;
```

스택이 가득 찼는지 확인하도록 구현하였다.

---

### Push 연산 구현
`pushArrayStack()` 함수를 이용하여 데이터를 스택에 삽입하도록 구현하였다.

```c
s->top++;
```

top 값을 증가시킨 뒤 데이터를 저장하도록 구현하였다.

문자형(Character)과 정수형(Integer)을 union 자료형으로 구분하여 저장하도록 구현하였다.

```c
if (s->type == CHARACTER)
```

---

### Pop 연산 구현
`popArrayStack()` 함수를 이용하여 스택의 top 데이터를 제거 및 반환하도록 구현하였다.

```c
stackElement temp = s->data[s->top];
s->top--;
```

top 위치의 데이터를 반환한 뒤 top 값을 감소시키도록 구현하였다.

---

### Peek 연산 구현
`peekArrayStack()` 함수를 이용하여 현재 top 데이터를 반환하도록 구현하였다.

```c
return s->data[s->top];
```

스택의 가장 위 데이터를 확인할 수 있도록 구현하였다.

---

### 중위 표기식 → 후위 표기식 변환 기능
`infixToPostfix()` 함수를 이용하여 중위 표기식을 후위 표기식으로 변환하도록 구현하였다.

```c
if (infix[i] >= '0' && infix[i] <= '9')
```

숫자인 경우 postfix 문자열에 바로 저장하도록 구현하였다.

연산자의 우선순위를 비교하여 스택에 저장 및 출력하도록 구현하였다.

```c
if (precedence(infix[i]) <= precedence(prevOp.operator))
```

괄호 처리 또한 스택을 이용하여 구현하였다.

```c
else if (infix[i] == '(')
```

```c
else if (infix[i] == ')')
```

---

### 연산 우선순위 기능
`precedence()` 함수를 이용하여 연산자의 우선순위를 반환하도록 구현하였다.

```c
if (op == '*' || op == '/')
```

곱셈과 나눗셈의 우선순위를 높게 설정하도록 구현하였다.

```c
else if (op == '+' || op == '-')
```

덧셈과 뺄셈의 우선순위를 낮게 설정하도록 구현하였다.

---

### 후위 표기식 계산 기능
`evalPostfix()` 함수를 이용하여 후위 표기식을 계산하도록 구현하였다.

```c
int i1 = popArrayStack(valueStack).value;
int i2 = popArrayStack(valueStack).value;
```

스택에서 두 개의 값을 pop하여 연산하도록 구현하였다.

연산 결과는 다시 스택에 push하도록 구현하였다.

```c
pushArrayStack(valueStack, result);
```

최종적으로 마지막 결과값을 반환하도록 구현하였다.

```c
return popArrayStack(valueStack).value;
```

---

### 현재 연산 상태 출력 기능
중위 표기식 변환 과정과 후위 표기식 계산 과정에서 현재 상태를 출력하도록 구현하였다.

```c
printf("- Postfix: %-15s | ", postfix);
```

현재 postfix 문자열과 operator stack 상태를 출력하도록 구현하였다.

```c
printf("- Current: %c | ", postfix[i]);
```

현재 계산 중인 문자와 value stack 상태를 출력하도록 구현하였다.

---

## 실행 예시

```text
Transform:

- Postfix: 3               | Stack:
- Postfix: 3               | Stack: +
- Postfix: 34              | Stack: +
- Postfix: 34              | Stack: + *
...

- Result: 3456+*7*+

Eval:

- Postfix: 3456+*7*+

- Current: 3 | Stack: 3
- Current: 4 | Stack: 3 4
- Current: 5 | Stack: 3 4 5
...

- Result: 311
```
