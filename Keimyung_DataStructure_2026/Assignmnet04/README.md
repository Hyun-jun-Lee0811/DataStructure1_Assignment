# [자료구조1] Assignment 4 - 2026.03.29

## 과제 개요

GCD 알고리즘의 시간복잡도를 분석하고, 피보나치 수열을 활용하여 실제 수행 시간과의 관계를 프로파일링한다.

---

## 과제 1: GCD 복잡도 분석

### 사용 알고리즘

유클리드 호제법(Euclidean Algorithm)을 사용하여 최대공약수를 계산한다.

### GCD 알고리즘의 파일 링크
- https://github.com/Hyun-jun-Lee0811/Keimyung_DataStructure_2026/blob/assignment-04-profiling/Keimyung_DataStructure_2026/Assignmnet04/my_math.c
- https://github.com/Hyun-jun-Lee0811/Keimyung_DataStructure_2026/blob/assignment-04-profiling/Keimyung_DataStructure_2026/Assignmnet04/my_math.h

```c
while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
}
```

---

### 시간 복잡도

유클리드 호제법의 시간 복잡도는 다음과 같다.

```
O(log n)
```

---

### 분석

* 나머지 연산을 반복하며 값이 빠르게 감소한다.
* 최악의 경우는 연속된 피보나치 수일 때 발생한다.
* 따라서 시간 복잡도는 입력 크기에 대해 로그 시간에 비례한다.

---

## 과제 2: 피보나치 기반 프로파일링

### 구현 내용

* n = 5 ~ 45까지 증가시키며 수행
* F(n), F(n-1)을 계산
* GCD(F(n), F(n-1)) 실행 시간 측정
* `clock()` 함수 사용

---

### 실행 결과

```text
n  F(n)  F(n-1)  GCD 결과  소요 시간
5 5 3 1 0.00000
6 8 5 1 0.00000
7 13 8 1 0.00000
...
45 1134903170 701408733 1 0.00000
```

---

### 결과 분석

* 모든 경우에서 GCD 결과는 1로 나타남
  → 서로 연속된 피보나치 수는 항상 서로소 관계임

* 실행 시간은 거의 0에 가까움
  → 입력 값이 증가해도 수행 시간이 크게 증가하지 않음

---

### 복잡도 검증

* 피보나치 수는 빠르게 증가하지만
* GCD 연산 시간은 거의 일정하게 유지됨
* 이는 유클리드 알고리즘이 **O(log n)** 시간복잡도를 가지기 때문

---

## 프로파일링 분석

* CPU 사용 시간 측정 결과 매우 짧은 시간(0.00000ms)으로 측정됨 -> 측정된 소요 시간이 0.00000ms인 이유는 알고리즘의 시간 복잡도가 $O(\log n)$으로 매우 낮아, 현대 CPU의 연산 속도가 clock() 함수의 최소 측정 단위보다 훨씬 빠르기 때문
* 이는 연산 자체가 매우 빠르기 때문이며,
* 실제로는 매우 작은 단위에서 증가하지만 출력에서 표현되지 않음

---

## 결론

* 유클리드 호제법은 매우 효율적인 알고리즘이며
* 입력 값이 증가하더라도 실행 시간은 크게 증가하지 않는다.
* 피보나치 수를 이용한 테스트를 통해 이론적인 시간복잡도(O(log n))가 실제로도 성립함을 확인하였다.
* 피보나치 수열은 유클리드 호제법에서 나머지 연산이 가장 많이 발생하는 최악의 입력 사례임에도 불구하고, 프로파일링 결과 시스템 리소스 점유율이 매우 낮게 유지되는 것을 통해 알고리즘의 우수성을 확인

<img width="1371" height="842" alt="image" src="https://github.com/user-attachments/assets/8078281b-f4b9-4e84-ad21-dae35e0dc956" />
<img width="366" height="609" alt="image" src="https://github.com/user-attachments/assets/b16d3083-1dbf-4fb9-b485-5fe6d9b43a7d" />

