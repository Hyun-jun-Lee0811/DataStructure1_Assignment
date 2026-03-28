# [자료구조1] 과제(3) - ADT

### 1) ADT
- 분수 자료형을 관리하기 위한 추상 자료형
- 구현체는 추가적으로 정수 및 소수 형태의 입력을 지원함
  
- 데이터 객체: Fraction: int 타입의 분자(num)와 int 타입의 분모(den)로 구성된 구조체.

- 연산
  - simplify(f): 분수 $f$를 기약분수 형태로 변환하여 반환한다. (분모가 음수일 경우 부호를 분자로 이동시킨다.)
  - subtract(f1, f2): 두 분수의 차를 계산하여 기약분수 형태로 반환한다.
  - multiply(f1, f2): 두 분수의 곱을 계산하여 기약분수 형태로 반환한다.
  - divide(f1, f2): 두 분수의 나눗셈을 계산하여 기약분수 형태로 반환한다.
  - parseInput(str): "A/B" 형태의 문자열, 소수 형태, 혹은 정수 형태의 문자열을 입력받아 분수 자료형으로 변환한다.
  - printFraction(f): 분수를 "A/B" 형태로 출력한다. 단, 분모가 1인 경우 정수 형태(A)로 출력한다.
<img width="553" height="216" alt="화면 캡처 2026-03-20 014741" src="https://github.com/user-attachments/assets/78dbc48b-0578-4af1-bb0d-13c96163d07f" />

### 2) GCD, LCM
- 두 정수의 최대공약수와 최소공배수를 구하기 위해 **유클리드 호제법**을 사용
- GCD Pseudo Code
```
 function get_gcd(a, b):
    a = absolute_value(a)
    b = absolute_value(b)
    while b is not 0:
        remainder = a % b
        a = b
        b = remainder
    return a
```
  - LCM Pseudo Code
```
 function get_lcm(a, b):
    if a is 0 or b is 0:
        return 0
    return absolute_value((a / get_gcd(a, b)) * b)
```
<img width="525" height="171" alt="화면 캡처 2026-03-20 014829" src="https://github.com/user-attachments/assets/ec59bc84-b3bf-4f70-8b4a-3d59027a4468" />

<img width="2252" height="2520" alt="image" src="https://github.com/user-attachments/assets/6d1d4a1a-a652-4610-8340-39469e15ea25" />


3) 직사각형  둘레 및 넓이
<img width="799" height="544" alt="화면 캡처 2026-03-20 015651" src="https://github.com/user-attachments/assets/2f20df6f-875f-4a7f-849f-c30de383c700" />
