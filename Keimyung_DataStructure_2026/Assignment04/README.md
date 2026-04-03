# [자료구조1] Assignment 4 - 2026.03.29

## 과제 개요

GCD 알고리즘의 시간복잡도를 분석하고, 피보나치 수열을 활용하여 실제 수행 시간과의 관계를 프로파일링한다.


## 과제 1: GCD 복잡도 분석

### 사용 알고리즘

유클리드 호제법(Euclidean Algorithm)을 사용하여 최대공약수를 계산한다.

### GCD 알고리즘의 파일 링크

* https://github.com/Hyun-jun-Lee0811/Keimyung_DataStructure_2026/blob/assignment-04-profiling/Keimyung_DataStructure_2026/Assignmnet04/my_math.c
* https://github.com/Hyun-jun-Lee0811/Keimyung_DataStructure_2026/blob/assignment-04-profiling/Keimyung_DataStructure_2026/Assignmnet04/my_math.h

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

* 나머지 연산을 반복하면서 값이 빠르게 감소한다.
* 최악의 경우는 **연속된 피보나치 수**일 때 발생한다.
* 따라서 시간 복잡도는 입력 크기에 대해 로그 시간에 비례한다.

---

## 과제 2: 피보나치 기반 프로파일링

### 구현 내용

* n = 5 ~ 45까지 증가시키며 수행
* F(n), F(n-1)을 계산
* GCD(F(n), F(n-1)) 실행 시간 측정
* 정확한 측정을 위해 동일 연산을 **1,000,000번 반복 수행**
* `clock()` 함수 사용

---

### 실행 결과 (일부)

```text
n, F(n), 소요 시간(ms)
5, 5, ...
10, 55, ...
20, 6765, ...
30, 832040, ...
40, 102334155, ...
45, 1134903170, ...
```

---

### 결과 분석

* 모든 경우에서 GCD 결과는 1로 나타남
  → 연속된 피보나치 수는 항상 서로소 관계

* 반복 횟수를 증가시켜 측정한 결과, 실행 시간이 유의미하게 측정됨

* n이 증가함에 따라 입력 값(F(n))은 매우 빠르게 증가하지만
  실행 시간은 완만하게 증가하거나 거의 일정하게 유지됨

---

### 복잡도 검증

* 피보나치 수는 지수적으로 증가하지만
* GCD 연산 횟수는 크게 증가하지 않음

→ 이는 유클리드 알고리즘이 **O(log n)** 시간복잡도를 가지기 때문

→ 특히 피보나치 수는 유클리드 알고리즘의 **최악의 입력 케이스**이므로
해당 결과는 이론적인 복잡도를 잘 검증한다고 볼 수 있음

---

## 프로파일링 분석

* 기존 단일 실행에서는 측정 시간이 0으로 출력됨

* 이를 해결하기 위해 동일 연산을 1,000,000번 반복 수행하여 측정

*  결과:

  * 실행 시간이 정상적으로 측정됨
  * 입력 크기 증가 대비 시간 증가가 매우 작음


---

## 결론

* 유클리드 호제법은 매우 효율적인 알고리즘이며, 시간 복잡도는 O(log n)이다.
* 피보나치 수열을 활용한 실험을 통해 이론적인 최악의 경우에서도 성능이 안정적임을 확인하였다.
* 반복 실행을 통한 프로파일링을 통해 실제 실행 시간 또한 매우 작게 유지됨을 확인하였다.

---

## 프로파일링 결과
메모리 사용량은 입력 크기 증가에 관계없이 약 818KB 정도로 일정하게 유지됨을 확인하였다
<img width="1380" height="849" alt="image" src="https://github.com/user-attachments/assets/1be2f603-ed08-45fc-8d30-0775a2e8ca8e" />

<img width="829" height="611" alt="image" src="https://github.com/user-attachments/assets/24a2ca94-7424-491c-b63b-4d080776e0c5" />

## 상세 프로파일링 분석
1. **Hot Path 확인**: `main` 함수 내에서 호출된 `get_gcd` 함수가 전체 CPU 사용량의 약 **98%**를 차지하고 있습니다. 이는 반복문을 통해 GCD 알고리즘을 집중적으로 테스트했음을 증명합니다.
2. **코드 라인별 부하**: `get_gcd` 내부의 `a % b` 연산(8번 라인)이 가장 높은 비중(59.00%)을 차지합니다. 이를 통해 알고리즘의 시간 복잡도에 가장 큰 영향을 미치는 '기본 연산'을 시각적으로 확인할 수 있었습니다.
3. **결론**: 피보나치 수열(최악의 케이스)을 입력으로 넣었음에도 불구하고, 프로파일링 결과 시스템 부하가 특정 연산에 집중되는 것을 확인하였으며 이는 이론적 분석인 $O(\log n)$의 동작 방식과 일치합니다.
<img width="838" height="861" alt="image" src="https://github.com/user-attachments/assets/f2c2ee8e-3444-452b-a765-11207016f799" />


=======
# [자료구조1] Assignment 4 - 2026.03.29

## 과제 개요

GCD 알고리즘과 피보나치 수열의 시간복잡도를 분석하고, 재귀적 구현과 반복적 연산이 CPU와 메모리에 미치는 영향을 프로파일링을 통해 검증한다.


## 과제 1: GCD 복잡도 분석

### 사용 알고리즘

유클리드 호제법을 사용하여 최대공약수를 계산한다.

---

### 시간 복잡도

```
O(log n)
```

---

### GCD 알고리즘의 파일 링크

* https://github.com/Hyun-jun-Lee0811/Keimyung_DataStructure_2026/blob/assignment-04-profiling/Keimyung_DataStructure_2026/Assignmnet04/my_math.c
* https://github.com/Hyun-jun-Lee0811/Keimyung_DataStructure_2026/blob/assignment-04-profiling/Keimyung_DataStructure_2026/Assignmnet04/my_math.h

```c
while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
}
```

## 프로파일링 결과
메모리 사용량은 입력 크기 증가에 관계없이 약 818KB 정도로 일정하게 유지됨을 확인하였다
<img width="1380" height="849" alt="image" src="https://github.com/user-attachments/assets/1be2f603-ed08-45fc-8d30-0775a2e8ca8e" />

<img width="829" height="611" alt="image" src="https://github.com/user-attachments/assets/24a2ca94-7424-491c-b63b-4d080776e0c5" />

<img width="838" height="861" alt="image" src="https://github.com/user-attachments/assets/f2c2ee8e-3444-452b-a765-11207016f799" />

### 분석

* 나머지 연산을 반복하면서 값이 빠르게 감소한다.
* 최악의 경우는 **연속된 피보나치 수**일 때 발생한다.
* 따라서 시간 복잡도는 입력 크기에 대해 로그 시간에 비례한다.

---

## 과제 2: 피보나치 기반 프로파일링

### 구현 내용

* n = 5 ~ 45까지 증가시키며 수행
* F(n), F(n-1)을 계산
* GCD(F(n), F(n-1)) 실행 시간 측정
* `clock()` 함수 사용

---

### 시간 복잡도

```
O(2^n)
```

```c
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2); // 재귀 호출
}
```

### 실행 결과 (일부)
  $n$이 커짐에 따라 시간이 0ms에서 21ms까지 지수적으로 늘어나고 있습니다.

<img width="1574" height="795" alt="image" src="https://github.com/user-attachments/assets/4704e192-ff0e-4e82-a23a-0b6b32387a71" />
<img width="979" height="504" alt="image" src="https://github.com/user-attachments/assets/06892953-cf7c-4a04-bf49-3fd549086759" />
<img width="387" height="511" alt="image" src="https://github.com/user-attachments/assets/aba9973c-1e48-4e2c-b8db-d256a4922761" />
<img width="1123" height="805" alt="image" src="https://github.com/user-attachments/assets/ce90a422-6ad8-43ed-8903-eafe87651eb0" />

---

### 결과 분석

* 모든 경우에서 GCD 결과는 1로 나타남  
  → 연속된 피보나치 수는 항상 서로소 관계

* n이 증가함에 따라 실행 시간이 급격하게 증가함

* 이는 GCD가 아니라 Fibonacci 계산 때문이며,  
  재귀적 Fibonacci는 동일한 계산을 반복하기 때문에 비효율적이다.

* Fibonacci 함수의 시간 복잡도는 O(2^n)으로,  
  입력이 증가할수록 실행 시간이 지수적으로 증가한다.

---

### 복잡도 검증

* Fibonacci 함수는 재귀적으로 구현되어 O(2^n)의 시간복잡도를 가진다.
* 반면 GCD 알고리즘은 O(log n)으로 매우 빠르다.

→ 따라서 전체 실행 시간은 GCD가 아니라 Fibonacci에 의해 결정된다.

→ 프로파일링 결과 n이 증가할수록 실행 시간이 급격히 증가하는 것은  
Fibonacci의 지수적 시간복잡도를 반영한 것이다.

---


## 프로파일링 분석

* 실행 시간의 대부분은 Fibonacci 함수에서 발생한다.
* 재귀 호출이 중복되면서 호출 횟수가 기하급수적으로 증가한다.
* GCD 연산은 매우 빠르기 때문에 전체 실행 시간에 거의 영향을 주지 않는다.

→ 따라서 병목 구간은 Fibonacci이며,  
이는 시간복잡도 O(2^n)과 일치한다.


---

## 결론

* 유클리드 호제법(GCD)은 O(log n)으로 매우 효율적인 알고리즘이다.
* 반면 재귀적으로 구현된 Fibonacci는 O(2^n)의 시간복잡도를 가지며 매우 비효율적이다.
* 프로파일링 결과, 전체 실행 시간은 Fibonacci 함수에 의해 결정됨을 확인하였다.
* 이를 통해 이론적인 시간복잡도와 실제 실행 결과가 일치함을 검증하였다.

---


## 상세 프로파일링 분석
1. **Hot Path 확인**: 전체 CPU 사용량의 대부분은 `fibonacci` 함수에서 발생한다.  
   이는 재귀 호출로 인해 동일한 계산이 반복되기 때문이다.

2. **재귀 호출 구조**: Fibonacci 함수는 하나의 호출이 두 개의 하위 호출을 생성하는 구조를 가지며,  
   호출 횟수가 기하급수적으로 증가한다.

3. **GCD 연산 영향**: `get_gcd` 함수는 O(log n)의 시간복잡도를 가지므로 실행 시간이 매우 짧으며,  
   전체 실행 시간에 거의 영향을 주지 않는다.

4. **결론**: 전체 프로그램의 성능은 Fibonacci 함수에 의해 결정되며,  
   이는 이론적인 시간복잡도 O(2^n)과 일치한다.


>>>>>>> origin/main:Keimyung_DataStructure_2026/Assignmnet04/README.md
