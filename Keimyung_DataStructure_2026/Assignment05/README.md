# [자료구조1] Assignment 5 - 2026.04.01

## 과제 1: 배열 알아보기

### 구현 내용

### #define N 10을 사용하여 배열 크기를 유연하게 관리.
### rand() 함수를 이용해 무작위 숫자로 배열을 채운 뒤, 정방향/역방향 출력 및 통계(총합, 최댓값, 최솟값) 산출.
---

### 구현 코드

```c
#define N 10

int arr[N];
int sum = 0;
int maxNum = 0;
int minNum = 0;

for (int i = 0; i < N; i++) {
    arr[i] = rand() % (i + 1);
}
minNum = arr[0];
```

---

### 요구사항

1. **정방향 출력**

```text
정방향: 1 3 2 5 ...
```

2. **역방향 출력**

```text
역방향: ... 5 2 3 1
```

3. **배열 분석**

```text
합=XX, 최댓값=XX, 최솟값=XX
```
---

### 정방향, 역방향, 배열 출력

```text
정방향: 0 1 1 0 4 4 5 6 7 4
역방향: 4 7 6 5 4 4 0 1 1 0
합=32, 최댓값=7, 최솟값=0
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
10x10 마방진:
 51  63  75  87  99   1  13  25  37  49
 62  74  86  98 100  12  24  36  48  50
 73  85  97   9  11  23  35  47  59  61
 84  96   8  20  22  34  46  58  60  72
 95   7  19  21  33  45  57  69  71  83
  6  18  30  32  44  56  68  70  82  94
 17  29  31  43  55  67  79  81  93   5
 28  40  42  54  66  78  80  92   4  16
 39  41  53  65  77  89  91   3  15  27
  0  52  64  76  88  90   2  14  26  38
```

---

### 합 검증

마방진의 모든 행, 열, 대각선의 합은 동일해야 한다.

---

### 구현 코드

```c
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        rawSum += box[i][j];
        columnSum += box[j][i];
    }
    diagonal1 += box[i][i];
    diagonal2 += box[i][N - 1 - i];

    printf("%d행의 합: %2d, %d열의 합: %2d\n", i + 1, rawSum, i + 1, columnSum);
}
```

---

### 가로, 세로, 대각선 출력

```text
10행의 합: 5040, 10열의 합: 5040
＼의 합: 555
／의 합: 405
```
