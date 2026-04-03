# [자료구조1] Assignment 5 - 2026.04.01

## 과제 1: 배열 알아보기

### 구현 내용

### #define N 11을 사용하여 배열 크기를 유연하게 관리.
### rand() 함수를 이용해 무작위 숫자로 배열을 채운 뒤, 정방향/역방향 출력 및 통계(총합, 최댓값, 최솟값) 산출.
---

### 구현 코드

```c
#define N 11

int arr[N];
int sum = 0;
int maxNum = 0;
int minNum = 0;


for (int i = 0; i < N; i++) {
     arr[i] = rand() % (N + 1);
}
minNum = arr[0];
```

---

### 요구사항

1. **정방향 출력**

```text
정방향: 5 11 10 4 5 4 6 6 10 8 5
```

2. **역방향 출력**

```text
역방향: 5 8 10 6 6 4 5 4 10 11 5
```

3. **배열 분석**

```text
합=74, 최댓값=11, 최솟값=4
```
---

### 정방향, 역방향, 배열 출력

```text
정방향: 5 11 10 4 5 4 6 6 10 8 5
역방향: 5 8 10 6 6 4 5 4 10 11 5
합=74, 최댓값=11, 최솟값=4
```

---

## 과제 2: 홀수 마방진

### 구현 내용

* N×N 크기의 2차원 배열 생성
* 1부터 N²까지의 수를 중복 없이 채움

---

### 구현 코드

```c
int box[N][N] = { 0 };
int firstStart = 0;
int middleStart = N / 2;

for (int num = 1; num <= N * N; num++) {
    box[firstStart][middleStart] = num;

    int nextFirstStart = firstStart - 1;
    int nextMiddleStart = middleStart + 1;

    if (nextFirstStart < 0) nextFirstStart = N - 1;
    if (nextMiddleStart >= N) nextMiddleStart = 0;

    if (box[nextFirstStart][nextMiddleStart] != 0) {
        firstStart = (firstStart + 1) % N;
    } else {
        firstStart = nextFirstStart;
        middleStart = nextMiddleStart;
    }
}
```

---

### 마방진 출력

```text
마방진
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

마방진의 모든 행, 열, 대각선의 합은 동일해야 한다.

---

### 구현 코드

```c
for (int i = 0; i < N; i++) {
    int rawSum = 0;
    int columnSum = 0;

    for (int j = 0; j < N; j++) {
        rawSum += box[i][j];
        columnSum += box[j][i];
    }

    printf("%d행의 합: %d, %d열의 합: %d\n", i + 1, rawSum, i + 1, columnSum);
}
```
```c
int diagonal1 = 0;
int diagonal2 = 0;

for (int i = 0; i < N; i++) {
    diagonal1 += box[i][i];
    diagonal2 += box[i][N - 1 - i];
}

printf("＼의 합: %d\n", diagonal1);
printf("／의 합: %d\n", diagonal2);
```

---

### 가로, 세로, 대각선 출력

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
9행의 합: 671, 9열의 합: 671
10행의 합: 671, 10열의 합: 671
11행의 합: 671, 11열의 합: 671
＼의 합: 671
／의 합: 671
```
