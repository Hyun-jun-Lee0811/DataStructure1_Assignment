# [자료구조1] Assignment 6 - 2026.04.04

## 과제

포인터를 활용하여 동적 할당 배열을 다루고,
모든 배열 접근을 인덱스(`arr[i]`)가 아닌 포인터 연산(`*(arr + i)`)으로 수행한다.
또한 이를 기반으로 **홀수 마방진**을 구현한다.

---

## 배열 알아보기 (동적 할당 + 포인터)

### 내용

* 사용자로부터 정수 `N` 입력
* `malloc()`을 이용하여 크기 `N` 배열 생성
* 배열을 **0 ~ N 범위 랜덤 값**으로 초기화
* 포인터 연산으로 배열 순회 및 분석

---

#### 1. 정방향 출력

```c
for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
}
```

#### 2. 역방향 출력

```c
for (int i = N - 1; i >= 0; i--) {
    printf("%d ", *(arr + i));
}
```

#### 3. 배열 분석 (합 / 최댓값 / 최솟값)

```c
int maxNum = *arr;
int minNum = *arr;

for (int i = 0; i < N; i++) {
    int val = *(arr + i);
    sum += val;
    if (val > maxNum) {
        maxNum = val;
    }
    if (val < minNum) {
        minNum = val;
    }
}
```

---

### 실행 결과

```text
N 입력: 11
정방향: 5 6 4 9 9 6 1 0 3 8 10
역방향: 10 8 3 0 1 6 9 9 4 6 5
합=61, 최댓값=10, 최솟값=0
```

---

## 홀수 마방진 (동적 2차원 배열 + 포인터)

### 내용

* 사용자로부터 홀수 `N` 입력
* `int**` 형태의 2차원 배열 동적 할당
* 모든 접근을 포인터 방식으로 수행
* **Siamese Method**를 이용한 마방진 생성

---

### 동적 할당

```c
int** box = (int**)malloc(sizeof(int*) * N);

for (int i = 0; i < N; i++) {
    *(box + i) = (int*)malloc(sizeof(int) * N);

    for (int j = 0; j < N; j++) {
        *(*(box + i) + j) = 0;
    }
}
```

---

### 마방진 생성

```c
for (int num = 1; num <= N * N; num++) {
    *(*(box + firstStart) + middleStart) = num;

    int nextFirstStart = firstStart - 1;
    int nextMiddleStart = middleStart + 1;

    if (nextFirstStart < 0) {
        nextFirstStart = N - 1;
       }
    if (nextMiddleStart >= N) {
        nextMiddleStart = 0;
       }
    if (*(*(box + nextFirstStart) + nextMiddleStart) != 0) {
        firstStart = (firstStart + 1) % N;
    } else {
        firstStart = nextFirstStart;
        middleStart = nextMiddleStart;
    }
}
```

---

### 마방진 출력

```c
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        printf("%3d ", *(*(box + i) + j));
    }
    printf("\n");
}
```

---

###  합

```c
int diagonal1 = 0;
int diagonal2 = 0;

for (int i = 0; i < N; i++) {
    int rawSum = 0;
    int columnSum = 0;

    for (int j = 0; j < N; j++) {
        rawSum += *(*(box + i) + j);
        columnSum += *(*(box + j) + i);
    }

    diagonal1 += *(*(box + i) + i);
    diagonal2 += *(*(box + i) + (N - 1 - i));

    printf("%d행의 합: %d, %d열의 합: %d\n", i + 1, rawSum, i + 1, columnSum);
}
```

---

### 실행 결과

```text
마방진 입력: 11

11x11 홀수 마방진:
 68  81  94 107 120   1  14  27  40  53  66
 80  93 106 119  11  13  26  39  52  65  67
 92 105 118  10  12  25  38  51  64  77  79
104 117   9  22  24  37  50  63  76  78  91
116   8  21  23  36  49  62  75  88  90 103
  7  20  33  35  48  61  74  87  89 102 115
 19  32  34  47  60  73  86  99 101 114   6
 31  44  46  59  72  85  98 100 113   5  18
 43  45  58  71  84  97 110 112   4  17  30
 55  57  70  83  96 109 111   3  16  29  42
 56  69  82  95 108 121   2  15  28  41  54
```

---

### 합 검증

```text
<합계>:
1행의 합: 671, 1열의 합: 671
2행의 합: 671, 2열의 합: 671
3행의 합: 671, 3열의 합: 671
4행의 합: 671, 4열의 합: 671
5행의 합: 671, 5열의 합: 671
6행의 합: 671, 6열의 합: 671
7행의 합: 671, 7열의 합: 671
8행의 합: 671, 8열의 합: 671
＼의 합: 671
／의 합: 671
```
