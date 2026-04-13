# [자료구조1] Assignment 8 - 2026.04.09

##  과제 개요

피보나치 수열을 순환적 방법과 재귀적 방법으로 각각 구현하고,  
정수 N을 1부터 증가시키면서 두 방식의 수행 시간을 측정하여 비교합니다.

측정 결과를 기반으로 시간 복잡도 차이를 분석하고,
그래프 및 표를 통해 성능 차이를 시각적으로 확인합니다.

---

## 구현 내용

- 피보나치 수열 구현
  - 반복(순환) 방식
  - 재귀 방식
- `clock()`을 이용한 수행 시간 측정
- N 증가에 따른 성능 변화 분석

---

## 피보나치 수열 구현 (순환 vs 재귀)

### ✔ 내용

- 피보나치 수열 정의
  - `F(1) = 1, F(2) = 1`
- 두 방식 각각 구현 후 결과 비교

---

## 수행 시간 측정

### 방법

- N을 1부터 40까지 증가시키며 실행
- 각 N에 대해:
  - 반복 방식 수행 시간 측정
  - 재귀 방식 수행 시간 측정
- `clock()`을 이용하여 실행 시간 계산

---

## 실행 결과

```text
N,IterTime,RecTime
1,0.000000,0.000000
2,0.000000,0.000000
...
36,0.000000,0.131000
37,0.000000,0.194000
38,0.000000,0.305000
39,0.000000,0.499000
40,0.000000,0.891000
41,0.000000,1.868000
42,0.000000,2.334000
43,0.000000,3.809000
44,0.000000,10.768000
45,0.000000,17.383000
46,0.000000,24.949000
```

<p align="center">
  <img src="https://github.com/user-attachments/assets/9ca9943b-c772-4e36-accb-1f61b1538f55" width="45%" />
  <img src="https://github.com/user-attachments/assets/25f163fd-5bfb-4533-9cbd-a4bc23b289b5" width="45%" />
</p>

## 프로파일링
 - 'Hot Path' 데이터를 통해, 하나의 값을 구하기 위해 자기 자신을 수만 번 다시 호출하는 재귀 특유의 중복 계산 과정 확인했습니다.
 - CPU 사용량 그래프와 상세 분석 지표를 보면 $N$이 커질수록 연산 비용이 지수적으로 증가합니다.
<p align="center">
  <img src="https://github.com/user-attachments/assets/6ad2afae-9485-4fd2-b4fa-8b0ce60a5e65" width="45%" />
  <img src="https://github.com/user-attachments/assets/6cceb954-435e-4003-8b13-08c8c31f6997" width="45%" />
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/3c192110-25ed-4c33-8ef5-87717c51ea9e" width="45%" />
  <img src="https://github.com/user-attachments/assets/84b82758-d3b1-4529-b1e7-0a94fed4e290" width="45%" />
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/204c9f81-828c-4604-a70a-3d0fdc044e06" width="60%" />
</p>
